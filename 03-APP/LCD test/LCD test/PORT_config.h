#ifndef MCAL_01_PORT_PORT_CONFIG_H_
#define MCAL_01_PORT_PORT_CONFIG_H_

/************************************************************************************************************************************************/
/* Available configuration modes                                                                                                                */
/* THE USER MUST NOT CHANGE THESE VALUES!!!!                                                                                                    */
/************************************************************************************************************************************************/
#define PRE_COMPILATION_CONFIGURATION   0
#define POST_COMPILATION_CONFIGURATION  1



/************************************************************************************************************************************************/
/* Please choose the configuration mode for Init function                                                                                       */
/* Options:                                                                                                                                     */
/*      0-  PRE_COMPILATION_CONFIGURATION                                                                                                       */
/*      1-  POST_COMPILATION_CONFIGURATION                                                                                                       */
/************************************************************************************************************************************************/
#define CONFIGURATION_MODE	PRE_COMPILATION_CONFIGURATION


/************************************************************************************************************************************************/
/* Please configure the Mode for each Pin                                                                                                       */
/* Options:                                                                                                                                     */
/*      0-  PIN_INPUT_FLOATING                                                                                                                  */
/*      1-  PIN_INPUT_PULLUP                                                                                                                    */
/*      2-  PIN_OUTPUT_LOW                                                                                                                      */
/*      3-  PIN_OUTPUT_HIGH                                                                                                                     */
/************************************************************************************************************************************************/
#if PORT_A_EXIST == EXIST
#define PIN_A0_MODE     PIN_INPUT_PULLUP
#define PIN_A1_MODE     PIN_INPUT_FLOATING
#define PIN_A2_MODE     PIN_OUTPUT_LOW
#define PIN_A3_MODE     PIN_INPUT_FLOATING
#define PIN_A4_MODE     PIN_INPUT_FLOATING
#define PIN_A5_MODE     PIN_INPUT_FLOATING

#if PIN_6_EXIST == EXIST
#define PIN_A6_MODE     PIN_INPUT_FLOATING
#endif

#if PIN_7_EXIST == EXIST
#define PIN_A7_MODE     PIN_INPUT_FLOATING
#endif
    
#endif/* Port A check */


#if PORT_B_EXIST == EXIST
#define PIN_B0_MODE     PIN_INPUT_FLOATING
#define PIN_B1_MODE     PIN_INPUT_FLOATING
#define PIN_B2_MODE     PIN_INPUT_FLOATING
#define PIN_B3_MODE     PIN_INPUT_FLOATING
#define PIN_B4_MODE     PIN_INPUT_FLOATING
#define PIN_B5_MODE     PIN_INPUT_FLOATING

#if PIN_6_EXIST == EXIST
#define PIN_B6_MODE     PIN_INPUT_FLOATING
#endif

#if PIN_7_EXIST == EXIST
#define PIN_B7_MODE     PIN_INPUT_FLOATING
#endif

#endif/* Port B check */


#if PORT_C_EXIST == EXIST
#define PIN_C0_MODE     PIN_OUTPUT_LOW
#define PIN_C1_MODE     PIN_OUTPUT_LOW
#define PIN_C2_MODE     PIN_OUTPUT_LOW
#define PIN_C3_MODE     PIN_OUTPUT_LOW
#define PIN_C4_MODE     PIN_OUTPUT_LOW
#define PIN_C5_MODE     PIN_OUTPUT_LOW

#if PIN_6_EXIST == EXIST
#define PIN_C6_MODE     PIN_OUTPUT_LOW
#endif

#if PIN_7_EXIST == EXIST
#define PIN_C7_MODE     PIN_OUTPUT_LOW
#endif

#endif/* Port C check */


#if PORT_D_EXIST == EXIST
#define PIN_D0_MODE     PIN_INPUT_FLOATING
#define PIN_D1_MODE     PIN_INPUT_FLOATING
#define PIN_D2_MODE     PIN_INPUT_FLOATING
#define PIN_D3_MODE     PIN_INPUT_FLOATING
#define PIN_D4_MODE     PIN_INPUT_FLOATING
#define PIN_D5_MODE     PIN_INPUT_FLOATING

#if PIN_6_EXIST == EXIST
#define PIN_D6_MODE     PIN_INPUT_FLOATING
#endif

#if PIN_7_EXIST == EXIST
#define PIN_D7_MODE     PIN_INPUT_FLOATING
#endif

#endif/* Port D check */


#endif /* MCAL_01_PORT_PORT_CONFIG_H_ */