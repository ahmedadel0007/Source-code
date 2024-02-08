/************************************************************************************************************************************************/
/* File             :       BTN.c                                                                                                       */
/* AUTHOR           :       Ahmed Adel                                                                                                        */
/* Origin Date      :       1/1/2023                                                                                                          */
/* SWC              :       Switch                                                                                                                 */
/************************************************************************************************************************************************/

#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO.h"

#include "BTN_cfg.h"
#include "BTN.h"

#include <util/delay.h>


extern HBTN_strBTN_t BTNs_config[NUMBER_OF_BTNS];

HBTN_enuErrorStatus_t HBTN_enuInit(void)
{
	HBTN_enuErrorStatus_t Ret_enuErrorStatus = HBTN_enuOk;
	u8 i;

	PORT_strConfig_t Loc_strCurrBTN;
	
	for(i = 0; i < NUMBER_OF_BTNS; i++)
	{
		Loc_strCurrBTN.pin = BTNs_config[i].pin;
		Loc_strCurrBTN.port = BTNs_config[i].port;

		if( BTNs_config[i].connectionType == HBTN_enuPullDown )
		{
			Loc_strCurrBTN.mode = PIN_INPUT_FLOATING;
		}
		else if(BTNs_config[i].connectionType == HBTN_enuPullUp )
		{
			Loc_strCurrBTN.mode = PIN_INPUT_PULLUP;
		}
		else
		{
			Ret_enuErrorStatus = HBTN_enuInvalidConnection;
		}

		/* In case PORT_enuSetPinConfig fails */
		if( PORT_enuSetPinConfig(&Loc_strCurrBTN) )
		{
			Ret_enuErrorStatus = HBTN_enuDIOError;
		}

		}/* End of for loop */

		return Ret_enuErrorStatus;
	}


	// HBTN_enuErrorStatus_t HBTN_enuUpdate(void)
	// {
	//     HBTN_enuErrorStatus_t Ret_enuErrorStatus = HBTN_enuOk;
	//     u8 i;

	//     for(i = 0; i < NUMBER_OF_BTNS; i++)
	//     {
	//         Ret_enuErrorStatus = DIO_enuGetPinValue( BTNs_config[i].port, BTNs_config[i].pin, &(BTNs_config[i].state) );
	//     }

	//     if(Ret_enuErrorStatus != HBTN_enuOk)
	//     {
	//         Ret_enuErrorStatus = HBTN_enuDIOError;
	//     }

	//     return Ret_enuErrorStatus;
	// }


	HBTN_enuErrorStatus_t HTBN_enuGetState(HBTN_enuBTNsList_t Copy_enuBTN ,HBTN_enuState_t * Add_u8State)
	{
		HBTN_enuErrorStatus_t Ret_enuErrorStatus = HBTN_enuOk;
		u8 Loc_enuInput;
		if( Copy_enuBTN < NUMBER_OF_BTNS )
		{
			if(Add_u8State != NULL)
			{
				Ret_enuErrorStatus = DIO_enuGetPinValue(BTNs_config[Copy_enuBTN].port, BTNs_config[Copy_enuBTN].pin, &Loc_enuInput);

				/***************** PULLDOWN CONNECTION CASE **********************/
				if( BTNs_config[Copy_enuBTN].connectionType == HBTN_enuPullDown )
				{
					if( (Loc_enuInput == HBTN_enuHIGH) && (BTNs_config[Copy_enuBTN].state == HBTN_enuReleased ) )
					{
						_delay_ms(50);
						Ret_enuErrorStatus = DIO_enuGetPinValue(BTNs_config[Copy_enuBTN].port, BTNs_config[Copy_enuBTN].pin, &Loc_enuInput);

						if( (Loc_enuInput == HBTN_enuHIGH) && (BTNs_config[Copy_enuBTN].state == HBTN_enuReleased ) )
						{
							BTNs_config[Copy_enuBTN].state = HBTN_enuPressed;
						}
						else {/* do nothing */}
					}
					else if( (Loc_enuInput == HBTN_enuHIGH) && (BTNs_config[Copy_enuBTN].state == HBTN_enuPressed ) )
					{
						BTNs_config[Copy_enuBTN].state = HBTN_enuHold;
					}
					else if (Loc_enuInput == HBTN_enuLOW)
					{
						BTNs_config[Copy_enuBTN].state = HBTN_enuReleased;
					}
					else{/* do nothing */}

					}/* End of PullDown connection case */
					/***************** PULLUP CONNECTION CASE **********************/
					else if(BTNs_config[Copy_enuBTN].connectionType == HBTN_enuPullUp)
					{
						if( (Loc_enuInput == HBTN_enuLOW) && (BTNs_config[Copy_enuBTN].state == HBTN_enuReleased ) )
						{
							_delay_ms(50);
							Ret_enuErrorStatus = DIO_enuGetPinValue(BTNs_config[Copy_enuBTN].port, BTNs_config[Copy_enuBTN].pin, &Loc_enuInput);

							if( (Loc_enuInput == HBTN_enuLOW) && (BTNs_config[Copy_enuBTN].state == HBTN_enuReleased ) )
							{
								BTNs_config[Copy_enuBTN].state = HBTN_enuPressed;
							}
							else {/* do nothing */}
						}
						else if( (Loc_enuInput == HBTN_enuLOW) && (BTNs_config[Copy_enuBTN].state == HBTN_enuPressed) )
						{
							BTNs_config[Copy_enuBTN].state = HBTN_enuHold;
						}
						else if ( Loc_enuInput == HBTN_enuHIGH )
						{
							BTNs_config[Copy_enuBTN].state = HBTN_enuReleased;
						}
						else {/* do nothing */}
						}/* End of PullUp connection case */
						else {/* do nothing */}


						*Add_u8State = BTNs_config[Copy_enuBTN].state;
						}/* End of Null pointer check */
						else
						{
							Ret_enuErrorStatus = HBTN_enuNullPointer;
						}
						}/* End of BTN check */
						else
						{
							Ret_enuErrorStatus = HBTN_enuInvalidBTN;
							}/* End of BTN check */

							return Ret_enuErrorStatus;
						}