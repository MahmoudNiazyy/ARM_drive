#ifndef M_UART_PRV_H
#define M_UART_PRV_H

#define M_UART1_BASE_ADDRESS	   0x40011000


typedef struct
{

	u32 SR  ;
	u32 DR  ;
	u32 BRR ;
	u32 CR1 ;
	u32 CR2 ;
	u32 CR3 ;
	u32 GTPR;



}UART_t;




#define UART1 		((volatile UART_t *)M_UART1_BASE_ADDRESS)








#endif
