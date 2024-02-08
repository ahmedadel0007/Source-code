/*
 * GccApplication1.c
 *
 * Created: 12/12/2023 3:03:11 PM
 * Author : Ahmed Adel
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define FCPU	1000000UL
#include "STD_TYPES.h"
#include "LED_Cfg.h"
#include "LED.h"
#include "PORT_config.h"
#include "PORT_interface.h"


int main(void)
{
 HLED_enuInit();
 _delay_ms(3000);
   
    while (1) 
    {
	         HLED_enuSetLEDState(LED_one, HLED_enuOFF);
	         HLED_enuSetLEDState(LED_two, HLED_enuOFF);
	       
	 
	         _delay_ms(1000);
	 
	         HLED_enuSetLEDState(LED_one, HLED_enuOFF);
	         HLED_enuSetLEDState(LED_two, HLED_enuON);
	 
	 
	         _delay_ms(1000);
	     }
	 
	    return 0;
	 
	 	
    }


