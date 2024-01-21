#ifndef EXTI_INT_H_
#define EXTI_INT_H_


#define LINE0     0
#define LINE1     1
#define LINE2     2
#define LINE3     3
#define LINE4     4
#define LINE5     5
#define LINE6     6
#define LINE7     7
#define LINE8     8
#define LINE9     9
#define LINE10    10
#define LINE11    11
#define LINE12    12
#define LINE13    13
#define LINE14    14
#define LINE15    15


#define PORTA 0
#define PORTB 1
#define PORTC 2

void EXTI_voidSetExtiConfig(u8 Copy_u8PORT , u8 Copy_u8Line);


void EXTI_EnableInterrupt(u8 Copy_u8Line);


void EXTI_DisableInterrupt(u8 Copy_u8Line);


void EXTI_SetSoftwareInterrupt(u8 Copy_u8Line);


typedef enum{

	EXTI_RISING_EDGE=0,
	EXTI_FALLING_EDGE,
	EXTI_ON_CHANGE,

}EXTI_TriggerMode_t;


void EXTI_SetTriggerSource(u8 Copy_u8Line,EXTI_TriggerMode_t Copy_uddtTriggerMode);



typedef enum
{
	EXTI_0=0,
	EXTI_1,
	EXTI_2,
	EXTI_3,
	EXTI_4,
	EXTI_5,
	EXTI_6,
	EXTI_7,
	EXTI_8,
	EXTI_9,
	EXTI_10,
	EXTI_11,
	EXTI_12,
	EXTI_13,
	EXTI_14,
	EXTI_15,
}EXTI_Number_t;


void EXTI_voidCallBack(void(*ptr)(void),EXTI_Number_t Copy_uddtIntNumber);

/*
void EXTI1_voidCallBack(void(*ptr)(void));
void EXTI2_voidCallBack(void(*ptr)(void));
void EXTI3_voidCallBack(void(*ptr)(void));
void EXTI4_voidCallBack(void(*ptr)(void));
void EXTI5_voidCallBack(void(*ptr)(void));
void EXTI6_voidCallBack(void(*ptr)(void));
void EXTI7_voidCallBack(void(*ptr)(void));
void EXTI8_voidCallBack(void(*ptr)(void));
void EXTI9_voidCallBack(void(*ptr)(void));
void EXTI10_voidCallBack(void(*ptr)(void));
void EXTI11_voidCallBack(void(*ptr)(void));
void EXTI12_voidCallBack(void(*ptr)(void));
void EXTI13_voidCallBack(void(*ptr)(void));
void EXTI14_voidCallBack(void(*ptr)(void));
void EXTI15_voidCallBack(void(*ptr)(void));
*/


#endif
