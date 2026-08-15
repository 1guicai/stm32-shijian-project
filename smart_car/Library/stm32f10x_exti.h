  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_exti.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the EXTI firmware
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
 24→#ifndef __STM32F10x_EXTI_H
 25→#define __STM32F10x_EXTI_H
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
 38→/** @addtogroup EXTI
 39→  * @{
 40→  */
 41→
 42→/** @defgroup EXTI_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  EXTI mode enumeration  
 48→  */
 49→
 50→typedef enum
 51→{
 52→  EXTI_Mode_Interrupt = 0x00,
 53→  EXTI_Mode_Event = 0x04
 54→}EXTIMode_TypeDef;
 55→
 56→#define IS_EXTI_MODE(MODE) (((MODE) == EXTI_Mode_Interrupt) || ((MODE) == EXTI_Mode_Event))
 57→
 58→/** 
 59→  * @brief  EXTI Trigger enumeration  
 60→  */
 61→
 62→typedef enum
 63→{
 64→  EXTI_Trigger_Rising = 0x08,
 65→  EXTI_Trigger_Falling = 0x0C,  
 66→  EXTI_Trigger_Rising_Falling = 0x10
 67→}EXTITrigger_TypeDef;
 68→
 69→#define IS_EXTI_TRIGGER(TRIGGER) (((TRIGGER) == EXTI_Trigger_Rising) || \
 70→                                  ((TRIGGER) == EXTI_Trigger_Falling) || \
 71→                                  ((TRIGGER) == EXTI_Trigger_Rising_Falling))
 72→/** 
 73→  * @brief  EXTI Init Structure definition  
 74→  */
 75→
 76→typedef struct
 77→{
 78→  uint32_t EXTI_Line;               /*!< Specifies the EXTI lines to be enabled or disabled.
 79→                                         This parameter can be any combination of @ref EXTI_Lines */
 80→   
 81→  EXTIMode_TypeDef EXTI_Mode;       /*!< Specifies the mode for the EXTI lines.
 82→                                         This parameter can be a value of @ref EXTIMode_TypeDef */
 83→
 84→  EXTITrigger_TypeDef EXTI_Trigger; /*!< Specifies the trigger signal active edge for the EXTI lines.
 85→                                         This parameter can be a value of @ref EXTIMode_TypeDef */
 86→
 87→  FunctionalState EXTI_LineCmd;     /*!< Specifies the new state of the selected EXTI lines.
 88→                                         This parameter can be set either to ENABLE or DISABLE */ 
 89→}EXTI_InitTypeDef;
 90→
 91→/**
 92→  * @}
 93→  */
 94→
 95→/** @defgroup EXTI_Exported_Constants
 96→  * @{
 97→  */
 98→
 99→/** @defgroup EXTI_Lines 
100→  * @{
101→  */
102→
103→#define EXTI_Line0       ((uint32_t)0x00001)  /*!< External interrupt line 0 */
104→#define EXTI_Line1       ((uint32_t)0x00002)  /*!< External interrupt line 1 */
105→#define EXTI_Line2       ((uint32_t)0x00004)  /*!< External interrupt line 2 */
106→#define EXTI_Line3       ((uint32_t)0x00008)  /*!< External interrupt line 3 */
107→#define EXTI_Line4       ((uint32_t)0x00010)  /*!< External interrupt line 4 */
108→#define EXTI_Line5       ((uint32_t)0x00020)  /*!< External interrupt line 5 */
109→#define EXTI_Line6       ((uint32_t)0x00040)  /*!< External interrupt line 6 */
110→#define EXTI_Line7       ((uint32_t)0x00080)  /*!< External interrupt line 7 */
111→#define EXTI_Line8       ((uint32_t)0x00100)  /*!< External interrupt line 8 */
112→#define EXTI_Line9       ((uint32_t)0x00200)  /*!< External interrupt line 9 */
113→#define EXTI_Line10      ((uint32_t)0x00400)  /*!< External interrupt line 10 */
114→#define EXTI_Line11      ((uint32_t)0x00800)  /*!< External interrupt line 11 */
115→#define EXTI_Line12      ((uint32_t)0x01000)  /*!< External interrupt line 12 */
116→#define EXTI_Line13      ((uint32_t)0x02000)  /*!< External interrupt line 13 */
117→#define EXTI_Line14      ((uint32_t)0x04000)  /*!< External interrupt line 14 */
118→#define EXTI_Line15      ((uint32_t)0x08000)  /*!< External interrupt line 15 */
119→#define EXTI_Line16      ((uint32_t)0x10000)  /*!< External interrupt line 16 Connected to the PVD Output */
120→#define EXTI_Line17      ((uint32_t)0x20000)  /*!< External interrupt line 17 Connected to the RTC Alarm event */
121→#define EXTI_Line18      ((uint32_t)0x40000)  /*!< External interrupt line 18 Connected to the USB Device/USB OTG FS
122→                                                   Wakeup from suspend event */                                    
123→#define EXTI_Line19      ((uint32_t)0x80000)  /*!< External interrupt line 19 Connected to the Ethernet Wakeup event */
124→                                          
125→#define IS_EXTI_LINE(LINE) ((((LINE) & (uint32_t)0xFFF00000) == 0x00) && ((LINE) != (uint16_t)0x00))
126→#define IS_GET_EXTI_LINE(LINE) (((LINE) == EXTI_Line0) || ((LINE) == EXTI_Line1) || \
127→                            ((LINE) == EXTI_Line2) || ((LINE) == EXTI_Line3) || \
128→                            ((LINE) == EXTI_Line4) || ((LINE) == EXTI_Line5) || \
129→                            ((LINE) == EXTI_Line6) || ((LINE) == EXTI_Line7) || \
130→                            ((LINE) == EXTI_Line8) || ((LINE) == EXTI_Line9) || \
131→                            ((LINE) == EXTI_Line10) || ((LINE) == EXTI_Line11) || \
132→                            ((LINE) == EXTI_Line12) || ((LINE) == EXTI_Line13) || \
133→                            ((LINE) == EXTI_Line14) || ((LINE) == EXTI_Line15) || \
134→                            ((LINE) == EXTI_Line16) || ((LINE) == EXTI_Line17) || \
135→                            ((LINE) == EXTI_Line18) || ((LINE) == EXTI_Line19))
136→
137→                    
138→/**
139→  * @}
140→  */
141→
142→/**
143→  * @}
144→  */
145→
146→/** @defgroup EXTI_Exported_Macros
147→  * @{
148→  */
149→
150→/**
151→  * @}
152→  */
153→
154→/** @defgroup EXTI_Exported_Functions
155→  * @{
156→  */
157→
158→void EXTI_DeInit(void);
159→void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);
160→void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);
161→void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);
162→FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);
163→void EXTI_ClearFlag(uint32_t EXTI_Line);
164→ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
165→void EXTI_ClearITPendingBit(uint32_t EXTI_Line);
166→
167→#ifdef __cplusplus
168→}
169→#endif
170→
171→#endif /* __STM32F10x_EXTI_H */
172→/**
173→  * @}
174→  */
175→
176→/**
177→  * @}
178→  */
179→
180→/**
181→  * @}
182→  */
183→
184→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/