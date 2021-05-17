[org 0x7c00]

mov bp, 0x7c00  ;program loads into 0x7c00 when boots
mov sp, bp

; clears the screen
mov ah, 0x00
mov al, 0x03
int 10h

mov [BOOT_DISK], dl ; lower data register

mov bx, TestString
call PrintString ; calls the address of printstring

; Reading from extendedDisk
call ReadDisk


jmp PROGRAM_SPACE

%include 'print.asm'
%include 'diskRead.asm'

times 510-($ - $$) db 0
db 0x55, 0xaa