//program to toggle more than 1 led

#include<lpc21xx.h> 
void delay(unsigned int a);	
int main()
{
	IODIR0=(1<<11);   
	while(1)		  
	{	
	IOSET0=(1<<11);	 
	delay(500);		 		
	IOCLR0=(1<<11);	 
	delay(500);			 
	}
}
											  
void delay(unsigned int a)	
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++){}		

   }
