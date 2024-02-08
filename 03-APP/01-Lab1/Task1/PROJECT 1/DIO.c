#include "DIO.h"
#include "D:\embedded system\00-LIB\Bit_Math.h"
#include "DIO_private.h"
#include "D:\embedded system\00-LIB\STD_TYPES.h"
typedef 	unsigned char			u8;
typedef 	unsigned short int		u16;
typedef 	unsigned int 			u32;

typedef 	signed char				s8;
typedef 	signed short int		s16;
typedef 	signed int 				s32;

typedef 	float					f32;
typedef 	double 					f64;

#define     NULL    (void*) 0

/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	

DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enuErrorStatus = DIO_enumWrongPort;
	
	if (Copy_enumPortNum > DIO_enumPortD)
	{
		Ret_enuErrorStatus = DIO_enumWrongPort;
		
	}
	
	else if (Copy_enumPinNum > DIO_enumPin7)
	{
		
		Ret_enuErrorStatus = DIO_enumWrongPin;
		
	}
	
	else if (Copy_enumConfig > DIO_enumInputExternalPD)
	{
		
		Ret_enuErrorStatus = DIO_enumWrongConfig;
		
	}
	
	else 
	{
		Ret_enuErrorStatus = DIO_enumOk;
		
		switch (Copy_enumPortNum)
		{
			case DIO_enumPortA:		
								switch (Copy_enumConfig)
								{
									case DIO_enumOutput: 
															SET_BIT(DDRA,Copy_enumPinNum);
															break;
									
									case DIO_enumInputInternalPU:
																
															CLR_BIT(DDRA,Copy_enumPinNum);
															SET_BIT(PORTA,Copy_enumPinNum);
															break;
									
									case DIO_enumInputExternalPD:
															
															CLR_BIT(DDRA,Copy_enumPinNum);
															CLR_BIT(PORTA,Copy_enumPinNum);
															break;
									
									default:
															break;
								}
								break;
			
			
			
			case DIO_enumPortB:
								switch (Copy_enumConfig)
								{
									case DIO_enumOutput: 
															SET_BIT(DDRB,Copy_enumPinNum);
															break;
									
									case DIO_enumInputInternalPU:
																
															CLR_BIT(DDRB,Copy_enumPinNum);
															SET_BIT(PORTB,Copy_enumPinNum);
															break;
									
									case DIO_enumInputExternalPD:
															
															CLR_BIT(DDRB,Copy_enumPinNum);
															CLR_BIT(PORTB,Copy_enumPinNum);
															break;
									
									default:
															break;
								}
								break;			
			
			
	
		case DIO_enumPortC:
								switch (Copy_enumConfig)
								{
									case DIO_enumOutput: 
															SET_BIT(DDRC,Copy_enumPinNum);
															break;
									
									case DIO_enumInputInternalPU:
																
															CLR_BIT(DDRC,Copy_enumPinNum);
															SET_BIT(PORTC,Copy_enumPinNum);
															break;
									
									case DIO_enumInputExternalPD:
															
															CLR_BIT(DDRC,Copy_enumPinNum);
															CLR_BIT(PORTC,Copy_enumPinNum);
															break;
									
									default:
															break;
								}
								break;	
								
								
			case DIO_enumPortD:
								switch (Copy_enumConfig)
								{
									case DIO_enumOutput: 
															SET_BIT(DDRD,Copy_enumPinNum);
															break;
									
									case DIO_enumInputInternalPU:
																
															CLR_BIT(DDRD,Copy_enumPinNum);
															SET_BIT(PORTD,Copy_enumPinNum);
															break;
									
									case DIO_enumInputExternalPD:
															
															CLR_BIT(DDRD,Copy_enumPinNum);
															CLR_BIT(PORTD,Copy_enumPinNum);
															break;
									
									default:
															break;
								}
								break;			
			
			default:
								break;

	}
		
		
		
	}  
	
	return Ret_enuErrorStatus;
	
	
}


