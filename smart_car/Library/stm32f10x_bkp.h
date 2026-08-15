  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_bkp.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the BKP firmware 
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
 24→#ifndef __STM32F10x_BKP_H
 25→#define __STM32F10x_BKP_H
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
 38→/** @addtogroup BKP
 39→  * @{
 40→  */
 41→
 42→/** @defgroup BKP_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/**
 47→  * @}
 48→  */
 49→
 50→/** @defgroup BKP_Exported_Constants
 51→  * @{
 52→  */
 53→
 54→/** @defgroup Tamper_Pin_active_level 
 55→  * @{
 56→  */
 57→
 58→#define BKP_TamperPinLevel_High           ((uint16_t)0x0000)
 59→#define BKP_TamperPinLevel_Low            ((uint16_t)0x0001)
 60→#define IS_BKP_TAMPER_PIN_LEVEL(LEVEL) (((LEVEL) == BKP_TamperPinLevel_High) || \
 61→                                        ((LEVEL) == BKP_TamperPinLevel_Low))
 62→/**
 63→  * @}
 64→  */
 65→
 66→/** @defgroup RTC_output_source_to_output_on_the_Tamper_pin 
 67→  * @{
 68→  */
 69→
 70→#define BKP_RTCOutputSource_None          ((uint16_t)0x0000)
 71→#define BKP_RTCOutputSource_CalibClock    ((uint16_t)0x0080)
 72→#define BKP_RTCOutputSource_Alarm         ((uint16_t)0x0100)
 73→#define BKP_RTCOutputSource_Second        ((uint16_t)0x0300)
 74→#define IS_BKP_RTC_OUTPUT_SOURCE(SOURCE) (((SOURCE) == BKP_RTCOutputSource_None) || \
 75→                                          ((SOURCE) == BKP_RTCOutputSource_CalibClock) || \
 76→                                          ((SOURCE) == BKP_RTCOutputSource_Alarm) || \
 77→                                          ((SOURCE) == BKP_RTCOutputSource_Second))
 78→/**
 79→  * @}
 80→  */
 81→
 82→/** @defgroup Data_Backup_Register 
 83→  * @{
 84→  */
 85→
 86→#define BKP_DR1                           ((uint16_t)0x0004)
 87→#define BKP_DR2                           ((uint16_t)0x0008)
 88→#define BKP_DR3                           ((uint16_t)0x000C)
 89→#define BKP_DR4                           ((uint16_t)0x0010)
 90→#define BKP_DR5                           ((uint16_t)0x0014)
 91→#define BKP_DR6                           ((uint16_t)0x0018)
 92→#define BKP_DR7                           ((uint16_t)0x001C)
 93→#define BKP_DR8                           ((uint16_t)0x0020)
 94→#define BKP_DR9                           ((uint16_t)0x0024)
 95→#define BKP_DR10                          ((uint16_t)0x0028)
 96→#define BKP_DR11                          ((uint16_t)0x0040)
 97→#define BKP_DR12                          ((uint16_t)0x0044)
 98→#define BKP_DR13                          ((uint16_t)0x0048)
 99→#define BKP_DR14                          ((uint16_t)0x004C)
