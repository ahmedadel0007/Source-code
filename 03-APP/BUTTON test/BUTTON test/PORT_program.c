/*
Author : Ahmed Adel 
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Target.h"
#include "Registers.h"
#include "PORT_config.h"
#include "PORT_interface.h"

/****************************************** PRE-COMPILATION CONFIGURATION CODE ************************************************************/


#if CONFIGURATION_MODE == PRE_COMPILATION_CONFIGURATION

#define CONCAT_X(b0,b1,b2,b3,b4,b5,b6,b7)   0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONCAT(b0,b1,b2,b3,b4,b5,b6,b7)     CONCAT_X(b0,b1,b2,b3,b4,b5,b6,b7)

PORT_enuErrorStatus_t PORT_enuInit(void)
{


/************************************************************************************/
/* PORT A PRE-COMPILATION CONFIGURATION                                             */
/************************************************************************************/
#if PORT_A_EXIST == EXIST
    #if  PIN_A0_MODE == PIN_INPUT_FLOATING
        #define PIN_A0_DDR  PIN_LOW
        #define PIN_A0_PORT PIN_LOW
    #elif PIN_A0_MODE == PIN_INPUT_PULLUP
        #define PIN_A0_DDR  PIN_LOW
        #define PIN_A0_PORT PIN_HIGH
    #elif PIN_A0_MODE == PIN_OUTPUT_LOW
        #define PIN_A0_DDR  PIN_HIGH
        #define PIN_A0_PORT PIN_LOW
    #elif PIN_A0_MODE == PIN_OUTPUT_HIGH
        #define PIN_A0_DDR  PIN_HIGH
        #define PIN_A0_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_A1_MODE == PIN_INPUT_FLOATING
        #define PIN_A1_DDR  PIN_LOW
        #define PIN_A1_PORT PIN_LOW
    #elif PIN_A1_MODE == PIN_INPUT_PULLUP
        #define PIN_A1_DDR  PIN_LOW
        #define PIN_A1_PORT PIN_HIGH
    #elif PIN_A1_MODE == PIN_OUTPUT_LOW
        #define PIN_A1_DDR  PIN_HIGH
        #define PIN_A1_PORT PIN_LOW
    #elif PIN_A1_MODE == PIN_OUTPUT_HIGH
        #define PIN_A1_DDR  PIN_HIGH
        #define PIN_A1_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_A2_MODE == PIN_INPUT_FLOATING
        #define PIN_A2_DDR  PIN_LOW
        #define PIN_A2_PORT PIN_LOW
    #elif PIN_A2_MODE == PIN_INPUT_PULLUP
        #define PIN_A2_DDR  PIN_LOW
        #define PIN_A2_PORT PIN_HIGH
    #elif PIN_A2_MODE == PIN_OUTPUT_LOW
        #define PIN_A2_DDR  PIN_HIGH
        #define PIN_A2_PORT PIN_LOW
    #elif PIN_A2_MODE == PIN_OUTPUT_HIGH
        #define PIN_A2_DDR  PIN_HIGH
        #define PIN_A2_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_A3_MODE == PIN_INPUT_FLOATING
        #define PIN_A3_DDR  PIN_LOW
        #define PIN_A3_PORT PIN_LOW
    #elif PIN_A3_MODE == PIN_INPUT_PULLUP
        #define PIN_A3_DDR  PIN_LOW
        #define PIN_A3_PORT PIN_HIGH
    #elif PIN_A3_MODE == PIN_OUTPUT_LOW
        #define PIN_A3_DDR  PIN_HIGH
        #define PIN_A3_PORT PIN_LOW
    #elif PIN_A3_MODE == PIN_OUTPUT_HIGH
        #define PIN_A3_DDR  PIN_HIGH
        #define PIN_A3_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_A4_MODE == PIN_INPUT_FLOATING
        #define PIN_A4_DDR  PIN_LOW
        #define PIN_A4_PORT PIN_LOW
    #elif PIN_A4_MODE == PIN_INPUT_PULLUP
        #define PIN_A4_DDR  PIN_LOW
        #define PIN_A4_PORT PIN_HIGH
    #elif PIN_A4_MODE == PIN_OUTPUT_LOW
        #define PIN_A4_DDR  PIN_HIGH
        #define PIN_A4_PORT PIN_LOW
    #elif PIN_A4_MODE == PIN_OUTPUT_HIGH
        #define PIN_A4_DDR  PIN_HIGH
        #define PIN_A4_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_A5_MODE == PIN_INPUT_FLOATING
        #define PIN_A5_DDR  PIN_LOW
        #define PIN_A5_PORT PIN_LOW
    #elif PIN_A5_MODE == PIN_INPUT_PULLUP
        #define PIN_A5_DDR  PIN_LOW
        #define PIN_A5_PORT PIN_HIGH
    #elif PIN_A5_MODE == PIN_OUTPUT_LOW
        #define PIN_A5_DDR  PIN_HIGH
        #define PIN_A5_PORT PIN_LOW
    #elif PIN_A5_MODE == PIN_OUTPUT_HIGH
        #define PIN_A5_DDR  PIN_HIGH
        #define PIN_A5_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

#if PIN_6_EXIST == EXIST
    #if  PIN_A6_MODE == PIN_INPUT_FLOATING
        #define PIN_A6_DDR  PIN_LOW
        #define PIN_A6_PORT PIN_LOW
    #elif PIN_A6_MODE == PIN_INPUT_PULLUP
        #define PIN_A6_DDR  PIN_LOW
        #define PIN_A6_PORT PIN_HIGH
    #elif PIN_A6_MODE == PIN_OUTPUT_LOW
        #define PIN_A6_DDR  PIN_HIGH
        #define PIN_A6_PORT PIN_LOW
    #elif PIN_A6_MODE == PIN_OUTPUT_HIGH
        #define PIN_A6_DDR  PIN_HIGH
        #define PIN_A6_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#else   /* If PIN6 does not exist */
    /* This part is to give a defualt value to the macro so it's easier to concate it later     */
    /* because if the macros does not exist it won't be possible to concate it so will have to  */
    /* make a concate function for each case                                                    */
    #define PIN_D6_DDR      0
    #define PIN_D6_PORT     0
#endif

#if PIN_7_EXIST == EXIST
    #if  PIN_A7_MODE == PIN_INPUT_FLOATING
        #define PIN_A7_DDR  PIN_LOW
        #define PIN_A7_PORT PIN_LOW
    #elif PIN_A7_MODE == PIN_INPUT_PULLUP
        #define PIN_A7_DDR  PIN_LOW
        #define PIN_A7_PORT PIN_HIGH
    #elif PIN_A7_MODE == PIN_OUTPUT_LOW
        #define PIN_A7_DDR  PIN_HIGH
        #define PIN_A7_PORT PIN_LOW
    #elif PIN_A7_MODE == PIN_OUTPUT_HIGH
        #define PIN_A7_DDR  PIN_HIGH
        #define PIN_A7_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#else   /* If PIN6 does not exist */
    /* This part is to give a defualt value to the macro so it's easier to concate it later     */
    /* because if the macros does not exist it won't be possible to concate it so will have to  */
    /* make a concate function for each case                                                    */
    #define PIN_D6_DDR      0
    #define PIN_D6_PORT     0
#endif

#endif/* End of Port A */


/************************************************************************************/
/* PORT B PRE-COMPILATION CONFIGURATION                                             */
/************************************************************************************/
#if PORT_B_EXIST == EXIST
    #if  PIN_B0_MODE == PIN_INPUT_FLOATING
        #define PIN_B0_DDR  PIN_LOW
        #define PIN_B0_PORT PIN_LOW
    #elif PIN_B0_MODE == PIN_INPUT_PULLUP
        #define PIN_B0_DDR  PIN_LOW
        #define PIN_B0_PORT PIN_HIGH
    #elif PIN_B0_MODE == PIN_OUTPUT_LOW
        #define PIN_B0_DDR  PIN_HIGH
        #define PIN_B0_PORT PIN_LOW
    #elif PIN_B0_MODE == PIN_OUTPUT_HIGH
        #define PIN_B0_DDR  PIN_HIGH
        #define PIN_B0_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_B1_MODE == PIN_INPUT_FLOATING
        #define PIN_B1_DDR  PIN_LOW
        #define PIN_B1_PORT PIN_LOW
    #elif PIN_B1_MODE == PIN_INPUT_PULLUP
        #define PIN_B1_DDR  PIN_LOW
        #define PIN_B1_PORT PIN_HIGH
    #elif PIN_B1_MODE == PIN_OUTPUT_LOW
        #define PIN_B1_DDR  PIN_HIGH
        #define PIN_B1_PORT PIN_LOW
    #elif PIN_B1_MODE == PIN_OUTPUT_HIGH
        #define PIN_B1_DDR  PIN_HIGH
        #define PIN_B1_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_B2_MODE == PIN_INPUT_FLOATING
        #define PIN_B2_DDR  PIN_LOW
        #define PIN_B2_PORT PIN_LOW
    #elif PIN_B2_MODE == PIN_INPUT_PULLUP
        #define PIN_B2_DDR  PIN_LOW
        #define PIN_B2_PORT PIN_HIGH
    #elif PIN_B2_MODE == PIN_OUTPUT_LOW
        #define PIN_B2_DDR  PIN_HIGH
        #define PIN_B2_PORT PIN_LOW
    #elif PIN_B2_MODE == PIN_OUTPUT_HIGH
        #define PIN_B2_DDR  PIN_HIGH
        #define PIN_B2_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_B3_MODE == PIN_INPUT_FLOATING
        #define PIN_B3_DDR  PIN_LOW
        #define PIN_B3_PORT PIN_LOW
    #elif PIN_B3_MODE == PIN_INPUT_PULLUP
        #define PIN_B3_DDR  PIN_LOW
        #define PIN_B3_PORT PIN_HIGH
    #elif PIN_B3_MODE == PIN_OUTPUT_LOW
        #define PIN_B3_DDR  PIN_HIGH
        #define PIN_B3_PORT PIN_LOW
    #elif PIN_B3_MODE == PIN_OUTPUT_HIGH
        #define PIN_B3_DDR  PIN_HIGH
        #define PIN_B3_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_B4_MODE == PIN_INPUT_FLOATING
        #define PIN_B4_DDR  PIN_LOW
        #define PIN_B4_PORT PIN_LOW
    #elif PIN_B4_MODE == PIN_INPUT_PULLUP
        #define PIN_B4_DDR  PIN_LOW
        #define PIN_B4_PORT PIN_HIGH
    #elif PIN_B4_MODE == PIN_OUTPUT_LOW
        #define PIN_B4_DDR  PIN_HIGH
        #define PIN_B4_PORT PIN_LOW
    #elif PIN_B4_MODE == PIN_OUTPUT_HIGH
        #define PIN_B4_DDR  PIN_HIGH
        #define PIN_B4_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_B5_MODE == PIN_INPUT_FLOATING
        #define PIN_B5_DDR  PIN_LOW
        #define PIN_B5_PORT PIN_LOW
    #elif PIN_B5_MODE == PIN_INPUT_PULLUP
        #define PIN_B5_DDR  PIN_LOW
        #define PIN_B5_PORT PIN_HIGH
    #elif PIN_B5_MODE == PIN_OUTPUT_LOW
        #define PIN_B5_DDR  PIN_HIGH
        #define PIN_B5_PORT PIN_LOW
    #elif PIN_B5_MODE == PIN_OUTPUT_HIGH
        #define PIN_B5_DDR  PIN_HIGH
        #define PIN_B5_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

#if PIN_6_EXIST == EXIST
    #if  PIN_B6_MODE == PIN_INPUT_FLOATING
        #define PIN_B6_DDR  PIN_LOW
        #define PIN_B6_PORT PIN_LOW
    #elif PIN_B6_MODE == PIN_INPUT_PULLUP
        #define PIN_B6_DDR  PIN_LOW
        #define PIN_B6_PORT PIN_HIGH
    #elif PIN_B6_MODE == PIN_OUTPUT_LOW
        #define PIN_B6_DDR  PIN_HIGH
        #define PIN_B6_PORT PIN_LOW
    #elif PIN_B6_MODE == PIN_OUTPUT_HIGH
        #define PIN_B6_DDR  PIN_HIGH
        #define PIN_B6_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#else   /* If PIN6 does not exist */
    /* This part is to give a defualt value to the macro so it's easier to concate it later     */
    /* because if the macros does not exist it won't be possible to concate it so will have to  */
    /* make a concate function for each case                                                    */
    #define PIN_D6_DDR      0
    #define PIN_D6_PORT     0
#endif

#if PIN_7_EXIST == EXIST
    #if  PIN_B7_MODE == PIN_INPUT_FLOATING
        #define PIN_B7_DDR  PIN_LOW
        #define PIN_B7_PORT PIN_LOW
    #elif PIN_B7_MODE == PIN_INPUT_PULLUP
        #define PIN_B7_DDR  PIN_LOW
        #define PIN_B7_PORT PIN_HIGH
    #elif PIN_B7_MODE == PIN_OUTPUT_LOW
        #define PIN_B7_DDR  PIN_HIGH
        #define PIN_B7_PORT PIN_LOW
    #elif PIN_B7_MODE == PIN_OUTPUT_HIGH
        #define PIN_B7_DDR  PIN_HIGH
        #define PIN_B7_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#else   /* If PIN7 does not exist */
    /* This part is to give a defualt value to the macro so it's easier to concate it later     */
    /* because if the macros does not exist it won't be possible to concate it so will have to  */
    /* make a concate function for each case                                                    */
    #define PIN_D7_DDR      0
    #define PIN_D7_PORT     0
#endif

#endif/* End of Port B */


/************************************************************************************/
/* PORT C PRE-COMPILATION CONFIGURATION                                             */
/************************************************************************************/
#if PORT_C_EXIST == EXIST
    #if  PIN_C0_MODE == PIN_INPUT_FLOATING
        #define PIN_C0_DDR  PIN_LOW
        #define PIN_C0_PORT PIN_LOW
    #elif PIN_C0_MODE == PIN_INPUT_PULLUP
        #define PIN_C0_DDR  PIN_LOW
        #define PIN_C0_PORT PIN_HIGH
    #elif PIN_C0_MODE == PIN_OUTPUT_LOW
        #define PIN_C0_DDR  PIN_HIGH
        #define PIN_C0_PORT PIN_LOW
    #elif PIN_C0_MODE == PIN_OUTPUT_HIGH
        #define PIN_C0_DDR  PIN_HIGH
        #define PIN_C0_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_C1_MODE == PIN_INPUT_FLOATING
        #define PIN_C1_DDR  PIN_LOW
        #define PIN_C1_PORT PIN_LOW
    #elif PIN_C1_MODE == PIN_INPUT_PULLUP
        #define PIN_C1_DDR  PIN_LOW
        #define PIN_C1_PORT PIN_HIGH
    #elif PIN_C1_MODE == PIN_OUTPUT_LOW
        #define PIN_C1_DDR  PIN_HIGH
        #define PIN_C1_PORT PIN_LOW
    #elif PIN_C1_MODE == PIN_OUTPUT_HIGH
        #define PIN_C1_DDR  PIN_HIGH
        #define PIN_C1_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_C2_MODE == PIN_INPUT_FLOATING
        #define PIN_C2_DDR  PIN_LOW
        #define PIN_C2_PORT PIN_LOW
    #elif PIN_C2_MODE == PIN_INPUT_PULLUP
        #define PIN_C2_DDR  PIN_LOW
        #define PIN_C2_PORT PIN_HIGH
    #elif PIN_C2_MODE == PIN_OUTPUT_LOW
        #define PIN_C2_DDR  PIN_HIGH
        #define PIN_C2_PORT PIN_LOW
    #elif PIN_C2_MODE == PIN_OUTPUT_HIGH
        #define PIN_C2_DDR  PIN_HIGH
        #define PIN_C2_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_C3_MODE == PIN_INPUT_FLOATING
        #define PIN_C3_DDR  PIN_LOW
        #define PIN_C3_PORT PIN_LOW
    #elif PIN_C3_MODE == PIN_INPUT_PULLUP
        #define PIN_C3_DDR  PIN_LOW
        #define PIN_C3_PORT PIN_HIGH
    #elif PIN_C3_MODE == PIN_OUTPUT_LOW
        #define PIN_C3_DDR  PIN_HIGH
        #define PIN_C3_PORT PIN_LOW
    #elif PIN_C3_MODE == PIN_OUTPUT_HIGH
        #define PIN_C3_DDR  PIN_HIGH
        #define PIN_C3_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_C4_MODE == PIN_INPUT_FLOATING
        #define PIN_C4_DDR  PIN_LOW
        #define PIN_C4_PORT PIN_LOW
    #elif PIN_C4_MODE == PIN_INPUT_PULLUP
        #define PIN_C4_DDR  PIN_LOW
        #define PIN_C4_PORT PIN_HIGH
    #elif PIN_C4_MODE == PIN_OUTPUT_LOW
        #define PIN_C4_DDR  PIN_HIGH
        #define PIN_C4_PORT PIN_LOW
    #elif PIN_C4_MODE == PIN_OUTPUT_HIGH
        #define PIN_C4_DDR  PIN_HIGH
        #define PIN_C4_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_C5_MODE == PIN_INPUT_FLOATING
        #define PIN_C5_DDR  PIN_LOW
        #define PIN_C5_PORT PIN_LOW
    #elif PIN_C5_MODE == PIN_INPUT_PULLUP
        #define PIN_C5_DDR  PIN_LOW
        #define PIN_C5_PORT PIN_HIGH
    #elif PIN_C5_MODE == PIN_OUTPUT_LOW
        #define PIN_C5_DDR  PIN_HIGH
        #define PIN_C5_PORT PIN_LOW
    #elif PIN_C5_MODE == PIN_OUTPUT_HIGH
        #define PIN_C5_DDR  PIN_HIGH
        #define PIN_C5_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#if PIN_6_EXIST == EXIST
    #if  PIN_C6_MODE == PIN_INPUT_FLOATING
        #define PIN_C6_DDR  PIN_LOW
        #define PIN_C6_PORT PIN_LOW
    #elif PIN_C6_MODE == PIN_INPUT_PULLUP
        #define PIN_C6_DDR  PIN_LOW
        #define PIN_C6_PORT PIN_HIGH
    #elif PIN_C6_MODE == PIN_OUTPUT_LOW
        #define PIN_C6_DDR  PIN_HIGH
        #define PIN_C6_PORT PIN_LOW
    #elif PIN_C6_MODE == PIN_OUTPUT_HIGH
        #define PIN_C6_DDR  PIN_HIGH
        #define PIN_C6_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#else   /* If PIN6 does not exist */
    /* This part is to give a defualt value to the macro so it's easier to concate it later     */
    /* because if the macros does not exist it won't be possible to concate it so will have to  */
    /* make a concate function for each case                                                    */
    #define PIN_D6_DDR      0
    #define PIN_D6_PORT     0
#endif

#if PIN_7_EXIST == EXIST
    #if  PIN_C7_MODE == PIN_INPUT_FLOATING
        #define PIN_C7_DDR  PIN_LOW
        #define PIN_C7_PORT PIN_LOW
    #elif PIN_C7_MODE == PIN_INPUT_PULLUP
        #define PIN_C7_DDR  PIN_LOW
        #define PIN_C7_PORT PIN_HIGH
    #elif PIN_C7_MODE == PIN_OUTPUT_LOW
        #define PIN_C7_DDR  PIN_HIGH
        #define PIN_C7_PORT PIN_LOW
    #elif PIN_C7_MODE == PIN_OUTPUT_HIGH
        #define PIN_C7_DDR  PIN_HIGH
        #define PIN_C7_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#else   /* If PIN7 does not exist */
    /* This part is to give a defualt value to the macro so it's easier to concate it later     */
    /* because if the macros does not exist it won't be possible to concate it so will have to  */
    /* make a concate function for each case                                                    */
    #define PIN_D7_DDR      0
    #define PIN_D7_PORT     0    
#endif

#endif/* End of Port C */


/************************************************************************************/
/* PORT D PRE-COMPILATION CONFIGURATION                                             */
/************************************************************************************/
#if PORT_D_EXIST == EXIST
    #if  PIN_D0_MODE == PIN_INPUT_FLOATING
        #define PIN_D0_DDR  PIN_LOW
        #define PIN_D0_PORT PIN_LOW
    #elif PIN_D0_MODE == PIN_INPUT_PULLUP
        #define PIN_D0_DDR  PIN_LOW
        #define PIN_D0_PORT PIN_HIGH
    #elif PIN_D0_MODE == PIN_OUTPUT_LOW
        #define PIN_D0_DDR  PIN_HIGH
        #define PIN_D0_PORT PIN_LOW
    #elif PIN_D0_MODE == PIN_OUTPUT_HIGH
        #define PIN_D0_DDR  PIN_HIGH
        #define PIN_D0_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_D1_MODE == PIN_INPUT_FLOATING
        #define PIN_D1_DDR  PIN_LOW
        #define PIN_D1_PORT PIN_LOW
    #elif PIN_D1_MODE == PIN_INPUT_PULLUP
        #define PIN_D1_DDR  PIN_LOW
        #define PIN_D1_PORT PIN_HIGH
    #elif PIN_D1_MODE == PIN_OUTPUT_LOW
        #define PIN_D1_DDR  PIN_HIGH
        #define PIN_D1_PORT PIN_LOW
    #elif PIN_D1_MODE == PIN_OUTPUT_HIGH
        #define PIN_D1_DDR  PIN_HIGH
        #define PIN_D1_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_D2_MODE == PIN_INPUT_FLOATING
        #define PIN_D2_DDR  PIN_LOW
        #define PIN_D2_PORT PIN_LOW
    #elif PIN_D2_MODE == PIN_INPUT_PULLUP
        #define PIN_D2_DDR  PIN_LOW
        #define PIN_D2_PORT PIN_HIGH
    #elif PIN_D2_MODE == PIN_OUTPUT_LOW
        #define PIN_D2_DDR  PIN_HIGH
        #define PIN_D2_PORT PIN_LOW
    #elif PIN_D2_MODE == PIN_OUTPUT_HIGH
        #define PIN_D2_DDR  PIN_HIGH
        #define PIN_D2_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_D3_MODE == PIN_INPUT_FLOATING
        #define PIN_D3_DDR  PIN_LOW
        #define PIN_D3_PORT PIN_LOW
    #elif PIN_D3_MODE == PIN_INPUT_PULLUP
        #define PIN_D3_DDR  PIN_LOW
        #define PIN_D3_PORT PIN_HIGH
    #elif PIN_D3_MODE == PIN_OUTPUT_LOW
        #define PIN_D3_DDR  PIN_HIGH
        #define PIN_D3_PORT PIN_LOW
    #elif PIN_D3_MODE == PIN_OUTPUT_HIGH
        #define PIN_D3_DDR  PIN_HIGH
        #define PIN_D3_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_D4_MODE == PIN_INPUT_FLOATING
        #define PIN_D4_DDR  PIN_LOW
        #define PIN_D4_PORT PIN_LOW
    #elif PIN_D4_MODE == PIN_INPUT_PULLUP
        #define PIN_D4_DDR  PIN_LOW
        #define PIN_D4_PORT PIN_HIGH
    #elif PIN_D4_MODE == PIN_OUTPUT_LOW
        #define PIN_D4_DDR  PIN_HIGH
        #define PIN_D4_PORT PIN_LOW
    #elif PIN_D4_MODE == PIN_OUTPUT_HIGH
        #define PIN_D4_DDR  PIN_HIGH
        #define PIN_D4_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

    #if  PIN_D5_MODE == PIN_INPUT_FLOATING
        #define PIN_D5_DDR  PIN_LOW
        #define PIN_D5_PORT PIN_LOW
    #elif PIN_D5_MODE == PIN_INPUT_PULLUP
        #define PIN_D5_DDR  PIN_LOW
        #define PIN_D5_PORT PIN_HIGH
    #elif PIN_D5_MODE == PIN_OUTPUT_LOW
        #define PIN_D5_DDR  PIN_HIGH
        #define PIN_D5_PORT PIN_LOW
    #elif PIN_D5_MODE == PIN_OUTPUT_HIGH
        #define PIN_D5_DDR  PIN_HIGH
        #define PIN_D5_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif

#if PIN_6_EXIST == EXIST
    #if  PIN_D6_MODE == PIN_INPUT_FLOATING
        #define PIN_D6_DDR  PIN_LOW
        #define PIN_D6_PORT PIN_LOW
    #elif PIN_D6_MODE == PIN_INPUT_PULLUP
        #define PIN_D6_DDR  PIN_LOW
        #define PIN_D6_PORT PIN_HIGH
    #elif PIN_D6_MODE == PIN_OUTPUT_LOW
        #define PIN_D6_DDR  PIN_HIGH
        #define PIN_D6_PORT PIN_LOW
    #elif PIN_D6_MODE == PIN_OUTPUT_HIGH
        #define PIN_D6_DDR  PIN_HIGH
        #define PIN_D6_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#else   /* If PIN6 does not exist */
    /* This part is to give a defualt value to the macro so it's easier to concate it later     */
    /* because if the macros does not exist it won't be possible to concate it so will have to  */
    /* make a concate function for each case                                                    */
    #define PIN_D6_DDR      0
    #define PIN_D6_PORT     0
#endif

#if PIN_7_EXIST == EXIST
    #if  PIN_D7_MODE == PIN_INPUT_FLOATING
        #define PIN_D7_DDR  PIN_LOW
        #define PIN_D7_PORT PIN_LOW
    #elif PIN_D7_MODE == PIN_INPUT_PULLUP
        #define PIN_D7_DDR  PIN_LOW
        #define PIN_D7_PORT PIN_HIGH
    #elif PIN_D7_MODE == PIN_OUTPUT_LOW
        #define PIN_D7_DDR  PIN_HIGH
        #define PIN_D7_PORT PIN_LOW
    #elif PIN_D7_MODE == PIN_OUTPUT_HIGH
        #define PIN_D7_DDR  PIN_HIGH
        #define PIN_D7_PORT PIN_HIGH
    #else
        #error ("Invalid Pin configuration!")
    #endif
#else   /* If PIN7 does not exist */
    /* This part is to give a defualt value to the macro so it's easier to concate it later     */
    /* because if the macros does not exist it won't be possible to concate it so will have to  */
    /* make a concate function for each case                                                    */
    #define PIN_D7_DDR      0
    #define PIN_D7_PORT     0
#endif

#endif/* End of PORT D */




/************************************************************************************/
/* Setting the values of Port A registers                                           */
/************************************************************************************/
#if PORT_A_EXIST == EXIST
DDRA_REG = CONCAT(PIN_A0_DDR, PIN_A1_DDR, PIN_A2_DDR, PIN_A3_DDR,
                  PIN_A4_DDR, PIN_A5_DDR, PIN_A6_DDR, PIN_A7_DDR);

PORTA_REG = CONCAT(PIN_A0_PORT, PIN_A1_PORT, PIN_A2_PORT, PIN_A3_PORT,
                   PIN_A4_PORT, PIN_A5_PORT, PIN_A6_PORT, PIN_A7_PORT);
#endif


/************************************************************************************/
/* Setting the values of Port B registers                                           */
/************************************************************************************/
#if PORT_B_EXIST == EXIST
DDRB_REG = CONCAT(PIN_B0_DDR, PIN_B1_DDR, PIN_B2_DDR, PIN_B3_DDR,
                  PIN_B4_DDR, PIN_B5_DDR, PIN_B6_DDR, PIN_B7_DDR);

PORTB_REG = CONCAT(PIN_B0_PORT, PIN_B1_PORT, PIN_B2_PORT, PIN_B3_PORT,
                   PIN_B4_PORT, PIN_B5_PORT, PIN_B6_PORT, PIN_B7_PORT);
#endif


/************************************************************************************/
/* Setting the values of Port C registers                                           */
/************************************************************************************/
#if PORT_C_EXIST == EXIST
DDRC_REG = CONCAT(PIN_C0_DDR, PIN_C1_DDR, PIN_C2_DDR, PIN_C3_DDR,
                  PIN_C4_DDR, PIN_C5_DDR, PIN_C6_DDR, PIN_C7_DDR);

PORTC_REG = CONCAT(PIN_C0_PORT, PIN_C1_PORT, PIN_C2_PORT, PIN_C3_PORT,
                   PIN_C4_PORT, PIN_C5_PORT, PIN_C6_PORT, PIN_C7_PORT);
#endif


/************************************************************************************/
/* Setting the values of Port D registers                                           */
/************************************************************************************/
#if PORT_D_EXIST == EXIST
DDRD_REG = CONCAT(PIN_D0_DDR, PIN_D1_DDR, PIN_D2_DDR, PIN_D3_DDR,
                  PIN_D4_DDR, PIN_D5_DDR, PIN_D6_DDR, PIN_D7_DDR);

PORTD_REG = CONCAT(PIN_D0_PORT, PIN_D1_PORT, PIN_D2_PORT, PIN_D3_PORT,
                   PIN_D4_PORT, PIN_D5_PORT, PIN_D6_PORT, PIN_D7_PORT);
#endif




return PORT_enuOK;

}
#endif /* End if Pre-Compilation Configration Mode check */



