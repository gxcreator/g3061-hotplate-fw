#ifndef	__EEPROM_H
#define	__EEPROM_H

#include	"config.h"

void	DisableEEPROM(void);
void 	EEPROM_read_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number);
void 	EEPROM_write_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number);
void	EEPROM_SectorErase(uint16_t EE_address);


#endif
