
#include "STD_TYPES.h"
#include "Target.h"
#include "PORT_config.h"
#include "PORT_interface.h"



/************************************************************************************************************************************************/
/* Please configure the Mode for each Pin                                                                                                       */
/* Each index in the array represents a pin in the MCU                                                                                          */

/* Options:                                                                                                                                     */
/*      0-  PIN_INPUT_FLOATING                                                                                                                  */
/*      1-  PIN_INPUT_PULLUP                                                                                                                    */
/*      2-  PIN_OUTPUT_LOW                                                                                                                      */
/*      3-  PIN_OUTPUT_HIGH                                                                                                                     */
/************************************************************************************************************************************************/

#if NUMBER_OF_PINS == 32

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
	PIN_INPUT_PULLUP,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING,     /* Pin 7 */
    PIN_INPUT_FLOATING,     /* Pin 8 */
    PIN_INPUT_FLOATING,     /* Pin 9 */
    PIN_INPUT_FLOATING,     /* Pin 10 */
    PIN_INPUT_FLOATING,     /* Pin 11 */
    PIN_INPUT_FLOATING,     /* Pin 12 */
    PIN_INPUT_FLOATING,     /* Pin 13 */
    PIN_INPUT_FLOATING,     /* Pin 14 */
    PIN_INPUT_FLOATING,     /* Pin 15 */
    PIN_INPUT_FLOATING,     /* Pin 16 */
    PIN_INPUT_FLOATING,     /* Pin 17 */
    PIN_INPUT_FLOATING,     /* Pin 18 */
    PIN_INPUT_FLOATING,     /* Pin 19 */
    PIN_INPUT_FLOATING,     /* Pin 20 */
    PIN_INPUT_FLOATING,     /* Pin 21 */
    PIN_INPUT_FLOATING,     /* Pin 22 */
    PIN_INPUT_FLOATING,     /* Pin 23 */
    PIN_INPUT_FLOATING,     /* Pin 24 */
    PIN_INPUT_FLOATING,     /* Pin 25 */
    PIN_INPUT_FLOATING,     /* Pin 26 */
    PIN_INPUT_FLOATING,     /* Pin 27 */
    PIN_INPUT_FLOATING,     /* Pin 28 */
    PIN_INPUT_FLOATING,     /* Pin 29 */
    PIN_INPUT_FLOATING,     /* Pin 30 */
	PIN_OUTPUT_HIGH     /* Pin 31 */
};

#elif NUMBER_OF_PINS == 28

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING,     /* Pin 7 */
    PIN_INPUT_FLOATING,     /* Pin 8 */
    PIN_INPUT_FLOATING,     /* Pin 9 */
    PIN_INPUT_FLOATING,     /* Pin 10 */
    PIN_INPUT_FLOATING,     /* Pin 11 */
    PIN_INPUT_FLOATING,     /* Pin 12 */
    PIN_INPUT_FLOATING,     /* Pin 13 */
    PIN_INPUT_FLOATING,     /* Pin 14 */
    PIN_INPUT_FLOATING,     /* Pin 15 */
    PIN_INPUT_FLOATING,     /* Pin 16 */
    PIN_INPUT_FLOATING,     /* Pin 17 */
    PIN_INPUT_FLOATING,     /* Pin 18 */
    PIN_INPUT_FLOATING,     /* Pin 19 */
    PIN_INPUT_FLOATING,     /* Pin 20 */
    PIN_INPUT_FLOATING,     /* Pin 21 */
    PIN_INPUT_FLOATING,     /* Pin 22 */
    PIN_INPUT_FLOATING,     /* Pin 23 */
    PIN_INPUT_FLOATING,     /* Pin 24 */
    PIN_INPUT_FLOATING,     /* Pin 25 */
    PIN_INPUT_FLOATING,     /* Pin 26 */
    PIN_INPUT_FLOATING     /* Pin 27 */
};

#elif NUMBER_OF_PINS == 24

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING,     /* Pin 7 */
    PIN_INPUT_FLOATING,     /* Pin 8 */
    PIN_INPUT_FLOATING,     /* Pin 9 */
    PIN_INPUT_FLOATING,     /* Pin 10 */
    PIN_INPUT_FLOATING,     /* Pin 11 */
    PIN_INPUT_FLOATING,     /* Pin 12 */
    PIN_INPUT_FLOATING,     /* Pin 13 */
    PIN_INPUT_FLOATING,     /* Pin 14 */
    PIN_INPUT_FLOATING,     /* Pin 15 */
    PIN_INPUT_FLOATING,     /* Pin 16 */
    PIN_INPUT_FLOATING,     /* Pin 17 */
    PIN_INPUT_FLOATING,     /* Pin 18 */
    PIN_INPUT_FLOATING,     /* Pin 19 */
    PIN_INPUT_FLOATING,     /* Pin 20 */
    PIN_INPUT_FLOATING,     /* Pin 21 */
    PIN_INPUT_FLOATING,     /* Pin 22 */
    PIN_INPUT_FLOATING     /* Pin 23 */
};

