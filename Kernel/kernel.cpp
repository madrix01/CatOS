#include "TextPrint.cpp"
#include "colorCodes.h"
#include "IDT.cpp"

extern const char Logo[];
// const char Logo[] = ""; 

extern "C" void _start() {
    SetCursorPos(0); 
    ClearScreen();
    PrintText(Logo, FG_LRED);
    InitializeIDT();
    return;
}
