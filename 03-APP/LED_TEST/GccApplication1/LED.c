#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO.h"

#include "LED_priv.h"
#include "LED_Cfg.h"
#include "LED.h"


extern HLED_strLED_t LEDS_config [NUMBER_OF_LEDS];

HLED_enuErrorStatus_t HLED_enuInit(void)
{
	HLED_enuErrorStatus_t Ret_enuErrorStatus = HLED_enuOk;
	u8 i;
	
	PORT_strConfig_t Loc_strCurrLED;
	for(i = 0; i < NUMBER_OF_LEDS; i++)
	{
		if( (LEDS_config[i].activeMode == HLED_enuActiveHigh) || (LEDS_config[i].activeMode == HLED_enuActiveLow) )
		{
			Loc_strCurrLED.pin = LEDS_config[i].pin;
			Loc_strCurrLED.port = LEDS_config[i].port;

			if( (LEDS_config[i].activeMode == HLED_enuActiveHigh) && (LEDS_config[i].state == HLED_enuOFF) )
			{
				Loc_strCurrLED.mode = PIN_OUTPUT_LOW;
			}
			else if( (LEDS_config[i].activeMode == HLED_enuActiveHigh) && (LEDS_config[i].state == HLED_enuON) )
			{
				Loc_strCurrLED.mode = PIN_OUTPUT_HIGH;
			}
			else if( (LEDS_config[i].activeMode == HLED_enuActiveLow) && (LEDS_config[i].state == HLED_enuON) )
			{
				Loc_strCurrLED.mode = PIN_OUTPUT_LOW;
			}
			else if ( (LEDS_config[i].activeMode == HLED_enuActiveLow) && (LEDS_config[i].state == HLED_enuOFF) )
			{
				Loc_strCurrLED.mode = PIN_OUTPUT_HIGH;
			}

			/* In case the PORT_enuSetPinConfig fails, set the return stataus to DIO_error */
			if( PORT_enuSetPinConfig(&Loc_strCurrLED) )
			{
				Ret_enuErrorStatus = HLED_enuDIOError;
			}
			else {/* do nothing */}
		}
		else
		{
			Ret_enuErrorStatus = HLED_enuInvalidActiveMode;
			}/* end of active mode check */
			}/* end of for loop */

			return Ret_enuErrorStatus;

		}


		HLED_enuErrorStatus_t HLED_enuSetLEDState(HLED_enuLEDsList_t Copy_enuLED, HLED_enuLEDState_t Copy_enuState)
		{
			HLED_enuErrorStatus_t Ret_enuErrorStatus = HLED_enuOk;

			if(Copy_enuLED < NUMBER_OF_LEDS)
			{
				if( (Copy_enuState == HLED_enuON) || (Copy_enuState == HLED_enuOFF) )
				{
					LEDS_config[Copy_enuLED].state = Copy_enuState;
				}
				else
				{
					Ret_enuErrorStatus = HLED_enuInvalidState;
				}
			}
			else
			{
				Ret_enuErrorStatus = HLED_enuInvalidLED;
				}/* end of LED check */
				
				return Ret_enuErrorStatus;
			}


			HLED_enuErrorStatus_t HLED_enuUpdate(void)
			{
				HLED_enuErrorStatus_t Ret_enuErrorStatus = HLED_enuOk;
				u8 i;

				for(i = 0; i < NUMBER_OF_LEDS; i++)
				{

					if( (LEDS_config[i].activeMode == HLED_enuActiveHigh) && (LEDS_config[i].state == HLED_enuOFF) )
					{
						Ret_enuErrorStatus = DIO_enuSetPinValue(LEDS_config[i].port, LEDS_config[i].pin, DIO_enuLow);
					}
					else if( (LEDS_config[i].activeMode == HLED_enuActiveHigh) && (LEDS_config[i].state == HLED_enuON) )
					{
						Ret_enuErrorStatus = DIO_enuSetPinValue(LEDS_config[i].port, LEDS_config[i].pin, DIO_enuHigh);
					}
					else if( (LEDS_config[i].activeMode == HLED_enuActiveLow) && (LEDS_config[i].state == HLED_enuON) )
					{
						Ret_enuErrorStatus = DIO_enuSetPinValue(LEDS_config[i].port, LEDS_config[i].pin, DIO_enuLow);
					}
					else if ( (LEDS_config[i].activeMode == HLED_enuActiveLow) && (LEDS_config[i].state == HLED_enuOFF) )
					{
						Ret_enuErrorStatus = DIO_enuSetPinValue(LEDS_config[i].port, LEDS_config[i].pin, DIO_enuHigh);
					}

					}/* end of for loop */
					
					if( Ret_enuErrorStatus != HLED_enuOk )
					{
						Ret_enuErrorStatus = HLED_enuDIOError;
					}

					return Ret_enuErrorStatus;
				}