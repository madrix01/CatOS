#pragma once 
#include "../libs/stdlib.cpp"
#include "../drivers/console.cpp"

extern "C" void shutdown();

void programRun(void* bufPtr, int buf_size){
    if(memcmp(bufPtr, "hello", 5) == 0){
        write("Hello there !!!");
    }else if(memcmp(bufPtr, "exit", 4) == 0){
        write("exiting");
        shutdown();
    }
}