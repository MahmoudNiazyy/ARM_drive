/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		29 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM_ARM (32-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#ifndef MGPIO_PRV_H_
#define MGPIO_PRV_H_

#define GPIOA_BASE_ADDRESS    (0x40020000)

#define GPIOB_BASE_ADDRESS    (0x40020400)

#define GPIOC_BASE_ADDRESS    (0x40020800)

typedef struct
{
	u32 GPIOx_MODER;
	u32 GPIOx_OTYPER;
	u32 GPIOx_OSPEEDR;
	u32 GPIOx_PUPDR;
	u32 GPIOx_IDR;
	u32 GPIOx_ODR;
	u32 GPIOx_BSRR;
	u32 GPIOx_LCKR;
	u32 GPIOx_AFRL;
	u32 GPIOx_AFRH;
}GPIOx_t;

#define GPIOA     ((volatile GPIOx_t*)GPIOA_BASE_ADDRESS)

#define GPIOB     ((volatile GPIOx_t*)GPIOB_BASE_ADDRESS)

#define GPIOC     ((volatile GPIOx_t*)GPIOC_BASE_ADDRESS)

#define GPIO_MODE_MASK      	 0b11

#define GPIO_ALTERN_MASK		0b1111

#define GPIO_OTYPER_MASK 		 0b01

#define GPIO_PUPDR_MASK      	 0b11

#define GPIO_OSPEEDR_MASK      	 0b11






#endif
