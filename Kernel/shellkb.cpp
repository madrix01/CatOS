#pragma once
#include "Keyboard.cpp"


void ShellKeyBoardHandler(uint_8 scanCode, uint_8 chr){
    if(chr != 0){
        // PrintChar(scanCode);
        switch (chr){
        case '\b':
            SetCursorPos(CursorPosition -1);
            PrintChar(' ');
            SetCursorPos(CursorPosition - 1);
            break;
        case '\n':
            break;
        default:
            PrintChar(chr);
            break;
        }
    }
}