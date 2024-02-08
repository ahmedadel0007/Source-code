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


int main(void)
{
	DIO_enumSetPortConfig (DIO_enumPortA, DIO_enumOutput) ;  /*keda 5alena 2awl two pins output*/
	DIO_enumSetPortConfig (DIO_enumPortA, DIO_enumOutput);      /*keda al output low*/
	
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