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
			if(currentMemorySegment->MemoryLength > size + sizeof(MemorySegmentHeader)){
				MemorySegmentHeader* newSegmentHeader = (MemorySegmentHeader*)((uint_64) currentMemorySegment + sizeof(MemorySegmentHeader) + size);
				newSegmentHeader->Free = true;
				newSegmentHeader->MemoryLength = ((uint_64) currentMemorySegment->MemoryLength) - (sizeof(MemorySegmentHeader) + size);
	
				newSegmentHeader->NextFreeSegment = currentMemorySegment->NextFreeSegment;
				newSegmentHeader->NextSegment = currentMemorySegment->NextSegment;
				newSegmentHeader->PrevSegment = currentMemorySegment;
				newSegmentHeader->PrevFreeSegment = currentMemorySegment->PrevFreeSegment;


				currentMemorySegment->NextFreeSegment = newSegmentHeader;
				currentMemorySegment->NextSegment = newSegmentHeader;
				currentMemorySegment->MemoryLength = size;
			}

			if(currentMemorySegment == FirstFreeMemorySegment)
				FirstFreeMemorySegment = currentMemorySegment->NextFreeSegment;

			currentMemorySegment->Free = false;
			
		
			if(currentMemorySegment->PrevFreeSegment != 0) currentMemorySegment->PrevFreeSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
			
			if(currentMemorySegment->NextFreeSegment != 0) currentMemorySegment->NextFreeSegment->PrevFreeSegment = currentMemorySegment->PrevFreeSegment;
			if(currentMemorySegment->PrevSegment != 0) currentMemorySegment->PrevSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
			if(currentMemorySegment->NextSegment != 0) currentMemorySegment->NextSegment->PrevFreeSegment = currentMemorySegment->PrevFreeSegment;
			
			return currentMemorySegment + 1;
        }

		if(currentMemorySegment->NextFreeSegment == 0)return 0; // No memeory remaining ;

		currentMemorySegment = currentMemorySegment->NextFreeSegment;
    }

	return 0;
}
