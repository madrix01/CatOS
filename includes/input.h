#pragma once
#include <TypeDef.h>
#define BUFFER_SIZE 2000

struct circular_buffer{
    char buf[BUFFER_SIZE];
    uint_32 r;
    uint_32 w;
} key_buffer;

static struct{
    uint_8 serial;
    uint_8 keyboard;
} required_satisfied;


enum input {
	INPUT_SERIAL,
	INPUT_KEYBOARD,
    INPUT_BOTH
};

int require_input(enum input option);
int input_read(char *,int);
void key_buffer_append(char c);
char read_key_buffer(bool);