#include "config.h"
#include "EEPROM.h"
#include "fw_iap.h"

//Select IAP_CMD directly: vendor command macros trigger IAP and force EA = 1.

//========================================================================
// Function: void ISP_Disable(void)
// Description: Disable ISP/IAP access.
// Parameters: non.
// Returns: non.
// Version: V1.0, 2012-10-22
//========================================================================
void	DisableEEPROM(void)
{
	IAP_CONTR = 0;			//Disable IAP operations.
	IAP_CMD   = 0;			//Clear the IAP command.
	IAP_TRIG  = 0;			//Prevent accidental IAP command triggers.
	IAP_ADDRH = 0xff;		//Clear the high address byte.
	IAP_ADDRL = 0xff;		//Clear the low address byte and point outside EEPROM.
}

//========================================================================
// Function: void EEPROM_Trig(void)
// Description: Trigger an EEPROM operation.
// Parameters: none.
// Returns: none.
// Version: V1.0, 2014-6-30
//========================================================================
void EEPROM_Trig(void)
{
	F0 = EA;    //Save the global interrupt state.
	EA = 0;     //Disable interrupts so the trigger command remains valid.
	IAP_TRIG = 0x5A;
	IAP_TRIG = 0xA5;                    //Write 5AH, then A5H to the trigger register each time.
																			//Writing A5H triggers the IAP command immediately.
																			//The CPU waits for IAP completion before continuing.
	NOP();
	NOP();
	EA = F0;    //Restore the global interrupt state.
}

//========================================================================
// Function: void EEPROM_read_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number)
// Description: Read n bytes from an EEPROM address into a buffer.
// Parameters: EE_address:  Starting EEPROM address.
//             DataAddress: Destination buffer address.
//             number:      Number of bytes to read.
// Returns: non.
// Version: V1.0, 2012-10-22
//========================================================================
void EEPROM_read_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number)
{
	IAP_CONTR = 0x80;                       //Enable IAP and clear stale control flags.
	IAP_SetWaitTime();
	IAP_CMD = 1;                            //Issue the byte-read command once while unchanged.
	do
	{
		IAP_ADDRH = (uint8_t)(EE_address >> 8);
		IAP_ADDRL = (uint8_t)EE_address;
		EEPROM_Trig();                      //Trigger the EEPROM operation.
		*DataAddress = IAP_ReadData();      //Store the read data in the buffer.
		EE_address++;
		DataAddress++;
	}while(--number);

	DisableEEPROM();
}

//========================================================================
// Function: void EEPROM_SectorErase(uint16_t EE_address)
// Description: Erase the EEPROM sector at the specified address.
// Parameters: EE_address: Address of the EEPROM sector to erase.
// Returns: non.
// Version: V1.0, 2013-5-10
//========================================================================
void EEPROM_SectorErase(uint16_t EE_address)
{
	IAP_CONTR = 0x80;                   //Enable IAP and clear stale control flags.
	IAP_SetWaitTime();
	IAP_CMD = 3;                        //Issue the sector-erase command once while unchanged.
																			//Only sector erase is supported; each sector is 512 bytes.
																			//Any byte address in a sector identifies that sector.
	IAP_ADDRH = (uint8_t)(EE_address >> 8);
	IAP_ADDRL = (uint8_t)EE_address;
	EEPROM_Trig();                      //Trigger the EEPROM operation.
	DisableEEPROM();                    //Disable EEPROM operations.
}

//========================================================================
// Function: void EEPROM_write_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number)
// Description: Write n buffer bytes to an EEPROM address.
// Parameters: EE_address:  Starting EEPROM address.
//             DataAddress: Source buffer address.
//             number:      Number of bytes to write.
// Returns: non.
// Version: V1.0, 2012-10-22
//========================================================================
void EEPROM_write_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number)
{
	IAP_CONTR = 0x80;                   //Enable IAP and clear stale control flags.
	IAP_SetWaitTime();
	IAP_CMD = 2;                        //Issue the byte-write command.
	do
	{
		IAP_ADDRH = (uint8_t)(EE_address >> 8);
		IAP_ADDRL = (uint8_t)EE_address;
		IAP_WriteData(*DataAddress);     //Write IAP_DATA again only when the data changes.
		EEPROM_Trig();                    //Trigger the EEPROM operation.
		EE_address++;                     //Next address.
		DataAddress++;                    //Next data byte.
	}while(--number);                   //Continue until complete.
	DisableEEPROM();
}
