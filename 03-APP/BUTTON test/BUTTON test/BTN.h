/************************************************************************************************************************************************/
/* File             :       BTN.h                                                                                                          */
/* AUTHOR           :       Ahmed Adel                                                                                                         */
/* Origin Date      :       1/1/2024                                                                                                          */
/* SWC              :       SWitch                                                                                                                 */
/************************************************************************************************************************************************/

#ifndef _HAL_Switch_BTN_H_
#define _HAL_Switch_BTN_H_




/************************************************************************************************************************************************/
/* BTN Error status                                                                                                                             */
/************************************************************************************************************************************************/
typedef enum
{
	HBTN_enuOk,
	HBTN_enuDIOError,
	HBTN_enuNOk,
	HBTN_enuInvalidConnection,
	HBTN_enuInvalidBTN,
	HBTN_enuNullPointer,
}HBTN_enuErrorStatus_t;


/************************************************************************************************************************************************/
/* States of the BTN                                                                                                                            */
/************************************************************************************************************************************************/
typedef enum
{
	HBTN_enuPressed,
	HBTN_enuReleased,
	HBTN_enuHold,
}HBTN_enuState_t;


typedef enum
{
	HBTN_enuPullUp,
	HBTN_enuPullDown,
}HBTN_enuConnectionType_t;

typedef enum
{
	HBTN_enuLOW,
	HBTN_enuHIGH,
}HBTN_enuInput_t;


/************************************************************************************************************************************************/
/* Struct for creating LEDs object with its configuration                                                                                       */
/* pin  : PORT_enuPin0 to PORT_enuPin7 (if exist)                                                                                               */
/* port : PORT_enuPORTA to PORT_enuPORTD (if exist)                                                                                             */
/* connectionType:                                                                                                                              */
/*          - HBTN_enuPullUp                                                                                                                    */
/*          - HBTN_enuPullDown                                                                                                                  */
/************************************************************************************************************************************************/
typedef struct
{
	u8                          pin;
	u8                          port;
	HBTN_enuConnectionType_t    connectionType;
	HBTN_enuState_t             state;

}HBTN_strBTN_t;





/************************************************************************************************************************************************/
/* Function:        HBTN_enuInit()                                                                                                        */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      Initializes the Buttons according to the configuration in HBTN_config.c file                                                            */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - Add the desired BTNs first in the BTNS_list in HBTN_int.h file and configure them HBTN_config.c file                                  */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return HBTN_enuErrorStatus_t                                                                                                           */
/************************************************************************************************************************************************/
HBTN_enuErrorStatus_t HBTN_enuInit(void);


/************************************************************************************************************************************************/
/* Function:        HTBN_enuGetState()                                                                                                          */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      Gets the state of the given BTN and save it in the given pointer                                                                        */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - BTNs must be Initalized using HBTN_enuInit() function                                                                                 */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - @param Copy_enuBTN The BTN name as added in the HBTN_enuBTNsList_t in HBTN_config.h file                                              */
/*      - @param Add_u8State The pointer through which the state of the BTN is returned                                                         */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      @return HBTN_enuErrorStatus_t                                                                                                           */
/************************************************************************************************************************************************/
HBTN_enuErrorStatus_t HTBN_enuGetState(HBTN_enuBTNsList_t Copy_enuBTN ,HBTN_enuState_t * Add_u8State);


/************************************************************************************************************************************************/
/* Function:        HBTN_enuUpdate()                                                                                                            */
/*                                                                                                                                              */
/* Description:                                                                                                                                 */
/*      Updates the BTNs_config array according to the hardware state of the BTNs                                                               */
/*                                                                                                                                              */
/* Pre-Conditions:                                                                                                                              */
/*      - BTNs must be Initialized firts using HBTN_enuInit() function                                                                          */
/*                                                                                                                                              */
/* Parameters:                                                                                                                                  */
/*      - None                                                                                                                                  */
/*                                                                                                                                              */
/* RETURN:                                                                                                                                      */
/*      - @return HBTN_enuErrorStatus_t                                                                                                         */
/************************************************************************************************************************************************/
// HBTN_enuErrorStatus_t HBTN_enuUpdate(void);

#endif /* 02_HAL_BTN_BTN_H_ */