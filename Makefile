NASM = nasm
QEMU = qemu-system-i386
BOOT_BIN = boot/boot.bin
IMAGE = os.img

all: $(IMAGE)

$(BOOT_BIN): boot/boot.asm
	$(NASM) -f bin -o $@ $<

$(IMAGE): $(BOOT_BIN)
	cp $(BOOT_BIN) $(IMAGE)
	truncate -s 1474560 $(IMAGE)

run: $(IMAGE)
	$(QEMU) -drive format=raw,file=$(IMAGE),if=ide

clean:
	rm -f $(BOOT_BIN) $(IMAGE)

.PHONY: all run clean
