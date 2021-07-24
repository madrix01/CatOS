.SILENT : start

GCC = x86_64-elf-gcc
LINKER = x86_64-elf-ld
QEMU = qemu-system-x86_64
CFLAGS = -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c
BUILDDIR = ./bin
KDIR = ./Kernel
S1DIR = ./Sector1
S2DIR = ./Sector2+


start:
	rm -R ./bin
	mkdir bin
	nasm -f bin ${S1DIR}/boot.asm -o ${BUILDDIR}/boot.bin
	nasm -f elf64 ${S2DIR}/extendedProg.asm -o ./bin/extendedProg.o
	nasm -f elf64 ${KDIR}/Binaries.asm -o ./bin/Binaries.o
	
	${GCC} ${CFLAGS} "${KDIR}/kernel.cpp" -o "${BUILDDIR}/kernel.o"
	${GCC} ${CFLAGS} "${KDIR}/IDT.cpp" -o "${BUILDDIR}/IDT.o"
	${GCC} ${CFLAGS} "${KDIR}/IO.cpp" -o "${BUILDDIR}/IO.o"
	${GCC} ${CFLAGS} "${KDIR}/Keyboard.cpp" -o "${BUILDDIR}/Keyboard.o"
	${GCC} ${CFLAGS} "${KDIR}/MemoryMap.cpp" -o "${BUILDDIR}/MemoryMap.o"
	${GCC} ${CFLAGS} "${KDIR}/input.cpp" -o "${BUILDDIR}/input.o"
	${GCC} ${CFLAGS} "${KDIR}/drivers/console.cpp" -o "${BUILDDIR}/console.o"
	${GCC} ${CFLAGS} "${KDIR}/libs/stdlib.cpp" -o "${BUILDDIR}/stdlib.o"
	${GCC} ${CFLAGS} "${KDIR}/Shell/shell.cpp" -o "${BUILDDIR}/shell.o"
	${GCC} ${CFLAGS} "${KDIR}/mem/heap.cpp" -o "${BUILDDIR}/heap.o"

	${LINKER} -T"link.ld"
	cat ${BUILDDIR}/boot.bin ${BUILDDIR}/kernel.bin >> ${BUILDDIR}/CatOS.bin
	${QEMU} -fda  ${BUILDDIR}/CatOS.bin