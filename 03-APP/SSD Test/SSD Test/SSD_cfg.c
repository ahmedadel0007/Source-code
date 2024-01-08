#include "STD_TYPES.h"
#include "DIO.h"
#include "PORT_interface.h"
#include "SSD_cfg.h"
#include "SSD.h"

const _7SEG_StructConfig_t _7SEG_Config[NUM_OF_7SEG] =
{
	[_7SEG_0] =
	{
		.PinConfig[0] = {.Port = DIO_enuPORTA, .Pin = DIO_enuPin0},
		.PinConfig[1] = {.Port = DIO_enuPORTA, .Pin = DIO_enuPin1},
		.PinConfig[2] = {.Port = DIO_enuPORTA, .Pin = DIO_enuPin2},
		.PinConfig[3] = {.Port = DIO_enuPORTA, .Pin = DIO_enuPin3},
		.PinConfig[4] = {.Port = DIO_enuPORTA, .Pin = DIO_enuPin4},
		.PinConfig[5] = {.Port = DIO_enuPORTA, .Pin = DIO_enuPin5},
		.PinConfig[6] = {.Port = DIO_enuPORTA, .Pin = DIO_enuPin6},
		.Type = _7SEG_CommonCathode
	},
	[_7SEG_1] =
	{
		.PinConfig[0] = {.Port = DIO_enuPORTC, .Pin = DIO_enuPin0},
		.PinConfig[1] = {.Port = DIO_enuPORTC, .Pin = DIO_enuPin1},
		.PinConfig[2] = {.Port = DIO_enuPORTC, .Pin = DIO_enuPin2},
		.PinConfig[3] = {.Port = DIO_enuPORTC, .Pin = DIO_enuPin3},
		.PinConfig[4] = {.Port = DIO_enuPORTD, .Pin = DIO_enuPin1},
		.PinConfig[5] = {.Port = DIO_enuPORTD, .Pin = DIO_enuPin4},
		.PinConfig[6] = {.Port = DIO_enuPORTD, .Pin = DIO_enuPin6},
		.Type = _7SEG_CommonCathode
	}
};