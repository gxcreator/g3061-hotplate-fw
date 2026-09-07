# HeatingPlate-PD

This project ports the original Keil firmware to SDCC for the STC8H3K64S2 microcontroller.
It controls a heating plate with an OLED display, buttons, and settings stored in EEPROM.
EEPROM retains settings without power.

![G3061](G3061-small2.jpg)

## Temperature Sensor

This firmware now targets a standard IEC 60751 PT100 sensor connected to ground.
The sensor input has a 500 ohm pull-up resistor, marked `5000` in the photo.
The pull-up supply must also be the ADC reference supply.
The conversion in `src/temperature.c` calculates resistance before temperature.
It does not use the old board's calibration polynomial.

The display rounds temperatures to whole degrees from 0 to 400 C.
An ADC reading outside this range stops heating and displays `SENSOR FAULT`.
This includes open and shorted sensors.
Each converted sample at or above 360 C also latches this shutdown, even if the moving average is lower.
An internal-reference ADC result of zero or outside the 12-bit range latches the same fault.
The fault check uses each new sample before averaging.
Repair the fault before cycling power to reset the shutdown.

Verify the temperature against an independent thermometer before enabling heating.
Sensor identity, resistor tolerance, and lead resistance affect accuracy.
The new conversion still needs hardware validation.

## Requirements

