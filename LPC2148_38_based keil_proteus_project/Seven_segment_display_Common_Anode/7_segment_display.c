#include<lpc21xx.h>



void delay(unsigned int c)
{unsigned int a;
for(a=1;a<=50000;a++);}



int main()
{
PINSEL0=0x00000000; //GPIO
PINSEL1=0x00000000;
PINSEL2=0x00000000;

IO0DIR|=0xffffffff; //making all the bits as output
IO1DIR = ~(1<<16); //switch is acting as input hence send 0 to p1.16 without altering other bits

while(1)
{
unsigned long int j;
int i,a[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; //anode type
int b[] ={0x90,0x80, 0xF8, 0x82,0x92,0x99,0xB0,0xA4,0xF9,0xC0};



if(IO1PIN & (1<<16)) // if switch is ON
{
for(j=0;j<10;j++)
{ IO0SET=IO0SET|a[j]; // send 0 to 9 - up counter



delay(10000);
IO0CLR=a[j];
delay(10000);
}
}
else // if switch is OFF
{



for(j=0;j<10;j++)
{
IO0SET=IO0SET|b[j]; // send 9 to 0 - down counter





delay(10000);
IO0CLR=b[j];
delay(10000);



}



}
}
}



/*#include<LPC21XX.H> // header file for lpc2148

void delay(); // delay function
//unsigned int i,j,k; // globle variable
unsigned int ar[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90 }; // array data

int main()
{
	//int i;
	PINSEL0=0X00000000; // select port0 as gpio mode
	IO0DIR =0X000000FF; // make starting 8 pin as output and other as input of port0

	
while(1)
	{
	if((IOPIN0&0x00000800)==0x00000800)
		{
			for(int i=0;i<10;i++)
			{
				IO0SET = ar[i];
				delay();
				IO0CLR = ar[i];
			}
		}
	else
	{
		for(int i=9;i>=0;i--)
		{
			IO0SET =ar[i];
			delay();
			IO0CLR =ar[i];
		}
	}
	return 0;
	}
}

void delay()
{
	for(int j=0;j<50000;j++);
}*/