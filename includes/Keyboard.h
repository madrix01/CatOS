#pragma once
#include <TypeDef.h>
#include <drivers/console.h>

extern bool leftShiftPressed, rightShiftPressed;
extern uint_8 LastScanCode;
extern void StandardKeyBoardHandler(uint_8 scanCode, uint_8 chr);