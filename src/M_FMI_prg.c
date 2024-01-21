#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "M_FMI_cfg.h"
#include "M_FMI_prv.h"
#include "M_FMI_int.h"


void FMI_voidSectorErase (u8 copy_u8Sector)
{
	/*1-pooling on Busy Flag*/
	while(!(GET_BIT(FMI->SR,16)));
	if(GET_BIT(FMI->CR,31) == 1)
	{
		FMI->KEYR = FMI_KEY1;
		FMI->KEYR = FMI_KEY2;
	}
	/*Select sector*/
	FMI->CR &= ~(0b1111<<3);
	FMI->CR |=(copy_u8Sector<<3);

	/*Select erase mode*/
	SET_BIT(FMI->CR , 1);
	/*start operation*/
	SET_BIT(FMI->CR , 16);
	while(!GET_BIT(FMI->CR , 16));
	/*Clear end of operation flag*/
	SET_BIT(FMI->SR , 0);
	/*Deselect erase mode*/
	CLR_BIT(FMI->CR , 1);

}

void FMI_allSectorErase (void)
{
	for( u8 i =1;i<=7;i++)
	{
		FMI_voidSectorErase (i);
	}
}
void FMI_voidFlashWrite (u32 copy_u32Addess ,  u16* copy_puData , u16 copy_u16Length )
{
	/*1-pooling on Busy Flag*/
	while(!(GET_BIT(FMI->SR,16)));
	if(GET_BIT(FMI->CR,31) == 1)
	{
		FMI->KEYR = FMI_KEY1;
		FMI->KEYR = FMI_KEY2;
	}
	/*select element size*/
	FMI->CR &=~(0b11<<8);
	FMI->CR |=(1<<8);
	/*Activiting Programming mode*/
	FMI->CR |=1;
	/* Write data on flash*/
	for(u16 counter = 0 ; counter <copy_u16Length ; counter ++)
	{
		*((volatile u16*)copy_u32Addess) =  copy_puData[counter];
		copy_u32Addess += 2;
	}
	while(!GET_BIT(FMI->CR , 16));
		/*Clear end of operation flag*/
		SET_BIT(FMI->SR , 0);
		/*Deselect erase mode*/
		CLR_BIT(FMI->CR , 0);


}



u16 DataBuffer[100] ;

static u8 HexParser_u8Ascii2Hex(u8 A_u8Ascii)
{
	u8 local_u8HexValue = 0;
	if(A_u8Ascii> '0' && A_u8Ascii<'9')
	{
		local_u8HexValue =local_u8HexValue-'0';
	}
	else if (A_u8Ascii>='A' && A_u8Ascii< 'F')
	{
		local_u8HexValue =local_u8HexValue-55;
	}
	return local_u8HexValue;
}
void M_HexParseData(u8* copy_u8arr)
{
	u8 cc_High = 0;
	u8 cc_Low = 0;
	u8 cc;
	u8 local_u8Digit0 = 0;
	u8 local_u8Digit1 = 0;
	u8 local_u8Digit2 = 0;
	u8 local_u8Digit3 = 0;
	u32 address =0;

	cc_High = HexParser_u8Ascii2Hex(copy_u8arr[1]);
	cc_Low = HexParser_u8Ascii2Hex(copy_u8arr[2]);
	cc=(cc_High<<4)| cc_Low;


	local_u8Digit0 = HexParser_u8Ascii2Hex(copy_u8arr[3]);
	local_u8Digit1 = HexParser_u8Ascii2Hex(copy_u8arr[4]);
	local_u8Digit2 = HexParser_u8Ascii2Hex(copy_u8arr[5]);
	local_u8Digit3 = HexParser_u8Ascii2Hex(copy_u8arr[6]);
	address = 0x8000000|(local_u8Digit0<<12)|(local_u8Digit1<<8)|(local_u8Digit2<<4)|(local_u8Digit3);

	for(u8 i = 0 ; i<(cc/2) ; i++)
	{
		local_u8Digit0 = HexParser_u8Ascii2Hex(copy_u8arr[9+(i*4)]);
		local_u8Digit1 = HexParser_u8Ascii2Hex(copy_u8arr[10+(i*4)]);
		local_u8Digit2 = HexParser_u8Ascii2Hex(copy_u8arr[11+(i*4)]);
		local_u8Digit3 = HexParser_u8Ascii2Hex(copy_u8arr[12+(i*4)]);
		DataBuffer[i] = (local_u8Digit0<<12)|(local_u8Digit1<<8)|(local_u8Digit2<<4)|(local_u8Digit3);
	}
	FMI_voidFlashWrite(address , DataBuffer , cc/2 );
}
