#include "TextPrint.cpp"
#include "colorCodes.h"
#include "IDT.cpp"
#include "Keyboard.cpp"
#include "shell.cpp"
#include "input.h"

extern const char Logo[];

extern "C" void _start() {
    SetCursorPos(0); 
    ClearScreen();
    PrintText(Logo, FG_LRED);
    PrintText("\n\r\n\r");
    InitializeIDT();
    require_input(INPUT_BOTH);
    MainKeyBoardHandler = KeyboardHandler;
    while(true)
        BasicShell();
    return;
}