/*---------------------------------------------------------------------------------------------------------------------------*/

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
 
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enuErrorStatus = DIO_enumWrongPort;
	
	if (Copy_enumPortNum > DIO_enumPortD)
	{
		Ret_enuErrorStatus = DIO_enumWrongPort;
		
	}
	
	else if (Copy_enumConfig > DIO_enumInputExternalPD)
	{
		
		Ret_enuErrorStatus = DIO_enumWrongConfig;
		
	}
	
	else 
	{
		Ret_enuErrorStatus = DIO_enumOk;
		
		switch (Copy_enumPortNum)
		{
			case DIO_enumPortA:		
								switch (Copy_enumConfig)
								{
									case DIO_enumOutput: 
															SET_PORT(DDRA);
															break;
									
									case DIO_enumInputInternalPU:
																
															CLR_PORT(DDRA);
															SET_PORT(PORTA);
															break;
									
									case DIO_enumInputExternalPD:
															
															CLR_PORT(DDRA);
															CLR_PORT(PORTA);
															break;
									
									default:
															break;
								}
								break;
			
			
			
			case DIO_enumPortB:
								switch (Copy_enumConfig)
								{
									case DIO_enumOutput: 
															SET_PORT(DDRB);
															break;
									
									case DIO_enumInputInternalPU:
																
															CLR_PORT(DDRB);
															SET_PORT(PORTB);
															break;
									
									case DIO_enumInputExternalPD:
															
															CLR_PORT(DDRB);
															CLR_PORT(PORTB);
															break;
									
									default:
															break;
								}
								break;			
			
			
	
		case DIO_enumPortC:
								switch (Copy_enumConfig)
								{
									case DIO_enumOutput: 
															SET_PORT(DDRC);
															break;
									
									case DIO_enumInputInternalPU:
																
															CLR_PORT(DDRC);
															SET_PORT(PORTC);
															break;
									
									case DIO_enumInputExternalPD:
															
															CLR_PORT(DDRC);
															CLR_PORT(PORTC);
															break;
									
									default:
															break;
								}
								break;	
								
								
			case DIO_enumPortD:
								switch (Copy_enumConfig)
								{
									case DIO_enumOutput: 
									                       SET_PORT(DDRD);
															break;
									
									case DIO_enumInputInternalPU:
																
															CLR_PORT(DDRD);
															SET_PORT(PORTD);
															break;
									
									case DIO_enumInputExternalPD:
															
															CLR_PORT(DDRD);
															CLR_PORT(PORTD);
															
															break;
									
									default:
															break;
								}
								break;			
			
			            default:
								break;
	
		}
		
	}
	
	
	return Ret_enuErrorStatus;
	
}
/*------------------------------------------------------------------------------------------------------------*/
/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */
 
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t  Ret_enuErrorStatus = DIO_enumWrongPort;
	
	if ( Copy_enumPortNum > DIO_enumPortD )
	{
		Ret_enuErrorStatus = DIO_enumWrongPort;
		
	}
	
	else if ( Copy_enumPinNum > DIO_enumPin7 )
	{
		
		Ret_enuErrorStatus = DIO_enumWrongPin;
		
	}
	
	
	else 
	{
	   Ret_enuErrorStatus = DIO_enumOk;
		
		switch (Copy_enumPortNum)
		{
			case DIO_enumPortA:
			
								switch (Copy_enumLogicState)
								{
									case DIO_enumLogicHigh: 
															SET_BIT(PORTA,Copy_enumLogicState);
															break;
									
									case DIO_enumLogicLow:
																
															CLR_BIT(PORTA,Copy_enumLogicState);
															break;
									
									
								  default:
								                         break;
								}	
								break;
								
			case DIO_enumPortB:
			
			                switch (Copy_enumLogicState)
			                {
				              case DIO_enumLogicHigh:
				                                     SET_BIT(PORTB,Copy_enumLogicState);
				                                     break;
				
				               case DIO_enumLogicLow:
		                                             CLR_BIT(PORTB,Copy_enumLogicState);
				                                     break;
				                  default:
				                                      break;
			                 }
			                 break;
		case DIO_enumPortC:
							
						switch (Copy_enumLogicState)
						{
						 case DIO_enumLogicHigh:
								               SET_BIT(PORTC,Copy_enumLogicState);
								               break;
								
						case DIO_enumLogicLow:
								              CLR_BIT(PORTC,Copy_enumLogicState);
								              break;
								default:
								              break;
							}
							break; 
		case DIO_enumPortD:
		
		               switch (Copy_enumLogicState)
		                {
			             case DIO_enumLogicHigh:
			                                   SET_BIT(PORTD,Copy_enumLogicState);
			                                   break;
			
			            case DIO_enumLogicLow:
			                                  CLR_BIT(PORTD,Copy_enumLogicState);
			                                  break;
			                    default:
			                                  break;
		               
	                     }
	                                          break;
	
	                            default:
	                                         break;

                       }



                  }


