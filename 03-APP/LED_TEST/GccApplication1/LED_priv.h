/************************************************************************************************************************************************/
/* File             :       HLED_priv.h                                                                                                          */
/* AUTHOR           :       Ahmed Adel                                                                                                          */
/* Origin Date      :       10/12/2023                                                                                                          */
/* SWC              :       LED                                                                                                                 */
/************************************************************************************************************************************************/
#ifndef _HAL_HLED_HLED_PRIV_H_
#define _HAL_HLED_HLED_PRIV_H_

/************************************************************************************************************************************************/
/* Active mode of the LED (ActiveHigh or ActiveLow)                                                                                             */
/************************************************************************************************************************************************/
typedef enum
{
    
    /* ActiveLow  = LEDs is ON when the output is LOW and OFF when output is HIGH*/
    HLED_enuActiveLow,

    /* ActiveHIGH = LEDs is ON when the output is HIGH and OFF when output is LOW */
    HLED_enuActiveHigh,

}HLED_enuActiveMode_t;


#endif /* 02_HAL_HLED_HLED_PRIV_H_ */