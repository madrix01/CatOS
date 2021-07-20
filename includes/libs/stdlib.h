#pragma once
#include <TypeDef.h>

extern "C" int StrLen(const void* aptr);
void* memset(void* bufptr, uint_8 value, int size);
int memcmp(const void* aptr, const void* bptr, int size);