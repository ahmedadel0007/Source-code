#include "STD_TYPES.h"
#include "DIO.h"
#include "PORT_interface.h"
#include "PORT_config.h"
#include "SSD_cfg.h"
#include "SSD.h"

extern const _7SEG_StructConfig_t _7SEG_Config[NUM_OF_7SEG];

DIO_enuErrorStatus_t SSD_enumInit()
{
	DIO_enuErrorStatus_t Ret_enumErrorStatus = DIO_enuOk;
	
	//new array of PORT_structConfig_t type ( which consists of Port, Pin and ConfigType) to be used in the PORT_enumSetConfig function
	PORT_strConfig_t  _7SEG_StructConfig;
	
	for(u8 Loc_u8Counter = 0; Loc_u8Counter < NUM_OF_7SEG; Loc_u8Counter++) //For loop on the current number of 7 Segments
	{
		
		for(u8 Loc_u8Counter_1 = 0; Loc_u8Counter_1 < 7; Loc_u8Counter_1 ++) //For loop on the 7 Pins
		{
			
			_7SEG_StructConfig.port=_7SEG_Config[Loc_u8Counter].PinConfig[Loc_u8Counter_1].Port;
			_7SEG_StructConfig.pin=_7SEG_Config[Loc_u8Counter].PinConfig[Loc_u8Counter_1].Pin;
			
			switch(_7SEG_Config[Loc_u8Counter].Type) //Switch Cases on the Type to be Initially Output Low
			{
				case _7SEG_CommonAnode:
				_7SEG_StructConfig.mode=PIN_OUTPUT_LOW;
				break;
				case _7SEG_CommonCathode:
				_7SEG_StructConfig.mode=PIN_OUTPUT_LOW;
				break;
				
				default:
				break;
			}

			Ret_enumErrorStatus=PORT_enuSetPinConfig(&_7SEG_StructConfig);
			if(Ret_enumErrorStatus != DIO_enuOk)
			{
				break;
			}
		}
		
	}
	return Ret_enumErrorStatus;
}
DIO_enuErrorStatus_t SSD_enumSetValue(u8 Copy_u8SegName, u8 Copy_u8Value)
{
	DIO_enuErrorStatus_t Ret_enumErrorStatus = DIO_enuNOK;
	
	if(Copy_u8SegName > NUM_OF_7SEG || Copy_u8SegName < 0) //If the Segment Number is Invalid
	{
		Ret_enumErrorStatus = DIO_enuNOK;
	}
	else if(Copy_u8Value > 9 || Copy_u8Value < 0) //If the Number is Larger Than 9 or Less Than 0
	{
		Ret_enumErrorStatus = DIO_enuNOK;
	}
	else
	{
		switch(Copy_u8Value) //Switch Cases on The Value Entered Depending on the Type
		{
			case 0:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
			    DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				default:
				break;
			}
			break;
			
			case 1:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				default:
				break;
			}
			break;
			
			case 2:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				default:
				break;
			}
			break;
			
			case 3:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				default:
				break;
			}
			break;
			
			case 4:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				default:
				break;
			}
			break;
			
			case 5:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				default:
				break;
			}
			break;
			
			case 6:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				default:
				break;
			}
			break;
			
			case 7:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				default:
				break;
			}
			break;
			
			case 8:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				default:
				break;
			}
			break;
			
			case 9:
			switch(_7SEG_Config[Copy_u8SegName].Type)
			{
				case _7SEG_CommonAnode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuLow);
				break;
				
				case _7SEG_CommonCathode:
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[0].Port,_7SEG_Config[Copy_u8SegName].PinConfig[0].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[1].Port,_7SEG_Config[Copy_u8SegName].PinConfig[1].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[2].Port,_7SEG_Config[Copy_u8SegName].PinConfig[2].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[3].Port,_7SEG_Config[Copy_u8SegName].PinConfig[3].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[4].Port,_7SEG_Config[Copy_u8SegName].PinConfig[4].Pin,DIO_enuLow);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[5].Port,_7SEG_Config[Copy_u8SegName].PinConfig[5].Pin,DIO_enuHigh);
				DIO_enuSetPinValue(_7SEG_Config[Copy_u8SegName].PinConfig[6].Port,_7SEG_Config[Copy_u8SegName].PinConfig[6].Pin,DIO_enuHigh);
				break;
				
				default:
				break;
			}
			break;
			
			default:
			break;
		}
		Ret_enumErrorStatus=DIO_enuOk;
	}
	return Ret_enumErrorStatus;
}

DIO_enuErrorStatus_t SSD_enumSetValueAll(u16 Copy_u8Value)
{
	DIO_enuErrorStatus_t Ret_enumErrorStatus = DIO_enuNOK;
	
	for(u8 Loc_u8Counter=NUM_OF_7SEG -1; Loc_u8Counter >=0; Loc_u8Counter--) //For Loop on the Number of Segments starting With the Segment Representing the Hundreds
	{
		u8 Loc_u8Num = Copy_u8Value % 10; //Get the Hundreds Digit
		Copy_u8Value /= 10; //Get the Next Digit
		Ret_enumErrorStatus = SSD_enumSetValue(Loc_u8Counter, Loc_u8Num); //Set the Value of each Segment
		
		if(Ret_enumErrorStatus != DIO_enuOk)
		{
			break;
		}
	}
	
	return Ret_enumErrorStatus;
}