/****************************************** POST-COMPILATION (LINK TIME) CONFIGURATION CODE *************************************************/


#if CONFIGURATION_MODE == POST_COMPILATION_CONFIGURATION

extern u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS];

PORT_enuErrorStatus_t PORT_enuInit(void)
{
    u8 Loc_u8Counter;
    u8 Loc_u8Port;
    u8 Loc_u8Pin;
    for(Loc_u8Counter = 0; Loc_u8Counter < NUMBER_OF_PINS; Loc_u8Counter++)
    {
        #if PIN_6_EXIST && PIN_7_EXIST
            Loc_u8Port = Loc_u8Counter/8;
            Loc_u8Pin = Loc_u8Counter%8;

        #elif PIN_6_EXIST && !PIN_7_EXIST
            Loc_u8Port = Loc_u8Counter/7;
            Loc_u8Pin = Loc_u8Counter%7;

        #elif !PIN_6_EXIST && !PIN_7_EXIST
            Loc_u8Port = Loc_u8Counter/6;
            Loc_u8Pin = Loc_u8Counter%6;

        #endif

        switch(Loc_u8Port)
        {
            #if PORT_A_EXIST
            case PORT_enuPORTA:
                switch(PORT_u8ArrPinsConfig[Loc_u8Counter])
                {
                    case PIN_INPUT_FLOATING:
                        CLR_BIT(DDRA_REG, Loc_u8Pin);
                        CLR_BIT(PORTA_REG, Loc_u8Pin);
                        break;

                    case PIN_INPUT_PULLUP:
                        CLR_BIT(DDRA_REG, Loc_u8Pin);
                        SET_BIT(PORTA_REG, Loc_u8Pin);
                        break;

                    case PIN_OUTPUT_LOW:
                        SET_BIT(DDRA_REG, Loc_u8Pin);
                        CLR_BIT(PORTA_REG, Loc_u8Pin);
                        break;

                    case PIN_OUTPUT_HIGH:
                        SET_BIT(DDRA_REG, Loc_u8Pin);
                        SET_BIT(PORTA_REG, Loc_u8Pin);
                        break;

                    default:
                        break;
                }
                break; /* End of Port A case */
            #endif

            #if PORT_B_EXIST
            case PORT_enuPORTB:
                switch(PORT_u8ArrPinsConfig[Loc_u8Counter])
                {
                    case PIN_INPUT_FLOATING:
                        CLR_BIT(DDRB_REG, Loc_u8Pin);
                        CLR_BIT(PORTB_REG, Loc_u8Pin);
                        break;

                    case PIN_INPUT_PULLUP:
                        CLR_BIT(DDRB_REG, Loc_u8Pin);
                        SET_BIT(PORTB_REG, Loc_u8Pin);
                        break;

                    case PIN_OUTPUT_LOW:
                        SET_BIT(DDRB_REG, Loc_u8Pin);
                        CLR_BIT(PORTB_REG, Loc_u8Pin);
                        break;

                    case PIN_OUTPUT_HIGH:
                        SET_BIT(DDRB_REG, Loc_u8Pin);
                        SET_BIT(PORTB_REG, Loc_u8Pin);
                        break;

                    default:
                        break;
                }
                break; /* End of Port B case */  
            #endif

            #if PORT_C_EXIST
            case PORT_enuPORTC:
                switch(PORT_u8ArrPinsConfig[Loc_u8Counter])
                {
                    case PIN_INPUT_FLOATING:
                        CLR_BIT(DDRC_REG, Loc_u8Pin);
                        CLR_BIT(PORTC_REG, Loc_u8Pin);
                        break;

                    case PIN_INPUT_PULLUP:
                        CLR_BIT(DDRC_REG, Loc_u8Pin);
                        SET_BIT(PORTC_REG, Loc_u8Pin);
                        break;

                    case PIN_OUTPUT_LOW:
                        SET_BIT(DDRC_REG, Loc_u8Pin);
                        CLR_BIT(PORTC_REG, Loc_u8Pin);
                        break;

                    case PIN_OUTPUT_HIGH:
                        SET_BIT(DDRC_REG, Loc_u8Pin);
                        SET_BIT(PORTC_REG, Loc_u8Pin);
                        break;

                    default:
                        break;
                }
                break; /* End of Port C case */  
            #endif

            #if PORT_D_EXIST
            case PORT_enuPORTD:
                switch(PORT_u8ArrPinsConfig[Loc_u8Counter])
                {
                    case PIN_INPUT_FLOATING:
                        CLR_BIT(DDRD_REG, Loc_u8Pin);
                        CLR_BIT(PORTD_REG, Loc_u8Pin);
                        break;

                    case PIN_INPUT_PULLUP:
                        CLR_BIT(DDRD_REG, Loc_u8Pin);
                        SET_BIT(PORTD_REG, Loc_u8Pin);
                        break;

                    case PIN_OUTPUT_LOW:
                        SET_BIT(DDRD_REG, Loc_u8Pin);
                        CLR_BIT(PORTD_REG, Loc_u8Pin);
                        break;

                    case PIN_OUTPUT_HIGH:
                        SET_BIT(DDRD_REG, Loc_u8Pin);
                        SET_BIT(PORTD_REG, Loc_u8Pin);
                        break;

                    default:
                        break;
                }
                break; /* End of Port D case */  
            #endif

            default:
                break;

        }/* End of Port switch */

    }

    return PORT_enuOK;
}


