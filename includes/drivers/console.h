#pragma once
#include <TypeDef.h>
#include <colorCodes.h>


static void init_cursor(void);
static void enable_cursor(void);
static void update_cursor(int x, int y);
static inline uint_8 vga_entry_color(uint_8 fg, uint_8 bg);
static inline uint_16 vga_entry(unsigned char uc, uint_8 color);
static void scroll(void);
void console_required();
static void putchar(char c, uint_8 color, uint_32 x, uint_32 y);
extern void putch(char c, uint_8 color);
static void write(const char* s, uint_8 color);
void ClearScreen(uint_64 ClearColor);
template<typename T>
const char* IntegerToString(T value);