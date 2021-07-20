#pragma once
#include <TypeDef.h>
#include <IO.h>
#include <kbScanCodeS1.h>
#include <input.h>

struct IDT64{
	uint_16 offset_low;
	uint_16 selector;
	uint_8 ist;
	uint_8 types_attr;
	uint_16 offset_mid;
	uint_32 offset_high;
	uint_32 zero;
};


void (*MainKeyBoardHandler)(uint_8 scanCode, uint_8 chr);
void InitializeIDT();