#include "STD_TYPES.h"
#include "DIO.h"
#include "PORT_interface.h"



#define PRESSED     0
#define RELEASED    1

#define BTN_PORT    DIO_enuPORTA
#define BTN_PIN     DIO_enuPin0

int main (void)
{
	u8 Loc_u8Number = 254;
	u8 Loc_u8BtnValue = RELEASED;
	u8 Loc_u8BtnState = RELEASED;

	PORT_enuInit();
	//    DIO_enuSetPortValue(DIO_enuPORTC, Loc_u8Number);
	while(1)
	{
		DIO_enuGetPinValue(BTN_PORT, BTN_PIN, &Loc_u8BtnValue);

		if( (Loc_u8BtnState == RELEASED) && (Loc_u8BtnValue == PRESSED))
		{
			DIO_enuSetPinValue(DIO_enuPORTA, DIO_enuPin2, DIO_enuHigh);
			Loc_u8Number++;
			Loc_u8BtnState = PRESSED;
		}
		else if( (Loc_u8BtnState == PRESSED) && (Loc_u8BtnValue == RELEASED))
		{
			Loc_u8BtnState = RELEASED;
		}
		else
		{
			/* do nothing */
		}
	}

	return 0;
}