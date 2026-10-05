bits 16
org 0x7c00

start:
    cli
    mov ax, 0x07c0
    mov ds, ax
    mov es, ax
    mov si, message
    call print_string
    jmp hang

print_string:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    mov bx, 0x0007
    int 0x10
    jmp print_string
.done:
    ret

hang:
    cli
    hlt
    jmp hang

message db "Hello, OS!", 0

times 510 - ($ - $$) db 0
 dw 0xAA55
