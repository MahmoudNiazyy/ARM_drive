#ifndef _MGPIO_INT_H_
#define _MGPIO_INT_H_


/***************************** PORT MACROS  ***********************/
#define   PORT_A   0
#define   PORT_B   1
#define   PORT_C   2

/***************************** PIN MACROS ***************************/
#define PIN_0      	0
#define PIN_1		1
#define PIN_2		2
#define PIN_3		3
#define PIN_4       4
#define PIN_5       5
#define PIN_6       6
#define PIN_7       7
#define PIN_8       8
#define PIN_9       9
#define PIN_10      10
#define PIN_11      11
#define PIN_12      12
#define PIN_13      13
#define PIN_14      14
#define PIN_15      15

/*************************** Mode Direction Macros  ****************************/
#define   INPUT_MODE     00
#define   OUTPUT_MODE    01
#define   ALT_FUNC_MODE  10
#define   ALALOG_MODE    11

/************************** OUTPUT Macros ***************************/
#define OUTPUT_PUSH_PULL    	0
#define OUTPUT_OPEN_DRAIN    	1

/************************** OUTPUT Speed Macros *********************/
#define OUTPUT_LOW_SPEED   		    	0
#define OUTPUT_MEDIUM_SPEED     		1
#define OUTPUT_HIGH_SPEED    			2
#define OUTPUT_VHIGH_SPEED       		3

/************************* INPUT Mode Macros **********************/
#define INPUT_FLOAT     	    0
#define INPUT_PULLUP  	        1
#define INPUT_PULLDOWN       	2

/************************  PINS               *********************/
#define PIN_HIGH      1
#define PIN_LOW       0

enum
{
	SYSTEM ,
	TIM1_2,
	TIM3_5,
	TIM8_11,
	I2C1_3,
	SPI1_4,
	SPI_3,
	USART1_2,
	USART6,
	I2C2_3,
	OTG_FS,
	RESERVED0,
	RESERVED1,
	EVENTOUT
};
void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);

void MGPIO_voidSetPinOutConfig(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8OutType,u8 Copy_u8Speed);

void MGPIO_voidSetInputConfig(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinConfig);

void MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_u8Data);

void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Data);

void MGPIO_voidResetPinValueAdvanced(u8 Copy_u8Port,u8 Copy_u8Pin);

void MGPIO_voidSetPinAlternating(u8 Copy_u8Port,u8 Copy_u8Pin , u8 AlterFunc);






#endif
