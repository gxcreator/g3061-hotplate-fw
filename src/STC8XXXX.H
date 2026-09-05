/* SDCC-converted register header for STC8xxxx (STCxH family). */
/* Generated from STC8xxxx.h; the original is kept for Keil in ../ */
#ifndef __STC8XXXX_H_SDCC_GEN
#define __STC8XXXX_H_SDCC_GEN

/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* If this code is used, note that it uses STC documentation and code.            */
/*---------------------------------------------------------------------*/

#ifndef	_STC8xxxx_H
#define	_STC8xxxx_H

#include <intrins.h>

/*  BYTE Registers  */
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x80) P0;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x81) SP;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x82) DPL;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x83) DPH;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x84) S4CON;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x85) S4BUF;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x87) PCON;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x88) TCON;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x89) TMOD;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x8A) TL0;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x8B) TL1;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x8C) TH0;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x8D) TH1;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x8E) AUXR;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x8F) WAKE_CLKO;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x8F) INT_CLKO;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x90) P1;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x91) P1M1;	//P1M1.n,P1M0.n 	=00--->Standard,	01--->push-pull		All 1T devices behave the same
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x92) P1M0;	//					=10--->pure input,	11--->open drain
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x93) P0M1;	//P0M1.n,P0M0.n 	=00--->Standard,	01--->push-pull
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x94) P0M0;	//					=10--->pure input,	11--->open drain
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x95) P2M1;	//P2M1.n,P2M0.n 	=00--->Standard,	01--->push-pull
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x96) P2M0;	//					=10--->pure input,	11--->open drain
//sfr PCON2 = 0x97;
//sfr	AUXR2 = 0x97;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x98) SCON;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x99) SBUF;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x9A) S2CON;	//
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0x9B) S2BUF;	//

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xA0) P2;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xA1) BUS_SPEED;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xA2) P_SW1;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xA8) IE;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xA9) SADDR;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xAA) WKTCL;	//Wake-up timer low byte
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xAB) WKTCH;	//Wake-up timer high byte
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xAC) S3CON;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xAD) S3BUF;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xAE) TA;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xAF) IE2;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB0) P3;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB1) P3M1;	//P3M1.n,P3M0.n 	=00--->Standard,	01--->push-pull
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB2) P3M0;	//					=10--->pure input,	11--->open drain
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB3) P4M1;	//P4M1.n,P4M0.n 	=00--->Standard,	01--->push-pull
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB4) P4M0;	//					=10--->pure input,	11--->open drain
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB5) IP2;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB6) IP2H;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB7) IPH;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB8) IP;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xB9) SADEN;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xBA) P_SW2;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xBB) VOCTRL;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xBC) ADC_CONTR;	//ADC control register
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xBD) ADC_RES;	//ADC result high byte
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xBE) ADC_RESL;	//ADC result low byte

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC0) P4;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC1) WDT_CONTR;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC2) IAP_DATA;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC3) IAP_ADDRH;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC4) IAP_ADDRL;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC5) IAP_CMD;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC6) IAP_TRIG;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC7) IAP_CONTR;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC2) ISP_DATA;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC3) ISP_ADDRH;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC4) ISP_ADDRL;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC5) ISP_CMD;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC6) ISP_TRIG;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC7) ISP_CONTR;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC8) P5;	//
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xC9) P5M1;	//	P5M1.n,P5M0.n 	=00--->Standard,	01--->push-pull
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xCA) P5M0;	//					=10--->pure input,	11--->open drain
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xCB) P6M1;	//	P5M1.n,P5M0.n 	=00--->Standard,	01--->push-pull
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xCC) P6M0;	//					=10--->pure input,	11--->open drain
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xCD) SPSTAT;	//
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xCE) SPCTL;	//
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xCF) SPDAT;	//

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD0) PSW;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD1) T4T3M;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD2) T4H;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD3) T4L;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD4) T3H;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD5) T3L;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD6) T2H;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD7) T2L;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD2) TH4;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD3) TL4;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD4) TH3;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD5) TL3;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD6) TH2;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD7) TL2;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD8) CCON;	//
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xD9) CMOD;	//
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xDA) CCAPM0;	//PCA module 0 operating mode register.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xDB) CCAPM1;	//PCA module 1 operating mode register.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xDC) CCAPM2;	//PCA module 2 operating mode register.
//sfr CCAPM3 = 0xDD; //Working mode register of PCA module 3.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xDC) USBCLK;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xDE) ADCCFG;	//
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xDF) IP3;	//Interrupt priority register

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE0) ACC;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE1) P7M1;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE2) P7M0;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE3) DPS;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE4) DPL1;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE5) DPH1;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE6) CMPCR1;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE7) CMPCR2;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE8) P6;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xE9) CL;	//
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xEA) CCAP0L;	//The lower 8 bits of the capture/compare register of PCA module 0.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xEB) CCAP1L;	//The lower 8 bits of the capture/compare register of PCA module 1.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xEC) CCAP2L;	//The lower 8 bits of the capture/compare register of PCA module 2.
//sfr CCAP3L = 0xED; //The lower 8 bits of the capture/compare register of PCA module 3.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xEC) USBDAT;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xEE) IP3H;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xEF) AUXINTIF;	//Auxiliary interrupt flags B6-INT4IF, B5-INT3IF, B4-INT2IF, B2-T4IF, B1-T3IF, B0-T2IF

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF0) B;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF1) PWMSET;	//Enhanced PWM global configuration register
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF2) PCA_PWM0;	//PCA module 0 PWM register.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF3) PCA_PWM1;	//PCA module 1 PWM register.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF4) PCA_PWM2;	//PCA module 2 PWM register.
//sfr PCA_PWM3 = 0xF5; //PCA module 3 PWM register.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF6) PWMCFG01;	//Enhanced PWM configuration register
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF7) PWMCFG23;	//Enhanced PWM configuration register
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF4) USBCON;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF5) IAP_TPS;

#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF8) P7;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xF9) CH;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xFA) CCAP0H;		//The upper 8 bits of the capture/compare register of PCA module 0.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xFB) CCAP1H;		//The upper 8 bits of the capture/compare register of PCA module 1.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xFC) CCAP2H;		//The upper 8 bits of the capture/compare register of PCA module 2.
//sfr CCAP3H = 0xFD; //High 8 bits of capture/compare register of PCA module 3.
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xFE) PWMCFG45;	//Enhanced PWM configuration register
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xFC) USBADR;
#include <intrins.h>
#define code __code
#define bit  __bit

__sfr __at(0xFF) RSTCFG;		//


//                                     7    6    5    4    3     2       1       0      Reset Value
//INT_CLKO: Interrupt and clock output control register - EX4 EX3 EX2 - T2CLKO T1CLKO T0CLKO 0000,0000
#define	INT4_Enable()	INT_CLKO |= (1 << 6)
#define	INT3_Enable()	INT_CLKO |= (1 << 5)	
#define	INT2_Enable()	INT_CLKO |= (1 << 4)	
#define	INT1_Enable()	EX1 = 1
#define	INT0_Enable()	EX0 = 1

#define	INT4_Disable()	INT_CLKO &= ~(1 << 6)
#define	INT3_Disable()	INT_CLKO &= ~(1 << 5)	
#define	INT2_Disable()	INT_CLKO &= ~(1 << 4)	
#define	INT1_Disable()	EX1 = 0
#define	INT0_Disable()	EX0 = 0

//                               7    6       5       4      3    2     1     0      Reset Value
//AUXINTIF: Auxiliary interrupt flag register - INT4IF INT3IF INT2IF - T4IF T3IF T2IF 0000,0000
#define	INT4IF	0x40
#define	INT3IF	0x20
#define	INT2IF	0x10
#define	T4IF	0x04
#define	T3IF	0x02
#define	T2IF	0x01

#define	INT4_Clear()	AUXINTIF &= ~INT4IF		/* Clear the external interrupt 4 flag */
#define	INT3_Clear()	AUXINTIF &= ~INT3IF		/* Clear the external interrupt 3 flag */
#define	INT2_Clear()	AUXINTIF &= ~INT2IF		/* Clear the external interrupt 2 flag */
#define	INT1_Clear()	IE1 = 0					/* Clear external interrupt 1 flag */
#define	INT0_Clear()	IE0 = 0					/* Clear the external interrupt 0 flag */

#define	INT0_Fall()		IT0 = 1		/* INT0 falling edge interrupt           */
#define	INT0_RiseFall()	IT0 = 0		/* INT0 interrupts on both falling and rising edges   */
#define	INT1_Fall()		IT1 = 1		/* INT1 falling edge interrupt           */
#define	INT1_RiseFall()	IT0 = 0		/* INT1 interrupts on both falling and rising edges   */


//===============================================================
#define	EAXSFR()		P_SW2 |=  0x80		/* MOVX A,@DPTR/MOVX @DPTR,A operates on extended SFR (XSFR) */
#define	EAXRAM()		P_SW2 &= ~0x80		/* MOVX A,@DPTR/MOVX @DPTR,A operates on extended RAM (XRAM) */

#define	I2C_USE_P14P15()	P_SW2 &= ~0x30						/* Switch I2C to P1.4(SDA) P1.5(SCL) (power-on default).*/
#define	I2C_USE_P24P25()	P_SW2  = (P_SW2 & ~0x30) | 0x10		/* Switch I2C to P2.4(SDA) P2.5(SCL).*/
#define	I2C_USE_P76P77()	P_SW2  = (P_SW2 & ~0x30) | 0x20		/* Switch I2C to P7.6(SDA) P7.7(SCL).*/
#define	I2C_USE_P33P32()	P_SW2 |= 0x30						/* Switch I2C to P3.3(SDA) P3.2(SCL).*/

#define CLKSEL      (*(unsigned char volatile __xdata *)0xfe00)
#define	CKSEL		(*(unsigned char volatile __xdata *)0xfe00)	/* Main clock source selection    */
#define	CLKDIV		(*(unsigned char volatile __xdata *)0xfe01)	/* Main clock frequency division      */
#define	IRC24MCR	(*(unsigned char volatile __xdata *)0xfe02)	/* IRC 24MHZ control   */
#define	XOSCCR		(*(unsigned char volatile __xdata *)0xfe03)	/* XOSC control        */
#define	IRC32KCR	(*(unsigned char volatile __xdata *)0xfe04)	/* IRC 32KHZ control   */
#define MCLKOCR   (*(unsigned char volatile __xdata *)0xfe05)
#define IRCDB     (*(unsigned char volatile __xdata *)0xfe06)
#define X32KCR    (*(unsigned char volatile __xdata *)0xfe08)

#define	MainFosc_IRC24M()	CKSEL = (CKSEL & ~0x03)			/* Select internal 24MHZ clock */
#define	MainFosc_XTAL()		CKSEL = (CKSEL & ~0x03) | 0x01	/* Select external crystal or clock */
#define	MainFosc_IRC32K()	CKSEL =  CKSEL | 0x03			/* Select internal 32K clock */
#define	EXT_CLOCK()			XOSCCR = 0x80					/* Select external clock */
#define	EXT_CRYSTAL()		XOSCCR = 0xC0					/* Select external crystal oscillator */


#define	P0PU		(*(unsigned char volatile __xdata *)0xfe10)	/* P0 4.1K Pull Up Enable  */
#define	P1PU		(*(unsigned char volatile __xdata *)0xfe11)	/* P1 4.1K Pull Up Enable  */
#define	P2PU		(*(unsigned char volatile __xdata *)0xfe12)	/* P2 4.1K Pull Up Enable  */
#define	P3PU		(*(unsigned char volatile __xdata *)0xfe13)	/* P3 4.1K Pull Up Enable  */
#define	P4PU		(*(unsigned char volatile __xdata *)0xfe14)	/* P4 4.1K Pull Up Enable  */
#define	P5PU		(*(unsigned char volatile __xdata *)0xfe15)	/* P5 4.1K Pull Up Enable  */
#define	P6PU		(*(unsigned char volatile __xdata *)0xfe16)	/* P6 4.1K Pull Up Enable  */
#define	P7PU		(*(unsigned char volatile __xdata *)0xfe17)	/* P7 4.1K Pull Up Enable  */

#define	P0NCS		(*(unsigned char volatile __xdata *)0xfe18)	/* P0 Non Schmit Trigger 0: Enable port Schmitt trigger function (default), 1: Disable  */
#define	P1NCS		(*(unsigned char volatile __xdata *)0xfe19)	/* P1 Non Schmit Trigger  */
#define	P2NCS		(*(unsigned char volatile __xdata *)0xfe1a)	/* P2 Non Schmit Trigger  */
#define	P3NCS		(*(unsigned char volatile __xdata *)0xfe1b)	/* P3 Non Schmit Trigger  */
#define	P4NCS		(*(unsigned char volatile __xdata *)0xfe1c)	/* P4 Non Schmit Trigger  */
#define	P5NCS		(*(unsigned char volatile __xdata *)0xfe1d)	/* P5 Non Schmit Trigger  */
#define	P6NCS		(*(unsigned char volatile __xdata *)0xfe1e)	/* P6 Non Schmit Trigger  */
#define	P7NCS		(*(unsigned char volatile __xdata *)0xfe1f)	/* P7 Non Schmit Trigger  */

#define P0SR    (*(unsigned char volatile __xdata *)0xfe20) /* Port level conversion speed 0: fast, 1: slow (default)  */
#define P1SR    (*(unsigned char volatile __xdata *)0xfe21)
#define P2SR    (*(unsigned char volatile __xdata *)0xfe22)
#define P3SR    (*(unsigned char volatile __xdata *)0xfe23)
#define P4SR    (*(unsigned char volatile __xdata *)0xfe24)
#define P5SR    (*(unsigned char volatile __xdata *)0xfe25)
#define P6SR    (*(unsigned char volatile __xdata *)0xfe26)
#define P7SR    (*(unsigned char volatile __xdata *)0xfe27)

#define P0DR    (*(unsigned char volatile __xdata *)0xfe28) /* Port drive current control 0: Enhanced drive capability, 1: Normal drive capability (default)  */
#define P1DR    (*(unsigned char volatile __xdata *)0xfe29)
#define P2DR    (*(unsigned char volatile __xdata *)0xfe2a)
#define P3DR    (*(unsigned char volatile __xdata *)0xfe2b)
#define P4DR    (*(unsigned char volatile __xdata *)0xfe2c)
#define P5DR    (*(unsigned char volatile __xdata *)0xfe2d)
#define P6DR    (*(unsigned char volatile __xdata *)0xfe2e)
#define P7DR    (*(unsigned char volatile __xdata *)0xfe2f)

#define P0IE    (*(unsigned char volatile __xdata *)0xfe30)/* Port digital signal input enable 0: disable digital signal input, 1: enable digital signal input (default)  */
#define P1IE    (*(unsigned char volatile __xdata *)0xfe31)
#define P2IE    (*(unsigned char volatile __xdata *)0xfe32)
#define P3IE    (*(unsigned char volatile __xdata *)0xfe33)
#define P4IE    (*(unsigned char volatile __xdata *)0xfe34)
#define P5IE    (*(unsigned char volatile __xdata *)0xfe35)
#define P6IE    (*(unsigned char volatile __xdata *)0xfe36)
#define P7IE    (*(unsigned char volatile __xdata *)0xfe37)

#define	I2CCFG		(*(unsigned char volatile __xdata *)0xfe80)	/*   */
#define	I2CMSCR		(*(unsigned char volatile __xdata *)0xfe81)	/*   */
#define	I2CMSST		(*(unsigned char volatile __xdata *)0xfe82)	/*   */
#define	I2CSLCR		(*(unsigned char volatile __xdata *)0xfe83)	/*   */
#define	I2CSLST		(*(unsigned char volatile __xdata *)0xfe84)	/*   */
#define	I2CSLADR	(*(unsigned char volatile __xdata *)0xfe85)	/*   */
#define	I2CTXD		(*(unsigned char volatile __xdata *)0xfe86)	/*   */
#define	I2CRXD		(*(unsigned char volatile __xdata *)0xfe87)	/*   */
#define I2CMSAUX  (*(unsigned char volatile __xdata *)0xfe88)

#define TM2PS     (*(unsigned char volatile __xdata *)0xfea2)
#define TM3PS     (*(unsigned char volatile __xdata *)0xfea3)
#define TM4PS     (*(unsigned char volatile __xdata *)0xfea4)
#define ADCTIM    (*(unsigned char volatile __xdata *)0xfea8)
#define T3T4PIN   (*(unsigned char volatile __xdata *)0xfeac)

#define PWMA_ETRPS (*(unsigned char volatile __xdata *)0xfeb0)
#define PWMA_ENO   (*(unsigned char volatile __xdata *)0xfeb1)
#define PWMA_PS    (*(unsigned char volatile __xdata *)0xfeb2)
#define PWMA_IOAUX (*(unsigned char volatile __xdata *)0xfeb3)
#define PWMB_ETRPS (*(unsigned char volatile __xdata *)0xfeb4)
#define PWMB_ENO   (*(unsigned char volatile __xdata *)0xfeb5)
#define PWMB_PS    (*(unsigned char volatile __xdata *)0xfeb6)
#define PWMB_IOAUX (*(unsigned char volatile __xdata *)0xfeb7)
#define PWMA_CR1   (*(unsigned char volatile __xdata *)0xfec0)
#define PWMA_CR2   (*(unsigned char volatile __xdata *)0xfec1)
#define PWMA_SMCR  (*(unsigned char volatile __xdata *)0xfec2)
#define PWMA_ETR   (*(unsigned char volatile __xdata *)0xfec3)
#define PWMA_IER   (*(unsigned char volatile __xdata *)0xfec4)
#define PWMA_SR1   (*(unsigned char volatile __xdata *)0xfec5)
#define PWMA_SR2   (*(unsigned char volatile __xdata *)0xfec6)
#define PWMA_EGR   (*(unsigned char volatile __xdata *)0xfec7)
#define PWMA_CCMR1 (*(unsigned char volatile __xdata *)0xfec8)
#define PWMA_CCMR2 (*(unsigned char volatile __xdata *)0xfec9)
#define PWMA_CCMR3 (*(unsigned char volatile __xdata *)0xfeca)
#define PWMA_CCMR4 (*(unsigned char volatile __xdata *)0xfecb)
#define PWMA_CCER1 (*(unsigned char volatile __xdata *)0xfecc)
#define PWMA_CCER2 (*(unsigned char volatile __xdata *)0xfecd)
#define PWMA_CNTR  (*(unsigned int volatile __xdata *)0xfece)
#define PWMA_CNTRH (*(unsigned char volatile __xdata *)0xfece)
#define PWMA_CNTRL (*(unsigned char volatile __xdata *)0xfecf)
#define PWMA_PSCR  (*(unsigned int volatile __xdata *)0xfed0)
#define PWMA_PSCRH (*(unsigned char volatile __xdata *)0xfed0)
#define PWMA_PSCRL (*(unsigned char volatile __xdata *)0xfed1)
#define PWMA_ARR   (*(unsigned int volatile __xdata *)0xfed2)
#define PWMA_ARRH  (*(unsigned char volatile __xdata *)0xfed2)
#define PWMA_ARRL  (*(unsigned char volatile __xdata *)0xfed3)
#define PWMA_RCR   (*(unsigned char volatile __xdata *)0xfed4)
#define PWMA_CCR1  (*(unsigned int volatile __xdata *)0xfed5)
#define PWMA_CCR1H (*(unsigned char volatile __xdata *)0xfed5)
#define PWMA_CCR1L (*(unsigned char volatile __xdata *)0xfed6)
#define PWMA_CCR2  (*(unsigned int volatile __xdata *)0xfed7)
#define PWMA_CCR2H (*(unsigned char volatile __xdata *)0xfed7)
#define PWMA_CCR2L (*(unsigned char volatile __xdata *)0xfed8)
#define PWMA_CCR3  (*(unsigned int volatile __xdata *)0xfed9)
#define PWMA_CCR3H (*(unsigned char volatile __xdata *)0xfed9)
#define PWMA_CCR3L (*(unsigned char volatile __xdata *)0xfeda)
#define PWMA_CCR4  (*(unsigned int volatile __xdata *)0xfedb)
#define PWMA_CCR4H (*(unsigned char volatile __xdata *)0xfedb)
#define PWMA_CCR4L (*(unsigned char volatile __xdata *)0xfedc)
#define PWMA_BRK   (*(unsigned char volatile __xdata *)0xfedd)
#define PWMA_DTR   (*(unsigned char volatile __xdata *)0xfede)
#define PWMA_OISR  (*(unsigned char volatile __xdata *)0xfedf)

#define PWMB_CR1   (*(unsigned char volatile __xdata *)0xfee0)
#define PWMB_CR2   (*(unsigned char volatile __xdata *)0xfee1)
#define PWMB_SMCR  (*(unsigned char volatile __xdata *)0xfee2)
#define PWMB_ETR   (*(unsigned char volatile __xdata *)0xfee3)
#define PWMB_IER   (*(unsigned char volatile __xdata *)0xfee4)
#define PWMB_SR1   (*(unsigned char volatile __xdata *)0xfee5)
#define PWMB_SR2   (*(unsigned char volatile __xdata *)0xfee6)
#define PWMB_EGR   (*(unsigned char volatile __xdata *)0xfee7)
#define PWMB_CCMR1 (*(unsigned char volatile __xdata *)0xfee8)
#define PWMB_CCMR2 (*(unsigned char volatile __xdata *)0xfee9)
#define PWMB_CCMR3 (*(unsigned char volatile __xdata *)0xfeea)
#define PWMB_CCMR4 (*(unsigned char volatile __xdata *)0xfeeb)
#define PWMB_CCER1 (*(unsigned char volatile __xdata *)0xfeec)
#define PWMB_CCER2 (*(unsigned char volatile __xdata *)0xfeed)
#define PWMB_CNTR  (*(unsigned int volatile __xdata *)0xfeee)
#define PWMB_CNTRH (*(unsigned char volatile __xdata *)0xfeee)
#define PWMB_CNTRL (*(unsigned char volatile __xdata *)0xfeef)
#define PWMB_PSCR  (*(unsigned int volatile __xdata *)0xfef0)
#define PWMB_PSCRH (*(unsigned char volatile __xdata *)0xfef0)
#define PWMB_PSCRL (*(unsigned char volatile __xdata *)0xfef1)
#define PWMB_ARR   (*(unsigned int volatile __xdata *)0xfef2)
#define PWMB_ARRH  (*(unsigned char volatile __xdata *)0xfef2)
#define PWMB_ARRL  (*(unsigned char volatile __xdata *)0xfef3)
#define PWMB_RCR   (*(unsigned char volatile __xdata *)0xfef4)
#define PWMB_CCR5  (*(unsigned int volatile __xdata *)0xfef5)
#define PWMB_CCR5H (*(unsigned char volatile __xdata *)0xfef5)
#define PWMB_CCR5L (*(unsigned char volatile __xdata *)0xfef6)
#define PWMB_CCR6  (*(unsigned int volatile __xdata *)0xfef7)
#define PWMB_CCR6H (*(unsigned char volatile __xdata *)0xfef7)
#define PWMB_CCR6L (*(unsigned char volatile __xdata *)0xfef8)
#define PWMB_CCR7  (*(unsigned int volatile __xdata *)0xfef9)
#define PWMB_CCR7H (*(unsigned char volatile __xdata *)0xfef9)
#define PWMB_CCR7L (*(unsigned char volatile __xdata *)0xfefa)
#define PWMB_CCR8  (*(unsigned int volatile __xdata *)0xfefb)
#define PWMB_CCR8H (*(unsigned char volatile __xdata *)0xfefb)
#define PWMB_CCR8L (*(unsigned char volatile __xdata *)0xfefc)
#define PWMB_BRK   (*(unsigned char volatile __xdata *)0xfefd)
#define PWMB_DTR   (*(unsigned char volatile __xdata *)0xfefe)
#define PWMB_OISR  (*(unsigned char volatile __xdata *)0xfeff)

/////////////////////////////////////////////////
//FD00H-FDFFH
/////////////////////////////////////////////////

