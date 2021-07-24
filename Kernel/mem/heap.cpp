#include <mem/heap.h>

MemorySegmentHeader* FirstFreeMemorySegment;

void InitializeHeap(uint_64 HeapAddr, uint_64 HeapLength){
    FirstFreeMemorySegment = (MemorySegmentHeader*) HeapAddr;
    FirstFreeMemorySegment->MemoryLength = HeapLength - sizeof(MemorySegmentHeader);
    FirstFreeMemorySegment->NextSegment = 0;
    FirstFreeMemorySegment->PrevSegment = 0;
    FirstFreeMemorySegment->NextFreeSegment = 0;
    FirstFreeMemorySegment->PrevFreeSegment = 0;
    FirstFreeMemorySegment->Free = true;    
}

void* malloc(uint_64 size){
    uint_64 remainder = size%8;

    size -= remainder;
    if(remainder != 0) size += 8;

    MemorySegmentHeader* currentMemorySegment = FirstFreeMemorySegment;

    while(true){
        if(currentMemorySegment->MemoryLength >= size){
            return currentMemorySegment + 1;
        }
    }
}