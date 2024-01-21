#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "H_TFT_prv.h"
#include "H_TFT_int.h"
#include "M_GPIO_int.h"
#include "H_SPI_int.h"
#include "M_STK_int.h"

static void H_TFT_WriteCommande (u8 Copy_u8commande)
{
	MGPIO_voidSetPinValue(PORT_A , SDA_PIN,0);
	MSPI_u16Transceive(Copy_u8commande);
}
static void H_TFT_WriteData (u8 Copy_u8Data)
{
	MGPIO_voidSetPinValue(PORT_A , SDA_PIN,1);
	MSPI_u16Transceive(Copy_u8Data);

}

void H_TFT_Reset (void)
{
	MGPIO_voidSetPinValue(PORT_A , Reset_PIN,1);
	STK_voidDelayUs(100);
	MGPIO_voidSetPinValue(PORT_A , Reset_PIN,0);
	STK_voidDelayUs(10);
	MGPIO_voidSetPinValue(PORT_A , Reset_PIN,1);
	STK_voidDelayUs(100);
	MGPIO_voidSetPinValue(PORT_A , Reset_PIN,0);
	STK_voidDelayUs(100);
	MGPIO_voidSetPinValue(PORT_A , Reset_PIN,1);
	STK_voidDelayUs(120);
}

void H_TFT_Init(void)
{
	H_TFT_Reset();
	H_TFT_WriteCommande(0X11);	// tesahy el TFT
	STK_voidDelayMs(150);
	H_TFT_WriteCommande(0X3A);	// to select color mode
	H_TFT_WriteData(0X05);	// RGB565
	H_TFT_WriteCommande(0X29);	// Display
}

void H_TFT_Display(const u16* Copy_u8Arr)
{
	/*Setting X Dimensions */
	H_TFT_WriteCommande(0X2A);
	H_TFT_WriteData(0);
	H_TFT_WriteData(0);
	H_TFT_WriteData(0);
	H_TFT_WriteData(127);
	/*Setting Y Dimensions */
	H_TFT_WriteCommande(0X2B);
	H_TFT_WriteData(0);
	H_TFT_WriteData(0);
	H_TFT_WriteData(0);
	H_TFT_WriteData(159);
	H_TFT_WriteCommande(0X2C);
	for(u16 counter =0 ; counter < 20480 ; counter++)
	{
		u8 low = ((u8)Copy_u8Arr[counter]);
		u8 High = (u8)(Copy_u8Arr[counter]>>8);
		H_TFT_WriteData(High);
		H_TFT_WriteData(low);
	}
}
