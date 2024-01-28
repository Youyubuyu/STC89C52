#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer = P2^5;

#define SPEED 500

#define P0  0
#define L1  1
#define L1_ 2
#define L2  3
#define L2_ 4
#define L3  5
#define L4  6
#define L4_ 7
#define L5  8
#define L5_ 9
#define L6  10
#define L6_ 11
#define L7  12
#define M1  13
#define M1_ 14
#define M2  15
#define M2_ 16
#define M3  17
#define M4  18
#define M4_ 19
#define M5  20
#define M5_ 21
#define M6  22
#define M6_ 23
#define M7  24
#define H1  25
#define H1_ 26
#define H2  27
#define H2_ 28
#define H3  29
#define H4  30
#define H4_ 31
#define H5  32
#define H5_ 33
#define H6  34
#define H6_ 35
#define H7  36
#define SH1  37
#define SH1_ 38
#define SH2  39
#define SH2_ 40
#define SH3  41
#define SH4  42
#define SH4_ 43
#define SH5  44
#define SH5_ 45
#define SH6  46
#define SH6_ 47
#define SH7  48

unsigned int FreqTable[] = {
0,
63628, 63731, 63835, 63928, 64021, 64103, 64185, 64260,
64331, 64400, 64463, 64524, 64580, 64633, 64684, 64732,
64777, 64820, 64860, 64898, 64934, 64968, 65000, 65030,
65058, 65085, 65110, 65134, 65157, 65178, 65198, 65217,
65235, 65252, 65268, 65283, 65297, 65310, 65323, 65335,
65346, 65357, 65367, 65377, 65385, 65394, 65402, 65409
};

unsigned char code Music[] = {
	//我们哭了
	P0,2,
	L5,2,
	M1,2,
	M2,2,
	M1,8,
	//我们笑着
	P0,2,
	M1,2,
	M1,2,
	M2,1,
	M1,1,
	M1,8,
	//我们抬头望天空
	P0,2,
	M1,2,
	M1,2,
	M2,2,
	M3,2,
	M6,2,
	M7,2,
	H1,2,
	//星星还亮着几颗
	P0,2,
	M6,2,
	M6,2,
	M5,2,
	M5,2,
	M3,2,
	M1,2,
	M2,2,
	//我们唱着
	P0,2,
	L5,2,
	M1,2,
	M2,1,
	M1,1,
	M1,8,
	//时间的歌
	P0,2,
	M1,2,
	M1,3,
	M2,1,
	M3,8,
	//才懂得相互拥抱
	P0,2,
	L5,2,
	M1,2,
	M2,2,
	M3,2,
	M6,2,
	M7,2,
	H1,2,
	//到底是为了什么
	P0,2,
	M6,2,
	M6,2,
	M5,2,
	M5,2,
	M6,2,
	M3,2,
	M2,2,
	//因为我刚好遇见你
	P0,2,
	H1,2,
	H1,2,
	H1,2,
	H1,2,
	M6,2,
	SH1,2,
	H6,2,
	H6,4,
	//留下足迹才美丽
	H6,2,
	H5,2,
	H5,2,
	H3,2,
	H3,2,
	H1,2,
	H2,4,
	//风吹花落泪如雨
	H1,2,
	H1,2,
	H1,2,
	M6,2,
	SH1,2,
	SH2,2,
	SH1,4,
	//因为不想分离
	SH1,2,
	H6,2,
	P0,2,
	H5,2,
	H3,2,
	H5,2,
	H2,4,
	//因为刚好遇见你
	H1,2,
	M7,2,
	H1,2,
	M6,2,
	SH1,2,
	H6,2,
	H6,4,
	//留下十年的期许
	H6,2,
	H5,2,
	H5,2,
	H5,1,
	H6,1,
	H3,2,
	H5,2,
	H2,4,
	//如果再相遇
	H1,2,
	H2,2,
	H1,2,
	M7,1,
	H1,9,
	//我想我会记得你
	H1,2,
	H2,2,
	H3,2,
	H2,1,
	H1,3,
	M7,1,
	H1,9,
};

unsigned char FreqSelect, MusicSelect;

void main()
{
	Timer0_Init();
	while(1)
	{
		FreqSelect = Music[MusicSelect];
		MusicSelect++;
		Delay(SPEED / 4 * Music[MusicSelect]);
		MusicSelect++;
		TR0 = 0;
		Delay(5);
		TR0 = 1;
		if(MusicSelect > 221)
		{
			MusicSelect = 0;
		}
	}
}

void Timer0_Routine() interrupt 1
{
	if(FreqTable[FreqSelect])
	{
	TL0 = FreqTable[FreqSelect] % 256;				//设置定时初值
	TH0 = FreqTable[FreqSelect] / 256;				//设置定时初值
	Buzzer =! Buzzer;
	}
}