#define     PWM0C       (*(unsigned int volatile __xdata *)0xff00)
#define     PWM0CH      (*(unsigned char volatile __xdata *)0xff00)
#define     PWM0CL      (*(unsigned char volatile __xdata *)0xff01)
#define     PWM0CKS     (*(unsigned char volatile __xdata *)0xff02)
#define     PWM0TADC    (*(unsigned int volatile __xdata *)0xff03)
#define     PWM0TADCH   (*(unsigned char volatile __xdata *)0xff03)
#define     PWM0TADCL   (*(unsigned char volatile __xdata *)0xff04)
#define     PWM0IF      (*(unsigned char volatile __xdata *)0xff05)
#define     PWM0FDCR    (*(unsigned char volatile __xdata *)0xff06)
#define     PWM00T1     (*(unsigned int volatile __xdata *)0xff10)
#define     PWM00T1H    (*(unsigned char volatile __xdata *)0xff10)
#define     PWM00T1L    (*(unsigned char volatile __xdata *)0xff11)
#define     PWM00T2     (*(unsigned int volatile __xdata *)0xff12)
#define     PWM00T2H    (*(unsigned char volatile __xdata *)0xff12)
#define     PWM00T2L    (*(unsigned char volatile __xdata *)0xff13)
#define     PWM00CR     (*(unsigned char volatile __xdata *)0xff14)
#define     PWM00HLD    (*(unsigned char volatile __xdata *)0xff15)
#define     PWM01T1     (*(unsigned int volatile __xdata *)0xff18)
#define     PWM01T1H    (*(unsigned char volatile __xdata *)0xff18)
#define     PWM01T1L    (*(unsigned char volatile __xdata *)0xff19)
#define     PWM01T2    	(*(unsigned int volatile __xdata *)0xff1a)
#define     PWM01T2H    (*(unsigned char volatile __xdata *)0xff1a)
#define     PWM01T2L    (*(unsigned char volatile __xdata *)0xff1b)
#define     PWM01CR     (*(unsigned char volatile __xdata *)0xff1c)
#define     PWM01HLD    (*(unsigned char volatile __xdata *)0xff1d)
#define     PWM02T1     (*(unsigned int volatile __xdata *)0xff20)
#define     PWM02T1H    (*(unsigned char volatile __xdata *)0xff20)
#define     PWM02T1L    (*(unsigned char volatile __xdata *)0xff21)
#define     PWM02T2    	(*(unsigned int volatile __xdata *)0xff22)
#define     PWM02T2H    (*(unsigned char volatile __xdata *)0xff22)
#define     PWM02T2L    (*(unsigned char volatile __xdata *)0xff23)
#define     PWM02CR     (*(unsigned char volatile __xdata *)0xff24)
#define     PWM02HLD    (*(unsigned char volatile __xdata *)0xff25)
#define     PWM03T1    	(*(unsigned int volatile __xdata *)0xff28)
#define     PWM03T1H    (*(unsigned char volatile __xdata *)0xff28)
#define     PWM03T1L    (*(unsigned char volatile __xdata *)0xff29)
#define     PWM03T2    	(*(unsigned int volatile __xdata *)0xff2a)
#define     PWM03T2H    (*(unsigned char volatile __xdata *)0xff2a)
#define     PWM03T2L    (*(unsigned char volatile __xdata *)0xff2b)
#define     PWM03CR     (*(unsigned char volatile __xdata *)0xff2c)
#define     PWM03HLD    (*(unsigned char volatile __xdata *)0xff2d)
#define     PWM04T1    	(*(unsigned int volatile __xdata *)0xff30)
#define     PWM04T1H    (*(unsigned char volatile __xdata *)0xff30)
#define     PWM04T1L    (*(unsigned char volatile __xdata *)0xff31)
#define     PWM04T2    	(*(unsigned int volatile __xdata *)0xff32)
#define     PWM04T2H    (*(unsigned char volatile __xdata *)0xff32)
#define     PWM04T2L    (*(unsigned char volatile __xdata *)0xff33)
#define     PWM04CR     (*(unsigned char volatile __xdata *)0xff34)
#define     PWM04HLD    (*(unsigned char volatile __xdata *)0xff35)
#define     PWM05T1     (*(unsigned int volatile __xdata *)0xff38)
#define     PWM05T1H    (*(unsigned char volatile __xdata *)0xff38)
#define     PWM05T1L    (*(unsigned char volatile __xdata *)0xff39)
#define     PWM05T2     (*(unsigned int volatile __xdata *)0xff3a)
#define     PWM05T2H    (*(unsigned char volatile __xdata *)0xff3a)
#define     PWM05T2L    (*(unsigned char volatile __xdata *)0xff3b)
#define     PWM05CR     (*(unsigned char volatile __xdata *)0xff3c)
#define     PWM05HLD    (*(unsigned char volatile __xdata *)0xff3d)
#define     PWM06T1     (*(unsigned int volatile __xdata *)0xff40)
#define     PWM06T1H    (*(unsigned char volatile __xdata *)0xff40)
#define     PWM06T1L    (*(unsigned char volatile __xdata *)0xff41)
#define     PWM06T2     (*(unsigned int volatile __xdata *)0xff42)
#define     PWM06T2H    (*(unsigned char volatile __xdata *)0xff42)
#define     PWM06T2L    (*(unsigned char volatile __xdata *)0xff43)
#define     PWM06CR     (*(unsigned char volatile __xdata *)0xff44)
#define     PWM06HLD    (*(unsigned char volatile __xdata *)0xff45)
#define     PWM07T1     (*(unsigned int volatile __xdata *)0xff48)
#define     PWM07T1H    (*(unsigned char volatile __xdata *)0xff48)
#define     PWM07T1L    (*(unsigned char volatile __xdata *)0xff49)
#define     PWM07T2     (*(unsigned int volatile __xdata *)0xff4a)
#define     PWM07T2H    (*(unsigned char volatile __xdata *)0xff4a)
#define     PWM07T2L    (*(unsigned char volatile __xdata *)0xff4b)
#define     PWM07CR     (*(unsigned char volatile __xdata *)0xff4c)
#define     PWM07HLD    (*(unsigned char volatile __xdata *)0xff4d)
#define     PWM1C       (*(unsigned int volatile __xdata *)0xff50)
#define     PWM1CH      (*(unsigned char volatile __xdata *)0xff50)
#define     PWM1CL      (*(unsigned char volatile __xdata *)0xff51)
#define     PWM1CKS     (*(unsigned char volatile __xdata *)0xff52)
#define     PWM1IF      (*(unsigned char volatile __xdata *)0xff55)
#define     PWM1FDCR    (*(unsigned char volatile __xdata *)0xff56)
#define     PWM10T1     (*(unsigned int volatile __xdata *)0xff60)
#define     PWM10T1H    (*(unsigned char volatile __xdata *)0xff60)
#define     PWM10T1L    (*(unsigned char volatile __xdata *)0xff61)
#define     PWM10T2     (*(unsigned int volatile __xdata *)0xff62)
#define     PWM10T2H    (*(unsigned char volatile __xdata *)0xff62)
#define     PWM10T2L    (*(unsigned char volatile __xdata *)0xff63)
#define     PWM10CR     (*(unsigned char volatile __xdata *)0xff64)
#define     PWM10HLD    (*(unsigned char volatile __xdata *)0xff65)
#define     PWM11T1     (*(unsigned int volatile __xdata *)0xff68)
#define     PWM11T1H    (*(unsigned char volatile __xdata *)0xff68)
#define     PWM11T1L    (*(unsigned char volatile __xdata *)0xff69)
#define     PWM11T2     (*(unsigned int volatile __xdata *)0xff6a)
#define     PWM11T2H    (*(unsigned char volatile __xdata *)0xff6a)
#define     PWM11T2L    (*(unsigned char volatile __xdata *)0xff6b)
#define     PWM11CR     (*(unsigned char volatile __xdata *)0xff6c)
#define     PWM11HLD    (*(unsigned char volatile __xdata *)0xff6d)
#define     PWM12T1     (*(unsigned int volatile __xdata *)0xff70)
#define     PWM12T1H    (*(unsigned char volatile __xdata *)0xff70)
#define     PWM12T1L    (*(unsigned char volatile __xdata *)0xff71)
#define     PWM12T2     (*(unsigned int volatile __xdata *)0xff72)
#define     PWM12T2H    (*(unsigned char volatile __xdata *)0xff72)
#define     PWM12T2L    (*(unsigned char volatile __xdata *)0xff73)
#define     PWM12CR     (*(unsigned char volatile __xdata *)0xff74)
#define     PWM12HLD    (*(unsigned char volatile __xdata *)0xff75)
#define     PWM13T1     (*(unsigned int volatile __xdata *)0xff78)
#define     PWM13T1H    (*(unsigned char volatile __xdata *)0xff78)
#define     PWM13T1L    (*(unsigned char volatile __xdata *)0xff79)
#define     PWM13T2     (*(unsigned int volatile __xdata *)0xff7a)
#define     PWM13T2H    (*(unsigned char volatile __xdata *)0xff7a)
#define     PWM13T2L    (*(unsigned char volatile __xdata *)0xff7b)
#define     PWM13CR     (*(unsigned char volatile __xdata *)0xff7c)
#define     PWM13HLD    (*(unsigned char volatile __xdata *)0xff7d)
#define     PWM14T1     (*(unsigned int volatile __xdata *)0xff80)
#define     PWM14T1H    (*(unsigned char volatile __xdata *)0xff80)
#define     PWM14T1L    (*(unsigned char volatile __xdata *)0xff81)
#define     PWM14T2     (*(unsigned int volatile __xdata *)0xff82)
#define     PWM14T2H    (*(unsigned char volatile __xdata *)0xff82)
#define     PWM14T2L    (*(unsigned char volatile __xdata *)0xff83)
#define     PWM14CR     (*(unsigned char volatile __xdata *)0xff84)
#define     PWM14HLD    (*(unsigned char volatile __xdata *)0xff85)
#define     PWM15T1     (*(unsigned int volatile __xdata *)0xff88)
#define     PWM15T1H    (*(unsigned char volatile __xdata *)0xff88)
#define     PWM15T1L    (*(unsigned char volatile __xdata *)0xff89)
#define     PWM15T2     (*(unsigned int volatile __xdata *)0xff8a)
#define     PWM15T2H    (*(unsigned char volatile __xdata *)0xff8a)
#define     PWM15T2L    (*(unsigned char volatile __xdata *)0xff8b)
#define     PWM15CR     (*(unsigned char volatile __xdata *)0xff8c)
#define     PWM15HLD    (*(unsigned char volatile __xdata *)0xff8d)
#define     PWM16T1     (*(unsigned int volatile __xdata *)0xff90)
#define     PWM16T1H    (*(unsigned char volatile __xdata *)0xff90)
#define     PWM16T1L    (*(unsigned char volatile __xdata *)0xff91)
#define     PWM16T2     (*(unsigned int volatile __xdata *)0xff92)
#define     PWM16T2H    (*(unsigned char volatile __xdata *)0xff92)
#define     PWM16T2L    (*(unsigned char volatile __xdata *)0xff93)
#define     PWM16CR     (*(unsigned char volatile __xdata *)0xff94)
#define     PWM16HLD    (*(unsigned char volatile __xdata *)0xff95)
#define     PWM17T1     (*(unsigned int volatile __xdata *)0xff98)
#define     PWM17T1H    (*(unsigned char volatile __xdata *)0xff98)
#define     PWM17T1L    (*(unsigned char volatile __xdata *)0xff99)
#define     PWM17T2     (*(unsigned int volatile __xdata *)0xff9a)
#define     PWM17T2H    (*(unsigned char volatile __xdata *)0xff9a)
#define     PWM17T2L    (*(unsigned char volatile __xdata *)0xff9b)
#define     PWM17CR     (*(unsigned char volatile __xdata *)0xff9c)
#define     PWM17HLD    (*(unsigned char volatile __xdata *)0xff9d)
#define     PWM2C       (*(unsigned int volatile __xdata *)0xffa0)
#define     PWM2CH      (*(unsigned char volatile __xdata *)0xffa0)
#define     PWM2CL      (*(unsigned char volatile __xdata *)0xffa1)
#define     PWM2CKS     (*(unsigned char volatile __xdata *)0xffa2)
#define     PWM2TADC    (*(unsigned int volatile __xdata *)0xffa3)
#define     PWM2TADCH   (*(unsigned char volatile __xdata *)0xffa3)
#define     PWM2TADCL   (*(unsigned char volatile __xdata *)0xffa4)
#define     PWM2IF      (*(unsigned char volatile __xdata *)0xffa5)
#define     PWM2FDCR    (*(unsigned char volatile __xdata *)0xffa6)
#define     PWM20T1     (*(unsigned int volatile __xdata *)0xffb0)
#define     PWM20T1H    (*(unsigned char volatile __xdata *)0xffb0)
#define     PWM20T1L    (*(unsigned char volatile __xdata *)0xffb1)
#define     PWM20T2     (*(unsigned int volatile __xdata *)0xffb2)
#define     PWM20T2H    (*(unsigned char volatile __xdata *)0xffb2)
#define     PWM20T2L    (*(unsigned char volatile __xdata *)0xffb3)
#define     PWM20CR     (*(unsigned char volatile __xdata *)0xffb4)
#define     PWM20HLD    (*(unsigned char volatile __xdata *)0xffb5)
#define     PWM21T1     (*(unsigned int volatile __xdata *)0xffb8)
#define     PWM21T1H    (*(unsigned char volatile __xdata *)0xffb8)
#define     PWM21T1L    (*(unsigned char volatile __xdata *)0xffb9)
#define     PWM21T2     (*(unsigned int volatile __xdata *)0xffba)
#define     PWM21T2H    (*(unsigned char volatile __xdata *)0xffba)
#define     PWM21T2L    (*(unsigned char volatile __xdata *)0xffbb)
#define     PWM21CR     (*(unsigned char volatile __xdata *)0xffbc)
#define     PWM21HLD    (*(unsigned char volatile __xdata *)0xffbd)
#define     PWM22T1     (*(unsigned int volatile __xdata *)0xffc0)
#define     PWM22T1H    (*(unsigned char volatile __xdata *)0xffc0)
#define     PWM22T1L    (*(unsigned char volatile __xdata *)0xffc1)
#define     PWM22T2     (*(unsigned int volatile __xdata *)0xffc2)
#define     PWM22T2H    (*(unsigned char volatile __xdata *)0xffc2)
#define     PWM22T2L    (*(unsigned char volatile __xdata *)0xffc3)
#define     PWM22CR     (*(unsigned char volatile __xdata *)0xffc4)
#define     PWM22HLD    (*(unsigned char volatile __xdata *)0xffc5)
#define     PWM23T1     (*(unsigned int volatile __xdata *)0xffc8)
#define     PWM23T1H    (*(unsigned char volatile __xdata *)0xffc8)
#define     PWM23T1L    (*(unsigned char volatile __xdata *)0xffc9)
#define     PWM23T2     (*(unsigned int volatile __xdata *)0xffca)
#define     PWM23T2H    (*(unsigned char volatile __xdata *)0xffca)
#define     PWM23T2L    (*(unsigned char volatile __xdata *)0xffcb)
#define     PWM23CR     (*(unsigned char volatile __xdata *)0xffcc)
#define     PWM23HLD    (*(unsigned char volatile __xdata *)0xffcd)
#define     PWM24T1     (*(unsigned int volatile __xdata *)0xffd0)
#define     PWM24T1H    (*(unsigned char volatile __xdata *)0xffd0)
#define     PWM24T1L    (*(unsigned char volatile __xdata *)0xffd1)
#define     PWM24T2     (*(unsigned int volatile __xdata *)0xffd2)
#define     PWM24T2H    (*(unsigned char volatile __xdata *)0xffd2)
#define     PWM24T2L    (*(unsigned char volatile __xdata *)0xffd3)
#define     PWM24CR     (*(unsigned char volatile __xdata *)0xffd4)
#define     PWM24HLD    (*(unsigned char volatile __xdata *)0xffd5)
#define     PWM25T1     (*(unsigned int volatile __xdata *)0xffd8)
#define     PWM25T1H    (*(unsigned char volatile __xdata *)0xffd8)
#define     PWM25T1L    (*(unsigned char volatile __xdata *)0xffd9)
#define     PWM25T2     (*(unsigned int volatile __xdata *)0xffda)
#define     PWM25T2H    (*(unsigned char volatile __xdata *)0xffda)
#define     PWM25T2L    (*(unsigned char volatile __xdata *)0xffdb)
#define     PWM25CR     (*(unsigned char volatile __xdata *)0xffdc)
#define     PWM25HLD    (*(unsigned char volatile __xdata *)0xffdd)
#define     PWM26T1     (*(unsigned int volatile __xdata *)0xffe0)
#define     PWM26T1H    (*(unsigned char volatile __xdata *)0xffe0)
#define     PWM26T1L    (*(unsigned char volatile __xdata *)0xffe1)
#define     PWM26T2     (*(unsigned int volatile __xdata *)0xffe2)
#define     PWM26T2H    (*(unsigned char volatile __xdata *)0xffe2)
#define     PWM26T2L    (*(unsigned char volatile __xdata *)0xffe3)
#define     PWM26CR     (*(unsigned char volatile __xdata *)0xffe4)
#define     PWM26HLD    (*(unsigned char volatile __xdata *)0xffe5)
#define     PWM27T1     (*(unsigned int volatile __xdata *)0xffe8)
#define     PWM27T1H    (*(unsigned char volatile __xdata *)0xffe8)
#define     PWM27T1L    (*(unsigned char volatile __xdata *)0xffe9)
#define     PWM27T2     (*(unsigned int volatile __xdata *)0xffea)
#define     PWM27T2H    (*(unsigned char volatile __xdata *)0xffea)
#define     PWM27T2L    (*(unsigned char volatile __xdata *)0xffeb)
#define     PWM27CR     (*(unsigned char volatile __xdata *)0xffec)
#define     PWM27HLD    (*(unsigned char volatile __xdata *)0xffed)

/////////////////////////////////////////////////
//FC00H-FCFFH
/////////////////////////////////////////////////

#define     PWM3C       (*(unsigned int volatile __xdata *)0xfc00)
#define     PWM3CH      (*(unsigned char volatile __xdata *)0xfc00)
#define     PWM3CL      (*(unsigned char volatile __xdata *)0xfc01)
#define     PWM3CKS     (*(unsigned char volatile __xdata *)0xfc02)
#define     PWM3IF      (*(unsigned char volatile __xdata *)0xfc05)
#define     PWM3FDCR    (*(unsigned char volatile __xdata *)0xfc06)
#define     PWM30T1     (*(unsigned int volatile __xdata *)0xfc10)
#define     PWM30T1H    (*(unsigned char volatile __xdata *)0xfc10)
#define     PWM30T1L    (*(unsigned char volatile __xdata *)0xfc11)
#define     PWM30T2     (*(unsigned int volatile __xdata *)0xfc12)
#define     PWM30T2H    (*(unsigned char volatile __xdata *)0xfc12)
#define     PWM30T2L    (*(unsigned char volatile __xdata *)0xfc13)
#define     PWM30CR     (*(unsigned char volatile __xdata *)0xfc14)
#define     PWM30HLD    (*(unsigned char volatile __xdata *)0xfc15)
#define     PWM31T1     (*(unsigned int volatile __xdata *)0xfc18)
#define     PWM31T1H    (*(unsigned char volatile __xdata *)0xfc18)
#define     PWM31T1L    (*(unsigned char volatile __xdata *)0xfc19)
#define     PWM31T2     (*(unsigned int volatile __xdata *)0xfc1a)
#define     PWM31T2H    (*(unsigned char volatile __xdata *)0xfc1a)
#define     PWM31T2L    (*(unsigned char volatile __xdata *)0xfc1b)
#define     PWM31CR     (*(unsigned char volatile __xdata *)0xfc1c)
#define     PWM31HLD    (*(unsigned char volatile __xdata *)0xfc1d)
#define     PWM32T1     (*(unsigned int volatile __xdata *)0xfc20)
#define     PWM32T1H    (*(unsigned char volatile __xdata *)0xfc20)
#define     PWM32T1L    (*(unsigned char volatile __xdata *)0xfc21)
#define     PWM32T2     (*(unsigned int volatile __xdata *)0xfc22)
#define     PWM32T2H    (*(unsigned char volatile __xdata *)0xfc22)
#define     PWM32T2L    (*(unsigned char volatile __xdata *)0xfc23)
#define     PWM32CR     (*(unsigned char volatile __xdata *)0xfc24)
#define     PWM32HLD    (*(unsigned char volatile __xdata *)0xfc25)
#define     PWM33T1     (*(unsigned int volatile __xdata *)0xfc28)
#define     PWM33T1H    (*(unsigned char volatile __xdata *)0xfc28)
#define     PWM33T1L    (*(unsigned char volatile __xdata *)0xfc29)
#define     PWM33T2     (*(unsigned int volatile __xdata *)0xfc2a)
#define     PWM33T2H    (*(unsigned char volatile __xdata *)0xfc2a)
#define     PWM33T2L    (*(unsigned char volatile __xdata *)0xfc2b)
#define     PWM33CR     (*(unsigned char volatile __xdata *)0xfc2c)
#define     PWM33HLD    (*(unsigned char volatile __xdata *)0xfc2d)
#define     PWM34T1     (*(unsigned int volatile __xdata *)0xfc30)
#define     PWM34T1H    (*(unsigned char volatile __xdata *)0xfc30)
#define     PWM34T1L    (*(unsigned char volatile __xdata *)0xfc31)
#define     PWM34T2     (*(unsigned int volatile __xdata *)0xfc32)
#define     PWM34T2H    (*(unsigned char volatile __xdata *)0xfc32)
#define     PWM34T2L    (*(unsigned char volatile __xdata *)0xfc33)
#define     PWM34CR     (*(unsigned char volatile __xdata *)0xfc34)
#define     PWM34HLD    (*(unsigned char volatile __xdata *)0xfc35)
#define     PWM35T1     (*(unsigned int volatile __xdata *)0xfc38)
#define     PWM35T1H    (*(unsigned char volatile __xdata *)0xfc38)
#define     PWM35T1L    (*(unsigned char volatile __xdata *)0xfc39)
#define     PWM35T2     (*(unsigned int volatile __xdata *)0xfc3a)
#define     PWM35T2H    (*(unsigned char volatile __xdata *)0xfc3a)
#define     PWM35T2L    (*(unsigned char volatile __xdata *)0xfc3b)
#define     PWM35CR     (*(unsigned char volatile __xdata *)0xfc3c)
#define     PWM35HLD    (*(unsigned char volatile __xdata *)0xfc3d)
#define     PWM36T1     (*(unsigned int volatile __xdata *)0xfc40)
#define     PWM36T1H    (*(unsigned char volatile __xdata *)0xfc40)
#define     PWM36T1L    (*(unsigned char volatile __xdata *)0xfc41)
#define     PWM36T2     (*(unsigned int volatile __xdata *)0xfc42)
#define     PWM36T2H    (*(unsigned char volatile __xdata *)0xfc42)
#define     PWM36T2L    (*(unsigned char volatile __xdata *)0xfc43)
#define     PWM36CR     (*(unsigned char volatile __xdata *)0xfc44)
#define     PWM36HLD    (*(unsigned char volatile __xdata *)0xfc45)
#define     PWM37T1     (*(unsigned int volatile __xdata *)0xfc48)
#define     PWM37T1H    (*(unsigned char volatile __xdata *)0xfc48)
#define     PWM37T1L    (*(unsigned char volatile __xdata *)0xfc49)
#define     PWM37T2     (*(unsigned int volatile __xdata *)0xfc4a)
#define     PWM37T2H    (*(unsigned char volatile __xdata *)0xfc4a)
#define     PWM37T2L    (*(unsigned char volatile __xdata *)0xfc4b)
#define     PWM37CR     (*(unsigned char volatile __xdata *)0xfc4c)
#define     PWM37HLD    (*(unsigned char volatile __xdata *)0xfc4d)
#define     PWM4C       (*(unsigned int volatile __xdata *)0xfc50)
#define     PWM4CH      (*(unsigned char volatile __xdata *)0xfc50)
#define     PWM4CL      (*(unsigned char volatile __xdata *)0xfc51)
#define     PWM4CKS     (*(unsigned char volatile __xdata *)0xfc52)
#define     PWM4TADC    (*(unsigned int volatile __xdata *)0xfc53)
#define     PWM4TADCH   (*(unsigned char volatile __xdata *)0xfc53)
#define     PWM4TADCL   (*(unsigned char volatile __xdata *)0xfc54)
#define     PWM4IF      (*(unsigned char volatile __xdata *)0xfc55)
#define     PWM4FDCR    (*(unsigned char volatile __xdata *)0xfc56)
#define     PWM40T1     (*(unsigned int volatile __xdata *)0xfc60)
#define     PWM40T1H    (*(unsigned char volatile __xdata *)0xfc60)
#define     PWM40T1L    (*(unsigned char volatile __xdata *)0xfc61)
#define     PWM40T2     (*(unsigned int volatile __xdata *)0xfc62)
#define     PWM40T2H    (*(unsigned char volatile __xdata *)0xfc62)
#define     PWM40T2L    (*(unsigned char volatile __xdata *)0xfc63)
#define     PWM40CR     (*(unsigned char volatile __xdata *)0xfc64)
#define     PWM40HLD    (*(unsigned char volatile __xdata *)0xfc65)
#define     PWM41T1     (*(unsigned int volatile __xdata *)0xfc68)
#define     PWM41T1H    (*(unsigned char volatile __xdata *)0xfc68)
#define     PWM41T1L    (*(unsigned char volatile __xdata *)0xfc69)
#define     PWM41T2     (*(unsigned int volatile __xdata *)0xfc6a)
#define     PWM41T2H    (*(unsigned char volatile __xdata *)0xfc6a)
#define     PWM41T2L    (*(unsigned char volatile __xdata *)0xfc6b)
#define     PWM41CR     (*(unsigned char volatile __xdata *)0xfc6c)
#define     PWM41HLD    (*(unsigned char volatile __xdata *)0xfc6d)
#define     PWM42T1     (*(unsigned int volatile __xdata *)0xfc70)
#define     PWM42T1H    (*(unsigned char volatile __xdata *)0xfc70)
#define     PWM42T1L    (*(unsigned char volatile __xdata *)0xfc71)
#define     PWM42T2     (*(unsigned int volatile __xdata *)0xfc72)
#define     PWM42T2H    (*(unsigned char volatile __xdata *)0xfc72)
#define     PWM42T2L    (*(unsigned char volatile __xdata *)0xfc73)
#define     PWM42CR     (*(unsigned char volatile __xdata *)0xfc74)
#define     PWM42HLD    (*(unsigned char volatile __xdata *)0xfc75)
#define     PWM43T1     (*(unsigned int volatile __xdata *)0xfc78)
#define     PWM43T1H    (*(unsigned char volatile __xdata *)0xfc78)
#define     PWM43T1L    (*(unsigned char volatile __xdata *)0xfc79)
#define     PWM43T2     (*(unsigned int volatile __xdata *)0xfc7a)
#define     PWM43T2H    (*(unsigned char volatile __xdata *)0xfc7a)
#define     PWM43T2L    (*(unsigned char volatile __xdata *)0xfc7b)
#define     PWM43CR     (*(unsigned char volatile __xdata *)0xfc7c)
#define     PWM43HLD    (*(unsigned char volatile __xdata *)0xfc7d)
#define     PWM44T1     (*(unsigned int volatile __xdata *)0xfc80)
#define     PWM44T1H    (*(unsigned char volatile __xdata *)0xfc80)
#define     PWM44T1L    (*(unsigned char volatile __xdata *)0xfc81)
#define     PWM44T2     (*(unsigned int volatile __xdata *)0xfc82)
#define     PWM44T2H    (*(unsigned char volatile __xdata *)0xfc82)
#define     PWM44T2L    (*(unsigned char volatile __xdata *)0xfc83)
#define     PWM44CR     (*(unsigned char volatile __xdata *)0xfc84)
#define     PWM44HLD    (*(unsigned char volatile __xdata *)0xfc85)
#define     PWM45T1     (*(unsigned int volatile __xdata *)0xfc88)
#define     PWM45T1H    (*(unsigned char volatile __xdata *)0xfc88)
#define     PWM45T1L    (*(unsigned char volatile __xdata *)0xfc89)
#define     PWM45T2     (*(unsigned int volatile __xdata *)0xfc8a)
#define     PWM45T2H    (*(unsigned char volatile __xdata *)0xfc8a)
#define     PWM45T2L    (*(unsigned char volatile __xdata *)0xfc8b)
#define     PWM45CR     (*(unsigned char volatile __xdata *)0xfc8c)
#define     PWM45HLD    (*(unsigned char volatile __xdata *)0xfc8d)
#define     PWM46T1     (*(unsigned int volatile __xdata *)0xfc90)
#define     PWM46T1H    (*(unsigned char volatile __xdata *)0xfc90)
#define     PWM46T1L    (*(unsigned char volatile __xdata *)0xfc91)
#define     PWM46T2     (*(unsigned int volatile __xdata *)0xfc92)
#define     PWM46T2H    (*(unsigned char volatile __xdata *)0xfc92)
#define     PWM46T2L    (*(unsigned char volatile __xdata *)0xfc93)
#define     PWM46CR     (*(unsigned char volatile __xdata *)0xfc94)
#define     PWM46HLD    (*(unsigned char volatile __xdata *)0xfc95)
#define     PWM47T1     (*(unsigned int volatile __xdata *)0xfc98)
#define     PWM47T1H    (*(unsigned char volatile __xdata *)0xfc98)
#define     PWM47T1L    (*(unsigned char volatile __xdata *)0xfc99)
#define     PWM47T2     (*(unsigned int volatile __xdata *)0xfc9a)
#define     PWM47T2H    (*(unsigned char volatile __xdata *)0xfc9a)
#define     PWM47T2L    (*(unsigned char volatile __xdata *)0xfc9b)
#define     PWM47CR     (*(unsigned char volatile __xdata *)0xfc9c)
#define     PWM47HLD    (*(unsigned char volatile __xdata *)0xfc9d)
#define     PWM5C       (*(unsigned int volatile __xdata *)0xfca0)
#define     PWM5CH      (*(unsigned char volatile __xdata *)0xfca0)
#define     PWM5CL      (*(unsigned char volatile __xdata *)0xfca1)
#define     PWM5CKS     (*(unsigned char volatile __xdata *)0xfca2)
#define     PWM5IF      (*(unsigned char volatile __xdata *)0xfca5)
#define     PWM5FDCR    (*(unsigned char volatile __xdata *)0xfca6)
#define     PWM50T1     (*(unsigned int volatile __xdata *)0xfcb0)
#define     PWM50T1H    (*(unsigned char volatile __xdata *)0xfcb0)
#define     PWM50T1L    (*(unsigned char volatile __xdata *)0xfcb1)
#define     PWM50T2     (*(unsigned int volatile __xdata *)0xfcb2)
#define     PWM50T2H    (*(unsigned char volatile __xdata *)0xfcb2)
#define     PWM50T2L    (*(unsigned char volatile __xdata *)0xfcb3)
#define     PWM50CR     (*(unsigned char volatile __xdata *)0xfcb4)
#define     PWM50HLD    (*(unsigned char volatile __xdata *)0xfcb5)
#define     PWM51T1     (*(unsigned int volatile __xdata *)0xfcb8)
#define     PWM51T1H    (*(unsigned char volatile __xdata *)0xfcb8)
#define     PWM51T1L    (*(unsigned char volatile __xdata *)0xfcb9)
#define     PWM51T2     (*(unsigned int volatile __xdata *)0xfcba)
#define     PWM51T2H    (*(unsigned char volatile __xdata *)0xfcba)
#define     PWM51T2L    (*(unsigned char volatile __xdata *)0xfcbb)
#define     PWM51CR     (*(unsigned char volatile __xdata *)0xfcbc)
#define     PWM51HLD    (*(unsigned char volatile __xdata *)0xfcbd)
#define     PWM52T1     (*(unsigned int volatile __xdata *)0xfcc0)
#define     PWM52T1H    (*(unsigned char volatile __xdata *)0xfcc0)
#define     PWM52T1L    (*(unsigned char volatile __xdata *)0xfcc1)
#define     PWM52T2     (*(unsigned int volatile __xdata *)0xfcc2)
#define     PWM52T2H    (*(unsigned char volatile __xdata *)0xfcc2)
#define     PWM52T2L    (*(unsigned char volatile __xdata *)0xfcc3)
#define     PWM52CR     (*(unsigned char volatile __xdata *)0xfcc4)
#define     PWM52HLD    (*(unsigned char volatile __xdata *)0xfcc5)
#define     PWM53T1     (*(unsigned int volatile __xdata *)0xfcc8)
#define     PWM53T1H    (*(unsigned char volatile __xdata *)0xfcc8)
#define     PWM53T1L    (*(unsigned char volatile __xdata *)0xfcc9)
#define     PWM53T2     (*(unsigned int volatile __xdata *)0xfcca)
#define     PWM53T2H    (*(unsigned char volatile __xdata *)0xfcca)
#define     PWM53T2L    (*(unsigned char volatile __xdata *)0xfccb)
#define     PWM53CR     (*(unsigned char volatile __xdata *)0xfccc)
#define     PWM53HLD    (*(unsigned char volatile __xdata *)0xfccd)
#define     PWM54T1     (*(unsigned int volatile __xdata *)0xfcd0)
#define     PWM54T1H    (*(unsigned char volatile __xdata *)0xfcd0)
#define     PWM54T1L    (*(unsigned char volatile __xdata *)0xfcd1)
#define     PWM54T2     (*(unsigned int volatile __xdata *)0xfcd2)
#define     PWM54T2H    (*(unsigned char volatile __xdata *)0xfcd2)
#define     PWM54T2L    (*(unsigned char volatile __xdata *)0xfcd3)
#define     PWM54CR     (*(unsigned char volatile __xdata *)0xfcd4)
#define     PWM54HLD    (*(unsigned char volatile __xdata *)0xfcd5)
#define     PWM55T1     (*(unsigned int volatile __xdata *)0xfcd8)
#define     PWM55T1H    (*(unsigned char volatile __xdata *)0xfcd8)
#define     PWM55T1L    (*(unsigned char volatile __xdata *)0xfcd9)
#define     PWM55T2     (*(unsigned int volatile __xdata *)0xfcda)
#define     PWM55T2H    (*(unsigned char volatile __xdata *)0xfcda)
#define     PWM55T2L    (*(unsigned char volatile __xdata *)0xfcdb)
#define     PWM55CR     (*(unsigned char volatile __xdata *)0xfcdc)
#define     PWM55HLD    (*(unsigned char volatile __xdata *)0xfcdd)
#define     PWM56T1     (*(unsigned int volatile __xdata *)0xfce0)
#define     PWM56T1H    (*(unsigned char volatile __xdata *)0xfce0)
#define     PWM56T1L    (*(unsigned char volatile __xdata *)0xfce1)
#define     PWM56T2     (*(unsigned int volatile __xdata *)0xfce2)
#define     PWM56T2H    (*(unsigned char volatile __xdata *)0xfce2)
#define     PWM56T2L    (*(unsigned char volatile __xdata *)0xfce3)
#define     PWM56CR     (*(unsigned char volatile __xdata *)0xfce4)
#define     PWM56HLD    (*(unsigned char volatile __xdata *)0xfce5)
#define     PWM57T1     (*(unsigned int volatile __xdata *)0xfce8)
#define     PWM57T1H    (*(unsigned char volatile __xdata *)0xfce8)
#define     PWM57T1L    (*(unsigned char volatile __xdata *)0xfce9)
#define     PWM57T2     (*(unsigned int volatile __xdata *)0xfcea)
#define     PWM57T2H    (*(unsigned char volatile __xdata *)0xfcea)
#define     PWM57T2L    (*(unsigned char volatile __xdata *)0xfceb)
#define     PWM57CR     (*(unsigned char volatile __xdata *)0xfcec)
#define     PWM57HLD    (*(unsigned char volatile __xdata *)0xfced)


