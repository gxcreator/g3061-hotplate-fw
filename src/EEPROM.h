#ifndef	__EEPROM_H
#define	__EEPROM_H

#include	"config.h"

#define		STC8X1K08	8
#define		STC8X1K16	16
#define		STC8XxK32	32
#define		STC8XxK60	60

//	Select the MCU model.
#define	MCU_Type	STC8XxK60  //60 KiB code, 4 KiB IAP EEPROM

/************************** ISP/IAP *****************************

   Model        Size  Sectors  Start address    End address   MOVC read offset
STC8X1K08        4K     8      0x0000  ~  0x0FFF                0x2000
STC8X1K16       12K    24      0x0000  ~  0x2FFF                0x4000
STC8XxK32       32K    64      0x0000  ~  0x7FFF                0x8000
STC8XxK60        4K     8      0x0000  ~  0x0FFF                0xF000

*/

#if   (MCU_Type == STC8X1K08)
      #define   MOVC_ShiftAddress    0x2000
#elif (MCU_Type == STC8X1K16)
      #define   MOVC_ShiftAddress    0x4000
#elif (MCU_Type == STC8XxK32)
      #define   MOVC_ShiftAddress    0x8000
#elif (MCU_Type == STC8XxK60)
      #define   MOVC_ShiftAddress    0xF000
#else
      #define   MOVC_ShiftAddress    0xC000		//User-defined.
#endif


void	DisableEEPROM(void);
void 	EEPROM_read_n(u16 EE_address,u8 *DataAddress,u16 number);
void 	EEPROM_write_n(u16 EE_address,u8 *DataAddress,u16 number);
void	EEPROM_SectorErase(u16 EE_address);


#endif
