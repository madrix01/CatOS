PROGRAM_SPACE equ 0x7e00 ; declaring constant

ReadDisk:
    mov ah, 0x02
    mov bx, PROGRAM_SPACE ; define location
    mov al, 4 ; how many sectors to read
    mov dl, [BOOT_DISK]
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02 ; start reading the second sector
    int 0x13 ; interupt for reading file
    jc DiskReadFailed
    ret


BOOT_DISK:
    db 0

DiskReadError:
    db 'Disk read failed :(', 0

DiskReadFailed:
    mov bx, DiskReadError
    call PrintString
    jmp $