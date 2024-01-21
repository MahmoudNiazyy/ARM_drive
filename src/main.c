#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_int.h"
#include "M_GPIO_int.h"
#include "M_STK_int.h"
#include "M_EXTINT_int.h"
#include "M_UART_int.h"
#include "M_FMI_int.h"


u8 Global_pu8RxBuffer[533][50];
u8 Global_u8RxBufferCounter =0 ;

typedef void (*function_t)(void) ;

function_t App_Call;

u8 timoutFlag = 0 ;
u8 EraseFlag =0;

void STK_CallBack(void) // the func that be used to call the app
{
#define SCB_VTOR   	*((volatile u32*)(0xE000ED00+0x08))
	timoutFlag =1;
	SCB_VTOR = 0x8004000;
	App_Call = *(function_t*)0x8004004;
	App_Call();
}

int main(void)
{

	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1 , 15);
	MRCC_Enable_peripheral(RCC_APB2 , APB2_USART1);
	MRCC_Enable_peripheral(RCC_AHB1 , AHB1_GPIOA);

	MGPIO_voidSetPinMode(PORT_A , PIN_9 , ALT_FUNC_MODE );
	MGPIO_voidSetPinAlternating(PORT_A , PIN_9 , USART1_2);
	MGPIO_voidSetPinMode(PORT_A , PIN_10 , ALT_FUNC_MODE );
	MGPIO_voidSetPinAlternating(PORT_A , PIN_10 , USART1_2);

	M_UART_Init();
	STK_voidInit();
	M_UART_Enable();
	STK_CtrlIntState(1);
	STK_voidStart(15000000*2);
	STK_SetCallBack(STK_CallBack);


	u8 local_u8UartRXStatus = 0;
	while(timoutFlag ==1)
	{
		local_u8UartRXStatus = M_UART_RecieveSynch(&Global_pu8RxBuffer[Global_u8RxBufferCounter]);
		if(local_u8UartRXStatus == 1)
		{
				if (EraseFlag !=1)  // ma3 awel if condition lama astlm awel char
				{
					EraseFlag = 1 ;
					FMI_allSectorErase();
				}
				/*stop timer */
				M_SYSTICK_Stop();


				if(Global_pu8RxBuffer[Global_u8RxBufferCounter] == '*')
				{



					Global_u8RxBufferCounter = 0;


				}
				else
				{
					Global_u8RxBufferCounter++;
				}

				if(Global_pu8RxBuffer[8] == '1')
				{
					for (u8 i=0;i<533;i++){

							M_HexParseData(Global_pu8RxBuffer[i]);

						}
						STK_CallBack();						// end of file
				}
		}
	}



}