- Linux with GNU Make.
- Git with GitHub SSH access for the HAL submodule.
- SDCC, including `sdas8051` and `packihx`.
- Python 3 with `venv` support.
- [stcgal](https://github.com/grigorig/stcgal) to program the board through a USB-to-UART adapter.

Hardware tests used SDCC 4.6.0.
Other compiler versions need separate tests.

On Debian or Ubuntu, install the tools:

```bash
sudo apt update
sudo apt install git make sdcc python3-venv
python3 -m venv "$HOME/.venvs/stcgal"
"$HOME/.venvs/stcgal/bin/python" -m pip install stcgal==1.10
```

Your distribution may provide another SDCC version.
Check the installed version:

```bash
sdcc --version
```

## Build

Run the build commands from the directory that contains this README:

```bash
git submodule update --init --recursive
make
```

The HAL submodule uses the SSH URL `git@github.com:IOsetting/FwLib_STC8.git`.
Initialize it before the first build. Git records its exact revision; do not update it with `--remote` as part of a normal build.

The build produces `build/HeatingPlate-PD.hex`.
It also prints flash and external RAM usage against the linker limits, plus internal RAM allocation and stack space.
The file `build/HeatingPlate-PD.mem` lists memory use.

To rebuild all files:

```bash
make clean
make
```

The build includes SDCC's `src/crtxinit.asm` with `DUAL_DPTR = 1`.
This startup routine uses two 16-bit pointers to initialize the chip's extended RAM, called XRAM.
Keep this file in the build.
Do not add `--no-xinit-opt`.

### Formatting

Run `make format` to format all project-owned C sources and headers in `src/` and `tests/` using `.clang-format`.
The style uses four spaces, a 100-column limit, and preserves include order. Vendor code, generated files, and assembly are excluded.
Install `clang-format` separately if needed. To select a versioned executable, use `make format CLANG_FORMAT=clang-format-22`.
Run `make format-check` to check formatting without changing files.

### Integer Types

Project-owned C code uses `<stdint.h>` types for numeric values, including display buffers and font/bitmap bytes.
The migration preserves SDCC widths and signedness: unsigned bytes use `uint8_t`, signed bytes use `int8_t`, and 16-bit values use `uint16_t` or `int16_t`.
Host-test counters use `uint32_t`, including the ADC completion count that reaches 65536. The hosted test entry point retains the required `int main(void)` signature.
The application retains SDCC bit variables and floating-point measurement averages. Shared control bits are volatile, and foreground multi-byte accesses and event consumption save, clear, and restore `EA`. Vendor sources and the EEPROM byte layout are unchanged. The PID arithmetic corrections are described below.

## Application Modules

`src/main.c` contains board startup, the Timer0 interrupt entry, and the foreground pipeline. Each module owns private static state; there is no shared application-state structure.
The loop delegates to static home, settings, controller, fault, and persistence functions. Each successful page iteration consumes one button snapshot and forwards it to persistence after input handling, including when input changes the page. Invalid home samples leave input and realtime events pending for the fault path.

| Module | Responsibility |
| --- | --- |
| `settings.c/.h` | Little-endian EEPROM codec, validation, edit limits, dirty sectors, and commit |
| `measurements.c/.h` | Thirty-sample temperature/supply windows, thirty reference reads per update, raw-sample safety checks |
| `pid.c/.h` | Resettable integral/error history and signed, bounded PID calculation |
| `buttons.c/.h` | ISR gesture timing, saturating 500-tick hold counters, atomic one-byte event/held-state snapshots |
| `realtime.c/.h` | PWM phase, atomic duty mailbox, period events, stale guard, fault and EEPROM interlocks |
| `ui.c/.h` | Byte-sized screen/selection storage, flash-resident destination/field tables, shared PID/temperature submenu input, shared settings renderer, graph history |

Only `ui.c` in the firmware includes `bmp.h`, which defines both assets and drawing functions. The software I2C backend and both native font tables in `oledfont.h` are unchanged.

### Native 128x32 Display

The physical panel is confirmed to be 128x32. The production driver now uses native pixel coordinates and a single 512-byte XRAM framebuffer (`128 * 4`), with no doubled rows or odd-pixel workaround. Clear and flush each transfer four pages, numbered 0..3, instead of eight. Each full transfer sends 512 display-data bytes and 12 page/column command bytes. The existing per-byte protocol sends three I2C bytes per transaction: 1,572 transmitted I2C bytes, excluding ACK clocks, versus 3,144 before migration. Bus timing and reset delays are unchanged.

The original driver identifies the controller as SSD1306. Initialization now sends `A8 1F` (32-way multiplex) and `DA 02` (sequential COM pins, no left/right remap), retaining page addressing `20 02`, offset/start line zero, charge pump, contrast, display rotation, and inversion controls. These meanings follow the manufacturer's [Solomon Systech SSD1306 datasheet, sections 9 and 10.1.11/10.1.18](https://www.digikey.in/en/htmldatasheets/production/1797895/0/0/1/ssd1306). Controller identity is inherited, not established by a chip readout; physical resolution alone does not prove COM wiring. This standard 128x32 configuration still requires hardware acceptance. No firmware was flashed during this migration.

All framebuffer APIs and all `Draw_*` helpers in `bmp.h` use pixel x/y. `OLED_DrawBitmap(x, y, width, height, bitmap, inverted)` accepts arbitrary y, partial heights, and right/bottom clipping. Its source format is page-major, bit 0 at the top, with `width * ceil(height / 8)` bytes. Clipping retains the source stride. A shifted source byte updates at most two destination pages; masks preserve pixels outside the rectangle and exclude final-page padding from inversion. Empty rectangles and origins outside 128x32 do nothing. There is no per-pixel bitmap loop or second framebuffer.

`OLED_DrawBMP_2()` and `OLED_DrawBMP_2_Inverted()` remain single-evaluation macros calling that core with inversion 0 or 1; their y argument is now pixels, not pages. The distinct direct-to-controller APIs (`OLED_Set_Pos`, `OLED_DrawBMP`, and `OLED_ShowChar/Num/String`) retain column/page coordinates, bounded to pages 0..3. Raw `OLED_DrawBMP` writes whole pages, including source padding, and bypasses the framebuffer; use the buffered core for partial-page preservation. `OLED_DrawLine` rejects endpoints outside native bounds. The unused buffered `OLED_DrawChar` now renders the complete native 8x16 glyph with proper 128-byte stride, clipping, and retained overlap/reverse behavior. Its numeric cursor uses eight-column spacing without wrapping onto earlier rows.

Nonediting Kp/Ki/Kd and maximum/minimum menus intentionally invert the full native 28x28 rectangle, including corners and background. Mode still draws the active mode normally and the inactive mode inverted. Editors and Back icons remain normal. Prior alternate-asset and submenu-label-artwork deletions are retained. `render_settings()` still selects a two-byte code-memory icon pointer, inversion flag, digit count, and tab count in one switch; input policies and selected-setting fallback are unchanged.

Settings icons occupy (22, 0), labels (58, 8), editor digits (53, 16), and tabs y=28. TOP uses 32x32 icons; submenus use 28x28. The 17x24 arrows start at y=4, not page 1. Native 6x8 labels occupy y=8..15, above 12-pixel editor digits at y=16..27 and four-pixel tabs at y=28..31. The longest label ends at x=105, before the right arrow at x=109. PID editors retain four digits and temperature editors three. Labels remain code-memory strings: `PID`, `Temp`, `Display`, `P gain`, `I gain`, `D gain`, `Max temp`, `Min temp`, `Normal`, `Graph`, and `Back`.

`OLED_DrawStringSmall()` uses the unchanged native 6x8 font through the bitmap core, without a row-duplication lookup table. Unsupported indices draw a space; only complete six-column glyphs fit at the right edge, and the bottom clips safely. HOME uses 24-pixel actual-temperature digits and state icons, 12-pixel voltage and target digits, and eight-pixel loading bars at y=24. Loading fills and target markers use native pixel offsets. Graph axes are 103x32 with normalized y=0..30; values occupy y=0 and y=12 and the heater switch y=24. The fault screen places the 11 visible characters of `SENSOR FAULT` at x=16 using unchanged 8x16 glyphs on controller pages 1 and 2 (pixel y=8..23), without drawing the string terminator.

### Bitmap Inventory

All artwork in `bmp.h` was converted once by selecting source rows 1, 3, ..., 63 as applicable. Horizontal coordinates and asset ordering are unchanged. Unused `taroff` is retained and converted as 23x12. Fonts are not collapsed: `asc2_0806` (92 native 6x8 entries, 552 bytes) and `asc2_1608` (95 native 8x16 entries, 1,520 bytes) remain byte-for-byte unchanged; small labels use the former and direct/buffered large text the latter.

| Assets | Entries | Native Size | Bytes per Entry | Consumers |
| --- | ---: | --- | ---: | --- |
| `BIGNUM` | 10 | 16x24 | 48 | HOME actual temperature |
| `SMALLNUM` | 10 | 8x12 | 16 | Target, voltage, graph values, editors |
| `taroff` | 1 | 23x12 | 46 | Unused retained artwork |
| `oc` | 1 | 11x12 | 22 | Target degree/unit symbol |
| `volv`, `vol_` | 1 each | 8x12, 2x12 | 16, 4 | Voltage unit and decimal point |
| `outline` | 1 | 55x8 | 55 | Loading bars |
| `LoadLeft`, `LoadRight` | 1 each | 8x8 | 8 | Loading direction symbols |
| `state` | 3 | 42x24 | 126 | HOME state |
| `page1_icon` | 4 | 32x32 | 128 | TOP menu |
| `page1_arrlw/arrrw/arrlb/arrrb` | 1 each | 17x24 | 51 | Navigation/editor arrows |
| `tab`, `tab2` | 1 each | 12x4 | 12 | Selection tabs |
| `PID`, `TEMP`, `mode` | 4, 3, 3 | 28x28 | 112 | Settings icons including Back |
| `switch_ope`, `switch_clo` | 1 each | 16x8 | 16 | Graph heater state |
| `xy` | 1 | 103x32 | 412 | Graph axes |

Page-major storage needs 112 bytes per 28x28 icon, not the tightly bit-packed 98 bytes; its fourth page has four zero padding bits per column. The 8x12 digits similarly require 16 bytes each and tabs still require 12 bytes. Total artwork decreases from 6,534 to 3,481 bytes. Static conversion compared row-index extraction with independent odd-bit nibble packing before writing. Unequal source row pairs occur in `BIGNUM` (269 pairs), `SMALLNUM` (100), and `switch_ope` (10); all other pairs match. Odd rows were deliberately retained in these cases, not averaged or ORed. Numeric strokes and switch appearance need hardware inspection.

Build the normal UI with `make -B all`; the resulting image is `build/HeatingPlate-PD.hex`. There is no diagnostic overlay or alternate geometry build option.

Menu table lookups check selection bounds. Two-byte code-memory descriptors share PID/temperature submenu handling; screen dispatch and back behavior remain explicit. Invalid editor selections retain the `SET_TARGET` field-lookup fallback.

Single-button taps change the target or menu selection. Holds repeat numeric edits once per foreground frame after 500 timer ticks; releasing a single held button retains the final tap. A both-button tap toggles heating on HOME or selects a menu item. Holding both buttons enters settings or goes back one level. Buttons held across startup must be released before accepting gestures. Entering or leaving settings keeps heating disabled. HOME still measures and renders before processing input; menus process input before rendering. A menu exit renders HOME directly, without an invalid icon index. PID requests and graph shifts retain their coalesced, once-per-1000-tick cadence; enabling and safety recovery also request a new PID immediately.

Button names distinguish `BUTTON_EVENT_*` notifications from `BUTTON_STATE_*_HELD` levels. `BUTTON_EVENT_ALL_RELEASED` is initially pending and then emitted once per transition to both buttons released, rather than on every foreground read. A new press cancels an unconsumed all-released notification but retains gesture events, preventing a stale release from committing during a later press or hold. A single-button release can coexist with the other button's held state; that snapshot does not commit. Persistence runs after edits so a release-created dirty setting is saved in the same iteration. A tap leaves an editor with its item selected; a long back resets the parent selection to its first item.

The graph stores 101 normalized byte coordinates from 0 to 30, rather than temperatures that overflow above 255 C. This uses 101 bytes, versus 202 for `uint16_t` temperatures. Both target and history use the minimum-temperature offset. Changing limits clears history so different scales cannot mix. All progress/graph divisions guard degenerate limits, and voltage rendering is capped at its two-digit display range.

The physical buttons are LEFT (formerly UP, `key0` on P3.2) and RIGHT (formerly DOWN, `key1` on P3.3). LEFT retains numeric increment and next-menu-item behavior; RIGHT retains numeric decrement and previous-menu-item behavior. Release flags are `BUTTON_EVENT_LEFT_RELEASE` / `BUTTON_EVENT_RIGHT_RELEASE`, and held levels are `BUTTON_STATE_LEFT_HELD` / `BUTTON_STATE_RIGHT_HELD`. Wiring, flag values, and gesture timing are unchanged.

### Settings Layout

| Setting | EEPROM Address (Hex) | Bytes |
| --- | --- | --- |
| Target | `0x0000` | 2 |
| Kp / Ki / Kd | `0x0200` / `0x0204` / `0x0208` | 2 each |
| Maximum / minimum | `0x0400` / `0x0404` | 2 each |
| Display mode | `0x0600` | 1 |

Two-byte values remain low-byte first. Commits erase only dirty 512-byte sectors and rewrite all defined fields in those sectors. Validation retains maximum clamping to 200..350 C, minimum values above 200 defaulting to zero, gains above 1000 defaulting to 500, and invalid modes defaulting to zero. Existing gains from 501..1000 still load; upward edits stop at 500, while downward edits remain available. The minimum must now be strictly below the maximum; a loaded 200/200 pair becomes 199/200. Targets are clamped on load and after edits, and any target clamp marks its sector dirty. Other boot-time validation corrections, as before, are not automatically written.

### Heater Interlocks

The ISR uses `active_duty > phase` with phases 0..999 and duties 0..1000. Thus zero is always off and 1000 is continuously on when permitted. Foreground duty publication is atomic; the ISR latches it only at phase zero. Disable, fault, stale detection, and EEPROM pause clear both duties and force the output low without waiting for a period boundary.

A complete valid measurement refreshes the stale timer. After 2000 Timer0 ticks without one, the ISR disables heating even if the foreground is stuck in the vendor ADC polling loop. This shutdown is not latched and does not change the user's enable selection. A fresh valid measurement followed by a reset/new PID calculation is required to recover; PWM starts at a subsequent period boundary. The vendor ADC poll is still unbounded, so the UI cannot recover until the ADC returns. The timer must remain running and interrupts must remain enabled for this guard to work.

Before the first EEPROM erase, the foreground forces the heater low and inhibits the ISR for the entire commit, including gaps between IAP calls. It retains the user enable selection. After commit, PID state is reset and the interlock remains closed until the next HOME measurement and new PID publication. The reference conversions precede the temperature conversion, so a stalled reference read cannot certify an earlier temperature as fresh. Measurements run at startup and on HOME; settings pages already have heating disabled.

PID products use signed `int32_t` intermediates. For the supported 0..400 C inputs and 0..1000 gains, even the uncapped product sum has magnitude at most 1,700,000. Error conversion still truncates the floating-point difference toward zero. Integration remains restricted to errors between -10 and 10, with a +/-500 accumulator limit and the positive integral-output limit. Positive proportional and derivative terms are capped at 1000; the derivative limit no longer overwrites the integral. Previous error retains the raw error, not a proportional-limit artifact. Final duty is clamped to 0..1000. These fixes require control-loop testing and may require gain retuning.

### Memory Comparison

The native128x32 migration was measured with forced production SDCC 4.6.0 builds (`make -B all`):

| Resource | Legacy 128x64 Baseline | Native 128x32 | Change |
| --- | ---: | ---: | ---: |
| Flash | 30,994 B | 27,307 B | -3,687 B |
| XRAM | 1,592 B | 1,081 B | -511 B |
| Framebuffer (included in XRAM) | 1,024 B | 512 B | -512 B |
| Static IRAM | 109 B | 106 B | -3 B |
| Available stack | 145 B | 148 B | +3 B |

The framebuffer occupies XRAM `0x023A..0x0439`; all XRAM occupies `0x0001..0x0439`. Other XRAM allocations increase by one byte in total. Assembly declares exactly `.ds 512` for the sole framebuffer and retains code-memory assets and fonts. Generated assembly for main (including the ISR), buttons, realtime, software I2C, ADC, EEPROM, and Timer0 is byte-for-byte identical to this migration's baseline. Two IRAM bytes remain unallocated. Stack availability is linker space, not a measured runtime high-water mark. Source/asset and assembly inspection, production formatting, and diff checks were used; host tests and sanitizers were deliberately not run or maintained.

The comparisons below are historical measurements before native128x32, not current geometry or memory usage.

The initial baseline build report and forced refactored SDCC 4.6.0 build reported:

| Resource | Baseline | Refactored | Change |
| --- | ---: | ---: | ---: |
| Flash | 39,501 B | 34,134 B | -5,367 B |
| XRAM | 1,632 B | 1,579 B | -53 B |
| Static IRAM | 95 B | 111 B | +16 B |
| Available stack | 138 B | 143 B | +5 B |

The baseline had 23 bytes of unallocated IRAM; the refactored layout has 2. Stack availability is linker space, not a measured runtime high-water mark. Integer sample windows save 120 bytes versus the old float windows while preserving floating-point averages; module parameters and other allocations use part of those savings.
The structural cleanup of the already modular version changed flash from 34,030 to 34,134 bytes and XRAM from 1,572 to 1,579 bytes; static IRAM and available stack were unchanged. Timer0 retains the same 14-byte register-save set and two direct calls. Both ISR callees remain helper-call-free, and button timing retains its existing single register push/pop pair.
The subsequent table-driven menu cleanup changed flash from 34,134 to 34,143 bytes (+9) and XRAM from 1,579 to 1,580 bytes (+1), with static IRAM and available stack unchanged. Destination/field tables and submenu descriptors reside in code memory.

Full-rectangle PID inversion was measured with forced baseline and final SDCC builds:

| Resource | Before Inversion | After Inversion | Change |
| --- | ---: | ---: | ---: |
| Flash | 34,143 B | 33,755 B | -388 B |
| XRAM | 1,580 B | 1,595 B | +15 B |
| Static IRAM | 111 B | 109 B | -2 B |
| Available stack | 143 B | 145 B | +2 B |

Removing 588 asset bytes offset 200 bytes of drawing/UI code overhead in that runtime-wrapper version. No second framebuffer was allocated.

Replacing the runtime wrappers with header macros was measured with forced baseline and final SDCC 4.6.0 builds (`make -B`):

| Resource | Runtime Wrappers | Header Macros | Change |
| --- | ---: | ---: | ---: |
| Flash | 33,755 B | 33,819 B | +64 B |
| XRAM | 1,595 B | 1,581 B | -14 B |
| Static IRAM | 109 B | 109 B | 0 B |
| Available stack | 145 B | 145 B | 0 B |

The macros eliminate two 7-byte wrapper parameter/local allocations in XRAM. The shared core still needs its inversion argument, so this recovers 14 of the previous 15 added XRAM bytes. Setting inversion at each call site costs more flash overall than the removed wrapper code saves. Generated assembly calls or jumps directly to `OLED_DrawBitmap`; the old wrapper symbols and parameter allocations are absent. The normal/inverted drawing loop is unchanged. Unallocated IRAM remains 2 bytes; stack availability is not measured runtime use.

Extending full-rectangle inversion to temperature and mode was measured with forced baseline and final SDCC builds (`make -B`):

| Resource | PID Inversion Only | Temperature/Mode Inversion | Change |
| --- | ---: | ---: | ---: |
| Flash | 33,819 B | 33,120 B | -699 B |
| XRAM | 1,581 B | 1,581 B | 0 B |
| Static IRAM | 109 B | 109 B | 0 B |
| Available stack | 145 B | 145 B | 0 B |

Removing 784 alternate-asset bytes offsets 85 bytes of additional UI code. No framebuffer, wrapper, or parameter storage was added. Unallocated IRAM remains 2 bytes; stack availability is linker space, not measured runtime usage.

The shared settings renderer was measured with forced baseline and final SDCC 4.6.0 builds (`make -B`). This baseline already had submenu labels and their assets removed; those earlier changes are not counted as refactor savings.

| Resource | Before Shared Renderer | Shared Renderer | Change |
| --- | ---: | ---: | ---: |
| Flash | 30,783 B | 30,543 B | -240 B |
| XRAM | 1,581 B | 1,583 B | +2 B |
| Static IRAM | 109 B | 109 B | 0 B |
| Available stack | 145 B | 145 B | 0 B |

Generated assembly allocates two bytes for the code-qualified icon pointer instead of a three-byte generic pointer. The existing generic-pointer OLED API is unchanged. Removing the three renderer helpers offsets most shared-local storage; the net XRAM cost is two bytes. No additional firmware framebuffer is allocated. Unallocated IRAM remains 2 bytes, and available stack is not measured runtime usage.

Compact settings labels were measured with forced baseline and final SDCC 4.6.0 builds (`make -B all`):

| Resource | Before Text | With Text | Change |
| --- | ---: | ---: | ---: |
| Flash | 30,543 B | 30,920 B | +377 B |
| XRAM | 1,583 B | 1,590 B | +7 B |
| Static IRAM | 109 B | 109 B | 0 B |
| Available stack | 145 B | 145 B | 0 B |

The label arrays occupy 108 bytes in code memory. Added XRAM is a two-byte selected-label pointer plus five bytes of text-helper parameter/local storage, not string copies. Assembly confirms `MOVC` string reads and code-tagged font pointers passed to the existing bitmap core. Unallocated IRAM remains 2 bytes; stack availability is not measured runtime usage. Verification for this change used only target builds, memory/assembly inspection, production-source formatting checks, and `git diff --check`. Host tests and sanitizers were not run or updated; historical host-renderer results predate these labels. Physical text appearance and render timing still need hardware validation.

## HAL Integration

Hardware access uses [FwLib_STC8](https://github.com/IOsetting/FwLib_STC8) at `lib/FwLib_STC8`.
The initial port pins revision `992a4e060a48d860c203ce4ce61dfe90b51acbd6`.
The library has an Apache-2.0 license; its license and source remain unchanged in the submodule.
This port uses peripheral headers and macros plus `fw_sys.c` for `SYS_DelayUs()` and `fw_adc.c` for `ADC_ConvertHP()`, not the upstream demo build.
ADC initialization requests 20 us through the approximate, clock-configured delay.
ADC reads select the channel, clear the completion flag, enable power, and call `ADC_ConvertHP()` to start, wait for, and read the conversion.
The library uses two NOPs before polling instead of the former 10 us delay; polling still has no timeout. Invalid channels return `0xFFFF` without starting a conversion.
These timing changes require hardware ADC validation; OLED and I2C delays remain unchanged.
Linking `fw_sys.c` does not call `SYS_SetClock()` or change oscillator settings.

The Makefile supplies `__CONF_MCU_MODEL=MCU_MODEL_STC8H3K64S2`, `__CONF_FOSC=33177600UL`, and `__CONF_CLKDIV=0` to every C compilation.
These constants describe the assumed clock; they do not program it.
Do not call `SYS_SetClock()` or copy oscillator trim values from the library examples.
Application initialization enables extended-register access once with `SFRX_ON()`, immediately after the heater-off setup, and leaves it enabled.
Peripheral drivers, including `adc_init()`, rely on this startup policy. Do not call `SFRX_OFF()` or helpers that unconditionally clear `P_SW2.7`.
Audit new FwLib helpers for this behavior: generic `SFRX_*` wrappers can clear the bit on exit. The currently called helpers do not.
The current XRAM allocation (`0x0001` through `0x0439`) is below the extended-register region; recheck this if the memory layout changes.
The previously reported chip frequency was approximately 29.971 MHz, so actual timing still requires measurement.

Board pin assignments are in `src/board.h`:

| Function | Pin or Channel | Configuration |
| --- | --- | --- |
| Heater | P3.4 | Active high, push-pull; latch cleared before enabling the driver |
| LEFT / RIGHT buttons | P3.2 / P3.3 | Active low, open drain with released latches |
| OLED SCL / SDA | P3.5 / P3.6 | Push-pull / quasi-bidirectional, software I2C |
| OLED reset | P2.3 | Push-pull |
| Supply / temperature | P1.0 / P1.1, ADC0 / ADC1 | High-impedance inputs |
| Internal reference | ADC15 | Nominal 1.19 V |

Only used pins are configured. Unused pins retain their prior modes instead of receiving whole-port mode writes.
The heater is disabled at the start of application initialization; this does not guarantee its electrical state during reset or C runtime startup.

The following hardware behavior is retained:

- Timer0 uses 1T mode, 16-bit auto-reload `0x7E66`, and interrupt vector 1. The heater still uses a 1000-tick software PWM period. Timer2 is not started by the application.
- ADC configuration after normal startup remains `ADCTIM=0x3F` and `ADCCFG=0x2F`: 32 sample clocks, system clock/32, and right-aligned 12-bit results. Extended-register access stays enabled globally.
- ADC initialization uses FwLib field setters and disables PWM triggering. It preserves unrelated configuration bits and result registers; it is startup configuration, not a reset of an active conversion. Reads wait for a completed conversion before using its result.
- EEPROM operations retain their addresses, byte order, 512-byte sectors, and interrupt-state restoration. The upstream IAP command macros are not used because they unconditionally enable interrupts.
- OLED reset delays, software bus transactions, and fonts are retained. Settings rendering includes the intentional bitmap inversion and compact text labels described above. The hardware I2C peripheral cannot use the board's P3.5/P3.6 wiring.
- PT100 conversion, voltage scaling, and thirty-sample averaging are retained. PID arithmetic and application interlocks have the corrections described above.

`src/i2c.h` defines the public `i2c_*` interface without selecting a software or hardware implementation.
The Makefile currently selects `src/soft_i2c.c`, which owns software bus initialization, START/STOP signals, byte transmission, ACK clocks, and the private single-NOP delay.
For a board with suitable hardware I2C pins, replace this backend with an implementation of the same interface; OLED bus calls do not need to change.
`src/oled.c` supplies the OLED address and control bytes and retains reset handling and rendering.
The transport clocks ACK bits but does not check the slave response; it does not add retries, clock stretching, or bus recovery.

### Verification

Host tests have been abandoned for this migration. Files in `tests/` and their Makefile targets are retained untouched, not maintained for the new bitmap coordinates or asset sizes. Do not treat their historical results as native128x32 verification. No host tests or sanitizers were run, added, or edited.

Production-only verification commands:

```bash
make -B all
clang-format --style=file --dry-run --Werror src/oled.c src/oled.h src/ui.c src/bmp.h
git diff --check
```

Inspect the SDCC map, memory report, and generated assembly as well as production source bounds. The bitmap core first bounds x/y, then clips width/height by subtraction. Its low-page index cannot exceed 511; a high-page write occurs only when active bits cross the page boundary, and bottom clipping guarantees that page exists. Source reads retain the declared bitmap width. This covers 28-row inversion masks, arrows at y=4, 12-row digits at y=12 or y=16, and four-row tabs at y=28 without modifying adjacent pixels. Static inspection does not establish runtime stack depth, physical display mapping, timing, or thermal stability.

Native display acceptance, with the heater disconnected:

1. Confirm all 32 rows and 128 columns are visible, with no doubled, missing, or interleaved rows. Confirm the SSD1306/sequential-COM assumption on the actual module.
2. Inspect all TOP and submenu selections, normal/inverted mode states, Back icons, arrow positions, and three-/four-digit editors. Verify complete labels and clean boundaries between icons, digits, and tabs.
3. Inspect HOME numeric strokes, both voltage layouts, heating/off state artwork, empty/full loading bars, and the target marker. Inspect graph endpoints, target dashes, and the enabled-switch icon.
4. Inject a sensor fault and confirm the complete `SENSOR FAULT` message is visible and heating remains latched off.
5. Check rotation/inversion, power cycling, ghost rows, display contrast, reset/bus waveforms, and render cadence. The shorter frame transfer changes foreground cadence even though timer and heater policy are unchanged; check hold-repeat rate and display smoothing on hardware.

Before enabling heat on the ported firmware, test with the heater disconnected:

1. Check the heater gate from reset through initialization, and verify that unused pin modes are suitable for the board.
2. Measure Timer0/PWM timing and OLED reset and bus waveforms.
3. Check voltage readings and PT100 conversion with an independent reference; inject open and shorted sensor faults.
4. Check settings retention across power cycles and verify the image fits the chip's actual flash/EEPROM split.
5. Inject temperatures immediately below and at 360 C and a zero reference. Verify latched shutdown before averaging and no button-driven restart.
6. Stall ADC completion while requesting heat. Verify heater-low at 2000 timer ticks, then fresh-sample/reset-PID recovery only after conversion resumes. Measure actual elapsed time: ticks assume the configured oscillator.
7. Scope the heater during EEPROM erase/write and recovery, including duty 0, 1, 999, and 1000. Check physical button gestures, render cadence, and PID response before connecting the heater; repeat thermal tests with an independent cutoff.

Remaining safety work includes bounded ADC polling for foreground recovery, EEPROM integrity/readback and power-loss handling, and a watchdog policy. EEPROM callers must still pass a nonzero byte count. The stale guard is not an independent hardware cutoff and cannot protect against a stopped CPU/timer or globally disabled interrupts. Use an independent thermal cutoff; no host test substitutes for hardware validation.

## Flash

Programming replaces the installed firmware.
The chip may also erase saved EEPROM settings.
Keep heating disabled during the first test.

1. Connect a compatible USB-to-UART adapter to the board's programming connector.
2. Check the adapter connections: TX to RX, RX to TX, and ground to ground.
3. Replace `/dev/ttyUSB0` below if your adapter uses another device path.

Read the current chip options without programming:

```bash
sudo "$HOME/.venvs/stcgal/bin/stcgal" -P stc8d -p /dev/ttyUSB0
```

When stcgal requests a power cycle, disconnect the board's power.
Restore power to let stcgal detect the chip.

Check `program_eeprom_split`, which gives the code region size in bytes.
The firmware must fit inside that region.
Leave at least 2 KiB for EEPROM settings.
The Makefile permits up to 60 KiB of code, which leaves 4 KiB for EEPROM.
The Makefile does not configure the chip's memory split.
If you need this split, add `-o program_eeprom_split=61440` to the programming command.

Program the firmware:

```bash
sudo "$HOME/.venvs/stcgal/bin/stcgal" \
  -P stc8d \
  -p /dev/ttyUSB0 \
  build/HeatingPlate-PD.hex
```

1. Disconnect the board's power when stcgal requests a power cycle.
2. Restore power.
3. Wait for stcgal to finish programming.
4. Disconnect the board's power again.
5. Restore power to start the firmware.
6. Check the display and sensor readings before enabling heating.

This command retains the existing memory split.
Without `-t`, stcgal uses the reported frequency as its calibration target.
The Makefile assumes 33.1776 MHz; `src/config.h` requires this explicit HAL configuration.
A different clock frequency changes timer intervals and software delays.
