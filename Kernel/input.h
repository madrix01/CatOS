#pragma once

enum input {
	INPUT_SERIAL,
	INPUT_KEYBOARD,
    INPUT_BOTH
};

extern "C" int require_input(enum input option);
extern "C" int input_read(char *,int);
extern "C" void key_buffer_append(char c);
extern "C" char read_key_buffer(bool);