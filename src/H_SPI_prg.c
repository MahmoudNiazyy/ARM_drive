#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "H_SPI_prv.h"
#include "H_SPI_int.h"
#include "SPI_cfg.h"
#include "M_GPIO_int.h"


void MSPI_voidInit(void)
{
	SPI1_REG->CR1 = 0x0347;
}

u16  MSPI_u16Transceive(u16 Copy_u16Data)
{
	/*Wait until the transmit buffer is empty*/

	SPI1_REG->DR = Copy_u16Data;
	/*Wait until the receive buffer is not empty*/
	while (GET_BIT(SPI1_REG->SR,7));
	return (u8)SPI1_REG->DR;
}
