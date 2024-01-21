#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "M_GPIO_int.h"
#include "M_STK_int.h"
#include "H_LedMatrix_int.h"


void HLEDMATRIX_VoidInit(void){

	/*Set GPIO PIin Configuration  */
		/*Port A Row Setting */

		MGPIO_voidSetPinMode(PORT_A,PIN_1,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_A,PIN_2,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_A,PIN_3,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_A,PIN_4,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_A,PIN_5,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_A,PIN_6,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_A,PIN_7,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_A,PIN_8,OUTPUT_MODE);

		MGPIO_voidSetPinOutConfig(PORT_A,PIN_1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_A,PIN_2,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_A,PIN_3,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_A,PIN_4,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_A,PIN_5,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_A,PIN_6,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_A,PIN_7,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_A,PIN_8,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);

		/*Set GPIO PIN Config Port B COLS Setting */
		MGPIO_voidSetPinMode(PORT_B,PIN_0,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_B,PIN_1,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_B,PIN_2,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_B,PIN_5,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_B,PIN_6,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_B,PIN_7,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_B,PIN_8,OUTPUT_MODE);
		MGPIO_voidSetPinMode(PORT_B,PIN_9,OUTPUT_MODE);


		MGPIO_voidSetPinOutConfig(PORT_B,PIN_0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_B,PIN_1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_B,PIN_2,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_B,PIN_5,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_B,PIN_6,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_B,PIN_7,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_B,PIN_8,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);
		MGPIO_voidSetPinOutConfig(PORT_B,PIN_9,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM_SPEED);


}

void HLEDMATRIX_VoidDisplay(u8 *Copy_u8arr)
{



HLEDMATRIX_VoidDisableColumns();
HLEDMATRIX_VoidSetRowValue(Copy_u8arr[1]);
MGPIO_voidSetPinValue(PORT_A,PIN_1,PIN_HIGH);
M_SYSTICK_voidDelayMS(20);

HLEDMATRIX_VoidDisableColumns();
HLEDMATRIX_VoidSetRowValue(Copy_u8arr[2]);
MGPIO_voidSetPinValue(PORT_A,PIN_2,PIN_HIGH);
M_SYSTICK_voidDelayMS(20);

HLEDMATRIX_VoidDisableColumns();
HLEDMATRIX_VoidSetRowValue(Copy_u8arr[3]);
MGPIO_voidSetPinValue(PORT_A,PIN_3,PIN_HIGH);
M_SYSTICK_voidDelayMS(20);

HLEDMATRIX_VoidDisableColumns();
HLEDMATRIX_VoidSetRowValue(Copy_u8arr[4]);
MGPIO_voidSetPinValue(PORT_A,PIN_4,PIN_HIGH);
M_SYSTICK_voidDelayMS(20);

HLEDMATRIX_VoidDisableColumns();
HLEDMATRIX_VoidSetRowValue(Copy_u8arr[5]);
MGPIO_voidSetPinValue(PORT_A,PIN_5,PIN_HIGH);
M_SYSTICK_voidDelayMS(20);

HLEDMATRIX_VoidDisableColumns();
HLEDMATRIX_VoidSetRowValue(Copy_u8arr[6]);
MGPIO_voidSetPinValue(PORT_A,PIN_6,PIN_HIGH);
M_SYSTICK_voidDelayMS(20);

HLEDMATRIX_VoidDisableColumns();
HLEDMATRIX_VoidSetRowValue(Copy_u8arr[7]);
MGPIO_voidSetPinValue(PORT_A,PIN_7,PIN_HIGH);
M_SYSTICK_voidDelayMS(20);

HLEDMATRIX_VoidDisableColumns();
HLEDMATRIX_VoidSetRowValue(Copy_u8arr[8]);
MGPIO_voidSetPinValue(PORT_A,PIN_8,PIN_HIGH);
M_SYSTICK_voidDelayMS(20);
}

void HLEDMATRIX_VoidDisableColumns(void){
	MGPIO_voidSetPinValue(PORT_A,PIN_0,PIN_LOW);
	MGPIO_voidSetPinValue(PORT_A,PIN_1,PIN_LOW);
	MGPIO_voidSetPinValue(PORT_A,PIN_2,PIN_LOW);
	MGPIO_voidSetPinValue(PORT_A,PIN_3,PIN_LOW);
	MGPIO_voidSetPinValue(PORT_A,PIN_4,PIN_LOW);
	MGPIO_voidSetPinValue(PORT_A,PIN_5,PIN_LOW);

	MGPIO_voidSetPinValue(PORT_A,PIN_6,PIN_LOW);
	MGPIO_voidSetPinValue(PORT_A,PIN_7,PIN_LOW);
}

void HLEDMATRIX_VoidSetRowValue(u8 Copy_u8RowValue){
MGPIO_voidSetPinValue(PORT_B,PIN_0,!GET_BIT(Copy_u8RowValue,0));
MGPIO_voidSetPinValue(PORT_B,PIN_1,!GET_BIT(Copy_u8RowValue,1));
MGPIO_voidSetPinValue(PORT_B,PIN_2,!GET_BIT(Copy_u8RowValue,2));
MGPIO_voidSetPinValue(PORT_B,PIN_5,!GET_BIT(Copy_u8RowValue,3));
MGPIO_voidSetPinValue(PORT_B,PIN_6,!GET_BIT(Copy_u8RowValue,4));
MGPIO_voidSetPinValue(PORT_B,PIN_7,!GET_BIT(Copy_u8RowValue,5));
MGPIO_voidSetPinValue(PORT_B,PIN_8,!GET_BIT(Copy_u8RowValue,6));
MGPIO_voidSetPinValue(PORT_B,PIN_9,!GET_BIT(Copy_u8RowValue,7));
}



