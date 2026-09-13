#!/usr/bin/env bash
set -euo pipefail

KB=mechboards/sofle/r2g
KM=foolmap

wait_for_rp2() {
    echo "Waiting for a half to appear in bootloader mode" >&2
    while true; do
        local dev
        dev=$(lsblk -rno NAME,LABEL 2>/dev/null | awk '$2=="RPI-RP2"{print $1; exit}')
        if [ -n "${dev:-}" ]; then
            echo "/dev/$dev"
            return 0
        fi
        sleep 1
    done
}

wait_for_gone() {
    local dev="$1"
    echo "Waiting for $dev to disappear" >&2
    while lsblk "$dev" >/dev/null 2>&1; do
        sleep 1
    done
}

flash_one() {
    local n="$1"
    echo
    echo "Half $n: put it into bootloader mode"
    local dev
    dev=$(wait_for_rp2)
    echo "Found $dev, mounting"
    udisksctl mount -b "$dev" >/dev/null 2>&1 || true
    echo "Flashing $KB ($KM)"
    qmk flash -kb "$KB" -km "$KM"
    wait_for_gone "$dev"
    echo "Half $n flashed."
}

flash_one 1
flash_one 2

echo
echo "Both halves flashed."
