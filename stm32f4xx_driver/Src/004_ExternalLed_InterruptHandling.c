/*
 * 004_ExternalLed_InterruptHandling.c
 *
 *  Created on: Nov 22, 2023
 *      Author: sametuslu
 */


#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"

#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW
void delay(void) {
	for (uint32_t i = 0; i < 500000 / 2; i++)
		;
}

int main(void) {
	GPIO_Handle_t GpioLed1, GPIOBtn;

	GpioLed1.pGPIOx = GPIOA;
	GpioLed1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	GpioLed1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed1.GPIO_PinConfig.GPIO_PinPupdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed1);

	GPIOBtn.pGPIOx = GPIOB;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPupdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GPIOBtn);
	/*
	 GpioLed2.pGPIOx = GPIOD;
	 GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	 GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	 GpioLed2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	 GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	 GpioLed2.GPIO_PinConfig.GPIO_PinPupdControl = GPIO_NO_PUPD;

	 GPIO_PeriClockControl(GPIOD, ENABLE);

	 GPIO_Init(&GpioLed2);

	 GpioLed3.pGPIOx = GPIOD;
	 GpioLed3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	 GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	 GpioLed3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	 GpioLed3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	 GpioLed3.GPIO_PinConfig.GPIO_PinPupdControl = GPIO_NO_PUPD;

	 GPIO_PeriClockControl(GPIOD, ENABLE);

	 GPIO_Init(&GpioLed3);

	 GpioLed4.pGPIOx = GPIOD;
	 GpioLed4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	 GpioLed4.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	 GpioLed4.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	 GpioLed4.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	 GpioLed4.GPIO_PinConfig.GPIO_PinPupdControl = GPIO_NO_PUPD;

	 GPIO_PeriClockControl(GPIOD, ENABLE);

	 GPIO_Init(&GpioLed4);*/

	while (1) {
		/*GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
		 delay(); */
		if (GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_12) == BTN_PRESSED) {
			delay();
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
		}
			//delay();
			/*GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
			 delay();
			 GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
			 delay();*/
		}

		return 0;
	}


