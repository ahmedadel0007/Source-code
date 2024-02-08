/************************************************************************************************************************************************/
/* File             :       HLED_int.h                                                                                                          */
/* AUTHOR           :       Ahmed Adel                                                                                                         */
/* Origin Date      :       10/12/2023                                                                                                          */
/* SWC              :       LED                                                                                                                 */
/************************************************************************************************************************************************/
#ifndef _HAL_HLED_HLED_INT_H_
#define _HAL_HLED_HLED_INT_H_

#include "LED_Cfg.h"



/************************************************************************************************************************************************/
/* HLED error status                                                                                                                            */
/************************************************************************************************************************************************/
typedef enum
{
	HLED_enuOk,
	HLED_enuDIOError,
	HLED_enuNOk,
	HLED_enuInvalidActiveMode,
	HLED_enuInvalidLED,
	HLED_enuInvalidState
}HLED_enuErrorStatus_t;


/************************************************************************************************************************************************/
/* States of the LED                                                                                                                            */
/************************************************************************************************************************************************/
typedef enum
{
	HLED_enuOFF,
	HLED_enuON
	
}HLED_enuLEDState_t;


/************************************************************************************************************************************************/
/* Struct for creating LEDs object with its configuration                                                                                       */
/* pin  : PORT_enuPin0 to PORT_enuPin7 (if exist)                                                                                               */
/* port : PORT_enuPORTA to PORT_enuPORTD (if exist)                                                                                             */
/* activeMode:                                                                                                                                  */
/*          - HLED_enuActiveLow                                                                                                                 */
/*          - HLED_enuActiveHigh                                                                                                                */
/* state: Current state of the LED                                                                                                              */
/*          - HLED_enuON                                                                                                                        */
/*          - HLED_enuOFF                                                                                                                       */
/************************************************************************************************************************************************/
typedef struct
{
	u8 pin;
	u8 port;
	u8 activeMode;
	u8 state;

}HLED_strLED_t;


/************************************************************************************************************************************************/
/* Function:        HLED_enuInit()                                                                                                              */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      Initializes the LEDs configured in config.c                                                                                             */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - Configure the LEDs in HLED_config.c file and add the LED to the HLED_enuLEDsList in HLED_condig.h file                                */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return HLED_enuErrorStatus_t                                                                                                           */
/************************************************************************************************************************************************/
HLED_enuErrorStatus_t HLED_enuInit(void);


/************************************************************************************************************************************************/
/* Function:        HLED_enuSetEDState()                                                                                                        */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      Sets the state of the given LED to the given state                                                                                      */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - The LED must exist and be added to LEDS_config array in HLED_config.c and HLED_enuLEDsList_t in HLED_config.h                         */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - @param Copy_enuLED The LED name as added in the HLED_enuLEDsList_t in HLED_config.h file                                              */
/*      - @param Copy_enuState The new LED state (either HLED_enuON or HLED_enuOFF)                                                             */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return HLED_enuErrorStatus_t                                                                                                           */
/************************************************************************************************************************************************/
HLED_enuErrorStatus_t HLED_enuSetLEDState(HLED_enuLEDsList_t , HLED_enuLEDState_t Copy_enuState);



/************************************************************************************************************************************************/
/* Function:        HLED_voidUpdate()                                                                                                           */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      Updates the LEDs hardware state according to the configuration in LEDs_config array in HLED_config.c file                               */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - LEDs must be Initialized firts using HLED_enuInit() function                                                                          */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      - @return HLED_enuErrorStatus_t                                                                                                         */
/************************************************************************************************************************************************/
HLED_enuErrorStatus_t HLED_enuUpdate(void);

#endif /* 02_HAL_HLED_HLED_INT_H_ */