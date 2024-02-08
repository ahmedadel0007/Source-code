/*
 * DIO.c
 *
 * Created: 11/28/2023 12:43:56 AM
 *  Author: AhmedAdel007
 */ 

#include "DIO.h"

/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t retErr=DIO_enumOk;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		retErr=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		retErr=DIO_enumWrongPin;
	}
	else if(Copy_enumConfig>DIO_enumInputExternalPD)
	{
		retErr=DIO_enumWrongConfig;
	}
	else  /*Validation Done, and Parameters are correct.*/
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			{
				switch (Copy_enumConfig)
				{
					case DIO_enumOutput:
					{
						SET_BIT(DDRA,Copy_enumPinNum);
						break;
					}
					case DIO_enumInputInternalPU:
					{
						/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated*/
						CLEAR_BIT(DDRA,Copy_enumPinNum);
						SET_BIT(PORTA,Copy_enumPinNum);
						break;
					}
					case DIO_enumInputExternalPD:
					{
						CLEAR_BIT(DDRA,Copy_enumPinNum) ;
						CLEAR_BIT(PORTA,Copy_enumPinNum);
						break;
					}
					default:
					{
						/*Nothing To Do but for MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortB:
			{
				switch (Copy_enumConfig)
				{
					case DIO_enumOutput:
					{
						SET_BIT(DDRB,Copy_enumPinNum);
						break;
					}
					case DIO_enumInputInternalPU:
					{
						/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated*/
						CLEAR_BIT(DDRB,Copy_enumPinNum);
						SET_BIT(PORTB,Copy_enumPinNum);
						break;
					}
					case DIO_enumInputExternalPD:
					{
						CLEAR_BIT(DDRB,Copy_enumPinNum) ;
						CLEAR_BIT(PORTB,Copy_enumPinNum);
						break;
					}
					default:
					{
						/*Nothing To Do but for MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortC:
			{
				switch (Copy_enumConfig)
				{
					case DIO_enumOutput:
					{
						SET_BIT(DDRC,Copy_enumPinNum);
						break;
					}
					case DIO_enumInputInternalPU:
					{
						/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated*/
						CLEAR_BIT(DDRC,Copy_enumPinNum);
						SET_BIT(PORTC,Copy_enumPinNum);
						break;
					}
					case DIO_enumInputExternalPD:
					{
						CLEAR_BIT(DDRC,Copy_enumPinNum) ;
						CLEAR_BIT(PORTC,Copy_enumPinNum);
						break;
					}
					default:
					{
						/*Nothing To Do but for MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortD:
			{
				switch (Copy_enumConfig)
				{
					case DIO_enumOutput:
					{
						SET_BIT(DDRD,Copy_enumPinNum);
						break;
					}
					case DIO_enumInputInternalPU:
					{
						/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated*/
						CLEAR_BIT(DDRD,Copy_enumPinNum);
						SET_BIT(PORTD,Copy_enumPinNum);
						break;
					}
					case DIO_enumInputExternalPD:
					{
						CLEAR_BIT(DDRD,Copy_enumPinNum) ;
						CLEAR_BIT(PORTD,Copy_enumPinNum);
						break;
					}
					default:
					{
						/*Nothing To Do but for MISRA*/
					}
				}
				break;
			}
		}
	}
	return retErr;
}

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t retErr=DIO_enumOk;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		retErr=DIO_enumWrongPort;
	}
	else if(Copy_enumConfig>DIO_enumInputExternalPD)
	{
		retErr=DIO_enumWrongConfig;
	}
	else  /*Validation Done, and Parameters are correct.*/
	{
		switch (Copy_enumPortNum)
		{
			case DIO_enumPortA:
			{
				switch (Copy_enumConfig)
				{
					case DIO_enumOutput:
					{
						DDRA=PORT_OUTPUT; /* Set the Whole port at time to be output pins*/
						break;
					}
					case DIO_enumInputInternalPU:
					{
						/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated*/
						DDRA =PORT_INPUT;
						PORTA=PORT_PULLUP_ON;
						break;
					}
					case DIO_enumInputExternalPD:
					{
						DDRA =PORT_INPUT;
						PORTA=PORT_PULLDOWN_ON;
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortB:
			{
				switch (Copy_enumConfig)
				{
					case DIO_enumOutput:
					{
						DDRB=PORT_OUTPUT; /* Set the Whole port at time to be output pins*/
						break;
					}
					case DIO_enumInputInternalPU:
					{
						/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated*/
						DDRB =PORT_INPUT;
						PORTB=PORT_PULLUP_ON;
						break;
					}
					case DIO_enumInputExternalPD:
					{
						DDRB =PORT_INPUT;
						PORTB=PORT_PULLDOWN_ON;
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortC:
			{
				switch (Copy_enumConfig)
				{
					case DIO_enumOutput:
					{
						DDRC=PORT_OUTPUT; /* Set the Whole port at time to be output pins*/
						break;
					}
					case DIO_enumInputInternalPU:
					{
						/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated*/
						DDRC =PORT_INPUT;
						PORTC=PORT_PULLUP_ON;
						break;
					}
					case DIO_enumInputExternalPD:
					{
						DDRC =PORT_INPUT;
						PORTC=PORT_PULLDOWN_ON;
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortD:
			{
				switch (Copy_enumConfig)
				{
					case DIO_enumOutput:
					{
						DDRD=PORT_OUTPUT; /* Set the Whole port at time to be output pins*/
						break;
					}
					case DIO_enumInputInternalPU:
					{
						/*If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated*/
						DDRD =PORT_INPUT;
						PORTD=PORT_PULLUP_ON;
						break;
					}
					case DIO_enumInputExternalPD:
					{
						DDRD =PORT_INPUT;
						PORTD=PORT_PULLDOWN_ON;
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
		}
	}
	return retErr;
}

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t retErr=DIO_enumOk;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		retErr=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		retErr=DIO_enumWrongPin;
	}
	else if(Copy_enumLogicState>DIO_enumLogicHigh)
	{
		retErr=DIO_enumWrongLogic;
	}
	else  /*Validation Done, and Parameters are correct.*/
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			{
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					{
						SET_BIT(PORTA,Copy_enumPinNum);
						break;
					}
					case DIO_enumLogicLow:
					{
						CLEAR_BIT(PORTA,Copy_enumPinNum);
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortB:
			{
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					{
						SET_BIT(PORTB,Copy_enumPinNum);
						break;
					}
					case DIO_enumLogicLow:
					{
						CLEAR_BIT(PORTB,Copy_enumPinNum);
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortC:
			{
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					{
						SET_BIT(PORTC,Copy_enumPinNum);
						break;
					}
					case DIO_enumLogicLow:
					{
						CLEAR_BIT(PORTC,Copy_enumPinNum);
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortD:
			{
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					{
						SET_BIT(PORTD,Copy_enumPinNum);
						break;
					}
					case DIO_enumLogicLow:
					{
						CLEAR_BIT(PORTD,Copy_enumPinNum);
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			default:
			{
				/*Nothing To Do but For MISRA*/
			}
		}
			
	}
	return retErr;
}

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t retErr=DIO_enumOk;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		retErr=DIO_enumWrongPort;
	}
	else if(Copy_enumLogicState>DIO_enumLogicHigh)
	{
		retErr=DIO_enumWrongLogic;
	}
	else  /*Validation Done, and Parameters are correct.*/
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			{
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					{
						PORTA=PORT_LOGIC_HIGH;
						break;
					}
					case DIO_enumLogicLow:
					{
						PORTA=PORT_LOGIC_LOW;
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortB:
			{
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					{
						PORTB=PORT_LOGIC_HIGH;
						break;
					}
					case DIO_enumLogicLow:
					{
						PORTB=PORT_LOGIC_LOW;
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortC:
			{
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					{
						PORTC=PORT_LOGIC_HIGH;
						break;
					}
					case DIO_enumLogicLow:
					{
						PORTC=PORT_LOGIC_LOW;
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			case DIO_enumPortD:
			{
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
					{
						PORTD=PORT_LOGIC_HIGH;
						break;
					}
					case DIO_enumLogicLow:
					{
						PORTD=PORT_LOGIC_LOW;
						break;
					}
					default:
					{
						/*Nothing To Do but For MISRA*/
					}
				}
				break;
			}
			default:
			{
				/*Nothing To Do but For MISRA*/
			}
		}
		
	}
	return retErr;
}

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfigType,volatile DIO_enumLogicState_t* Add_PenumPinValue)
{
	DIO_enumError_t retErr=DIO_enumOk;
	DIO_enumLogicState_t Loc_BtnState=DIO_enumLogicLow;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		retErr=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		retErr=DIO_enumWrongPin;
	}
	else if(Add_PenumPinValue==NULL)
	{
		retErr=DIO_enumNullPointer;
	}
	else  /*Validation Done, and Parameters are correct.*/
	{
		switch (Copy_enumPortNum)
		{
			case DIO_enumPortA:
			{
				Loc_BtnState=READ_BIT(PINA,Copy_enumPinNum);
				if(Copy_enumConfigType==DIO_enumInputExternalPD)
				{
					if(Loc_BtnState==DIO_enumLogicLow)
					{
						*Add_PenumPinValue=BUTTON_RELEASED;	
					}
					else
					{
						*Add_PenumPinValue=BUTTON_PRESSED;
					}	
				}
				else if(Copy_enumConfigType==DIO_enumInputInternalPU)
				{
					if(Loc_BtnState==DIO_enumLogicLow)
					{
						*Add_PenumPinValue=BUTTON_PRESSED;
					}
					else
					{
						*Add_PenumPinValue=BUTTON_RELEASED;
					}
				}
				
				break;
			}
			case DIO_enumPortB:
			{
				Loc_BtnState=READ_BIT(PINB,Copy_enumPinNum);
				if(Copy_enumConfigType==DIO_enumInputExternalPD)
				{
					if(Loc_BtnState==DIO_enumLogicLow)
					{
						*Add_PenumPinValue=BUTTON_RELEASED;
					}
					else
					{
						*Add_PenumPinValue=BUTTON_PRESSED;
					}
				}
				else if(Copy_enumConfigType==DIO_enumInputInternalPU)
				{
					if(Loc_BtnState==DIO_enumLogicLow)
					{
						*Add_PenumPinValue=BUTTON_PRESSED;
					}
					else
					{
						*Add_PenumPinValue=BUTTON_RELEASED;
					}
				}
				break;
			}
			case DIO_enumPortC:
			{
				Loc_BtnState=READ_BIT(PINC,Copy_enumPinNum);
				if(Copy_enumConfigType==DIO_enumInputExternalPD)
				{
					if(Loc_BtnState==DIO_enumLogicLow)
					{
						*Add_PenumPinValue=BUTTON_RELEASED;
					}
					else
					{
						*Add_PenumPinValue=BUTTON_PRESSED;
					}
				}
				else if(Copy_enumConfigType==DIO_enumInputInternalPU)
				{
					if(Loc_BtnState==DIO_enumLogicLow)
					{
						*Add_PenumPinValue=BUTTON_PRESSED;
					}
					else
					{
						*Add_PenumPinValue=BUTTON_RELEASED;
					}
				}
				break;
			}
			case DIO_enumPortD:
			{
				Loc_BtnState=READ_BIT(PIND,Copy_enumPinNum);
				if(Copy_enumConfigType==DIO_enumInputExternalPD)
				{
					if(Loc_BtnState==DIO_enumLogicLow)
					{
						*Add_PenumPinValue=BUTTON_RELEASED;
					}
					else
					{
						*Add_PenumPinValue=BUTTON_PRESSED;
					}
				}
				else if(Copy_enumConfigType==DIO_enumInputInternalPU)
				{
					if(Loc_BtnState==DIO_enumLogicLow)
					{
						*Add_PenumPinValue=BUTTON_PRESSED;
					}
					else
					{
						*Add_PenumPinValue=BUTTON_RELEASED;
					}
				}
				break;
			}
			default:
			{
				/*Nothing To Do but For MISRA*/
			}
		}
	}
	return retErr;
}

/**
 *@brief : Function to Toggle the Pin.
 *@Param :Port Number,Pin Number.
 *@return:Error State.
 */
DIO_enumError_t DIO_enumTogglePin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum)
{
	DIO_enumError_t retErr=DIO_enumOk;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		retErr=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		retErr=DIO_enumWrongPin;
	}
	
	else  /*Validation Done, and Parameters are correct.*/
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			{
				TOGGLE_BIT(PORTA,Copy_enumPinNum);
				break;
			}
			case DIO_enumPortB:
			{
				TOGGLE_BIT(PORTB,Copy_enumPinNum);
				break;
			}
			case DIO_enumPortC:
			{
				TOGGLE_BIT(PORTC,Copy_enumPinNum);
				break;
			}
			case DIO_enumPortD:
			{
				TOGGLE_BIT(PORTD,Copy_enumPinNum);
				break;
			}
			default:
			{
				/*Nothing To Do but For MISRA*/
			}
		}
		
	}
	return retErr;	
}

void DIO_DelayMs(u32 Copy_u32TimeMs)
{
	void DIO_DelayMs(u32 Copy_u32TimeMs) {
		u32 i, j;
		for (i = 0; i < Copy_u32TimeMs; ++i) {
			for (j = 0; j < 80000; ++j) {
				asm volatile("nop");
			}
		}
	}
}