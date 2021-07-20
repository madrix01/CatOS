.SILENT : start

start:
	rm -R ./bin
	mkdir bin
	nasm -f bin ./Sector1/boot.asm -o ./bin/boot.bin
	nasm -f elf64 ./Sector2+/extendedProg.asm -o ./bin/extendedProg.o
	nasm -f elf64 ./Kernel/Binaries.asm -o ./bin/Binaries.o
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/kernel.cpp" -o "./bin/kernel.o"
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/IDT.cpp" -o "./bin/IDT.o"
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/IO.cpp" -o "./bin/IO.o"
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/Keyboard.cpp" -o "./bin/Keyboard.o"
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/MemoryMap.cpp" -o "./bin/MemoryMap.o"
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/input.cpp" -o "./bin/input.o"
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/drivers/console.cpp" -o "./bin/console.o"
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/libs/stdlib.cpp" -o "./bin/stdlib.o"
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/Shell/shell.cpp" -o "./bin/shell.o"

	x86_64-elf-ld -T"link.ld"
	cat ./bin/boot.bin ./bin/kernel.bin >> ./bin/CatOS.bin
	qemu-system-x86_64 -fda  ./bin/CatOS.bin
