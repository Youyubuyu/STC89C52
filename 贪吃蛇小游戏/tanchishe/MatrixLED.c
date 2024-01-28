#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;  //RCLK
sbit SCK=P3^6;  //SRCLK
sbit SER=P3^4;  //SER

#define MATRIX_LED_PORT P0

/*
* 74HC595写入一个字节
* 参数：要写入的字节
*/


void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
	SER=Byte&(0x80>>i);
	SCK=1;
	SCK=0;
	}
	RCK=1;
	RCK=0;
}

/*
*点阵屏初始化
*/

void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}

/*
* LED点阵屏显示一列数据
* 参数：Column 要选择的列，范围：0~7，0在最左边
*      Data 选择列显示的数据，高位在上，1为亮，0为灭
*/

void MatrixLED_ShowColumn(unsigned char Column, Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}