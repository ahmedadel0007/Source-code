
#include "DIO.h"
#include "LCD.h"
#include "KPD.h"

int main(void)
{
	/*Init LCD*/
	CLCD_voidInit();
	
	/*Init KEYPAD*/
	KPD_Init();
	//LCD_enumWriteCommand(LCD_DISPLAY_CLEAR);
	
	/*Variables for The Operations*/
	u8 Loc_u8FirstNumber=0;
	u8 Loc_u8SecondNumber=0;
	u8 Loc_u8Flag=0;
	u8 Loc_u8Operator=0;
	u8 Loc_u8key=0;
	u8 Loc_u8Result=0;
	u8 Loc_u8InvalidStr[10]="Invalid";
	while(1)
	{
		/*Read if There is a Pressed Key*/
		KEYPAD_enumGetKey(&Loc_u8key);
		
		/*If the Pressed Key is a Number*/
		if(Loc_u8key >= '0' && Loc_u8key<='9')
		{
			/*Print it on the LCD*/
			LCD_enumWriteData(Loc_u8key);
			
			/*If The Flag is 0, It Means The User is Still Entering The First Number And Has Not Entered An Operator*/
			if(Loc_u8Flag == 0)
			{
				Loc_u8FirstNumber*=10;
				Loc_u8FirstNumber+=Loc_u8key-'0'; /*Convert The ASCII to A Number*/
			}
			/*The User is Entering The Second Number*/
			else
			{
				Loc_u8SecondNumber*=10;
				Loc_u8SecondNumber+=Loc_u8key-'0';
			}
			
			/*So It Doesn't Write The Number Continuously*/
			Loc_u8key=0;
		}
		else if(Loc_u8key == '=')
		{
			LCD_enumWriteData(Loc_u8key);
			Loc_u8key=0;;
			
			switch (Loc_u8Operator)
			{
				/*The Operation Is Addition*/
				case 1:
				Loc_u8Result=Loc_u8FirstNumber+Loc_u8SecondNumber;
				LCD_enumWriteNumber(Loc_u8Result);
				break;
				
				/*The Operation Is Subtraction*/
				case 2:
				Loc_u8Result=Loc_u8FirstNumber-Loc_u8SecondNumber;
				LCD_enumWriteNumber(Loc_u8Result);
				break;
				
				/*The Operation Is Multiplication*/
				case 3:
				Loc_u8Result=Loc_u8FirstNumber*Loc_u8SecondNumber;
				LCD_enumWriteNumber(Loc_u8Result);
				break;
				
				/*The Operation Is Division*/
				case 4:
				/*If The Second Number Entered is Zero, Print Invalid*/
				if(Loc_u8SecondNumber==0)
				{
					LCD_enumWriteCommand(LCD_DISPLAY_CLEAR);
					LCD_enumWriteString(Loc_u8InvalidStr);
				}
				else
				{
					Loc_u8Result=Loc_u8FirstNumber/Loc_u8SecondNumber;
					LCD_enumWriteNumber(Loc_u8Result);
				}
				break;
				
				default:
				break;
			}
		}
		else if(Loc_u8key == 'c')
		{
			/*Clear The Screen*/
			LCD_enumWriteCommand(LCD_DISPLAY_CLEAR);
			
			/*Reset The Variables*/
			Loc_u8Flag=0;
			Loc_u8key=0;
			Loc_u8FirstNumber=0;
			Loc_u8SecondNumber=0;
			Loc_u8Operator=0;
			Loc_u8Result=0;
		}
		else 
		{
			/*If The Key Is An Operation*/
			switch (Loc_u8key)
			{
				case '+':
				LCD_enumWriteData(Loc_u8key);
				Loc_u8key=0;
				Loc_u8Operator=1;
				/*Set The Flag So The Next Numbers Entered Are Saved In The Second Number Variable*/
				Loc_u8Flag=1;
				break;
				
				case '-':
				LCD_enumWriteData(Loc_u8key);
				Loc_u8key=0;
				Loc_u8Operator=2;
				Loc_u8Flag=1;
				break;
				
				case '*':
				LCD_enumWriteData(Loc_u8key);
				Loc_u8key=0;
				Loc_u8Operator=3;
				Loc_u8Flag=1;
				break;
				
				case '/':
				LCD_enumWriteData(Loc_u8key);
				Loc_u8key=0;
				Loc_u8Operator=4;
				Loc_u8Flag=1;
				break;
				
				default:
				break;
			}
		}
	}
	return 0;
}