[extern _idt]
idtDescriptor:
    dw 4095     ;size of the IDT
    dq _idt     ;base offset of our IDT


    %macro PUSHALL 0
  	    push rax
  	    push rcx
  	    push rdx
  	    push r8
  	    push r9
  	    push r10
  	    push r11
    %endmacro

    %macro POPALL 0
  	    pop r11
  	    pop r10
  	    pop r9
  	    pop r8
  	    pop rdx
  	    pop rcx
  	    pop rax
    %endmacro    

[extern isr1_handler]

isr1:           ;interrupt service return 1
    PUSHALL
    call isr1_handler
    POPALL
    iretq       ;interrupt return q(quad)
    GLOBAL isr1
    
LoadIDT:
    lidt[idtDescriptor]
    sti         ; set interrupt flag
    ret         ; returns 
    GLOBAL LoadIDT  ;makes function global
