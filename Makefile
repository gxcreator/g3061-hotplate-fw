# Makefile for building the HeatingPlate-PD firmware with SDCC
# (open-source 8051 compiler) instead of Keil C51.
#
# Target: STC8H3K64S2  (64KB flash, 256B IRAM, 3KB XRAM)
# Matches the Keil project's LARGE memory model with floating point.
#
# Usage:   make            -> build/HeatingPlate-PD.hex
#          make clean
#          make format     -> format project-owned C sources and headers
#
# Linker limit: 60 KiB code. The programmed flash/EEPROM split is separate.

SDCC    ?= sdcc
SDAS8051 ?= sdas8051
PACKIHX ?= packihx
HOST_CC ?= cc
CLANG_FORMAT ?= clang-format

SRC_DIR := src
BUILD   := build
TARGET  := HeatingPlate-PD
CODE_SIZE := 0xF000
HAL_DIR := lib/FwLib_STC8

ifneq ($(filter-out clean format,$(if $(MAKECMDGOALS),$(MAKECMDGOALS),all)),)
ifeq ($(wildcard $(HAL_DIR)/include/fw_conf.h),)
$(error FwLib_STC8 is missing. Run 'git submodule update --init --recursive')
endif
endif

# Match the existing clock assumption; do not trim the oscillator at runtime.
HAL_FLAGS := -D__CONF_MCU_MODEL=MCU_MODEL_STC8H3K64S2 \
             -D__CONF_FOSC=33177600UL -D__CONF_CLKDIV=0

MCU_FLAGS := -mmcs51 --model-large \
             --iram-size 256 --xram-size 3072 --code-size $(CODE_SIZE)

CFLAGS  := $(MCU_FLAGS) --fsigned-char --opt-code-size -Isrc \
           -I$(HAL_DIR)/include $(HAL_FLAGS)
LFLAGS  := $(MCU_FLAGS) --out-fmt-ihx

SRCS := main.c ADC.c temperature.c oled.c soft_i2c.c EEPROM.c timer0.c
# SDCC 4.6.0 runtime source, with DUAL_DPTR=1 for the STC8H's DPS selector.
RELS := $(SRCS:%.c=$(BUILD)/%.rel) $(BUILD)/fw_sys.rel $(BUILD)/fw_adc.rel $(BUILD)/crtxinit.rel
HDRS := $(wildcard $(SRC_DIR)/*.h $(HAL_DIR)/include/*.h)
FORMAT_FILES := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*.h tests/*.c tests/*.h)

all: $(BUILD)/$(TARGET).hex
	@awk 'function report(name, used, limit) { \
		printf "%-23s %9d %9d %7.1f%% %9d\n", \
			name, used, limit, (limit ? 100 * used / limit : 0), limit - used; \
	} \
	BEGIN { \
	    printf "========\n" ;\
		printf "%-23s %9s %9s %8s %9s\n", \
			"Memory", "Used (B)", "Limit (B)", "Usage", "Free (B)"; \
	} \
	/^0x[[:xdigit:]]+:[|]/ { \
		n = split($$0, cells, /[|]/); \
		for (i = 2; i < n; i++) { \
			if (cells[i] == "S") stack++; \
			else if (cells[i] == " ") spare++; \
			else allocated++; \
		} \
	} \
	/PAGED EXT\. RAM/ { report("Paged XRAM (shared)", $$(NF-1), $$NF); } \
	/EXTERNAL RAM/ { report("XRAM", $$(NF-1), $$NF); } \
	/ROM\/EPROM\/FLASH/ { report("Flash (linker limit)", $$(NF-1), $$NF); } \
	END { \
		printf "IRAM: %d B static, %d B available for stack, %d B unallocated (%d B total)\n", \
			allocated, stack, spare, allocated + stack + spare; \
		print "Paged XRAM shares XRAM. Stack availability is not measured runtime usage."; \
	}' "$(BUILD)/$(TARGET).mem"

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/%.rel: $(SRC_DIR)/%.c $(HDRS) Makefile | $(BUILD)
	$(SDCC) $(CFLAGS) -c $< -o $@

$(BUILD)/fw_sys.rel: $(HAL_DIR)/src/fw_sys.c $(HDRS) Makefile | $(BUILD)
	# Upstream ticks_ms/ticks_us use read-only __code without const (SDCC 356).
	$(SDCC) $(CFLAGS) --disable-warning 356 -c $< -o $@

$(BUILD)/fw_adc.rel: $(HAL_DIR)/src/fw_adc.c $(HDRS) Makefile | $(BUILD)
	$(SDCC) $(CFLAGS) -c $< -o $@

$(BUILD)/%.rel: $(SRC_DIR)/%.asm Makefile | $(BUILD)
	$(SDAS8051) -plosgff $@ $<

$(BUILD)/$(TARGET).ihx: $(RELS)
	$(SDCC) $(LFLAGS) -o $@ $(RELS)

$(BUILD)/$(TARGET).hex: $(BUILD)/$(TARGET).ihx
	$(PACKIHX) $< > $@

test: $(BUILD)/hal_test
	"$(BUILD)/hal_test"

$(BUILD)/hal_test: tests/hal_test.c $(SRC_DIR)/ADC.c $(HAL_DIR)/src/fw_adc.c $(SRC_DIR)/EEPROM.c $(SRC_DIR)/timer0.c $(SRC_DIR)/soft_i2c.c $(HDRS) Makefile | $(BUILD)
	$(HOST_CC) -std=c11 -O2 -Wall -Wextra -Werror -Wno-parentheses \
		-I$(HAL_DIR)/include $< -o $@

format:
	$(CLANG_FORMAT) --style=file -i $(FORMAT_FILES)

clean:
	rm -rf $(BUILD)

.PHONY: all clean test format
