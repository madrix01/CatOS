.SILENT : start

start:
	rm -R ./bin
	mkdir bin
	nasm -f bin ./Sector1/boot.asm -o ./bin/boot.bin
	nasm -f elf64 ./Sector2+/extendedProg.asm -o ./bin/extendedProg.o
	nasm -f elf64 ./Kernel/Binaries.asm -o ./bin/Binaries.o
	x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -I ./includes -m64 -c "./Kernel/kernel.cpp" -o "./bin/kernel.o"
	x86_64-elf-ld -T"link.ld"
	cat ./bin/boot.bin ./bin/kernel.bin >> ./bin/CatOS.bin
	qemu-system-x86_64 -fda  ./bin/CatOS.bin
