  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_pwr.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the PWR firmware functions.
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
 23→#include "stm32f10x_pwr.h"
 24→#include "stm32f10x_rcc.h"
 25→
 26→/** @addtogroup STM32F10x_StdPeriph_Driver
 27→  * @{
 28→  */
 29→
 30→/** @defgroup PWR 
 31→  * @brief PWR driver modules
 32→  * @{
 33→  */ 
 34→
 35→/** @defgroup PWR_Private_TypesDefinitions
 36→  * @{
 37→  */
 38→
 39→/**
 40→  * @}
 41→  */
 42→
 43→/** @defgroup PWR_Private_Defines
 44→  * @{
 45→  */
 46→
 47→/* --------- PWR registers bit address in the alias region ---------- */
 48→#define PWR_OFFSET               (PWR_BASE - PERIPH_BASE)
 49→
 50→/* --- CR Register ---*/
 51→
 52→/* Alias word address of DBP bit */
 53→#define CR_OFFSET                (PWR_OFFSET + 0x00)
 54→#define DBP_BitNumber            0x08
 55→#define CR_DBP_BB                (PERIPH_BB_BASE + (CR_OFFSET * 32) + (DBP_BitNumber * 4))
 56→
 57→/* Alias word address of PVDE bit */
 58→#define PVDE_BitNumber           0x04
 59→#define CR_PVDE_BB               (PERIPH_BB_BASE + (CR_OFFSET * 32) + (PVDE_BitNumber * 4))
 60→
 61→/* --- CSR Register ---*/
 62→
 63→/* Alias word address of EWUP bit */
 64→#define CSR_OFFSET               (PWR_OFFSET + 0x04)
 65→#define EWUP_BitNumber           0x08
 66→#define CSR_EWUP_BB              (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (EWUP_BitNumber * 4))
 67→
 68→/* ------------------ PWR registers bit mask ------------------------ */
 69→
 70→/* CR register bit mask */
 71→#define CR_DS_MASK               ((uint32_t)0xFFFFFFFC)
 72→#define CR_PLS_MASK              ((uint32_t)0xFFFFFF1F)
 73→
 74→
 75→/**
 76→  * @}
 77→  */
 78→
 79→/** @defgroup PWR_Private_Macros
 80→  * @{
 81→  */
 82→
 83→/**
 84→  * @}
 85→  */
 86→
 87→/** @defgroup PWR_Private_Variables
 88→  * @{
 89→  */
 90→
 91→/**
 92→  * @}
 93→  */
 94→
 95→/** @defgroup PWR_Private_FunctionPrototypes
 96→  * @{
 97→  */
 98→
 99→/**
100→  * @}
101→  */
102→
103→/** @defgroup PWR_Private_Functions
104→  * @{
105→  */
106→
107→/**
108→  * @brief  Deinitializes the PWR peripheral registers to their default reset values.
109→  * @param  None
110→  * @retval None
111→  */
112→void PWR_DeInit(void)
113→{
114→  RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, ENABLE);
115→  RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, DISABLE);
116→}
117→
118→/**
119→  * @brief  Enables or disables access to the RTC and backup registers.
120→  * @param  NewState: new state of the access to the RTC and backup registers.
121→  *   This parameter can be: ENABLE or DISABLE.
122→  * @retval None
123→  */
124→void PWR_BackupAccessCmd(FunctionalState NewState)
125→{
126→  /* Check the parameters */
127→  assert_param(IS_FUNCTIONAL_STATE(NewState));
128→  *(__IO uint32_t *) CR_DBP_BB = (uint32_t)NewState;
129→}
130→
131→/**
132→  * @brief  Enables or disables the Power Voltage Detector(PVD).
133→  * @param  NewState: new state of the PVD.
134→  *   This parameter can be: ENABLE or DISABLE.
135→  * @retval None
136→  */
137→void PWR_PVDCmd(FunctionalState NewState)
138→{
139→  /* Check the parameters */
140→  assert_param(IS_FUNCTIONAL_STATE(NewState));
141→  *(__IO uint32_t *) CR_PVDE_BB = (uint32_t)NewState;
142→}
143→
144→/**
145→  * @brief  Configures the voltage threshold detected by the Power Voltage Detector(PVD).
146→  * @param  PWR_PVDLevel: specifies the PVD detection level
147→  *   This parameter can be one of the following values:
148→  *     @arg PWR_PVDLevel_2V2: PVD detection level set to 2.2V
149→  *     @arg PWR_PVDLevel_2V3: PVD detection level set to 2.3V
150→  *     @arg PWR_PVDLevel_2V4: PVD detection level set to 2.4V
151→  *     @arg PWR_PVDLevel_2V5: PVD detection level set to 2.5V
152→  *     @arg PWR_PVDLevel_2V6: PVD detection level set to 2.6V
153→  *     @arg PWR_PVDLevel_2V7: PVD detection level set to 2.7V
154→  *     @arg PWR_PVDLevel_2V8: PVD detection level set to 2.8V
155→  *     @arg PWR_PVDLevel_2V9: PVD detection level set to 2.9V
156→  * @retval None
157→  */
158→void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel)
159→{
160→  uint32_t tmpreg = 0;
161→  /* Check the parameters */
162→  assert_param(IS_PWR_PVD_LEVEL(PWR_PVDLevel));
163→  tmpreg = PWR->CR;
164→  /* Clear PLS[7:5] bits */
165→  tmpreg &= CR_PLS_MASK;
166→  /* Set PLS[7:5] bits according to PWR_PVDLevel value */
167→  tmpreg |= PWR_PVDLevel;
168→  /* Store the new value */
169→  PWR->CR = tmpreg;
170→}
171→
172→/**
173→  * @brief  Enables or disables the WakeUp Pin functionality.
174→  * @param  NewState: new state of the WakeUp Pin functionality.
175→  *   This parameter can be: ENABLE or DISABLE.
176→  * @retval None
177→  */
178→void PWR_WakeUpPinCmd(FunctionalState NewState)
179→{
180→  /* Check the parameters */
181→  assert_param(IS_FUNCTIONAL_STATE(NewState));
182→  *(__IO uint32_t *) CSR_EWUP_BB = (uint32_t)NewState;
183→}
184→
185→/**
186→  * @brief  Enters STOP mode.
187→  * @param  PWR_Regulator: specifies the regulator state in STOP mode.
188→  *   This parameter can be one of the following values:
189→  *     @arg PWR_Regulator_ON: STOP mode with regulator ON
190→  *     @arg PWR_Regulator_LowPower: STOP mode with regulator in low power mode
191→  * @param  PWR_STOPEntry: specifies if STOP mode in entered with WFI or WFE instruction.
192→  *   This parameter can be one of the following values:
193→  *     @arg PWR_STOPEntry_WFI: enter STOP mode with WFI instruction
194→  *     @arg PWR_STOPEntry_WFE: enter STOP mode with WFE instruction
195→  * @retval None
196→  */
197→void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry)
198→{
199→  uint32_t tmpreg = 0;
200→  /* Check the parameters */
201→  assert_param(IS_PWR_REGULATOR(PWR_Regulator));
202→  assert_param(IS_PWR_STOP_ENTRY(PWR_STOPEntry));
203→  
204→  /* Select the regulator state in STOP mode ---------------------------------*/
205→  tmpreg = PWR->CR;
206→  /* Clear PDDS and LPDS bits */
207→  tmpreg &= CR_DS_MASK;
208→  /* Set LPDS bit according to PWR_Regulator value */
209→  tmpreg |= PWR_Regulator;
210→  /* Store the new value */
211→  PWR->CR = tmpreg;
212→  /* Set SLEEPDEEP bit of Cortex System Control Register */
213→  SCB->SCR |= SCB_SCR_SLEEPDEEP;
214→  
215→  /* Select STOP mode entry --------------------------------------------------*/
216→  if(PWR_STOPEntry == PWR_STOPEntry_WFI)
217→  {   
218→    /* Request Wait For Interrupt */
219→    __WFI();
220→  }
221→  else
222→  {
223→    /* Request Wait For Event */
224→    __WFE();
225→  }
226→  
227→  /* Reset SLEEPDEEP bit of Cortex System Control Register */
228→  SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP);  
229→}
230→
231→/**
232→  * @brief  Enters STANDBY mode.
233→  * @param  None
234→  * @retval None
235→  */
236→void PWR_EnterSTANDBYMode(void)
237→{
238→  /* Clear Wake-up flag */
239→  PWR->CR |= PWR_CR_CWUF;
240→  /* Select STANDBY mode */
241→  PWR->CR |= PWR_CR_PDDS;
242→  /* Set SLEEPDEEP bit of Cortex System Control Register */
243→  SCB->SCR |= SCB_SCR_SLEEPDEEP;
244→/* This option is used to ensure that store operations are completed */
245→#if defined ( __CC_ARM   )
246→  __force_stores();
247→#endif
248→  /* Request Wait For Interrupt */
249→  __WFI();
250→}
251→
252→/**
253→  * @brief  Checks whether the specified PWR flag is set or not.
254→  * @param  PWR_FLAG: specifies the flag to check.
255→  *   This parameter can be one of the following values:
256→  *     @arg PWR_FLAG_WU: Wake Up flag
257→  *     @arg PWR_FLAG_SB: StandBy flag
258→  *     @arg PWR_FLAG_PVDO: PVD Output
259→  * @retval The new state of PWR_FLAG (SET or RESET).
260→  */
261→FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG)
262→{
263→  FlagStatus bitstatus = RESET;
264→  /* Check the parameters */
265→  assert_param(IS_PWR_GET_FLAG(PWR_FLAG));
266→  
267→  if ((PWR->CSR & PWR_FLAG) != (uint32_t)RESET)
268→  {
269→    bitstatus = SET;
270→  }
271→  else
272→  {
273→    bitstatus = RESET;
274→  }
275→  /* Return the flag status */
276→  return bitstatus;
277→}
278→
279→/**
280→  * @brief  Clears the PWR's pending flags.
281→  * @param  PWR_FLAG: specifies the flag to clear.
282→  *   This parameter can be one of the following values:
283→  *     @arg PWR_FLAG_WU: Wake Up flag
284→  *     @arg PWR_FLAG_SB: StandBy flag
285→  * @retval None
286→  */
287→void PWR_ClearFlag(uint32_t PWR_FLAG)
288→{
289→  /* Check the parameters */
290→  assert_param(IS_PWR_CLEAR_FLAG(PWR_FLAG));
291→         
292→  PWR->CR |=  PWR_FLAG << 2;
293→}
294→
295→/**
296→  * @}
297→  */
298→
299→/**
300→  * @}
301→  */
302→
303→/**
304→  * @}
305→  */
306→
307→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/