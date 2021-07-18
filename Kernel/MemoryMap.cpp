#pragma once
#include <TypeDef.h>

struct MemoryMapEntry{
    uint_64 BaseAddr;
    uint_64 RegionLength;
    uint_32 RegionType;
    uint_32 ExtendedAttribute;
};

extern uint_8 MemoryRegionCount;