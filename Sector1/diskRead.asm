PROGRAM_SPACE equ 0x8000    ; declaring constant

ReadDisk:
    mov ah, 0x02            ; Read sectors from drive
    mov bx, PROGRAM_SPACE   ; define location
    mov al, 64              ; how many sectors to read
    mov dl, [BOOT_DISK]     ; drive 
    mov ch, 0x00            ; cylinder
    mov dh, 0x00            ; head
    mov cl, 0x02            ; sector -start reading the second sector 
    int 0x13                ; interupt for reading file
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