#elif NUMBER_OF_PINS == 21

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING,     /* Pin 7 */
    PIN_INPUT_FLOATING,     /* Pin 8 */
    PIN_INPUT_FLOATING,     /* Pin 9 */
    PIN_INPUT_FLOATING,     /* Pin 10 */
    PIN_INPUT_FLOATING,     /* Pin 11 */
    PIN_INPUT_FLOATING,     /* Pin 12 */
    PIN_INPUT_FLOATING,     /* Pin 13 */
    PIN_INPUT_FLOATING,     /* Pin 14 */
    PIN_INPUT_FLOATING,     /* Pin 15 */
    PIN_INPUT_FLOATING,     /* Pin 16 */
    PIN_INPUT_FLOATING,     /* Pin 17 */
    PIN_INPUT_FLOATING,     /* Pin 18 */
    PIN_INPUT_FLOATING,     /* Pin 19 */
    PIN_INPUT_FLOATING     /* Pin 20 */
};

#elif NUMBER_OF_PINS == 18

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING,     /* Pin 7 */
    PIN_INPUT_FLOATING,     /* Pin 8 */
    PIN_INPUT_FLOATING,     /* Pin 9 */
    PIN_INPUT_FLOATING,     /* Pin 10 */
    PIN_INPUT_FLOATING,     /* Pin 11 */
    PIN_INPUT_FLOATING,     /* Pin 12 */
    PIN_INPUT_FLOATING,     /* Pin 13 */
    PIN_INPUT_FLOATING,     /* Pin 14 */
    PIN_INPUT_FLOATING,     /* Pin 15 */
    PIN_INPUT_FLOATING,     /* Pin 16 */
    PIN_INPUT_FLOATING     /* Pin 17 */
};

#elif NUMBER_OF_PINS == 16

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING,     /* Pin 7 */
    PIN_INPUT_FLOATING,     /* Pin 8 */
    PIN_INPUT_FLOATING,     /* Pin 9 */
    PIN_INPUT_FLOATING,     /* Pin 10 */
    PIN_INPUT_FLOATING,     /* Pin 11 */
    PIN_INPUT_FLOATING,     /* Pin 12 */
    PIN_INPUT_FLOATING,     /* Pin 13 */
    PIN_INPUT_FLOATING,     /* Pin 14 */
    PIN_INPUT_FLOATING     /* Pin 15 */
};

#elif NUMBER_OF_PINS == 14

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING,     /* Pin 7 */
    PIN_INPUT_FLOATING,     /* Pin 8 */
    PIN_INPUT_FLOATING,     /* Pin 9 */
    PIN_INPUT_FLOATING,     /* Pin 10 */
    PIN_INPUT_FLOATING,     /* Pin 11 */
    PIN_INPUT_FLOATING,     /* Pin 12 */
    PIN_INPUT_FLOATING     /* Pin 13 */
};

#elif NUMBER_OF_PINS == 12

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING,     /* Pin 7 */
    PIN_INPUT_FLOATING,     /* Pin 8 */
    PIN_INPUT_FLOATING,     /* Pin 9 */
    PIN_INPUT_FLOATING,     /* Pin 10 */
    PIN_INPUT_FLOATING     /* Pin 11 */
};

#elif NUMBER_OF_PINS == 8

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING,     /* Pin 6 */
    PIN_INPUT_FLOATING     /* Pin 7 */

};

#elif NUMBER_OF_PINS == 7

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING,     /* Pin 5 */
    PIN_INPUT_FLOATING     /* Pin 6 */
};

#elif NUMBER_OF_PINS == 6

u8 PORT_u8ArrPinsConfig[NUMBER_OF_PINS] = {
    PIN_INPUT_FLOATING,     /* Pin 0 */
    PIN_INPUT_FLOATING,     /* Pin 1 */
    PIN_INPUT_FLOATING,     /* Pin 2 */
    PIN_INPUT_FLOATING,     /* Pin 3 */
    PIN_INPUT_FLOATING,     /* Pin 4 */
    PIN_INPUT_FLOATING     /* Pin 5 */
};

#endif