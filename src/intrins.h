/* SDCC shim: provides Keil's <intrins.h> _nop_() */
#ifndef __SDCC_PORT_INTRINS_H
#define __SDCC_PORT_INTRINS_H

#define _nop_() __asm nop __endasm

#endif