100→#define BKP_DR15                          ((uint16_t)0x0050)
101→#define BKP_DR16                          ((uint16_t)0x0054)
102→#define BKP_DR17                          ((uint16_t)0x0058)
103→#define BKP_DR18                          ((uint16_t)0x005C)
104→#define BKP_DR19                          ((uint16_t)0x0060)
105→#define BKP_DR20                          ((uint16_t)0x0064)
106→#define BKP_DR21                          ((uint16_t)0x0068)
107→#define BKP_DR22                          ((uint16_t)0x006C)
108→#define BKP_DR23                          ((uint16_t)0x0070)
109→#define BKP_DR24                          ((uint16_t)0x0074)
110→#define BKP_DR25                          ((uint16_t)0x0078)
111→#define BKP_DR26                          ((uint16_t)0x007C)
112→#define BKP_DR27                          ((uint16_t)0x0080)
113→#define BKP_DR28                          ((uint16_t)0x0084)
114→#define BKP_DR29                          ((uint16_t)0x0088)
115→#define BKP_DR30                          ((uint16_t)0x008C)
116→#define BKP_DR31                          ((uint16_t)0x0090)
117→#define BKP_DR32                          ((uint16_t)0x0094)
118→#define BKP_DR33                          ((uint16_t)0x0098)
119→#define BKP_DR34                          ((uint16_t)0x009C)
120→#define BKP_DR35                          ((uint16_t)0x00A0)
121→#define BKP_DR36                          ((uint16_t)0x00A4)
122→#define BKP_DR37                          ((uint16_t)0x00A8)
123→#define BKP_DR38                          ((uint16_t)0x00AC)
124→#define BKP_DR39                          ((uint16_t)0x00B0)
125→#define BKP_DR40                          ((uint16_t)0x00B4)
126→#define BKP_DR41                          ((uint16_t)0x00B8)
127→#define BKP_DR42                          ((uint16_t)0x00BC)
128→
129→#define IS_BKP_DR(DR) (((DR) == BKP_DR1)  || ((DR) == BKP_DR2)  || ((DR) == BKP_DR3)  || \
130→                       ((DR) == BKP_DR4)  || ((DR) == BKP_DR5)  || ((DR) == BKP_DR6)  || \
131→                       ((DR) == BKP_DR7)  || ((DR) == BKP_DR8)  || ((DR) == BKP_DR9)  || \
132→                       ((DR) == BKP_DR10) || ((DR) == BKP_DR11) || ((DR) == BKP_DR12) || \
133→                       ((DR) == BKP_DR13) || ((DR) == BKP_DR14) || ((DR) == BKP_DR15) || \
134→                       ((DR) == BKP_DR16) || ((DR) == BKP_DR17) || ((DR) == BKP_DR18) || \
135→                       ((DR) == BKP_DR19) || ((DR) == BKP_DR20) || ((DR) == BKP_DR21) || \
136→                       ((DR) == BKP_DR22) || ((DR) == BKP_DR23) || ((DR) == BKP_DR24) || \
137→                       ((DR) == BKP_DR25) || ((DR) == BKP_DR26) || ((DR) == BKP_DR27) || \
138→                       ((DR) == BKP_DR28) || ((DR) == BKP_DR29) || ((DR) == BKP_DR30) || \
139→                       ((DR) == BKP_DR31) || ((DR) == BKP_DR32) || ((DR) == BKP_DR33) || \
140→                       ((DR) == BKP_DR34) || ((DR) == BKP_DR35) || ((DR) == BKP_DR36) || \
141→                       ((DR) == BKP_DR37) || ((DR) == BKP_DR38) || ((DR) == BKP_DR39) || \
142→                       ((DR) == BKP_DR40) || ((DR) == BKP_DR41) || ((DR) == BKP_DR42))
143→
144→#define IS_BKP_CALIBRATION_VALUE(VALUE) ((VALUE) <= 0x7F)
145→/**
146→  * @}
147→  */
148→
149→/**
150→  * @}
151→  */
152→
153→/** @defgroup BKP_Exported_Macros
154→  * @{
155→  */
156→
157→/**
158→  * @}
159→  */
160→
161→/** @defgroup BKP_Exported_Functions
162→  * @{
163→  */
164→
165→void BKP_DeInit(void);
166→void BKP_TamperPinLevelConfig(uint16_t BKP_TamperPinLevel);
167→void BKP_TamperPinCmd(FunctionalState NewState);
168→void BKP_ITConfig(FunctionalState NewState);
169→void BKP_RTCOutputConfig(uint16_t BKP_RTCOutputSource);
170→void BKP_SetRTCCalibrationValue(uint8_t CalibrationValue);
171→void BKP_WriteBackupRegister(uint16_t BKP_DR, uint16_t Data);
172→uint16_t BKP_ReadBackupRegister(uint16_t BKP_DR);
173→FlagStatus BKP_GetFlagStatus(void);
174→void BKP_ClearFlag(void);
175→ITStatus BKP_GetITStatus(void);
176→void BKP_ClearITPendingBit(void);
177→
178→#ifdef __cplusplus
179→}
180→#endif
181→
182→#endif /* __STM32F10x_BKP_H */
183→/**
184→  * @}
185→  */
186→
187→/**
188→  * @}
189→  */
190→
191→/**
192→  * @}
193→  */
194→
195→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/