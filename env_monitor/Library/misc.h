  1→/**
  2→  ******************************************************************************
  3→  * @file    misc.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the miscellaneous
  8→  *          firmware library functions (add-on to CMSIS functions).
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
 24→#ifndef __MISC_H
 25→#define __MISC_H
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
 38→/** @addtogroup MISC
 39→  * @{
 40→  */
 41→
 42→/** @defgroup MISC_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  NVIC Init Structure definition  
 48→  */
 49→
 50→typedef struct
 51→{
 52→  uint8_t NVIC_IRQChannel;                    /*!< Specifies the IRQ channel to be enabled or disabled.
 53→                                                   This parameter can be a value of @ref IRQn_Type 
 54→                                                   (For the complete STM32 Devices IRQ Channels list, please
 55→                                                    refer to stm32f10x.h file) */
 56→
 57→  uint8_t NVIC_IRQChannelPreemptionPriority;  /*!< Specifies the pre-emption priority for the IRQ channel
 58→                                                   specified in NVIC_IRQChannel. This parameter can be a value
 59→                                                   between 0 and 15 as described in the table @ref NVIC_Priority_Table */
 60→
 61→  uint8_t NVIC_IRQChannelSubPriority;         /*!< Specifies the subpriority level for the IRQ channel specified
 62→                                                   in NVIC_IRQChannel. This parameter can be a value
 63→                                                   between 0 and 15 as described in the table @ref NVIC_Priority_Table */
 64→
 65→  FunctionalState NVIC_IRQChannelCmd;         /*!< Specifies whether the IRQ channel defined in NVIC_IRQChannel
 66→                                                   will be enabled or disabled. 
 67→                                                   This parameter can be set either to ENABLE or DISABLE */   
 68→} NVIC_InitTypeDef;
 69→ 
 70→/**
 71→  * @}
 72→  */
 73→
 74→/** @defgroup NVIC_Priority_Table 
 75→  * @{
 76→  */
 77→
 78→/**
 79→@code  
 80→ The table below gives the allowed values of the pre-emption priority and subpriority according
 81→ to the Priority Grouping configuration performed by NVIC_PriorityGroupConfig function
 82→  ============================================================================================================================
 83→    NVIC_PriorityGroup   | NVIC_IRQChannelPreemptionPriority | NVIC_IRQChannelSubPriority  | Description
 84→  ============================================================================================================================
 85→   NVIC_PriorityGroup_0  |                0                  |            0-15             |   0 bits for pre-emption priority
 86→                         |                                   |                             |   4 bits for subpriority
 87→  ----------------------------------------------------------------------------------------------------------------------------
 88→   NVIC_PriorityGroup_1  |                0-1                |            0-7              |   1 bits for pre-emption priority
 89→                         |                                   |                             |   3 bits for subpriority
 90→  ----------------------------------------------------------------------------------------------------------------------------    
 91→   NVIC_PriorityGroup_2  |                0-3                |            0-3              |   2 bits for pre-emption priority
 92→                         |                                   |                             |   2 bits for subpriority
 93→  ----------------------------------------------------------------------------------------------------------------------------    
 94→   NVIC_PriorityGroup_3  |                0-7                |            0-1              |   3 bits for pre-emption priority
 95→                         |                                   |                             |   1 bits for subpriority
 96→  ----------------------------------------------------------------------------------------------------------------------------    
 97→   NVIC_PriorityGroup_4  |                0-15               |            0                |   4 bits for pre-emption priority
 98→                         |                                   |                             |   0 bits for subpriority                       
 99→  ============================================================================================================================
100→@endcode
101→*/
102→
103→/**
104→  * @}
105→  */
106→
107→/** @defgroup MISC_Exported_Constants
108→  * @{
109→  */
110→
111→/** @defgroup Vector_Table_Base 
112→  * @{
113→  */
114→
115→#define NVIC_VectTab_RAM             ((uint32_t)0x20000000)
116→#define NVIC_VectTab_FLASH           ((uint32_t)0x08000000)
117→#define IS_NVIC_VECTTAB(VECTTAB) (((VECTTAB) == NVIC_VectTab_RAM) || \
118→                                  ((VECTTAB) == NVIC_VectTab_FLASH))
119→/**
120→  * @}
121→  */
122→
123→/** @defgroup System_Low_Power 
124→  * @{
125→  */
126→
127→#define NVIC_LP_SEVONPEND            ((uint8_t)0x10)
128→#define NVIC_LP_SLEEPDEEP            ((uint8_t)0x04)
129→#define NVIC_LP_SLEEPONEXIT          ((uint8_t)0x02)
130→#define IS_NVIC_LP(LP) (((LP) == NVIC_LP_SEVONPEND) || \
131→                        ((LP) == NVIC_LP_SLEEPDEEP) || \
132→                        ((LP) == NVIC_LP_SLEEPONEXIT))
133→/**
134→  * @}
135→  */
136→
137→/** @defgroup Preemption_Priority_Group 
138→  * @{
139→  */
140→
141→#define NVIC_PriorityGroup_0         ((uint32_t)0x700) /*!< 0 bits for pre-emption priority
142→                                                            4 bits for subpriority */
143→#define NVIC_PriorityGroup_1         ((uint32_t)0x600) /*!< 1 bits for pre-emption priority
144→                                                            3 bits for subpriority */
145→#define NVIC_PriorityGroup_2         ((uint32_t)0x500) /*!< 2 bits for pre-emption priority
146→                                                            2 bits for subpriority */
147→#define NVIC_PriorityGroup_3         ((uint32_t)0x400) /*!< 3 bits for pre-emption priority
148→                                                            1 bits for subpriority */
149→#define NVIC_PriorityGroup_4         ((uint32_t)0x300) /*!< 4 bits for pre-emption priority
150→                                                            0 bits for subpriority */
151→
152→#define IS_NVIC_PRIORITY_GROUP(GROUP) (((GROUP) == NVIC_PriorityGroup_0) || \
153→                                       ((GROUP) == NVIC_PriorityGroup_1) || \
154→                                       ((GROUP) == NVIC_PriorityGroup_2) || \
155→                                       ((GROUP) == NVIC_PriorityGroup_3) || \
156→                                       ((GROUP) == NVIC_PriorityGroup_4))
157→
158→#define IS_NVIC_PREEMPTION_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10)
159→
160→#define IS_NVIC_SUB_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10)
161→
162→#define IS_NVIC_OFFSET(OFFSET)  ((OFFSET) < 0x000FFFFF)
163→
164→/**
165→  * @}
166→  */
167→
168→/** @defgroup SysTick_clock_source 
169→  * @{
170→  */
171→
172→#define SysTick_CLKSource_HCLK_Div8    ((uint32_t)0xFFFFFFFB)
173→#define SysTick_CLKSource_HCLK         ((uint32_t)0x00000004)
174→#define IS_SYSTICK_CLK_SOURCE(SOURCE) (((SOURCE) == SysTick_CLKSource_HCLK) || \
175→                                       ((SOURCE) == SysTick_CLKSource_HCLK_Div8))
176→/**
177→  * @}
178→  */
179→
180→/**
181→  * @}
182→  */
183→
184→/** @defgroup MISC_Exported_Macros
185→  * @{
186→  */
187→
188→/**
189→  * @}
190→  */
191→
192→/** @defgroup MISC_Exported_Functions
193→  * @{
194→  */
195→
196→void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
197→void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
198→void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
199→void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);
200→void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);
201→
202→#ifdef __cplusplus
203→}
204→#endif
205→
206→#endif /* __MISC_H */
207→
208→/**
209→  * @}
210→  */
211→
212→/**
213→  * @}
214→  */
215→
216→/**
217→  * @}
218→  */
219→
220→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/