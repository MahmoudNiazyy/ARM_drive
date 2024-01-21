#ifndef EXTI_PRV_H_
#define EXTI_PRV_H_

#define EXTI_BASE_ADDRESS         0x40013C00
#define SYSCFG_BASE_ADDRESS       0x40013800

#define EXTI_SYSCFG_MASK          0b1111


typedef struct
{
	u32 MEMRMP;
	u32 PMC;
    u32 EXTICR[4];
    u32 CMPCR;

}SYSCFG_t;


typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;



#define EXTI                      ((volatile EXTI_t*)EXTI_BASE_ADDRESS)
#define SYSCFG                    ((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)






/*
#define SYSCFG_EXTICR1           *((volatile u32*)0x08)
#define SYSCFG_EXTICR2           *((volatile u32*)0x0C)
#define SYSCFG_EXTICR3           *((volatile u32*)0x10)
#define SYSCFG_EXTICR4           *((volatile u32*)0x14)
*/








#endif
