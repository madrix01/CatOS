#pragma once
#include "TextPrint.cpp"	
#include "input.cpp"
#include "IDT.cpp"
#include "shellkb.cpp"

void print_prompt(){
	char buf[3] = {0};
	PrintText("> ", FG_LGRN);
	input_read(buf, 3);
	PrintText("\n\r");
	if(buf == "ls "){
		PrintText("Here are you files");
	}
	PrintText("\n\r");
}


void BasicShell(){
	MainKeyBoardHandler = ShellKeyBoardHandler;
	print_prompt();
}