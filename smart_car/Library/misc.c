  1→/**
  2→  ******************************************************************************
  3→  * @file    misc.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the miscellaneous firmware functions (add-on
  8→  *          to CMSIS functions).
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
 23→/* Includes ------------------------------------------------------------------*/
 24→#include "misc.h"
 25→
 26→/** @addtogroup STM32F10x_StdPeriph_Driver
 27→  * @{
 28→  */
 29→
 30→/** @defgroup MISC 
 31→  * @brief MISC driver modules
 32→  * @{
 33→  */
 34→
 35→/** @defgroup MISC_Private_TypesDefinitions
 36→  * @{
 37→  */
 38→
 39→/**
 40→  * @}
 41→  */ 
 42→
 43→/** @defgroup MISC_Private_Defines
 44→  * @{
 45→  */
 46→
 47→#define AIRCR_VECTKEY_MASK    ((uint32_t)0x05FA0000)
 48→/**
 49→  * @}
 50→  */
 51→
 52→/** @defgroup MISC_Private_Macros
 53→  * @{
 54→  */
 55→
 56→/**
 57→  * @}
 58→  */
 59→
 60→/** @defgroup MISC_Private_Variables
 61→  * @{
 62→  */
 63→
 64→/**
 65→  * @}
 66→  */
 67→
 68→/** @defgroup MISC_Private_FunctionPrototypes
 69→  * @{
 70→  */
 71→
 72→/**
 73→  * @}
 74→  */
 75→
 76→/** @defgroup MISC_Private_Functions
 77→  * @{
 78→  */
 79→
 80→/**
 81→  * @brief  Configures the priority grouping: pre-emption priority and subpriority.
 82→  * @param  NVIC_PriorityGroup: specifies the priority grouping bits length. 
 83→  *   This parameter can be one of the following values:
 84→  *     @arg NVIC_PriorityGroup_0: 0 bits for pre-emption priority
 85→  *                                4 bits for subpriority
 86→  *     @arg NVIC_PriorityGroup_1: 1 bits for pre-emption priority
 87→  *                                3 bits for subpriority
 88→  *     @arg NVIC_PriorityGroup_2: 2 bits for pre-emption priority
 89→  *                                2 bits for subpriority
 90→  *     @arg NVIC_PriorityGroup_3: 3 bits for pre-emption priority
 91→  *                                1 bits for subpriority
 92→  *     @arg NVIC_PriorityGroup_4: 4 bits for pre-emption priority
 93→  *                                0 bits for subpriority
 94→  * @retval None
 95→  */
 96→void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup)
 97→{
 98→  /* Check the parameters */
 99→  assert_param(IS_NVIC_PRIORITY_GROUP(NVIC_PriorityGroup));
100→  
101→  /* Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value */
102→  SCB->AIRCR = AIRCR_VECTKEY_MASK | NVIC_PriorityGroup;
103→}
104→
105→/**
106→  * @brief  Initializes the NVIC peripheral according to the specified
107→  *         parameters in the NVIC_InitStruct.
108→  * @param  NVIC_InitStruct: pointer to a NVIC_InitTypeDef structure that contains
109→  *         the configuration information for the specified NVIC peripheral.
110→  * @retval None
111→  */
112→void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct)
113→{
114→  uint32_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;
115→  
116→  /* Check the parameters */
117→  assert_param(IS_FUNCTIONAL_STATE(NVIC_InitStruct->NVIC_IRQChannelCmd));
118→  assert_param(IS_NVIC_PREEMPTION_PRIORITY(NVIC_InitStruct->NVIC_IRQChannelPreemptionPriority));  
119→  assert_param(IS_NVIC_SUB_PRIORITY(NVIC_InitStruct->NVIC_IRQChannelSubPriority));
120→    
121→  if (NVIC_InitStruct->NVIC_IRQChannelCmd != DISABLE)
122→  {
123→    /* Compute the Corresponding IRQ Priority --------------------------------*/    
124→    tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t)0x700))>> 0x08;
125→    tmppre = (0x4 - tmppriority);
126→    tmpsub = tmpsub >> tmppriority;
127→
128→    tmppriority = (uint32_t)NVIC_InitStruct->NVIC_IRQChannelPreemptionPriority << tmppre;
129→    tmppriority |=  NVIC_InitStruct->NVIC_IRQChannelSubPriority & tmpsub;
130→    tmppriority = tmppriority << 0x04;
131→        
132→    NVIC->IP[NVIC_InitStruct->NVIC_IRQChannel] = tmppriority;
133→    
134→    /* Enable the Selected IRQ Channels --------------------------------------*/
135→    NVIC->ISER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
136→      (uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
137→  }
138→  else
139→  {
140→    /* Disable the Selected IRQ Channels -------------------------------------*/
141→    NVIC->ICER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
142→      (uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
143→  }
144→}
145→
146→/**
147→  * @brief  Sets the vector table location and Offset.
148→  * @param  NVIC_VectTab: specifies if the vector table is in RAM or FLASH memory.
149→  *   This parameter can be one of the following values:
150→  *     @arg NVIC_VectTab_RAM
151→  *     @arg NVIC_VectTab_FLASH
152→  * @param  Offset: Vector Table base offset field. This value must be a multiple 
153→  *         of 0x200.
154→  * @retval None
155→  */
156→void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset)
157→{ 
158→  /* Check the parameters */
159→  assert_param(IS_NVIC_VECTTAB(NVIC_VectTab));
160→  assert_param(IS_NVIC_OFFSET(Offset));  
161→   
162→  SCB->VTOR = NVIC_VectTab | (Offset & (uint32_t)0x1FFFFF80);
163→}
164→
165→/**
166→  * @brief  Selects the condition for the system to enter low power mode.
167→  * @param  LowPowerMode: Specifies the new mode for the system to enter low power mode.
168→  *   This parameter can be one of the following values:
169→  *     @arg NVIC_LP_SEVONPEND
170→  *     @arg NVIC_LP_SLEEPDEEP
171→  *     @arg NVIC_LP_SLEEPONEXIT
172→  * @param  NewState: new state of LP condition. This parameter can be: ENABLE or DISABLE.
173→  * @retval None
174→  */
175→void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState)
176→{
177→  /* Check the parameters */
178→  assert_param(IS_NVIC_LP(LowPowerMode));
179→  assert_param(IS_FUNCTIONAL_STATE(NewState));  
180→  
181→  if (NewState != DISABLE)
182→  {
183→    SCB->SCR |= LowPowerMode;
184→  }
185→  else
186→  {
187→    SCB->SCR &= (uint32_t)(~(uint32_t)LowPowerMode);
188→  }
189→}
190→
191→/**
192→  * @brief  Configures the SysTick clock source.
193→  * @param  SysTick_CLKSource: specifies the SysTick clock source.
194→  *   This parameter can be one of the following values:
195→  *     @arg SysTick_CLKSource_HCLK_Div8: AHB clock divided by 8 selected as SysTick clock source.
196→  *     @arg SysTick_CLKSource_HCLK: AHB clock selected as SysTick clock source.
197→  * @retval None
198→  */
199→void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource)
200→{
201→  /* Check the parameters */
202→  assert_param(IS_SYSTICK_CLK_SOURCE(SysTick_CLKSource));
203→  if (SysTick_CLKSource == SysTick_CLKSource_HCLK)
204→  {
205→    SysTick->CTRL |= SysTick_CLKSource_HCLK;
206→  }
207→  else
208→  {
209→    SysTick->CTRL &= SysTick_CLKSource_HCLK_Div8;
210→  }
211→}
212→
213→/**
214→  * @}
215→  */
216→
217→/**
218→  * @}
219→  */
220→
221→/**
222→  * @}
223→  */
224→
225→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/