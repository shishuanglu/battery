/**
  ******************************************************************************
  * @file    LIB_Config.h
  * @author  Waveshare Team
  * @version 
  * @date    13-October-2014
  * @brief     This file provides configurations for low layer hardware libraries.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, WAVESHARE SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _USE_LIB_CONFIG_H_
#define _USE_LIB_CONFIG_H_
//Macro Definition

/* Includes ------------------------------------------------------------------*/
#include "MacroAndConst.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

//Config
#include "Config.h"
/*------------------------------------------------------------------------------------------------------*/

//delay
//#include "delay.h"

/*------------------------------------------------------------------------------------------------------*/
//SPI
//#include "SPI.h"

/*------------------------------------------------------------------------------------------------------*/
//SSD1331
#include "Fonts.h"
#include "main.h"
#include "ssd1331.h"



#define SSD1331_RES_GPIO        RES_GPIO_Port
#define SSD1331_RES_PIN         RES_Pin

#define SSD1331_DC_GPIO         DC_GPIO_Port
#define SSD1331_DC_PIN          DC_Pin

#define SSD1331_CS_GPIO         CS_GPIO_Port
#define SSD1331_CS_PIN          CS_Pin


#define __SSD1331_RES_SET()     HAL_GPIO_WritePin(SSD1331_RES_GPIO, SSD1331_RES_PIN, GPIO_PIN_SET)
#define __SSD1331_RES_CLR()     HAL_GPIO_WritePin(SSD1331_RES_GPIO, SSD1331_RES_PIN, GPIO_PIN_RESET)

#define __SSD1331_DC_SET()      HAL_GPIO_WritePin(SSD1331_DC_GPIO, SSD1331_DC_PIN, GPIO_PIN_SET)
#define __SSD1331_DC_CLR()      HAL_GPIO_WritePin(SSD1331_DC_GPIO, SSD1331_DC_PIN, GPIO_PIN_RESET)

#define __SSD1331_CS_SET()      HAL_GPIO_WritePin(SSD1331_CS_GPIO, SSD1331_CS_PIN, GPIO_PIN_SET)
#define __SSD1331_CS_CLR()      HAL_GPIO_WritePin(SSD1331_CS_GPIO, SSD1331_CS_PIN, GPIO_PIN_RESET)

#define SSD1331_SCLK_GPIO       SCLK_GPIO_Port
#define SSD1331_SCLK_PIN        SCLK_Pin

#define SSD1331_SDIN_GPIO       SDIN_GPIO_Port
#define SSD1331_SDIN_PIN        SDIN_Pin

#define __SSD1331_SCLK_SET()    HAL_GPIO_WritePin(SSD1331_SCLK_GPIO, SSD1331_SCLK_PIN, GPIO_PIN_SET)
#define __SSD1331_SCLK_CLR()    HAL_GPIO_WritePin(SSD1331_SCLK_GPIO, SSD1331_SCLK_PIN, GPIO_PIN_RESET)

#define __SSD1331_SDIN_SET()    HAL_GPIO_WritePin(SSD1331_SDIN_GPIO, SSD1331_SDIN_PIN, GPIO_PIN_SET)
#define __SSD1331_SDIN_CLR()    HAL_GPIO_WritePin(SSD1331_SDIN_GPIO, SSD1331_SDIN_PIN, GPIO_PIN_RESET)

#define __SSD1331_WRITE_BYTE(__DATA) HAL_SPI_Transmit(&hspi1, &__DATA, 1,10)

/*------------------------------------------------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */


#endif

/*-------------------------------END OF FILE-------------------------------*/

