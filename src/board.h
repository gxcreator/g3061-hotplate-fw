#ifndef BOARD_H
#define BOARD_H

#include "config.h"
#include "fw_gpio.h"

/* Active-high heater and active-low buttons. */
#define heat P34
#define key0 P32 /* LEFT */
#define key1 P33 /* RIGHT */
#define HEATER_PIN GPIO_Pin_4
#define BUTTON_PINS (GPIO_Pin_2 | GPIO_Pin_3)

/* Software I2C: these pins cannot use the hardware I2C peripheral. */
#define SOFT_I2C_SCL P35
#define SOFT_I2C_SDA P36
#define OLED_RES P23
#define SOFT_I2C_SCL_PIN GPIO_Pin_5
#define SOFT_I2C_SDA_PIN GPIO_Pin_6
#define OLED_RES_PIN GPIO_Pin_3

#define vol_channel 0
#define tem_channel 1
#define vcc_channel 15
#define SUPPLY_ADC_PIN GPIO_Pin_0
#define TEMPERATURE_ADC_PIN GPIO_Pin_1

#endif
