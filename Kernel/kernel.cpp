#include <drivers/console.h>
#include <colorCodes.h>
#include <input.h>
#include <IDT.h>
#include <Keyboard.h>
#include <Shell/shell.h>
#include <MemoryMap.h>

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
