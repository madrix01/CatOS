nasm -f bin ./Sector1/boot.asm -o ./bin/boot.bin
nasm -f bin ./Sector2+/extendedProg.asm -o ./bin/extendedProg.bin
cd ./bin
cat boot.bin extendedProg.bin >> boot.bin
qemu-system-x86_64 ../bin/boot.bin