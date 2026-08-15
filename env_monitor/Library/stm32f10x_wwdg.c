  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_wwdg.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the WWDG firmware functions.
  8→  ******************************************************************************
  9→  * @attention
 10→  *
 11→  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 12→  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 13→  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 14→  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 15→  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 16→  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 17→  *
 18→  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 19→  ******************************************************************************
 20→  */
 21→
 22→/* Includes ------------------------------------------------------------------*/
 23→#include "stm32f10x_wwdg.h"
 24→#include "stm32f10x_rcc.h"
 25→
 26→/** @addtogroup STM32F10x_StdPeriph_Driver
 27→  * @{
 28→  */
 29→
 30→/** @defgroup WWDG 
 31→  * @brief WWDG driver modules
 32→  * @{
 33→  */
 34→
 35→/** @defgroup WWDG_Private_TypesDefinitions
 36→  * @{
 37→  */
 38→
 39→/**
 40→  * @}
 41→  */
 42→
 43→/** @defgroup WWDG_Private_Defines
 44→  * @{
 45→  */
 46→
 47→/* ----------- WWDG registers bit address in the alias region ----------- */
 48→#define WWDG_OFFSET       (WWDG_BASE - PERIPH_BASE)
 49→
 50→/* Alias word address of EWI bit */
 51→#define CFR_OFFSET        (WWDG_OFFSET + 0x04)
 52→#define EWI_BitNumber     0x09
 53→#define CFR_EWI_BB        (PERIPH_BB_BASE + (CFR_OFFSET * 32) + (EWI_BitNumber * 4))
 54→
 55→/* --------------------- WWDG registers bit mask ------------------------ */
 56→
 57→/* CR register bit mask */
 58→#define CR_WDGA_Set       ((uint32_t)0x00000080)
 59→
 60→/* CFR register bit mask */
 61→#define CFR_WDGTB_Mask    ((uint32_t)0xFFFFFE7F)
 62→#define CFR_W_Mask        ((uint32_t)0xFFFFFF80)
 63→#define BIT_Mask          ((uint8_t)0x7F)
 64→
 65→/**
 66→  * @}
 67→  */
 68→
 69→/** @defgroup WWDG_Private_Macros
 70→  * @{
 71→  */
 72→
 73→/**
 74→  * @}
 75→  */
 76→
 77→/** @defgroup WWDG_Private_Variables
 78→  * @{
 79→  */
 80→
 81→/**
 82→  * @}
 83→  */
 84→
 85→/** @defgroup WWDG_Private_FunctionPrototypes
 86→  * @{
 87→  */
 88→
 89→/**
 90→  * @}
 91→  */
 92→
 93→/** @defgroup WWDG_Private_Functions
 94→  * @{
 95→  */
 96→
 97→/**
 98→  * @brief  Deinitializes the WWDG peripheral registers to their default reset values.
 99→  * @param  None
100→  * @retval None
101→  */
102→void WWDG_DeInit(void)
103→{
104→  RCC_APB1PeriphResetCmd(RCC_APB1Periph_WWDG, ENABLE);
105→  RCC_APB1PeriphResetCmd(RCC_APB1Periph_WWDG, DISABLE);
106→}
107→
108→/**
109→  * @brief  Sets the WWDG Prescaler.
110→  * @param  WWDG_Prescaler: specifies the WWDG Prescaler.
111→  *   This parameter can be one of the following values:
112→  *     @arg WWDG_Prescaler_1: WWDG counter clock = (PCLK1/4096)/1
113→  *     @arg WWDG_Prescaler_2: WWDG counter clock = (PCLK1/4096)/2
114→  *     @arg WWDG_Prescaler_4: WWDG counter clock = (PCLK1/4096)/4
115→  *     @arg WWDG_Prescaler_8: WWDG counter clock = (PCLK1/4096)/8
116→  * @retval None
117→  */
118→void WWDG_SetPrescaler(uint32_t WWDG_Prescaler)
119→{
120→  uint32_t tmpreg = 0;
121→  /* Check the parameters */
122→  assert_param(IS_WWDG_PRESCALER(WWDG_Prescaler));
123→  /* Clear WDGTB[1:0] bits */
124→  tmpreg = WWDG->CFR & CFR_WDGTB_Mask;
125→  /* Set WDGTB[1:0] bits according to WWDG_Prescaler value */
126→  tmpreg |= WWDG_Prescaler;
127→  /* Store the new value */
128→  WWDG->CFR = tmpreg;
129→}
130→
131→/**
132→  * @brief  Sets the WWDG window value.
133→  * @param  WindowValue: specifies the window value to be compared to the downcounter.
134→  *   This parameter value must be lower than 0x80.
135→  * @retval None
136→  */
137→void WWDG_SetWindowValue(uint8_t WindowValue)
138→{
139→  __IO uint32_t tmpreg = 0;
140→
141→  /* Check the parameters */
142→  assert_param(IS_WWDG_WINDOW_VALUE(WindowValue));
143→  /* Clear W[6:0] bits */
144→
145→  tmpreg = WWDG->CFR & CFR_W_Mask;
146→
147→  /* Set W[6:0] bits according to WindowValue value */
148→  tmpreg |= WindowValue & (uint32_t) BIT_Mask;
149→
150→  /* Store the new value */
151→  WWDG->CFR = tmpreg;
152→}
153→
154→/**
155→  * @brief  Enables the WWDG Early Wakeup interrupt(EWI).
156→  * @param  None
157→  * @retval None
158→  */
159→void WWDG_EnableIT(void)
160→{
161→  *(__IO uint32_t *) CFR_EWI_BB = (uint32_t)ENABLE;
162→}
163→
164→/**
165→  * @brief  Sets the WWDG counter value.
166→  * @param  Counter: specifies the watchdog counter value.
167→  *   This parameter must be a number between 0x40 and 0x7F.
168→  * @retval None
169→  */
170→void WWDG_SetCounter(uint8_t Counter)
171→{
172→  /* Check the parameters */
173→  assert_param(IS_WWDG_COUNTER(Counter));
174→  /* Write to T[6:0] bits to configure the counter value, no need to do
175→     a read-modify-write; writing a 0 to WDGA bit does nothing */
176→  WWDG->CR = Counter & BIT_Mask;
177→}
178→
179→/**
180→  * @brief  Enables WWDG and load the counter value.                  
181→  * @param  Counter: specifies the watchdog counter value.
182→  *   This parameter must be a number between 0x40 and 0x7F.
183→  * @retval None
184→  */
185→void WWDG_Enable(uint8_t Counter)
186→{
187→  /* Check the parameters */
188→  assert_param(IS_WWDG_COUNTER(Counter));
189→  WWDG->CR = CR_WDGA_Set | Counter;
190→}
191→
192→/**
193→  * @brief  Checks whether the Early Wakeup interrupt flag is set or not.
194→  * @param  None
195→  * @retval The new state of the Early Wakeup interrupt flag (SET or RESET)
196→  */
197→FlagStatus WWDG_GetFlagStatus(void)
198→{
199→  return (FlagStatus)(WWDG->SR);
200→}
201→
202→/**
203→  * @brief  Clears Early Wakeup interrupt flag.
204→  * @param  None
205→  * @retval None
206→  */
207→void WWDG_ClearFlag(void)
208→{
209→  WWDG->SR = (uint32_t)RESET;
210→}
211→
212→/**
213→  * @}
214→  */
215→
216→/**
217→  * @}
218→  */
219→
220→/**
221→  * @}
222→  */
223→
224→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/