#pragma once
#include "./TypeDef.cpp"

// Put one byte out on the address we specify
void outb(uint_16 port, uint_8 val) {
	asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

uint_8 inb(uint_16 port) {
	uint_8 returnVal;
	asm volatile ("inb %1, %0"
		: "=a"(returnVal)
		: "Nd"(port));
	return returnVal;
}