#include <REGX52.H>

/*
 * ��ʱ����ʼ����1����@12.000MHz
 */

void Timer0_Init()		//1����@12.000MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x18;				//���ö�ʱ��ֵ
	TH0 = 0xFC;				//���ö�ʱ��ֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0=1;
	EA=1;
	PT0=0;
}

/*

��ʱ���жϺ���ģ��

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;				//���ö�ʱ��ֵ
	TH0 = 0xFC;				//���ö�ʱ��ֵ
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		
	}
}

*/

