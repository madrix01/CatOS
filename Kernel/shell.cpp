#pragma once
#include "TextPrint.cpp"	
#include "input.cpp" 

void print_prompt(){
	char buf[3] = {0};
	PrintText("> ", FG_LGRN);
	input_read(buf, 2);
	PrintText(buf);
}


void BasicShell(){
	print_prompt();
}