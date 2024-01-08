#include "std_types.h"
#include "bit_math.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"


/******************************************************************************************************************/
/*FUNCTION FOR SETTING THE PIN VALUE IT TAKES 3 ARGUMENTS:THE PORT NUMBER FROM 0 TO 3,PIN 
NUMBER FROM 0 TO 7 AND THE PIN VALUE EITHER 0 OR 1 AND RETURNS THE ERROR STATUS EITHER WRONG 
PORT NUMBER OR WRONG PIN NUMBER OR WRONG PIN VALUE OR EVERY THING IS OK AND SETTING THE PIN VALUE
(CHECK THE OPTIONS ABOVE FOR THIS FUNCTION PARAMETERS TO BE ABLE TO USE THE API WITH A CORRECT BEHAVIOUR)*/

DIO_enumRetErrorState_t DIO_enumSetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinValue){
DIO_enumRetErrorState_t RetErrorState_SetPinValue=RetErrorState_OK;
#if (NUM_OF_PORTS>4||NUM_OF_PORTS<1)
#error "WRONG NUMBER OF PORTS CONFIGURATION"
#endif
if(Copy_u8PinNumber>DIO_U8PIN7||Copy_u8PinNumber<DIO_U8PIN0) 
	RetErrorState_SetPinValue=RetErrorState_NOK_WRONGPINNUMBER;
else if(Copy_u8PinValue>DIO_U8PINSTATEHIGH||Copy_u8PinValue<DIO_U8PINSTATELOW)
	RetErrorState_SetPinValue=RetErrorState_NOK_WRONGPINVALUE;
else if(Copy_u8PortNumber>NUM_OF_PORTS||Copy_u8PortNumber<DIO_U8PORTA){ 
	RetErrorState_SetPinValue=RetErrorState_NOK_WRONGPORTNUMBER;}
else{
#if (NUM_OF_PORTS==4||NUM_OF_PORTS==3||NUM_OF_PORTS==2||NUM_OF_PORTS==1)
if(Copy_u8PortNumber==DIO_U8PORTA){
if(Copy_u8PinValue==1)        SET_BIT(PORTA,Copy_u8PinNumber);
else                          CLEAR_BIT(PORTA,Copy_u8PinNumber);
}
#endif
#if (NUM_OF_PORTS==4||NUM_OF_PORTS==3||NUM_OF_PORTS==2)
if(Copy_u8PortNumber==DIO_U8PORTB){
if(Copy_u8PinValue==1)        SET_BIT(PORTB,Copy_u8PinNumber);
else                          CLEAR_BIT(PORTB,Copy_u8PinNumber);
}
#endif
#if (NUM_OF_PORTS==4||NUM_OF_PORTS==3)
if(Copy_u8PortNumber==DIO_U8PORTC){
if(Copy_u8PinValue==1)        SET_BIT(PORTC,Copy_u8PinNumber);
else                          CLEAR_BIT(PORTC,Copy_u8PinNumber);
}
#endif
#if (NUM_OF_PORTS==4)
if(Copy_u8PortNumber==DIO_U8PORTD){
if(Copy_u8PinValue==1)        SET_BIT(PORTD,Copy_u8PinNumber);
else                          CLEAR_BIT(PORTD,Copy_u8PinNumber);
}
#endif
}
return RetErrorState_SetPinValue;	
}
/**************************************************************************************************************/
/*FUNCTION FOR SETTING THE PORT DIRECTION IT TAKES 2 ARGUMENTS:THE PORT NUMBER FROM
0 TO 3 AND THE PORT DIRECTION FROM 0x0 TO 0xFF AND RETURNS THE ERROR STATUS EITHER 
WRONG PORT NUMBER OR WRONG PORT DIRECTION OR EVERY THING IS OK AND SETTING THE PORT DIRECTION
(CHECK THE OPTIONS ABOVE FOR THIS FUNCTION PARAMETERS TO BE ABLE TO USE THE API WITH A CORRECT BEHAVIOUR)*/

DIO_enumRetErrorState_t DIO_enumSetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue){
DIO_enumRetErrorState_t RetErrorState_SetPortValue=RetErrorState_OK;
#if (NUM_OF_PORTS>4||NUM_OF_PORTS<1)
#error "WRONG NUMBER OF PORTS CONFIGURATION"
#endif
if(Copy_u8PortValue>DIO_U8PORT_HIGH||Copy_u8PortValue<DIO_U8PORT_LOW) 
RetErrorState_SetPortValue=RetErrorState_NOK_WRONGPORTVALUE;
else if(Copy_u8PortNumber>NUM_OF_PORTS||Copy_u8PortNumber<DIO_U8PORTA) 
RetErrorState_SetPortValue=RetErrorState_NOK_WRONGPORTNUMBER;
else{
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3,NUM_OF_PORTS==2,NUM_OF_PORTS==1)
if(Copy_u8PortNumber==DIO_U8PORTA)
PORTA=Copy_u8PortValue;
#endif
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3,NUM_OF_PORTS==2)
if(Copy_u8PortNumber==DIO_U8PORTB) 
PORTB=Copy_u8PortValue;
#endif
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3)
if(Copy_u8PortNumber==DIO_U8PORTC) 
PORTC=Copy_u8PortValue;
#endif
#if (NUM_OF_PORTS==4)
if(Copy_u8PortNumber==DIO_U8PORTD) 
PORTD=Copy_u8PortValue;
#endif
}
return RetErrorState_SetPortValue;
}
/******************************************************************************************************************/
/*FUNCTION FOR GETTING THE PIN VALUE IT TAKES 3 ARGUMENTS:THE PORT NUMBER FROM 0 TO 3,PIN NUMBER FROM
0 TO 7 AND POINTER TO VARIABLE THAT WILL HOLD THE VALUE OF THE PIN EITHER 0 OR 1 AND RETURNS THE ERROR
STATUS EITHER WRONG PORT NUMBER OR WRONG PIN NUMBER OR PASSING NULL POINTER AS AN ARGUMENT OR EVERY 
THING IS OK AND ASSIGNING THE PIN VALUE TO THE VARIABLE THAT WE HAVE PASSED
(CHECK THE OPTIONS ABOVE FOR THIS FUNCTION PARAMETERS TO BE ABLE TO USE THE API WITH A CORRECT BEHAVIOUR)*/

