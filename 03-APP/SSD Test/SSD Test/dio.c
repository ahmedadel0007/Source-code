/************************************************************************************************************************************************/
/* File             :       DIO.c                                                                                                               */
/* AUTHOR           :       Ahmed Adel                                                                                                        */
/* Origin Date      :       25/11/2023                                                                                                          */
/* SWC              :       DIO                                                                                                                 */
/* Target           :       Atmega32                                                                                                            */
/************************************************************************************************************************************************/

#include "../../../../../workspace/ITI_ES_INTAKE44/00-LIB/STD_TYPES.h"
#include "../../../../../workspace/ITI_ES_INTAKE44/00-LIB/BIT_MATH.h"
#include "../../../../../workspace/ITI_ES_INTAKE44/00-LIB/Registers.h"
#include "../../../../../workspace/ITI_ES_INTAKE44/00-LIB/Target.h"

#include "DIO.h"



DIO_enuErrorStatus_t DIO_enuSetPinConfiguration(DIO_enuPort_t Copy_enuPortNum, DIO_enuPin_t Copy_enuPinNum, DIO_enuConfigMode_t Copy_enuMode)
{
#if PORT_A_EXIST && PORT_B_EXIST && PORT_C_EXIST && PORT_D_EXIST
    volatile u8* DIO_arrDDR[4] = {&DDRA_REG, &DDRB_REG, &DDRC_REG, &DDRD_REG};
    volatile u8* DIO_arrPORT[4] = {&PORTA_REG, &PORTB_REG, &PORTC_REG, &PORTD_REG};
#elif PORT_A_EXIST && PORT_B_EXIST && PORT_C_EXIST && !PORT_D_EXIST
    volatile u8* DIO_arrDDR[3] = {&DDRA_REG, &DDRB_REG, &DDRC_REG};
    volatile u8* DIO_arrPORT[3] = {&PORTA_REG, &PORTB_REG, &PORTC_REG};

#elif PORT_A_EXIST && PORT_B_EXIST && !PORT_C_EXIST && !PORT_D_EXIST
    volatile u8* DIO_arrDDR[2] = {&DDRA_REG, &DDRB_REG};
    volatile u8* DIO_arrPORT[2] = {&PORTA_REG, &PORTB_REG};

#elif PORT_A_EXIST && !PORT_B_EXIST && !PORT_C_EXIST && !PORT_D_EXIST
    volatile u8* DIO_arrDDR[1] = {&DDRA_REG};
    volatile u8* DIO_arrPORT[1] = {&PORTA_REG};

#elif !PORT_A_EXIST && PORT_B_EXIST && !PORT_C_EXIST && !PORT_D_EXIST
    volatile u8* DIO_arrDDR[1] = {&DDRB_REG};
    volatile u8* DIO_arrPORT[1] = {&PORTB_REG};

#elif !PORT_A_EXIST && !PORT_B_EXIST && PORT_C_EXIST && !PORT_D_EXIST
    volatile u8* DIO_arrDDR[1] = {&DDRC_REG};
    volatile u8* DIO_arrPORT[1] = {&PORTC_REG};

#endif
    DIO_enuErrorStatus_t Ret_enuErrorStatus = DIO_enuOk;

    if( (Copy_enuPortNum >= 0) && (Copy_enuPortNum < DIO_enuMaxPort) )
    {
        if( (Copy_enuPinNum >= 0) && (Copy_enuPinNum < DIO_enuMaxPin) )
        {
            

            /*********************************** START OF FUNCTION CORE ***************************************/

            switch(Copy_enuMode)
            {
                case DIO_enuOutput:
                    SET_BIT( *DIO_arrDDR[Copy_enuPortNum], Copy_enuPinNum );
                    CLR_BIT( *DIO_arrPORT[Copy_enuPortNum], Copy_enuPinNum );
                    break;
                
                case DIO_enuInputFloating:
                    CLR_BIT( *DIO_arrDDR[Copy_enuPortNum], Copy_enuPinNum );
                    CLR_BIT( *DIO_arrPORT[Copy_enuPortNum], Copy_enuPinNum );
                    break;
                
                case DIO_enuInputPullUp:
                    CLR_BIT( *DIO_arrDDR[Copy_enuPortNum], Copy_enuPinNum );
                    SET_BIT( *DIO_arrPORT[Copy_enuPortNum], Copy_enuPinNum );
                    break;
                
                default:
                    Ret_enuErrorStatus = DIO_enuInvalidConfig;
            }

            /*********************************** END   OF FUNCTION CORE ***************************************/

        }
        else
        {
            Ret_enuErrorStatus = DIO_enuInvalidPin;
        } /* End of Pin check */
    }
    else
    {
        Ret_enuErrorStatus = DIO_enuInvalidPort;
    } /* End of Port check */

    return Ret_enuErrorStatus;
}


