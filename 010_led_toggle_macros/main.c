/*

 Modify the led toggle bitfield exercise with macros

*/

#include <stdint.h>
#include "main.h"


int main(void)
{
	// Generously use volatile for memory map addresses 
	RCC_AHB1ENR_t volatile* const ptClock = ADD_REG_AHB1ENR;
	GPIOx_MODE_t volatile* const ptGpioAMode = ADD_GPIOA_MODE;
	GPIOx_ODR_t volatile* const ptDataOut = ADD_GPIOA_OUT;

	// MANIPULATING PA05
	// 1.Enable the clock peripheral
	ptClock->gpioa_en = CLOCK_EN;
	// 2. Turn pin mode on
	// a. Clear the two bit position
	ptGpioAMode->pin_5 = MODE_CONF_OUTPUT;

	while (1)
	{
		// Turn LED on
		ptDataOut->pin_5 = PIN_STATE_HIGH;//0x20
		for (uint32_t i = 0; i < TIME_DELAY; i++);
		// Turn LED off
		ptDataOut->pin_5 = PIN_STATE_LOW;//0x20
		for (uint32_t i = 0; i < TIME_DELAY; i++);

	}
}