return Ret_enuErrorStatus;

}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
  DIO_enumError_t Ret_enuErrorStatus = DIO_enumWrongPort;
  
              if ( Copy_enumPortNum > DIO_enumPortD )
                {
	                Ret_enuErrorStatus = DIO_enumWrongPort;
	  
                }
   		   
			  else
              
			  {
	               Ret_enuErrorStatus = DIO_enumOk;
	  
	                  switch (Copy_enumPortNum)
	                   {
		                 case DIO_enumPortA:
		  
		                              switch (Copy_enumLogicState)
											{
			                                   case DIO_enumLogicHigh:
											   
			                                   SET_BIT(PORTA,Copy_enumLogicState);
											   
			                                   break;
			  
			                                  case DIO_enumLogicLow:
			  
			                                   CLR_BIT(PORTA,Copy_enumLogicState);
			                                  
											   break;
			  
			  
			                          default:
			                                   break;
		                                     }
		                                       break;
		  
		                case DIO_enumPortB:
		  
		                                   switch (Copy_enumLogicState)
		                                    {
			                              case DIO_enumLogicHigh:
			                                                    
									           SET_BIT(PORTB,Copy_enumLogicState);
			                                   
											   break;
			  
			                               case DIO_enumLogicLow:
			                                   
											   CLR_BIT(PORTB,Copy_enumLogicState);
			                                   
											   break;
			                          default:
			                                   
											   break;
		                                    }
		                                       break;
		              case DIO_enumPortC:
		  
		                                switch (Copy_enumLogicState)
		                                  {
			                            case DIO_enumLogicHigh:
			  
			                                 SET_BIT(DIO_enumPortC,Copy_enumLogicState);
			                                  
											  break;
			  
			                          case DIO_enumLogicLow:
			                                 
											CLR_BIT(DIO_enumPortC,Copy_enumLogicState);
			                                 
											 break;
			                      
								    default:
			                                 break;
		                                   }
		                                     break;
		               case DIO_enumPortD:
		  
		                           switch (Copy_enumLogicState)
		                             {
			                            case DIO_enumLogicHigh:
			                              
										    SET_BIT(PORTD,Copy_enumLogicState);
			  
			                                break;
			  
			                           case DIO_enumLogicLow:
			  
			                               CLR_BIT(PORTD,Copy_enumLogicState);
			
			                                 break;
			                       default:
			                                break;
			  
		                              }
		                                     break;
		  
		                             default:
		                                     break;
	  }



  }


  return Ret_enuErrorStatus;
}


