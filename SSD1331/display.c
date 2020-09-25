/*
 * display.c
 *
 *  Created on: 2020��6��19��
 *      Author: Administrator
 */
#include "display.h"
#include "ssd1331.h"
#include "Fonts.h"

typedef enum
{
	PAGE_INIT = 0,			//��ʼ������
	PAGE_VOLT_DISPLAY,		//��ѹ��ʾ����
	PAGE_VOLT_WARNING_DISPLAY,	//�͵�ѹ�������


}PAGE_STATE_E;

PAGE_STATE_E nextPage = PAGE_INIT;
static PAGE_STATE_E curPage = PAGE_INIT;


void set_next_page(PAGE_STATE_E state)
{
	nextPage = state;
}

PAGE_STATE_E get_cur_page(void)
{
	return curPage;
}

/**
  * @brief  ��ʼ��������ʾ
  * @param  None
  * @retval  None
  */
void page_init_display(void)
{
	ssd1331_draw_1616GB2312(0,0,c_ch1616GB2312_1,5,GREEN);		//"���ɺ���"
	ssd1331_draw_1616GB2312(0,16,c_ch1616GB2312_2,5,YELLOW);	//"���ܵ��"
	ssd1331_draw_1616GB2312(0,32,c_ch1616GB2312_3,5,BLUE);		//"��������"
	ssd1331_draw_1616GB2312(0,48,c_ch1616GB2312_4,5,RED);		//"���Ժ�..."
}

/**
  * @brief  ��ѹ������ʾ
  * @param  None
  * @retval  None
  */
void page_volt_display(void)
{
	ssd1331_draw_1616GB2312(16,0,c_ch1616GB2312_5,4,GREEN);		//"��ǰ״̬"
	ssd1331_draw_1616GB2312(0,16,c_ch1616GB2312_6,3,YELLOW);	//"��ѹ��"
	ssd1331_draw_1616GB2312(0,32,c_ch1616GB2312_7,3,BLUE);		//"������"
	ssd1331_draw_1616GB2312(0,48,c_ch1616GB2312_8,3,RED);		//"������"

	ssd1331_display_string(48,16,"12.34V",16,YELLOW);
	ssd1331_display_string(48,32,"12.34A",16,BLUE);
	ssd1331_display_string(48,48,"12.34%",16,RED);
}

/**
  * @brief  ��ѹ���������ʾ
  * @param  None
  * @retval  None
  */
void page_volt_warning_display(void)
{


}


/**
  * @brief  ��ʾҳ�����
  * @param  None
  * @retval  None
  */
void page_switch_update(void)
{

	if (nextPage == curPage) {
		return;
	}
	curPage = nextPage;

	 ssd1331_clear_screen();

	switch (curPage) {

		case PAGE_INIT:
			page_init_display();

			break;

		case PAGE_VOLT_DISPLAY:
			page_volt_display();

			break;

		case PAGE_VOLT_WARNING_DISPLAY:
			page_volt_warning_display();

			break;
	}

}

/**
  * @brief  ��ʾҳ���ʼ��
  * @param  None
  * @retval  None
  */
void page_init(void)
{
	/*1331��ʼ��������*/
	ssd1331_init();

	page_init_display();
}
