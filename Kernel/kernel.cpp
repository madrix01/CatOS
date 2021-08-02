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
    void* TestMemoryAddress = malloc(0x10);
	void* TestMemoryAddress2 = malloc(0x1);
	void* TestMemoryAddress3 = malloc(0x10);
    write(HexToString((uint_64)TestMemoryAddress));
   	write("\n\r");
	write(HexToString((uint_64)TestMemoryAddress2));
 	write("\n\r");
	write(HexToString((uint_64)TestMemoryAddress3));
	write("\n\r");
	while(true)
        BasicShell();
    return;
}

