  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_dbgmcu.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the DBGMCU firmware functions.
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
 23→#include "stm32f10x_dbgmcu.h"
 24→
 25→/** @addtogroup STM32F10x_StdPeriph_Driver
 26→  * @{
 27→  */
 28→
 29→/** @defgroup DBGMCU 
 30→  * @brief DBGMCU driver modules
 31→  * @{
 32→  */ 
 33→
 34→/** @defgroup DBGMCU_Private_TypesDefinitions
 35→  * @{
 36→  */
 37→
 38→/**
 39→  * @}
 40→  */
 41→
 42→/** @defgroup DBGMCU_Private_Defines
 43→  * @{
 44→  */
 45→
 46→#define IDCODE_DEVID_MASK    ((uint32_t)0x00000FFF)
 47→/**
 48→  * @}
 49→  */
 50→
 51→/** @defgroup DBGMCU_Private_Macros
 52→  * @{
 53→  */
 54→
 55→/**
 56→  * @}
 57→  */
 58→
 59→/** @defgroup DBGMCU_Private_Variables
 60→  * @{
 61→  */
 62→
 63→/**
 64→  * @}
 65→  */
 66→
 67→/** @defgroup DBGMCU_Private_FunctionPrototypes
 68→  * @{
 69→  */
 70→
 71→/**
 72→  * @}
 73→  */
 74→
 75→/** @defgroup DBGMCU_Private_Functions
 76→  * @{
 77→  */
 78→
 79→/**
 80→  * @brief  Returns the device revision identifier.
 81→  * @param  None
 82→  * @retval Device revision identifier
 83→  */
 84→uint32_t DBGMCU_GetREVID(void)
 85→{
 86→   return(DBGMCU->IDCODE >> 16);
 87→}
 88→
 89→/**
 90→  * @brief  Returns the device identifier.
 91→  * @param  None
 92→  * @retval Device identifier
 93→  */
 94→uint32_t DBGMCU_GetDEVID(void)
 95→{
 96→   return(DBGMCU->IDCODE & IDCODE_DEVID_MASK);
 97→}
 98→
 99→/**
100→  * @brief  Configures the specified peripheral and low power mode behavior
101→  *   when the MCU under Debug mode.
102→  * @param  DBGMCU_Periph: specifies the peripheral and low power mode.
103→  *   This parameter can be any combination of the following values:
104→  *     @arg DBGMCU_SLEEP: Keep debugger connection during SLEEP mode              
105→  *     @arg DBGMCU_STOP: Keep debugger connection during STOP mode               
106→  *     @arg DBGMCU_STANDBY: Keep debugger connection during STANDBY mode            
107→  *     @arg DBGMCU_IWDG_STOP: Debug IWDG stopped when Core is halted          
108→  *     @arg DBGMCU_WWDG_STOP: Debug WWDG stopped when Core is halted          
109→  *     @arg DBGMCU_TIM1_STOP: TIM1 counter stopped when Core is halted          
110→  *     @arg DBGMCU_TIM2_STOP: TIM2 counter stopped when Core is halted          
111→  *     @arg DBGMCU_TIM3_STOP: TIM3 counter stopped when Core is halted          
112→  *     @arg DBGMCU_TIM4_STOP: TIM4 counter stopped when Core is halted          
113→  *     @arg DBGMCU_CAN1_STOP: Debug CAN2 stopped when Core is halted           
114→  *     @arg DBGMCU_I2C1_SMBUS_TIMEOUT: I2C1 SMBUS timeout mode stopped when Core is halted
115→  *     @arg DBGMCU_I2C2_SMBUS_TIMEOUT: I2C2 SMBUS timeout mode stopped when Core is halted
116→  *     @arg DBGMCU_TIM5_STOP: TIM5 counter stopped when Core is halted          
117→  *     @arg DBGMCU_TIM6_STOP: TIM6 counter stopped when Core is halted          
118→  *     @arg DBGMCU_TIM7_STOP: TIM7 counter stopped when Core is halted          
119→  *     @arg DBGMCU_TIM8_STOP: TIM8 counter stopped when Core is halted
120→  *     @arg DBGMCU_CAN2_STOP: Debug CAN2 stopped when Core is halted 
121→  *     @arg DBGMCU_TIM15_STOP: TIM15 counter stopped when Core is halted
122→  *     @arg DBGMCU_TIM16_STOP: TIM16 counter stopped when Core is halted
123→  *     @arg DBGMCU_TIM17_STOP: TIM17 counter stopped when Core is halted                
124→  *     @arg DBGMCU_TIM9_STOP: TIM9 counter stopped when Core is halted
125→  *     @arg DBGMCU_TIM10_STOP: TIM10 counter stopped when Core is halted
126→  *     @arg DBGMCU_TIM11_STOP: TIM11 counter stopped when Core is halted
127→  *     @arg DBGMCU_TIM12_STOP: TIM12 counter stopped when Core is halted
128→  *     @arg DBGMCU_TIM13_STOP: TIM13 counter stopped when Core is halted
129→  *     @arg DBGMCU_TIM14_STOP: TIM14 counter stopped when Core is halted
130→  * @param  NewState: new state of the specified peripheral in Debug mode.
131→  *   This parameter can be: ENABLE or DISABLE.
132→  * @retval None
133→  */
134→void DBGMCU_Config(uint32_t DBGMCU_Periph, FunctionalState NewState)
135→{
136→  /* Check the parameters */
137→  assert_param(IS_DBGMCU_PERIPH(DBGMCU_Periph));
138→  assert_param(IS_FUNCTIONAL_STATE(NewState));
139→
140→  if (NewState != DISABLE)
141→  {
142→    DBGMCU->CR |= DBGMCU_Periph;
143→  }
144→  else
145→  {
146→    DBGMCU->CR &= ~DBGMCU_Periph;
147→  }
148→}
149→
150→/**
151→  * @}
152→  */
153→
154→/**
155→  * @}
156→  */
157→
158→/**
159→  * @}
160→  */
161→
162→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/