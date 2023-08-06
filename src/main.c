#include <hardware_defintions.h>

#define LED_PIN_HIGH	PIN5_HIGH

int main(void) {
	// Enable clock access to GPIOA
	RCC_AHBEN_R |= GPIOAEN;
	// Set PA5 to output mode
	GPIOA_MODE_R |= (1U << 10); // Set bit 10 to 1
	GPIOA_MODE_R &=~ (1U << 11); // Set bit 11 to 0
	// while(1) {
	// 	// SET PA5 High
	// 	GPIOA_OD_R ^= LED_PIN_HIGH;
	// 	for(int i = 0; i < 100000; i++);
	// }

	return 0;
}
