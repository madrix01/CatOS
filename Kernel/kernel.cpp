#include "input.h"
#include "./drivers/console.cpp"
#include "colorCodes.h"
#include "IDT.cpp"
#include "Keyboard.cpp"
#include "./Shell/shell.cpp"

extern const char Logo[];

extern "C" void _start() {
    console_required();
    write(Logo, FG_LBLUE);
    write("\n\r");
    InitializeIDT();
    require_input(INPUT_BOTH);
    MainKeyBoardHandler = StandardKeyBoardHandler;
    while(true)
        BasicShell();
    return;
}
