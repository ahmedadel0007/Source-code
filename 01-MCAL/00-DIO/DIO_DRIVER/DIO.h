/*
 * DIO.h
 *
 * Created: 11/28/2023 12:43:39 AM
 *  Author: Ahmedadel007
 */ 


#ifndef DIO_H_
#define DIO_H_
#define ENABLE			0x01
#define DISABLE			0x00
#define TOGGLE_TASK		ENABLE
#define BINARY_REP		DISABLE

#include "DIO_private.h"
#include "D:\workspace\ITI_ES_INTAKE44\00-LIB\STD_TYPES"

/***************************MACROs Declerations**************************************/

#define  PORT_OUTPUT		0xFF
#define  PORT_INPUT			0x00
#define  PORT_PULLUP_ON		0xFF
#define	 PORT_PULLDOWN_ON	0x00
#define  PORT_LOGIC_HIGH	0xFF
#define	 PORT_LOGIC_LOW		0x00
#define  BUTTON_PRESSED	    0x01
#define  BUTTON_RELEASED	0x00
#define F_CPU				8000000
			
/************************************************************************************/

/************************************************************************/
/*************Functions Declaration(DIO_MODULE_INTERFACES)***************/
/************************************************************************/

/**
 *@brief : The ports Type of the AVR Atmega32                            
 */
typedef enum
{  
	DIO_enumPortA,
	DIO_enumPortB,
	DIO_enumPortC,
	DIO_enumPortD
}DIO_enumPorts_t;

/**
 *@brief : The Error List Type                                           
 */
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function Performed Correctly.
	 */
	DIO_enumOk,             
	/**
	 *@brief : NULL Pointer is passed.
	 */
	DIO_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	DIO_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	DIO_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	DIO_enumWrongConfig,    
	/**
	 *@brief : Select Logic State type Not Found .
	 */     
	DIO_enumWrongLogic
}DIO_enumError_t;
	
/**
 *@brief : The Configuration Type of Pins to be Input or Output !        
 */
typedef enum
{	
	DIO_enumOutput,             /* Select Pin Configuration to be Output*/
	DIO_enumInputInternalPU,    /*PU : Pull Up                          */
	DIO_enumInputExternalPD     /*PD : Pull Down                        */
}DIO_enumConfig_t;
	
/**
 *@brief :  Logic State Type : HIGH (5V) or LOW(0V )                     
 */
typedef enum
{   
	DIO_enumLogicLow,
	DIO_enumLogicHigh
}DIO_enumLogicState_t;

/**
 *@brief :  Pins Type                                                    
 */
typedef enum
{
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3,
	DIO_enumPin4,
	DIO_enumPin5,
	DIO_enumPin6,
	DIO_enumPin7
}DIO_enumPins_t;


/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig);

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig);

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState);

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState); 
/**
 *@brief : Function to Toggle the Pin.
 *@Param :Port Number,Pin Number.
 *@return:Error State.
 */
DIO_enumError_t DIO_enumTogglePin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum);
/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfigType,volatile DIO_enumLogicState_t* Add_PenumPinValue);

/**
 * \brief 
 * 
 * \param Copy_u32TimeMs
 * 
 * \return void
 */
void DIO_DelayMs(u32 Copy_u32TimeMs);

#endif /* DIO_H_ */