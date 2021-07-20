OUTPUT_FORMAT(binary)

ENTRY (_start)

INPUT
(
    ./bin/extendedProg.o
    ./bin/kernel.o
    ./bin/IO.o
    ./bin/Keyboard.o
    ./bin/MemoryMap.o
    ./bin/input.o
    ./bin/IDT.o
    ./bin/console.o
    ./bin/stdlib.o
    ./bin/shell.o
    ./bin/Binaries.o
)

OUTPUT
(
    ./bin/kernel.bin
)
SECTIONS
{
    . = 0x8000;

    .text : ALIGN(0x1000)
    {
        *(.text)
    }

    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
	_idt = .;
	. = . + 0x1000;	
    }

    .data : ALIGN(0x1000)
    {
        *(.data)
    }
    
    .rodata : ALIGN(0x1000)
    {
        *(.rodata)
    }
    .bss : ALIGN(0x1000)
    {
        *(COMMON)
        *(.bss)
    }
}
