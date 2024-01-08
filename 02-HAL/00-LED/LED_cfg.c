/************************************************************************************************************************************************/
/* File             :       LED_cfg.c                                                                                                       */
/* AUTHOR           :       Ahmed Adel                                                                                                        */
/* Origin Date      :       24/12/2023                                                                                                          */
/* SWC              :       LED                                                                                                                 */
/************************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "LED_Cfg.h" 
#include "LED.h"   
#include "LED_priv.h"

/************************************************************************************************************************************************/
/* This array should contain all LEDs objects                                                                                                   */
/* Each LED object contains the following:                                                                                                      */
/*                                                                                                                                              */
/* pin        : PORT_enuPin0 to PORT_enuPin7 (if exist)                                                                                         */
/*                                                                                                                                              */
/* port       : PORT_enuPORTA to PORT_enuPORTD (if exist)                                                                                       */
/*                                                                                                                                              */
/* activeMode :                                                                                                                                 */
/*          - HLED_enuActiveLow                                                                                                                 */
/*          - HLED_enuActiveHigh                                                                                                                */
/*                                                                                                                                              */
/* state      : Current state of the LED                                                                                                        */
/*          - HLED_enuON                                                                                                                        */
/*          - HLED_enuOFF                                                                                                                       */
/************************************************************************************************************************************************/

HLED_strLED_t  LEDS_config[NUMBER_OF_LEDS]=
{
[LED_one]= {
	              .pin = PORT_enuPin0,
	              .port = PORT_enuPORTA,
	              .activeMode=HLED_enuActiveLow,
	              .state = HLED_enuOFF                            /* this is for user to config*/
            }
			,
[LED_two]={
	          .pin = PORT_enuPin1,
	          .port = PORT_enuPORTA,
	          .activeMode = HLED_enuActiveHigh,
	          .state = HLED_enuON               /* this is for user to config*/
           }
		   ,	
[LED_three]={	
	             .pin = PORT_enuPin2,
	             .port = PORT_enuPORTA,
	             .activeMode = HLED_enuActiveHigh,
	             .state = HLED_enuON                          /* this is for user to config*/	   
		   		
            }
};
