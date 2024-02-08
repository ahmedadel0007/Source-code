/*
*
* Author : Ahmed Adel
* Date :25/12/2023
* Seven Segment .h 
*/

#ifndef HAL_SSD_H_
#define HAL_SSD_H_

#include "SSD_cfg.h"



/************************************************************************************************************************************************/
/* Function:        SSD_enumInit()                                                                                                             */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      Initializes the Seven segments configured in config.c                                                                                   */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - Configure the SSD in SSD_config.c file and add the SSD to the SSDname in SSD_cfg.h file                         */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return HSSEG_enuErrorStatus_t                                                                                                          */
/************************************************************************************************************************************************/

DIO_enuErrorStatus_t SSD_enumInit();


/************************************************************************************************************************************************/
/* Function:        HSSEG_enuSetValue()                                                                                                         */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      Sets the value of the given SSEG to the given Value                                                                                     */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - Initializing the SSEGs using HSSEG_enuInit()                                                                                          */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - @param Copy_enuSSEG The name of the SSEG as defined in HSSEG_config.h                                                                 */
/*      - @param Copy_u8Value The value (digit) to display on the SSEG                                                                          */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return HSSEG_enuErrorStatus_t                                                                                                          */
/************************************************************************************************************************************************/
DIO_enuErrorStatus_t SSD_enumSetValue( u8 Copy_enumSSD ,u8 Copy_u8Value);


/************************************************************************************************************************************************/
/* Function:        SSD_enumSetAllValue()                                                                                                      */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      This function is used when all the SSEGs exist work togther as a multi-digit display and displays the given number                      */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - Initializing the SSEGs using HSSEG_enuInit()                                                                                          */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - @param Copy_u8Value The Number to display on all SSEGs togther                                                                        */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return SSD_enumErrorStatus_t                                                                                                          */
/************************************************************************************************************************************************/
DIO_enuErrorStatus_t SSD_enumSetValueAll(u16 Copy_u8Value);



#endif /*HAL_SSD_H_*/
