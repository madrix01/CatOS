nasm -f bin boot.asm -o ./bin/boot.bin
qemu-system-x86_64 ./bin/boot.bin