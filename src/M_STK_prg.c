#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "M_STK_int.h"
#include "M_STK_prv.h"
#include "M_STK_cfg.h"


static void (*Global_ptrtofunction)(void)=NULL;


void STK_voidInit(void)
{
	STK->CTRL &= ~(1<<2);

}


void STK_voidStart(u32 Copy_u32PreloadValue)
{
	STK->VAL=0;
	STK->LOAD = Copy_u32PreloadValue;

	SET_BIT(STK->CTRL,0);
	//STK->CTRL|=1;
}

M_SYSTICK_Stop(void)
{
	STK->VAL=0;
	CLR_BIT(STK->CTRL,0);
}



u8 STK_ReadFlag(void)
{
	return ( GET_BIT(STK->CTRL , 16));
			//((STK->CTRL>>16)&1);
}


void STK_voidDelayUs(u32 Copy_u32DelayUs)
{
	if(Copy_u32DelayUs >= 2 )
	{


		STK_CtrlIntState(0);
		STK_voidStart(Copy_u32DelayUs*2);
		while(STK_ReadFlag()==0);
	}

}

void STK_voidDelayMs(u32 Copy_u32DelayMs)
{
	if(Copy_u32DelayMs >=2 )
	{
		STK_CtrlIntState(0);
		STK_voidStart(Copy_u32DelayMs*2000);
		while(STK_ReadFlag()==0);
	}
}

void STK_CtrlIntState(u8 Copy_u8IntState)
{
	if(Copy_u8IntState == 1 )
	{
		SET_BIT(STK->CTRL,1);
		//STK->CTRL |= (1<<1);
	}
	else
	{
		//STK->CTRL |= ~(1<<1);
		CLR_BIT(STK->CTRL,1);
	}

}

u32 GET_Elabstet(void)
{
	/* Calculating the Elapsed time */
		return ((STK->LOAD)-(STK->VAL)) ;
}

void STK_SetCallBack(void(*ptofun)(void))
{
	Global_ptrtofunction=ptofun;
}





void Systick_IRQHandler(void)
{
	Global_ptrtofunction();
}
