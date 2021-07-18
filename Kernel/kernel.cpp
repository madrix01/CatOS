// #include <idt.h>
#include <drivers/console.h>
#include <colorCodes.h>
#include "input.cpp"
#include "IDT.cpp"
#include "Keyboard.cpp"
#include "./Shell/shell.cpp"
#include "MemoryMap.cpp"

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
