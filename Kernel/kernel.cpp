#include "TextPrint.cpp"
#include "colorCodes.h"
#include "IDT.cpp"

extern const char Logo[];
// const char Logo[] = ""; 

extern "C" void _start() {
    SetCursorPos(0); 
    ClearScreen();
    // PrintText("!-----Welcome to sOS-----!\n\r", FG_RED);
    PrintText(Logo, FG_RED);
    InitializeIDT();
    return;
}
