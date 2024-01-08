/*
 * GccApplication1.c
 *
 * Created: 12/12/2023 3:03:11 PM
 * Author : Ahmed Adel
 */ 


#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "PORT_config.h"
#include "LED.h"
#include "LED_Cfg.h"


int main(void)
{

   
    while (1) 
    {
		 LED_enumInit();
		  _delay_ms(3000);
		  
	 LED_On(LED_one);
	 _delay_ms(3000);
	 LED_On(LED_two);
	 _delay_ms(3000);
	 LED_On(LED_three);
		
    }
}

