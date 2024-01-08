/*
 * PORT_interface.h
 *
 * Created: 2/12/2023 
 *  Author: Ahmedadel007
 */ 

#ifndef MCAL_01_PORT_PORT_H_
#define MCAL_01_PORT_PORT_H_


/************************************************************************************************************************************************/
/* Defining the number of pins according to the available Ports and available Pins in the target in case of Post-Compile config                 */
/************************************************************************************************************************************************/

#if CONFIGURATION_MODE == POST_COMPILATION_CONFIGURATION

#if PIN_6_EXIST && PIN_7_EXIST

#if PORT_A_EXIST && PORT_B_EXIST && PORT_C_EXIST && PORT_D_EXIST
#define NUMBER_OF_PINS		32
#elif PORT_A_EXIST && PORT_B_EXIST && PORT_C_EXIST && !PORT_D_EXIST
#define NUMBER_OF_PINS		24
#elif PORT_A_EXIST && PORT_B_EXIST && !PORT_C_EXIST && !PORT_D_EXIST
#define NUMBER_OF_PINS		16
#else
#define NUMBER_OF_PINS		8
#endif

#elif	PIN_6_EXIST && !PIN_7_EXIST

#if PORT_A_EXIST && PORT_B_EXIST && PORT_C_EXIST && PORT_D_EXIST
#define NUMBER_OF_PINS		28
#elif PORT_A_EXIST && PORT_B_EXIST && PORT_C_EXIST && !PORT_D_EXIST
#define NUMBER_OF_PINS		21
#elif PORT_A_EXIST && PORT_B_EXIST && !PORT_C_EXIST && !PORT_D_EXIST
#define NUMBER_OF_PINS		14
#else
#define NUMBER_OF_PINS		7
#endif

#elif	!PIN_6_EXIST && !PIN_7_EXIST

#if PORT_A_EXIST && PORT_B_EXIST && PORT_C_EXIST && PORT_D_EXIST
#define NUMBER_OF_PINS		24
#elif PORT_A_EXIST && PORT_B_EXIST && PORT_C_EXIST && !PORT_D_EXIST
#define NUMBER_OF_PINS		18
#elif PORT_A_EXIST && PORT_B_EXIST && !PORT_C_EXIST && !PORT_D_EXIST
#define NUMBER_OF_PINS		12
#else
#define NUMBER_OF_PINS		6
#endif

#endif

#endif/* end of configuration mode check */


/************************************************************************************************************************************************/
/* Macros to represent HIGH and LOW values of a pin                                                                                             */
/************************************************************************************************************************************************/
#define PIN_LOW     0   
#define PIN_HIGH    1   


/************************************************************************************************************************************************/
/* Available Modes for each Pin                                                                                                                 */
/* THE USER MUST NOT CHANGE THESE VALUES!!!!                                                                                                    */
/************************************************************************************************************************************************/
#define PIN_INPUT_FLOATING      0
#define PIN_INPUT_PULLUP        1
#define PIN_OUTPUT_LOW          2
#define PIN_OUTPUT_HIGH         3


/************************************************************************************************************************************************/
/* @brief DIO Error status.                                                                                                                     */
/************************************************************************************************************************************************/
typedef enum
{
    PORT_enuOK,
    PORT_enuWrongConfig,
    PORT_enuInvalidPin,
    PORT_enuInvalidPort,
    PORT_enuNullPointer,

}PORT_enuErrorStatus_t;

/************************************************************************************************************************************************/
/* @brief DIO Available Pins.                                                                                                                   */
/************************************************************************************************************************************************/
typedef enum
{
    PORT_enuPin0 = 0,    
    PORT_enuPin1,    
    PORT_enuPin2,    
    PORT_enuPin3,    
    PORT_enuPin4,    
    PORT_enuPin5,
#if PIN_6_EXIST == EXIST  
    PORT_enuPin6,
#endif
#if PIN_7_EXIST == EXIST
    PORT_enuPin7,
#endif
    PORT_enuMaxPin,    
}PORT_enuPin_t;


/************************************************************************************************************************************************/
/* @brief Available DIO Ports.                                                                                                                  */
/************************************************************************************************************************************************/
typedef enum
{
#if PORT_A_EXIST == EXIST
    PORT_enuPORTA = 0,

#endif
#if PORT_B_EXIST == EXIST
    PORT_enuPORTB,

#endif
#if PORT_C_EXIST == EXIST
    PORT_enuPORTC,

#endif
#if PORT_D_EXIST == EXIST
    PORT_enuPORTD,

#endif
    PORT_enuMaxPort,
}PORT_enuPort_t;


/************************************************************************************************************************************************/
/* Struct for configuring each pin                                                                                                              */
/* pin  : PORT_enuPin0 to PORT_enuPin7 (if exist)                                                                                               */
/* port : PORT_enuPORTA to PORT_enuPORTD (if exist)                                                                                             */
/* mode :                                                                                                                                       */
/*      0-  PIN_INPUT_FLOATING                                                                                                                  */
/*      1-  PIN_INPUT_PULLUP                                                                                                                    */
/*      2-  PIN_OUTPUT_LOW                                                                                                                      */
/*      3-  PIN_OUTPUT_HIGH                                                                                                                     */
/************************************************************************************************************************************************/
typedef struct
{
    u8 pin;
    u8 port;
    u8 mode;

}PORT_strConfig_t;


/************************************************************************************************************************************************/
/* Function:        PORT_enuInit()                                                                                                              */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */ 
/*      Initializes the configuration of the DIO pins                                                                                           */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* INPUTS:                                                                                                                                      */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return PORT_enuErrorStatus_t                                                                                                           */
/************************************************************************************************************************************************/
PORT_enuErrorStatus_t PORT_enuInit(void);


/************************************************************************************************************************************************/
/* Function:        PORT_enuSetPinConfig()                                                                                                      */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */ 
/*      Sets the configuration of a specific pin                                                                                                */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - @param Add_strPinConfig Pointer to the pin configuration struct                                                                       */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return PORT_enuErrorStatus_t                                                                                                           */
/************************************************************************************************************************************************/
PORT_enuErrorStatus_t PORT_enuSetPinConfig(PORT_strConfig_t * Add_strPinConfig);


/************************************************************************************************************************************************/
/* Function:        PORT_enuSetAllPinsConfig()                                                                                                  */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */ 
/*      Sets the configuration of all given pins at once                                                                                        */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - @param Arr_strPinConfig Array of PORT_config struct objects                                                                           */
/*      - @param u8 Copy_u8Size Size of the array                                                                                               */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return PORT_enuErrorStatus_t                                                                                                           */
/************************************************************************************************************************************************/
PORT_enuErrorStatus_t PORT_enuSetAllPinsConfig(PORT_strConfig_t * Arr_strPinConfig, u8 Copy_u8Size);

#endif /* MCAL_01_PORT_PORT_H_ */