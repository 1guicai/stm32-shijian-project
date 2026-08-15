  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_pwr.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the PWR firmware 
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
 24→#ifndef __STM32F10x_PWR_H
 25→#define __STM32F10x_PWR_H
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
 38→/** @addtogroup PWR
 39→  * @{
 40→  */ 
 41→
 42→/** @defgroup PWR_Exported_Types
 43→  * @{
 44→  */ 
 45→
 46→/**
 47→  * @}
 48→  */ 
 49→
 50→/** @defgroup PWR_Exported_Constants
 51→  * @{
 52→  */ 
 53→
 54→/** @defgroup PVD_detection_level 
 55→  * @{
 56→  */ 
 57→
 58→#define PWR_PVDLevel_2V2          ((uint32_t)0x00000000)
 59→#define PWR_PVDLevel_2V3          ((uint32_t)0x00000020)
 60→#define PWR_PVDLevel_2V4          ((uint32_t)0x00000040)
 61→#define PWR_PVDLevel_2V5          ((uint32_t)0x00000060)
 62→#define PWR_PVDLevel_2V6          ((uint32_t)0x00000080)
 63→#define PWR_PVDLevel_2V7          ((uint32_t)0x000000A0)
 64→#define PWR_PVDLevel_2V8          ((uint32_t)0x000000C0)
 65→#define PWR_PVDLevel_2V9          ((uint32_t)0x000000E0)
 66→#define IS_PWR_PVD_LEVEL(LEVEL) (((LEVEL) == PWR_PVDLevel_2V2) || ((LEVEL) == PWR_PVDLevel_2V3)|| \
 67→                                 ((LEVEL) == PWR_PVDLevel_2V4) || ((LEVEL) == PWR_PVDLevel_2V5)|| \
 68→                                 ((LEVEL) == PWR_PVDLevel_2V6) || ((LEVEL) == PWR_PVDLevel_2V7)|| \
 69→                                 ((LEVEL) == PWR_PVDLevel_2V8) || ((LEVEL) == PWR_PVDLevel_2V9))
 70→/**
 71→  * @}
 72→  */
 73→
 74→/** @defgroup Regulator_state_is_STOP_mode 
 75→  * @{
 76→  */
 77→
 78→#define PWR_Regulator_ON          ((uint32_t)0x00000000)
 79→#define PWR_Regulator_LowPower    ((uint32_t)0x00000001)
 80→#define IS_PWR_REGULATOR(REGULATOR) (((REGULATOR) == PWR_Regulator_ON) || \
 81→                                     ((REGULATOR) == PWR_Regulator_LowPower))
 82→/**
 83→  * @}
 84→  */
 85→
 86→/** @defgroup STOP_mode_entry 
 87→  * @{
 88→  */
 89→
 90→#define PWR_STOPEntry_WFI         ((uint8_t)0x01)
 91→#define PWR_STOPEntry_WFE         ((uint8_t)0x02)
 92→#define IS_PWR_STOP_ENTRY(ENTRY) (((ENTRY) == PWR_STOPEntry_WFI) || ((ENTRY) == PWR_STOPEntry_WFE))
 93→ 
 94→/**
 95→  * @}
 96→  */
 97→
 98→/** @defgroup PWR_Flag 
 99→  * @{
100→  */
101→
102→#define PWR_FLAG_WU               ((uint32_t)0x00000001)
103→#define PWR_FLAG_SB               ((uint32_t)0x00000002)
104→#define PWR_FLAG_PVDO             ((uint32_t)0x00000004)
105→#define IS_PWR_GET_FLAG(FLAG) (((FLAG) == PWR_FLAG_WU) || ((FLAG) == PWR_FLAG_SB) || \
106→                               ((FLAG) == PWR_FLAG_PVDO))
107→
108→#define IS_PWR_CLEAR_FLAG(FLAG) (((FLAG) == PWR_FLAG_WU) || ((FLAG) == PWR_FLAG_SB))
109→/**
110→  * @}
111→  */
112→
113→/**
114→  * @}
115→  */
116→
117→/** @defgroup PWR_Exported_Macros
118→  * @{
119→  */
120→
121→/**
122→  * @}
123→  */
124→
125→/** @defgroup PWR_Exported_Functions
126→  * @{
127→  */
128→
129→void PWR_DeInit(void);
130→void PWR_BackupAccessCmd(FunctionalState NewState);
131→void PWR_PVDCmd(FunctionalState NewState);
132→void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel);
133→void PWR_WakeUpPinCmd(FunctionalState NewState);
134→void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
135→void PWR_EnterSTANDBYMode(void);
136→FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG);
137→void PWR_ClearFlag(uint32_t PWR_FLAG);
138→
139→#ifdef __cplusplus
140→}
141→#endif
142→
143→#endif /* __STM32F10x_PWR_H */
144→/**
145→  * @}
146→  */
147→
148→/**
149→  * @}
150→  */
151→
152→/**
153→  * @}
154→  */
155→
156→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/