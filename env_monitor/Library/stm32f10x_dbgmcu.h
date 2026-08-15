  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_dbgmcu.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the DBGMCU 
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
 24→#ifndef __STM32F10x_DBGMCU_H
 25→#define __STM32F10x_DBGMCU_H
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
 38→/** @addtogroup DBGMCU
 39→  * @{
 40→  */
 41→
 42→/** @defgroup DBGMCU_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/**
 47→  * @}
 48→  */
 49→
 50→/** @defgroup DBGMCU_Exported_Constants
 51→  * @{
 52→  */
 53→
 54→#define DBGMCU_SLEEP                 ((uint32_t)0x00000001)
 55→#define DBGMCU_STOP                  ((uint32_t)0x00000002)
 56→#define DBGMCU_STANDBY               ((uint32_t)0x00000004)
 57→#define DBGMCU_IWDG_STOP             ((uint32_t)0x00000100)
 58→#define DBGMCU_WWDG_STOP             ((uint32_t)0x00000200)
 59→#define DBGMCU_TIM1_STOP             ((uint32_t)0x00000400)
 60→#define DBGMCU_TIM2_STOP             ((uint32_t)0x00000800)
 61→#define DBGMCU_TIM3_STOP             ((uint32_t)0x00001000)
 62→#define DBGMCU_TIM4_STOP             ((uint32_t)0x00002000)
 63→#define DBGMCU_CAN1_STOP             ((uint32_t)0x00004000)
 64→#define DBGMCU_I2C1_SMBUS_TIMEOUT    ((uint32_t)0x00008000)
 65→#define DBGMCU_I2C2_SMBUS_TIMEOUT    ((uint32_t)0x00010000)
 66→#define DBGMCU_TIM8_STOP             ((uint32_t)0x00020000)
 67→#define DBGMCU_TIM5_STOP             ((uint32_t)0x00040000)
 68→#define DBGMCU_TIM6_STOP             ((uint32_t)0x00080000)
 69→#define DBGMCU_TIM7_STOP             ((uint32_t)0x00100000)
 70→#define DBGMCU_CAN2_STOP             ((uint32_t)0x00200000)
 71→#define DBGMCU_TIM15_STOP            ((uint32_t)0x00400000)
 72→#define DBGMCU_TIM16_STOP            ((uint32_t)0x00800000)
 73→#define DBGMCU_TIM17_STOP            ((uint32_t)0x01000000)
 74→#define DBGMCU_TIM12_STOP            ((uint32_t)0x02000000)
 75→#define DBGMCU_TIM13_STOP            ((uint32_t)0x04000000)
 76→#define DBGMCU_TIM14_STOP            ((uint32_t)0x08000000)
 77→#define DBGMCU_TIM9_STOP             ((uint32_t)0x10000000)
 78→#define DBGMCU_TIM10_STOP            ((uint32_t)0x20000000)
 79→#define DBGMCU_TIM11_STOP            ((uint32_t)0x40000000)
 80→                                              
 81→#define IS_DBGMCU_PERIPH(PERIPH) ((((PERIPH) & 0x800000F8) == 0x00) && ((PERIPH) != 0x00))
 82→/**
 83→  * @}
 84→  */ 
 85→
 86→/** @defgroup DBGMCU_Exported_Macros
 87→  * @{
 88→  */
 89→
 90→/**
 91→  * @}
 92→  */
 93→
 94→/** @defgroup DBGMCU_Exported_Functions
 95→  * @{
 96→  */
 97→
 98→uint32_t DBGMCU_GetREVID(void);
 99→uint32_t DBGMCU_GetDEVID(void);
100→void DBGMCU_Config(uint32_t DBGMCU_Periph, FunctionalState NewState);
101→
102→#ifdef __cplusplus
103→}
104→#endif
105→
106→#endif /* __STM32F10x_DBGMCU_H */
107→/**
108→  * @}
109→  */
110→
111→/**
112→  * @}
113→  */
114→
115→/**
116→  * @}
117→  */
118→
119→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/