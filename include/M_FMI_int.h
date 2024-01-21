#ifndef M_FMI_INT_H
#define M_FMI_INT_H


void FMI_voidSectorErase (u8 copy_u8Sector);
void FMI_voidFlashWrite (u32 copy_u32Addess ,  u16* copy_puData , u16 copy_u16Length );
void FMI_allSectorErase (void);
void M_HexParseData(u8* copy_u8arr);
//static u8 HexParser_u8Ascii2Hex(u8 A_u8Ascii);

#endif
