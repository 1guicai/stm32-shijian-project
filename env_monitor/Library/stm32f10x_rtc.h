  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_rtc.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the RTC firmware 
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
 24→#ifndef __STM32F10x_RTC_H
 25→#define __STM32F10x_RTC_H
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
 38→/** @addtogroup RTC
 39→  * @{
 40→  */ 
 41→
 42→/** @defgroup RTC_Exported_Types
 43→  * @{
 44→  */ 
 45→
 46→/**
 47→  * @}
 48→  */ 
 49→
 50→/** @defgroup RTC_Exported_Constants
 51→  * @{
 52→  */
 53→
 54→/** @defgroup RTC_interrupts_define 
 55→  * @{
 56→  */
 57→
 58→#define RTC_IT_OW            ((uint16_t)0x0004)  /*!< Overflow interrupt */
 59→#define RTC_IT_ALR           ((uint16_t)0x0002)  /*!< Alarm interrupt */
 60→#define RTC_IT_SEC           ((uint16_t)0x0001)  /*!< Second interrupt */
 61→#define IS_RTC_IT(IT) ((((IT) & (uint16_t)0xFFF8) == 0x00) && ((IT) != 0x00))
 62→#define IS_RTC_GET_IT(IT) (((IT) == RTC_IT_OW) || ((IT) == RTC_IT_ALR) || \
 63→                           ((IT) == RTC_IT_SEC))
 64→/**
 65→  * @}
 66→  */ 
 67→
 68→/** @defgroup RTC_interrupts_flags 
 69→  * @{
 70→  */
 71→
 72→#define RTC_FLAG_RTOFF       ((uint16_t)0x0020)  /*!< RTC Operation OFF flag */
 73→#define RTC_FLAG_RSF         ((uint16_t)0x0008)  /*!< Registers Synchronized flag */
 74→#define RTC_FLAG_OW          ((uint16_t)0x0004)  /*!< Overflow flag */
 75→#define RTC_FLAG_ALR         ((uint16_t)0x0002)  /*!< Alarm flag */
 76→#define RTC_FLAG_SEC         ((uint16_t)0x0001)  /*!< Second flag */
 77→#define IS_RTC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint16_t)0xFFF0) == 0x00) && ((FLAG) != 0x00))
 78→#define IS_RTC_GET_FLAG(FLAG) (((FLAG) == RTC_FLAG_RTOFF) || ((FLAG) == RTC_FLAG_RSF) || \
 79→                               ((FLAG) == RTC_FLAG_OW) || ((FLAG) == RTC_FLAG_ALR) || \
 80→                               ((FLAG) == RTC_FLAG_SEC))
 81→#define IS_RTC_PRESCALER(PRESCALER) ((PRESCALER) <= 0xFFFFF)
 82→
 83→/**
 84→  * @}
 85→  */
 86→
 87→/**
 88→  * @}
 89→  */
 90→
 91→/** @defgroup RTC_Exported_Macros
 92→  * @{
 93→  */
 94→
 95→/**
 96→  * @}
 97→  */
 98→
 99→/** @defgroup RTC_Exported_Functions
100→  * @{
101→  */
102→
103→void RTC_ITConfig(uint16_t RTC_IT, FunctionalState NewState);
104→void RTC_EnterConfigMode(void);
105→void RTC_ExitConfigMode(void);
106→uint32_t  RTC_GetCounter(void);
107→void RTC_SetCounter(uint32_t CounterValue);
108→void RTC_SetPrescaler(uint32_t PrescalerValue);
109→void RTC_SetAlarm(uint32_t AlarmValue);
110→uint32_t  RTC_GetDivider(void);
111→void RTC_WaitForLastTask(void);
112→void RTC_WaitForSynchro(void);
113→FlagStatus RTC_GetFlagStatus(uint16_t RTC_FLAG);
114→void RTC_ClearFlag(uint16_t RTC_FLAG);
115→ITStatus RTC_GetITStatus(uint16_t RTC_IT);
116→void RTC_ClearITPendingBit(uint16_t RTC_IT);
117→
118→#ifdef __cplusplus
119→}
120→#endif
121→
122→#endif /* __STM32F10x_RTC_H */
123→/**
124→  * @}
125→  */
126→
127→/**
128→  * @}
129→  */
130→
131→/**
132→  * @}
133→  */
134→
135→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/