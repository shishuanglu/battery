//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ʹ��SysTick����ͨ����ģʽ���ӳٽ��й���
//����delay_us,delay_ms
//�������Ƶ���
//���̵�ַ��http://shop73023976.taobao.com/shop/view_shop.htm?tracelog=twddp&trace_log=qianniu_pc
//�޸�����:2014/3/16
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������Ƶ���2014/3/16
//All rights reserved
//********************************************************************************


#ifndef __OLED_H
#define __OLED_H			  	 
//#include "sys.h"
#include "stdlib.h"
#include "main.h"

//OLEDģʽ����
//0:4�ߴ���ģʽ

#define OLED_MODE 0
		    						  
//-----------------OLED�˿ڶ���----------------  					   

#define OLED_RS_Set()  HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET)
#define OLED_RS_Clr()  HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET)

#define OLED_CS_Set()  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET)
#define OLED_CS_Clr()  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET)

#define OLED_SCLK_Set()  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET)
#define OLED_SCLK_Clr()  HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET)

#define OLED_SDIN_Set()  HAL_GPIO_WritePin(SDIN_GPIO_Port, SDIN_Pin, GPIO_PIN_SET)
#define OLED_SDIN_Clr()  HAL_GPIO_WritePin(SDIN_GPIO_Port, SDIN_Pin, GPIO_PIN_RESET)



#define OLED_RES_Set()  HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, GPIO_PIN_SET)
#define OLED_RES_Clr()  HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, GPIO_PIN_RESET)



//PC0~7,��Ϊ������
#define DATAOUT(x) GPIO_Write(GPIOC,x);//���  
//ʹ��4�ߴ��нӿ�ʱʹ�� 



 		     
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����
//OLED�����ú���






#endif  
	 



