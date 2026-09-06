# Makefile for building the HeatingPlate-PD firmware with SDCC
# (open-source 8051 compiler) instead of Keil C51.
#
# Target: STC8H3K64S2  (64KB flash, 256B IRAM, 3KB XRAM)
# Matches the Keil project's LARGE memory model with floating point.
#
# Usage:   make            -> build/HeatingPlate-PD.hex
#          make clean
#
# Flash layout: 60 KiB code (0x0000-0xEFFF), 4 KiB IAP EEPROM.
# Configure STC-ISP for 4 KiB EEPROM before flashing this image.

SDCC    ?= sdcc
SDAS8051 ?= sdas8051
PACKIHX ?= packihx

SRC_DIR := src
BUILD   := build
TARGET  := HeatingPlate-PD
CODE_SIZE := 0xF000

MCU_FLAGS := -mmcs51 --model-large \
             --iram-size 256 --xram-size 3072 --code-size $(CODE_SIZE)

CFLAGS  := $(MCU_FLAGS) --fsigned-char --opt-code-size -Isrc
LFLAGS  := $(MCU_FLAGS) --out-fmt-ihx

SRCS := main.c ADC.c temperature.c oled.c EEPROM.c timer0.c
# SDCC 4.6.0 runtime source, with DUAL_DPTR=1 for the STC8H's DPS selector.
RELS := $(SRCS:%.c=$(BUILD)/%.rel) $(BUILD)/crtxinit.rel
HDRS := $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/*.H)

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

$(BUILD)/%.rel: $(SRC_DIR)/%.asm Makefile | $(BUILD)
	$(SDAS8051) -plosgff $@ $<

$(BUILD)/$(TARGET).ihx: $(RELS)
	$(SDCC) $(LFLAGS) -o $@ $(RELS)

$(BUILD)/$(TARGET).hex: $(BUILD)/$(TARGET).ihx
	$(PACKIHX) $< > $@

clean:
	rm -rf $(BUILD)

.PHONY: all clean
