#ifndef M_UART_INT_H
#define M_UART_INT_H


#define BAUD_9600RATE_MASK   52





void M_UART_Init(void);
void  M_UART_Enable(void);

void M_UART_SendFrame(char* Copy_u8SendData);
u8 M_UART_RecieveFrame(void);
void M_UART_SendData(u8 copy_u8data);
u8 M_UART_RecieveFrameEDITED(void);
u8 M_UART_RecieveSynch(u8 *Copy_u8PTr);











#endif