//						             7      6      5      4      3      2      1      0     Reset Value
//sfr PWMSET = 0xF1H; ENGLBSET PWMRST ENPWM5 ENPWM4 ENPWM3 ENPWM2 ENPWM1 ENPWM0 0000,0000 /* Enhanced PWM global configuration register */ 
#define PWM15_SET_Uniform()				PWMSET |= 0x80		//1: 6 groups of PWM adopt a unified setting method
#define PWM15_SET_Independent()		PWMSET &= ~0x80		//0: 6 groups of PWM adopt independent setting methods

#define PWM15_Reset()							PWMSET |= 0x40		//1: Reset all PWM XFR registers, SFR remains unchanged

#define PWM15_PWM5_Enable()				PWMSET |= 0x20		//1: Enable PWM5 (including PWM50~PWM54).
#define PWM15_PWM5_Disable()			PWMSET &= ~0x20		//0: Disable PWM5

#define PWM15_PWM4_Enable()				PWMSET |= 0x10		//1: Enable PWM4 (including PWM40~PWM47).
#define PWM15_PWM4_Disable()			PWMSET &= ~0x10		//0: Disable PWM4

#define PWM15_PWM3_Enable()				PWMSET |= 0x08		//1: Enable PWM3 (including PWM30~PWM37).
#define PWM15_PWM3_Disable()			PWMSET &= ~0x08		//0: Disable PWM3

#define PWM15_PWM2_Enable()				PWMSET |= 0x04		//1: Enable PWM2 (including PWM20~PWM27).
#define PWM15_PWM2_Disable()			PWMSET &= ~0x04		//0: Disable PWM2

#define PWM15_PWM1_Enable()				PWMSET |= 0x02		//1: Enable PWM1 (including PWM10~PWM17).
#define PWM15_PWM1_Disable()			PWMSET &= ~0x02		//0: Disable PWM1

#define PWM15_PWM0_Enable()				PWMSET |= 0x01		//1: Enable PWM0 (including PWM00~PWM07).
#define PWM15_PWM0_Disable()			PWMSET &= ~0x01		//0: Disable PWM0

//						              7       6       5       4       3        2        1        0     Reset Value
//sfr PWMCFG01= 0xF6H; PWM1CBIF EPWM1CBI FLTPS0 PWM1CEN PWM0CBIF EPWM0CBI ENPWM0TA PWM0CEN 0000,0000 /* Enhanced PWM configuration register */ 
//sfr PWMCFG23= 0xF7H; PWM3CBIF EPWM3CBI FLTPS1 PWM3CEN PWM2CBIF EPWM2CBI ENPWM2TA PWM2CEN 0000,0000 /* Enhanced PWM configuration register */ 
//sfr PWMCFG45= 0xFEH; PWM5CBIF EPWM5CBI FLTPS2 PWM5CEN PWM4CBIF EPWM4CBI ENPWM4TA PWM4CEN 0000,0000 /* Enhanced PWM configuration register */ 
#define		PWM1CBIF			0x80
#define		PWM0CBIF			0x08
#define		FLTPSn				0x20

#define PWM15_Counter1Int_Enable()		PWMCFG01 |= 0x40		//1: Enable counter zero interrupt
#define PWM15_Counter1Int_Disable()		PWMCFG01 &= ~0x40		//0: Disable counter zero interrupt
#define PWM15_Counter1_Enable()				PWMCFG01 |= 0x10		//1: Enable counter
#define PWM15_Counter1_Disable()			PWMCFG01 &= ~0x10		//0: Disable the counter
#define PWM15_Counter0Int_Enable()		PWMCFG01 |= 0x04		//1: Enable counter zero interrupt
#define PWM15_Counter0Int_Disable()		PWMCFG01 &= ~0x04		//0: Disable counter zero interrupt
#define PWM15_Counter0_Enable()				PWMCFG01 |= 0x01		//1: Enable counter
#define PWM15_Counter0_Disable()			PWMCFG01 &= ~0x01		//0: Disable the counter
#define PWM15_PWM0_ADC_Enable()				PWMCFG01 |= 0x02		//1: PWM is associated with ADC
#define PWM15_PWM0_ADC_Disable()			PWMCFG01 &= ~0x02		//0: PWM is not related to ADC

#define PWM15_Counter3Int_Enable()		PWMCFG23 |= 0x40		//1: Enable counter zero interrupt
#define PWM15_Counter3Int_Disable()		PWMCFG23 &= ~0x40		//0: Disable counter zero interrupt
#define PWM15_Counter3_Enable()				PWMCFG23 |= 0x10		//1: Enable counter
#define PWM15_Counter3_Disable()			PWMCFG23 &= ~0x10		//0: Disable the counter
#define PWM15_Counter2Int_Enable()		PWMCFG23 |= 0x04		//1: Enable counter zero interrupt
#define PWM15_Counter2Int_Disable()		PWMCFG23 &= ~0x04		//0: Disable counter zero interrupt
#define PWM15_Counter2_Enable()				PWMCFG23 |= 0x01		//1: Enable counter
#define PWM15_Counter2_Disable()			PWMCFG23 &= ~0x01		//0: Disable the counter
#define PWM15_PWM2_ADC_Enable()				PWMCFG23 |= 0x02		//1: PWM is associated with ADC
#define PWM15_PWM2_ADC_Disable()			PWMCFG23 &= ~0x02		//0: PWM is not related to ADC

#define PWM15_Counter5Int_Enable()		PWMCFG45 |= 0x40		//1: Enable counter zero interrupt
#define PWM15_Counter5Int_Disable()		PWMCFG45 &= ~0x40		//0: Disable counter zero interrupt
#define PWM15_Counter5_Enable()				PWMCFG45 |= 0x10		//1: Enable counter
#define PWM15_Counter5_Disable()			PWMCFG45 &= ~0x10		//0: Disable the counter
#define PWM15_Counter4Int_Enable()		PWMCFG45 |= 0x04		//1: Enable counter zero interrupt
#define PWM15_Counter4Int_Disable()		PWMCFG45 &= ~0x04		//0: Disable counter zero interrupt
#define PWM15_Counter4_Enable()				PWMCFG45 |= 0x01		//1: Enable counter
#define PWM15_Counter4_Disable()			PWMCFG45 &= ~0x01		//0: Disable the counter
#define PWM15_PWM4_ADC_Enable()				PWMCFG45 |= 0x02		//1: PWM is associated with ADC
#define PWM15_PWM4_ADC_Disable()			PWMCFG45 &= ~0x02		//0: PWM is not related to ADC

/*  PWMnIF  */
#define		C7IF   = (1<<7)
#define		C6IF   = (1<<6)
#define		C5IF   = (1<<5)
#define		C4IF   = (1<<4)
#define		C3IF   = (1<<3)
#define		C2IF   = (1<<2)
#define		C1IF   = (1<<1)
#define		C0IF   = 1

/*  PWMnFDCR  */
#define		INVCMP   = (1<<7)
#define		INVIO    = (1<<6)
#define		ENFD     = (1<<5)
#define		FLTFLIO  = (1<<4)
#define		EFDI     = (1<<3)
#define		FDCMP    = (1<<2)
#define		FDIO     = (1<<1)
#define		FDIF     = 1

//						             7  6  5     4      3      2      1      0     Reset Value
//sfr PWM0CKS = 0xFF02H; - - - SELT2 PWM_PS[3:0] xxx0,0000 /* Enhanced PWM clock selection register */ 
//sfr PWM1CKS = 0xFF52H; - - - SELT2 PWM_PS[3:0] xxx0,0000 /* Enhanced PWM clock selection register */ 
//sfr PWM2CKS = 0xFFA2H; - - - SELT2 PWM_PS[3:0] xxx0,0000 /* Enhanced PWM clock selection register */ 
//sfr PWM3CKS = 0xFC02H; - - - SELT2 PWM_PS[3:0] xxx0,0000 /* Enhanced PWM clock selection register */ 
//sfr PWM4CKS = 0xFC52H; - - - SELT2 PWM_PS[3:0] xxx0,0000 /* Enhanced PWM clock selection register */ 
//sfr PWM5CKS = 0xFCA2H; - - - SELT2 PWM_PS[3:0] xxx0,0000 /* Enhanced PWM clock selection register */ 
#define PWM0_PS_Clock()				PWM0CKS &= ~0x10		//0: The PWMn clock source is the divided clock of the system clock.
#define PWM0_T2_Clock()				PWM0CKS |= 0x10			//1: The PWMn clock source is the overflow pulse of timer 2
#define PWM0_PS_Set(n)				PWM0CKS = (PWM0CKS & ~0x0F) | (n & 0x0F)		//System clock prescaler parameter setting: SYSclk / (PWM_PS+1)
#define PWM1_PS_Clock()				PWM1CKS &= ~0x10		//0: The PWMn clock source is the divided clock of the system clock.
#define PWM1_T2_Clock()				PWM1CKS |= 0x10			//1: The PWMn clock source is the overflow pulse of timer 2
#define PWM1_PS_Set(n)				PWM1CKS = (PWM1CKS & ~0x0F) | (n & 0x0F)		//System clock prescaler parameter setting: SYSclk / (PWM_PS+1)
#define PWM2_PS_Clock()				PWM2CKS &= ~0x10		//0: The PWMn clock source is the divided clock of the system clock.
#define PWM2_T2_Clock()				PWM2CKS |= 0x10			//1: The PWMn clock source is the overflow pulse of timer 2
#define PWM2_PS_Set(n)				PWM2CKS = (PWM2CKS & ~0x0F) | (n & 0x0F)		//System clock prescaler parameter setting: SYSclk / (PWM_PS+1)
#define PWM3_PS_Clock()				PWM3CKS &= ~0x10		//0: The PWMn clock source is the divided clock of the system clock.
#define PWM3_T2_Clock()				PWM3CKS |= 0x10			//1: The PWMn clock source is the overflow pulse of timer 2
#define PWM3_PS_Set(n)				PWM3CKS = (PWM3CKS & ~0x0F) | (n & 0x0F)		//System clock prescaler parameter setting: SYSclk / (PWM_PS+1)
#define PWM4_PS_Clock()				PWM4CKS &= ~0x10		//0: The PWMn clock source is the divided clock of the system clock.
#define PWM4_T2_Clock()				PWM4CKS |= 0x10			//1: The PWMn clock source is the overflow pulse of timer 2
#define PWM4_PS_Set(n)				PWM4CKS = (PWM4CKS & ~0x0F) | (n & 0x0F)		//System clock prescaler parameter setting: SYSclk / (PWM_PS+1)
#define PWM5_PS_Clock()				PWM5CKS &= ~0x10		//0: The PWMn clock source is the divided clock of the system clock.
#define PWM5_T2_Clock()				PWM5CKS |= 0x10			//1: The PWMn clock source is the overflow pulse of timer 2
#define PWM5_PS_Set(n)				PWM5CKS = (PWM5CKS & ~0x0F) | (n & 0x0F)		//System clock prescaler parameter setting: SYSclk / (PWM_PS+1)

/*  PWMnTADC  */
#define PWM15_PWM0TADC(n)			PWM0TADC = (n & 0x7fff)		//PWM ADC trigger point
#define PWM15_PWM2TADC(n)			PWM2TADC = (n & 0x7fff)		//PWM ADC trigger point
#define PWM15_PWM4TADC(n)			PWM4TADC = (n & 0x7fff)		//PWM ADC trigger point

/*  PWMnTADC  */
#define PWM15_PWM0TADC(n)			PWM0TADC = (n & 0x7fff)		//PWM ADC trigger point


/*  BIT Registers  */
/*  PSW   */
__sbit __at(0xD7) CY;
__sbit __at(0xD6) AC;
__sbit __at(0xD5) F0;
__sbit __at(0xD4) RS1;
__sbit __at(0xD3) RS0;
__sbit __at(0xD2) OV;
__sbit __at(0xD1) F1;
__sbit __at(0xD0) P;

/*  TCON  */
__sbit __at(0x8F) TF1;	//Timer 1 overflow interrupt flag bit
__sbit __at(0x8E) TR1;	//Timer 1 run control bit
__sbit __at(0x8D) TF0;	//Timer 0 overflow interrupt flag bit
__sbit __at(0x8C) TR0;	//Timer 0 operation control bit
__sbit __at(0x8B) IE1;	//External interrupt 1 flag
__sbit __at(0x8A) IT1;	//External interrupt 1 signal mode control bit, 1: Interrupt on falling edge, 0: Interrupt on both rising and falling edges.
__sbit __at(0x89) IE0;	//External interrupt 0 flag
__sbit __at(0x88) IT0;	//External interrupt 0 signal mode control bit, 1: falling edge interrupt, 0: rising and falling interrupt.

/*  P0  */
__sbit __at(0x80) P00;
__sbit __at(0x81) P01;
__sbit __at(0x82) P02;
__sbit __at(0x83) P03;
__sbit __at(0x84) P04;
__sbit __at(0x85) P05;
__sbit __at(0x86) P06;
__sbit __at(0x87) P07;

/*  P1  */
__sbit __at(0x90) P10;
__sbit __at(0x91) P11;
__sbit __at(0x92) P12;
__sbit __at(0x93) P13;
__sbit __at(0x94) P14;
__sbit __at(0x95) P15;
__sbit __at(0x96) P16;
__sbit __at(0x97) P17;

__sbit __at(0x90) RXD2;
__sbit __at(0x91) TXD2;
__sbit __at(0x90) CCP1;
__sbit __at(0x91) CCP0;
__sbit __at(0x92) SPI_SS;
__sbit __at(0x93) SPI_MOSI;
__sbit __at(0x94) SPI_MISO;
__sbit __at(0x95) SPI_SCLK;

__sbit __at(0xA2) SPI_SS_2;
__sbit __at(0xA3) SPI_MOSI_2;
__sbit __at(0xA4) SPI_MISO_2;
__sbit __at(0xA5) SPI_SCLK_2;

__sbit __at(0xCC) SPI_SS_3;
__sbit __at(0xC0) SPI_MOSI_3;
__sbit __at(0xC1) SPI_MISO_3;
__sbit __at(0xC3) SPI_SCLK_3;

__sbit __at(0xB5) SPI_SS_4;
__sbit __at(0xB4) SPI_MOSI_4;
__sbit __at(0xB3) SPI_MISO_4;
__sbit __at(0xB2) SPI_SCLK_4;

/*  P2  */
__sbit __at(0xA0) P20;
__sbit __at(0xA1) P21;
__sbit __at(0xA2) P22;
__sbit __at(0xA3) P23;
__sbit __at(0xA4) P24;
__sbit __at(0xA5) P25;
__sbit __at(0xA6) P26;
__sbit __at(0xA7) P27;

/*  P3  */
__sbit __at(0xB0) P30;
__sbit __at(0xB1) P31;
__sbit __at(0xB2) P32;
__sbit __at(0xB3) P33;
__sbit __at(0xB4) P34;
__sbit __at(0xB5) P35;
__sbit __at(0xB6) P36;
__sbit __at(0xB7) P37;

__sbit __at(0xB0) RXD;
__sbit __at(0xB1) TXD;
__sbit __at(0xB2) INT0;
__sbit __at(0xB3) INT1;
__sbit __at(0xB4) T0;
__sbit __at(0xB5) T1;
__sbit __at(0xB6) WR;
__sbit __at(0xB7) RD;

__sbit __at(0xB6) INT2;
__sbit __at(0xB7) INT3;
__sbit __at(0xB0) INT4;
__sbit __at(0xB7) CCP2;

__sbit __at(0xB5) CLKOUT0;
__sbit __at(0xB4) CLKOUT1;

/*  P4  */
__sbit __at(0xC0) P40;
__sbit __at(0xC1) P41;
__sbit __at(0xC2) P42;
__sbit __at(0xC3) P43;
__sbit __at(0xC4) P44;
__sbit __at(0xC5) P45;
__sbit __at(0xC6) P46;
__sbit __at(0xC7) P47;

/*  P5  */
__sbit __at(0xC8) P50;
__sbit __at(0xC9) P51;
__sbit __at(0xCA) P52;
__sbit __at(0xCB) P53;
__sbit __at(0xCC) P54;
__sbit __at(0xCD) P55;
__sbit __at(0xCE) P56;
__sbit __at(0xCF) P57;

/*  P6  */
__sbit __at(0xE8) P60;
__sbit __at(0xE9) P61;
__sbit __at(0xEA) P62;
__sbit __at(0xEB) P63;
__sbit __at(0xEC) P64;
__sbit __at(0xED) P65;
__sbit __at(0xEE) P66;
__sbit __at(0xEF) P67;

/*  P7  */
__sbit __at(0xF8) P70;
__sbit __at(0xF9) P71;
__sbit __at(0xFA) P72;
__sbit __at(0xFB) P73;
__sbit __at(0xFC) P74;
__sbit __at(0xFD) P75;
__sbit __at(0xFE) P76;
__sbit __at(0xFF) P77;


/*  SCON  */
__sbit __at(0x9F) SM0;	//SM0/FE SM0 SM1 = 00 ~ 11: Mode 0~3
__sbit __at(0x9E) SM1;	//
__sbit __at(0x9D) SM2;	//Multiprocessor communication
__sbit __at(0x9C) REN;	//Receive enable
__sbit __at(0x9B) TB8;	//Send data bit 8
__sbit __at(0x9A) RB8;	//Receive data bit 8
__sbit __at(0x99) TI;	//Send interrupt flag bit
__sbit __at(0x98) RI;	//Receive interrupt flag bit

/*  IE   */
__sbit __at(0xAF) EA;	//Interrupt enable master control bit
__sbit __at(0xAE) ELVD;	//Low voltage monitoring interrupt enable bit
__sbit __at(0xAD) EADC;	//ADC interrupt enable bit
__sbit __at(0xAC) ES;	//Serial interrupt enable control bit
__sbit __at(0xAB) ET1;	//Timer 1 interrupt enable bit
__sbit __at(0xAA) EX1;	//External interrupt 1 enable control bit
__sbit __at(0xA9) ET0;	//Timer 0 interrupt enable bit
__sbit __at(0xA8) EX0;	//External interrupt 0 enable control bit

__sbit __at(0xE0) ACC0;
__sbit __at(0xE1) ACC1;
__sbit __at(0xE2) ACC2;
__sbit __at(0xE3) ACC3;
__sbit __at(0xE4) ACC4;
__sbit __at(0xE5) ACC5;
__sbit __at(0xE6) ACC6;
__sbit __at(0xE7) ACC7;

__sbit __at(0xF0) B0;
__sbit __at(0xF1) B1;
__sbit __at(0xF2) B2;
__sbit __at(0xF3) B3;
__sbit __at(0xF4) B4;
__sbit __at(0xF5) B5;
__sbit __at(0xF6) B6;
__sbit __at(0xF7) B7;


//							             7     6     5     4     3     2     1     0     Reset Value
//sfr IE2       = 0xAF;		ETKSUI   ET4   ET3   ES4   ES3   ET2   ESPI  ES2   x000,0000B	//Auxiliary Interrupt   
#define		SPI_INT_ENABLE()		IE2 |=  2	/* Enable SPI interrupts		*/
#define		SPI_INT_DISABLE()		IE2 &= ~2	/* Enable SPI interrupts		*/
#define		UART2_INT_ENABLE()		IE2 |=  1	/* Allow serial port 2 interrupt	*/
#define		UART2_INT_DISABLE()		IE2 &= ~1	/* Allow serial port 2 interrupt	*/


//                                           7      6      5      4      3      2      1      0      Reset Value
//sfr IP2   = 0xB5; //                    PPWM2FD PI2C   PCMP    PX4  PPWM0FD  PPWM0  PSPI   PS2     0000,0000
#define		PUSB		0x80
#define		PPWM2FD	0x80
#define		PTKSU		0x80
#define		PI2C	0x40
#define		PCMP	0x20
#define		PX4		0x10
#define		PPWM0FD	0x08
#define		PPWM0	0x04
#define		PSPI	0x02
#define		PS2		0x01
//                                           7      6      5      4      3      2      1      0      Reset Value
//sfr IP2H  = 0xB6; //                    PPWM2FDH PI2CH PCMPH   PX4H PPWM0FDH PPWM0H PSPIH  PS2H    0000,0000
#define		PUSBH		0x80
#define		PPWM2FDH	0x80
#define		PTKSUH	0x80
#define		PI2CH		0x40
#define		PCMPH		0x20
#define		PX4H		0x10
#define		PPWM0FDH	0x08
#define		PPWM0H	0x04
#define		PSPIH		0x02
#define		PS2H		0x01

//Serial port 2 interrupt priority control
#define 	UART2_Priority(n)			do{if(n == 0) IP2H &= ~PS2H, IP2 &= ~PS2; \
																if(n == 1) IP2H &= ~PS2H, IP2 |= PS2; \
																if(n == 2) IP2H |= PS2H, IP2 &= ~PS2; \
																if(n == 3) IP2H |= PS2H, IP2 |= PS2; \
															}while(0)
//SPI interrupt priority control
#define 	SPI_Priority(n)				do{if(n == 0) IP2H &= ~PSPIH, IP2 &= ~PSPI; \
																if(n == 1) IP2H &= ~PSPIH, IP2 |= PSPI; \
																if(n == 2) IP2H |= PSPIH, IP2 &= ~PSPI; \
																if(n == 3) IP2H |= PSPIH, IP2 |= PSPI; \
															}while(0)
//External interrupt 4 interrupt priority control
#define 	INT4_Priority(n)				do{if(n == 0) IP2H &= ~PX4H, IP2 &= ~PX4; \
																if(n == 1) IP2H &= ~PX4H, IP2 |= PX4; \
																if(n == 2) IP2H |= PX4H, IP2 &= ~PX4; \
																if(n == 3) IP2H |= PX4H, IP2 |= PX4; \
															}while(0)
//Comparator interrupt priority control
#define 	CMP_Priority(n)				do{if(n == 0) IP2H &= ~PCMPH, IP2 &= ~PCMP; \
																if(n == 1) IP2H &= ~PCMPH, IP2 |= PCMP; \
																if(n == 2) IP2H |= PCMPH, IP2 &= ~PCMP; \
																if(n == 3) IP2H |= PCMPH, IP2 |= PCMP; \
															}while(0)