DIO_enuErrorStatus_t DIO_enuSetPortConfiguration(DIO_enuPort_t Copy_enuPortNum, DIO_enuConfigMode_t Copy_enuMode)
{

   volatile u8* DIO_arrDDR[4] = {&DDRA_REG, &DDRB_REG, &DDRC_REG, &DDRD_REG};
   volatile u8* DIO_arrPORT[4] = {&PORTA_REG, &PORTB_REG, &PORTC_REG, &PORTD_REG};

    DIO_enuErrorStatus_t Ret_enuErrorStatus = DIO_enuOk;

    if( (Copy_enuPortNum >= 0) && (Copy_enuPortNum < DIO_enuMaxPort) )
    {

        /*********************************** START OF FUNCTION CORE ***************************************/

        switch(Copy_enuMode)
        {
            case DIO_enuOutput:
                *DIO_arrDDR[Copy_enuPortNum] = REG_HIGH;
                break;

            case DIO_enuInputFloating:
                *DIO_arrDDR[Copy_enuPortNum] = REG_LOW;
                break;

            case DIO_enuInputPullUp:
                *DIO_arrDDR[Copy_enuPortNum] = REG_LOW;
                *DIO_arrPORT[Copy_enuPortNum] = REG_HIGH;
                break;

            default:
                Ret_enuErrorStatus = DIO_enuInvalidConfig;
        }

        /*********************************** END   OF FUNCTION CORE ***************************************/
    }
    else
    {
        Ret_enuErrorStatus = DIO_enuInvalidPort;
    } /* End of Port check */

    return Ret_enuErrorStatus;
}


