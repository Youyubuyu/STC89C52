#include <REGX52.H>
#include "Timer1.h"

sbit Motor = P1^0;

unsigned char Counter, Compare;

void Motor_Init()
{
	Timer1_Init();
}

void Motor_SetSpeed(unsigned char Speed)
{
	Compare = Speed;
}

void Timer1_Routine() interrupt 3
{
	TL1 = 0x9C;				//���ö�ʱ��ֵ
	TH1 = 0xFF;				//���ö�ʱ��ֵ
	Counter++;
	Counter %= 100;
	if(Counter < Compare)
	{
		Motor = 1;
	}
	else
	{
		Motor = 0;
	}
}