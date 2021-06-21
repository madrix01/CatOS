#pragma once 
#include "../libs/stdlib.cpp"
#include "../TextPrint.cpp"

void programRun(void* bufPtr){
    if(memcmp(bufPtr, "hello", 5) == 0){
        PrintText("Hello There !!\n\r");
    }
}