#include <REGX52.H>
#include "Delay.h"

/*
	矩阵键盘读取按键键码
	KeyNumber 按下按键的键码值
	如果按键按下不放，程序会停留在此函数，松手的一瞬间，返回按键键码，没有按键按下时，返回0
*/

unsigned char Key_KeyNumber;
unsigned char Key()
{
	unsigned char a;
	a=Key_KeyNumber;
	Key_KeyNumber=0;
	return a;
}

unsigned char MatrixKey()
{
	unsigned char KeyNumber=0;
	
	P1=0xFF;
	P1_2=0;
	if(P1_5==0){KeyNumber=10;}//方向：左
	
	P1=0xFF;
	P1_1=0;
	if(P1_6==0){KeyNumber=7;}//方向：上
	if(P1_4==0){KeyNumber=15;}//方向：下
	
	P1=0xFF;
	P1_0=0;
	if(P1_5==0){KeyNumber=12;}//方向：右
	
	return KeyNumber;
}

void Circulate_MatrixKey()
{
		static unsigned char Now_Key=0;		
		Now_Key=MatrixKey();
		if(Now_Key==7){Key_KeyNumber=2;}//下
		if(Now_Key==15){Key_KeyNumber=1;}//上
		if(Now_Key==10){Key_KeyNumber=4;}//右
		if(Now_Key==12){Key_KeyNumber=3;}//左
}