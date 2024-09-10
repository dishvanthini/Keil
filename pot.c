#include<lpc21xx.h>
#include "lcd_fun.c"
#include "uart.h"
int main()
{
unsigned int val;

lcd_conf();
uart_config();

//config p0.27as AIN1
PINSEL1|=(1<<22); //bitnum
PINSEL1&=~(1<<23);

ADCR=(1<<0)|(4<<8)|(1<<16)|(1<<21);
while(1)
{
while(!(ADDR&(1<<31)));
val=ADDR&(0x3FF<<6);
val=val>>6;
//val=val/3.3;;
lcd_num(val);
uart_num(val);
delay(1000);
lcd_cmd(0x01);
delay(1000);
}
}
