#include "STD_Types.h"
#include "STD_TYPES.h"
#include "M_NVIC_prv.h"
#include "M_NVIC_int.h"
#include "M_NVIC_cfg.h"

 u8 Global_u8IPR;
void NVIC_voidEnableInterrupt(u8 Copy_u8IntPos)
{
	NVIC->ISER[Copy_u8IntPos/REGISTER_DIVISION]=1<<(Copy_u8IntPos%REGISTER_DIVISION);
}

void NVIC_voidDisableInterrupt(u8 Copy_u8IntPos)
{
	NVIC->ICER[Copy_u8IntPos/REGISTER_DIVISION]=1<<(Copy_u8IntPos%REGISTER_DIVISION);
}

void NVIC_voidEnableInterruptPending(u8 Copy_u8IntPos)
{
	NVIC->ISPR[Copy_u8IntPos/REGISTER_DIVISION]=1<<(Copy_u8IntPos%REGISTER_DIVISION);
}

void NVIC_voidDisableInterruptPending(u8 Copy_u8IntPos)
{
	NVIC->ICPR[Copy_u8IntPos/REGISTER_DIVISION]=1<<(Copy_u8IntPos%REGISTER_DIVISION);
}

u8 NVIC_u8IsInterruptActive(u8 Copy_u8IntPos)
{
	u8 Local_u8PinPos;
	u8 Local_u8RegPos;
	u8 Local_u8InterruptState;

	Local_u8RegPos=Copy_u8IntPos/REGISTER_DIVISION;
	Local_u8PinPos=Copy_u8IntPos%REGISTER_DIVISION;

	Local_u8InterruptState=(((NVIC->IABR[Local_u8RegPos])>>Local_u8PinPos) & 1);
	return Local_u8InterruptState;
}

void NVIC_SetInterruptPriorty(u8 Copy_u8IntPos, u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum)
{
	switch (Global_u8IPR)
	{
	case NVIC_GROUPMODE_G16S0:NVIC->IPR[Copy_u8IntPos]= Copy_u8GroupNum<<4;  break;
	case NVIC_GROUPMODE_G8S2:NVIC->IPR[Copy_u8IntPos]= (Copy_u8GroupNum<<5)|(Copy_u8SubGroupNum<<4); break;
	case NVIC_GROUPMODE_G4S4:NVIC->IPR[Copy_u8IntPos]= (Copy_u8GroupNum<<6)|(Copy_u8SubGroupNum<<4); break;
	case NVIC_GROUPMODE_G2S8:NVIC->IPR[Copy_u8IntPos]= (Copy_u8GroupNum<<7)|(Copy_u8SubGroupNum<<4); break;
	case NVIC_GROUPMODE_G0S16:NVIC->IPR[Copy_u8IntPos]= Copy_u8SubGroupNum<<4;  break;
	default: break;
	}
}

void NVIC_voidSetInterruptGroupMode(NVIC_GroupMode_t Copy_uddtGroupMode)
{
	Global_u8IPR=Copy_uddtGroupMode;
	u32 Copy_u32Local;
	SCB_AIRCR = NVIC_VECTKEY;
	Copy_u32Local = NVIC_VECTKEY | (Copy_uddtGroupMode<<8);
	SCB_AIRCR=Copy_u32Local;

}