DIO_enuErrorStatus_t DIO_enuSetPinValue(DIO_enuPort_t Copy_enuPortNum, DIO_enuPin_t Copy_enuPinNum, DIO_enuState_t Copy_enuState)
{
    DIO_enuErrorStatus_t Ret_enuErrorStatus = DIO_enuOk;

    if( (Copy_enuPinNum >= 0) && (Copy_enuPinNum < DIO_enuMaxPin) )
    {
        switch(Copy_enuPortNum)
        {
#if PORT_A_EXIST == EXIST
            case DIO_enuPORTA:
                /* If pin configuration is set to anything other than Output then return InvalidOperation */
                if( GET_BIT(DDRA_REG, Copy_enuPinNum) == DIO_enuHigh )
                {
                    switch(Copy_enuState)
                    {
                        case DIO_enuLow:
                            CLR_BIT(PORTA_REG, Copy_enuPinNum);
                            break;

                        case DIO_enuHigh:
                            SET_BIT(PORTA_REG, Copy_enuPinNum);
                            break;

                        default:
                            Ret_enuErrorStatus = DIO_enuInvalidState;
                            break;
                    }/* End of State switch */
                }
                else
                {
                    Ret_enuErrorStatus = DIO_enuInvalidOperation;
                }/* End of pin configuration check */

                break;/* End of PortA case */
#endif

#if PORT_B_EXIST == EXIST
            case DIO_enuPORTB:
                 /* If pin configuration is set to anything other than Output then return InvalidOperation */
                if( GET_BIT(DDRB_REG, Copy_enuPinNum) == DIO_enuHigh )
                {
                    switch(Copy_enuState)
                    {
                        case DIO_enuLow:
                            CLR_BIT(PORTB_REG, Copy_enuPinNum);
                            break;

                        case DIO_enuHigh:
                            SET_BIT(PORTB_REG, Copy_enuPinNum);
                            break;

                        default:
                            Ret_enuErrorStatus = DIO_enuInvalidState;
                            break;
                    }/* End of State switch */
                }
                else
                {
                    Ret_enuErrorStatus = DIO_enuInvalidOperation;
                }/* End of pin configuration check */

                break; /* End of PortB case */
#endif

#if PORT_C_EXIST == EXIST
            case DIO_enuPORTC:
                 /* If pin configuration is set to anything other than Output then return InvalidOperation */
                if( GET_BIT(DDRC_REG, Copy_enuPinNum) == DIO_enuHigh )
                {
                    switch(Copy_enuState)
                    {
                        case DIO_enuLow:
                            CLR_BIT(PORTC_REG, Copy_enuPinNum);
                            break;

                        case DIO_enuHigh:
                            SET_BIT(PORTC_REG, Copy_enuPinNum);
                            break;

                        default:
                            Ret_enuErrorStatus = DIO_enuInvalidState;
                            break;
                    }/* End of State switch */
                }
                else
                {
                    Ret_enuErrorStatus = DIO_enuInvalidOperation;
                }/* End of pin configuration check */

                break;/* End of PortC case */
#endif

#if PORT_D_EXIST == EXIST
            case DIO_enuPORTD:
                 /* If pin configuration is set to anything other than Output then return InvalidOperation */
                if( GET_BIT(DDRD_REG, Copy_enuPinNum) == DIO_enuHigh )
                {
                    switch(Copy_enuState)
                    {
                        case DIO_enuLow:
                            CLR_BIT(PORTD_REG, Copy_enuPinNum);
                            break;

                        case DIO_enuHigh:
                            SET_BIT(PORTD_REG, Copy_enuPinNum);
                            break;

                        default:
                        Ret_enuErrorStatus = DIO_enuInvalidState;
                            break;
                    }/* End of State switch */
                }
                else
                {
                    Ret_enuErrorStatus = DIO_enuInvalidOperation;
                }/* End of pin configuration check */

                break;/* End of PortD case */
#endif
            default:
                Ret_enuErrorStatus = DIO_enuInvalidPort;
        }/* End of Port switch */
    }
    else
    {
        Ret_enuErrorStatus = DIO_enuInvalidPin;
    } /* End of Pin check */

    return Ret_enuErrorStatus;
}