//I2C interrupt priority control
#define 	I2C_Priority(n)				do{if(n == 0) IP2H &= ~PI2CH, IP2 &= ~PI2C; \
																if(n == 1) IP2H &= ~PI2CH, IP2 |= PI2C; \
																if(n == 2) IP2H |= PI2CH, IP2 &= ~PI2C; \
																if(n == 3) IP2H |= PI2CH, IP2 |= PI2C; \
															}while(0)
//Enhanced PWM0 interrupt priority control
#define 	PWM0_Priority(n)			do{if(n == 0) IP2H &= ~PPWM0H, IP2 &= ~PPWM0; \
																if(n == 1) IP2H &= ~PPWM0H, IP2 |= PPWM0; \
																if(n == 2) IP2H |= PPWM0H, IP2 &= ~PPWM0; \
																if(n == 3) IP2H |= PPWM0H, IP2 |= PPWM0; \
															}while(0)
//Enhanced PWM0 fault detection interrupt priority control
#define 	PWM0FD_Priority(n)		do{if(n == 0) IP2H &= ~PPWM0FDH, IP2 &= ~PPWM0FD; \
																if(n == 1) IP2H &= ~PPWM0FDH, IP2 |= PPWM0FD; \
																if(n == 2) IP2H |= PPWM0FDH, IP2 &= ~PPWM0FD; \
																if(n == 3) IP2H |= PPWM0FDH, IP2 |= PPWM0FD; \
															}while(0)
//Enhanced PWM2 fault detection interrupt priority control
#define 	PWM2FD_Priority(n)		do{if(n == 0) IP2H &= ~PPWM2FDH, IP2 &= ~PPWM2FD; \
																if(n == 1) IP2H &= ~PPWM2FDH, IP2 |= PPWM2FD; \
																if(n == 2) IP2H |= PPWM2FDH, IP2 &= ~PPWM2FD; \
																if(n == 3) IP2H |= PPWM2FDH, IP2 |= PPWM2FD; \
															}while(0)
//Touch key interrupt priority control
#define 	PTKSU_Priority(n)			do{if(n == 0) IP2H &= ~PTKSUH, IP2 &= ~PTKSU; \
																if(n == 1) IP2H &= ~PTKSUH, IP2 |= PTKSU; \
																if(n == 2) IP2H |= PTKSUH, IP2 &= ~PTKSU; \
																if(n == 3) IP2H |= PTKSUH, IP2 |= PTKSU; \
															}while(0)

//                                           7      6      5     4      3      2      1     0      Reset Value
//sfr IP3   = 0xDF; //                    PPWM4FD PPWM5  PPWM4  PPWM3  PPWM2  PPWM1  PS4   PS3     0000,0000
#define		PPWM4FD	0x80
#define		PPWM5		0x40
#define		PPWM4		0x20
#define		PPWM3		0x10
#define		PPWM2		0x08
#define		PPWM1		0x04
#define		PRTC		0x04
#define		PS4			0x02
#define		PS3			0x01
//                                           7        6       5      4       3       2     1     0      Reset Value
//sfr IP3H  = 0xEE; //                    PPWM4FDH PPWM5H  PPWM4H  PPWM3H  PPWM2H  PPWM1H PS4H  PS3H    0000,0000
#define		PPWM4FDH	0x80
#define		PPWM5H		0x40
#define		PPWM4H		0x20
#define		PPWM3H		0x10
#define		PPWM2H	0x08
#define		PPWM1H	0x04
#define		PRTCH		0x04
#define		PS4H		0x02
#define		PS3H		0x01

#ifdef STC8Hxx

//Enhanced PWM1 interrupt priority control
#define 	PWM1_Priority(n)			do{if(n == 0) IP2H &= ~PPWM1H, IP2 &= ~PPWM1; \
																if(n == 1) IP2H &= ~PPWM1H, IP2 |= PPWM1; \
																if(n == 2) IP2H |= PPWM1H, IP2 &= ~PPWM1; \
																if(n == 3) IP2H |= PPWM1H, IP2 |= PPWM1; \
															}while(0)
//Enhanced PWM2 interrupt priority control
#define 	PWM2_Priority(n)			do{if(n == 0) IP2H &= ~PPWM2H, IP2 &= ~PPWM2; \
																if(n == 1) IP2H &= ~PPWM2H, IP2 |= PPWM2; \
																if(n == 2) IP2H |= PPWM2H, IP2 &= ~PPWM2; \
																if(n == 3) IP2H |= PPWM2H, IP2 |= PPWM2; \
															}while(0)
//USB interrupt priority control
#define 	USB_Priority(n)				do{if(n == 0) IP2H &= ~PUSBH, IP2 &= ~PUSB; \
																if(n == 1) IP2H &= ~PUSBH, IP2 |= PUSB; \
																if(n == 2) IP2H |= PUSBH, IP2 &= ~PUSB; \
																if(n == 3) IP2H |= PUSBH, IP2 |= PUSB; \
															}while(0)
//RTC interrupt priority control
#define 	RTC_Priority(n)				do{if(n == 0) IP3H &= ~PRTCH, IP3 &= ~PRTC; \
																if(n == 1) IP3H &= ~PRTCH, IP3 |= PRTC; \
																if(n == 2) IP3H |= PRTCH, IP3 &= ~PRTC; \
																if(n == 3) IP3H |= PRTCH, IP3 |= PRTC; \
															}while(0)
#else

//Enhanced PWM1 interrupt priority control
#define 	PWM1_Priority(n)			do{if(n == 0) IP3H &= ~PPWM1H, IP3 &= ~PPWM1; \
																if(n == 1) IP3H &= ~PPWM1H, IP3 |= PPWM1; \
																if(n == 2) IP3H |= PPWM1H, IP3 &= ~PPWM1; \
																if(n == 3) IP3H |= PPWM1H, IP3 |= PPWM1; \
															}while(0)
//Enhanced PWM2 interrupt priority control
#define 	PWM2_Priority(n)			do{if(n == 0) IP3H &= ~PPWM2H, IP3 &= ~PPWM2; \
																if(n == 1) IP3H &= ~PPWM2H, IP3 |= PPWM2; \
																if(n == 2) IP3H |= PPWM2H, IP3 &= ~PPWM2; \
																if(n == 3) IP3H |= PPWM2H, IP3 |= PPWM2; \
															}while(0)

#endif

//Enhanced PWM3 interrupt priority control
#define 	PWM3_Priority(n)			do{if(n == 0) IP3H &= ~PPWM3H, IP3 &= ~PPWM3; \
																if(n == 1) IP3H &= ~PPWM3H, IP3 |= PPWM3; \
																if(n == 2) IP3H |= PPWM3H, IP3 &= ~PPWM3; \
																if(n == 3) IP3H |= PPWM3H, IP3 |= PPWM3; \
															}while(0)
//Enhanced PWM4 interrupt priority control
#define 	PWM4_Priority(n)			do{if(n == 0) IP3H &= ~PPWM4H, IP3 &= ~PPWM4; \
																if(n == 1) IP3H &= ~PPWM4H, IP3 |= PPWM4; \
																if(n == 2) IP3H |= PPWM4H, IP3 &= ~PPWM4; \
																if(n == 3) IP3H |= PPWM4H, IP3 |= PPWM4; \
															}while(0)
//Enhanced PWM5 interrupt priority control
#define 	PWM5_Priority(n)			do{if(n == 0) IP3H &= ~PPWM5H, IP3 &= ~PPWM5; \
																if(n == 1) IP3H &= ~PPWM5H, IP3 |= PPWM5; \
																if(n == 2) IP3H |= PPWM5H, IP3 &= ~PPWM5; \
																if(n == 3) IP3H |= PPWM5H, IP3 |= PPWM5; \
															}while(0)
//Enhanced PWM4 fault detection interrupt priority control
#define 	PWM4FD_Priority(n)		do{if(n == 0) IP3H &= ~PPWM4FDH, IP3 &= ~PPWM4FD; \
																if(n == 1) IP3H &= ~PPWM4FDH, IP3 |= PPWM4FD; \
																if(n == 2) IP3H |= PPWM4FDH, IP3 &= ~PPWM4FD; \
																if(n == 3) IP3H |= PPWM4FDH, IP3 |= PPWM4FD; \
															}while(0)
//Serial port 3 interrupt priority control
#define 	UART3_Priority(n)			do{if(n == 0) IP3H &= ~PS3H, IP3 &= ~PS3; \
																if(n == 1) IP3H &= ~PS3H, IP3 |= PS3; \
																if(n == 2) IP3H |= PS3H, IP3 &= ~PS3; \
																if(n == 3) IP3H |= PS3H, IP3 |= PS3; \
															}while(0)
//Serial port 4 interrupt priority control
#define 	UART4_Priority(n)			do{if(n == 0) IP3H &= ~PS4H, IP3 &= ~PS4; \
																if(n == 1) IP3H &= ~PS4H, IP3 |= PS4; \
																if(n == 2) IP3H |= PS4H, IP3 &= ~PS4; \
																if(n == 3) IP3H |= PS4H, IP3 |= PS4; \
															}while(0)

//                                          7     6     5    4    3    2    1    0    Reset Value
//sfr IP = 0xB8; //Interrupt priority low bit PPCA PLVD PADC PS PT1 PX1 PT0 PX0 0000,0000
//--------
__sbit __at(0xBF) PPCA;	//PCA module interrupt priority
__sbit __at(0xBE) PLVD;	//Low voltage monitoring interrupt priority
__sbit __at(0xBD) PADC;	//ADC interrupt priority
__sbit __at(0xBC) PS;	//Serial interrupt 0 priority setting bit
__sbit __at(0xBB) PT1;	//Timer 1 interrupt priority bit
__sbit __at(0xBA) PX1;	//External interrupt 1 priority setting bit
__sbit __at(0xB9) PT0;	//Timer 0 interrupt priority bit
__sbit __at(0xB8) PX0;	//External interrupt 0 priority setting bit

//                                           7      6      5      4      3      2      1      0      Reset Value
//sfr IPH = 0xB7; //Interrupt priority high bit PPCAH PLVDH PADCH PSH PT1H PX1H PT0H PX0H 0000,0000
#define		PPCAH	0x80
#define		PLVDH	0x40
#define		PADCH	0x20
#define		PSH		0x10
#define		PT1H	0x08
#define		PX1H	0x04
#define		PT0H	0x02
#define		PX0H	0x01

//External interrupt 0 interrupt priority control
#define 	INT0_Priority(n)			do{if(n == 0) IPH &= ~PX0H, PX0 = 0; \
																if(n == 1) IPH &= ~PX0H, PX0 = 1; \
																if(n == 2) IPH |= PX0H, PX0 = 0; \
																if(n == 3) IPH |= PX0H, PX0 = 1; \
															}while(0)
//External interrupt 1 interrupt priority control
#define 	INT1_Priority(n)			do{if(n == 0) IPH &= ~PX1H, PX1 = 0; \
																if(n == 1) IPH &= ~PX1H, PX1 = 1; \
																if(n == 2) IPH |= PX1H, PX1 = 0; \
																if(n == 3) IPH |= PX1H, PX1 = 1; \
															}while(0)
//Timer 0 interrupt priority control
#define 	Timer0_Priority(n)		do{if(n == 0) IPH &= ~PT0H, PT0 = 0; \
																if(n == 1) IPH &= ~PT0H, PT0 = 1; \
																if(n == 2) IPH |= PT0H, PT0 = 0; \
																if(n == 3) IPH |= PT0H, PT0 = 1; \
															}while(0)
//Timer 1 interrupt priority control
#define 	Timer1_Priority(n)		do{if(n == 0) IPH &= ~PT1H, PT1 = 0; \
																if(n == 1) IPH &= ~PT1H, PT1 = 1; \
																if(n == 2) IPH |= PT1H, PT1 = 0; \
																if(n == 3) IPH |= PT1H, PT1 = 1; \
															}while(0)
//Serial port 1 interrupt priority control
#define 	UART1_Priority(n)			do{if(n == 0) IPH &= ~PSH, PS = 0; \
																if(n == 1) IPH &= ~PSH, PS = 1; \
																if(n == 2) IPH |= PSH, PS = 0; \
																if(n == 3) IPH |= PSH, PS = 1; \
															}while(0)
//ADC interrupt priority control
#define 	ADC_Priority(n)				do{if(n == 0) IPH &= ~PADCH, PADC = 0; \
																if(n == 1) IPH &= ~PADCH, PADC = 1; \
																if(n == 2) IPH |= PADCH, PADC = 0; \
																if(n == 3) IPH |= PADCH, PADC = 1; \
															}while(0)
//Low voltage detection interrupt priority control
#define 	LVD_Priority(n)				do{if(n == 0) IPH &= ~PLVDH, PADC = 0; \
																if(n == 1) IPH &= ~PLVDH, PADC = 1; \
																if(n == 2) IPH |= PLVDH, PADC = 0; \
																if(n == 3) IPH |= PLVDH, PADC = 1; \
															}while(0)
//CCP/PCA/PWM interrupt priority control
#define 	PCA_Priority(n)				do{if(n == 0) IPH &= ~PPCAH, PPCA = 0; \
																if(n == 1) IPH &= ~PPCAH, PPCA = 1; \
																if(n == 2) IPH |= PPCAH, PPCA = 0; \
																if(n == 3) IPH |= PPCAH, PPCA = 1; \
															}while(0)

//#define		PCA_InterruptFirst()	PPCA = 1
//#define		LVD_InterruptFirst()	PLVD = 1
//#define		ADC_InterruptFirst()	PADC = 1
//#define		UART1_InterruptFirst()	PS   = 1
//#define		Timer1_InterruptFirst()	PT1  = 1
//#define		INT1_InterruptFirst()	PX1  = 1
//#define		Timer0_InterruptFirst()	PT0  = 1
//#define		INT0_InterruptFirst()	PX0  = 1


/*************************************************************************************************/


//                       7      6     5    4    3    2     1      0        Reset Value
//sfr CMPCR1 = 0xE6;   CMPEN  CMPIF  PIE  NIE  PIS  NIS  CMPOE  CMPRES      00000000B
#define	CMPEN	0x80	//1: enable comparator, 0: disable, disable comparator power
#define	CMPIF	0x40	//Comparator interrupt flag, set on a rising or falling edge; clear it to 0 in software
#define	PIE		0x20	//1: The comparison result changes from 0 to 1, generating a rising edge interrupt.
#define	NIE		0x10	//1: The comparison result changes from 1 to 0, generating a falling edge interrupt.
#define	PIS		0x08	//Input positive polarity selection, 0: select internal P3.7 as positive input, 1: ADC input terminal selected by ADC_CHS[3:0] as positive input.
#define	NIS		0x04	//Input negative polarity selection, 0: select the internal BandGap voltage BGv as the negative input, 1: select the external P3.6 as the input.
#define	CMPOE	0x02	//1: Allow comparison result output, 0: Disable.
#define	CMPRES	0x01	//Comparison result, 1: CMP+ level is higher than CMP-, 0: CMP+ level is lower than CMP-, read only

#define	CMP_P_P37	0x00	//Input positive polarity selection, 0: select internal P3.7 as positive input
#define	CMP_P_ADC	0x08	//Input positive polarity selection, 1: The ADC input terminal selected by ADC_CHS[3:0] is used as a positive input.
#define	CMP_N_GAP	0x00	//Input negative polarity selection, 0: select the internal BandGap voltage BGv as the negative input.
#define	CMP_N_P36	0x04	//Input negative polarity selection, 1: Select external P3.6 as input.

#define	CMPO_P34()	P_SW2 &= ~0x08	//The results are output to P3.4.
#define	CMPO_P41()	P_SW2 |=  0x08	//The results are output to P4.1.

//                       7        6       5  4  3  2  1  0    Reset Value
//sfr CMPCR2 = 0xE7;   INVCMPO  DISFLT       LCDTY[5:0]       00001001B
#define	INVCMPO	0x80	//1: Comparator output IO is inverted, 0: Not inverted
#define	DISFLT	0x40	//1: Disable 0.1uF filter, 0: Allow
#define	LCDTY	0x00	//0~63, the number of delay cycles for comparison result changes



/*************************************************************************************************/
//                     7     6     5    4    3    2   1   0       Reset Value
//sfr SCON  = 0x98;   SM0   SM1   SM2  REN  TB8  RB8  TI  RI      00000000B		 //S1 Control

#define		S1_DoubleRate()		PCON  |=  0x80
#define		S1_SHIFT()			SCON  &=  0x3f

#define		S1_8bit()			SCON   =  (SCON & 0x3f) | 0x40
#define		S1_9bit()			SCON   =  (SCON & 0x3f) | 0xc0
#define		S1_RX_Enable()		SCON  |=  0x10
#define		S1_RX_Disable()		SCON  &= ~0x10
#define		TI1					TI					/* Check whether TI1 transmission is complete								 */
#define		RI1					RI					/* Check whether RI1 reception is complete								 */
#define		SET_TI1()			TI = 1				/* Set TI1 (triggers interrupt)								 */
#define		CLR_TI1()			TI = 0				/* Clear TI1											 */
#define		CLR_RI1()			RI = 0				/* Clear RI1											 */
#define		S1TB8_SET()			TB8 = 1				/* Set TB8											 */
#define		S1TB8_CLR()			TB8 = 0				/* Clear TB8											 */
#define		S1_Int_Enable()		ES     =  1			/* Enable UART1 interrupt									 */
#define		S1_Int_Disable()	ES     =  0			/* Disable UART1 interrupt									 */
#define 	S1_BRT_UseTimer1()	AUXR  &= ~1
#define 	S1_BRT_UseTimer2()	AUXR  |=  1
#define		S1_USE_P30P31()		P_SW1 &= ~0xc0						//UART1 uses P30 P31 port default
#define		S1_USE_P36P37()		P_SW1  =  (P_SW1 & ~0xc0) | 0x40	//UART1 uses P36 P37 port
#define		S1_USE_P16P17()		P_SW1  =  (P_SW1 & ~0xc0) | 0x80	//UART1 uses P16 P17 port
#define		S1_USE_P43P44()		P_SW1 |=  0xc0						//UART1 uses P43 P44 port
//#define S1_TXD_RXD_SHORT() PCON2 |= (1<<4) //Connect TXD and RXD for relay output
//#define S1_TXD_RXD_OPEN() PCON2 &= ~(1<<4) //Disconnect TXD and RXD connection relay Default

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S2CON = 0x9A;		S2SM0    -    S2SM2  S2REN  S2TB8  S2RB8  S2TI  S2RI      00000000B		 //S2 Control

#define		S2_MODE0()			S2CON &= ~(1<<7)	/* Serial port 2 mode 0, 8-bit UART, baud rate = timer 2 overflow rate / 4 */
#define		S2_MODE1()			S2CON |=  (1<<7)	/* Serial port 2 mode 1, 9-bit UART, baud rate = timer 2 overflow rate / 4 */
#define		S2_8bit()			S2CON &= ~(1<<7)	/* Serial port 2 mode 0, 8-bit UART, baud rate = timer 2 overflow rate / 4 */
#define		S2_9bit()			S2CON |=  (1<<7)	/* Serial port 2 mode 1, 9-bit UART, baud rate = timer 2 overflow rate / 4 */
#define		S2_RX_Enable()		S2CON |=  (1<<4)	/* Enable UART2 receiver										 */
#define		S2_RX_Disable()		S2CON &= ~(1<<4)	/* Disable UART2 receiver										 */
#define		TI2					(S2CON & 2) 		/* Check whether TI2 transmission is complete								 */
#define		RI2					(S2CON & 1) 		/* Check whether RI2 reception is complete								 */
#define		SET_TI2()			S2CON |=  (1<<1)	/* Set TI2 (triggers interrupt)								 */
#define		CLR_TI2()			S2CON &= ~(1<<1)	/* Clear TI2											 */
#define		CLR_RI2()			S2CON &= ~1			/* Clear RI2											 */
#define		S2TB8_SET()			S2CON |=  (1<<3)	/* Set TB8											 */
#define		S2TB8_CLR()			S2CON &= ~(1<<3)	/* Clear TB8											 */
#define		S2_Int_Enable()		IE2   |=  1			/* Enable UART2 interrupt									 */
#define		S2_Int_Disable()	IE2   &= ~1			/* Disable UART2 interrupt									 */
#define		S2_USE_P10P11()		P_SW2 &= ~1			/* UART2 uses P1 port default							 */
#define		S2_USE_P46P47()		P_SW2 |=  1			/* UART2 uses P4 port									 */

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S3CON = 0xAC;		S3SM0  S3ST3  S3SM2  S3REN  S3TB8  S3RB8  S3TI  S3RI      00000000B		 //S3 Control

#define		S3_MODE0()			S3CON &= ~(1<<7)	/* Serial port 3 mode 0, 8-bit UART, baud rate = timer overflow rate / 4  */
#define		S3_MODE1()			S3CON |=  (1<<7)	/* Serial port 3 mode 1, 9-bit UART, baud rate = timer overflow rate / 4  */
#define		S3_8bit()			S3CON &= ~(1<<7)	/* Serial port 3 mode 0, 8-bit UART, baud rate = timer overflow rate / 4  */
#define		S3_9bit()			S3CON |=  (1<<7)	/* Serial port 3 mode 1, 9-bit UART, baud rate = timer overflow rate / 4  */
#define		S3_RX_Enable()		S3CON |=  (1<<4)	/* Enable UART3 receiver									     */
#define		S3_RX_Disable()		S3CON &= ~(1<<4)	/* Disable UART3 receiver									     */
#define		TI3					(S3CON & 2) != 0	/* Check whether TI3 transmission is complete								 */
#define		RI3					(S3CON & 1) != 0	/* Check whether RI3 reception is complete								 */
#define		SET_TI3()			S3CON |=  (1<<1)	/* Set TI3 (triggers interrupt)								 */
#define		CLR_TI3()			S3CON &= ~(1<<1)	/* Clear TI3											 */
#define		CLR_RI3()			S3CON &= ~1			/* Clear RI3											 */
#define		S3TB8_SET()			S3CON |=  (1<<3)	/* Set TB8											 */
#define		S3TB8_CLR()			S3CON &= ~(1<<3)	/* Clear TB8											 */
#define		S3_Int_Enable()		IE2   |=  (1<<3)	/* Enable UART3 interrupt								     */
#define		S3_Int_Disable()	IE2   &= ~(1<<3)	/* Disable UART3 interrupt								     */
#define 	S3_BRT_UseTimer3()	S3CON |=  (1<<6)	/* BRT select Timer3								 */
#define 	S3_BRT_UseTimer2()	S3CON &= ~(1<<6)	/* BRT select Timer2								 */
#define		S3_USE_P00P01()		P_SW2 &= ~2			/* UART3 uses P0 port default						     */
#define		S3_USE_P50P51()		P_SW2 |=  2			/* UART3 uses P5 port								     */

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S4CON = 0x84;		S4SM0  S4ST4  S4SM2  S4REN  S4TB8  S4RB8  S4TI  S4RI      00000000B		 //S4 Control

#define		S4_MODE0()			S4CON &= ~(1<<7)	/* Serial port 4 mode 0, 8-bit UART, baud rate = timer overflow rate / 4  */
#define		S4_MODE1()			S4CON |=  (1<<7)	/* Serial port 4 mode 1, 9-bit UART, baud rate = timer overflow rate / 4  */
#define		S4_8bit()			S4CON &= ~(1<<7)	/* Serial port 4 mode 0, 8-bit UART, baud rate = timer overflow rate / 4  */
#define		S4_9bit()			S4CON |=  (1<<7)	/* Serial port 4 mode 1, 9-bit UART, baud rate = timer overflow rate / 4  */
#define		S4_RX_Enable()		S4CON |=  (1<<4)	/* Enable UART4 receiver									     */
#define		S4_RX_Disable()		S4CON &= ~(1<<4)	/* Disable UART4 receiver									     */
#define		TI4					(S4CON & 2) != 0	/* Check whether TI3 transmission is complete							     */
#define		RI4					(S4CON & 1) != 0	/* Check whether RI3 reception is complete							     */
#define		SET_TI4()			S4CON |=  2			/* Set TI3 (triggers interrupt)							     */
#define		CLR_TI4()			S4CON &= ~2			/* Clear TI3										     */
#define		CLR_RI4()			S4CON &= ~1			/* Clear RI3										     */
#define		S4TB8_SET()			S4CON |=  8			/* Set TB8										     */
#define		S4TB8_CLR()			S4CON &= ~8			/* Clear TB8										     */
#define		S4_Int_Enable()		IE2   |=  (1<<4)	/* Enable UART4 interrupt								     */
#define		S4_Int_Disable()	IE2   &= ~(1<<4)	/* Disable UART4 interrupt								     */
#define 	S4_BRT_UseTimer4()	S4CON |=  (1<<6)	/* BRT select Timer4								 */
#define 	S4_BRT_UseTimer2()	S4CON &= ~(1<<6)	/* BRT select Timer2								 */
#define		S4_USE_P02P03()		P_SW2 &= ~4			/* UART4 uses P0 port default						     */
#define		S4_USE_P52P53()		P_SW2 |=  4			/* UART4 uses P5 port								     */



/**********************************************************/
//						   7     6       5      4     3      2      1      0    Reset Value
//sfr AUXR  = 0x8E;		T0x12 T1x12 UART_M0x6  T2R  T2_C/T T2x12 EXTRAM  S1ST2  0000,0000	//Auxiliary Register 

#define 	InternalXdata_Disable()		AUXR |=  2		/* The use of internal xdata is prohibited, all access to xdata is access to external xdata  */
#define 	InternalXdata_Enable()		AUXR &= ~2		/* It is allowed to use internal xdata. When the accessed address is in the internal xdata range, the internal xadta is accessed. When the address exceeds the internal xdata, the external xdata is accessed.  */
#define		S1_M0x6()					AUXR |=  (1<<5)	/* UART Mode0 Speed is 6x Standard       */
#define		S1_M0x1()					AUXR &= ~(1<<5)	/* default,	UART Mode0 Speed is Standard */

//====================================
#define		Timer0_16bitAutoReload()	TMOD &= ~0x03					/* 16-bit auto-reload	*/
#define		Timer0_16bit()				TMOD  = (TMOD & ~0x03) | 0x01	/* 16 bit         */
#define		Timer0_8bitAutoReload()		TMOD  = (TMOD & ~0x03) | 0x02	/* 8-bit auto-reload	*/
#define		Timer0_16bitAutoRL_NoMask()	TMOD |=  0x03		/* 16-bit auto-reload non-maskable interrupt	*/
#define 	Timer0_Run()	 			TR0 = 1				/* Allow timer 0 to count			*/
#define 	Timer0_Stop()	 			TR0 = 0				/* Disable timer 0 counting			*/
#define		Timer0_Gate_INT0_P32()		TMOD |=  (1<<3)		/* Timer 0 is enabled by external INT0 high level to allow timing counting. */
#define		Timer0_AsTimer()			TMOD &= ~(1<<2)		/* Timer 0 is used as a timer	*/
#define		Timer0_AsCounter()			TMOD |=  (1<<2)		/* Timer 0 is used as a counter	*/
#define		Timer0_AsCounterP34()		TMOD |=  (1<<2)		/* Timer 0 is used as a counter	*/
#define 	Timer0_1T()					AUXR |=  (1<<7)		/* Timer0 clodk = fo	*/
#define 	Timer0_12T()				AUXR &= ~(1<<7)		/* Timer0 clodk = fo/12 divide by 12, default	*/
#define		Timer0_CLKO_Enable()		INT_CLKO |=  1			/* Allow T0 overflow pulse to be output at T0 (P3.5) pin, Fck0 = 1/2 T0 overflow rate, T0 can be 1T or 12T.	*/
#define		Timer0_CLKO_Disable()		INT_CLKO &= ~1
#define		Timer0_CLKO_Enable_P34()	INT_CLKO |=  1			/* Allow T0 overflow pulse to be output at T0 (P3.5) pin, Fck0 = 1/2 T0 overflow rate, T0 can be 1T or 12T.	*/
#define		Timer0_CLKO_Disable_P34()	INT_CLKO &= ~1
#define 	Timer0_InterruptEnable()	ET0 = 1				/* Enable Timer1 interrupt.*/
#define 	Timer0_InterruptDisable()	ET0 = 0				/* Disable Timer1 interrupt.*/

