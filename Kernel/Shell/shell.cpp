#pragma once
#include "../drivers/console.cpp"	
#include "../input.cpp"
#include "../IDT.cpp"
#include "../libs/stdlib.cpp"
#include "../Programs/console.cpp"

void print_prompt(){
	char buf[128];
	memset(buf, 0, 128);
	write("> ", FG_LGRN);
	int buf_size = input_read(buf, 128);
	programRun(buf, buf_size);
	write("\n\r");
	memset(buf, 0, buf_size);
}


void BasicShell(){
	print_prompt();
}