DIO_enumRetErrorState_t DIO_enumGetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 *Copy_pu8PinValue){
DIO_enumRetErrorState_t RetErrorState_GetPinValue=RetErrorState_OK;
#if (NUM_OF_PORTS<1||NUM_OF_PORTS>4)
#error "WRONG NUMBER OF PORTS CONFIGURATION"
#endif
if((Copy_u8PortNumber>NUM_OF_PORTS)||(Copy_u8PortNumber<DIO_U8PORTA)) 
	RetErrorState_GetPinValue=RetErrorState_NOK_WRONGPORTNUMBER;
else if((Copy_u8PinNumber>DIO_U8PIN7)||(Copy_u8PinNumber<DIO_U8PIN0))
	RetErrorState_GetPinValue=RetErrorState_NOK_WRONGPINNUMBER;
else if(Copy_pu8PinValue==NULL)  
	RetErrorState_GetPinValue=RetErrorState_NOK_NULLPTR;
else {
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3,NUM_OF_PORTS==2,NUM_OF_PORTS==1)
if(Copy_u8PortNumber==DIO_U8PORTA)
*Copy_pu8PinValue=GET_BIT(PINA,Copy_u8PinNumber);
#endif
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3,NUM_OF_PORTS==2)
if(Copy_u8PortNumber==2) 
*Copy_pu8PinValue=GET_BIT(PINB,Copy_u8PinNumber);
#endif
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3)
if(Copy_u8PortNumber==DIO_U8PORTC) 
*Copy_pu8PinValue=GET_BIT(PINC,Copy_u8PinNumber);
#endif
#if (NUM_OF_PORTS==4)
if(Copy_u8PortNumber==DIO_U8PORTD) 
*Copy_pu8PinValue=GET_BIT(PIND,Copy_u8PinNumber);
#endif
}
return RetErrorState_GetPinValue;
}
/******************************************************************************************************************/
/*FUNCTION FOR GETTING THE PORT VALUE IT TAKES 3 ARGUMENTS:THE PORT NUMBER FROM 0 TO 3 AND POINTER TO VARIABLE
THAT WILL HOLD THE VALUE OF THE PORT AND RETURNS THE ERROR STATUS EITHER WRONG PORT NUMBER OR PASSING NULL 
POINTER AS AN ARGUMENT OR EVERY THING IS OK AND ASSIGNING THE PORT VALUE TO THE VARIABLE THAT WE HAVE PASSED
(CHECK THE OPTIONS ABOVE FOR THIS FUNCTION PARAMETERS TO BE ABLE TO USE THE API WITH A CORRECT BEHAVIOUR)*/
DIO_enumRetErrorState_t DIO_enumGetPortValue(u8 Copy_u8PortNumber,u8 *Copy_pu8PortValue){
DIO_enumRetErrorState_t RetErrorState_GetPortValue=RetErrorState_OK;
#if (NUM_OF_PORTS<1||NUM_OF_PORTS>4)
#error "WRONG NUMBER OF PORTS CONFIGURATION"
#endif
if((Copy_u8PortNumber>NUM_OF_PORTS)||(Copy_u8PortNumber<DIO_U8PORTA)) 
	RetErrorState_GetPortValue=RetErrorState_NOK_WRONGPORTNUMBER;
else if(Copy_pu8PortValue==NULL)  
	RetErrorState_GetPortValue=RetErrorState_NOK_NULLPTR;
else {
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3,NUM_OF_PORTS==2,NUM_OF_PORTS==1)
if(Copy_u8PortNumber==DIO_U8PORTA)
	*Copy_pu8PortValue=PINA;
#endif
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3,NUM_OF_PORTS==2)
if(Copy_u8PortNumber==DIO_U8PORTB) 
	*Copy_pu8PortValue=PINB;
#endif
#if (NUM_OF_PORTS==4,NUM_OF_PORTS==3)
if(Copy_u8PortNumber==DIO_U8PORTC) 
	*Copy_pu8PortValue=PINC;
#endif
#if (NUM_OF_PORTS==4)
if(Copy_u8PortNumber==DIO_U8PORTD) 
	*Copy_pu8PortValue=PIND;
#endif
}
return RetErrorState_GetPortValue;	
}