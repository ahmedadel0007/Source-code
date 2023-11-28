/*
 * main.c
 *
 * Created: 11/25/2023 11:38:47 AM
 *  Author: HP
 */ 

#include "D:\embedded system\01-MCAL\00-DIO\DIO_DRIVER\DIO.h"
#include "D:\embedded system\01-MCAL\00-DIO\DIO_DRIVER\DIO_private.h"
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define SET_BIT(REG,BIT)      (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)      (REG &= ~(1<<BIT))
#define GET_BIT(REG,BIT)      ((REG >> BIT) & 0x01)
#define TOG_BIT(REG,BIT)      (REG ^= (1<<BIT))
#define SET_PORT(REG)         (REG |= 0xFF)
#define CLR_PORT(REG)         (REG &= 0x00)
#define TOG_PORT(REG)         (REG ^= 0xFF)

typedef 	unsigned char			u8;
typedef 	unsigned short int		u16;
typedef 	unsigned int 			u32;
typedef 	signed char				s8;
typedef 	signed short int		s16;
typedef 	signed int 				s32;
typedef 	float					f32;
typedef 	double 					f64;

#define DDRA             *((volatile u8*) 0x3A)
#define PORTA            *((volatile u8*) 0x3B)
#define PINA             *((volatile u8*) 0x39)

#define DDRB             *((volatile u8*) 0x37)
#define PORTB            *((volatile u8*) 0x38)
#define PINB             *((volatile u8*) 0x36)

#define DDRC             *((volatile u8*) 0x34)
#define PORTC            *((volatile u8*) 0x35)
#define PINC             *((volatile u8*) 0x33)

#define DDRD             *((volatile u8*) 0x31)
#define PORTD            *((volatile u8*) 0x32)
#define PIND             *((volatile u8*) 0x30)
int main(void)
{
	DIO_enumSetPortConfig(DIO_enumPortA, DIO_enumPin0, DIO_enumOutput) ;  /*keda 5alena 2awl two pins output*/
	DIO_enumSetPortConfig(DIO_enumPortA, DIO_enumPin1, DIO_enumOutput);                     /*keda al output low*/
	
    while(1)
    {
      DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);    /*first bit high*/
	   _delay_ms(1000);                                                   /*delay*/
	  DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh);     /*second bit high*/
	  DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);    /*first bit low*/ 
	  _delay_ms(1000);                                                   /*delay*/
	  DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);    /*second bit low*/
	  DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);     /*first bit high*/
	    
    }
}