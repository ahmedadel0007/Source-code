/************************************************************************************************************************************************/
/* File             :       DIO.h                                                                                                               */
/* AUTHOR           :       Ahmed Adel                                                                                                        */
/* Origin Date      :       25/11/2023                                                                                                          */
/* SWC              :       DIO                                                                                                                 */
/* Target           :       Atmega32                                                                                                            */
/************************************************************************************************************************************************/

#ifndef TASK3_H_
#define TASK3_H_

#define REG_HIGH   0xFF
#define REG_LOW    0x00

#include "STD_TYPES.h"

/************************************************************************************************************************************************/
/* @brief Available DIO Ports.                                                                                                                  */
/************************************************************************************************************************************************/
typedef enum
{
#if PORT_A_EXIST == EXIST
    DIO_enuPORTA = 0,

#endif
#if PORT_B_EXIST == EXIST
    DIO_enuPORTB,

#endif
#if PORT_C_EXIST == EXIST
    DIO_enuPORTC,

#endif
#if PORT_D_EXIST == EXIST
    DIO_enuPORTD,

#endif
    DIO_enuMaxPort,
}DIO_enuPort_t;


/************************************************************************************************************************************************/
/* @brief DIO Available Pins.                                                                                                                   */
/************************************************************************************************************************************************/
typedef enum
{
    DIO_enuPin0 = 0,    
    DIO_enuPin1,    
    DIO_enuPin2,    
    DIO_enuPin3,    
    DIO_enuPin4,    
    DIO_enuPin5,
#if PIN_6_EXIST == EXIST  
    DIO_enuPin6,
#endif
#if PIN_7_EXIST == EXIST
    DIO_enuPin7,
#endif
    DIO_enuMaxPin,    
}DIO_enuPin_t;


/************************************************************************************************************************************************/
/* @brief DIO Error status.                                                                                                                     */
/************************************************************************************************************************************************/
typedef enum
{
    /**
     * @brief Everything Ok, Function had Performed Correctly.
     */
    DIO_enuOk,
	
	DIO_enuNOK,

     /**
     * @brief Null pointer passed.
     */
    DIO_enuNullPointer,

     /**
     * @brief Invalid Port Number.
     */
    DIO_enuInvalidPort,

     /**
     * @brief Invalid Pin number
     */
    DIO_enuInvalidPin,

     /**
     * @brief Passed config is Invalid.
     */
    DIO_enuInvalidConfig,

     /**
     * @brief Passed Logic State is Invalid.
     */
    DIO_enuInvalidState,

    /**
     * @brief Requesting to get value from pin configured as Output or Requesting to set the value of pin condigured as Input.
     */
    DIO_enuInvalidOperation,
}DIO_enuErrorStatus_t;


/************************************************************************************************************************************************/
/* @brief Availbale Pin Configuration Modes.                                                                                                    */
/************************************************************************************************************************************************/
typedef enum
{
    /**
	 *@brief : Select Pin Configuration to be Output .
	 */
    DIO_enuOutput,

    /**
	 *@brief : Select Pin Configuration to be Input with Floating .
	 */
    DIO_enuInputFloating,

    /**
	 *@brief : Select Pin Configuration to be Input with Internal PullUp.
	 */
    DIO_enuInputPullUp,

    DIO_enuMaxConfig
}DIO_enuConfigMode_t;


/************************************************************************************************************************************************/
/* @brief Availbale Pin States : HIGH (5V) or LOW(0V)                                                                                           */
/************************************************************************************************************************************************/
typedef enum
{
    DIO_enuLow,
    DIO_enuHigh
}DIO_enuState_t;


/************************************************************************************************************************************************/
/* Function:        DIO_enuSetPinConfiguration()                                                                                                */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */ 
/*      Sets the given pin in the given port as output, inputfloat, inputPullUp or inputPullDown                                                */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* INPUTS:                                                                                                                                      */
/*      @param  Copy_enuPortNum The port (PortA, PortB, PortC or PortD)                                                                         */
/*      @param  Copy_enuPinNum Pin number (Pin0 -> Pin7)                                                                                        */
/*      @param  Copy_enuMode Pin Mode (Output, IntputFloating, InputPullUp or InputPulldown)                                                    */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return DIO_enuErrorStatus_t                                                                                                            */
/************************************************************************************************************************************************/
DIO_enuErrorStatus_t DIO_enuSetPinConfiguration(DIO_enuPort_t Copy_enuPortNum, DIO_enuPin_t Copy_enuPinNum, DIO_enuConfigMode_t Copy_enuMode);


