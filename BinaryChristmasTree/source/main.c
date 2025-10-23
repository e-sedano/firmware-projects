/*
	Tiny Binary Christmas Tree
	
	GOAL:
	Make a tiny binary Christmas tree that counts up then down and flashes a special color when it restarts

*/

#include <stdint.h>
#include "tm4c123gh6pm.h"

// simple blocking delay
void delay_ms(uint32_t ms) {
    for (volatile uint32_t i = 0; i < (ms * 16000); i++);
}

int main(void) {
    // 1. Enable clock for Port F
    SYSCTL_RCGCGPIO_R |= (1U << 5);
    while ((SYSCTL_PRGPIO_R & (1U << 5)) == 0);

    // 2. Configure PF1–PF3 as outputs (LEDs)
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_DEN_R |= 0x0E;

    uint8_t count = 0;
    int8_t direction = 1; // 1 = up, -1 = down

    while (1) {
        // Show binary count on LEDs (shift bits to PF1–PF3)
        GPIO_PORTF_DATA_R = (count << 1);
        delay_ms(300);

        // Update counter
        count += direction;

        // If reached end of range (0 or 7), flip direction
        if (count > 7 || count == 0) {
            // Flash blue LED 3 times to show reset
            for (int i = 0; i < 3; i++) {
                GPIO_PORTF_DATA_R = (1 << 2);  // Blue ON
                delay_ms(200);
                GPIO_PORTF_DATA_R = 0x00;      // All OFF
                delay_ms(200);
            }

            // Reverse direction
            direction = -direction;

            // small pause before resuming count
            delay_ms(400);
        }
    }
}
