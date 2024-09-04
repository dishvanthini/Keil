#include<lpc21xx.h>

#define RS(1<<10)
#define RW(1<<12)
#define EN(1<<13)
#define DATA(0xFF<<15)

void lcd_conf(void);
void lcd_cmd(unsigned char c);
void lcd_data(unsigned char d);
void delay(unsigned int a);
void lcd_str(unsigned char *ptr)
void lcd_num(unsigned int num )

int main(){
  lcd_config();
  lcd_data('A');
}

void lcd_conf(void)
	{
	IODIR0 |=RS|RW|EN|DATA;
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	lcd_cmd(0x80);	
	}

void lcd_cmd(unsigned char c){
	IOCLR0=(0xFF<<15);
	IOSET0=(c<<15);
	IOCLR0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay(10);
	IOCLR0=EN;
}

void lcd_data(unsigned char d)
	{
	IOCLR0=(0xFF<<15);
	IOSET0=(d<<15);
	IOSET0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay(10);
	IOCLR0=EN;
	}

void lcd_str(unsigned char *ptr)
	{
	while(*ptr !='\0')
	{
		lcd_data(*ptr);
		ptr++;
	}
	}
void delay(unsigned int a)	
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++){}		

   }
void lcd_num(unsigned int num)
	{
	if(num)
	{
		lcd_num(num/10);
		lcd_data(num%10+0x30);
	}
	}
