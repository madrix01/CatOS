#pragma once
#include "TextPrint.cpp"	
#include "input.cpp"


void print_prompt(){
	char buf[3] = {0};
	PrintText("> ", FG_LGRN);
	input_read(buf, 3);
	PrintText("\n\r");
	if(buf[0] == 'l' && buf[1] == 's'){
		PrintText("Here are you files");
	}

	// PrintText("\n\rChar 1: ");
	// PrintText(IntegerToString((int)buf[0]));
	// PrintText("\n\rChar 2: ");
	// PrintText(IntegerToString((int)buf[1]));
	// PrintText("\n\rChar 3: ");
	// PrintText(IntegerToString((int)buf[2]));

	// PrintText(buf);
	PrintText("\n\r");
}


void BasicShell(){
	print_prompt();
}