#define		T0_Load(n)					TH0 = (n) / 256,	TL0 = (n) % 256
#define		T0_Load_us_1T(n)			Timer0_AsTimer(),Timer0_1T(), Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/1000)*(n))/1000)/256, TL0=(65536-((MAIN_Fosc/1000)*(n))/1000)%256
#define		T0_Load_us_12T(n)			Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/12000)*(n))/1000)/256,TL0=(65536-((MAIN_Fosc/12000)*(n))/1000)%256
#define		T0_Frequency_1T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_1T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/2)/(n))%256,INT_CLKO |= bit0,TR0=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T0_Frequency_12T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/24)/(n))%256,INT_CLKO |= bit0,TR0=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define		Timer1_16bitAutoReload()	TMOD &= ~0x30					/* 16-bit auto-reload	*/
#define		Timer1_16bit()				TMOD  = (TMOD & ~0x30) | 0x10	/* 16 bit			*/
#define		Timer1_8bitAutoReload()		TMOD  = (TMOD & ~0x30) | 0x20	/* 8-bit auto-reload	*/
#define 	Timer1_Run()	 			TR1 = 1				/* Allow timer 1 to count			*/
#define 	Timer1_Stop()	 			TR1 = 0				/* Disable timer 1 counting			*/
#define		Timer1_Gate_INT1_P33()		TMOD |=  (1<<7)		/* Timer 1 is enabled by external INT1 high level to allow timing counting.	*/
#define		Timer1_AsTimer()			TMOD &= ~(1<<6)		/* Timer 1 is used as a timer			*/
#define		Timer1_AsCounter()			TMOD |=  (1<<6)		/* Timer 1 is used as a counter			*/
#define		Timer1_AsCounterP35()		TMOD |=  (1<<6)		/* Timer 1 is used as a counter			*/
#define 	Timer1_1T()					AUXR |=  (1<<6)		/* Timer1 clodk = fo		*/
#define 	Timer1_12T()				AUXR &= ~(1<<6)		/* Timer1 clodk = fo/12 divide by 12, default	*/
#define		Timer1_CLKO_Enable()		INT_CLKO |=  2			/* Allow T1 overflow pulse to be output at T1 (P3.4) pin, Fck1 = 1/2 T1 overflow rate, T1 can be 1T or 12T.	*/
#define		Timer1_CLKO_Disable()		INT_CLKO &= ~2
#define		Timer1_CLKO_Enable_P35()	INT_CLKO |=  2			/* Allow T1 overflow pulse to be output at T1 (P3.4) pin, Fck1 = 1/2 T1 overflow rate, T1 can be 1T or 12T.	*/
#define		Timer1_CLKO_Disable_P35()	INT_CLKO &= ~2
#define 	Timer1_InterruptEnable()	ET1 = 1				/* Enable Timer1 interrupt.	*/
#define 	Timer1_InterruptDisable()	ET1 = 0				/* Disable Timer1 interrupt.	*/

#define		T1_Load(n)					TH1 = (n) / 256,	TL1 = (n) % 256
#define		T1_Load_us_1T(n)			Timer1_AsTimer(),Timer1_1T(), Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T1_Load_us_12T(n)			Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T1_Frequency_1T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_1T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/2)/(n))%256,INT_CLKO |= bit1,TR1=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T1_Frequency_12T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/24)/(n))%256,INT_CLKO |= bit1,TR1=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer2_Run()	 			AUXR |=  (1<<4)	/* Allow timer 2 to count	*/
#define 	Timer2_Stop()	 			AUXR &= ~(1<<4)	/* Disable timer 2 counting	*/
#define		Timer2_AsTimer()			AUXR &= ~(1<<3)	/* Timer 2 is used as a timer	*/
#define		Timer2_AsCounter()			AUXR |=  (1<<3)	/* Timer 2 is used as a counter	*/
#define		Timer2_AsCounterP31()		AUXR |=  (1<<3)	/* Timer 2 is used as a counter	*/
#define 	Timer2_1T()					AUXR |=  (1<<2)	/* Timer0 clock = fo	*/
#define 	Timer2_12T()				AUXR &= ~(1<<2)	/* Timer0 clock = fo/12 divide by 12, default	*/
#define		Timer2_CLKO_Enable()		INT_CLKO |=  4		/* Allow T2 overflow pulse to be output at P1.3 pin, Fck2 = 1/2 T2 overflow rate, T2 can be 1T or 12T.	*/
#define		Timer2_CLKO_Disable()		INT_CLKO &= ~4
#define		Timer2_CLKO_Enable_P13()	INT_CLKO |=  4		/* Allow T2 overflow pulse to be output at P1.3 pin, Fck2 = 1/2 T2 overflow rate, T2 can be 1T or 12T.	*/
#define		Timer2_CLKO_Disable_P13()	INT_CLKO &= ~4
#define 	Timer2_InterruptEnable()	IE2  |=  (1<<2)	/* Enable Timer2 interrupt.	*/
#define 	Timer2_InterruptDisable()	IE2  &= ~(1<<2)	/* Disable Timer2 interrupt.	*/

#define		T2_Load(n)					TH2 = (n) / 256,	TL2 = (n) % 256
#define		T2_Load_us_1T(n)			Timer2_AsTimer(),Timer2_1T(), TH2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T2_Load_us_12T(n)			Timer2_AsTimer(),Timer2_12T(),TH2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T2_Frequency_1T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_1T(), TH2=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL2=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T2_Frequency_12T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_12T(),TH2=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL2=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer3_Run()	 			T4T3M |=  (1<<3)	/* Allow timer 3 to count	*/
#define 	Timer3_Stop()	 			T4T3M &= ~(1<<3)	/* Disable timer 3 counting	*/
#define		Timer3_AsTimer()			T4T3M &= ~(1<<2)	/* Timer 3 is used as a timer	*/
#define		Timer3_AsCounter()			T4T3M |=  (1<<2)	/* Timer 3 is used as a counter, P0.5 is an external pulse	*/
#define		Timer3_AsCounterP05()		T4T3M |=  (1<<2)	/* Timer 3 is used as a counter, P0.5 is an external pulse	*/
#define 	Timer3_1T()					T4T3M |=  (1<<1)	/* 1T mode	*/
#define 	Timer3_12T()				T4T3M &= ~(1<<1)	/* 12T mode, default	*/
#define		Timer3_CLKO_Enable()		T4T3M |=  1			/* Allow T3 overflow pulse to be output at T3 (P0.4) pin, Fck = 1/2 T2 overflow rate, T2 can be 1T or 12T.	*/
#define		Timer3_CLKO_Disable()		T4T3M &= ~1			/* Disable T3 overflow pulse output at T3 (P0.4) pin	*/
#define		Timer3_CLKO_Enable_P04()	T4T3M |=  1			/* Allow T3 overflow pulse to be output at T3 (P0.4) pin, Fck = 1/2 T2 overflow rate, T2 can be 1T or 12T.	*/
#define		Timer3_CLKO_Disable_P04()	T4T3M &= ~1			/* Disable T3 overflow pulse output at T3 (P0.4) pin	*/
#define 	Timer3_InterruptEnable()	IE2  |=  (1<<5)		/* Enable Timer3 interrupt.	*/
#define 	Timer3_InterruptDisable()	IE2  &= ~(1<<5)		/* Disable Timer3 interrupt.	*/

#define		T3_Load(n)					TH3 = (n) / 256,	TL3 = (n) % 256
#define		T3_Load_us_1T(n)			Timer3_AsTimer(),Timer3_1T(), TH3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T3_Load_us_12T(n)			Timer3_AsTimer(),Timer3_12T(),TH3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T3_Frequency_1T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_1T(), TH3=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL3=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T3_Frequency_12T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_12T(),TH3=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL3=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer4_Run()	 			T4T3M |=  (1<<7)	/* Allow timer 4 to count	*/
#define 	Timer4_Stop()	 			T4T3M &= ~(1<<7)	/* Disable timer 4 counting	*/
#define		Timer4_AsTimer()			T4T3M &= ~(1<<6)	/* Timer 4 is used as a timer  */
#define		Timer4_AsCounter()			T4T3M |=  (1<<6)	/* Timer 4 is used as a counter, P0.7 is an external pulse	*/
#define		Timer4_AsCounterP07()		T4T3M |=  (1<<6)	/* Timer 4 is used as a counter, P0.7 is an external pulse	*/
#define 	Timer4_1T()					T4T3M |=  (1<<5)	/* 1T mode	*/
#define 	Timer4_12T()				T4T3M &= ~(1<<5)	/* 12T mode, default	*/
#define		Timer4_CLKO_Enable()		T4T3M |=  (1<<4)	/* Allow T4 overflow pulse to be output at T4 (P0.6) pin, Fck = 1/2 T2 overflow rate, T2 can be 1T or 12T.	*/
#define		Timer4_CLKO_Disable()		T4T3M &= ~(1<<4)	/* Disable T4 overflow pulse output at T4 (P0.6) pin	*/
#define		Timer4_CLKO_Enable_P06()	T4T3M |=  (1<<4)	/* Allow T4 overflow pulse to be output at T4 (P0.6) pin, Fck = 1/2 T2 overflow rate, T2 can be 1T or 12T.	*/
#define		Timer4_CLKO_Disable_P06()	T4T3M &= ~(1<<4)	/* Disable T4 overflow pulse output at T4 (P0.6) pin	*/
#define 	Timer4_InterruptEnable()	IE2  |=  (1<<6)		/* Enable Timer4 interrupt.	*/
#define 	Timer4_InterruptDisable()	IE2  &= ~(1<<6)		/* Disable Timer4 interrupt.	*/

#define		T4_Load(n)					TH4 = (n) / 256,	TL4 = (n) % 256
#define		T4_Load_us_1T(n)			Timer4_AsTimer(),Timer4_1T(), TH4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T4_Load_us_12T(n)			Timer4_AsTimer(),Timer4_12T(),TH4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T4_Frequency_1T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_1T(), TH4=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL4=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T4_Frequency_12T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_12T(),TH4=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL4=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
//====================================================================================================================

//sfr WDT_CONTR = 0xC1; //Watch-Dog-Timer Control register
//                                      7     6     5      4       3      2   1   0     Reset Value
//                                  WDT_FLAG  -  EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0    xx00,0000
#define D_WDT_FLAG			(1<<7)
#define D_EN_WDT			(1<<5)
#define D_CLR_WDT			(1<<4)	/* auto clear	*/
#define D_IDLE_WDT			(1<<3)	/* WDT counter when Idle	*/
#define D_WDT_SCALE_2		0
#define D_WDT_SCALE_4		1
#define D_WDT_SCALE_8		2		/* T=393216*N/fo	*/
#define D_WDT_SCALE_16		3
#define D_WDT_SCALE_32		4
#define D_WDT_SCALE_64		5
#define D_WDT_SCALE_128		6
#define D_WDT_SCALE_256		7

#define	WDT_PS_Set(n)	WDT_CONTR = (WDT_CONTR & ~0x07) | (n & 0x07)		/* Watchdog timer clock prescaler setting */
#define	WDT_reset(n)	WDT_CONTR = D_EN_WDT + D_CLR_WDT + D_IDLE_WDT + (n)		/* Initialize and service WDT */


//						  7     6      5    4     3      2    1     0     Reset Value
//sfr PCON   = 0x87;	SMOD  SMOD0  LVDF  POF   GF1    GF0   PD   IDL    0001,0000	 //Power Control 
//SMOD //Serial port double speed
//SMOD0
#define		LVDF		(1<<5)	/* P4.6 low-voltage detection flag */
//POF
//GF1
//GF0
//#define 	D_PD		2		/* set 1, power down mode */
//#define 	D_IDLE		1		/* set 1, idle mode */
#define		MCU_IDLE()			PCON |= 1	/* MCU enters IDLE mode */
#define		MCU_POWER_DOWN()	PCON |= 2	/* MCU enters sleep mode */


//sfr IAP_CMD   = 0xC5;
#define		IAP_STANDBY()	IAP_CMD = 0		//IAP idle command (disabled)
#define		IAP_READ()		IAP_CMD = 1		//IAP read command
#define		IAP_WRITE()		IAP_CMD = 2		//IAP write command
#define		IAP_ERASE()		IAP_CMD = 3		//IAP erase command

//sfr IAP_TRIG  = 0xC6;
#define 	IAP_TRIG()	IAP_TRIG = 0x5A,	IAP_TRIG = 0xA5		/* IAP trigger command */

//							            7    6    5      4    3   2  1   0   Reset Value
//sfr IAP_CONTR = 0xC7;		IAPEN SWBS SWRST CFAIL  -   -  -   -   0000,x000	//IAP Control Register

#define IAP_EN          (1<<7)
#define IAP_SWBS        (1<<6)
#define IAP_SWRST       (1<<5)
#define IAP_CMD_FAIL    (1<<4)

#define	IAP_ENABLE()		IAP_CONTR = IAP_EN; IAP_TPS = MAIN_Fosc / 1000000
#define	IAP_DISABLE()		IAP_CONTR = 0; IAP_CMD = 0; IAP_TRIG = 0; IAP_ADDRH = 0xff; IAP_ADDRL = 0xff


/* ADC Register */
//								7       6      5       4         3      2    1    0   Reset Value
//sfr ADC_CONTR = 0xBC; ADC_POWER SPEED1 SPEED0 ADC_FLAG ADC_START CHS2 CHS1 CHS0 0000,0000 /* AD conversion control register */ 
//sfr ADC_RES = 0xBD; ADCV.9 ADCV.8 ADCV.7 ADCV.6 ADCV.5 ADCV.4 ADCV.3 ADCV.2 0000,0000 /* High 8 bits of A/D conversion result */ 
//sfr ADC_RESL = 0xBE; ADCV.1 ADCV.0 0000,0000 /* Low 2 bits of A/D conversion result */
//sfr ADC_CONTR = 0xBC; //Use MOV operation directly, do not use AND or


//sfr SPCTL = 0xCE; SPI control register
//   7       6       5       4       3       2       1       0    	Reset Value
//	SSIG	SPEN	DORD	MSTR	CPOL	CPHA	SPR1	SPR0		0x00

#define	SPI_SSIG_None()		SPCTL |=  (1<<7)		/* 1: Ignore the SS pin	*/
#define	SPI_SSIG_Enable()	SPCTL &= ~(1<<7)		/* 0: SS pin is used to determine the master and slave	*/
#define	SPI_Enable()		SPCTL |=  (1<<6)		/* 1: Allow SPI	*/
#define	SPI_Disable()		SPCTL &= ~(1<<6)		/* 0: Disable SPI	*/
#define	SPI_LSB_First()		SPCTL |=  (1<<5)		/* 1: LSB goes first	*/
#define	SPI_MSB_First()		SPCTL &= ~(1<<5)		/* 0: MSB first	*/
#define	SPI_Master()		SPCTL |=  (1<<4)		/* 1: Set as host	*/
#define	SPI_Slave()			SPCTL &= ~(1<<4)		/* 0: Set as slave	*/
#define	SPI_SCLK_NormalH()	SPCTL |=  (1<<3)		/* 1: SCLK is high level when idle	*/
#define	SPI_SCLK_NormalL()	SPCTL &= ~(1<<3)		/* 0: SCLK is low level when idle	*/
#define	SPI_PhaseH()		SPCTL |=  (1<<2)		/* 1: 	*/
#define	SPI_PhaseL()		SPCTL &= ~(1<<2)		/* 0: 	*/
#define	SPI_Speed(n)		SPCTL = (SPCTL & ~3) | (n)	/*Set speed, 0 -- fosc/4, 1 -- fosc/8, 2 -- fosc/16, 3 -- fosc/32	*/

//sfr SPDAT  = 0xCF; //SPI Data Register                                                     0000,0000
//sfr SPSTAT = 0xCD; //SPI status register
//   7       6      5   4   3   2   1   0    	Reset Value
//	SPIF	WCOL	-	-	-	-	-	-
#define	SPIF	0x80		/* SPI transfer-complete flag. Write 1 to clear it to 0.*/
#define	WCOL	0x40		/* SPI write-collision flag. Write 1 to clear it to 0.  */

#define		SPI_USE_P12P13P14P15()	P_SW1 &= ~0x0c					/* Switch SPI to P12(SS) P13(MOSI) P14(MISO) P15(SCLK) (power-on default).*/
#define		SPI_USE_P22P23P24P25()	P_SW1 = (P_SW1 & ~0x0c) | 0x04	/* Switch SPI to P22(SS) P23(MOSI) P24(MISO) P25(SCLK).*/
#define		SPI_USE_P74P75P76P77()	P_SW1 = (P_SW1 & ~0x0c) | 0x08	/* Switch SPI to P74(SS) P75(MOSI) P76(MISO) P77(SCLK).*/
#define		SPI_USE_P35P34P33P32()	P_SW1 =  P_SW1 | 0x0C			/* Switch SPI to P35(SS) P34(MOSI) P33(MISO) P32(SCLK).*/


//						             7    6     5     4     3     2     1     0    Reset Value
//sfr I2CCFG = 0xFE80H; ENI2C MSSL MSSPEED[5:0] 0000,0000 /* I2C configuration register */ 
#define		I2C_Function(n)	(n==0?(I2CCFG &= ~0x80):(I2CCFG |= 0x80))	//0: Disable I2C function; 1: Enable I2C function
#define		I2C_ENABLE()	I2CCFG |= 0x80		/* Enable I2C functionality */
#define		I2C_DISABLE()	I2CCFG &= ~0x80		/* Disable I2C functionality */
#define		I2C_Master()	I2CCFG |=  0x40		/* 1: Set as host	*/
#define		I2C_Slave()		I2CCFG &= ~0x40		/* 0: Set as slave	*/
#define		I2C_SetSpeed(n)	I2CCFG = (I2CCFG & ~0x3f) | (n & 0x3f)	/* Bus speed=Fosc/2/(Speed*2+4) */

//						              7    6     5     4     3     2     1     0    Reset Value
//sfr I2CMSCR = 0xFE81H; EMSI - - - MSCMD[3:0] 0000,0000 /* I2C configuration register */ 
#define		I2C_Master_Inturrupt(n)	(n==0?(I2CMSCR &= ~0x80):(I2CMSCR |= 0x80))	//0: Disable I2C function; 1: Enable I2C function

#define	I2C_CMD_None				0
#define	I2C_CMD_Start				1
#define	I2C_CMD_Send				2
#define	I2C_CMD_RACK				3
#define	I2C_CMD_Read				4
#define	I2C_CMD_SACK				5
#define	I2C_CMD_Stop				6
#define	I2C_CMD_RFU1				7
#define	I2C_CMD_RFU2				8
#define	I2C_CMD_Start_Send_RACK		9
#define	I2C_CMD_Send_RACK					10
#define	I2C_CMD_Read_SACK					11
#define	I2C_CMD_Read_SNAK					12

#define		I2C_Command(n)	I2CMSCR = (I2CMSCR & ~0x0f) | (n & 0x0f)	/* host command */

//						              7     6     5     4     3     2      1     0        Reset Value
//sfr I2CMSST = 0xFE82H; MSBUSY MSIF - - - - MSACKI MSACKO 0000,0000 /* I2C host status register */ 

//						              7    6     5     4     3     2     1     0      Reset Value
//sfr I2CMSAUX = 0xFE88H; - - - - - - - WDTA 0000,0000 /* I2C host auxiliary control register */ 
#define		I2C_WDTA_EN()		I2CMSAUX |= 0x01		/* Enable automatic sending */
#define		I2C_WDTA_DIS()	I2CMSAUX &= ~0x01		/* Disable automatic sending */

//						             7     6     5     4     3     2    1    0       Reset Value
//sfr I2CSLCR = 0xFE83H; - ESTAI ERXI ETXI ESTOI - - SLRET 0000,0000 /* I2C slave control register */ 
#define		I2C_ESTAI_EN()		I2CSLCR |= 0x40			/* Enable slave to receive START signal interrupt */
#define		I2C_ESTAI_DIS()		I2CSLCR &= ~0x40		/* Disable slave device from receiving START signal interrupt */
#define		I2C_ERXI_EN()			I2CSLCR |= 0x20			/* Enable the slave to receive 1 byte data interrupt */
#define		I2C_ERXI_DIS()		I2CSLCR &= ~0x20		/* Disable slave receiving 1 byte data interrupt */
#define		I2C_ETXI_EN()			I2CSLCR |= 0x10			/* Enable slave to send 1 byte data interrupt */
#define		I2C_ETXI_DIS()		I2CSLCR &= ~0x10		/* Disable the slave from sending 1 byte data interrupt */
#define		I2C_ESTOI_EN()		I2CSLCR |= 0x08			/* Enable slave to receive STOP signal interrupt */
#define		I2C_ESTOI_DIS()		I2CSLCR &= ~0x08		/* Disable slave device from receiving STOP signal interrupt */
#define		I2C_SLRET()				I2CSLCR |= 0x01			/* Reset slave mode */

//						               7      6     5     4     3     2      1     0        Reset Value
//sfr I2CSLST = 0xFE84H; SLBUSY STAIF RXIF TXIF STOIF - SLACKI SLACKO 0000,0000 /* I2C slave status register */ 

//						              7    6     5     4     3     2     1     0      Reset Value
//sfr I2CSLADR = 0xFE85H; I2CSLADR[7:1] MA 0000,0000 /* I2C slave address register */ 
#define		I2C_Address(n)	I2CSLADR = (I2CSLADR & 0x01) | (n << 1)	/* slave address */
#define		I2C_MATCH_EN()	I2CSLADR &= ~0x01	/* Enable the slave address comparison function and only accept matching addresses. */
#define		I2C_MATCH_DIS()	I2CSLADR |= 0x01	/* Disable slave address comparison function, accept all device addresses */


//						               7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_ENO = 0xFEB1H; ENO4N ENO4P ENO3N ENO3P ENO2N ENO2P ENO1N ENO1P 0000,0000 /* Output enable register */ 
//sfr PWMB_ENO = 0xFEB5H; - ENO8P - ENO7P - ENO6P - ENO5P 0000,0000 /* Output enable register */ 
#define		PWM1P_OUT_EN()	PWMA_ENO |= 0x01	/* Enable PWM1P output */
#define		PWM1P_OUT_DIS()	PWMA_ENO &= ~0x01	/* Disable PWM1P output */
#define		PWM1N_OUT_EN()	PWMA_ENO |= 0x02	/* Enable PWM1N output */
#define		PWM1N_OUT_DIS()	PWMA_ENO &= ~0x02	/* Disable PWM1N output */
#define		PWM2P_OUT_EN()	PWMA_ENO |= 0x04	/* Enable PWM2P output */
#define		PWM2P_OUT_DIS()	PWMA_ENO &= ~0x04	/* Disable PWM2P output */
#define		PWM2N_OUT_EN()	PWMA_ENO |= 0x08	/* Enable PWM2N output */
#define		PWM2N_OUT_DIS()	PWMA_ENO &= ~0x08	/* Disable PWM2N output */
#define		PWM3P_OUT_EN()	PWMA_ENO |= 0x10	/* Enable PWM3P output */
#define		PWM3P_OUT_DIS()	PWMA_ENO &= ~0x10	/* Disable PWM3P output */
#define		PWM3N_OUT_EN()	PWMA_ENO |= 0x20	/* Enable PWM3N output */
#define		PWM3N_OUT_DIS()	PWMA_ENO &= ~0x20	/* Disable PWM3N output */
#define		PWM4P_OUT_EN()	PWMA_ENO |= 0x40	/* Enable PWM3P output */
#define		PWM4P_OUT_DIS()	PWMA_ENO &= ~0x40	/* Disable PWM3P output */
#define		PWM4N_OUT_EN()	PWMA_ENO |= 0x80	/* Enable PWM3N output */
#define		PWM4N_OUT_DIS()	PWMA_ENO &= ~0x80	/* Disable PWM3N output */

#define		PWM5P_OUT_EN()	PWMB_ENO |= 0x01	/* Enable PWM5P output */
#define		PWM5P_OUT_DIS()	PWMB_ENO &= ~0x01	/* Disable PWM5P output */
#define		PWM6P_OUT_EN()	PWMB_ENO |= 0x04	/* Enable PWM6P output */
#define		PWM6P_OUT_DIS()	PWMB_ENO &= ~0x04	/* Disable PWM6P output */
#define		PWM7P_OUT_EN()	PWMB_ENO |= 0x10	/* Enable PWM7P output */
#define		PWM7P_OUT_DIS()	PWMB_ENO &= ~0x10	/* Disable PWM7P output */
#define		PWM8P_OUT_EN()	PWMB_ENO |= 0x40	/* Enable PWM8P output */
#define		PWM8P_OUT_DIS()	PWMB_ENO &= ~0x40	/* Disable PWM8P output */

#define		PWMA_OutChannelSel(n)		PWMA_ENO = n	//Select output channel
#define		PWMB_OutChannelSel(n)		PWMB_ENO = n	//Select output channel

//						              7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_PS = 0xFEB2H; C4PS1 C4PS0 C3PS1 C3PS0 C2PS1 C2PS0 C1PS1 C1PS0 0000,0000 /* Output enable register */ 
//sfr PWMB_PS = 0xFEB6H; C8PS1 C8PS0 C7PS1 C7PS0 C6PS1 C6PS0 C5PS1 C5PS0 0000,0000 /* Output enable register */ 

#define		PWM1_USE_P10P11()		PWMA_PS = (PWMA_PS & ~0x03)					/* PWM channel 1 output pin switches to P10(PWM1P) P11(PWM1N) */ 
#define		PWM1_USE_P20P21()		PWMA_PS = (PWMA_PS & ~0x03) | 0x01	/* PWM channel 1 output pin switches to P20(PWM1P) P21(PWM1N) */ 
#define		PWM1_USE_P60P61()		PWMA_PS = (PWMA_PS & ~0x03) | 0x02	/* PWM channel 1 output pin switches to P60(PWM1P) P61(PWM1N) */ 

#define		PWM2_USE_P12P13()		PWMA_PS = (PWMA_PS & ~0x0C)					/* PWM channel 2 output pin switches to P12/P54(PWM2P) P13(PWM2N) */ 
#define		PWM2_USE_P22P23()		PWMA_PS = (PWMA_PS & ~0x0C) | 0x04	/* PWM channel 2 output pin switches to P22(PWM2P) P23(PWM2N) */ 
#define		PWM2_USE_P62P63()		PWMA_PS = (PWMA_PS & ~0x0C) | 0x08	/* PWM channel 2 output pin switches to P62(PWM2P) P63(PWM2N) */ 

