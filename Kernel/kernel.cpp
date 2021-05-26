#include "TextPrint.cpp"
#include "colorCodes.h"
#include "IDT.cpp"
extern const char Logo[];

extern "C" void _start() {
    InitializeIDT();

    ClearScreen();
    SetCursorPos(0); 
    PrintText("!-----Welcome to sOS-----!\n\r", FG_RED);
    PrintText(Logo);
    return;
}
