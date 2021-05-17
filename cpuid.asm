; %include "print.asm"

DetectCpuId:
    pushfd  ;push flag onto stack
    pop eax ;pop value in eax register
    mov ecx, eax

    xor eax, 1 << 21    ; flip the bit  

    push eax
    popfd
    
    pushfd
    pop eax
    
    push ecx
    popfd

    xor eax, ecx
    jz NoCpuId
    ret

DetectLongMode:
    mov eax, 0x80000001
    cpuid
    test edx, 1 << 29
    jz NoLongMode
    ret

ErrorDetect:
    db 'Error',0ah ,0

NoLongMode:
    ; mov bx, [ErrorDetect] 
    ; call PrintString
    ; jmp $
    hlt ;no longModesupport
NoCpuId:
    ; mov bx, [ErrorDetect] 
    ; call PrintString
    ; jmp $
    hlt ;no cpuid support