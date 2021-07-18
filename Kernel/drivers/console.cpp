#pragma once
#include <TypeDef.h>
#include "../libs/stdlib.cpp"
#include "../IO.cpp"
#include <colorCodes.h>

static const uint_32 vgaWIDTH = 80;
static const uint_32 VGA_HEIGHT = 25;
static uint_32 terminal_row, terminal_column;
static uint_8 terminal_color;
static uint_16* terminal_buffer;


static void init_cursor(void);

static void enable_cursor(void);


static void update_cursor(int x, int y);

enum colors {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};


static inline uint_8 vga_entry_color(uint_8 fg, uint_8 bg){
	return (fg | bg << 4);
}

static inline uint_16 vga_entry(unsigned char uc, uint_8 color){
	return (uint_16) uc | (uint_16) color << 8;
}

static void scroll(void){
	uint_16 blank = vga_entry(' ', terminal_color);
	if(terminal_row >= 25) {
		int i;
		for(i = 0*80; i < 24*80; i++)
			terminal_buffer[i] = terminal_buffer[i+80];
		
		for(i = 24*80; i < 25*80; i++)
			terminal_buffer[i] = blank;
		terminal_row = 24;
		update_cursor(terminal_column, terminal_row);
	}
}

void console_required(){
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(FG_LGRY, BG_BLACK);
	terminal_buffer = (uint_16*)0xb8000;
	init_cursor();
	for(uint_32 y = 0; y < VGA_HEIGHT; y++){
		for(uint_32 x = 0; x < vgaWIDTH; x++){
			const uint_32 index = y*vgaWIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

static void putchar(char c, uint_8 color, uint_32 x, uint_32 y){
	const uint_32 index = y*vgaWIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void putch(char c, uint_8 color = VGA_COLOR_WHITE){
	if(c == '\n'){
		terminal_row++;
		terminal_column = 0;
	}else if(c == '\b'){
		if(terminal_column == 0){

		}else{
			terminal_column--;
			putch(' ');
			terminal_column--;
		}
	}else if(c == '\t'){
		for(int x = 0; x < 4; x++)
			putch(' ');	
	}else if(c == '\r'){
		terminal_column = 0;
	}else{
		putchar(c, color, terminal_column, terminal_row);
		++terminal_column;
	}
	scroll();
	update_cursor(terminal_column, terminal_row);
}

static void write(const char* s, uint_8 color = VGA_COLOR_WHITE){
	uint_32 index = 0;
	while(s[index] != 0){
		putch(s[index], color);
		index++;	
	}
}

static void init_cursor(void){
	enable_cursor();
	update_cursor(0, 0);
}

static void enable_cursor(void){
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | 14);
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | 15);
}

static void update_cursor(int x, int y){	

	uint_16 pos = terminal_row * vgaWIDTH + terminal_column;	
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint_8) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint_8) ((pos >> 8) & 0xFF));
}

char integerToStringOut[128];
template<typename T>
const char* IntegerToString(T value){
    uint_8 isNegative = 0;

    if(value < 0){
        isNegative = true;
        value *= -1;
        integerToStringOut[0] = '-';
    }

    uint_8 size = 0;
    uint_64 sizeTester = (uint_64)value;
    while(sizeTester/10 > 0){
        sizeTester /= 10;
        size++;
    }

    uint_8 index = 0;
    uint_64 newVal = (uint_64)value;
    while(newVal/10 > 0){
        uint_8 remainder = newVal%10;
        newVal /= 10;
        integerToStringOut[isNegative + size - index] = remainder + 48;
        index++;
    }

    uint_8 remainder = newVal%10;
    integerToStringOut[isNegative + size - index] = remainder + 48;
    integerToStringOut[isNegative + size + 1] = 0;
    return integerToStringOut;
}

void ClearScreen(uint_64 ClearColor = BG_BLACK | FG_WHITE){
	uint_16 blank = vga_entry(' ', terminal_color);
	int i;

	for(i = 0*80; i < 25*80; i++){
		terminal_buffer[i] = blank;
	}
	terminal_column = 0;
	terminal_row = 0;
	update_cursor(terminal_column, terminal_row);
}
