  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_iwdg.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the IWDG 
  8→  *          firmware library.
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
 24→#ifndef __STM32F10x_IWDG_H
 25→#define __STM32F10x_IWDG_H
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
 38→/** @addtogroup IWDG
 39→  * @{
 40→  */
 41→
 42→/** @defgroup IWDG_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/**
 47→  * @}
 48→  */
 49→
 50→/** @defgroup IWDG_Exported_Constants
 51→  * @{
 52→  */
 53→
 54→/** @defgroup IWDG_WriteAccess
 55→  * @{
 56→  */
 57→
 58→#define IWDG_WriteAccess_Enable     ((uint16_t)0x5555)
 59→#define IWDG_WriteAccess_Disable    ((uint16_t)0x0000)
 60→#define IS_IWDG_WRITE_ACCESS(ACCESS) (((ACCESS) == IWDG_WriteAccess_Enable) || \
 61→                                      ((ACCESS) == IWDG_WriteAccess_Disable))
 62→/**
 63→  * @}
 64→  */
 65→
 66→/** @defgroup IWDG_prescaler 
 67→  * @{
 68→  */
 69→
 70→#define IWDG_Prescaler_4            ((uint8_t)0x00)
 71→#define IWDG_Prescaler_8            ((uint8_t)0x01)
 72→#define IWDG_Prescaler_16           ((uint8_t)0x02)
 73→#define IWDG_Prescaler_32           ((uint8_t)0x03)
 74→#define IWDG_Prescaler_64           ((uint8_t)0x04)
 75→#define IWDG_Prescaler_128          ((uint8_t)0x05)
 76→#define IWDG_Prescaler_256          ((uint8_t)0x06)
 77→#define IS_IWDG_PRESCALER(PRESCALER) (((PRESCALER) == IWDG_Prescaler_4)  || \
 78→                                      ((PRESCALER) == IWDG_Prescaler_8)  || \
 79→                                      ((PRESCALER) == IWDG_Prescaler_16) || \
 80→                                      ((PRESCALER) == IWDG_Prescaler_32) || \
 81→                                      ((PRESCALER) == IWDG_Prescaler_64) || \
 82→                                      ((PRESCALER) == IWDG_Prescaler_128)|| \
 83→                                      ((PRESCALER) == IWDG_Prescaler_256))
 84→/**
 85→  * @}
 86→  */
 87→
 88→/** @defgroup IWDG_Flag 
 89→  * @{
 90→  */
 91→
 92→#define IWDG_FLAG_PVU               ((uint16_t)0x0001)
 93→#define IWDG_FLAG_RVU               ((uint16_t)0x0002)
 94→#define IS_IWDG_FLAG(FLAG) (((FLAG) == IWDG_FLAG_PVU) || ((FLAG) == IWDG_FLAG_RVU))
 95→#define IS_IWDG_RELOAD(RELOAD) ((RELOAD) <= 0xFFF)
 96→/**
 97→  * @}
 98→  */
 99→
100→/**
101→  * @}
102→  */
103→
104→/** @defgroup IWDG_Exported_Macros
105→  * @{
106→  */
107→
108→/**
109→  * @}
110→  */
111→
112→/** @defgroup IWDG_Exported_Functions
113→  * @{
114→  */
115→
116→void IWDG_WriteAccessCmd(uint16_t IWDG_WriteAccess);
117→void IWDG_SetPrescaler(uint8_t IWDG_Prescaler);
118→void IWDG_SetReload(uint16_t Reload);
119→void IWDG_ReloadCounter(void);
120→void IWDG_Enable(void);
121→FlagStatus IWDG_GetFlagStatus(uint16_t IWDG_FLAG);
122→
123→#ifdef __cplusplus
124→}
125→#endif
126→
127→#endif /* __STM32F10x_IWDG_H */
128→/**
129→  * @}
130→  */
131→
132→/**
133→  * @}
134→  */
135→
136→/**
137→  * @}
138→  */
139→
140→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/