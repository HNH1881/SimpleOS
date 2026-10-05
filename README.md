# SimpleOS

A minimal operating system project for learning:

- x86 assembly
- C in a freestanding environment
- boot process and memory layout
- compiler/linker basics
- a simple bare-metal workflow with QEMU

## Project goals

1. Build a minimal boot sector that can run on x86 hardware or QEMU.
2. Learn how the CPU starts and loads the first instructions.
3. Move from assembly to a tiny C kernel.
4. Understand memory, interrupts, and system startup.

## Requirements

On Arch Linux:

```bash
sudo pacman -S --needed make nasm qemu-system-x86 gcc
```

## Build

```bash
make
```

## Run

```bash
make run
```

This builds a simple boot sector image `os.img` and launches it with QEMU.

The current project is intentionally minimal: it boots into a small assembly program that prints `Hello, OS!` and halts. The next step is to replace this with a tiny C kernel and then add memory management, interrupts, and a shell.

## Directory structure

- `boot/boot.asm` - the bootloader entry point
- `kernel/kernel.c` - C kernel skeleton for later stages
- `Makefile` - build and run automation

## Suggested learning path

1. Master x86 registers and addressing modes
2. Understand BIOS interrupt calls
3. Learn protected mode and segmentation
4. Build a 32-bit C kernel
5. Add paging, interrupts, and a scheduler
6. Add basic drivers and a shell

## Helpful resources

- OSDev Wiki
- xv6 (MIT teaching OS)
- JamesM's kernel development tutorials
- The little book about OS development
