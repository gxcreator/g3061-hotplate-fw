#include "board.h"
#include "i2c.h"

/* Keep the call overhead and single NOP used by the tested bus timing. */
static void soft_i2c_delay(void)
{
	NOP();
}

void i2c_init(void)
{
	SOFT_I2C_SCL=1;
	SOFT_I2C_SDA=1;
	/* SDA must be released for the slave's ACK bit. */
	GPIO_P3_SetMode(SOFT_I2C_SCL_PIN, GPIO_Mode_Output_PP);
	GPIO_P3_SetMode(SOFT_I2C_SDA_PIN, GPIO_Mode_InOut_QBD);
}

void i2c_start(void)
{
	SOFT_I2C_SDA=1;
	SOFT_I2C_SCL=1;
	soft_i2c_delay();
	SOFT_I2C_SDA=0;
	soft_i2c_delay();
	SOFT_I2C_SCL=0;
}

void i2c_stop(void)
{
	SOFT_I2C_SDA=0;
	soft_i2c_delay();
	SOFT_I2C_SCL=1;
	soft_i2c_delay();
	SOFT_I2C_SDA=1;
	soft_i2c_delay();
}

void i2c_clock_ack(void)
{
	SOFT_I2C_SDA=1;
	soft_i2c_delay();
	SOFT_I2C_SCL=1;
	soft_i2c_delay();
	SOFT_I2C_SCL=0;
	soft_i2c_delay();
}

void i2c_write_byte(uint8_t dat)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		SOFT_I2C_SCL=0;
		if(dat&0x80)
		{
			SOFT_I2C_SDA=1;
		}
		else
		{
			SOFT_I2C_SDA=0;
		}
		soft_i2c_delay();
		SOFT_I2C_SCL=1;
		soft_i2c_delay();
		SOFT_I2C_SCL=0;
		dat<<=1;
	}
}
