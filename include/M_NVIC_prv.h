#ifndef NVIC_PRV_H_
#define NVIC_PRV_H_




typedef struct
{
	u32 ISER[8] ;
	u32 reserved0[24];
	u32 ICER[8];
	u32 reserved1[24];
	u32 ISPR[8];
	u32 reserved2[24];
	u32 ICPR[8];
	u32 reserved3[24];
	u32 IABR[8];
	u32 reserved4[56];
	u8 IPR[240];
	u32 reserved5[580];
	u32 STIR;

}NVIC_t;

#define NVIC_BASE_ADDRESS            0xE000E100

#define NVIC                         ((volatile NVIC_t*)NVIC_BASE_ADDRESS)

#define  SCB_AIRCR                   (*(volatile u32 *)0xE000ED0C)

#define NVIC_VECTKEY                 0x05FA0000


#define REGISTER_DIVISION       32






































/*
typedef struct
{
	u32 ISER0;
    u32 ISER1;
    u32 ISER2;
    u32 ISER3;
    u32 ISER4;
    u32 ISER5;
    u32 ISER6;
    u32 ISER7;
    u32 ICER0;
    u32 ICER1;
    u32 ICER2;
    u32 ICER3;
    u32 ICER4;
    u32 ICER5;
    u32 ICER6;
    u32 ICER7;
    u32 ISPR0;
    u32 ISPR1;
    u32 ISPR2;
    u32 ISPR3;
    u32 ISPR4;
    u32 ISPR5;
    u32 ISPR6;
    u32 ISPR7;
    u32 ICPR0;
    u32 ICPR1;
    u32 ICPR2;
    u32 ICPR3;
    u32 ICPR4;
    u32 ICPR5;
    u32 ICPR6;
    u32 ICPR7;
    u32 IABR0;
    u32 IABR1;
    u32 IABR2;
    u32 IABR3;
    u32 IABR4;
    u32 IABR5;
    u32 IABR6;
    u32 IABR7;




}NVIC_t;
*/


#endif