#define		PWM3_USE_P14P15()		PWMA_PS = (PWMA_PS & ~0x30)					/* PWM channel 3 output pin switches to P14(PWM3P) P15(PWM3N) */ 
#define		PWM3_USE_P24P25()		PWMA_PS = (PWMA_PS & ~0x30) | 0x10	/* PWM channel 3 output pin switches to P24(PWM3P) P25(PWM3N) */ 
#define		PWM3_USE_P64P65()		PWMA_PS = (PWMA_PS & ~0x30) | 0x20	/* PWM channel 3 output pin switches to P64(PWM3P) P65(PWM3N) */ 

#define		PWM4_USE_P16P17()		PWMA_PS = (PWMA_PS & ~0xC0)					/* PWM channel 4 output pin switches to P16(PWM4P) P17(PWM4N) */ 
#define		PWM4_USE_P26P27()		PWMA_PS = (PWMA_PS & ~0xC0) | 0x40	/* PWM channel 4 output pin switches to P26(PWM4P) P27(PWM4N) */ 
#define		PWM4_USE_P66P67()		PWMA_PS = (PWMA_PS & ~0xC0) | 0x80	/* PWM channel 4 output pin switches to P66(PWM4P) P67(PWM4N) */ 
#define		PWM4_USE_P34P33()		PWMA_PS = (PWMA_PS | 0xC0)					/* PWM channel 4 output pin switches to P34(PWM4P) P33(PWM4N) */ 

#define		PWM5_USE_P20()			PWMB_PS = (PWMB_PS & ~0x03)					/* PWM channel 5 output pin switches to P20 (PWM5) */ 
#define		PWM5_USE_P17()			PWMB_PS = (PWMB_PS & ~0x03) | 0x01	/* PWM channel 5 output pin switches to P17 (PWM5) */ 
#define		PWM5_USE_P00()			PWMB_PS = (PWMB_PS & ~0x03) | 0x02	/* PWM channel 5 output pin switches to P00 (PWM5) */ 
#define		PWM5_USE_P74()			PWMB_PS = (PWMB_PS | 0x03)					/* PWM channel 5 output pin switches to P74 (PWM5) */ 

#define		PWM6_USE_P21()			PWMB_PS = (PWMB_PS & ~0x0C)					/* PWM channel 6 output pin switches to P21 (PWM6) */ 
#define		PWM6_USE_P54()			PWMB_PS = (PWMB_PS & ~0x0C) | 0x04	/* PWM channel 6 output pin switches to P54 (PWM6) */ 
#define		PWM6_USE_P01()			PWMB_PS = (PWMB_PS & ~0x0C) | 0x08	/* PWM channel 6 output pin switches to P01 (PWM6) */ 
#define		PWM6_USE_P75()			PWMB_PS = (PWMB_PS | 0x0C)					/* PWM channel 6 output pin switches to P75 (PWM6) */ 

#define		PWM7_USE_P22()			PWMB_PS = (PWMB_PS & ~0x30)					/* PWM channel 7 output pin switches to P22 (PWM7) */ 
#define		PWM7_USE_P33()			PWMB_PS = (PWMB_PS & ~0x30) | 0x10	/* PWM channel 7 output pin switches to P33 (PWM7) */ 
#define		PWM7_USE_P02()			PWMB_PS = (PWMB_PS & ~0x30) | 0x20	/* PWM channel 7 output pin switches to P02 (PWM7) */ 
#define		PWM7_USE_P76()			PWMB_PS = (PWMB_PS | 0x30)					/* PWM channel 7 output pin switches to P76 (PWM7) */ 

#define		PWM8_USE_P23()			PWMB_PS = (PWMB_PS & ~0xC0)					/* PWM channel 8 output pin switches to P23 (PWM8) */ 
#define		PWM8_USE_P34()			PWMB_PS = (PWMB_PS & ~0xC0) | 0x40	/* PWM channel 8 output pin switches to P34 (PWM8) */ 
#define		PWM8_USE_P03()			PWMB_PS = (PWMB_PS & ~0xC0) | 0x80	/* PWM channel 8 output pin switches to P03 (PWM8) */ 
#define		PWM8_USE_P77()			PWMB_PS = (PWMB_PS | 0xC0)					/* PWM channel 8 output pin switches to P77 (PWM8) */ 

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_IOAUX = 0xFEB3H; AUX4N AUX4P AUX3N AUX3P AUX2N AUX2P AUX1N AUX1P 0000,0000 /* Output additional enable register */ 
//sfr PWMB_IOAUX = 0xFEB7H; - AUX8P - AUX7P - AUX6P - AUX5P 0000,0000 /* Output additional enable register */ 
#define AUX4N			(1<<7)
#define AUX4P			(1<<6)
#define AUX3N			(1<<5)
#define AUX3P			(1<<4)
#define AUX2N			(1<<3)
#define AUX2P			(1<<2)
#define AUX1N			(1<<1)
#define AUX1P			(1)

#define AUX8P			(1<<6)
#define AUX7P			(1<<4)
#define AUX6P			(1<<2)
#define AUX5P			(1)


//						               7     6     5    4    3    2    1     0    Reset Value
//sfr PWMA_CR1 = 0xFEC0H; ARPEA CMSA1 CMSA0 DIRA OPMA URSA UDISA CENA 0000,0000 /* Control register 1 */ 
//sfr PWMB_CR1 = 0xFEE0H; ARPEB CMSB1 CMSB0 DIRB OPMB URSB UDISB CENB 0000,0000 /* Control register 1 */ 
#define ARPE1			(1<<7)
#define ARPE2			(1<<7)
#define PWMA_AlignMode_Edge()			PWMA_CR1 = (PWMA_CR1 & ~0x60)
#define PWMA_AlignMode_Mid1()			PWMA_CR1 = (PWMA_CR1 & ~0x60) | 0x20
#define PWMA_AlignMode_Mid2()			PWMA_CR1 = (PWMA_CR1 & ~0x60) | 0x40
#define PWMA_AlignMode_Mid3()			PWMA_CR1 = (PWMA_CR1 | 0x60)
#define PWMA_DIR_UP()							PWMA_CR1 &= ~0x10
#define PWMA_DIR_DN()							PWMA_CR1 |= 0x10
#define PWMA_OPMA(n)							(n==0?(PWMA_CR1 &= ~0x08):(PWMA_CR1 |= 0x08))	//Single pulse mode 0: When an update event occurs, the counter does not stop; 1: When the next update event occurs, the CEN bit is cleared and the counter stops
#define PWMA_URSA(n)							(n==0?(PWMA_CR1 &= ~0x04):(PWMA_CR1 |= 0x04))	//Update request source
#define PWMA_UDISA(n)							(n==0?(PWMA_CR1 &= ~0x02):(PWMA_CR1 |= 0x02))	//Disable update 0: generate update (UEV) event; 1: do not generate update event
#define PWMA_CEN_Enable()					PWMA_CR1 |= 0x01		//1: Enable counter
#define PWMA_CEN_Disable()				PWMA_CR1 &= ~0x01		//0: disable counter

#define PWMB_AlignMode_Edge()			PWMB_CR1 = (PWMB_CR1 & ~0x60)
#define PWMB_AlignMode_Mid1()			PWMB_CR1 = (PWMB_CR1 & ~0x60) | 0x20
#define PWMB_AlignMode_Mid2()			PWMB_CR1 = (PWMB_CR1 & ~0x60) | 0x40
#define PWMB_AlignMode_Mid3()			PWMB_CR1 = (PWMB_CR1 | 0x60)
#define PWMB_DIR_UP()							PWMB_CR1 &= ~0x10
#define PWMB_DIR_DN()							PWMB_CR1 |= 0x10
#define PWMB_OPMB(n)							(n==0?(PWMB_CR1 &= ~0x08):(PWMB_CR1 |= 0x08))	//Single pulse mode 0: When an update event occurs, the counter does not stop; 1: When the next update event occurs, the CEN bit is cleared and the counter stops
#define PWMB_URSB(n)							(n==0?(PWMB_CR1 &= ~0x04):(PWMB_CR1 |= 0x04))	//Update request source
#define PWMB_UDISB(n)							(n==0?(PWMB_CR1 &= ~0x02):(PWMB_CR1 |= 0x02))	//Disable update 0: generate update (UEV) event; 1: do not generate update event
#define PWMB_CEN_Enable()					PWMB_CR1 |= 0x01		//1: Enable counter
#define PWMB_CEN_Disable()				PWMB_CR1 &= ~0x01		//0: disable counter


//						               7     6     5    4    3    2    1    0    Reset Value
//sfr PWMA_CR2 = 0xFEC1H; TI1S MMSA2 MMSA1 MMSA0 - COMSA - CCPCA 0000,x0x0 /* Control register 2 */ 
//sfr PWMB_CR2 = 0xFEE1H; TI5S MMSB2 MMSB1 MMSB0 - COMSB - CCPCB 0000,x0xx /* Control register 2 */ 
#define PWM1P_TI1()							PWMA_CR2 &= ~0x80
#define PWM1P2P3P_XOR_TI1()			PWMA_CR2 |= 0x80
#define PWM5P_TI2()							PWMB_CR2 &= ~0x80
#define PWM5P6P7P_XOR_TI2()			PWMB_CR2 |= 0x80

#define MMSn_RESET					0		//reset
#define MMSn_ENABLE					1		//enable
#define MMSn_UPDATE					2		//update
#define MMSn_COMP_TRGO			3		//compare pulse
#define MMSn_OC1REF_TRGO		4		//compare
#define MMSn_OC2REF_TRGO		5		//compare
#define MMSn_OC3REF_TRGO		6		//compare
#define MMSn_OC4REF_TRGO		7		//compare

#define PWMA_MainModeSel(n)		PWMA_CR2 = (PWMA_CR2 & ~0x70) | (n<<4)	//Main mode selection
#define PWMB_MainModeSel(n)		PWMB_CR2 = (PWMB_CR2 & ~0x70) | (n<<4)	//Main mode selection

//0: When CCPC=1, these control bits are updated only when the COMG bit is set to 1
//1: When CCPC=1, these control bits are updated only when the COMG bit is set to 1 or a rising edge of TRGI occurs.
#define PWMA_COMSUpdateCtrl(n)		PWMA_CR2 = (n==0?(PWMA_CR2 &= ~0x04):(PWMA_CR2 |= 0x04))	//Update control selection of capture/compare control bits
#define PWMB_COMSUpdateCtrl(n)		PWMB_CR2 = (n==0?(PWMB_CR2 &= ~0x04):(PWMB_CR2 |= 0x04))	//Update control selection of capture/compare control bits
//0: CCIE, CCINE, CCiP, CCiNP and OCIM bits are not preloaded
//1: The CCIE, CCINE, CCiP, CCiNP and OCIM bits are preloaded; after this bit is set, they are updated only after the COMG bit is set.
#define PWMA_CCPCAPreloaded(n)		PWMA_CR2 = (n==0?(PWMA_CR2 &= ~0x01):(PWMA_CR2 |= 0x01))	//Capture/compare preload control bit (this bit only works for channels with complementary outputs)
#define PWMB_CCPCBPreloaded(n)		PWMA_CR2 = (n==0?(PWMA_CR2 &= ~0x01):(PWMA_CR2 |= 0x01))	//Capture/compare preload control bit (this bit only works for channels with complementary outputs)


//						               7    6    5    4    3    2     1     0    Reset Value
//sfr PWMA_SMCR = 0xFEC2H; MSMA TSA2 TSA1 TSA0 - SMSA2 SMSA1 SMSA0 0000,x000 /* Slave mode control register */ 
//sfr PWMB_SMCR = 0xFEE2H; MSMB TSB2 TSB1 TSB0 - SMSB2 SMSB1 SMSB0 0000,x000 /* Slave mode control register */ 
#define SMCR_TSn_ITR2				2
#define SMCR_TSn_EDGE				4
#define SMCR_TSn_TIMER1			5
#define SMCR_TSn_TIMER2			6
#define SMCR_TSn_ETRF				7

#define PWMA_SMCR_Source(n)		PWMA_SMCR = (PWMA_SMCR & ~0x70) | (n<<4)	//Trigger source selection
#define PWMB_SMCR_Source(n)		PWMB_SMCR = (PWMB_SMCR & ~0x70) | (n<<4)	//Trigger source selection

#define SMCR_SMSA_INSIDE_CLK			0
#define SMCR_SMSA_ENCODER_M1			1
#define SMCR_SMSA_ENCODER_M2			2
#define SMCR_SMSA_ENCODER_M3			3
#define SMCR_SMSA_RESET						4
#define SMCR_SMSA_GATE						5
#define SMCR_SMSA_TRIG						6
#define SMCR_SMSA_EXT_CLK					7

#define PWMA_SMCR_SMS(n)		PWMA_SMCR = (PWMA_SMCR & ~0x07) | (n & 7)	//Clock/trigger/slave mode selection
#define PWMB_SMCR_SMS(n)		PWMB_SMCR = (PWMB_SMCR & ~0x07) | (n & 7)	//Clock/trigger/slave mode selection

//						               7    6    5      4     3     2     1     0     Reset Value
//sfr PWMA_ETR = 0xFEC3H; ETP1 ECE1 ETPS11 ETPS10 ETF13 ETF12 ETF11 ETF10 0000,0000 /* External trigger register */ 
//sfr PWMB_ETR = 0xFEE3H; ETP2 ECE2 ETPS21 ETPS20 ETF23 ETF22 ETF21 ETF20 0000,0000 /* External trigger register */ 

//						               7    6    5      4     3     2     1    0    Reset Value
//sfr PWMA_IER = 0xFEC4H; BIEA TIEA COMIEA CC4IE CC3IE CC2IE CC1IE UIEA 0000,0000 /* Interrupt enable register */ 
//sfr PWMB_IER = 0xFEE4H; BIEB TIEB COMIEB CC8IE CC7IE CC6IE CC5IE UIEB 0000,0000 /* Interrupt enable register */ 
#define PWMA_UIEA_Enable()		PWMA_IER |= 0x01		//1: Allow update interruption
#define PWMA_UIEA_Disable()		PWMA_IER &= ~0x01		//0: Disable update interruption
#define PWMA_CC1IE_Enable()		PWMA_IER |= 0x02		//1: Enable capture/compare interrupts
#define PWMA_CC1IE_Disable()	PWMA_IER &= ~0x02		//0: Disable capture/compare interrupts
#define PWMA_CC2IE_Enable()		PWMA_IER |= 0x04		//1: Enable capture/compare interrupts
#define PWMA_CC2IE_Disable()	PWMA_IER &= ~0x04		//0: Disable capture/compare interrupts
#define PWMA_CC3IE_Enable()		PWMA_IER |= 0x08		//1: Enable capture/compare interrupts
#define PWMA_CC3IE_Disable()	PWMA_IER &= ~0x08		//0: Disable capture/compare interrupts
#define PWMA_CC4IE_Enable()		PWMA_IER |= 0x10		//1: Enable capture/compare interrupts
#define PWMA_CC4IE_Disable()	PWMA_IER &= ~0x10		//0: Disable capture/compare interrupts
#define PWMA_COMIEA_Enable()	PWMA_IER |= 0x20		//1: Allow COM interrupts
#define PWMA_COMIEA_Disable()	PWMA_IER &= ~0x20		//0: Disable COM interrupts
#define PWMA_TIEA_Enable()		PWMA_IER |= 0x40		//1: Allow triggering interrupts
#define PWMA_TIEA_Disable()		PWMA_IER &= ~0x40		//0: Disable interrupt triggering
#define PWMA_BIEA_Enable()		PWMA_IER |= 0x80		//1: Allow brake interrupt
#define PWMA_BIEA_Disable()		PWMA_IER &= ~0x80		//0: Disable brake interrupt

//						               7    6    5      4     3     2     1    0    Reset Value
//sfr PWMA_SR1 = 0xFEC5H; BIF1 TIF1 COMIF1 CC4IF CC3IF CC2IF CC1IF UIF1 0000,0000 /* Status register 1 */ 
//sfr PWMB_SR1 = 0xFEE5H; BIF2 TIF2 COMIF2 CC8IF CC7IF CC6IF CC5IF UIF2 0000,0000 /* Status register 1 */ 
#define UIF1			1
#define CC1IF			(1<<1)
#define CC2IF			(1<<2)
#define CC3IF			(1<<3)
#define CC4IF			(1<<4)
#define COMIF1		(1<<5)
#define TIF1			(1<<6)
#define BIF1			(1<<7)

#define UIF2			1
#define CC5IF			(1<<1)
#define CC6IF			(1<<2)
#define CC7IF			(1<<3)
#define CC8IF			(1<<4)
#define COMIF2		(1<<5)
#define TIF2			(1<<6)
#define BIF2			(1<<7)

//						              7   6   5    4     3     2     1    0   Reset Value
//sfr PWMA_SR2 = 0xFEC6H; - - - CC4OF CC3OF CC2OF CC1OF - xxx0,000x /* Status Register 2 */ 
//sfr PWMB_SR2 = 0xFEE6H; - - - CC8OF CC7OF CC6OF CC5OF - xxx0,000x /* Status Register 2 */ 

//						              7   6    5    4    3    2    1    0   Reset Value
//sfr PWMA_EGR = 0xFEC7H; BG1 TG1 COMG1 CC4G CC3G CC2G CC1G UG1 0000,0000 /* Event generation register */ 
//sfr PWMB_EGR = 0xFEE7H; BG2 TG2 COMG2 CC8G CC7G CC6G CC5G UG2 0000,0000 /* Event generation register */ 

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR1 = 0xFEC8H; OC1CE OC1M2 OC1M1 OC1M0 OC1PE OC1FE CC1S1 CC1S0 0000,0000 /* Capture/compare mode register 1 - channel configured in compare output mode */ 
//sfr PWMB_CCMR1 = 0xFEE8H; OC5CE OC5M2 OC5M1 OC5M0 OC5PE OC5FE CC5S1 CC5S0 0000,0000 /* Capture/Compare Mode Register 1 - Channel configured in compare output mode */ 
#define OCnCE			(1<<7)

#define CCMRn_FREEZE							0x00		//freeze
#define CCMRn_MATCH_VALID					0x10		//Set the output of channel n to a valid level when matching
#define CCMRn_MATCH_INVALID				0x20		//Set the output of channel n to an inactive level when matching
#define CCMRn_ROLLOVER						0x30		//flip
#define CCMRn_FORCE_INVALID				0x40		//Forced to invalid level
#define CCMRn_FORCE_VALID					0x50		//forced to active level
#define CCMRn_PWM_MODE1						0x60		//PWM mode 1
#define CCMRn_PWM_MODE2						0x70		//PWM mode 2

#define PWMA_OC1ModeSet(n)				PWMA_CCMR1 = (PWMA_CCMR1 & ~0x70) | (n)		//Output comparison mode setting
#define PWMB_OC5ModeSet(n)				PWMB_CCMR1 = (PWMB_CCMR1 & ~0x70) | (n)		//Output comparison mode setting

#define PWMA_OC1_ReloadEnable()		PWMA_CCMR1 |= 0x08		//1: Enable the preloading function of OC1PE output comparison
#define PWMA_OC1_RelosdDisable()	PWMA_CCMR1 &= ~0x08		//0: Disable the preload function of OC1PE output comparison
#define PWMB_OC5_ReloadEnable()		PWMB_CCMR1 |= 0x08		//1: Enable the preloading function of OC5PE output comparison
#define PWMB_OC5_RelosdDisable()	PWMB_CCMR1 &= ~0x08		//0: Disable the preload function of OC5PE output comparison

#define PWMA_OC1_FastEnable()			PWMA_CCMR1 |= 0x04		//1: Enable the OC1FE output comparison fast function
#define PWMA_OC1_FastDisable()		PWMA_CCMR1 &= ~0x04		//0: Disable OC1FE output comparison fast function
#define PWMB_OC5_FastEnable()			PWMB_CCMR1 |= 0x04		//1: Enable the OC5FE output comparison fast function
#define PWMB_OC5_FastDisable()		PWMB_CCMR1 &= ~0x04		//0: Disable OC5FE output comparison fast function

#define CCAS_OUTPUT						0x00		//output
#define CCAS_IUTPUT_TI1FP1		0x01		//Input, IC1/IC2/IC3/IC4 are mapped on TI1FP1
#define CCAS_IUTPUT_TI2FP1		0x02		//Input, IC1/IC2/IC3/IC4 are mapped on TI2FP1
#define CCAS_IUTPUT_TRC				0x03		//Input, IC1/IC2/IC3/IC4 are mapped on TRC
#define CCBS_OUTPUT						0x00		//output
#define CCBS_IUTPUT_TI5FP5		0x01		//Input, IC5/IC6/IC7/IC8 mapped on TI5FP5
#define CCBS_IUTPUT_TI6FP5		0x02		//Input, IC5/IC6/IC7/IC8 mapped on TI6FP5
#define CCBS_IUTPUT_TRC				0x03		//Input, IC5/IC6/IC7/IC8 are mapped on TRC

#define PWMA_CC1S_Direction(n)		PWMA_CCMR1 = (PWMA_CCMR1 & ~0x03) | (n)		//Capture/Compare 1 Select. These two bits define the direction of the channel (input/output) and the selection of the input pin.
#define PWMB_CC5S_Direction(n)		PWMB_CCMR1 = (PWMB_CCMR1 & ~0x03) | (n)		//Capture/Compare 5 selections. These two bits define the direction of the channel (input/output) and the selection of the input pin.

//						                 7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR1 = 0xFEC8H; IC1F3 IC1F2 IC1F1 IC1F0 IC1PSC1 IC1PSC0 CC1S1 CC1S0 0000,0000 /* Capture/Compare Mode Register 1 - Channel configured in capture input mode */ 
//sfr PWMB_CCMR1 = 0xFEE8H; IC5F3 IC5F2 IC5F1 IC5F0 IC5PSC1 IC5PSC0 CC5S1 CC5S0 0000,0000 /* Capture/Compare Mode Register 1 - Channel configured in capture input mode */ 

#define ICnF_01_Clock			0
#define ICnF_02_Clock			1
#define ICnF_04_Clock			2
#define ICnF_08_Clock			3
#define ICnF_12_Clock			4
#define ICnF_16_Clock			5
#define ICnF_24_Clock			6
#define ICnF_32_Clock			7
#define ICnF_48_Clock			8
#define ICnF_64_Clock			9
#define ICnF_80_Clock			10
#define ICnF_96_Clock			11
#define ICnF_128_Clock		12
#define ICnF_160_Clock		13
#define ICnF_192_Clock		14
#define ICnF_256_Clock		15

#define PWMA_IC1F_FilterClock(n)	PWMA_CCMR1 = (PWMA_CCMR1 & 0x0F) | (n<<4)		//Input capture 1 filter selection, this bit field defines the sampling frequency and digital filter length of TIn
#define PWMB_IC5F_FilterClock(n)	PWMB_CCMR1 = (PWMB_CCMR1 & 0x0F) | (n<<4)		//Input capture 5 filter selection, this bit field defines the sampling frequency and digital filter length of TIn

#define PWMA_IC1PSC_PrescalerSet(n)		PWMA_CCMR1 = (PWMA_CCMR1 & 0xF3) | ((n&3)<<2)		//Input/capture 1 prescaler, 0~3
#define PWMB_IC5PSC_PrescalerSet(n)		PWMB_CCMR1 = (PWMB_CCMR1 & 0xF3) | ((n&3)<<2)		//Input/capture 5 prescaler, 0~3

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR2 = 0xFEC9H; OC2CE OC2M2 OC2M1 OC2M0 OC2PE OC2FE CC2S1 CC2S0 0000,0000 /* Capture/Compare Mode Register 2 - Channel configured in compare output mode */ 
//sfr PWMB_CCMR2 = 0xFEE9H; OC6CE OC6M2 OC6M1 OC6M0 OC6PE OC6FE CC6S1 CC6S0 0000,0000 /* Capture/Compare Mode Register 2 - Channel configured in compare output mode */ 

#define PWMA_OC2ModeSet(n)				PWMA_CCMR2 = (PWMA_CCMR2 & ~0x70) | (n)		//Output comparison mode setting
#define PWMB_OC6ModeSet(n)				PWMB_CCMR2 = (PWMB_CCMR2 & ~0x70) | (n)		//Output comparison mode setting

#define PWMA_OC2_ReloadEnable()		PWMA_CCMR2 |= 0x08		//1: Enable the preloading function of OC2PE output comparison
#define PWMA_OC2_RelosdDisable()	PWMA_CCMR2 &= ~0x08		//0: Disable the preload function of OC2PE output comparison
#define PWMB_OC6_ReloadEnable()		PWMB_CCMR2 |= 0x08		//1: Enable the preloading function of OC6PE output comparison
#define PWMB_OC6_RelosdDisable()	PWMB_CCMR2 &= ~0x08		//0: Disable the preload function of OC6PE output comparison

#define PWMA_OC2_FastEnable()			PWMA_CCMR2 |= 0x04		//1: Enable the OC2FE output comparison fast function
#define PWMA_OC2_FastDisable()		PWMA_CCMR2 &= ~0x04		//0: Disable OC2FE output comparison fast function
#define PWMB_OC6_FastEnable()			PWMB_CCMR2 |= 0x04		//1: Enable the OC6FE output comparison fast function
#define PWMB_OC6_FastDisable()		PWMB_CCMR2 &= ~0x04		//0: Disable OC6FE output comparison fast function

#define PWMA_CC2S_Direction(n)		PWMA_CCMR2 = (PWMA_CCMR2 & ~0x03) | (n)		//Capture/Compare 2 Select. These two bits define the direction of the channel (input/output) and the selection of the input pin.
#define PWMB_CC6S_Direction(n)		PWMB_CCMR2 = (PWMB_CCMR2 & ~0x03) | (n)		//Capture/Compare 6 Select. These two bits define the direction of the channel (input/output) and the selection of the input pin.

//						                 7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR2 = 0xFEC9H; IC2F3 IC2F2 IC2F1 IC2F0 IC2PSC1 IC2PSC0 CC2S1 CC2S0 0000,0000 /* Capture/Compare Mode Register 2 - Channel configured in capture input mode */ 
//sfr PWMB_CCMR2 = 0xFEE9H; IC6F3 IC6F2 IC6F1 IC6F0 IC6PSC1 IC6PSC0 CC6S1 CC6S0 0000,0000 /* Capture/Compare Mode Register 2 - Channel configured in capture input mode */ 

#define PWMA_IC2F_FilterClock(n)	PWMA_CCMR2 = (PWMA_CCMR2 & 0x0F) | (n<<4)		//Input capture 2 filter selection, this bit field defines the sampling frequency and digital filter length of TIn
#define PWMB_IC6F_FilterClock(n)	PWMB_CCMR2 = (PWMB_CCMR2 & 0x0F) | (n<<4)		//Input capture 6 filter selection, this bit field defines the sampling frequency and digital filter length of TIn

#define PWMA_IC2PSC_PrescalerSet(n)		PWMA_CCMR2 = (PWMA_CCMR2 & 0xF3) | ((n&3)<<2)		//Input/capture 2 prescaler, 0~3
#define PWMB_IC6PSC_PrescalerSet(n)		PWMB_CCMR2 = (PWMB_CCMR2 & 0xF3) | ((n&3)<<2)		//Input/capture 6 prescaler, 0~3

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR3 = 0xFECAH; OC3CE OC3M2 OC3M1 OC3M0 OC3PE OC3FE CC3S1 CC3S0 0000,0000 /* Capture/Compare Mode Register 3 - Channel configured in compare output mode */ 
//sfr PWMB_CCMR3 = 0xFEEAH; OC7CE OC7M2 OC7M1 OC7M0 OC7PE OC7FE CC7S1 CC7S0 0000,0000 /* Capture/Compare Mode Register 3 - Channel configured in compare output mode */ 

