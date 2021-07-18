#pragma once

enum input {
	INPUT_SERIAL,
	INPUT_KEYBOARD,
    INPUT_BOTH
};

int require_input(enum input option);
int input_read(char *,int);
void key_buffer_append(char c);
char read_key_buffer(bool);