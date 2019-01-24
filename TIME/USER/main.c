#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
//ALIENTEK miniSTM32开发板实验1
//跑马灯实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

char time[] = "\"19/01/08,08:24:08+08\"";
char *a;
char *p1;
uint8_t i;

struct	time{
		uint8_t	year;
		uint8_t	month;
		uint8_t date;
		uint8_t hour;
		uint8_t min;
		uint8_t	sec;
};

struct time penli;


int main(void)
{		
		uart_init(115200);
		a = time; 
		printf("%s\r\n",a);
		
		for(i=0;i<5;i++)
		{
				a[3*i] = '\0';
		}
		a += 1;
		penli.year = atoi(a);
		penli.month = atoi(a+3);
		penli.date = atoi(a+6);
		penli.hour = atoi(a+9);
		penli.min  = atoi(a+12);
		penli.sec  = atoi(a+15);
		printf("20%d,%d,%d,%d,%d,%d\r\n",penli.year,penli.month,penli.date,penli.hour+8,penli.min,penli.sec);
		while(1);

 }

