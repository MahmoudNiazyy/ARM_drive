#ifndef M_SYSTICK_INT_H
#define M_SYSTICK_INT_H


void STK_voidInit(void);

void STK_voidStart(u32 Copy_u32PreloadValue);
M_SYSTICK_Stop(void);

void STK_voidDelayMs(u32 Copy_u32DelayMs);

void STK_voidDelayUs(u32 Copy_u32DelayUs);

u8 STK_ReadFlag(void);

void STK_CtrlIntState(u8 Copy_u8IntState);

void STK_SetCallBack(void(*ptofun)(void));

u32 GET_Elabstet(void);



#endif
