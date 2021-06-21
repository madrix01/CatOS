#pragma once
#include "TypeDef.cpp"

void* memset(void* bufptr, uint_8 value, int size){
    unsigned char* buf = (unsigned char*)bufptr;
    for(int i = 0; i < size; i++){
        buf[i] = (unsigned char) value;
    }
    return bufptr;
}