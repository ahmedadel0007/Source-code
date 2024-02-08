#ifndef HAL_SSD_cfg_H_
#define HAL_SSD_cfg_H_

#include "DIO.h"

/**
 *@brief : State The Number of your 7 Segments in Your Project                           
 */
#define NUM_OF_7SEG 2

/**
 *@brief : State your 7 Segments Here and Assign Them Ascendingly                       
 */
#define _7SEG_0 0
#define _7SEG_1 1

typedef enum
{
	_7SEG_CommonAnode,
	_7SEG_CommonCathode
}_7SEG_enumType_t;

typedef struct  
{
	DIO_enuPort_t Port;
	DIO_enuPin_t Pin;
}_7SEG_StructPinConfig_t;

typedef struct
{
    _7SEG_StructPinConfig_t PinConfig[7];
	_7SEG_enumType_t Type;
	
}_7SEG_StructConfig_t;





#endif /* _SSD_CONFIG_H_ */