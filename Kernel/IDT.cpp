#pragma once
#include "TypeDef.cpp"
#include "TextPrint.cpp"

struct IDT64{
	uint_16 offset_low;
	uint_16 selector;
	uint_8 ist;
	uint_8 types_attr;
	uint_16 offset_mid;
	uint_32 offset_high;
	uint_32 zero;
};

extern IDT64 _idt[256];
extern uint_64 isr1;
extern "C" void LoadIDT();


void InitializeIDT(){
    for(uint_64 t = 0; t < 256; t++){
        _idt[t].zero = 0;
        _idt[t].offset_low = (uint_16)(((uint_64)&isr1 & 0x000000000000ffff));
        _idt[t].offset_mid = (uint_16)(((uint_64)&isr1 & 0x00000000ffff0000) >> 16);
        _idt[t].offset_high = (uint_32)(((uint_64)&isr1 & 0xffffffff00000000) >> 32);
        _idt[t].ist = 0;
        _idt[t].selector = 0x08;
        _idt[t].types_attr = 0x8e;
        // Declares it as 32 bit interrupt gate 
    }
    // reprogramming pick chip 
    outb(0x21, 0xfd);
    outb(0xA1, 0xff);
    LoadIDT();

}


extern "C" void isr1_handler(){
    // signify the pick chip that interrupt is finished
    // PrintText("!-----Welcome to sOS-----!\n\r", FG_RED);
    PrintText(HexToString(inb(0x60)));
    outb(0x20, 0x20);
    outb(0xa0, 0x20);

}

