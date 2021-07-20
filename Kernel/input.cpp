#include <input.h>

// extern "C" 
char read_key_buffer(bool blocking){
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

// extern "C"
int input_read(char* buf, int size){
    if(required_satisfied.keyboard || required_satisfied.serial){
        int char_read = 0; 
        while(char_read < size){
            char c = read_key_buffer(true);
            if(c == '\b'){
                --buf;
                --char_read;
            }else if(c == '\n'){
                return char_read;
            }
            else{
                *buf = c;
                buf++;
                char_read++;
            }
            if(c == 0){
                return char_read;
            }
        }
        return char_read;
    }else{
        return 0;
    }
    return 0;
}

// extern 
void key_buffer_append(char c){
    if(c == 0) return;

    if(key_buffer.w == (key_buffer.r + BUFFER_SIZE - 1) % BUFFER_SIZE){
        key_buffer.w = 0;
        key_buffer.r = 0;
    }
    // PrintChar(c);
    if(c == '\b'){
        --key_buffer.w;
        --key_buffer.r;
    }
    
    key_buffer.buf[key_buffer.w] = c;
    key_buffer.w = (key_buffer.w + 1) % BUFFER_SIZE;
    return; 
}

// extern "C"
int require_input(enum input option){
    switch (option){
        case INPUT_SERIAL:
            if (required_satisfied.serial) return 1;
            required_satisfied.serial = 1;
            return 1;
        
        case INPUT_KEYBOARD:
            required_satisfied.keyboard = 1;
            return 1;
        
        case INPUT_BOTH:
            if(!required_satisfied.serial){
                required_satisfied.serial = 1;
            }
            if(!required_satisfied.keyboard){
                required_satisfied.keyboard = 1;
            }
            return 1;
        default:
            return 0;
    }
}