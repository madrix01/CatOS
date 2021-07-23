#pragma once
#include <TypeDef.h>
#include <colorCodes.h>
#include <IO.h>
#include <libs/stdlib.h>

static void init_cursor(void);
static void enable_cursor(void);
static void update_cursor(int x, int y);
static inline uint_8 vga_entry_color(uint_8 fg, uint_8 bg);
static inline uint_16 vga_entry(unsigned char uc, uint_8 color);
static void scroll(void);
void console_required();
static void putchar(char c, uint_8 color, uint_32 x, uint_32 y);
extern void putch(char c, uint_8 color = FG_WHITE);
extern void write(const char* s, uint_8 color = FG_WHITE);
void ClearScreen(uint_64 ClearColor = BG_BLACK | FG_WHITE);

static char integerToStringOut[128];
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