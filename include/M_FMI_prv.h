#ifndef M_FMI_PRV_H
#define M_FMI_PRV_H


#define FMI_BASE_ADDRESS  0x40023C00

typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 OPTCR;


}FMI_t;

#define FMI 	((volatile FMI_t*)FMI_BASE_ADDRESS)

#define FMI_KEY1 	 0x45670123
#define FMI_KEY2 	 0xCDEF89AB
#endif
