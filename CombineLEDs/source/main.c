/* Combine LEDs (color mixing)
	
	GOAL:
	Make your MCU mix colors using bit masks and OR
	Expected Pattern: RED -> BLUE -> GREEN -> YELLOW -> Off
	
*/

#include "tm4c123gh6pm.h"
#include <stdint.h>

void delay_ms(uint32_t ms){
	for (volatile uint32_t i = 0; i < (ms * 16000); i++);
}


int main(void) {
    SYSCTL_RCGCGPIO_R |= (1U << 5);
	  while ((SYSCTL_PRGPIO_R & (1U << 5)) == 0);
		GPIO_PORTF_DIR_R |= 0x0E;
		GPIO_PORTF_DEN_R |= 0x0E;
	
		while(1){
			GPIO_PORTF_DATA_R = (1 << 1); // Red LED
			delay_ms(500);
			GPIO_PORTF_DATA_R = (1 << 2); // Blue LED
			delay_ms(500);
			GPIO_PORTF_DATA_R = (1 << 3); // Green LED
			delay_ms(500);
			GPIO_PORTF_DATA_R = (1 << 1) | (1 << 3); // Yellow = red + green
			delay_ms(500);
			GPIO_PORTF_DATA_R = (1 << 1) | (1 << 2) | (1 << 3); // White = red + green + blue
			delay_ms(500);
			GPIO_PORTF_DATA_R = 0x00; // All off
			delay_ms(500);	
		}
}