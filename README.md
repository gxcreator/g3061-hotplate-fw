# HeatingPlate-PD

This project ports the original Keil firmware to SDCC for the STC8H3K64S2 microcontroller.
It controls a heating plate with an OLED display, buttons, and settings stored in EEPROM.
EEPROM retains settings without power.

![G3061](G3061-small2.jpg)

## Requirements

- Linux with GNU Make.
- SDCC, including `sdas8051` and `packihx`.
- Python 3 with `venv` support.
- [stcgal](https://github.com/grigorig/stcgal) to program the board through a USB-to-UART adapter.

Hardware tests used SDCC 4.6.0.
Other compiler versions need separate tests.

On Debian or Ubuntu, install the tools:

```bash
sudo apt update
sudo apt install make sdcc python3-venv
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
make
```

The build produces `build/HeatingPlate-PD.hex`.
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
The source assumes 33.1776 MHz in `src/config.h`.
A different clock frequency changes timer intervals and software delays.
