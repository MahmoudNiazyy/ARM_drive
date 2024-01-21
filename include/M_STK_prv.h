#ifndef M_SYSTICK_PRV_H
#define M_SYSTICK_PRV_H

#define SYSTICK_BASE_ADDRESS           0xE000E010


typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}Systick_t;

#define STK           ((volatile Systick_t*)SYSTICK_BASE_ADDRESS)

#define SYSTICK_CLOCK_SOURCE_MASK         0x00000000






#endif

