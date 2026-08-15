  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_iwdg.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the IWDG firmware functions.
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
 23→#include "stm32f10x_iwdg.h"
 24→
 25→/** @addtogroup STM32F10x_StdPeriph_Driver
 26→  * @{
 27→  */
 28→
 29→/** @defgroup IWDG 
 30→  * @brief IWDG driver modules
 31→  * @{
 32→  */ 
 33→
 34→/** @defgroup IWDG_Private_TypesDefinitions
 35→  * @{
 36→  */
 37→
 38→/**
 39→  * @}
 40→  */
 41→
 42→/** @defgroup IWDG_Private_Defines
 43→  * @{
 44→  */ 
 45→
 46→/* ---------------------- IWDG registers bit mask ----------------------------*/
 47→
 48→/* KR register bit mask */
 49→#define KR_KEY_Reload    ((uint16_t)0xAAAA)
 50→#define KR_KEY_Enable    ((uint16_t)0xCCCC)
 51→
 52→/**
 53→  * @}
 54→  */ 
 55→
 56→/** @defgroup IWDG_Private_Macros
 57→  * @{
 58→  */
 59→
 60→/**
 61→  * @}
 62→  */
 63→
 64→/** @defgroup IWDG_Private_Variables
 65→  * @{
 66→  */
 67→
 68→/**
 69→  * @}
 70→  */
 71→
 72→/** @defgroup IWDG_Private_FunctionPrototypes
 73→  * @{
 74→  */
 75→
 76→/**
 77→  * @}
 78→  */
 79→
 80→/** @defgroup IWDG_Private_Functions
 81→  * @{
 82→  */
 83→
 84→/**
 85→  * @brief  Enables or disables write access to IWDG_PR and IWDG_RLR registers.
 86→  * @param  IWDG_WriteAccess: new state of write access to IWDG_PR and IWDG_RLR registers.
 87→  *   This parameter can be one of the following values:
 88→  *     @arg IWDG_WriteAccess_Enable: Enable write access to IWDG_PR and IWDG_RLR registers
 89→  *     @arg IWDG_WriteAccess_Disable: Disable write access to IWDG_PR and IWDG_RLR registers
 90→  * @retval None
 91→  */
 92→void IWDG_WriteAccessCmd(uint16_t IWDG_WriteAccess)
 93→{
 94→  /* Check the parameters */
 95→  assert_param(IS_IWDG_WRITE_ACCESS(IWDG_WriteAccess));
 96→  IWDG->KR = IWDG_WriteAccess;
 97→}
 98→
 99→/**
100→  * @brief  Sets IWDG Prescaler value.
101→  * @param  IWDG_Prescaler: specifies the IWDG Prescaler value.
102→  *   This parameter can be one of the following values:
103→  *     @arg IWDG_Prescaler_4: IWDG prescaler set to 4
104→  *     @arg IWDG_Prescaler_8: IWDG prescaler set to 8
105→  *     @arg IWDG_Prescaler_16: IWDG prescaler set to 16
106→  *     @arg IWDG_Prescaler_32: IWDG prescaler set to 32
107→  *     @arg IWDG_Prescaler_64: IWDG prescaler set to 64
108→  *     @arg IWDG_Prescaler_128: IWDG prescaler set to 128
109→  *     @arg IWDG_Prescaler_256: IWDG prescaler set to 256
110→  * @retval None
111→  */
112→void IWDG_SetPrescaler(uint8_t IWDG_Prescaler)
113→{
114→  /* Check the parameters */
115→  assert_param(IS_IWDG_PRESCALER(IWDG_Prescaler));
116→  IWDG->PR = IWDG_Prescaler;
117→}
118→
119→/**
120→  * @brief  Sets IWDG Reload value.
121→  * @param  Reload: specifies the IWDG Reload value.
122→  *   This parameter must be a number between 0 and 0x0FFF.
123→  * @retval None
124→  */
125→void IWDG_SetReload(uint16_t Reload)
126→{
127→  /* Check the parameters */
128→  assert_param(IS_IWDG_RELOAD(Reload));
129→  IWDG->RLR = Reload;
130→}
131→
132→/**
133→  * @brief  Reloads IWDG counter with value defined in the reload register
134→  *   (write access to IWDG_PR and IWDG_RLR registers disabled).
135→  * @param  None
136→  * @retval None
137→  */
138→void IWDG_ReloadCounter(void)
139→{
140→  IWDG->KR = KR_KEY_Reload;
141→}
142→
143→/**
144→  * @brief  Enables IWDG (write access to IWDG_PR and IWDG_RLR registers disabled).
145→  * @param  None
146→  * @retval None
147→  */
148→void IWDG_Enable(void)
149→{
150→  IWDG->KR = KR_KEY_Enable;
151→}
152→
153→/**
154→  * @brief  Checks whether the specified IWDG flag is set or not.
155→  * @param  IWDG_FLAG: specifies the flag to check.
156→  *   This parameter can be one of the following values:
157→  *     @arg IWDG_FLAG_PVU: Prescaler Value Update on going
158→  *     @arg IWDG_FLAG_RVU: Reload Value Update on going
159→  * @retval The new state of IWDG_FLAG (SET or RESET).
160→  */
161→FlagStatus IWDG_GetFlagStatus(uint16_t IWDG_FLAG)
162→{
163→  FlagStatus bitstatus = RESET;
164→  /* Check the parameters */
165→  assert_param(IS_IWDG_FLAG(IWDG_FLAG));
166→  if ((IWDG->SR & IWDG_FLAG) != (uint32_t)RESET)
167→  {
168→    bitstatus = SET;
169→  }
170→  else
171→  {
172→    bitstatus = RESET;
173→  }
174→  /* Return the flag status */
175→  return bitstatus;
176→}
177→
178→/**
179→  * @}
180→  */
181→
182→/**
183→  * @}
184→  */
185→
186→/**
187→  * @}
188→  */
189→
190→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/