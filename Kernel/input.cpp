#include "TypeDef.cpp"
#include "input.h"
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


extern char read_key_buffer(bool blocking){
    char c;
    if(blocking){
        while(key_buffer.w == key_buffer.r){
            asm volatile("nop");
        }
    }

    c = key_buffer.buf[key_buffer.r];
    key_buffer.r = (key_buffer.r + 1)%BUFFER_SIZE;

    return c;
}

extern int input_read(char* buf, int size){
    if(required_satisfied.keyboard || required_satisfied.serial){
        int char_read = 0;
        while(char_read < size){
            char c = read_key_buffer(true);
            if(c == 0)
                return char_read;
            
            *buf = c;
            buf++;
            char_read++;
        }
    }else{
        return 0;
    }
    return 0;
}

extern void key_buffer_append(char c){
    if(c == 0) return;

    if(key_buffer.w == (key_buffer.r + BUFFER_SIZE - 1) % BUFFER_SIZE){
        key_buffer.w = 0;
        key_buffer.r = 0;
    }
    if(c == '\b'){
        --key_buffer.w;
        --key_buffer.r;
    }
    
    key_buffer.buf[key_buffer.w] = c;
    key_buffer.w = (key_buffer.w + 1) % BUFFER_SIZE;
    return; 
}