/*-----------------------------------------------------------------------------------------------------------------------------------*/

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t * Add_Pu8PinValue)
{
	 
	 DIO_enumError_t Ret_enuErrorStatus = DIO_enumWrongPort;

      if (Copy_enumPortNum > DIO_enumPortD)
        {
	       Ret_enuErrorStatus = DIO_enumWrongPort;
	
        }

       else if (Copy_enumPinNum > DIO_enumPin7)
         {
	
	        Ret_enuErrorStatus = DIO_enumWrongPin;
	
         }
          else if (* Add_Pu8PinValue = NULL)
           {
            	Ret_enuErrorStatus =DIO_enumNullPointer;
           }
else 
{
	switch(Copy_enumPortNum)
	{
		case DIO_enumPortA:
		        switch(Copy_enumPinNum)
				  {
			                        case DIO_enumPin0:
			                           
									   DIO_enumLogicState_t  *Add_Pu8PinVal = GET_BIT(DIO_enumPortA,DIO_enumPin0);
			
			                        break;
									
			                        case DIO_enumPin1:
			                         
									  *Add_Pu8PinVal = GET_BIT(DIO_enumPortA,DIO_enumPin1);
			
			                           break;
			                       
								     case DIO_enumPin2:
			
			                        *Add_Pu8PinVal = GET_BIT(DIO_enumPortA,DIO_enumPin2);
			
			                         break;
			                      
								    case DIO_enumPin3:
			                       
								   *Add_Pu8PinVal = GET_BIT(DIO_enumPortA,DIO_enumPin3);
			
			                         break;
			
			                        case DIO_enumPin4:
			                            
									*Add_Pu8PinVal = GET_BIT(DIO_enumPortA,DIO_enumPin4);
			
			                        break;
		
		                         	case DIO_enumPin5:
			                      
								  *Add_Pu8PinVal = GET_BIT(DIO_enumPortA,DIO_enumPin5);
			
		                        	break;
			
			                         case DIO_enumPin6:
			                      
								  *Add_Pu8PinVal = GET_BIT(DIO_enumPortA,DIO_enumPin6);
			
			                         break;
		                       
							   	case DIO_enumPin7:
		                         	*Add_Pu8PinVal = GET_BIT(DIO_enumPortA,DIO_enumPin7);
			
		                                 	break;
			                        default:
			                    break;
		                  }
		         break;
		              case DIO_enumPortB:
		                    switch(Copy_enumPinNum){
			                                case DIO_enumPin0:
			                                   *Add_Pu8PinVal = GET_BIT(DIO_enumPortB,DIO_enumPin0);
			
			                                          break;
			                                case DIO_enumPin1:
			                                   *Add_Pu8PinVal = GET_BIT(DIO_enumPortB,DIO_enumPin1);
			
			                                         break;
			                                case DIO_enumPin2:
			                                  *Add_Pu8PinVal = GET_BIT(DIO_enumPortB,DIO_enumPin2);
			
			                                       break;
			                                case DIO_enumPin3:
			                                   *Add_Pu8PinVal = GET_BIT(DIO_enumPortB,DIO_enumPin3);
			
			                                      break;
			                                 case DIO_enumPin4:
			                                   *Add_Pu8PinVal = GET_BIT(DIO_enumPortB,DIO_enumPin4);
			
			                                      break;
			                                case DIO_enumPin5:
			                                   *Add_Pu8PinVal = GET_BIT(DIO_enumPortB,DIO_enumPin5);
			
			                                       break;
			                                case DIO_enumPin6:
			                                    *Add_Pu8PinVal = GET_BIT(DIO_enumPortB,DIO_enumPin6);
			
			                                       break;
			                                case DIO_enumPin7:
			                                    *Add_Pu8PinVal = GET_BIT(DIO_enumPortB,DIO_enumPin7);
			
		                                        	break;
			                                   default:
			                               break;
		                                  }
		                                   break ;
		case DIO_enumPortC:
		switch(Copy_enumPinNum){
			case DIO_enumPin0:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortC,DIO_enumPin0);
			
			break;
			case DIO_enumPin1:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortC,DIO_enumPin1);
			
			break;
			case DIO_enumPin2:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortC,DIO_enumPin2);
			
			break;
			case DIO_enumPin3:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortC,DIO_enumPin3);
			
			break;
			case DIO_enumPin4:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortC,DIO_enumPin4);
			
			break;
			case DIO_enumPin5:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortC,DIO_enumPin5);
			
			break;
			case DIO_enumPin6:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortC,DIO_enumPin6);
			
			break;
			case DIO_enumPin7:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortC,DIO_enumPin7);
			
			break;
			default:
			break;
		}
		break;
		case DIO_enumPortD:
		switch(Copy_enumPinNum){
			case DIO_enumPin0:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortD,DIO_enumPin0);
			
			break;
			case DIO_enumPin1:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortD,DIO_enumPin1);
			
			break;
			case DIO_enumPin2:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortD,DIO_enumPin2);
			
			break;
			case DIO_enumPin3:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortD,DIO_enumPin3);
			
			break;
			case DIO_enumPin4:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortD,DIO_enumPin4);
			
			break;
			case DIO_enumPin5:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortD,DIO_enumPin5);
			
			break;
			case DIO_enumPin6:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortD,DIO_enumPin6);
			
			break;
			case DIO_enumPin7:
			*Add_Pu8PinVal = GET_BIT(DIO_enumPortD,DIO_enumPin7);
			
			break;
			default:
			break;
		}
		break;
		default :
		break;
	}
	
	Ret_enuErrorStatus = DIO_enumOk ;
}
}