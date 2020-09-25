/*
 * ads1015.c
 *
 *  Created on: Jun 18, 2020
 *      Author: Administrator
 */


#include "ADS1015.h"
//#include "myiic.h"

u16 ADS1015_CONFIG;//����ADS1015���ñ���

//ADS1015���ú���
//channel:ģ��ת��ͨ��
void ADS1015_Config(u8 i2cAddress,u8 channel)
{
  // Start with default values
  ADS1015_CONFIG  = ADS1015_REG_CONFIG_CQUE_NONE    | // Disable the comparator (default val)
					ADS1015_REG_CONFIG_CLAT_NONLAT  | // Non-latching (default val)
					ADS1015_REG_CONFIG_CPOL_ACTVLOW | // Alert/Rdy active low   (default val)
					ADS1015_REG_CONFIG_CMODE_TRAD   | // Traditional comparator (default val)
					ADS1015_REG_CONFIG_DR_3300SPS   | // 1600 samples per second (default)
					ADS1015_REG_CONFIG_MODE_SINGLE;   // Single-shot mode (default)

  // Set PGA/voltage range
  ADS1015_CONFIG |= ADS1015_REG_CONFIG_PGA_4_096V;
  switch (channel)
  {
	case (0):
	  ADS1015_CONFIG |= ADS1015_REG_CONFIG_MUX_SINGLE_0;
	  break;
	case (1):
	  ADS1015_CONFIG |= ADS1015_REG_CONFIG_MUX_SINGLE_1;
	  break;
	case (2):
	  ADS1015_CONFIG |= ADS1015_REG_CONFIG_MUX_SINGLE_2;
	  break;
	case (3):
	  ADS1015_CONFIG |= ADS1015_REG_CONFIG_MUX_SINGLE_3;
	  break;
  }
  // Set 'start single-conversion' bit
  ADS1015_CONFIG |= ADS1015_REG_CONFIG_OS_SINGLE;

  // Write config register to the ADC
  ADS1015_WriteOneByte(i2cAddress, ADS1015_REG_POINTER_CONFIG, ADS1015_CONFIG);
}

//ADS1015��ʼ������
void ADS1015_Init()
{
	IIC_Init();
	ADS1015_Config(ADS1015_ADDRESS,0);
}

//ADS1015�ӼĴ��������ֽ�����
u16 ADS1015_ReadOneByte(u8 i2cAddress,u16 ReadAddr)
{
	u16 temp=0;
	IIC_Start();
	IIC_Send_Byte(i2cAddress<<1);
	IIC_Wait_Ack();
	IIC_Send_Byte(ReadAddr);
	IIC_Wait_Ack();
	IIC_Stop();

	IIC_Start();
	IIC_Send_Byte((i2cAddress<<1)+1);
	IIC_Wait_Ack();
	temp=IIC_Read_Byte(1);
	temp=temp<<8;
	temp+=IIC_Read_Byte(1);
	IIC_Stop();
	return temp;
}

//ADS1015д���ֽ�����
void ADS1015_WriteOneByte(u8 i2cAddress,u16 WriteAddr,u16 DataToWrite)
{
	IIC_Start();
	IIC_Send_Byte(i2cAddress<<1);
	IIC_Wait_Ack();
	IIC_Send_Byte(WriteAddr);
	IIC_Wait_Ack();
	IIC_Send_Byte(DataToWrite>>8);
	IIC_Wait_Ack();
	IIC_Send_Byte(DataToWrite&0xff);
	IIC_Wait_Ack();
	IIC_Stop();
}

//ADS1015������
//����ֵ����ȡ��ADֵ
//Channel��ͨ��������Χ0-3
u16 ADS1015_Read(u8 channel)
{
	int temp;
	 // Start with default values
	  ADS1015_CONFIG  = ADS1015_REG_CONFIG_CQUE_NONE    | // Disable the comparator (default val)
						ADS1015_REG_CONFIG_CLAT_NONLAT  | // Non-latching (default val)
						ADS1015_REG_CONFIG_CPOL_ACTVLOW | // Alert/Rdy active low   (default val)
						ADS1015_REG_CONFIG_CMODE_TRAD   | // Traditional comparator (default val)
						ADS1015_REG_CONFIG_DR_3300SPS   | // 1600 samples per second (default)
						ADS1015_REG_CONFIG_MODE_SINGLE;   // Single-shot mode (default)

	  // Set PGA/voltage range
	 ADS1015_CONFIG |= ADS1015_REG_CONFIG_PGA_4_096V;
	if(channel<3)
	{
		switch (channel)
		{
			case (0):
				ADS1015_CONFIG |= ADS1015_REG_CONFIG_MUX_SINGLE_0;
			break;
			case (1):
				ADS1015_CONFIG |= ADS1015_REG_CONFIG_MUX_SINGLE_1;
			break;
			case (2):
				ADS1015_CONFIG |= ADS1015_REG_CONFIG_MUX_SINGLE_2;
			break;
			case (3):
				ADS1015_CONFIG |= ADS1015_REG_CONFIG_MUX_SINGLE_3;
			break;
		}
		  // Set 'start single-conversion' bit
		ADS1015_CONFIG |= ADS1015_REG_CONFIG_OS_SINGLE;
		ADS1015_WriteOneByte(ADS1015_ADDRESS,ADS1015_REG_POINTER_CONFIG, ADS1015_CONFIG);
		//delay_us(500);
		delay_ms(1);
		temp=ADS1015_ReadOneByte(ADS1015_ADDRESS,ADS1015_REG_POINTER_CONVERT);
		temp=temp>>4;
		return temp;
	}
	return 0;
}

//���AD1015�Ƿ����
//������
//i2cAddress��оƬ��ַ
//����ֵ��0���� 1������
u8 AD1015_Check(u8 i2cAddress)
{
	u8 x=22;
	IIC_Start();
	IIC_Send_Byte(i2cAddress<<1);
	x=IIC_Wait_Ack();
	return x;
}
