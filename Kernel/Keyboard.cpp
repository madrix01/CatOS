#pragma once
#include "TypeDef.cpp"
#include "TextPrint.cpp"


bool leftShiftPressed = false, rightShiftPressed = false;
uint_8 LastScanCode;

void StandardKeyBoardHandler(uint_8 scanCode, uint_8 chr){
    if(chr != 0){
        switch(leftShiftPressed || rightShiftPressed){
            case true:
                PrintChar(chr - 32);
                break;
            case false:
                PrintChar(chr);
                break;
        }
    } 
    else {
        switch(scanCode){
            case 0x8E: // backspace
                SetCursorPos(CursorPosition -1);
                PrintChar(' ');
                SetCursorPos(CursorPosition - 1);
                break;
            case 0x2A: //left shift
                leftShiftPressed = true;
                break;
            case 0xAA: // left shif released
                leftShiftPressed = false;
                break;
            case 0x36: //left shift
                rightShiftPressed = true;
                break;
            case 0xB6: // left shif released
                rightShiftPressed = false;
                break;
            case 0x9C: // left shif released
                PrintText("\n\r");
                break;
        }
    }

}

void KeyboardHandler0xE0(uint_8 scanCode){
    switch(scanCode){
        case 0x50:
            SetCursorPos(CursorPosition + VGA_WIDTH);
            break;
        case 0x48:
            SetCursorPos(CursorPosition - VGA_WIDTH);
            break;   
    }
}

void KeyboardHandler(uint_8 scanCode, uint_8 chr) {
    switch(LastScanCode){
        case 0xE0:
            KeyboardHandler0xE0(scanCode); 
            break;
        default:
            StandardKeyBoardHandler(scanCode, chr);
            break;
    }
    LastScanCode = scanCode;
}