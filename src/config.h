#ifndef CONFIG_H
#define CONFIG_H

/* The Makefile supplies these for every translation unit. */
#if !defined(__CONF_MCU_MODEL) || !defined(__CONF_FOSC) || !defined(__CONF_CLKDIV)
#error Define the board MCU and clock configuration before including the HAL
#endif

#include "fw_conf.h"
#include "fw_types.h"

#endif
