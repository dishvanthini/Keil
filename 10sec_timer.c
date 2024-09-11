#include<lpc21xx.h>
#include "lcd_fun.c"
#include"uart.h"
void timer(void);
void adc(void);

int main()
{
unsigned int val;

lcd_conf();
uart_config();
timer();
adc();


//config p0.28as AIN1

while(1)
{

	if(T0IR&(1<<0))
	{
	 while(!(ADDR&(1<<31)));
			val=ADDR&(0x3FF<<6);
			val=val>>6;
			val=val/3.3;
			lcd_num(val);
			uart_num(val);
			//uart_Str(".\r\n");
			delay(1000);
			
			lcd_cmd(0x01);
			delay(1000);
			T0IR=(1<<0); 	
	}



}
}

void adc(void)
{
PINSEL1|=(1<<24); //bitnum
PINSEL1&=~(1<<25);
ADCR=(1<<1)|(4<<8)|(1<<16)|(1<<21);
}

void timer(void)
{
T0PR=14; //prescale regr
T0MR0=10000000;	 //match reg

T0MCR=(1<<1)|(1<<0);//Mr0,1,2 interupt mode , mr3 interrupt and repeat mc
T0TCR=(1<<1);
T0TCR=(1<<0);
}

