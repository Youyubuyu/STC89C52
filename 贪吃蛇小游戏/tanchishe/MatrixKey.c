#include <REGX52.H>
#include "Delay.h"

/*
	������̶�ȡ��������
	KeyNumber ���°����ļ���ֵ
	����������²��ţ������ͣ���ڴ˺��������ֵ�һ˲�䣬���ذ������룬û�а�������ʱ������0
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
	if(P1_5==0){KeyNumber=10;}//������
	
	P1=0xFF;
	P1_1=0;
	if(P1_6==0){KeyNumber=7;}//������
	if(P1_4==0){KeyNumber=15;}//������
	
	P1=0xFF;
	P1_0=0;
	if(P1_5==0){KeyNumber=12;}//������
	
	return KeyNumber;
}

void Circulate_MatrixKey()
{
		static unsigned char Now_Key=0;		
		Now_Key=MatrixKey();
		if(Now_Key==7){Key_KeyNumber=2;}//��
		if(Now_Key==15){Key_KeyNumber=1;}//��
		if(Now_Key==10){Key_KeyNumber=4;}//��
		if(Now_Key==12){Key_KeyNumber=3;}//��
}