#define PWMA_OC3ModeSet(n)				PWMA_CCMR3 = (PWMA_CCMR3 & ~0x70) | (n)		//Output comparison mode setting
#define PWMB_OC7ModeSet(n)				PWMB_CCMR3 = (PWMB_CCMR3 & ~0x70) | (n)		//Output comparison mode setting

#define PWMA_OC3_ReloadEnable()		PWMA_CCMR3 |= 0x08		//1: Enable the preloading function of OC3PE output comparison
#define PWMA_OC3_RelosdDisable()	PWMA_CCMR3 &= ~0x08		//0: Disable the preload function of OC3PE output comparison
#define PWMB_OC7_ReloadEnable()		PWMB_CCMR3 |= 0x08		//1: Enable the preloading function of OC7PE output comparison
#define PWMB_OC7_RelosdDisable()	PWMB_CCMR3 &= ~0x08		//0: Disable the preload function of OC7PE output comparison

#define PWMA_OC3_FastEnable()			PWMA_CCMR3 |= 0x04		//1: Enable the OC3FE output comparison fast function
#define PWMA_OC3_FastDisable()		PWMA_CCMR3 &= ~0x04		//0: Disable OC3FE output comparison fast function
#define PWMB_OC7_FastEnable()			PWMB_CCMR3 |= 0x04		//1: Enable the OC7FE output comparison fast function
#define PWMB_OC7_FastDisable()		PWMB_CCMR3 &= ~0x04		//0: Disable OC7FE output comparison fast function

#define PWMA_CC3S_Direction(n)		PWMA_CCMR3 = (PWMA_CCMR3 & ~0x03) | (n)		//Capture/Compare 3 Selections. These two bits define the direction of the channel (input/output) and the selection of the input pin.
#define PWMB_CC7S_Direction(n)		PWMB_CCMR3 = (PWMB_CCMR3 & ~0x03) | (n)		//Capture/Compare 7 Select. These two bits define the direction of the channel (input/output) and the selection of the input pin.

//						                 7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR3 = 0xFECAH; IC3F3 IC3F2 IC3F1 IC3F0 IC3PSC1 IC3PSC0 CC3S1 CC3S0 0000,0000 /* Capture/Compare Mode Register 3 - Channel configured in capture input mode */ 
//sfr PWMB_CCMR3 = 0xFEEAH; IC7F3 IC7F2 IC7F1 IC7F0 IC7PSC1 IC7PSC0 CC7S1 CC7S0 0000,0000 /* Capture/Compare Mode Register 3 - Channel configured in capture input mode */ 

#define PWMA_IC3F_FilterClock(n)	PWMA_CCMR3 = (PWMA_CCMR3 & 0x0F) | (n<<4)		//Input capture 3 filter selection, this bit field defines the sampling frequency and digital filter length of TIn
#define PWMB_IC7F_FilterClock(n)	PWMB_CCMR3 = (PWMB_CCMR3 & 0x0F) | (n<<4)		//Input capture 7 filter selection, this bit field defines the sampling frequency and digital filter length of TIn

#define PWMA_IC3PSC_PrescalerSet(n)		PWMA_CCMR3 = (PWMA_CCMR3 & 0xF3) | ((n&3)<<2)		//Input/capture 3 prescaler, 0~3
#define PWMB_IC7PSC_PrescalerSet(n)		PWMB_CCMR3 = (PWMB_CCMR3 & 0xF3) | ((n&3)<<2)		//Input/capture 7 prescaler, 0~3

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR4 = 0xFECBH; OC4CE OC4M2 OC4M1 OC4M0 OC4PE OC4FE CC4S1 CC4S0 0000,0000 /* Capture/Compare Mode Register 4 - Channel configured in compare output mode */ 
//sfr PWMB_CCMR4 = 0xFEEBH; OC8CE OC8M2 OC8M1 OC8M0 OC8PE OC8FE CC8S1 CC8S0 0000,0000 /* Capture/Compare Mode Register 4 - Channel configured in compare output mode */ 

#define PWMA_OC4ModeSet(n)				PWMA_CCMR4 = (PWMA_CCMR4 & ~0x70) | (n)		//Output comparison mode setting
#define PWMB_OC8ModeSet(n)				PWMB_CCMR4 = (PWMB_CCMR4 & ~0x70) | (n)		//Output comparison mode setting

#define PWMA_OC4_ReloadEnable()		PWMA_CCMR4 |= 0x08		//1: Enable the preloading function of OC4PE output comparison
#define PWMA_OC4_RelosdDisable()	PWMA_CCMR4 &= ~0x08		//0: Disable the preload function of OC4PE output comparison
#define PWMB_OC8_ReloadEnable()		PWMB_CCMR4 |= 0x08		//1: Enable the preloading function of OC8PE output comparison
#define PWMB_OC8_RelosdDisable()	PWMB_CCMR4 &= ~0x08		//0: Disable the preload function of OC8PE output comparison

#define PWMA_OC4_FastEnable()			PWMA_CCMR4 |= 0x04		//1: Enable the OC4FE output comparison fast function
#define PWMA_OC4_FastDisable()		PWMA_CCMR4 &= ~0x04		//0: Disable OC4FE output comparison fast function
#define PWMB_OC8_FastEnable()			PWMB_CCMR4 |= 0x04		//1: Enable the OC8FE output comparison fast function
#define PWMB_OC8_FastDisable()		PWMB_CCMR4 &= ~0x04		//0: Disable OC8FE output comparison fast function

#define PWMA_CC4S_Direction(n)		PWMA_CCMR4 = (PWMA_CCMR4 & ~0x03) | (n)		//Capture/Compare 4 Select. These two bits define the direction of the channel (input/output) and the selection of the input pin.
#define PWMB_CC8S_Direction(n)		PWMB_CCMR4 = (PWMB_CCMR4 & ~0x03) | (n)		//Capture/Compare 8 Select. These two bits define the direction of the channel (input/output) and the selection of the input pin.

//						                 7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR4 = 0xFECBH; IC4F3 IC4F2 IC4F1 IC4F0 IC4PSC1 IC4PSC0 CC4S1 CC4S0 0000,0000 /* Capture/Compare Mode Register 4 - Channel configured in capture input mode */ 
//sfr PWMB_CCMR4 = 0xFEEBH; IC8F3 IC8F2 IC8F1 IC8F0 IC8PSC1 IC8PSC0 CC8S1 CC8S0 0000,0000 /* Capture/Compare Mode Register 4 - Channel configured in capture input mode */ 

#define PWMA_IC4F_FilterClock(n)	PWMA_CCMR4 = (PWMA_CCMR4 & 0x0F) | (n<<4)		//Input capture 4 filter selection, this bit field defines the sampling frequency and digital filter length of TIn
#define PWMB_IC8F_FilterClock(n)	PWMB_CCMR4 = (PWMB_CCMR4 & 0x0F) | (n<<4)		//Input capture 8 filter selection, this bit field defines the sampling frequency and digital filter length of TIn

#define PWMA_IC4PSC_PrescalerSet(n)		PWMA_CCMR4 = (PWMA_CCMR4 & 0xF3) | ((n&3)<<2)		//Input/capture 4 prescaler, 0~3
#define PWMB_IC8PSC_PrescalerSet(n)		PWMB_CCMR4 = (PWMB_CCMR4 & 0xF3) | ((n&3)<<2)		//Input/capture 8 prescaler, 0~3

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCER1 = 0xFECCH; CC2NP CC2NE CC2P CC2E CC1NP CC1NE CC1P CC1E 0000,0000 /* Capture/compare enable register 1 */ 
//sfr PWMB_CCER1 = 0xFEECH; - - CC6P CC6E - - CC5P CC5E 0000,0000 /* Capture/compare enable register 1 */ 

#define PWMA_CCER1_Disable()			PWMA_CCER1 = 0x00			//Disable all input capture/compare outputs
#define PWMA_CC1E_Enable()				PWMA_CCER1 |= 0x01		//1: Enable input capture/compare output
#define PWMA_CC1E_Disable()				PWMA_CCER1 &= ~0x01		//0: Disable input capture/compare output
#define PWMA_CC1P_LowValid()			PWMA_CCER1 |= 0x02		//1: Active low level
#define PWMA_CC1P_HighValid()			PWMA_CCER1 &= ~0x02		//0: High level is valid
#define PWMA_CC1P_CaptureRise()		PWMA_CCER1 |= 0x02		//1: Capture occurs on the falling edge of TI1F or TI2F
#define PWMA_CC1P_CaptureFall()		PWMA_CCER1 &= ~0x02		//0: Capture occurs on the rising edge of TI1F or TI2F
#define PWMA_CC1NE_Enable()				PWMA_CCER1 |= 0x04		//1: Enable comparison output
#define PWMA_CC1NE_Disable()			PWMA_CCER1 &= ~0x04		//0: Disable comparison output
#define PWMA_CC1NP_LowValid()			PWMA_CCER1 |= 0x08		//1: Active low level
#define PWMA_CC1NP_HighValid()		PWMA_CCER1 &= ~0x08		//0: High level is valid

#define PWMA_CC2E_Enable()				PWMA_CCER1 |= 0x10		//1: Enable input capture/compare output
#define PWMA_CC2E_Disable()				PWMA_CCER1 &= ~0x10		//0: Disable input capture/compare output
#define PWMA_CC2P_LowValid()			PWMA_CCER1 |= 0x20		//1: Active low level
#define PWMA_CC2P_HighValid()			PWMA_CCER1 &= ~0x20		//0: High level is valid
#define PWMA_CC2P_CaptureRise()		PWMA_CCER1 |= 0x20		//1: Capture occurs on the falling edge of TI1F or TI2F
#define PWMA_CC2P_CaptureFall()		PWMA_CCER1 &= ~0x20		//0: Capture occurs on the rising edge of TI1F or TI2F
#define PWMA_CC2NE_Enable()				PWMA_CCER1 |= 0x40		//1: Enable comparison output
#define PWMA_CC2NE_Disable()			PWMA_CCER1 &= ~0x40		//0: Disable comparison output
#define PWMA_CC2NP_LowValid()			PWMA_CCER1 |= 0x80		//1: Active low level
#define PWMA_CC2NP_HighValid()		PWMA_CCER1 &= ~0x80		//0: High level is valid

#define PWMB_CCER1_Disable()			PWMB_CCER1 = 0x00			//Disable all input capture/compare outputs
#define PWMB_CC5E_Enable()				PWMB_CCER1 |= 0x01		//1: Enable input capture/compare output
#define PWMB_CC5E_Disable()				PWMB_CCER1 &= ~0x01		//0: Disable input capture/compare output
#define PWMB_CC5P_LowValid()			PWMB_CCER1 |= 0x02		//1: Active low level
#define PWMB_CC5P_HighValid()			PWMB_CCER1 &= ~0x02		//0: High level is valid
#define PWMB_CC5P_CaptureRise()		PWMB_CCER1 |= 0x02		//1: Capture occurs on the falling edge of TI1F or TI2F
#define PWMB_CC5P_CaptureFall()		PWMB_CCER1 &= ~0x02		//0: Capture occurs on the rising edge of TI1F or TI2F

#define PWMB_CC6E_Enable()				PWMB_CCER1 |= 0x10		//1: Enable input capture/compare output
#define PWMB_CC6E_Disable()				PWMB_CCER1 &= ~0x10		//0: Disable input capture/compare output
#define PWMB_CC6P_LowValid()			PWMB_CCER1 |= 0x20		//1: Active low level
#define PWMB_CC6P_HighValid()			PWMB_CCER1 &= ~0x20		//0: High level is valid
#define PWMB_CC6P_CaptureRise()		PWMB_CCER1 |= 0x20		//1: Capture occurs on the falling edge of TI1F or TI2F
#define PWMB_CC6P_CaptureFall()		PWMB_CCER1 &= ~0x20		//0: Capture occurs on the rising edge of TI1F or TI2F

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCER2 = 0xFECDH; CC4NP CC4NE CC4P CC4E CC3NP CC3NE CC3P CC3E 0000,0000 /* Capture/compare enable register 2 */ 
//sfr PWMB_CCER2 = 0xFEEDH; - - CC8P CC8E - - CC7P CC7E 0000,0000 /* Capture/compare enable register 2 */ 

#define PWMA_CCER2_Disable()			PWMA_CCER2 = 0x00			//Disable all input capture/compare outputs
#define PWMA_CC3E_Enable()				PWMA_CCER2 |= 0x01		//1: Enable input capture/compare output
#define PWMA_CC3E_Disable()				PWMA_CCER2 &= ~0x01		//0: Disable input capture/compare output
#define PWMA_CC3P_LowValid()			PWMA_CCER2 |= 0x02		//1: Active low level
#define PWMA_CC3P_HighValid()			PWMA_CCER2 &= ~0x02		//0: High level is valid
#define PWMA_CC3P_CaptureRise()		PWMA_CCER2 |= 0x02		//1: Capture occurs on the falling edge of TI1F or TI2F
#define PWMA_CC3P_CaptureFall()		PWMA_CCER2 &= ~0x02		//0: Capture occurs on the rising edge of TI1F or TI2F
#define PWMA_CC3NE_Enable()				PWMA_CCER2 |= 0x04		//1: Enable comparison output
#define PWMA_CC3NE_Disable()			PWMA_CCER2 &= ~0x04		//0: Disable comparison output
#define PWMA_CC3NP_LowValid()			PWMA_CCER2 |= 0x08		//1: Active low level
#define PWMA_CC3NP_HighValid()		PWMA_CCER2 &= ~0x08		//0: High level is valid

#define PWMA_CC4E_Enable()				PWMA_CCER2 |= 0x10		//1: Enable input capture/compare output
#define PWMA_CC4E_Disable()				PWMA_CCER2 &= ~0x10		//0: Disable input capture/compare output
#define PWMA_CC4P_LowValid()			PWMA_CCER2 |= 0x20		//1: Active low level
#define PWMA_CC4P_HighValid()			PWMA_CCER2 &= ~0x20		//0: High level is valid
#define PWMA_CC4P_CaptureRise()		PWMA_CCER2 |= 0x20		//1: Capture occurs on the falling edge of TI1F or TI2F
#define PWMA_CC4P_CaptureFall()		PWMA_CCER2 &= ~0x20		//0: Capture occurs on the rising edge of TI1F or TI2F
#define PWMA_CC4NE_Enable()				PWMA_CCER2 |= 0x40		//1: Enable comparison output
#define PWMA_CC4NE_Disable()			PWMA_CCER2 &= ~0x40		//0: Disable comparison output
#define PWMA_CC4NP_LowValid()			PWMA_CCER2 |= 0x80		//1: Active low level
#define PWMA_CC4NP_HighValid()		PWMA_CCER2 &= ~0x80		//0: High level is valid

#define PWMB_CCER2_Disable()			PWMB_CCER2 = 0x00			//Disable all input capture/compare outputs
#define PWMB_CC7E_Enable()				PWMB_CCER2 |= 0x01		//1: Enable input capture/compare output
#define PWMB_CC7E_Disable()				PWMB_CCER2 &= ~0x01		//0: Disable input capture/compare output
#define PWMB_CC7P_LowValid()			PWMB_CCER2 |= 0x02		//1: Active low level
#define PWMB_CC7P_HighValid()			PWMB_CCER2 &= ~0x02		//0: High level is valid
#define PWMB_CC7P_CaptureRise()		PWMB_CCER2 |= 0x02		//1: Capture occurs on the falling edge of TI1F or TI2F
#define PWMB_CC7P_CaptureFall()		PWMB_CCER2 &= ~0x02		//0: Capture occurs on the rising edge of TI1F or TI2F

#define PWMB_CC8E_Enable()				PWMB_CCER2 |= 0x10		//1: Enable input capture/compare output
#define PWMB_CC8E_Disable()				PWMB_CCER2 &= ~0x10		//0: Disable input capture/compare output
#define PWMB_CC8P_LowValid()			PWMB_CCER2 |= 0x20		//1: Active low level
#define PWMB_CC8P_HighValid()			PWMB_CCER2 &= ~0x20		//0: High level is valid
#define PWMB_CC8P_CaptureRise()		PWMB_CCER2 |= 0x20		//1: Capture occurs on the falling edge of TI1F or TI2F
#define PWMB_CC8P_CaptureFall()		PWMB_CCER2 &= ~0x20		//0: Capture occurs on the rising edge of TI1F or TI2F

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CNTRH = 0xFECEH; CNT1[15:8] 0000,0000 /* High 8 bits of counter */ 
//sfr PWMB_CNTRH = 0xFEEEH; CNT2[15:8] 0000,0000 /* High 8 bits of counter */ 
//sfr PWMA_CNTRL = 0xFECFH; CNT1[7:0] 0000,0000 /* Low 8 bits of counter */ 
//sfr PWMB_CNTRL = 0xFEEFH; CNT2[7:0] 0000,0000 /* Low 8 bits of counter */ 

#define PWMA_Counter(n)						PWMA_CNTR = n		//Counter settings
#define PWMB_Counter(n)						PWMB_CNTR = n		//Counter settings

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_PSCRH = 0xFED0H; PSC1[15:8] 0000,0000 /* High 8 bits of prescaler */ 
//sfr PWMB_PSCRH = 0xFEF0H; PSC2[15:8] 0000,0000 /* High 8 bits of prescaler */ 
//sfr PWMA_PSCRL = 0xFED1H; PSC1[7:0] 0000,0000 /* Lower 8 bits of prescaler */ 
//sfr PWMB_PSCRL = 0xFEF1H; PSC2[7:0] 0000,0000 /* Lower 8 bits of prescaler */ 

#define PWMA_Prescaler(n)					PWMA_PSCR = n		//Prescaler settings
#define PWMB_Prescaler(n)					PWMB_PSCR = n		//Prescaler settings

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_ARRH = 0xFED2H; ARR1[15:8] 0000,0000 /* High 8 bits of automatic reload register */ 
//sfr PWMB_ARRH = 0xFEF2H; ARR2[15:8] 0000,0000 /* High 8 bits of automatic reload register */ 
//sfr PWMA_ARRL = 0xFED3H; ARR1[7:0] 0000,0000 /* Lower 8 bits of auto-reload register */ 
//sfr PWMB_ARRL = 0xFEF3H; ARR2[7:0] 0000,0000 /* Lower 8 bits of auto-reload register */ 

#define PWMA_AutoReload(n)				PWMA_ARR = n		//Auto-reload register settings
#define PWMB_AutoReload(n)				PWMB_ARR = n		//Auto-reload register settings

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_RCR = 0xFED4H; REP1[7:0] 0000,0000 /* Repeat counter register */ 
//sfr PWMB_RCR = 0xFEF4H; REP2[7:0] 0000,0000 /* Repeat counter register */ 

#define PWMA_ReCounter(n)					PWMA_RCR = n		//Repeat counter register settings
#define PWMB_ReCounter(n)					PWMB_RCR = n		//Repeat counter register settings

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR1H = 0xFED5H; CCR1[15:8] 0000,0000 /* Capture/compare register 1 high 8 bits */ 
//sfr PWMB_CCR5H = 0xFEF5H; CCR5[15:8] 0000,0000 /* Capture/compare register 1 high 8 bits */ 
//sfr PWMA_CCR1L = 0xFED6H; CCR1[7:0] 0000,0000 /* Capture/compare register 1 lower 8 bits */ 
//sfr PWMB_CCR5L = 0xFEF6H; CCR5[7:0] 0000,0000 /* Capture/compare register 1 lower 8 bits */ 

#define PWMA_Duty1(n)							PWMA_CCR1 = n		//Capture/Compare Register 1 Settings
#define PWMB_Duty5(n)							PWMB_CCR5 = n		//Capture/Compare Register 1 Settings

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR2H = 0xFED7H; CCR2[15:8] 0000,0000 /* Capture/compare register 2 high 8 bits */ 
//sfr PWMB_CCR6H = 0xFEF7H; CCR6[15:8] 0000,0000 /* Capture/compare register 2 high 8 bits */ 
//sfr PWMA_CCR2L = 0xFED8H; CCR2[7:0] 0000,0000 /* Capture/compare register 2 lower 8 bits */ 
//sfr PWMB_CCR6L = 0xFEF8H; CCR6[7:0] 0000,0000 /* Capture/compare register 2 lower 8 bits */ 

#define PWMA_Duty2(n)							PWMA_CCR2 = n		//Capture/Compare Register 2 Settings
#define PWMB_Duty6(n)							PWMB_CCR6 = n		//Capture/Compare Register 2 Settings

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR3H = 0xFED9H; CCR3[15:8] 0000,0000 /* Capture/compare register 3 high 8 bits */ 
//sfr PWMB_CCR7H = 0xFEF9H; CCR7[15:8] 0000,0000 /* Capture/compare register 3 high 8 bits */ 
//sfr PWMA_CCR3L = 0xFEDAH; CCR3[7:0] 0000,0000 /* Capture/compare register 3 lower 8 bits */ 
//sfr PWMB_CCR7L = 0xFEFAH; CCR7[7:0] 0000,0000 /* Capture/compare register 3 lower 8 bits */ 

#define PWMA_Duty3(n)							PWMA_CCR3 = n		//Capture/Compare Register 3 Settings
#define PWMB_Duty7(n)							PWMB_CCR7 = n		//Capture/Compare Register 3 Settings

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR4H = 0xFEDBH; CCR4[15:8] 0000,0000 /* Capture/compare register 4 high 8 bits */ 
//sfr PWMB_CCR8H = 0xFEFBH; CCR8[15:8] 0000,0000 /* Capture/compare register 4 high 8 bits */ 
//sfr PWMA_CCR4L = 0xFEDCH; CCR4[7:0] 0000,0000 /* Capture/compare register 4 lower 8 bits */ 
//sfr PWMB_CCR8L = 0xFEFCH; CCR8[7:0] 0000,0000 /* Capture/compare register 4 lower 8 bits */ 

#define PWMA_Duty4(n)							PWMA_CCR4 = n		//Capture/Compare Register 4 Settings
#define PWMB_Duty8(n)							PWMB_CCR8 = n		//Capture/Compare Register 4 Settings

//						              7    6    5    4     3     2     1      0     Reset Value
//sfr PWMA_BRK = 0xFEDDH; MOE1 AOE1 BKP1 BKE1 OSSR1 OSSI1 LOCK11 LOCK10 0000,0000 /* Brake register */ 
//sfr PWMB_BRK = 0xFEFDH; MOE2 AOE2 BKP2 BKE2 OSSR2 OSSI2 LOCK21 LOCK20 0000,0000 /* Brake register */ 

#define PWMA_BrakeOutputEnable()				PWMA_BRK |= 0x80		//1: Main output enabled
#define PWMA_BrakeOutputDisable()				PWMA_BRK &= ~0x80		//0: Main output disabled
#define PWMB_BrakeOutputEnable()				PWMB_BRK |= 0x80		//1: Main output enabled
#define PWMB_BrakeOutputDisable()				PWMB_BRK &= ~0x80		//0: Main output disabled

#define PWMA_BrakeAutoOutputEnable()		PWMA_BRK |= 0x40		//1: Automatic output enabled
#define PWMA_BrakeAutoOutputDisable()		PWMA_BRK &= ~0x40		//0: Automatic output disabled
#define PWMB_BrakeAutoOutputEnable()		PWMB_BRK |= 0x40		//1: Automatic output enabled
#define PWMB_BrakeAutoOutputDisable()		PWMB_BRK &= ~0x40		//0: Automatic output disabled

#define PWMA_BrakeHighValid()						PWMA_BRK |= 0x20		//1: Brake input is active at high level
#define PWMA_BrakeLowValid()						PWMA_BRK &= ~0x20		//0: Brake input is active at low level
#define PWMB_BrakeHighValid()						PWMB_BRK |= 0x20		//1: Brake input is active at high level
#define PWMB_BrakeLowValid()						PWMB_BRK &= ~0x20		//0: Brake input is active at low level

#define PWMA_BrakeEnable()							PWMA_BRK |= 0x10		//1: Enable brake input
#define PWMA_BrakeDisable()							PWMA_BRK &= ~0x10		//0: Disable brake input
#define PWMB_BrakeEnable()							PWMB_BRK |= 0x10		//1: Enable brake input
#define PWMB_BrakeDisable()							PWMB_BRK &= ~0x10		//0: Disable brake input

//"Off state" selection in running mode
#define PWMA_OSSRnEnable()							PWMA_BRK |= 0x08		//1: When PWM is not working, once CCiE=1 or CCiNE=1, first enable OC/OCN and output an invalid level, and then set OC/OCN enable output signal=1
#define PWMA_OSSRnDisable()							PWMA_BRK &= ~0x08		//0: When PWM is not working, OC/OCN output is disabled (OC/OCN enable output signal = 0)
#define PWMB_OSSRnEnable()							PWMB_BRK |= 0x08		//1: When PWM is not working, once CCiE=1 or CCiNE=1, first enable OC/OCN and output an invalid level, and then set OC/OCN enable output signal=1
#define PWMB_OSSRnDisable()							PWMB_BRK &= ~0x08		//0: When PWM is not working, OC/OCN output is disabled (OC/OCN enable output signal = 0)
//"Off state" selection in idle mode
#define PWMA_OSSInEnable()							PWMA_BRK |= 0x04		//1: When PWM is not working, once CCiE=1 or CCiNE=1, OC/OCN first outputs its idle level, and then OC/OCN enable output signal=1
#define PWMA_OSSInDisable()							PWMA_BRK &= ~0x04		//0: When PWM is not working, OC/OCN output is disabled (OC/OCN enable output signal = 0)
#define PWMB_OSSInEnable()							PWMB_BRK |= 0x04		//1: When PWM is not working, once CCiE=1 or CCiNE=1, OC/OCN first outputs its idle level, and then OC/OCN enable output signal=1
#define PWMB_OSSInDisable()							PWMB_BRK &= ~0x04		//0: When PWM is not working, OC/OCN output is disabled (OC/OCN enable output signal = 0)

#define PWMn_lock_L0			0		//Register writes are not protected
#define PWMn_lock_L1			1		//Lock level 1: The BKE, BKP, AOE bits of the PWMn_BKR register and the OISI bit of the PWMn_OISR register cannot be written to
#define PWMn_lock_L2			2		//Lock Level 2: Bits in Lock Level 1 cannot be written to, nor can the CC polarity bits and OSSR/OSSI bits be written to
#define PWMn_lock_L3			3		//Lock Level 3: Bits in Lock Level 2 cannot be written to, nor can the CC control bits be written to

#define PWMA_LockLevelSet(n)						PWMA_BRK = (PWMA_BRK & ~0x03) | (n&3)		//Lock settings. This bit provides write protection against software errors.
#define PWMB_LockLevelSet(n)						PWMB_BRK = (PWMB_BRK & ~0x03) | (n&3)		//Lock settings. This bit provides write protection against software errors.

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_DTR = 0xFEDEH; DTG1[7:0] 0000,0000 /* Dead time register */ 
//sfr PWMB_DTR = 0xFEFEH; DTG2[7:0] 0000,0000 /* Dead time register */ 

