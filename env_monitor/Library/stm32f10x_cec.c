  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_cec.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the CEC firmware functions.
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
 23→#include "stm32f10x_cec.h"
 24→#include "stm32f10x_rcc.h"
 25→
 26→/** @addtogroup STM32F10x_StdPeriph_Driver
 27→  * @{
 28→  */
 29→
 30→/** @defgroup CEC 
 31→  * @brief CEC driver modules
 32→  * @{
 33→  */
 34→
 35→/** @defgroup CEC_Private_TypesDefinitions
 36→  * @{
 37→  */
 38→
 39→/**
 40→  * @}
 41→  */
 42→
 43→
 44→/** @defgroup CEC_Private_Defines
 45→  * @{
 46→  */ 
 47→
 48→/* ------------ CEC registers bit address in the alias region ----------- */
 49→#define CEC_OFFSET                (CEC_BASE - PERIPH_BASE)
 50→
 51→/* --- CFGR Register ---*/
 52→
 53→/* Alias word address of PE bit */
 54→#define CFGR_OFFSET                 (CEC_OFFSET + 0x00)
 55→#define PE_BitNumber                0x00
 56→#define CFGR_PE_BB                  (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (PE_BitNumber * 4))
 57→
 58→/* Alias word address of IE bit */
 59→#define IE_BitNumber                0x01
 60→#define CFGR_IE_BB                  (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (IE_BitNumber * 4))
 61→
 62→/* --- CSR Register ---*/
 63→
 64→/* Alias word address of TSOM bit */
 65→#define CSR_OFFSET                  (CEC_OFFSET + 0x10)
 66→#define TSOM_BitNumber              0x00
 67→#define CSR_TSOM_BB                 (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TSOM_BitNumber * 4))
 68→
 69→/* Alias word address of TEOM bit */
 70→#define TEOM_BitNumber              0x01
 71→#define CSR_TEOM_BB                 (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TEOM_BitNumber * 4))
 72→  
 73→#define CFGR_CLEAR_Mask            (uint8_t)(0xF3)        /* CFGR register Mask */
 74→#define FLAG_Mask                  ((uint32_t)0x00FFFFFF) /* CEC FLAG mask */
 75→ 
 76→/**
 77→  * @}
 78→  */ 
 79→
 80→
 81→/** @defgroup CEC_Private_Macros
 82→  * @{
 83→  */ 
 84→
 85→/**
 86→  * @}
 87→  */ 
 88→
 89→
 90→/** @defgroup CEC_Private_Variables
 91→  * @{
 92→  */ 
 93→
 94→/**
 95→  * @}
 96→  */ 
 97→
 98→
 99→/** @defgroup CEC_Private_FunctionPrototypes
100→  * @{
101→  */
102→ 
103→/**
104→  * @}
105→  */ 
106→
107→
108→/** @defgroup CEC_Private_Functions
109→  * @{
110→  */ 
111→
112→/**
113→  * @brief  Deinitializes the CEC peripheral registers to their default reset 
114→  *         values.
115→  * @param  None
116→  * @retval None
117→  */
118→void CEC_DeInit(void)
119→{
120→  /* Enable CEC reset state */
121→  RCC_APB1PeriphResetCmd(RCC_APB1Periph_CEC, ENABLE);  
122→  /* Release CEC from reset state */
123→  RCC_APB1PeriphResetCmd(RCC_APB1Periph_CEC, DISABLE); 
124→}
125→
126→
127→/**
128→  * @brief  Initializes the CEC peripheral according to the specified 
129→  *         parameters in the CEC_InitStruct.
130→  * @param  CEC_InitStruct: pointer to an CEC_InitTypeDef structure that
131→  *         contains the configuration information for the specified
132→  *         CEC peripheral.
133→  * @retval None
134→  */
135→void CEC_Init(CEC_InitTypeDef* CEC_InitStruct)
136→{
137→  uint16_t tmpreg = 0;
138→ 
139→  /* Check the parameters */
140→  assert_param(IS_CEC_BIT_TIMING_ERROR_MODE(CEC_InitStruct->CEC_BitTimingMode)); 
141→  assert_param(IS_CEC_BIT_PERIOD_ERROR_MODE(CEC_InitStruct->CEC_BitPeriodMode));
142→     
143→  /*---------------------------- CEC CFGR Configuration -----------------*/
144→  /* Get the CEC CFGR value */
145→  tmpreg = CEC->CFGR;
146→  
147→  /* Clear BTEM and BPEM bits */
148→  tmpreg &= CFGR_CLEAR_Mask;
149→  
150→  /* Configure CEC: Bit Timing Error and Bit Period Error */
151→  tmpreg |= (uint16_t)(CEC_InitStruct->CEC_BitTimingMode | CEC_InitStruct->CEC_BitPeriodMode);
152→
153→  /* Write to CEC CFGR  register*/
154→  CEC->CFGR = tmpreg;
155→  
156→}
157→
158→/**
159→  * @brief  Enables or disables the specified CEC peripheral.
160→  * @param  NewState: new state of the CEC peripheral. 
161→  *     This parameter can be: ENABLE or DISABLE.
162→  * @retval None
163→  */
164→void CEC_Cmd(FunctionalState NewState)
165→{
166→  /* Check the parameters */
167→  assert_param(IS_FUNCTIONAL_STATE(NewState));
168→
169→  *(__IO uint32_t *) CFGR_PE_BB = (uint32_t)NewState;
170→
171→  if(NewState == DISABLE)
172→  {
173→    /* Wait until the PE bit is cleared by hardware (Idle Line detected) */
174→    while((CEC->CFGR & CEC_CFGR_PE) != (uint32_t)RESET)
175→    {
176→    }  
177→  }  
178→}
179→
180→/**
181→  * @brief  Enables or disables the CEC interrupt.
182→  * @param  NewState: new state of the CEC interrupt.
183→  *   This parameter can be: ENABLE or DISABLE.
184→  * @retval None
185→  */
186→void CEC_ITConfig(FunctionalState NewState)
187→{
188→  /* Check the parameters */
189→  assert_param(IS_FUNCTIONAL_STATE(NewState));
190→
191→  *(__IO uint32_t *) CFGR_IE_BB = (uint32_t)NewState;
192→}
193→
194→/**
195→  * @brief  Defines the Own Address of the CEC device.
196→  * @param  CEC_OwnAddress: The CEC own address
197→  * @retval None
198→  */
199→void CEC_OwnAddressConfig(uint8_t CEC_OwnAddress)
200→{
201→  /* Check the parameters */
202→  assert_param(IS_CEC_ADDRESS(CEC_OwnAddress));
203→
204→  /* Set the CEC own address */
205→  CEC->OAR = CEC_OwnAddress;
206→}
207→
208→/**
209→  * @brief  Sets the CEC prescaler value.
210→  * @param  CEC_Prescaler: CEC prescaler new value
211→  * @retval None
212→  */
213→void CEC_SetPrescaler(uint16_t CEC_Prescaler)
214→{
215→  /* Check the parameters */
216→  assert_param(IS_CEC_PRESCALER(CEC_Prescaler));
217→
218→  /* Set the  Prescaler value*/
219→  CEC->PRES = CEC_Prescaler;
220→}
221→
222→/**
223→  * @brief  Transmits single data through the CEC peripheral.
224→  * @param  Data: the data to transmit.
225→  * @retval None
226→  */
227→void CEC_SendDataByte(uint8_t Data)
228→{  
229→  /* Transmit Data */
230→  CEC->TXD = Data ;
231→}
232→
233→
234→/**
235→  * @brief  Returns the most recent received data by the CEC peripheral.
236→  * @param  None
237→  * @retval The received data.
238→  */
239→uint8_t CEC_ReceiveDataByte(void)
240→{
241→  /* Receive Data */
242→  return (uint8_t)(CEC->RXD);
243→}
244→
245→/**
246→  * @brief  Starts a new message.
247→  * @param  None
248→  * @retval None
249→  */
250→void CEC_StartOfMessage(void)
251→{  
252→  /* Starts of new message */
253→  *(__IO uint32_t *) CSR_TSOM_BB = (uint32_t)0x1;
254→}
255→
256→/**
257→  * @brief  Transmits message with or without an EOM bit.
258→  * @param  NewState: new state of the CEC Tx End Of Message. 
259→  *     This parameter can be: ENABLE or DISABLE.
260→  * @retval None
261→  */
262→void CEC_EndOfMessageCmd(FunctionalState NewState)
263→{   
264→  /* Check the parameters */
265→  assert_param(IS_FUNCTIONAL_STATE(NewState));
266→  
267→  /* The data byte will be transmitted with or without an EOM bit*/
268→  *(__IO uint32_t *) CSR_TEOM_BB = (uint32_t)NewState;
269→}
270→
271→/**
272→  * @brief  Gets the CEC flag status
273→  * @param  CEC_FLAG: specifies the CEC flag to check. 
274→  *   This parameter can be one of the following values:
275→  *     @arg CEC_FLAG_BTE: Bit Timing Error
276→  *     @arg CEC_FLAG_BPE: Bit Period Error
277→  *     @arg CEC_FLAG_RBTFE: Rx Block Transfer Finished Error
278→  *     @arg CEC_FLAG_SBE: Start Bit Error
279→  *     @arg CEC_FLAG_ACKE: Block Acknowledge Error
280→  *     @arg CEC_FLAG_LINE: Line Error
281→  *     @arg CEC_FLAG_TBTFE: Tx Block Transfer Finished Error
282→  *     @arg CEC_FLAG_TEOM: Tx End Of Message 
283→  *     @arg CEC_FLAG_TERR: Tx Error
284→  *     @arg CEC_FLAG_TBTRF: Tx Byte Transfer Request or Block Transfer Finished
285→  *     @arg CEC_FLAG_RSOM: Rx Start Of Message
286→  *     @arg CEC_FLAG_REOM: Rx End Of Message
287→  *     @arg CEC_FLAG_RERR: Rx Error
288→  *     @arg CEC_FLAG_RBTF: Rx Byte/Block Transfer Finished
289→  * @retval The new state of CEC_FLAG (SET or RESET)
290→  */
291→FlagStatus CEC_GetFlagStatus(uint32_t CEC_FLAG) 
292→{
293→  FlagStatus bitstatus = RESET;
294→  uint32_t cecreg = 0, cecbase = 0;
295→  
296→  /* Check the parameters */
297→  assert_param(IS_CEC_GET_FLAG(CEC_FLAG));
298→ 
299→  /* Get the CEC peripheral base address */
300→  cecbase = (uint32_t)(CEC_BASE);
301→  
302→  /* Read flag register index */
303→  cecreg = CEC_FLAG >> 28;
304→  
305→  /* Get bit[23:0] of the flag */
306→  CEC_FLAG &= FLAG_Mask;
307→  
308→  if(cecreg != 0)
309→  {
310→    /* Flag in CEC ESR Register */
311→    CEC_FLAG = (uint32_t)(CEC_FLAG >> 16);
312→    
313→    /* Get the CEC ESR register address */
314→    cecbase += 0xC;
315→  }
316→  else
317→  {
318→    /* Get the CEC CSR register address */
319→    cecbase += 0x10;
320→  }
321→  
322→  if(((*(__IO uint32_t *)cecbase) & CEC_FLAG) != (uint32_t)RESET)
323→  {
324→    /* CEC_FLAG is set */
325→    bitstatus = SET;
326→  }
327→  else
328→  {
329→    /* CEC_FLAG is reset */
330→    bitstatus = RESET;
331→  }
332→  
333→  /* Return the CEC_FLAG status */
334→  return  bitstatus;
335→}
336→
337→/**
338→  * @brief  Clears the CEC's pending flags.
339→  * @param  CEC_FLAG: specifies the flag to clear. 
340→  *   This parameter can be any combination of the following values:
341→  *     @arg CEC_FLAG_TERR: Tx Error
342→  *     @arg CEC_FLAG_TBTRF: Tx Byte Transfer Request or Block Transfer Finished
343→  *     @arg CEC_FLAG_RSOM: Rx Start Of Message
344→  *     @arg CEC_FLAG_REOM: Rx End Of Message
345→  *     @arg CEC_FLAG_RERR: Rx Error
346→  *     @arg CEC_FLAG_RBTF: Rx Byte/Block Transfer Finished
347→  * @retval None
348→  */
349→void CEC_ClearFlag(uint32_t CEC_FLAG)
350→{ 
351→  uint32_t tmp = 0x0;
352→  
353→  /* Check the parameters */
354→  assert_param(IS_CEC_CLEAR_FLAG(CEC_FLAG));
355→
356→  tmp = CEC->CSR & 0x2;
357→       
358→  /* Clear the selected CEC flags */
359→  CEC->CSR &= (uint32_t)(((~(uint32_t)CEC_FLAG) & 0xFFFFFFFC) | tmp);
360→}
361→
362→/**
363→  * @brief  Checks whether the specified CEC interrupt has occurred or not.
364→  * @param  CEC_IT: specifies the CEC interrupt source to check. 
365→  *   This parameter can be one of the following values:
366→  *     @arg CEC_IT_TERR: Tx Error
367→  *     @arg CEC_IT_TBTF: Tx Block Transfer Finished
368→  *     @arg CEC_IT_RERR: Rx Error
369→  *     @arg CEC_IT_RBTF: Rx Block Transfer Finished
370→  * @retval The new state of CEC_IT (SET or RESET).
371→  */
372→ITStatus CEC_GetITStatus(uint8_t CEC_IT)
373→{
374→  ITStatus bitstatus = RESET;
375→  uint32_t enablestatus = 0;
376→  
377→  /* Check the parameters */
378→   assert_param(IS_CEC_GET_IT(CEC_IT));
379→   
380→  /* Get the CEC IT enable bit status */
381→  enablestatus = (CEC->CFGR & (uint8_t)CEC_CFGR_IE) ;
382→  
383→  /* Check the status of the specified CEC interrupt */
384→  if (((CEC->CSR & CEC_IT) != (uint32_t)RESET) && enablestatus)
385→  {
386→    /* CEC_IT is set */
387→    bitstatus = SET;
388→  }
389→  else
390→  {
391→    /* CEC_IT is reset */
392→    bitstatus = RESET;
393→  }
394→  /* Return the CEC_IT status */
395→  return  bitstatus;
396→}
397→
398→/**
399→  * @brief  Clears the CEC's interrupt pending bits.
400→  * @param  CEC_IT: specifies the CEC interrupt pending bit to clear.
401→  *   This parameter can be any combination of the following values:
402→  *     @arg CEC_IT_TERR: Tx Error
403→  *     @arg CEC_IT_TBTF: Tx Block Transfer Finished
404→  *     @arg CEC_IT_RERR: Rx Error
405→  *     @arg CEC_IT_RBTF: Rx Block Transfer Finished
406→  * @retval None
407→  */
408→void CEC_ClearITPendingBit(uint16_t CEC_IT)
409→{
410→  uint32_t tmp = 0x0;
411→  
412→  /* Check the parameters */
413→  assert_param(IS_CEC_GET_IT(CEC_IT));
414→  
415→  tmp = CEC->CSR & 0x2;
416→  
417→  /* Clear the selected CEC interrupt pending bits */
418→  CEC->CSR &= (uint32_t)(((~(uint32_t)CEC_IT) & 0xFFFFFFFC) | tmp);
419→}
420→
421→/**
422→  * @}
423→  */ 
424→
425→/**
426→  * @}
427→  */ 
428→
429→/**
430→  * @}
431→  */ 
432→
433→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/