DIO_enuErrorStatus_t DIO_enuGetPinValue(DIO_enuPort_t Copy_enuPortNum, DIO_enuPin_t Copy_enuPinNum, u8 * Add_pu8Value)
{
    DIO_enuErrorStatus_t Ret_enuErrorStatus = DIO_enuOk;

    if( (Copy_enuPinNum >= 0) && (Copy_enuPinNum < DIO_enuMaxPin) )
    {
        if( Add_pu8Value != NULL )
        {
            switch(Copy_enuPortNum)
            {
#if PORT_A_EXIST == EXIST
                case DIO_enuPORTA:
                    /* If configuration is set as output then return InvalidOperation */
                    if( GET_BIT(DDRA_REG, Copy_enuPinNum) == DIO_enuLow )
                    {
                        *Add_pu8Value = GET_BIT(PINA_REG, Copy_enuPinNum);
                    }
                    else
                    {
                        Ret_enuErrorStatus = DIO_enuInvalidOperation;
                    }/* End of checking configuration of pin */
                    break;/* End of PortA case */
#endif

#if PORT_B_EXIST == EXIST
                case DIO_enuPORTB:
                    /* If configuration is set as output then return InvalidOperation */
                    if( GET_BIT(DDRB_REG, Copy_enuPinNum) == DIO_enuLow )
                    {
                        *Add_pu8Value = GET_BIT(PINB_REG, Copy_enuPinNum);
                    }
                    else
                    {
                        Ret_enuErrorStatus = DIO_enuInvalidOperation;
                    }/* End of checking configuration of pin */
                    break; /* End of PortB case */
#endif

#if PORT_C_EXIST == EXIST
                case DIO_enuPORTC:
                    /* If configuration is set as output then return InvalidOperation */
                    if( GET_BIT(DDRC_REG, Copy_enuPinNum) == DIO_enuLow )
                    {
                        *Add_pu8Value = GET_BIT(PINC_REG, Copy_enuPinNum);
                    }
                    else
                    {
                        Ret_enuErrorStatus = DIO_enuInvalidOperation;
                    }/* End of checking configuration of pin */
                    break;/* End of PortC case */
#endif

#if PORT_D_EXIST == EXIST
                case DIO_enuPORTD:
                    /* If configuration is set as output then return InvalidOperation */
                    if( GET_BIT(DDRD_REG, Copy_enuPinNum) == DIO_enuLow )
                    {
                        *Add_pu8Value = GET_BIT(PIND_REG, Copy_enuPinNum);
                    }
                    else
                    {
                        Ret_enuErrorStatus = DIO_enuInvalidOperation;
                    }/* End of checking configuration of pin */
                    break;/* End of PortD case */
#endif

                default:
                    Ret_enuErrorStatus = DIO_enuInvalidPort;
            }/* End of Port switch */

        }
        else
        {
            Ret_enuErrorStatus = DIO_enuNullPointer;
        }/* End of Null check */
    }
    else
    {
        Ret_enuErrorStatus = DIO_enuInvalidPin;
    } /* End of Pin check */

    return Ret_enuErrorStatus;
}


DIO_enuErrorStatus_t DIO_enuSetPortValue(DIO_enuPort_t Copy_enuPortNum, u8 Copy_u8Value)
{
    DIO_enuErrorStatus_t Ret_enuErrorStatus = DIO_enuOk;

    switch(Copy_enuPortNum)
    {
#if PORT_A_EXIST == EXIST
        case DIO_enuPORTA:
            /* If Port configuration is set to anything other than OUTPUT then return InvalidOperation */
            if( DDRA_REG == REG_HIGH )
            {
                PORTA_REG = Copy_u8Value;
            }
            else
            {
                Ret_enuErrorStatus = DIO_enuInvalidOperation;
            }/* End of PortA configuration check */

            break;
#endif

#if PORT_B_EXIST == EXIST
        case DIO_enuPORTB:
            /* If Port configuration is set to anything other than OUTPUT then return InvalidOperation */
            if( DDRB_REG == REG_HIGH )
            {
                PORTB_REG = Copy_u8Value;
            }
            else
            {
                Ret_enuErrorStatus = DIO_enuInvalidOperation;
            }/* End of PortB configuration check */

            break;
#endif

#if PORT_C_EXIST == EXIST
        case DIO_enuPORTC:
            /* If Port configuration is set to anything other than OUTPUT then return InvalidOperation */
            if( DDRC_REG == REG_HIGH )
            {
                PORTC_REG = Copy_u8Value;
            }
            else
            {
                Ret_enuErrorStatus = DIO_enuInvalidOperation;
            }/* End of PortC configuration check */

            break;
#endif

#if PORT_D_EXIST == EXIST
        case DIO_enuPORTD:
            /* If Port configuration is set to anything other than OUTPUT then return InvalidOperation */
            if( DDRD_REG == REG_HIGH )
            {
                PORTD_REG = Copy_u8Value;
            }
            else
            {
                Ret_enuErrorStatus = DIO_enuInvalidOperation;
            }/* End of PortD configuration check */

            break;
#endif
        default:
        	Ret_enuErrorStatus = DIO_enuInvalidPort;
        	break;

    }/* End of Port switch */

    return Ret_enuErrorStatus;
}