#endif /* End of Post compile config check */



PORT_enuErrorStatus_t PORT_enuSetPinConfig(PORT_strConfig_t * Add_strPinConfig)
{
    PORT_enuErrorStatus_t Ret_enuErrorStatus = PORT_enuOK;

    if(Add_strPinConfig->pin < PORT_enuMaxPin)
    {
        switch(Add_strPinConfig->port)
        {
        #if PORT_A_EXIST
            case PORT_enuPORTA:
                switch(Add_strPinConfig->mode)
                {
                    case PIN_INPUT_FLOATING:
                        CLR_BIT(DDRA_REG, Add_strPinConfig->pin);
                        CLR_BIT(PORTA_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_INPUT_PULLUP:
                        CLR_BIT(DDRA_REG, Add_strPinConfig->pin);
                        SET_BIT(PORTA_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_OUTPUT_LOW:
                        SET_BIT(DDRA_REG, Add_strPinConfig->pin);
                        CLR_BIT(PORTA_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_OUTPUT_HIGH:
                        SET_BIT(DDRA_REG, Add_strPinConfig->pin);
                        SET_BIT(PORTA_REG, Add_strPinConfig->pin);
                        break;
                    
                    default:
                        Ret_enuErrorStatus = PORT_enuWrongConfig;
                        break;
                }
                break;
        #endif/* end of Port A check */

        #if PORT_B_EXIST
            case PORT_enuPORTB:
                switch(Add_strPinConfig->mode)
                {
                    case PIN_INPUT_FLOATING:
                        CLR_BIT(DDRB_REG, Add_strPinConfig->pin);
                        CLR_BIT(PORTB_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_INPUT_PULLUP:
                        CLR_BIT(DDRB_REG, Add_strPinConfig->pin);
                        SET_BIT(PORTB_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_OUTPUT_LOW:
                        SET_BIT(DDRB_REG, Add_strPinConfig->pin);
                        CLR_BIT(PORTB_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_OUTPUT_HIGH:
                        SET_BIT(DDRB_REG, Add_strPinConfig->pin);
                        SET_BIT(PORTB_REG, Add_strPinConfig->pin);
                        break;

                    default:
                        Ret_enuErrorStatus = PORT_enuWrongConfig;
                        break;
                }
                break;
        #endif/* end of Port B check */

        #if PORT_C_EXIST
            case PORT_enuPORTC:
                switch(Add_strPinConfig->mode)
                {
                    case PIN_INPUT_FLOATING:
                        CLR_BIT(DDRC_REG, Add_strPinConfig->pin);
                        CLR_BIT(PORTC_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_INPUT_PULLUP:
                        CLR_BIT(DDRC_REG, Add_strPinConfig->pin);
                        SET_BIT(PORTC_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_OUTPUT_LOW:
                        SET_BIT(DDRC_REG, Add_strPinConfig->pin);
                        CLR_BIT(PORTC_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_OUTPUT_HIGH:
                        SET_BIT(DDRC_REG, Add_strPinConfig->pin);
                        SET_BIT(PORTC_REG, Add_strPinConfig->pin);
                        break;
                    
                    default:
                        Ret_enuErrorStatus = PORT_enuWrongConfig;
                        break;
                }
                break;
        #endif/* end of Port C check */

        #if PORT_D_EXIST
            case PORT_enuPORTD:
                switch(Add_strPinConfig->mode)
                {
                    case PIN_INPUT_FLOATING:
                        CLR_BIT(DDRD_REG, Add_strPinConfig->pin);
                        CLR_BIT(PORTD_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_INPUT_PULLUP:
                        CLR_BIT(DDRD_REG, Add_strPinConfig->pin);
                        SET_BIT(PORTD_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_OUTPUT_LOW:
                        SET_BIT(DDRD_REG, Add_strPinConfig->pin);
                        CLR_BIT(PORTD_REG, Add_strPinConfig->pin);
                        break;

                    case PIN_OUTPUT_HIGH:
                        SET_BIT(DDRD_REG, Add_strPinConfig->pin);
                        SET_BIT(PORTD_REG, Add_strPinConfig->pin);
                        break;

                    default:
                        Ret_enuErrorStatus = PORT_enuWrongConfig;
                        break;
                }
                break;
        #endif/* end of Port D check */

            default:
                Ret_enuErrorStatus = PORT_enuInvalidPort;
                break;

        }/* end of Ports switch */
    }
    else
    {
        Ret_enuErrorStatus = PORT_enuInvalidPin;
    }

    return Ret_enuErrorStatus;
}



// PORT_enuErrorStatus_t PORT_enuSetAllPinsConfig(PORT_strConfig_t * Arr_strPinConfig, u8 Copy_u8Size)
// {
//     PORT_enuErrorStatus_t Ret_enuErrorStatus = PORT_enuOK;
//     /* Iterator */
//     u8 i; 

//     /* Check if the given arr points to NULL */
//     if(Arr_strPinConfig !=  NULL)
//     {
//         for(i = 0; i < Copy_u8Size; i++)
//         {
//             if(Arr_strPinConfig[i].pin < PORT_enuMaxPin)
//             {
//                 switch(Arr_strPinConfig[i].port)
//                 {
//                 #if PORT_A_EXIST
//                     case PORT_enuPORTA:
//                         switch(Arr_strPinConfig[i].mode)
//                         {
//                             case PIN_INPUT_FLOATING:
//                                 CLR_BIT(DDRA_REG, Arr_strPinConfig[i].pin);
//                                 CLR_BIT(PORTA_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_INPUT_PULLUP:
//                                 CLR_BIT(DDRA_REG, Arr_strPinConfig[i].pin);
//                                 SET_BIT(PORTA_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_OUTPUT_LOW:
//                                 SET_BIT(DDRA_REG, Arr_strPinConfig[i].pin);
//                                 CLR_BIT(PORTA_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_OUTPUT_HIGH:
//                                 SET_BIT(DDRA_REG, Arr_strPinConfig[i].pin);
//                                 SET_BIT(PORTA_REG, Arr_strPinConfig[i].pin);
//                                 break;
                            
//                             default:
//                                 Ret_enuErrorStatus = PORT_enuWrongConfig;
//                                 break;
//                         }
//                         break;
//                 #endif/* end of Port A check */

//                 #if PORT_B_EXIST
//                     case PORT_enuPORTB:
//                         switch(Arr_strPinConfig[i].mode)
//                         {
//                             case PIN_INPUT_FLOATING:
//                                 CLR_BIT(DDRB_REG, Arr_strPinConfig[i].pin);
//                                 CLR_BIT(PORTB_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_INPUT_PULLUP:
//                                 CLR_BIT(DDRB_REG, Arr_strPinConfig[i].pin);
//                                 SET_BIT(PORTB_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_OUTPUT_LOW:
//                                 SET_BIT(DDRB_REG, Arr_strPinConfig[i].pin);
//                                 CLR_BIT(PORTB_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_OUTPUT_HIGH:
//                                 SET_BIT(DDRB_REG, Arr_strPinConfig[i].pin);
//                                 SET_BIT(PORTB_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             default:
//                                 Ret_enuErrorStatus = PORT_enuWrongConfig;
//                                 break;
//                         }
//                         break;
//                 #endif/* end of Port B check */

//                 #if PORT_C_EXIST
//                     case PORT_enuPORTC:
//                         switch(Arr_strPinConfig[i].mode)
//                         {
//                             case PIN_INPUT_FLOATING:
//                                 CLR_BIT(DDRC_REG, Arr_strPinConfig[i].pin);
//                                 CLR_BIT(PORTC_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_INPUT_PULLUP:
//                                 CLR_BIT(DDRC_REG, Arr_strPinConfig[i].pin);
//                                 SET_BIT(PORTC_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_OUTPUT_LOW:
//                                 SET_BIT(DDRC_REG, Arr_strPinConfig[i].pin);
//                                 CLR_BIT(PORTC_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_OUTPUT_HIGH:
//                                 SET_BIT(DDRC_REG, Arr_strPinConfig[i].pin);
//                                 SET_BIT(PORTC_REG, Arr_strPinConfig[i].pin);
//                                 break;
                            
//                             default:
//                                 Ret_enuErrorStatus = PORT_enuWrongConfig;
//                                 break;
//                         }
//                         break;
//                 #endif/* end of Port C check */

//                 #if PORT_D_EXIST
//                     case PORT_enuPORTD:
//                         switch(Arr_strPinConfig[i].mode)
//                         {
//                             case PIN_INPUT_FLOATING:
//                                 CLR_BIT(DDRD_REG, Arr_strPinConfig[i].pin);
//                                 CLR_BIT(PORTD_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_INPUT_PULLUP:
//                                 CLR_BIT(DDRD_REG, Arr_strPinConfig[i].pin);
//                                 SET_BIT(PORTD_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_OUTPUT_LOW:
//                                 SET_BIT(DDRD_REG, Arr_strPinConfig[i].pin);
//                                 CLR_BIT(PORTD_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             case PIN_OUTPUT_HIGH:
//                                 SET_BIT(DDRD_REG, Arr_strPinConfig[i].pin);
//                                 SET_BIT(PORTD_REG, Arr_strPinConfig[i].pin);
//                                 break;

//                             default:
//                                 Ret_enuErrorStatus = PORT_enuWrongConfig;
//                                 break;
//                         }
//                         break;
//                 #endif/* end of Port D check */

//                     default:
//                         Ret_enuErrorStatus = PORT_enuInvalidPort;
//                         break;

//                 }/* end of Ports switch */
//             }
//             else
//             {
//                 Ret_enuErrorStatus = PORT_enuInvalidPin;
//             }

//         }/* end of for loop */
//     }
//     else
//     {
//         Ret_enuErrorStatus = PORT_enuNullPointer;
//     }/* end of Null pointer check */

//     return Ret_enuErrorStatus;
// }



PORT_enuErrorStatus_t PORT_enuSetAllPinsConfig(PORT_strConfig_t * Arr_strPinConfig, u8 Copy_u8Size)
{
    PORT_enuErrorStatus_t Ret_enuErrorStatus = PORT_enuOK;
    /* Iterator */
    u8 i; 

    /* Check if the given arr points to NULL */
    if(Arr_strPinConfig !=  NULL)
    {
        for(i = 0; i < Copy_u8Size; i++)
        {
            PORT_enuSetPinConfig(&Arr_strPinConfig[i]);
        }/* end of for loop */
    }
    else
    {
        Ret_enuErrorStatus = PORT_enuNullPointer;
    }/* end of Null pointer check */

    return Ret_enuErrorStatus;
}