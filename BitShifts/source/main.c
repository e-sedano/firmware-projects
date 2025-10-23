/* Bit Shifts
	
	GOAL:
	Rotate LEDs using bit shifts instead of writing constants
	
	Expected LED Cycle: RED -> BLUE -> GREEN -> repeat

*/

#include "tm4c123gh6pm.h"
#include <stdint.h>

void delay_ms(uint32_t ms){
	
	for(volatile uint32_t i = 0; i < (ms * 16000); i++);

}


int main(void) {
    SYSCTL_RCGCGPIO_R |= (1U << 5);
		while ((SYSCTL_PRGPIO_R & (1U << 5)) == 0);
		GPIO_PORTF_DIR_R |= 0x0E;
		GPIO_PORTF_DEN_R |= 0x0E;
	
		uint8_t bit = 1; // start with bit 1 (red)
	
		while(1){
				GPIO_PORTF_DATA_R = (1 << bit); // shift 1 left by 'bit' positions
				delay_ms(400);
			
				bit++;
				if(bit > 3) bit = 1; // wrap back to red
			
		
		}
}