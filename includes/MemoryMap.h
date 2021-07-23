#pragma once
#include <TypeDef.h>
#include <drivers/console.h>

struct MemoryMapEntry{
    uint_64 BaseAddr;
    uint_64 RegionLength;
    uint_32 RegionType;
    uint_32 ExtendedAttribute;
};

extern "C" uint_8 MemoryRegionCount;
// uint_8 UsableMemoryRegionCount;

void PrintMemoryMap(MemoryMapEntry* memoryMap);
// MemoryMapEntry* UsableMemoryRegions[10];
MemoryMapEntry** GetUsableMemoryRegions();