//DTGn[7:5] = 000~011: Dead time = DTGn[7:0] * tCK_PSC
//DTGn[7:5] = 100~101: Dead time = (64 + DTGn[6:0]) * 2 * tCK_PSC
//DTGn[7:5] = 110: Dead time = (32 + DTGn[5:0]) * 8 * tCK_PSC
//DTGn[7:5] = 111: Dead time = (32 + DTGn[4:0]) * 16 * tCK_PSC

#define PWMA_DeadTime(n)					PWMA_DTR = n		//Dead-time generator settings
#define PWMB_DeadTime(n)					PWMB_DTR = n		//Dead-time generator settings

//						                7    6     5    4     3    2     1    0    Reset Value
//sfr PWMA_OISR = 0xFEDFH; OIS4N OIS4 OIS3N OIS3 OIS2N OIS2 OIS1N OIS1 0000,0000 /* Output idle status register */ 
//sfr PWMB_OISR = 0xFEFFH; - OIS8 - OIS7 - OIS6 - OIS5 x0x0,x0x0 /* Output idle status register */ 

#define PWMA_OC1_OUT_0()					PWMA_OISR &= ~0x01	/* When MOE=0, if OC1N is enabled, after a dead time, OC1=0 */
#define PWMA_OC1_OUT_1()					PWMA_OISR |= 0x01		/* When MOE=0, if OC1N is enabled, after a dead time, OC1=1 */
#define PWMA_OC1N_OUT_0()					PWMA_OISR &= ~0x02	/* When MOE=0, after a dead time, OC1N=0 */
#define PWMA_OC1N_OUT_1()					PWMA_OISR |= 0x02		/* When MOE=0, after a dead time, OC1N=1 */
#define PWMA_OC2_OUT_0()					PWMA_OISR &= ~0x04	/* When MOE=0, if OC2N is enabled, OC2=0 after a dead time */
#define PWMA_OC2_OUT_1()					PWMA_OISR |= 0x04		/* When MOE=0, if OC2N is enabled, after a dead time, OC2=1 */
#define PWMA_OC2N_OUT_0()					PWMA_OISR &= ~0x08	/* When MOE=0, after a dead time, OC2N=0 */
#define PWMA_OC2N_OUT_1()					PWMA_OISR |= 0x08		/* When MOE=0, after a dead time, OC2N=1 */
#define PWMA_OC3_OUT_0()					PWMA_OISR &= ~0x10	/* When MOE=0, if OC3N is enabled, after a dead time, OC3=0 */
#define PWMA_OC3_OUT_1()					PWMA_OISR |= 0x10		/* When MOE=0, if OC3N is enabled, after a dead time, OC3=1 */
#define PWMA_OC3N_OUT_0()					PWMA_OISR &= ~0x20	/* When MOE=0, after a dead time, OC3N=0 */
#define PWMA_OC3N_OUT_1()					PWMA_OISR |= 0x20		/* When MOE=0, after a dead time, OC3N=1 */
#define PWMA_OC4_OUT_0()					PWMA_OISR &= ~0x40	/* When MOE=0, if OC4N is enabled, after a dead time, OC4=0 */
#define PWMA_OC4_OUT_1()					PWMA_OISR |= 0x40		/* When MOE=0, if OC4N is enabled, after a dead time, OC4=1 */
#define PWMA_OC4N_OUT_0()					PWMA_OISR &= ~0x80	/* When MOE=0, after a dead time, OC4N=0 */
#define PWMA_OC4N_OUT_1()					PWMA_OISR |= 0x80		/* When MOE=0, after a dead time, OC4N=1 */

#define PWMB_OC5_OUT_0()					PWMB_OISR &= ~0x01	/* When MOE=0, after a dead time, OC5=0 */
#define PWMB_OC5_OUT_1()					PWMB_OISR |= 0x01		/* When MOE=0, after a dead time, OC5=1 */
#define PWMB_OC6_OUT_0()					PWMB_OISR &= ~0x04	/* When MOE=0, after a dead time, OC6=0 */
#define PWMB_OC6_OUT_1()					PWMB_OISR |= 0x04		/* When MOE=0, after a dead time, OC6=1 */
#define PWMB_OC7_OUT_0()					PWMB_OISR &= ~0x10	/* When MOE=0, after a dead time, OC7=0 */
#define PWMB_OC7_OUT_1()					PWMB_OISR |= 0x10		/* When MOE=0, after a dead time, OC7=1 */
#define PWMB_OC8_OUT_0()					PWMB_OISR &= ~0x40	/* When MOE=0, after a dead time, OC8=0 */
#define PWMB_OC8_OUT_1()					PWMB_OISR |= 0x40		/* When MOE=0, after a dead time, OC8=1 */




/*
;PCA_PWMn:    7       6     5   4   3   2     1       0
;			EBSn_1	EBSn_0	-	-	-	-	EPCnH	EPCnL
;B5-B2: reserved
;B1(EPCnH):	Forms a 9-bit value with CCAPnH in PWM mode.
;B0(EPCnL):	Forms a 9-bit value with CCAPnL in PWM mode.
*/
#define		PWM0_NORMAL()	PCA_PWM0 &= ~3					/* PWM0 normal output (default)	*/
#define		PWM0_OUT_0()	PCA_PWM0 |=  3, CCAP0H = 0xff	/* PWM0 always outputs 0		*/
#define		PWM0_OUT_1()	PCA_PWM0 &= 0xc0, CCAP0H = 0	/* PWM0 always outputs 1		*/

#define		PWM1_NORMAL()	PCA_PWM1 &= ~3					/* PWM1 normal output (default)	*/
#define		PWM1_OUT_0()	PCA_PWM1 |=  3, CCAP1H = 0xff	/* PWM1 always outputs 0		*/
#define		PWM1_OUT_1()	PCA_PWM1 &= 0xc0, CCAP1H = 0	/* PWM1 always outputs 1		*/

#define		PWM2_NORMAL()	PCA_PWM2 &= ~3					/* PWM2 normal output (default)	*/
#define		PWM2_OUT_0()	PCA_PWM2 |=  3, CCAP2H = 0xff	/* PWM2 always outputs 0		*/
#define		PWM2_OUT_1()	PCA_PWM2 &= 0xc0, CCAP2H = 0	/* PWM2 always outputs 1		*/

//#define PWM3_NORMAL() PCA_PWM3 &= ~3 /* PWM3 normal output (default) */
//#define PWM3_OUT_0() PCA_PWM3 |= 3, CCAP3H = 0xff /* PWM3 always outputs 0 */
//#define PWM3_OUT_1() PCA_PWM3 &= 0xc0, CCAP3H = 0 /* PWM3 always outputs 1 */


//						7     6     5     4     3     2     1     0     Reset Value
//sfr CCON = 0xD8; CF CR - - CCF3 CCF2 CCF1 CCF0 00xx,xx00 //PCA control register.
__sbit __at(0xD8) CCF0;	/* PCA module 0 interrupt flag; set by hardware and clear to 0 in software.	*/
__sbit __at(0xD9) CCF1;	/* PCA module 1 interrupt flag; set by hardware and clear to 0 in software.	*/
__sbit __at(0xDA) CCF2;	/* PCA module 2 interrupt flag; set by hardware and clear to 0 in software.	*/
//sbit CCF3  = CCON^3;	/* PCA module 3 interrupt flag; set by hardware and clear to 0 in software.	*/
__sbit __at(0xDE) CR;	/* 1: Enable PCA counter; software must clear it to 0.*/
__sbit __at(0xDF) CF;	/* PCA counter overflow (CH and CL change from FFFFH to 0000H) flag. After PCA counter overflow, hardware sets the flag; software must clear it to 0.*/

//					 7     6     5     4     3     2     1     0    Reset Value
//sfr CMOD = 0xD9; CIDL - - - CPS2 CPS1 CPS0 ECF 0xxx,0000 //PCA working mode register.
#define PCA_IDLE_OFF()		CMOD |=  (1<<7)				/* IDLE state PCA stops counting.	*/
#define PCA_IDLE_ON()		CMOD &= ~(1<<7)				/* IDLE state PCA continues counting.	*/
#define PCA_CLK_12T()		CMOD &= ~0x0E				/* PCA counting pulse selection fosc/12	*/
#define PCA_CLK_2T()		CMOD = (CMOD & ~0x0E) + 2	/* PCA counting pulse selection fosc/2	*/
#define PCA_CLK_T0()		CMOD = (CMOD & ~0x0E) + 4	/* The PCA count pulse selects the Timer0 interrupt. Timer0 can be set to work in 12T or 1T mode through the AUXR register.	*/
#define PCA_CLK_ECI()		CMOD = (CMOD & ~0x0E) + 6	/* The PCA counting pulse selects the external clock input from the ECI/P3.4 pin, with a maximum of fosc/2.	*/
#define PCA_CLK_1T()		CMOD = (CMOD & ~0x0E) + 8	/* PCA counting pulse selection Fosc	*/
#define PCA_CLK_4T()		CMOD = (CMOD & ~0x0E) + 10	/* PCA counting pulse selection Fosc/4	*/
#define PCA_CLK_6T()		CMOD = (CMOD & ~0x0E) + 12	/* PCA counting pulse selection Fosc/6	*/
#define PCA_CLK_8T()		CMOD = (CMOD & ~0x0E) + 14	/* PCA counting pulse selection Fosc/8	*/
#define PCA_INT_ENABLE()	CMOD |=  1					/* PCA counter overflow interrupt enable bit, 1---allows CF (CCON.7) to generate an interrupt.	*/
#define PCA_INT_DISABLE()	CMOD &= ~1					/* PCA counter overflow interrupt is disabled.	*/

//                	    7      6       5        4       3       2       1      0    Reset Value
//sfr P_SW1 = 0xA2;	  S1_S1  S1_S0  CCP_S1   CCP_S0  SPI_S1   SPI_S0    0      -    nn00,000x		//Auxiliary Register 1
#define		PCA_USE_P12P11P10P37()	P_SW1 &= ~0x30				/* Switch PCA/PWM to P12(ECI) P11(CCP0) P10(CCP1) P37(CCP2) (power-on default) */
#define		PCA_USE_P34P35P36P37()	P_SW1 = (P_SW1 & ~0x30) | 0x10	/* Switch PCA/PWM to P34(ECI) P35(CCP0) P36(CCP1) P37(CCP2) */
#define		PCA_USE_P24P25P26P27()	P_SW1 = (P_SW1 & ~0x30) | 0x20	/* Switch PCA/PWM to P24(ECI) P25(CCP0) P26(CCP1) P27(CCP2) */


/*									7     6       5       4     3     2     1     0     Reset Value
//sfr CCAPM0 = 0xDA; PWM register - ECOM0 CCAPP0 CCAPN0 MAT0 TOG0 PWM0 ECCF0 x000,0000 //PCA module 0
//sfr CCAPM1 = 0xDB; PWM register - ECOM1 CCAPP1 CCAPN1 MAT1 TOG1 PWM1 ECCF1 x000,0000 //PCA module 1
//sfr CCAPM2 = 0xDC; PWM register - ECOM2 CCAPP2 CCAPN2 MAT2 TOG2 PWM2 ECCF2 x000,0000 //PCA module 2
//sfr CCAPM3 = 0xDD; PWM register - ECOM3 CCAPP3 CCAPN3 MAT3 TOG3 PWM3 ECCF3 x000,0000 //PCA module 3
;ECOMn = 1: Enable comparison functionality.
;CAPPn = 1: Enable rising edge trigger capture function.
;CAPNn = 1: Enable falling edge trigger capture function.
;MATn = 1: Allow CCFn in CCON to be set when a match condition occurs.
;TOGn = 1: CEXn will flip when a match occurs. (CEX0/PCA0/PWM0/P3.7,CEX1/PCA1/PWM1/P3.5)
;PWMn = 1: Set CEXn as PWM output.
;ECCFn = 1: Allow CCFn in CCON to trigger interrupts.
;ECOMn CAPPn CAPNn MATn TOGn PWMn ECCFn
; 0 0 0 0 0 0 0 00H No functionality is enabled.
; x 1 0 0 0 0 x 20H 16-bit CEXn rising edge trigger capture function.
; x 0 1 0 0 0 x 10H 16-bit CEXn falling edge trigger capture function.
; x 1 1 0 0 0 x 30H 16-bit CEXn/PCAn edge (rising and falling edges) trigger capture function.
; 1 0 0 1 0 0 x 48H 16-bit software timer.
; 1 0 0 1 1 0 x 4CH 16-bit high-speed pulse output.
; 1 0 0 0 0 1 0 42H 8-bit PWM. No interrupt
; 1 1 0 0 0 1 1 63H 8-bit PWM. Low to high can generate an interrupt
; 1 0 1 0 0 1 1 53H 8-bit PWM. High to low can generate an interrupt
; 1 1 1 0 0 1 1 73H 8-bit PWM. Low to high or high to low can generate an interrupt
;*******************************************************************
;*******************************************************************/

#define		PCA0_none()				CCAPM0 = 0
#define		PCA0_PWM(nbit)			CCAPM0 = 0x42,PCA_PWM0 = (PCA_PWM0 & 0x3f) | (nbit<<6)
#define		PCA0_PWM_rise_int(nbit) CCAPM0 = 0x63,PCA_PWM0 = (PCA_PWM0 & 0x3f) | (nbit<<6)
#define		PCA0_PWM_fall_int(nbit) CCAPM0 = 0x53,PCA_PWM0 = (PCA_PWM0 & 0x3f) | (nbit<<6)
#define		PCA0_PWM_edge_int(nbit) CCAPM0 = 0x73,PCA_PWM0 = (PCA_PWM0 & 0x3f) | (nbit<<6)
#define		PCA0_capture_rise()		CCAPM0 = (0x20 + 1)
#define		PCA0_capture_fall()		CCAPM0 = (0x10 + 1)
#define		PCA0_capture_edge()		CCAPM0 = (0x30 + 1)
#define		PCA0_16bit_Timer()		CCAPM0 = (0x48 + 1)
#define		PCA0_High_PulseEnable()	CCAPM0 |= 0x04

#define		PCA1_none()				CCAPM1 = 0
#define		PCA1_PWM(nbit)			CCAPM1 = 0x42,PCA_PWM1 = (PCA_PWM1 & 0x3f) | (nbit<<6)
#define		PCA1_PWM_rise_int(nbit) CCAPM1 = 0x63,PCA_PWM1 = (PCA_PWM1 & 0x3f) | (nbit<<6)
#define		PCA1_PWM_fall_int(nbit) CCAPM1 = 0x53,PCA_PWM1 = (PCA_PWM1 & 0x3f) | (nbit<<6)
#define		PCA1_PWM_edge_int(nbit) CCAPM1 = 0x73,PCA_PWM1 = (PCA_PWM1 & 0x3f) | (nbit<<6)
#define		PCA1_capture_rise()		CCAPM1 = (0x20 + 1)
#define		PCA1_capture_fall()		CCAPM1 = (0x10 + 1)
#define		PCA1_capture_edge()		CCAPM1 = (0x30 + 1)
#define		PCA1_16bit_Timer()		CCAPM1 = (0x48 + 1)
#define		PCA1_High_PulseEnable()	CCAPM1 |= 0x04

#define		PCA2_none()				CCAPM2 = 0
#define		PCA2_PWM(nbit)			CCAPM2 = 0x42,PCA_PWM2 = (PCA_PWM2 & 0x3f) | (nbit<<6)
#define		PCA2_PWM_rise_int(nbit) CCAPM2 = 0x63,PCA_PWM2 = (PCA_PWM2 & 0x3f) | (nbit<<6)
#define		PCA2_PWM_fall_int(nbit) CCAPM2 = 0x53,PCA_PWM2 = (PCA_PWM2 & 0x3f) | (nbit<<6)
#define		PCA2_PWM_edge_int(nbit) CCAPM2 = 0x73,PCA_PWM2 = (PCA_PWM2 & 0x3f) | (nbit<<6)
#define		PCA2_capture_rise()		CCAPM2 = (0x20 + 1)
#define		PCA2_capture_fall()		CCAPM2 = (0x10 + 1)
#define		PCA2_capture_edge()		CCAPM2 = (0x30 + 1)
#define		PCA2_16bit_Timer()		CCAPM2 = (0x48 + 1)
#define		PCA2_High_PulseEnable()	CCAPM2 |= 0x04

//#define		PCA3_none()				CCAPM3 = 0
//#define		PCA3_PWM(nbit)			CCAPM3 = 0x42,PCA_PWM3 = (PCA_PWM3 & 0x3f) | (nbit<<6)
//#define		PCA3_PWM_rise_int(nbit) CCAPM3 = 0x63,PCA_PWM3 = (PCA_PWM3 & 0x3f) | (nbit<<6)
//#define		PCA3_PWM_fall_int(nbit) CCAPM3 = 0x53,PCA_PWM3 = (PCA_PWM3 & 0x3f) | (nbit<<6)
//#define		PCA3_PWM_edge_int(nbit) CCAPM3 = 0x73,PCA_PWM3 = (PCA_PWM3 & 0x3f) | (nbit<<6)
//#define		PCA3_capture_rise()		CCAPM3 = (0x20 + 1)
//#define		PCA3_capture_fall()		CCAPM3 = (0x10 + 1)
//#define		PCA3_capture_edge()		CCAPM3 = (0x30 + 1)
//#define		PCA3_16bit_Timer()		CCAPM3 = (0x48 + 1)
//#define		PCA3_High_PulseEnable()	CCAPM3 |= 0x04

/**********************************************************/
typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	unsigned long	u32;

/**********************************************************/
#define NOP1()  _nop_()
#define NOP2()  NOP1(),NOP1()
#define NOP3()  NOP2(),NOP1()
#define NOP4()  NOP3(),NOP1()
#define NOP5()  NOP4(),NOP1()
#define NOP6()  NOP5(),NOP1()
#define NOP7()  NOP6(),NOP1()
#define NOP8()  NOP7(),NOP1()
#define NOP9()  NOP8(),NOP1()
#define NOP10() NOP9(),NOP1()
#define NOP11() NOP10(),NOP1()
#define NOP12() NOP11(),NOP1()
#define NOP13() NOP12(),NOP1()
#define NOP14() NOP13(),NOP1()
#define NOP15() NOP14(),NOP1()
#define NOP16() NOP15(),NOP1()
#define NOP17() NOP16(),NOP1()
#define NOP18() NOP17(),NOP1()
#define NOP19() NOP18(),NOP1()
#define NOP20() NOP19(),NOP1()
#define NOP21() NOP20(),NOP1()
#define NOP22() NOP21(),NOP1()
#define NOP23() NOP22(),NOP1()
#define NOP24() NOP23(),NOP1()
#define NOP25() NOP24(),NOP1()
#define NOP26() NOP25(),NOP1()
#define NOP27() NOP26(),NOP1()
#define NOP28() NOP27(),NOP1()
#define NOP29() NOP28(),NOP1()
#define NOP30() NOP29(),NOP1()
#define NOP31() NOP30(),NOP1()
#define NOP32() NOP31(),NOP1()
#define NOP33() NOP32(),NOP1()
#define NOP34() NOP33(),NOP1()
#define NOP35() NOP34(),NOP1()
#define NOP36() NOP35(),NOP1()
#define NOP37() NOP36(),NOP1()
#define NOP38() NOP37(),NOP1()
#define NOP39() NOP38(),NOP1()
#define NOP40() NOP39(),NOP1()
#define NOP(N)  NOP##N()


/**********************************************/
#define	Pin0		0x01	//IO pin Px.0
#define	Pin1		0x02	//IO pin Px.1
#define	Pin2		0x04	//IO pin Px.2
#define	Pin3		0x08	//IO pin Px.3
#define	Pin4		0x10	//IO pin Px.4
#define	Pin5		0x20	//IO pin Px.5
#define	Pin6		0x40	//IO pin Px.6
#define	Pin7		0x80	//IO pin Px.7
#define	PinAll		0xFF	//All IO pins

#define P0n_standard(bitn)			P0M1 &= ~(bitn),	P0M0 &= ~(bitn)	/* 00  */
#define P0n_push_pull(bitn)			P0M1 &= ~(bitn),	P0M0 |=  (bitn)	/* 01  */
#define P0n_pure_input(bitn)		P0M1 |=  (bitn),	P0M0 &= ~(bitn)	/* 10  */
#define P0n_open_drain(bitn)		P0M1 |=  (bitn),	P0M0 |=  (bitn)	/* 11  */

#define P1n_standard(bitn)			P1M1 &= ~(bitn),	P1M0 &= ~(bitn)
#define P1n_push_pull(bitn)			P1M1 &= ~(bitn),	P1M0 |=  (bitn)
#define P1n_pure_input(bitn)		P1M1 |=  (bitn),	P1M0 &= ~(bitn)
#define P1n_open_drain(bitn)		P1M1 |=  (bitn),	P1M0 |=  (bitn)

#define P2n_standard(bitn)			P2M1 &= ~(bitn),	P2M0 &= ~(bitn)
#define P2n_push_pull(bitn)			P2M1 &= ~(bitn),	P2M0 |=  (bitn)
#define P2n_pure_input(bitn)		P2M1 |=  (bitn),	P2M0 &= ~(bitn)
#define P2n_open_drain(bitn)		P2M1 |=  (bitn),	P2M0 |=  (bitn)

#define P3n_standard(bitn)			P3M1 &= ~(bitn),	P3M0 &= ~(bitn)
#define P3n_push_pull(bitn)			P3M1 &= ~(bitn),	P3M0 |=  (bitn)
#define P3n_pure_input(bitn)		P3M1 |=  (bitn),	P3M0 &= ~(bitn)
#define P3n_open_drain(bitn)		P3M1 |=  (bitn),	P3M0 |=  (bitn)

#define P4n_standard(bitn)			P4M1 &= ~(bitn),	P4M0 &= ~(bitn)
#define P4n_push_pull(bitn)			P4M1 &= ~(bitn),	P4M0 |=  (bitn)
#define P4n_pure_input(bitn)		P4M1 |=  (bitn),	P4M0 &= ~(bitn)
#define P4n_open_drain(bitn)		P4M1 |=  (bitn),	P4M0 |=  (bitn)

#define P5n_standard(bitn)			P5M1 &= ~(bitn),	P5M0 &= ~(bitn)
#define P5n_push_pull(bitn)			P5M1 &= ~(bitn),	P5M0 |=  (bitn)
#define P5n_pure_input(bitn)		P5M1 |=  (bitn),	P5M0 &= ~(bitn)
#define P5n_open_drain(bitn)		P5M1 |=  (bitn),	P5M0 |=  (bitn)

#define P6n_standard(bitn)			P6M1 &= ~(bitn),	P6M0 &= ~(bitn)
#define P6n_push_pull(bitn)			P6M1 &= ~(bitn),	P6M0 |=  (bitn)
#define P6n_pure_input(bitn)		P6M1 |=  (bitn),	P6M0 &= ~(bitn)
#define P6n_open_drain(bitn)		P6M1 |=  (bitn),	P6M0 |=  (bitn)

#define P7n_standard(bitn)			P7M1 &= ~(bitn),	P7M0 &= ~(bitn)
#define P7n_push_pull(bitn)			P7M1 &= ~(bitn),	P7M0 |=  (bitn)
#define P7n_pure_input(bitn)		P7M1 |=  (bitn),	P7M0 &= ~(bitn)
#define P7n_open_drain(bitn)		P7M1 |=  (bitn),	P7M0 |=  (bitn)


/****************************************************************/


//sfr INT_CLKO = 0x8F; //Additional SFR WAKE_CLKO (address: 0x8F)
/*
    7   6    5    4   3     2        1       0         Reset Value
    -  EX4  EX3  EX2  -   T2CLKO   T1CLKO  T0CLKO      0000,0000B
b6 - EX4: External interrupt INT4 enabled
b5 - EX3: External interrupt INT3 enabled
b4 - EX2: External interrupt INT2 enabled
b2 - T1CLKO: Allow T2 overflow pulse to be output at P3.0 pin, Fck1 = 1/2 T1 overflow rate
b1 - T1CLKO: Allow T1 overflow pulse to be output at P3.4 pin, Fck1 = 1/2 T1 overflow rate
b0 - T0CLKO: Allow T0 overflow pulse to be output at P3.5 pin, Fck0 = 1/2 T0 overflow rate
*/

#define		LVD_InterruptEnable()		ELVD = 1
#define		LVD_InterruptDisable()		ELVD = 0


//sfr WKTCL = 0xAA; //Wake up timer low byte
//sfr WKTCH = 0xAB; //Wake up timer high byte
//	B7		B6	B5	B4	B3	B2	B1	B0		B7	B6	B5	B4	B3	B2	B1	B0
//	WKTEN				S11	S10	S9	S8		S7	S6	S5	S4	S3	S2	S1	S0	n * 560us
#define		WakeTimerDisable()		WKTCH &= 0x7f	/* WKTEN = 0 disable sleep wake timer */
#define		WakeTimerSet(scale)		WKTCL = (scale) % 256,WKTCH = (scale) / 256 | 0x80	/* WKTEN = 1 enables sleep wake timer */



//sfr BUS_SPEED = 0xA1; //Stretch register      -   -  -  -   -   -  EXRTS1  EXRTSS0 xxxx,xx10
#define		BUS_SPEED_1T()	BUS_SPEED = BUS_SPEED & ~3
#define		BUS_SPEED_2T()	BUS_SPEED = (BUS_SPEED & ~3) | 1
#define		BUS_SPEED_4T()	BUS_SPEED = (BUS_SPEED & ~3) | 2
#define		BUS_SPEED_8T()	BUS_SPEED = (BUS_SPEED & ~3) | 3

#define		BUS_RD_WR_P44_P43()	BUS_SPEED = BUS_SPEED & 0x3f
#define		BUS_RD_WR_P37_P36()	BUS_SPEED = (BUS_SPEED & 0x3f) | 0x40
#define		BUS_RD_WR_P42_P40()	BUS_SPEED = (BUS_SPEED & 0x3f) | 0x80


/*   interrupt vector */
#define		INT0_VECTOR		0
#define		TIMER0_VECTOR	1
#define		INT1_VECTOR		2
#define		TIMER1_VECTOR	3
#define		UART1_VECTOR	4
#define		ADC_VECTOR		5
#define		LVD_VECTOR		6
#define		PCA_VECTOR		7
#define		UART2_VECTOR	8
#define		SPI_VECTOR		9
#define		INT2_VECTOR		10
#define		INT3_VECTOR		11
#define		TIMER2_VECTOR	12
#define		INT4_VECTOR		16
#define		UART3_VECTOR	17
#define		UART4_VECTOR	18
#define		TIMER3_VECTOR	19
#define		TIMER4_VECTOR	20
#define		CMP_VECTOR		21
#define		PWM0_VECTOR		22
#define		PWMFD_VECTOR	23
#define		I2C_VECTOR		24
#define		USB_VECTOR		25
#define		PWMA_VECTOR		26
#define		PWMB_VECTOR		27
#define		PWM1_VECTOR		28
#define		PWM2_VECTOR		29
#define		PWM3_VECTOR		30
#define		PWM4_VECTOR		31
#define		PWM5_VECTOR		32


#define	TRUE	1
#define	FALSE	0

//=============================================================

//========================================

#define	Priority_0			0	//Interrupt priority level 0 (lowest)
#define	Priority_1			1	//Interrupt priority level 1 (lower)
#define	Priority_2			2	//Interrupt priority level 2 (higher)
#define	Priority_3			3	//Interrupt priority level 3 (highest)

//========================================

#define		ENABLE		1
#define		DISABLE		0

#endif


#endif
