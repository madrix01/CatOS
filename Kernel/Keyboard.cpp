#include <Keyboard.h>

bool leftShiftPressed = false;
bool rightShiftPressed = false;

void StandardKeyBoardHandler(uint_8 scanCode, uint_8 chr){
    if(chr != 0){
        switch(leftShiftPressed || rightShiftPressed){
            case true:
                putch(chr - 32);
                break;
            case false:
                putch(chr);
                break;
        }
    } 
    else {
        switch(scanCode){
            case 0x2A: //left shift
                leftShiftPressed = true;
                break;
            case 0xAA: // left shif released
                leftShiftPressed = false;
                break;
            case 0x36: //right shift
                rightShiftPressed = true;
                break;
            case 0xB6: //right shift released
                rightShiftPressed = false;
                break;
        }
    }

}

// void KeyboardHandler0xE0(uint_8 scanCode){
//     switch(scanCode){
//         case 0x50:
//             SetCursorPos(CursorPosition + VGA_WIDTH);
//             break;
//         case 0x48:
//             SetCursorPos(CursorPosition - VGA_WIDTH);
//             break;
//         case 0x4B:
//             SetCursorPos(CursorPosition - 1);
//             break;
//         case 0x4D:
//             SetCursorPos(CursorPosition + 1);
//             break;   
//     }
// }

// void KeyboardHandler(uint_8 scanCode, uint_8 chr) {
//     switch(LastScanCode){
//         case 0xE0:
//             KeyboardHandler0xE0(scanCode); 
//             break;
//         default:
//             StandardKeyBoardHandler(scanCode, chr);
//             break;
//     }
//     LastScanCode = scanCode;
// }