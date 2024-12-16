#!/bin/bash

# Default values
PROGRAMMER="openocd"
FIRMWARE="./cfw.elf"
CONFIG="-f interface/stlink.cfg -f target/stm32f4x.cfg"
# Config for dfu-util
#CONFIG="-v -d 0483:df11 -a 0 -s 0x08000000:leave"

# Function to display usage
usage() 
{
    echo "Usage: $0 --programmer <programmer> --firmware <firmware> [--config <cfg>]"
    exit 1
}

# Parse command-line arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        --programmer) PROGRAMMER="$2"; shift ;;
        --firmware) FIRMWARE="$2"; shift ;;
        --config) CONFIG="$2"; shift ;;
        *) usage ;;
    esac
    shift
done

# Flash firmware based on selected programmer
if [ "$PROGRAMMER" = "openocd" ]; then
    echo "Using OpenOCD to flash firmware..."
    openocd $CONFIG -c "program $FIRMWARE verify reset exit"
elif [ "$PROGRAMMER" = "dfu-util" ]; then
    echo "Using DFU-Util to flash firmware..."
    arm-none-eabi-objcopy -O binary $FIRMWARE cfw.bin
    dfu-util $CONFIG -D cfw.bin
else
    echo "Unknown programmer: $PROGRAMMER"
    exit 1
fi