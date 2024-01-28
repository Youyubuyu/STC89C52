#include <REGX52.H>

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;

/**
  * @brief  I2C��ʼ
  * @param  ��
  * @retval ��
  */
void I2C_Start(void)
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}

/**
  * @brief  I2Cֹͣ
  * @param  ��
  * @retval ��
  */
void I2C_Stop(void)
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

/**
  * @brief  I2C����һ���ֽ�
  * @param  Byte Ҫ���͵��ֽ�
  * @retval ��
  */
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		I2C_SDA = Byte & (0x80 >> i);
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}

/**
  * @brief  I2C����һ���ֽ�
  * @param  ��
  * @retval ���յ���һ���ֽ�����
  */
unsigned char I2C_ReceiveByte(void)
{
	unsigned char i, Byte = 0x00;
	I2C_SDA = 1;
	for(i = 0; i < 8; i++)
	{
		I2C_SCL = 1;
		if(I2C_SDA){Byte |= (0x80 >> i);}
		I2C_SCL = 0;				
	}
	return Byte;
}

/**
  * @brief  I2C����Ӧ��
  * @param  AckBit Ӧ��λ��0ΪӦ��1Ϊ��Ӧ��
  * @retval ��
  */
void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA = AckBit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

/**
  * @brief  I2C����Ӧ��λ
  * @param  ��
  * @retval ���յ���Ӧ��λ��0ΪӦ��1Ϊ��Ӧ��
  */
unsigned char I2C_ReceiveAck(void)
{
	unsigned char AckBit;
	I2C_SDA = 1;
	I2C_SCL = 1;
	AckBit = I2C_SDA;
	I2C_SCL = 0;
	return AckBit;
}