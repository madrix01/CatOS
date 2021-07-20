#include <MemoryMap.h>

// struct MemoryMapEntry{
//     uint_64 BaseAddr;
//     uint_64 RegionLength;
//     uint_32 RegionType;
//     uint_32 ExtendedAttribute;
// };

// extern uint_8 MemoryRegionCount;
// uint_8 UsableMemoryRegionCount;

void PrintMemoryMap(MemoryMapEntry* memoryMap){
    write("Memory Base : ");
    write(IntegerToString(memoryMap->BaseAddr));
    write("\n\rRegionLength : ");
    write(IntegerToString(memoryMap->RegionLength));
    write("\n\rRegion Type : ");
    write(IntegerToString(memoryMap->RegionType));
    write("\n\rAttribute : ");
    write(IntegerToString(memoryMap->ExtendedAttribute));
    write("\n\r --------- \n\r");
}

// MemoryMapEntry* UsableMemoryRegions[10];


bool MemoryRegionsGot = false;
MemoryMapEntry** GetUsableMemoryRegions(){
    if(MemoryRegionsGot){
        return UsableMemoryRegions;
    }

    uint_8 UsableRegionIndex = 0;
    for(uint_8 i = 0; i < MemoryRegionCount; i++){
        MemoryMapEntry* memMap = (MemoryMapEntry*) 0x5000;
        memMap += i;
        if(memMap->RegionType == 1){
            UsableMemoryRegions[UsableRegionIndex] = memMap;
            UsableRegionIndex++;
        }
        UsableMemoryRegionCount = UsableRegionIndex;
    }
    MemoryRegionsGot = true;    
    return UsableMemoryRegions;
}