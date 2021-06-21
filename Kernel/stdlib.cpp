#pragma once
#include "TypeDef.cpp"

void* memset(void* bufptr, uint_8 value, int size){
    unsigned char* buf = (unsigned char*)bufptr;
    for(int i = 0; i < size; i++){
        buf[i] = (unsigned char) value;
    }
    return bufptr;
}

int memcmp(const void* aptr, const void* bptr, int size){
    const uint_8 *a = (const uint_8*) aptr;
    const uint_8 *b = (const uint_8*) bptr;

    for(int i = 0; i < size; i++){
        if(a[i] < b[i])
            return -1;
        else if(b[i] < a[i])
            return 1;   
    }

    return 0;
}