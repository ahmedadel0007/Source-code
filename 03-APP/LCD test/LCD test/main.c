#include "STD_TYPES.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"

 
 #define F_CPU 1000000UL
 #include <avr/io.h>
 #include <util/delay.h>

 
#define NAME_LEN	13
#define  NUMBER_OF_LCD_COLOUMNS 16
int main(void)
{
	
	CLCD_voidInit();
	char myName[NAME_LEN] = {"Ahmed"};
	u8 loc_iterator = 0;
	CLCD_voidSendString(myName);
	while(1)
	{
		for(loc_iterator = 0 ; loc_iterator < (NUMBER_OF_LCD_COLOUMNS) ; loc_iterator++)
		{
			CLCD_voidSendCommand(LCD_SHIFT_DISPLAY_RIGHT);
			_delay_ms(5000);
		}
		for(loc_iterator = 0 ; loc_iterator < (NUMBER_OF_LCD_COLOUMNS+NAME_LEN) ; loc_iterator++)
		{
			CLCD_voidSendString(LCD_SHIFT_DISPLAY_LEFT);
			_delay_ms(50);
		}
		for(loc_iterator = 0 ; loc_iterator < NAME_LEN ; loc_iterator++)
		{
			CLCD_voidSendString(LCD_SHIFT_DISPLAY_RIGHT);
			_delay_ms(5000);
		}
	}
}