/************************************************************************************************************************************************/
/* Function:        DIO_enuSetPortConfiguration()                                                                                               */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */ 
/*      Sets the configuration of the whole Port as Ouput, InputFloating, InputPullUp, InputPullDown                                            */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* INPUTS:                                                                                                                                      */
/*      @param  Copy_enuPortNum The port (PortA, PortB, PortC or PortD)                                                                         */
/*      @param  Copy_enuMode Pin Mode (Output, IntputFloating, InputPullUp or InputPulldown)                                                    */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return DIO_enuErrorStatus_t                                                                                                            */
/************************************************************************************************************************************************/
DIO_enuErrorStatus_t DIO_enuSetPortConfiguration(DIO_enuPort_t Copy_enuPortNum, DIO_enuConfigMode_t Copy_enuMode);


/************************************************************************************************************************************************/
/* Function:        DIO_enuSetPinValue()                                                                                                        */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */ 
/*      Sets the value of given Pin in the given Port as High or Low                                                                            */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - Set the Pin configuration as Output using DIO_enuSetPinConfiguration()                                                                */
/*                                                                                                                                              */
/* INPUTS:                                                                                                                                      */
/*      @param  Copy_enuPortNum The port (PortA, PortB, PortC or PortD)                                                                         */
/*      @param  Copy_enuPinNum Pin number (Pin0 -> Pin7)                                                                                        */
/*      @param  Copy_enuState Pin value (Low or High)                                                                                           */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return DIO_enuErrorStatus_t                                                                                                            */
/************************************************************************************************************************************************/
DIO_enuErrorStatus_t DIO_enuSetPinValue(DIO_enuPort_t Copy_enuPortNum, DIO_enuPin_t Copy_enuPinNum, DIO_enuState_t Copy_enuState);


/************************************************************************************************************************************************/
/* Function:        DIO_enuGetPinValue()                                                                                                        */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */ 
/*      Gets the value of given Pin in the given Port and assign the value to the given pointer                                                 */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - Set the Pin configuration as Input using DIO_enuSetPinConfiguration()                                                                 */
/*                                                                                                                                              */
/* INPUTS:                                                                                                                                      */
/*      @param  Copy_enuPortNum The port (PortA, PortB, PortC or PortD)                                                                         */
/*      @param  Copy_enuPinNum Pin number (Pin0 -> Pin7)                                                                                        */
/*      @param Add_pu8Value Pointer through which value is returned                                                                             */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return DIO_enuErrorStatus_t                                                                                                            */
/************************************************************************************************************************************************/
DIO_enuErrorStatus_t DIO_enuGetPinValue(DIO_enuPort_t Copy_enuPortNum, DIO_enuPin_t Copy_enuPinNum, u8 * Add_pu8Value);


/************************************************************************************************************************************************/
/* Function:        DIO_enuSetPortValue()                                                                                                       */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */ 
/*      Sets the value of the whole given Port                                                                                                  */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - Set the Port configuration as Input using DIO_enuSetPortConfiguration() or set each Pin in the port Manually                          */ 
/*        using  DIO_enuSetPinConfiguration()                                                                                                   */
/*                                                                                                                                              */
/* INPUTS:                                                                                                                                      */
/*      @param  Copy_enuPortNum The port (PortA, PortB, PortC or PortD)                                                                         */
/*      @param  Copy_enuPinNum Pin number (Pin0 -> Pin7)                                                                                        */
/*      @param  Copy_u8Value The new value of the Port                                                                                          */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return DIO_enuErrorStatus_t                                                                                                            */
/************************************************************************************************************************************************/
DIO_enuErrorStatus_t DIO_enuSetPortValue(DIO_enuPort_t Copy_enuPortNum, u8 Copy_u8Value);

#endif /* TASK3_H_ */