#include <drivers/console.h>
#include <colorCodes.h>
#include <input.h>
#include <IDT.h>
#include <Keyboard.h>
#include <Shell/shell.h>
#include <MemoryMap.h>
#include <mem/heap.h>


extern const char Logo[];

extern "C" void _start() {
    console_required();
    write(Logo, FG_LBLUE);
    write("\n\r");
    InitializeIDT();
    require_input(INPUT_BOTH);
    MainKeyBoardHandler = StandardKeyBoardHandler;
    InitializeHeap(0x100000, 0x100000);
    void* TestMemoryAddress = malloc(64);
    write(HexToString((uint_64)TestMemoryAddress));
    while(true)
        BasicShell();
    return;
}

