#include<lpc214x.h>

#define bit(x) (1<<x)
#define delay for(i=0;i<2000;i++);

#define IR (IO1PIN & (1<<24))		// p1.24 is connected to OUT of IR sensor

unsigned int i;

void lcd_int();
void dat(unsigned char);
void cmd(unsigned char);
void string(unsigned char *);

void main()
{
IO0DIR =0XFFF;					// setting the direction as output
IO1DIR = 0x0;						// setting the direction as input for the port1 as it is configured as input for the IR sensor
lcd_int();
cmd(0x80);
	
while(1) {
if(IR == 0) {						// for logic input 0, the obstacle is detected
string("Obstacle Detcted");
}
else
{
string("Nothing is Detected");	// for logic input 1, obstacle is not created 
}
//delay();
//delay();
cmd(0x01);
}
}

void lcd_int()
{
cmd(0x38);
cmd(0x0c);
cmd(0x06);
cmd(0x01);
cmd(0x80);
}

void cmd(unsigned char a)
{
IO0PIN&=0x00;
IO0PIN|=(a<<0);
IO0CLR|=bit(8); //rs=0
IO0CLR|=bit(9); //rw=0
IO0SET|=bit(10); //en=1
delay;
IO0CLR|=bit(10); //en=0
}

void dat(unsigned char b)
{
IO0PIN&=0x00;
IO0PIN|=(b<<0);
IO0SET|=bit(8); //rs=1
IO0CLR|=bit(9); //rw=0
IO0SET|=bit(10); //en=1
delay;
IO0CLR|=bit(10); //en=0
}

void string(unsigned char *p)
{
while(*p!='\0') {
dat(*p++);
}
}