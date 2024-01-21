#ifndef NVIC_INT_H_
#define NVIC_INT_H_


typedef enum
{
	NVIC_GROUPMODE_G16S0=3,
	NVIC_GROUPMODE_G8S2,
	NVIC_GROUPMODE_G4S4,
	NVIC_GROUPMODE_G2S8,
	NVIC_GROUPMODE_G0S16,

}NVIC_GroupMode_t;


void NVIC_voidEnableInterrupt(u8 Copy_u8IntPos);

void NVIC_voidDisableInterrupt(u8 Copy_u8IntPos);

void NVIC_voidEnableInterruptPending(u8 Copy_u8IntPos);

void NVIC_voidDisableInterruptPending(u8 Copy_u8IntPos);

u8 NVIC_u8IsInterruptActive(u8 Copy_u8IntPos);

void NVIC_SetInterruptPriorty(u8 Copy_u8IntPos, u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum);

void NVIC_voidSetInterruptGroupMode(NVIC_GroupMode_t Copy_uddtGroupMode);






#endif
