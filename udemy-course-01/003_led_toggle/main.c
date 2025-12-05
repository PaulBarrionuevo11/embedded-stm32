/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Paul Barrionuevo
 * @brief          : Turn on/off the built in LED on the STM32F446RE
 *
 * 					use the appropriate registers referred in the user manual
 *
 * 					@register to access clock control (RCC_AHB1ENR)
 * 					Address offset: 0x30
 * 					Clock main Address: 0x40023800
 * 					Address: 0x40023830
 * 					@register to access GPIOA pin Mode
 * 					Address offset: 0x00
 * 					GPIO main Address: 0x40020000
 * 					Address: 0x40020000
 * 					@register to access GPIOA output data
 * 					Address offset: 0x14
 * 					GPIO main Address: 0x40020000
 * 					Address: 0x40020014
 *
 *
 ******************************************************************************
 */


#include <stdint.h>

#define TIME_DELAY 100000 // Adjust accordingly

int main(void)
{
	// Pointers to registers (STM32F4 addresses)
	uint32_t* ptClock = (uint32_t*)0x40023830;    // RCC_AHB1ENR
	uint32_t* ptPinMode = (uint32_t*)0x40020000;  // GPIOA_MODER
	uint32_t* ptDataOut = (uint32_t*)0x40020014;  // GPIOA_ODR

	// 1.Enable the clock peripheral
	*ptClock |= (1<<0);

	// 2. Turn pin mode on
	// a. Clear the two bit position
	*ptPinMode &= ~(3<<10); // ~(11<<10)
	*ptPinMode |= (1<<10); //0x400

	while(1)
	{
		// Turn LED on
		*ptDataOut |= (1<<5);//0x20
		for(uint32_t i=0; i< TIME_DELAY; i++);
		// Turn LED off
		*ptDataOut &= ~(1<<5);//0x20
		for(uint32_t i=0; i< TIME_DELAY; i++);

	}
}
