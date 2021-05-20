; [org 0x8000]
; [org 0x7e00]

jmp EnterProtectedMode

%include "./Sector2+/gdt.asm"
%include "./Sector1/print.asm"


EnterProtectedMode:
    call EnableA20                  ; so that all memory can be accessed
    cli                             ; disables interrupts
    lgdt [gdt_descriptor]           ; loading gdt
    mov eax, cr0                    ; 0 bit of eax states protected mode 
    or eax, 1                       ; or with 1 enables it
    mov cr0, eax
    jmp codeseg:StartProtectedMode

EnableA20:
    in al, 0x92
    or al, 2
    out 0x92, al
    ret

[bits 32]

%include "./Sector2+/cpuid.asm"
%include "./Sector2+/simplePaging.asm"

StartProtectedMode:

    mov ax, dataseg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov [0xb8000], byte 'H'

    call DetectCpuId
    call DetectLongMode
    call SetupIdentityPaging
    call EditGDT
    jmp codeseg:Start64Bit

[bits 64]
[extern _start]

Start64Bit:
    mov edi, 0xb8000
    mov rax, 0x1f201f201f201f20
    mov ecx, 500
    rep stosq
    call _start
    jmp $

times 2048-($-$$) db 0
