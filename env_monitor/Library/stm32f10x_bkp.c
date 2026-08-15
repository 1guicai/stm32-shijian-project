  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_bkp.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the BKP firmware functions.
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
 23→#include "stm32f10x_bkp.h"
 24→#include "stm32f10x_rcc.h"
 25→
 26→/** @addtogroup STM32F10x_StdPeriph_Driver
 27→  * @{
 28→  */
 29→
 30→/** @defgroup BKP 
 31→  * @brief BKP driver modules
 32→  * @{
 33→  */
 34→
 35→/** @defgroup BKP_Private_TypesDefinitions
 36→  * @{
 37→  */
 38→
 39→/**
 40→  * @}
 41→  */
 42→
 43→/** @defgroup BKP_Private_Defines
 44→  * @{
 45→  */
 46→
 47→/* ------------ BKP registers bit address in the alias region --------------- */
 48→#define BKP_OFFSET        (BKP_BASE - PERIPH_BASE)
 49→
 50→/* --- CR Register ----*/
 51→
 52→/* Alias word address of TPAL bit */
 53→#define CR_OFFSET         (BKP_OFFSET + 0x30)
 54→#define TPAL_BitNumber    0x01
 55→#define CR_TPAL_BB        (PERIPH_BB_BASE + (CR_OFFSET * 32) + (TPAL_BitNumber * 4))
 56→
 57→/* Alias word address of TPE bit */
 58→#define TPE_BitNumber     0x00
 59→#define CR_TPE_BB         (PERIPH_BB_BASE + (CR_OFFSET * 32) + (TPE_BitNumber * 4))
 60→
 61→/* --- CSR Register ---*/
 62→
 63→/* Alias word address of TPIE bit */
 64→#define CSR_OFFSET        (BKP_OFFSET + 0x34)
 65→#define TPIE_BitNumber    0x02
 66→#define CSR_TPIE_BB       (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TPIE_BitNumber * 4))
 67→
 68→/* Alias word address of TIF bit */
 69→#define TIF_BitNumber     0x09
 70→#define CSR_TIF_BB        (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TIF_BitNumber * 4))
 71→
 72→/* Alias word address of TEF bit */
 73→#define TEF_BitNumber     0x08
 74→#define CSR_TEF_BB        (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TEF_BitNumber * 4))
 75→
 76→/* ---------------------- BKP registers bit mask ------------------------ */
 77→
 78→/* RTCCR register bit mask */
 79→#define RTCCR_CAL_MASK    ((uint16_t)0xFF80)
 80→#define RTCCR_MASK        ((uint16_t)0xFC7F)
 81→
 82→/**
 83→  * @}
 84→  */ 
 85→
 86→
 87→/** @defgroup BKP_Private_Macros
 88→  * @{
 89→  */
 90→
 91→/**
 92→  * @}
 93→  */
 94→
 95→/** @defgroup BKP_Private_Variables
 96→  * @{
 97→  */
 98→
 99→/**
100→  * @}
101→  */
102→
103→/** @defgroup BKP_Private_FunctionPrototypes
104→  * @{
105→  */
106→
107→/**
108→  * @}
109→  */
110→
111→/** @defgroup BKP_Private_Functions
112→  * @{
113→  */
114→
115→/**
116→  * @brief  Deinitializes the BKP peripheral registers to their default reset values.
117→  * @param  None
118→  * @retval None
119→  */
120→void BKP_DeInit(void)
121→{
122→  RCC_BackupResetCmd(ENABLE);
123→  RCC_BackupResetCmd(DISABLE);
124→}
125→
126→/**
127→  * @brief  Configures the Tamper Pin active level.
128→  * @param  BKP_TamperPinLevel: specifies the Tamper Pin active level.
129→  *   This parameter can be one of the following values:
130→  *     @arg BKP_TamperPinLevel_High: Tamper pin active on high level
131→  *     @arg BKP_TamperPinLevel_Low: Tamper pin active on low level
132→  * @retval None
133→  */
134→void BKP_TamperPinLevelConfig(uint16_t BKP_TamperPinLevel)
135→{
136→  /* Check the parameters */
137→  assert_param(IS_BKP_TAMPER_PIN_LEVEL(BKP_TamperPinLevel));
138→  *(__IO uint32_t *) CR_TPAL_BB = BKP_TamperPinLevel;
139→}
140→
141→/**
142→  * @brief  Enables or disables the Tamper Pin activation.
143→  * @param  NewState: new state of the Tamper Pin activation.
144→  *   This parameter can be: ENABLE or DISABLE.
145→  * @retval None
146→  */
147→void BKP_TamperPinCmd(FunctionalState NewState)
148→{
149→  /* Check the parameters */
150→  assert_param(IS_FUNCTIONAL_STATE(NewState));
151→  *(__IO uint32_t *) CR_TPE_BB = (uint32_t)NewState;
152→}
153→
154→/**
155→  * @brief  Enables or disables the Tamper Pin Interrupt.
156→  * @param  NewState: new state of the Tamper Pin Interrupt.
157→  *   This parameter can be: ENABLE or DISABLE.
158→  * @retval None
159→  */
160→void BKP_ITConfig(FunctionalState NewState)
161→{
162→  /* Check the parameters */
163→  assert_param(IS_FUNCTIONAL_STATE(NewState));
164→  *(__IO uint32_t *) CSR_TPIE_BB = (uint32_t)NewState;
165→}
166→
167→/**
168→  * @brief  Select the RTC output source to output on the Tamper pin.
169→  * @param  BKP_RTCOutputSource: specifies the RTC output source.
170→  *   This parameter can be one of the following values:
171→  *     @arg BKP_RTCOutputSource_None: no RTC output on the Tamper pin.
172→  *     @arg BKP_RTCOutputSource_CalibClock: output the RTC clock with frequency
173→  *                                          divided by 64 on the Tamper pin.
174→  *     @arg BKP_RTCOutputSource_Alarm: output the RTC Alarm pulse signal on
175→  *                                     the Tamper pin.
176→  *     @arg BKP_RTCOutputSource_Second: output the RTC Second pulse signal on
177→  *                                      the Tamper pin.  
178→  * @retval None
179→  */
180→void BKP_RTCOutputConfig(uint16_t BKP_RTCOutputSource)
181→{
182→  uint16_t tmpreg = 0;
183→  /* Check the parameters */
184→  assert_param(IS_BKP_RTC_OUTPUT_SOURCE(BKP_RTCOutputSource));
185→  tmpreg = BKP->RTCCR;
186→  /* Clear CCO, ASOE and ASOS bits */
187→  tmpreg &= RTCCR_MASK;
188→  
189→  /* Set CCO, ASOE and ASOS bits according to BKP_RTCOutputSource value */
190→  tmpreg |= BKP_RTCOutputSource;
191→  /* Store the new value */
192→  BKP->RTCCR = tmpreg;
193→}
194→
195→/**
196→  * @brief  Sets RTC Clock Calibration value.
197→  * @param  CalibrationValue: specifies the RTC Clock Calibration value.
198→  *   This parameter must be a number between 0 and 0x7F.
199→  * @retval None
200→  */
201→void BKP_SetRTCCalibrationValue(uint8_t CalibrationValue)
202→{
203→  uint16_t tmpreg = 0;
204→  /* Check the parameters */
205→  assert_param(IS_BKP_CALIBRATION_VALUE(CalibrationValue));
206→  tmpreg = BKP->RTCCR;
207→  /* Clear CAL[6:0] bits */
208→  tmpreg &= RTCCR_CAL_MASK;
209→  /* Set CAL[6:0] bits according to CalibrationValue value */
210→  tmpreg |= CalibrationValue;
211→  /* Store the new value */
212→  BKP->RTCCR = tmpreg;
213→}
214→
215→/**
216→  * @brief  Writes user data to the specified Data Backup Register.
217→  * @param  BKP_DR: specifies the Data Backup Register.
218→  *   This parameter can be BKP_DRx where x:[1, 42]
219→  * @param  Data: data to write
220→  * @retval None
221→  */
222→void BKP_WriteBackupRegister(uint16_t BKP_DR, uint16_t Data)
223→{
224→  __IO uint32_t tmp = 0;
225→
226→  /* Check the parameters */
227→  assert_param(IS_BKP_DR(BKP_DR));
228→
229→  tmp = (uint32_t)BKP_BASE; 
230→  tmp += BKP_DR;
231→
232→  *(__IO uint32_t *) tmp = Data;
233→}
234→
235→/**
236→  * @brief  Reads data from the specified Data Backup Register.
237→  * @param  BKP_DR: specifies the Data Backup Register.
238→  *   This parameter can be BKP_DRx where x:[1, 42]
239→  * @retval The content of the specified Data Backup Register
240→  */
241→uint16_t BKP_ReadBackupRegister(uint16_t BKP_DR)
242→{
243→  __IO uint32_t tmp = 0;
244→
245→  /* Check the parameters */
246→  assert_param(IS_BKP_DR(BKP_DR));
247→
248→  tmp = (uint32_t)BKP_BASE; 
249→  tmp += BKP_DR;
250→
251→  return (*(__IO uint16_t *) tmp);
252→}
253→
254→/**
255→  * @brief  Checks whether the Tamper Pin Event flag is set or not.
256→  * @param  None
257→  * @retval The new state of the Tamper Pin Event flag (SET or RESET).
258→  */
259→FlagStatus BKP_GetFlagStatus(void)
260→{
261→  return (FlagStatus)(*(__IO uint32_t *) CSR_TEF_BB);
262→}
263→
264→/**
265→  * @brief  Clears Tamper Pin Event pending flag.
266→  * @param  None
267→  * @retval None
268→  */
269→void BKP_ClearFlag(void)
270→{
271→  /* Set CTE bit to clear Tamper Pin Event flag */
272→  BKP->CSR |= BKP_CSR_CTE;
273→}
274→
275→/**
276→  * @brief  Checks whether the Tamper Pin Interrupt has occurred or not.
277→  * @param  None
278→  * @retval The new state of the Tamper Pin Interrupt (SET or RESET).
279→  */
280→ITStatus BKP_GetITStatus(void)
281→{
282→  return (ITStatus)(*(__IO uint32_t *) CSR_TIF_BB);
283→}
284→
285→/**
286→  * @brief  Clears Tamper Pin Interrupt pending bit.
287→  * @param  None
288→  * @retval None
289→  */
290→void BKP_ClearITPendingBit(void)
291→{
292→  /* Set CTI bit to clear Tamper Pin Interrupt pending bit */
293→  BKP->CSR |= BKP_CSR_CTI;
294→}
295→
296→/**
297→  * @}
298→  */
299→
300→/**
301→  * @}
302→  */
303→
304→/**
305→  * @}
306→  */
307→
308→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/