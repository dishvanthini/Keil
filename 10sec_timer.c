#include<lpc21xx.h>

void toggle_led(unsigned int a);
void delay(unsigned int a);

int main()
{
IODIR1|=(0xFF<<17);

T0PR=14;
T1PR=14;

T0MR0=2000000;
T0MR1=3000000;
T0MR2=4000000;
T0MR3=5000000;

T1MR0=6000000;
T1MR1=7000000;
T1MR2=8000000;
T1MR3=9000000;

T0MCR=(1<<10)|(1<<9)|(1<<6)|(1<<3)|(1<<0); //Mr0,1,2 interupt mode , mr3 interrupt and repeat mc
T0TCR=(1<<1);
T0TCR=(1<<0);
  // MR0 and toggle 17
T1MCR=(1<<10)|(1<<9)|(1<<6)|(1<<3)|(1<<0); //Mr0,1,2 interupt mode , mr3 interrupt and repeat mc
T1TCR=(1<<1);
T1TCR=(1<<0);


while(1)
{

	if(T0IR&(1<<0))
	{
	toggle_led(17);
	T0IR=(1<<0); //reset the interrupt 
	}
	
	if(T0IR&(1<<1))
	{
	toggle_led(18);
	T0IR=(1<<1);
	}
	
	if(T0IR&(1<<2))
	{
	toggle_led(19);
	T0IR=(1<<2);
	}
	
	if(T0IR&(1<<3))
	{
	toggle_led(20);
	T0IR=(1<<3);
	}

	if(T1IR&(1<<0))
	{
	toggle_led(21);
	T1IR=(1<<0); //reset the interrupt 
	}
	
	if(T1IR&(1<<1))
	{
	toggle_led(22);
	T1IR=(1<<1);
	}
	
	if(T1IR&(1<<2))
	{
	toggle_led(23);
	T1IR=(1<<2);
	}
	
	if(T1IR&(1<<3))
	{
	toggle_led(24);
	T1IR=(1<<3);
	}

}

}

void toggle_led(unsigned int a)
{
IOSET1=(1<<a);
delay(500);
IOCLR1=(1<<a);
delay(500);
}

void delay(unsigned int a)
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++)
	{
	}
}

