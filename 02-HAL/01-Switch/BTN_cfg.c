/************************************************************************************************************************************************/
/* File             :       BTN_cfg.c                                                                                                       */
/* AUTHOR           :       Ahmed Adel                                                                                                        */
/* Origin Date      :       1/1/2024                                                                                                          */
/* SWC              :       Switch                                                                                                                 */
/************************************************************************************************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-PORT/PORT_interface.h"
#include "BTN_cfg.h"
#include "BTN.h"




/************************************************************************************************************************************************/
/* This array should contain all BTNs objects                                                                                                   */
/* Each BTN object contains the following:                                                                                                      */
/*                                                                                                                                              */
/* pin            : PORT_enuPin0 to PORT_enuPin7 (if exist)                                                                                     */
/*                                                                                                                                              */
/* port           : PORT_enuPORTA to PORT_enuPORTD (if exist)                                                                                   */
/*                                                                                                                                              */
/* connectionType :                                                                                                                             */
/*          - HBTN_enuPullUp                                                                                                                    */
/*          - HBTN_enuPullDown                                                                                                                  */
/* state          :                                                                                                                             */
/*          - HBTN_enuReleased                                                                                                                  */
/*          - HBTN_enuPressed                                                                                                                   */
/************************************************************************************************************************************************/
HBTN_strBTN_t BTNs_config[NUMBER_OF_BTNS] =
{

	/* ADD YOUT BTN OBJECTS HERE AFTER ADDING IT TO THE BTNS LIST IN THE HBTN_int.h FILE */

	[HBTN_Inc] = {
		.pin = PORT_enuPin0,
		.port = PORT_enuPORTA,
		.connectionType = HBTN_enuPullUp,
		.state = HBTN_enuReleased
	}
	,
	[HBTN_Dec] = {
		.pin = PORT_enuPin1,
		.port = PORT_enuPORTA,
		.connectionType = HBTN_enuPullUp,
		.state = HBTN_enuReleased
	}
	,
	[HBTN_Start] = {
		.pin = PORT_enuPin2,
		.port = PORT_enuPORTA,
		.connectionType = HBTN_enuPullUp,
		.state = HBTN_enuReleased
	}
};