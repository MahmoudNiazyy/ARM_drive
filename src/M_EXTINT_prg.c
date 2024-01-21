#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "M_EXTINT_prv.h"
#include "M_EXTINT_cfg.h"
#include "M_EXTINT_int.h"


static void (*EXTI_GlobalPointerToFunc[16])(void)={NULL};


void EXTI_voidSetExtiConfig(u8 Copy_u8PORT, u8 Copy_u8Line)
{
	if((Copy_u8Line >= 0)&& (Copy_u8Line<=15))
	{
		u8 Local_u8LineRegister;
		u8 Local_u8Bit;
		Local_u8LineRegister=Copy_u8Line/4;
		Local_u8Bit=(Copy_u8Line%4)*4;
        SYSCFG->EXTICR[Local_u8LineRegister] &= ~(1<<Local_u8Bit);
        SYSCFG->EXTICR[Local_u8LineRegister] |= (Copy_u8PORT<<Local_u8Bit);
	}
	else
	{
		/*do nothing*/
	}
}


void EXTI_EnableInterrupt(u8 Copy_u8Line)
{
	if((Copy_u8Line >= 0)&&(Copy_u8Line<=15))
	{
		EXTI->IMR |= 1<<Copy_u8Line;
	}
	else
	{
		/*Do Nothing*/
	}
}


void EXTI_DisableInterrupt(u8 Copy_u8Line)
{
	if((Copy_u8Line >= 0)&&(Copy_u8Line<=15))
	{
		EXTI->IMR |= ~(1<<Copy_u8Line);
	}
	else
	{
		/*do nothing*/
	}
}

void EXTI_SetSoftwareInterrupt(u8 Copy_u8Line)
{
	if((Copy_u8Line >= 0)&&(Copy_u8Line<=15))
	{
		EXTI->SWIER |= 1<<Copy_u8Line;
	}
	else
	{
		/*do nothing*/

	}
}

void EXTI_SetTriggerSource(u8 Copy_u8Line,EXTI_TriggerMode_t Copy_uddtTriggerMode)
{
	if((Copy_u8Line >= 0)&&(Copy_u8Line<=15))
	{
		switch (Copy_uddtTriggerMode)
		{
		case EXTI_RISING_EDGE: EXTI->RTSR |= 1<<Copy_u8Line;
		EXTI->FTSR &= ~(1<<Copy_u8Line);
		break;
		case EXTI_FALLING_EDGE: EXTI->RTSR &= ~(1<<Copy_u8Line);
		EXTI->FTSR |= 1<<Copy_u8Line;
		break;
		case EXTI_ON_CHANGE: EXTI->RTSR |= 1<<Copy_u8Line;
		EXTI->FTSR |= 1<<Copy_u8Line;
		break;
		}
	}
	else
	{
		/*do nothing*/
	}

}

void EXTI_voidCallBack(void(*ptr)(void),EXTI_Number_t Copy_uddtIntNumber)
{
	switch (Copy_uddtIntNumber)
	{
	case 0: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[0]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 1: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[1]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 2: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[2]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 3: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[3]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 4: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[4]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 5: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[5]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 6:  if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[6]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 7: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[7]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 8: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[8]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 9: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[9]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 10: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[10]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 11: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[11]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 12: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[12]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 13: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[13]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 14: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[14]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;
	case 15: if(ptr != NULL)
	{
		EXTI_GlobalPointerToFunc[15]=ptr;
	}
	else
	{
		/*do nothing*/
	}
	break;

	}
}






void EXTI0_IRQHandler(void)
{
	EXTI_GlobalPointerToFunc[0]();
	EXTI->PR |= 1<<0;    //without this it will do interrupts always
}
void EXTI1_IRQHandler(void)
{
	EXTI_GlobalPointerToFunc[1]();
	EXTI->PR |= 1<<1;    //without this it will do interrupts always
}
void EXTI2_IRQHandler(void)
{
	EXTI_GlobalPointerToFunc[2]();
	EXTI->PR |= 1<<2;
}
void EXTI3_IRQHandler(void)
{
	EXTI_GlobalPointerToFunc[3]();
	EXTI->PR |= 1<<3;
}
void EXTI4_IRQHandler(void)
{
	EXTI_GlobalPointerToFunc[4]();
    EXTI->PR |= 1<<4;
}
void EXTI5_9_IRQHandler(void)
{

}

void EXTI10_15_IRQHandler(void)
{

}
