
#include "robot.h"

//****************************************************************************************************************//
// BOOTLOADER JUMP
//****************************************************************************************************************//
#define REMAPPED_RESET_VECTOR_ADDRESS			0x1000	// Program memory address to jump bootloader

//*********************RESET REMAPPING****************************//
extern void _startup (void);
#pragma code REMAPPED_RESET_VECTOR = REMAPPED_RESET_VECTOR_ADDRESS
void _reset (void) {
    _asm goto _startup _endasm
}
#pragma code



void main() {
    TRobot robot;
    initialiserRobot(&robot); 
        
       
	
    
}
