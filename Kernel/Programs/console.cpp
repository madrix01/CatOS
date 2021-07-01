#pragma once 
#include "../libs/stdlib.cpp"
#include "../TextPrint.cpp"
#include "../drivers/console.cpp"

extern "C" void shutdown();

void programRun(void* bufPtr, int buf_size){
    if(memcmp(bufPtr, "hello", buf_size) == 0){
        write("Hello there !!!");
    }else if(memcmp(bufPtr, "exit", buf_size) == 0){
        write("exiting");
        shutdown();
    }
}