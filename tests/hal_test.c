/* Run from sdcc_port (do not define NDEBUG):
 * cc -std=c11 -O2 -Wall -Wextra -Werror -Wno-parentheses \
 *   -Ilib/FwLib_STC8/include tests/hal_test.c -o /tmp/opencode/g3061-hal-test
 * /tmp/opencode/g3061-hal-test
 *
 * Actual production sources and vendor macros, with byte-wide mock SFRs.
 * No target timing, SFR mapping/aliasing, interrupt concurrency or ABI coverage:
 * host int is normally 32 bits, while SDCC int is 16 bits. NOP observations
 * cannot verify the intermediate 0x5A trigger write or extended-SFR access.
 * Zero-length EEPROM calls intentionally remain untested (production do/while).
 * main.c initialization and GPIO setup are not included.
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef NDEBUG
#error These tests require assertions
#endif

#define ___FW_CONF_H___
#define __SDCC 1
#define __data
#define __CONF_FOSC 33177600UL
#define __CONF_CLKDIV 0
#define __CONF_MCU_MODEL 0x2A
#define __CONF_MCU_TYPE 3

static volatile uint8_t P_SW2, ADCTIM, ADCCFG, ADC_CONTR, ADC_RES, ADC_RESL;
static volatile uint8_t EA, F0, IAP_CONTR, IAP_CMD, IAP_TRIG;
static volatile uint8_t IAP_ADDRH, IAP_ADDRL, IAP_DATA, IAP_TPS;
static volatile uint8_t AUXR, TMOD, TH0, TL0, TF0, TR0, ET0, T2H, T2L, IE2;

static void mock_nop(void);
#define NOP() mock_nop()
#include "../src/ADC.c"
#include "../src/EEPROM.c"
#include "../src/timer0.c"

static uint8_t eeprom[0x800];
static unsigned adc_pending, adc_channel, adc_code, adc_completions;
static unsigned iap_active, iap_command, iap_address, iap_count, iap_nops;
static uint8_t initial_ea;

static void mock_nop(void)
{
    if (adc_pending) {
        assert(ADC_CONTR == (0xC0 | adc_channel));
        ADC_RES = (uint8_t)(adc_code >> 8);
        ADC_RESL = (uint8_t)adc_code;
        ADC_CONTR = (uint8_t)(0xA0 | adc_channel);
        adc_pending = 0;
        ++adc_completions;
    }
    if (iap_active) {
        unsigned address = ((unsigned)IAP_ADDRH << 8) | IAP_ADDRL;
        unsigned index = iap_nops / 2;
        assert(EA == 0);
        assert(F0 == initial_ea);
        assert(IAP_CONTR == 0x80);
        assert(IAP_TPS == 33);
        assert(IAP_CMD == iap_command);
        assert(IAP_TRIG == 0xA5);
        assert(index < iap_count);
        assert(address == iap_address + index);
        assert(address < sizeof eeprom);
        /* One operation per trigger, not one per NOP. */
        if ((iap_nops & 1) == 0) {
            switch (IAP_CMD) {
            case 1: IAP_DATA = eeprom[address]; break;
            case 2: eeprom[address] &= IAP_DATA; break;
            case 3: memset(eeprom + (address & ~0x1FFu), 0xFF, 512); break;
            default: assert(0);
            }
        }
        ++iap_nops;
    }
}

static void test_adc(void)
{
    unsigned saved, channel, code;
    for (saved = 0; saved < 256; ++saved) {
        P_SW2 = (uint8_t)saved;
        ADCTIM = ADCCFG = ADC_CONTR = ADC_RES = ADC_RESL = 0xFF;
        adc_init();
        assert(P_SW2 == saved);
        assert(ADCTIM == 0x3F);
        assert(ADCCFG == 0x2F);
        assert(ADC_CONTR == 0 && ADC_RES == 0 && ADC_RESL == 0);
    }
    for (channel = 0; channel < 16; ++channel) {
        for (code = 0; code < 4096; ++code) {
            adc_channel = channel;
            adc_code = code;
            adc_pending = 1;
            /* Stale completion flag and wrong channel must be replaced. */
            ADC_CONTR = (uint8_t)(0x20 | (channel ^ 15));
            ADC_RES = ADC_RESL = 0xFF;
            assert(get_adc(channel) == code);
            assert(adc_pending == 0);
            assert(ADC_CONTR == (0x80 | channel));
            assert(ADCCFG == 0x2F && ADCTIM == 0x3F);
            assert(P_SW2 == 0xFF);
        }
    }
    assert(adc_completions == 16 * 4096);
}

