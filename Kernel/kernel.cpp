#include "./TextPrint.cpp"

const char txt[] = {'a', 'b', 'c'};

extern "C" void _start() {
    // int* ptr = (int*)0xb8000;
    // *ptr = 0x50505050;
    // SetCursorPos(1000);
    SetCursorPos(PositionFromCoords(0, 0));
    PrintText("Hello world");
    // TestPrint();
    return;
}