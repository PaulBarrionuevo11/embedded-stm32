
#include <stdint.h>
#include "main.h"

#define TIME_DELAY 300000

int main(void)
{
	// Generously use volatile for memory map addresses 
	RCC_AHB1ENR_t volatile* const ptClock = (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MODE_t volatile* const ptGpioAMode = (GPIOx_MODE_t*)0x40020000;
	GPIOx_ODR_t volatile* const ptDataOut = (GPIOx_ODR_t*)0x40020014;

	// MANIPULATING PA05
	// 1.Enable the clock peripheral
	ptClock->gpioa_en = 1;
	// 2. Turn pin mode on
	// a. Clear the two bit position
	ptgpioaMode->pin_5 = 1;

	while (1)
	{
		// Turn LED on
		ptDataOut->pin_5 = 1;//0x20
		for (uint32_t i = 0; i < TIME_DELAY; i++);
		// Turn LED off
		ptDataOut->pin_5 = 0;//0x20
		for (uint32_t i = 0; i < TIME_DELAY; i++);

	}
}
