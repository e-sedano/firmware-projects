/* 
	Binary LED counter
	
	GOAL:
	Turn the three LEDs (red, blue, green) into a live binary counter
	

*/

#include "tm4c123gh6pm.h"
#include <stdint.h>


void delay_ms(uint32_t ms){
	for (volatile uint32_t i = 0; i < (ms * 16000); i++);

}

int main(void) {
	// Enable clock for port F
	SYSCTL_RCGCGPIO_R |= (1U << 5);
	while ((SYSCTL_PRGPIO_R & (1U << 5)) == 0);
	
	// Configure PF1-PF3 as output (LEDs)
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DEN_R |= 0x0E;
	
	// main loop: binary counter
	while(1){
		for (uint8_t count = 0; count < 8; count++){ // 0 - 7 bits
			GPIO_PORTF_DATA_R = (count << 1); // shift left so bits 0-2 map to PF1-PF3
			delay_ms(200);
		}
	
	}
    
}