static void begin_iap(unsigned command, unsigned address, unsigned count,
                      uint8_t ea)
{
    assert(count > 0);
    initial_ea = EA = ea;
    F0 = (uint8_t)!ea;
    IAP_CONTR = IAP_CMD = IAP_TRIG = IAP_TPS = 0xFF;
    IAP_ADDRH = IAP_ADDRL = IAP_DATA = 0xFF;
    iap_command = command;
    iap_address = address;
    iap_count = count;
    iap_nops = 0;
    iap_active = 1;
}

static void end_iap(void)
{
    assert(iap_nops == 2 * iap_count);
    assert(EA == initial_ea);
    assert(IAP_CONTR == 0 && IAP_CMD == 0 && IAP_TRIG == 0);
    assert(IAP_ADDRH == 0xFF && IAP_ADDRL == 0xFF);
    iap_active = 0;
}

static void test_eeprom(void)
{
    /* Current main.c settings layout, plus byte/sector boundary transfers. */
    static const struct { uint16_t address, count; } cases[] = {
        {0x0000, 2}, {0x0200, 2}, {0x0204, 2}, {0x0208, 2},
        {0x0400, 2}, {0x0404, 2}, {0x0600, 1},
        {0x00FE, 4}, {0x01FE, 260}, {0x03FE, 4}, {0x05FE, 4},
        {0x07FF, 1}
    };
    uint8_t expected[sizeof eeprom], input[260], output[262];
    unsigned ea, c, i, pass, sector;
    for (ea = 0; ea < 2; ++ea) {
        memset(eeprom, 0xFF, sizeof eeprom);
        memset(expected, 0xFF, sizeof expected);
        for (c = 0; c < sizeof cases / sizeof cases[0]; ++c) {
            unsigned address = cases[c].address, count = cases[c].count;
            /* Second pass exercises programming without erasing (1->0 only). */
            for (pass = 0; pass < 2; ++pass) {
                for (i = 0; i < count; ++i) {
                    input[i] = (uint8_t)(i * 37 + c * 19 + pass * 113);
                    expected[address + i] &= input[i];
                }
                begin_iap(2, address, count, (uint8_t)ea);
                EEPROM_write_n(cases[c].address, input, cases[c].count);
                end_iap();
                assert(memcmp(eeprom, expected, sizeof eeprom) == 0);

                memset(output, 0xA6, sizeof output);
                begin_iap(1, address, count, (uint8_t)ea);
                EEPROM_read_n(cases[c].address, output + 1, cases[c].count);
                end_iap();
                assert(memcmp(output + 1, expected + address, count) == 0);
                assert(output[0] == 0xA6);
                for (i = count + 1; i < sizeof output; ++i)
                    assert(output[i] == 0xA6);
                assert(memcmp(eeprom, expected, sizeof eeprom) == 0);
            }
        }
        for (sector = 0; sector < sizeof eeprom; sector += 512) {
            for (pass = 0; pass < 2; ++pass) {
                unsigned address = sector + (pass ? 511 : 0);
                for (i = 0; i < sizeof eeprom; ++i)
                    expected[i] = eeprom[i] = (uint8_t)(i * 13 + i / 256);
                memset(expected + sector, 0xFF, 512);
                begin_iap(3, address, 1, (uint8_t)ea);
                EEPROM_SectorErase((uint16_t)address);
                end_iap();
                assert(memcmp(eeprom, expected, sizeof eeprom) == 0);
            }
        }
    }
}

static void test_timers(void)
{
    unsigned mode, aux, bit;
    for (mode = 0; mode < 256; ++mode) {
        for (aux = 0; aux < 256; ++aux) {
            for (bit = 0; bit < 2; ++bit) {
                TMOD = (uint8_t)mode;
                AUXR = (uint8_t)aux;
                TF0 = TR0 = ET0 = EA = (uint8_t)bit;
                TH0 = TL0 = 0xFF;
                T2H = 0x12; T2L = 0x34; IE2 = 0xA5;
                Timer0Init();
                assert(TMOD == (mode & 0xF0));
                assert(AUXR == (aux | 0x80));
                assert(TH0 == 0x7E && TL0 == 0x66);
                assert(TF0 == 0 && TR0 == 1 && ET0 == 1);
                assert(EA == bit);
                assert(T2H == 0x12 && T2L == 0x34 && IE2 == 0xA5);
            }
        }
    }
    /* Timer2Init is not called by production; test only its standalone state. */
    for (aux = 0; aux < 256; ++aux) {
        AUXR = IE2 = (uint8_t)aux;
        T2H = T2L = 0;
        Timer2Init();
        assert(AUXR == (aux | 0x14));
        assert(IE2 == (aux | 0x04));
        assert(T2H == 0xF9 && T2L == 0x85);
    }
}

int main(void)
{
    test_adc();
    test_eeprom();
    test_timers();
    puts("HAL host tests passed: ADC, EEPROM, Timer0, standalone Timer2");
    return 0;
}
