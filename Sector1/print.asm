PrintString:
    mov ah, 0x0e
    .Loop:
    cmp [bx], byte 0
    je .Exit
        mov al, [bx]
        int 0x10
        inc bx
        jmp .Loop
    mov al, [bx]
    .Exit:
    ret

TestString:
    db 0ah, '!-----| Welcome to sOS |-----!',0ah ,0