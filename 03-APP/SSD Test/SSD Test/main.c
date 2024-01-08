#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "PORT_config.h"
#include "DIO.h"
#include "SSD.h"


#include <util/delay.h>
#define FCPU	1000000UL

int main()
{
     SSD_enumInit();
  

    while(1)
    {       SSD_enumSetValue(_7SEG_0,8);
		   SSD_enumSetValue(_7SEG_1,8);
		   _delay_ms(200);
        SSD_enumSetValueAll(88);
		_delay_ms(200);
    	//SSD_enumUpdate();

    }

    return 0;
}

