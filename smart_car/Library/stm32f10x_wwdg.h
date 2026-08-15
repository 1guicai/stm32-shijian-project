  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_wwdg.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the WWDG firmware
  8→  *          library.
  9→  ******************************************************************************
 10→  * @attention
 11→  *
 12→  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 13→  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 14→  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 15→  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 16→  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 17→  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 18→  *
 19→  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 20→  ******************************************************************************
 21→  */
 22→
 23→/* Define to prevent recursive inclusion -------------------------------------*/
 24→#ifndef __STM32F10x_WWDG_H
 25→#define __STM32F10x_WWDG_H
 26→
 27→#ifdef __cplusplus
 28→ extern "C" {
 29→#endif
 30→
 31→/* Includes ------------------------------------------------------------------*/
 32→#include "stm32f10x.h"
 33→
 34→/** @addtogroup STM32F10x_StdPeriph_Driver
 35→  * @{
 36→  */
 37→
 38→/** @addtogroup WWDG
 39→  * @{
 40→  */ 
 41→
 42→/** @defgroup WWDG_Exported_Types
 43→  * @{
 44→  */ 
 45→  
 46→/**
 47→  * @}
 48→  */ 
 49→
 50→/** @defgroup WWDG_Exported_Constants
 51→  * @{
 52→  */ 
 53→  
 54→/** @defgroup WWDG_Prescaler 
 55→  * @{
 56→  */ 
 57→  
 58→#define WWDG_Prescaler_1    ((uint32_t)0x00000000)
 59→#define WWDG_Prescaler_2    ((uint32_t)0x00000080)
 60→#define WWDG_Prescaler_4    ((uint32_t)0x00000100)
 61→#define WWDG_Prescaler_8    ((uint32_t)0x00000180)
 62→#define IS_WWDG_PRESCALER(PRESCALER) (((PRESCALER) == WWDG_Prescaler_1) || \
 63→                                      ((PRESCALER) == WWDG_Prescaler_2) || \
 64→                                      ((PRESCALER) == WWDG_Prescaler_4) || \
 65→                                      ((PRESCALER) == WWDG_Prescaler_8))
 66→#define IS_WWDG_WINDOW_VALUE(VALUE) ((VALUE) <= 0x7F)
 67→#define IS_WWDG_COUNTER(COUNTER) (((COUNTER) >= 0x40) && ((COUNTER) <= 0x7F))
 68→
 69→/**
 70→  * @}
 71→  */ 
 72→
 73→/**
 74→  * @}
 75→  */ 
 76→
 77→/** @defgroup WWDG_Exported_Macros
 78→  * @{
 79→  */ 
 80→/**
 81→  * @}
 82→  */ 
 83→
 84→/** @defgroup WWDG_Exported_Functions
 85→  * @{
 86→  */ 
 87→  
 88→void WWDG_DeInit(void);
 89→void WWDG_SetPrescaler(uint32_t WWDG_Prescaler);
 90→void WWDG_SetWindowValue(uint8_t WindowValue);
 91→void WWDG_EnableIT(void);
 92→void WWDG_SetCounter(uint8_t Counter);
 93→void WWDG_Enable(uint8_t Counter);
 94→FlagStatus WWDG_GetFlagStatus(void);
 95→void WWDG_ClearFlag(void);
 96→
 97→#ifdef __cplusplus
 98→}
 99→#endif
100→
101→#endif /* __STM32F10x_WWDG_H */
102→
103→/**
104→  * @}
105→  */ 
106→
107→/**
108→  * @}
109→  */ 
110→
111→/**
112→  * @}
113→  */ 
114→
115→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/