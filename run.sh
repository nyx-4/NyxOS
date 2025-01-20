#!/bin/bash
set -xue

# QEMU File Path
QEMU=qemu-system-riscv32

# Compiler path and arguments
CC=clang
CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib"

# Build the kernel
$CC $CFLAGS -Wl, -Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf kernel.c common.c

# Start QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot -kernel kernel.elf