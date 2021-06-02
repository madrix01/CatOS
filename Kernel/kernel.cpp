#include "TextPrint.cpp"
#include "colorCodes.h"
#include "IDT.cpp"

extern const char Logo[];

bool leftShiftPressed = false, rightShiftPressed = false;

void keyBoardHandler(uint_8 scanCode, uint_8 chr){
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

extern "C" void _start() {
    SetCursorPos(0); 
    ClearScreen();
    PrintText(Logo, FG_LRED);
    PrintText("\n\r\n\r");
    InitializeIDT();
    MainKeyBoardHandler = keyBoardHandler;
    return;
}
