#include<lpc21xx.h>
#include"lcd_fun.c"
#include"uart.h"
void timer_conf(void);
void int_conf(void);
void timer_isr(void)__irq;

int main()
{
	IODIR1|=(0xFF<<17);
	timer_conf();
	int_conf();
	lcd_conf();
	uart_config();

while(1){
	IOSET1=(1<<17);
	delay(500);
	IOCLR1=(1<<17);
	delay(500);
	}

}


void timer_conf(void){
	T0PR=14;// to stop at 15 , 14+1 -- 
	T0MR0=10000000;
	T0MCR=(1<<1)|(1<<0);  //
	T0TCR=(1<<1);			// to clear the 
	T0TCR=(1<<0);		   //enable timer 0 
}
void int_conf(void)
{
	VICIntSelect&=~(1<<4); // timer 0 and irq
	VICIntEnable=(1<<4);   //enable timer0 

	VICVectCntl0=(1<<5)|(4<<0);	  //bit 5 as GIE ,

	VICVectAddr0=(long)timer_isr;//load timer ISR addr
}
void timer_isr(void)__irq
{
   	IOSET1=(1<<24);
	delay(2000);
	IOCLR1=(1<<24);
	delay(2000);
	lcd_str("INTERRUPT FROM TIM");
	uart_str("INTERRUPT FROM TIM");
	delay(500);
	lcd_cmd(0x01);
	delay(500);
	lcd_cmd(0x01);
	delay(1000);

	T0IR=(1<<0);//MR0 so ,
	VICVectAddr=0;// defaut return to 0 , go to main
}
