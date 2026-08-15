  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_rtc.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the RTC firmware functions.
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
 23→#include "stm32f10x_rtc.h"
 24→
 25→/** @addtogroup STM32F10x_StdPeriph_Driver
 26→  * @{
 27→  */
 28→
 29→/** @defgroup RTC 
 30→  * @brief RTC driver modules
 31→  * @{
 32→  */
 33→
 34→/** @defgroup RTC_Private_TypesDefinitions
 35→  * @{
 36→  */ 
 37→/**
 38→  * @}
 39→  */
 40→
 41→/** @defgroup RTC_Private_Defines
 42→  * @{
 43→  */
 44→#define RTC_LSB_MASK     ((uint32_t)0x0000FFFF)  /*!< RTC LSB Mask */
 45→#define PRLH_MSB_MASK    ((uint32_t)0x000F0000)  /*!< RTC Prescaler MSB Mask */
 46→
 47→/**
 48→  * @}
 49→  */
 50→
 51→/** @defgroup RTC_Private_Macros
 52→  * @{
 53→  */
 54→
 55→/**
 56→  * @}
 57→  */
 58→
 59→/** @defgroup RTC_Private_Variables
 60→  * @{
 61→  */
 62→
 63→/**
 64→  * @}
 65→  */
 66→
 67→/** @defgroup RTC_Private_FunctionPrototypes
 68→  * @{
 69→  */
 70→
 71→/**
 72→  * @}
 73→  */
 74→
 75→/** @defgroup RTC_Private_Functions
 76→  * @{
 77→  */
 78→
 79→/**
 80→  * @brief  Enables or disables the specified RTC interrupts.
 81→  * @param  RTC_IT: specifies the RTC interrupts sources to be enabled or disabled.
 82→  *   This parameter can be any combination of the following values:
 83→  *     @arg RTC_IT_OW: Overflow interrupt
 84→  *     @arg RTC_IT_ALR: Alarm interrupt
 85→  *     @arg RTC_IT_SEC: Second interrupt
 86→  * @param  NewState: new state of the specified RTC interrupts.
 87→  *   This parameter can be: ENABLE or DISABLE.
 88→  * @retval None
 89→  */
 90→void RTC_ITConfig(uint16_t RTC_IT, FunctionalState NewState)
 91→{
 92→  /* Check the parameters */
 93→  assert_param(IS_RTC_IT(RTC_IT));  
 94→  assert_param(IS_FUNCTIONAL_STATE(NewState));
 95→  
 96→  if (NewState != DISABLE)
 97→  {
 98→    RTC->CRH |= RTC_IT;
 99→  }
100→  else
101→  {
102→    RTC->CRH &= (uint16_t)~RTC_IT;
103→  }
104→}
105→
106→/**
107→  * @brief  Enters the RTC configuration mode.
108→  * @param  None
109→  * @retval None
110→  */
111→void RTC_EnterConfigMode(void)
112→{
113→  /* Set the CNF flag to enter in the Configuration Mode */
114→  RTC->CRL |= RTC_CRL_CNF;
115→}
116→
117→/**
118→  * @brief  Exits from the RTC configuration mode.
119→  * @param  None
120→  * @retval None
121→  */
122→void RTC_ExitConfigMode(void)
123→{
124→  /* Reset the CNF flag to exit from the Configuration Mode */
125→  RTC->CRL &= (uint16_t)~((uint16_t)RTC_CRL_CNF); 
126→}
127→
128→/**
129→  * @brief  Gets the RTC counter value.
130→  * @param  None
131→  * @retval RTC counter value.
132→  */
133→uint32_t RTC_GetCounter(void)
134→{
135→  uint16_t tmp = 0;
136→  tmp = RTC->CNTL;
137→  return (((uint32_t)RTC->CNTH << 16 ) | tmp) ;
138→}
139→
140→/**
141→  * @brief  Sets the RTC counter value.
142→  * @param  CounterValue: RTC counter new value.
143→  * @retval None
144→  */
145→void RTC_SetCounter(uint32_t CounterValue)
146→{ 
147→  RTC_EnterConfigMode();
148→  /* Set RTC COUNTER MSB word */
149→  RTC->CNTH = CounterValue >> 16;
150→  /* Set RTC COUNTER LSB word */
151→  RTC->CNTL = (CounterValue & RTC_LSB_MASK);
152→  RTC_ExitConfigMode();
153→}
154→
155→/**
156→  * @brief  Sets the RTC prescaler value.
157→  * @param  PrescalerValue: RTC prescaler new value.
158→  * @retval None
159→  */
160→void RTC_SetPrescaler(uint32_t PrescalerValue)
161→{
162→  /* Check the parameters */
163→  assert_param(IS_RTC_PRESCALER(PrescalerValue));
164→  
165→  RTC_EnterConfigMode();
166→  /* Set RTC PRESCALER MSB word */
167→  RTC->PRLH = (PrescalerValue & PRLH_MSB_MASK) >> 16;
168→  /* Set RTC PRESCALER LSB word */
169→  RTC->PRLL = (PrescalerValue & RTC_LSB_MASK);
170→  RTC_ExitConfigMode();
171→}
172→
173→/**
174→  * @brief  Sets the RTC alarm value.
175→  * @param  AlarmValue: RTC alarm new value.
176→  * @retval None
177→  */
178→void RTC_SetAlarm(uint32_t AlarmValue)
179→{  
180→  RTC_EnterConfigMode();
181→  /* Set the ALARM MSB word */
182→  RTC->ALRH = AlarmValue >> 16;
183→  /* Set the ALARM LSB word */
184→  RTC->ALRL = (AlarmValue & RTC_LSB_MASK);
185→  RTC_ExitConfigMode();
186→}
187→
188→/**
189→  * @brief  Gets the RTC divider value.
190→  * @param  None
191→  * @retval RTC Divider value.
192→  */
193→uint32_t RTC_GetDivider(void)
194→{
195→  uint32_t tmp = 0x00;
196→  tmp = ((uint32_t)RTC->DIVH & (uint32_t)0x000F) << 16;
197→  tmp |= RTC->DIVL;
198→  return tmp;
199→}
200→
201→/**
202→  * @brief  Waits until last write operation on RTC registers has finished.
203→  * @note   This function must be called before any write to RTC registers.
204→  * @param  None
205→  * @retval None
206→  */
207→void RTC_WaitForLastTask(void)
208→{
209→  /* Loop until RTOFF flag is set */
210→  while ((RTC->CRL & RTC_FLAG_RTOFF) == (uint16_t)RESET)
211→  {
212→  }
213→}
214→
215→/**
216→  * @brief  Waits until the RTC registers (RTC_CNT, RTC_ALR and RTC_PRL)
217→  *   are synchronized with RTC APB clock.
218→  * @note   This function must be called before any read operation after an APB reset
219→  *   or an APB clock stop.
220→  * @param  None
221→  * @retval None
222→  */
223→void RTC_WaitForSynchro(void)
224→{
225→  /* Clear RSF flag */
226→  RTC->CRL &= (uint16_t)~RTC_FLAG_RSF;
227→  /* Loop until RSF flag is set */
228→  while ((RTC->CRL & RTC_FLAG_RSF) == (uint16_t)RESET)
229→  {
230→  }
231→}
232→
233→/**
234→  * @brief  Checks whether the specified RTC flag is set or not.
235→  * @param  RTC_FLAG: specifies the flag to check.
236→  *   This parameter can be one the following values:
237→  *     @arg RTC_FLAG_RTOFF: RTC Operation OFF flag
238→  *     @arg RTC_FLAG_RSF: Registers Synchronized flag
239→  *     @arg RTC_FLAG_OW: Overflow flag
240→  *     @arg RTC_FLAG_ALR: Alarm flag
241→  *     @arg RTC_FLAG_SEC: Second flag
242→  * @retval The new state of RTC_FLAG (SET or RESET).
243→  */
244→FlagStatus RTC_GetFlagStatus(uint16_t RTC_FLAG)
245→{
246→  FlagStatus bitstatus = RESET;
247→  
248→  /* Check the parameters */
249→  assert_param(IS_RTC_GET_FLAG(RTC_FLAG)); 
250→  
251→  if ((RTC->CRL & RTC_FLAG) != (uint16_t)RESET)
252→  {
253→    bitstatus = SET;
254→  }
255→  else
256→  {
257→    bitstatus = RESET;
258→  }
259→  return bitstatus;
260→}
261→
262→/**
263→  * @brief  Clears the RTC's pending flags.
264→  * @param  RTC_FLAG: specifies the flag to clear.
265→  *   This parameter can be any combination of the following values:
266→  *     @arg RTC_FLAG_RSF: Registers Synchronized flag. This flag is cleared only after
267→  *                        an APB reset or an APB Clock stop.
268→  *     @arg RTC_FLAG_OW: Overflow flag
269→  *     @arg RTC_FLAG_ALR: Alarm flag
270→  *     @arg RTC_FLAG_SEC: Second flag
271→  * @retval None
272→  */
273→void RTC_ClearFlag(uint16_t RTC_FLAG)
274→{
275→  /* Check the parameters */
276→  assert_param(IS_RTC_CLEAR_FLAG(RTC_FLAG)); 
277→    
278→  /* Clear the corresponding RTC flag */
279→  RTC->CRL &= (uint16_t)~RTC_FLAG;
280→}
281→
282→/**
283→  * @brief  Checks whether the specified RTC interrupt has occurred or not.
284→  * @param  RTC_IT: specifies the RTC interrupts sources to check.
285→  *   This parameter can be one of the following values:
286→  *     @arg RTC_IT_OW: Overflow interrupt
287→  *     @arg RTC_IT_ALR: Alarm interrupt
288→  *     @arg RTC_IT_SEC: Second interrupt
289→  * @retval The new state of the RTC_IT (SET or RESET).
290→  */
291→ITStatus RTC_GetITStatus(uint16_t RTC_IT)
292→{
293→  ITStatus bitstatus = RESET;
294→  /* Check the parameters */
295→  assert_param(IS_RTC_GET_IT(RTC_IT)); 
296→  
297→  bitstatus = (ITStatus)(RTC->CRL & RTC_IT);
298→  if (((RTC->CRH & RTC_IT) != (uint16_t)RESET) && (bitstatus != (uint16_t)RESET))
299→  {
300→    bitstatus = SET;
301→  }
302→  else
303→  {
304→    bitstatus = RESET;
305→  }
306→  return bitstatus;
307→}
308→
309→/**
310→  * @brief  Clears the RTC's interrupt pending bits.
311→  * @param  RTC_IT: specifies the interrupt pending bit to clear.
312→  *   This parameter can be any combination of the following values:
313→  *     @arg RTC_IT_OW: Overflow interrupt
314→  *     @arg RTC_IT_ALR: Alarm interrupt
315→  *     @arg RTC_IT_SEC: Second interrupt
316→  * @retval None
317→  */
318→void RTC_ClearITPendingBit(uint16_t RTC_IT)
319→{
320→  /* Check the parameters */
321→  assert_param(IS_RTC_IT(RTC_IT));  
322→  
323→  /* Clear the corresponding RTC pending bit */
324→  RTC->CRL &= (uint16_t)~RTC_IT;
325→}
326→
327→/**
328→  * @}
329→  */
330→
331→/**
332→  * @}
333→  */
334→
335→/**
336→  * @}
337→  */
338→
339→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/