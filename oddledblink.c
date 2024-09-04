//program to toggle more than 1 led

#include<lpc21xx.h> 
void delay(unsigned int a);	
int main()
{
	IODIR1=(0xFF<<17);   
	while(1)		  
	{	int i;
		for(i=17;i<=24;i++){

		if(i%2!=0){
		IOSET1=(1<<i);	 
		delay(500);		 	
		}	
			
		}
	IOCLR1=(0xFF<<17);	 
	delay(500);
				 
	}
}
											  
void delay(unsigned int a)	
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++){}		

   }
