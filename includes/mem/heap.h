#pragma once
#include <TypeDef.h>

struct MemorySegmentHeader{
    uint_64 MemoryLength;
    MemorySegmentHeader* NextSegment;
    MemorySegmentHeader* PrevSegment;
    MemorySegmentHeader* NextFreeSegment;
    MemorySegmentHeader* PrevFreeSegment;
    bool Free;
};


extern void InitializeHeap(uint_64 HeapAddr, uint_64 HeapLength);
extern void* malloc(uint_64 size);
