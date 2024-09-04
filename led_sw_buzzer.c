//program to toggle more than 1 led
#include<lpc21xx.h> 
void delay(unsigned int a);	
int main()
{
	IODIR0=(1<<11);// P0.11   buzzer
	IODIR1=(1<<17); 
	IODIR1=~(1<<25); //P1.25   switch    
	while(1)		  
	{  //& - operator to check . 
		if(IOPIN1 & (1<<25))	  //access the bit ,when 1 (switch pressed ),buzzred ...
		{	
			IOSET0=(1<<11);	 
			delay(500);	 		
			IOCLR0=(1<<11);	
			delay(500); 
		}
		else
		{
			IOSET1=(1<<17);	 
			delay(500);	 		
			IOCLR1=(1<<17);	
			delay(500); 
		}	 	 
	}
}											  
void delay(unsigned int a)	
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++){}		

   }
