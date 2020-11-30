#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
#include"string.h"
#include<stdlib.h>

void delay(uint16_t count)
{
	uint16_t i;
	for(i=0;i<count;i++)
	_delay_ms(1);
}
void main()
{
	uint16_t adc_val,adc_val1;
	uint8_t FSR1;
	InitLCD(0);
	USARTInit(51);
	InitADC();
	LCDClear();
	LCDWriteString("Temperature");
	LCDWriteStringXY(0,1,"Monitoring Node");
	char arr[10];
	delay(20);

	LCDClear();
	LCDWriteString("Temperature");
	while(1)
	{
		adc_val=ReadADC(0);
        FSR1=adc_val/2;
		delay(100);
      	write("FSR1:");
		itoa(FSR1,arr,10);
		write(arr);
		USARTWriteChar('\n');
		//USARTWriteChar('D');
		//char string[40];
		//memset(string,0,sizeof(string[0])*40);
		//sprintf(string,"FSR1: %d",FSR1);
		

	   
		//write(FSR1);
		//FSR1=adc_val/2;
		LCDWriteIntXY(0,1,FSR1,3);
	    
		//write("\r\n");
	   //USARTWriteInt
	    
	//	USARTWriteChar("\r\n");
		delay(100);
	//	strchar();
	}
}
