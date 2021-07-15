#pragma once 
#include "../libs/stdlib.cpp"
#include "../drivers/console.cpp"
#include "../colorCodes.h"

extern "C" void shutdown();

void programRun(void* bufPtr, int buf_size){
    if(memcmp(bufPtr, "hello", 5) == 0){
        write("Hello there !!!");
    }else if(memcmp(bufPtr, "exit", 4) == 0){
        write("exiting");
        shutdown();
    }else if(memcmp(bufPtr, "whoami", 6) == 0){
        write("CatOS v0.0.1 (alpha)", FG_LBLUE);
    }else if(memcmp(bufPtr, "clear", 5) == 0){
        ClearScreen();
    }else{
        write("[CatOS] Command not found", 0x0C);
    }
}