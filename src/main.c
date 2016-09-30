#include "main.h"

// local variables
static volatile uint32_t sysTickCnt = 0;

// local forward function definitions
static inline void configureGPIO(void);

/**
 **===========================================================================
 **
 **  Main entry point
 **
 **  - Configures GPIO ports
 **  - Sets SysTick for 100mS interval
 **  - Turns on LED attached to PA5
 **
 **===========================================================================
 */
int main(void) {

	if (ClkStatus != RESET) {

		configureGPIO();

		SysTick_Config((uint32_t) 0x00802C7F);

		GPIOA->ODR |= GPIO_ODR_ODR_5;

		while (1) {

		}

	} else {
		while (1) {

		}
	}
}

/**
 **===========================================================================
 **
 **  Toggles PA5 state every second
 **
 **===========================================================================
 */
void SysTick_Handler(void) {
	if (++sysTickCnt > 9) {
		GPIOA->ODR ^= GPIO_ODR_ODR_5;
		sysTickCnt = 0;
	}
}

/**
 **===========================================================================
 **
 **  Configures GPIOs
 **
 **  - PA5 as output
 **
 **===========================================================================
 */
static inline void configureGPIO(void) {

	GPIOA->MODER &= ~(GPIO_MODER_MODER5);
	GPIOA->MODER |= (GPIO_MODER_MODER5_0);
}
