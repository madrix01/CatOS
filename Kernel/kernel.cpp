#include "TextPrint.cpp"
#include "colorCodes.h"
#include "IDT.cpp"
#include "Keyboard.cpp"
#include "shell.cpp"

extern const char Logo[];

extern "C" void _start() {
    SetCursorPos(0); 
    ClearScreen();
    PrintText(Logo, FG_LRED);
    PrintText("\n\r\n\r");
    InitializeIDT();
    MainKeyBoardHandler = KeyboardHandler;
    BasicShell();
    return;
}
