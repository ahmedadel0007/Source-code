
typedef 	unsigned char			u8;
typedef 	unsigned short int		u16;
typedef 	unsigned int 			u32;
typedef 	signed char				s8;
typedef 	signed short int		s16;
typedef 	signed int 				s32;
typedef 	float					f32;
typedef 	double 					f64;

#define SET_BIT(REG,BIT)      (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)      (REG &= ~(1<<BIT))
#define GET_BIT(REG,BIT)      ((REG >> BIT) & 0x01)
#define TOG_BIT(REG,BIT)      (REG ^= (1<<BIT))

#define SET_PORT(REG)         (REG |= 0xFF)
#define CLR_PORT(REG)         (REG &= 0x00)
#define TOG_PORT(REG)         (REG ^= 0xFF)

#define DDRA             *((volatile u8*) 0x3A)
#define PORTA            *((volatile u8*) 0x3B)
#define PINA             *((volatile u8*) 0x39)

#define DDRB             *((volatile u8*) 0x37)
#define PORTB            *((volatile u8*) 0x38)
#define PINB             *((volatile u8*) 0x36)

#define DDRC             *((volatile u8*) 0x34)
#define PORTC            *((volatile u8*) 0x35)
#define PINC             *((volatile u8*) 0x33)

#define DDRD             *((volatile u8*) 0x31)
#define PORTD            *((volatile u8*) 0x32)
#define PIND             *((volatile u8*) 0x30)
 
 u8 Readbit(u8 reg, u8 Bp);
int main(void)
{
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	SET_BIT(DDRA,2);
	SET_BIT(DDRA,3);
	
	u8 Readbit(u8 Reg , u8 Bp)
	{
		return ((Reg&(1<<Bp))!=0);
	}
	
	u8 counter = 0;
	
	
    while(1)
    {
        while(!Readbit(PINA,5));  /*tool mana mash da5ed stuck mat3mlsh 7aga*/
        counter++;
		while(Readbit(PINA,5));   /*mat3mlsh 7aga la7ad mashel edey*/
	if(counter==1)
    {		
	SET_BIT(PORTA,0);
	CLR_BIT(PORTA,1);
	CLR_BIT(PORTA,2);
	CLR_BIT(PORTA,3);
	}
	else if(counter==2) 
	{
	SET_BIT(PORTA,1);
	CLR_BIT(PORTA,0);
	CLR_BIT(PORTA,2);
	CLR_BIT(PORTA,3);	
	}
	else if (counter==3) 
	{
		SET_BIT(PORTA,0);
		CLR_BIT(PORTA,2);
		SET_BIT(PORTA,1);
		CLR_BIT(PORTA,3);
	}
	else if(counter==4)
	{
		SET_BIT(PORTA,2);
		SET_BIT(PORTA,0);
	    CLR_BIT(PORTA,1);
		CLR_BIT(PORTA,3);
	}
	
}
}