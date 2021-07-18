#pragma once
#include <TypeDef.h>

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
extern "C" void InitializeIDT();
void (*MainKeyBoardHandler)(uint_8 scanCode, uint_8 chr);
// extern "C" void isr1_handler();
