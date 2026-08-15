  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_exti.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the EXTI firmware functions.
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
 23→#include "stm32f10x_exti.h"
 24→
 25→/** @addtogroup STM32F10x_StdPeriph_Driver
 26→  * @{
 27→  */
 28→
 29→/** @defgroup EXTI 
 30→  * @brief EXTI driver modules
 31→  * @{
 32→  */
 33→
 34→/** @defgroup EXTI_Private_TypesDefinitions
 35→  * @{
 36→  */
 37→
 38→/**
 39→  * @}
 40→  */
 41→
 42→/** @defgroup EXTI_Private_Defines
 43→  * @{
 44→  */
 45→
 46→#define EXTI_LINENONE    ((uint32_t)0x00000)  /* No interrupt selected */
 47→
 48→/**
 49→  * @}
 50→  */
 51→
 52→/** @defgroup EXTI_Private_Macros
 53→  * @{
 54→  */
 55→
 56→/**
 57→  * @}
 58→  */
 59→
 60→/** @defgroup EXTI_Private_Variables
 61→  * @{
 62→  */
 63→
 64→/**
 65→  * @}
 66→  */
 67→
 68→/** @defgroup EXTI_Private_FunctionPrototypes
 69→  * @{
 70→  */
 71→
 72→/**
 73→  * @}
 74→  */
 75→
 76→/** @defgroup EXTI_Private_Functions
 77→  * @{
 78→  */
 79→
 80→/**
 81→  * @brief  Deinitializes the EXTI peripheral registers to their default reset values.
 82→  * @param  None
 83→  * @retval None
 84→  */
 85→void EXTI_DeInit(void)
 86→{
 87→  EXTI->IMR = 0x00000000;
 88→  EXTI->EMR = 0x00000000;
 89→  EXTI->RTSR = 0x00000000; 
 90→  EXTI->FTSR = 0x00000000; 
 91→  EXTI->PR = 0x000FFFFF;
 92→}
 93→
 94→/**
 95→  * @brief  Initializes the EXTI peripheral according to the specified
 96→  *         parameters in the EXTI_InitStruct.
 97→  * @param  EXTI_InitStruct: pointer to a EXTI_InitTypeDef structure
 98→  *         that contains the configuration information for the EXTI peripheral.
 99→  * @retval None
100→  */
101→void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct)
102→{
103→  uint32_t tmp = 0;
104→
105→  /* Check the parameters */
106→  assert_param(IS_EXTI_MODE(EXTI_InitStruct->EXTI_Mode));
107→  assert_param(IS_EXTI_TRIGGER(EXTI_InitStruct->EXTI_Trigger));
108→  assert_param(IS_EXTI_LINE(EXTI_InitStruct->EXTI_Line));  
109→  assert_param(IS_FUNCTIONAL_STATE(EXTI_InitStruct->EXTI_LineCmd));
110→
111→  tmp = (uint32_t)EXTI_BASE;
112→     
113→  if (EXTI_InitStruct->EXTI_LineCmd != DISABLE)
114→  {
115→    /* Clear EXTI line configuration */
116→    EXTI->IMR &= ~EXTI_InitStruct->EXTI_Line;
117→    EXTI->EMR &= ~EXTI_InitStruct->EXTI_Line;
118→    
119→    tmp += EXTI_InitStruct->EXTI_Mode;
120→
121→    *(__IO uint32_t *) tmp |= EXTI_InitStruct->EXTI_Line;
122→
123→    /* Clear Rising Falling edge configuration */
124→    EXTI->RTSR &= ~EXTI_InitStruct->EXTI_Line;
125→    EXTI->FTSR &= ~EXTI_InitStruct->EXTI_Line;
126→    
127→    /* Select the trigger for the selected external interrupts */
128→    if (EXTI_InitStruct->EXTI_Trigger == EXTI_Trigger_Rising_Falling)
129→    {
130→      /* Rising Falling edge */
131→      EXTI->RTSR |= EXTI_InitStruct->EXTI_Line;
132→      EXTI->FTSR |= EXTI_InitStruct->EXTI_Line;
133→    }
134→    else
135→    {
136→      tmp = (uint32_t)EXTI_BASE;
137→      tmp += EXTI_InitStruct->EXTI_Trigger;
138→
139→      *(__IO uint32_t *) tmp |= EXTI_InitStruct->EXTI_Line;
140→    }
141→  }
142→  else
143→  {
144→    tmp += EXTI_InitStruct->EXTI_Mode;
145→
146→    /* Disable the selected external lines */
147→    *(__IO uint32_t *) tmp &= ~EXTI_InitStruct->EXTI_Line;
148→  }
149→}
150→
151→/**
152→  * @brief  Fills each EXTI_InitStruct member with its reset value.
153→  * @param  EXTI_InitStruct: pointer to a EXTI_InitTypeDef structure which will
154→  *         be initialized.
155→  * @retval None
156→  */
157→void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct)
158→{
159→  EXTI_InitStruct->EXTI_Line = EXTI_LINENONE;
160→  EXTI_InitStruct->EXTI_Mode = EXTI_Mode_Interrupt;
161→  EXTI_InitStruct->EXTI_Trigger = EXTI_Trigger_Falling;
162→  EXTI_InitStruct->EXTI_LineCmd = DISABLE;
163→}
164→
165→/**
166→  * @brief  Generates a Software interrupt.
167→  * @param  EXTI_Line: specifies the EXTI lines to be enabled or disabled.
168→  *   This parameter can be any combination of EXTI_Linex where x can be (0..19).
169→  * @retval None
170→  */
171→void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line)
172→{
173→  /* Check the parameters */
174→  assert_param(IS_EXTI_LINE(EXTI_Line));
175→  
176→  EXTI->SWIER |= EXTI_Line;
177→}
178→
179→/**
180→  * @brief  Checks whether the specified EXTI line flag is set or not.
181→  * @param  EXTI_Line: specifies the EXTI line flag to check.
182→  *   This parameter can be:
183→  *     @arg EXTI_Linex: External interrupt line x where x(0..19)
184→  * @retval The new state of EXTI_Line (SET or RESET).
185→  */
186→FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line)
187→{
188→  FlagStatus bitstatus = RESET;
189→  /* Check the parameters */
190→  assert_param(IS_GET_EXTI_LINE(EXTI_Line));
191→  
192→  if ((EXTI->PR & EXTI_Line) != (uint32_t)RESET)
193→  {
194→    bitstatus = SET;
195→  }
196→  else
197→  {
198→    bitstatus = RESET;
199→  }
200→  return bitstatus;
201→}
202→
203→/**
204→  * @brief  Clears the EXTI's line pending flags.
205→  * @param  EXTI_Line: specifies the EXTI lines flags to clear.
206→  *   This parameter can be any combination of EXTI_Linex where x can be (0..19).
207→  * @retval None
208→  */
209→void EXTI_ClearFlag(uint32_t EXTI_Line)
210→{
211→  /* Check the parameters */
212→  assert_param(IS_EXTI_LINE(EXTI_Line));
213→  
214→  EXTI->PR = EXTI_Line;
215→}
216→
217→/**
218→  * @brief  Checks whether the specified EXTI line is asserted or not.
219→  * @param  EXTI_Line: specifies the EXTI line to check.
220→  *   This parameter can be:
221→  *     @arg EXTI_Linex: External interrupt line x where x(0..19)
222→  * @retval The new state of EXTI_Line (SET or RESET).
223→  */
224→ITStatus EXTI_GetITStatus(uint32_t EXTI_Line)
225→{
226→  ITStatus bitstatus = RESET;
227→  uint32_t enablestatus = 0;
228→  /* Check the parameters */
229→  assert_param(IS_GET_EXTI_LINE(EXTI_Line));
230→  
231→  enablestatus =  EXTI->IMR & EXTI_Line;
232→  if (((EXTI->PR & EXTI_Line) != (uint32_t)RESET) && (enablestatus != (uint32_t)RESET))
233→  {
234→    bitstatus = SET;
235→  }
236→  else
237→  {
238→    bitstatus = RESET;
239→  }
240→  return bitstatus;
241→}
242→
243→/**
244→  * @brief  Clears the EXTI's line pending bits.
245→  * @param  EXTI_Line: specifies the EXTI lines to clear.
246→  *   This parameter can be any combination of EXTI_Linex where x can be (0..19).
247→  * @retval None
248→  */
249→void EXTI_ClearITPendingBit(uint32_t EXTI_Line)
250→{
251→  /* Check the parameters */
252→  assert_param(IS_EXTI_LINE(EXTI_Line));
253→  
254→  EXTI->PR = EXTI_Line;
255→}
256→
257→/**
258→  * @}
259→  */
260→
261→/**
262→  * @}
263→  */
264→
265→/**
266→  * @}
267→  */
268→
269→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/