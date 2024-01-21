#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "M_UART_prv.h"
#include "M_UART_cgf.h"
#include "M_UART_int.h"

static void (*M_UART_CallBack)(void) = ((void*)0);

void M_UART_Init(void)
{

	UART1->BRR = (104<<4)| 3;	// to select baud rate 9600 + mantessa
	//UART1->CR1 |= (1<<6);		// to select interrupt mode
	UART1->CR2 &= ~(1<<13);		// to select 1 stop bit
	UART1->CR2 &= ~(1<<12);		// to select 1 stop bit
	UART1->CR1 &= ~(1<<15);

	UART1->SR = 0;


}



void  M_UART_Disable(void)
{
	UART1->CR1 &= ~(1<<3);	// disable transsmission
	UART1->CR1 &= ~(1<<2);	// disable Recieve
	UART1->CR1 &= ~(1<<13);
}

void  M_UART_Enable(void)
{
	UART1->CR1 |= (1<<3);	// enable transsmission
	UART1->CR1 |= (1<<2);	// enable Recieve
	UART1->CR1 |= (1<<13);
}


void M_UART_SendFrame(char* Copy_u8SendData)
{
	u8 counter = 0;
	for(counter =0; Copy_u8SendData[counter] ; counter ++)
	{
		UART1->DR = Copy_u8SendData[counter];
		while(! (GET_BIT(UART1->SR, 7)) );
	}


}


void M_UART_SendData(u8 copy_u8data)
{

		UART1->DR = copy_u8data;
		while(! (GET_BIT(UART1->SR, 7)) );



}

u8 M_UART_RecieveFrame(void)
{
	while(! (GET_BIT(UART1->SR, 5)) );

	return  (u8)UART1->DR ;


}

void MUARTCallback(void (*ptr)(void))
{
	M_UART_CallBack = ptr;
}

void USART1_IRQHandler(void)
{
	M_UART_CallBack();
}


u8 M_UART_RecieveSynch(u8 *Copy_u8PTr)
{
	u8 Status = 0;
	if( (GET_BIT(UART1->SR, 5)) ==1 )
	{
		*Copy_u8PTr = (u8)UART1->DR;
		Status = 1;
	}
	else
	{
		Status = 0;

	}

	return  Status ;


}
