  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_usart.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the USART 
  8→  *          firmware library.
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
 24→#ifndef __STM32F10x_USART_H
 25→#define __STM32F10x_USART_H
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
 38→/** @addtogroup USART
 39→  * @{
 40→  */ 
 41→
 42→/** @defgroup USART_Exported_Types
 43→  * @{
 44→  */ 
 45→
 46→/** 
 47→  * @brief  USART Init Structure definition  
 48→  */ 
 49→  
 50→typedef struct
 51→{
 52→  uint32_t USART_BaudRate;            /*!< This member configures the USART communication baud rate.
 53→                                           The baud rate is computed using the following formula:
 54→                                            - IntegerDivider = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
 55→                                            - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 16) + 0.5 */
 56→
 57→  uint16_t USART_WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame.
 58→                                           This parameter can be a value of @ref USART_Word_Length */
 59→
 60→  uint16_t USART_StopBits;            /*!< Specifies the number of stop bits transmitted.
 61→                                           This parameter can be a value of @ref USART_Stop_Bits */
 62→
 63→  uint16_t USART_Parity;              /*!< Specifies the parity mode.
 64→                                           This parameter can be a value of @ref USART_Parity
 65→                                           @note When parity is enabled, the computed parity is inserted
 66→                                                 at the MSB position of the transmitted data (9th bit when
 67→                                                 the word length is set to 9 data bits; 8th bit when the
 68→                                                 word length is set to 8 data bits). */
 69→ 
 70→  uint16_t USART_Mode;                /*!< Specifies wether the Receive or Transmit mode is enabled or disabled.
 71→                                           This parameter can be a value of @ref USART_Mode */
 72→
 73→  uint16_t USART_HardwareFlowControl; /*!< Specifies wether the hardware flow control mode is enabled
 74→                                           or disabled.
 75→                                           This parameter can be a value of @ref USART_Hardware_Flow_Control */
 76→} USART_InitTypeDef;
 77→
 78→/** 
 79→  * @brief  USART Clock Init Structure definition  
 80→  */ 
 81→  
 82→typedef struct
 83→{
 84→
 85→  uint16_t USART_Clock;   /*!< Specifies whether the USART clock is enabled or disabled.
 86→                               This parameter can be a value of @ref USART_Clock */
 87→
 88→  uint16_t USART_CPOL;    /*!< Specifies the steady state value of the serial clock.
 89→                               This parameter can be a value of @ref USART_Clock_Polarity */
 90→
 91→  uint16_t USART_CPHA;    /*!< Specifies the clock transition on which the bit capture is made.
 92→                               This parameter can be a value of @ref USART_Clock_Phase */
 93→
 94→  uint16_t USART_LastBit; /*!< Specifies whether the clock pulse corresponding to the last transmitted
 95→                               data bit (MSB) has to be output on the SCLK pin in synchronous mode.
 96→                               This parameter can be a value of @ref USART_Last_Bit */
 97→} USART_ClockInitTypeDef;
 98→
 99→/**
100→  * @}
101→  */ 
102→
103→/** @defgroup USART_Exported_Constants
104→  * @{
105→  */ 
106→  
107→#define IS_USART_ALL_PERIPH(PERIPH) (((PERIPH) == USART1) || \
108→                                     ((PERIPH) == USART2) || \
109→                                     ((PERIPH) == USART3) || \
110→                                     ((PERIPH) == UART4) || \
111→                                     ((PERIPH) == UART5))
112→
113→#define IS_USART_123_PERIPH(PERIPH) (((PERIPH) == USART1) || \
114→                                     ((PERIPH) == USART2) || \
115→                                     ((PERIPH) == USART3))
116→
117→#define IS_USART_1234_PERIPH(PERIPH) (((PERIPH) == USART1) || \
118→                                      ((PERIPH) == USART2) || \
119→                                      ((PERIPH) == USART3) || \
120→                                      ((PERIPH) == UART4))
121→/** @defgroup USART_Word_Length 
122→  * @{
123→  */ 
124→  
125→#define USART_WordLength_8b                  ((uint16_t)0x0000)
126→#define USART_WordLength_9b                  ((uint16_t)0x1000)
127→                                    
128→#define IS_USART_WORD_LENGTH(LENGTH) (((LENGTH) == USART_WordLength_8b) || \
129→                                      ((LENGTH) == USART_WordLength_9b))
130→/**
131→  * @}
132→  */ 
133→
134→/** @defgroup USART_Stop_Bits 
135→  * @{
136→  */ 
137→  
138→#define USART_StopBits_1                     ((uint16_t)0x0000)
139→#define USART_StopBits_0_5                   ((uint16_t)0x1000)
140→#define USART_StopBits_2                     ((uint16_t)0x2000)
141→#define USART_StopBits_1_5                   ((uint16_t)0x3000)
142→#define IS_USART_STOPBITS(STOPBITS) (((STOPBITS) == USART_StopBits_1) || \
143→                                     ((STOPBITS) == USART_StopBits_0_5) || \
144→                                     ((STOPBITS) == USART_StopBits_2) || \
145→                                     ((STOPBITS) == USART_StopBits_1_5))
146→/**
147→  * @}
148→  */ 
149→
150→/** @defgroup USART_Parity 
151→  * @{
152→  */ 
153→  
154→#define USART_Parity_No                      ((uint16_t)0x0000)
155→#define USART_Parity_Even                    ((uint16_t)0x0400)
156→#define USART_Parity_Odd                     ((uint16_t)0x0600) 
157→#define IS_USART_PARITY(PARITY) (((PARITY) == USART_Parity_No) || \
158→                                 ((PARITY) == USART_Parity_Even) || \
159→                                 ((PARITY) == USART_Parity_Odd))
160→/**
161→  * @}
162→  */ 
163→
164→/** @defgroup USART_Mode 
165→  * @{
166→  */ 
167→  
168→#define USART_Mode_Rx                        ((uint16_t)0x0004)
169→#define USART_Mode_Tx                        ((uint16_t)0x0008)
170→#define IS_USART_MODE(MODE) ((((MODE) & (uint16_t)0xFFF3) == 0x00) && ((MODE) != (uint16_t)0x00))
171→/**
172→  * @}
173→  */ 
174→
175→/** @defgroup USART_Hardware_Flow_Control 
176→  * @{
177→  */ 
178→#define USART_HardwareFlowControl_None       ((uint16_t)0x0000)
179→#define USART_HardwareFlowControl_RTS        ((uint16_t)0x0100)
180→#define USART_HardwareFlowControl_CTS        ((uint16_t)0x0200)
181→#define USART_HardwareFlowControl_RTS_CTS    ((uint16_t)0x0300)
182→#define IS_USART_HARDWARE_FLOW_CONTROL(CONTROL)\
183→                              (((CONTROL) == USART_HardwareFlowControl_None) || \
184→                               ((CONTROL) == USART_HardwareFlowControl_RTS) || \
185→                               ((CONTROL) == USART_HardwareFlowControl_CTS) || \
186→                               ((CONTROL) == USART_HardwareFlowControl_RTS_CTS))
187→/**
188→  * @}
189→  */ 
190→
191→/** @defgroup USART_Clock 
192→  * @{
193→  */ 
194→#define USART_Clock_Disable                  ((uint16_t)0x0000)
195→#define USART_Clock_Enable                   ((uint16_t)0x0800)
196→#define IS_USART_CLOCK(CLOCK) (((CLOCK) == USART_Clock_Disable) || \
197→                               ((CLOCK) == USART_Clock_Enable))
198→/**
199→  * @}
200→  */ 
201→
202→/** @defgroup USART_Clock_Polarity 
203→  * @{
204→  */
205→  
206→#define USART_CPOL_Low                       ((uint16_t)0x0000)
207→#define USART_CPOL_High                      ((uint16_t)0x0400)
208→#define IS_USART_CPOL(CPOL) (((CPOL) == USART_CPOL_Low) || ((CPOL) == USART_CPOL_High))
209→
210→/**
211→  * @}
212→  */ 
213→
214→/** @defgroup USART_Clock_Phase
215→  * @{
216→  */
217→
218→#define USART_CPHA_1Edge                     ((uint16_t)0x0000)
219→#define USART_CPHA_2Edge                     ((uint16_t)0x0200)
220→#define IS_USART_CPHA(CPHA) (((CPHA) == USART_CPHA_1Edge) || ((CPHA) == USART_CPHA_2Edge))
221→
222→/**
223→  * @}
224→  */
225→
226→/** @defgroup USART_Last_Bit
227→  * @{
228→  */
229→
230→#define USART_LastBit_Disable                ((uint16_t)0x0000)
231→#define USART_LastBit_Enable                 ((uint16_t)0x0100)
232→#define IS_USART_LASTBIT(LASTBIT) (((LASTBIT) == USART_LastBit_Disable) || \
233→                                   ((LASTBIT) == USART_LastBit_Enable))
234→/**
235→  * @}
236→  */ 
237→
238→/** @defgroup USART_Interrupt_definition 
239→  * @{
240→  */
241→  
242→#define USART_IT_PE                          ((uint16_t)0x0028)
243→#define USART_IT_TXE                         ((uint16_t)0x0727)
244→#define USART_IT_TC                          ((uint16_t)0x0626)
245→#define USART_IT_RXNE                        ((uint16_t)0x0525)
246→#define USART_IT_IDLE                        ((uint16_t)0x0424)
247→#define USART_IT_LBD                         ((uint16_t)0x0846)
248→#define USART_IT_CTS                         ((uint16_t)0x096A)
249→#define USART_IT_ERR                         ((uint16_t)0x0060)
250→#define USART_IT_ORE                         ((uint16_t)0x0360)
251→#define USART_IT_NE                          ((uint16_t)0x0260)
252→#define USART_IT_FE                          ((uint16_t)0x0160)
253→#define IS_USART_CONFIG_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TXE) || \
254→                               ((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
255→                               ((IT) == USART_IT_IDLE) || ((IT) == USART_IT_LBD) || \
256→                               ((IT) == USART_IT_CTS) || ((IT) == USART_IT_ERR))
257→#define IS_USART_GET_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TXE) || \
258→                            ((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
259→                            ((IT) == USART_IT_IDLE) || ((IT) == USART_IT_LBD) || \
260→                            ((IT) == USART_IT_CTS) || ((IT) == USART_IT_ORE) || \
261→                            ((IT) == USART_IT_NE) || ((IT) == USART_IT_FE))
262→#define IS_USART_CLEAR_IT(IT) (((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
263→                               ((IT) == USART_IT_LBD) || ((IT) == USART_IT_CTS))
264→/**
265→  * @}
266→  */
267→
268→/** @defgroup USART_DMA_Requests 
269→  * @{
270→  */
271→
272→#define USART_DMAReq_Tx                      ((uint16_t)0x0080)
273→#define USART_DMAReq_Rx                      ((uint16_t)0x0040)
274→#define IS_USART_DMAREQ(DMAREQ) ((((DMAREQ) & (uint16_t)0xFF3F) == 0x00) && ((DMAREQ) != (uint16_t)0x00))
275→
276→/**
277→  * @}
278→  */ 
279→
280→/** @defgroup USART_WakeUp_methods
281→  * @{
282→  */
283→
284→#define USART_WakeUp_IdleLine                ((uint16_t)0x0000)
285→#define USART_WakeUp_AddressMark             ((uint16_t)0x0800)
286→#define IS_USART_WAKEUP(WAKEUP) (((WAKEUP) == USART_WakeUp_IdleLine) || \
287→                                 ((WAKEUP) == USART_WakeUp_AddressMark))
288→/**
289→  * @}
290→  */
291→
292→/** @defgroup USART_LIN_Break_Detection_Length 
293→  * @{
294→  */
295→  
296→#define USART_LINBreakDetectLength_10b      ((uint16_t)0x0000)
297→#define USART_LINBreakDetectLength_11b      ((uint16_t)0x0020)
298→#define IS_USART_LIN_BREAK_DETECT_LENGTH(LENGTH) \
299→                               (((LENGTH) == USART_LINBreakDetectLength_10b) || \
300→                                ((LENGTH) == USART_LINBreakDetectLength_11b))
301→/**
302→  * @}
303→  */
304→
305→/** @defgroup USART_IrDA_Low_Power 
306→  * @{
307→  */
308→
309→#define USART_IrDAMode_LowPower              ((uint16_t)0x0004)
310→#define USART_IrDAMode_Normal                ((uint16_t)0x0000)
311→#define IS_USART_IRDA_MODE(MODE) (((MODE) == USART_IrDAMode_LowPower) || \
312→                                  ((MODE) == USART_IrDAMode_Normal))
313→/**
314→  * @}
315→  */ 
316→
317→/** @defgroup USART_Flags 
318→  * @{
319→  */
320→
321→#define USART_FLAG_CTS                       ((uint16_t)0x0200)
322→#define USART_FLAG_LBD                       ((uint16_t)0x0100)
323→#define USART_FLAG_TXE                       ((uint16_t)0x0080)
324→#define USART_FLAG_TC                        ((uint16_t)0x0040)
325→#define USART_FLAG_RXNE                      ((uint16_t)0x0020)
326→#define USART_FLAG_IDLE                      ((uint16_t)0x0010)
327→#define USART_FLAG_ORE                       ((uint16_t)0x0008)
328→#define USART_FLAG_NE                        ((uint16_t)0x0004)
329→#define USART_FLAG_FE                        ((uint16_t)0x0002)
330→#define USART_FLAG_PE                        ((uint16_t)0x0001)
331→#define IS_USART_FLAG(FLAG) (((FLAG) == USART_FLAG_PE) || ((FLAG) == USART_FLAG_TXE) || \
332→                             ((FLAG) == USART_FLAG_TC) || ((FLAG) == USART_FLAG_RXNE) || \
333→                             ((FLAG) == USART_FLAG_IDLE) || ((FLAG) == USART_FLAG_LBD) || \
334→                             ((FLAG) == USART_FLAG_CTS) || ((FLAG) == USART_FLAG_ORE) || \
335→                             ((FLAG) == USART_FLAG_NE) || ((FLAG) == USART_FLAG_FE))
336→                              
337→#define IS_USART_CLEAR_FLAG(FLAG) ((((FLAG) & (uint16_t)0xFC9F) == 0x00) && ((FLAG) != (uint16_t)0x00))
338→#define IS_USART_PERIPH_FLAG(PERIPH, USART_FLAG) ((((*(uint32_t*)&(PERIPH)) != UART4_BASE) &&\
339→                                                  ((*(uint32_t*)&(PERIPH)) != UART5_BASE)) \
340→                                                  || ((USART_FLAG) != USART_FLAG_CTS)) 
341→#define IS_USART_BAUDRATE(BAUDRATE) (((BAUDRATE) > 0) && ((BAUDRATE) < 0x0044AA21))
342→#define IS_USART_ADDRESS(ADDRESS) ((ADDRESS) <= 0xF)
343→#define IS_USART_DATA(DATA) ((DATA) <= 0x1FF)
344→
345→/**
346→  * @}
347→  */ 
348→
349→/**
350→  * @}
351→  */ 
352→
353→/** @defgroup USART_Exported_Macros
354→  * @{
355→  */ 
356→
357→/**
358→  * @}
359→  */ 
360→
361→/** @defgroup USART_Exported_Functions
362→  * @{
363→  */
364→
365→void USART_DeInit(USART_TypeDef* USARTx);
366→void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
367→void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
368→void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
369→void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
370→void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
371→void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState);
372→void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
373→void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address);
374→void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16_t USART_WakeUp);
375→void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
376→void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16_t USART_LINBreakDetectLength);
377→void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
378→void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
379→uint16_t USART_ReceiveData(USART_TypeDef* USARTx);
380→void USART_SendBreak(USART_TypeDef* USARTx);
381→void USART_SetGuardTime(USART_TypeDef* USARTx, uint8_t USART_GuardTime);
382→void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler);
383→void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
384→void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
385→void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
386→void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
387→void USART_OneBitMethodCmd(USART_TypeDef* USARTx, FunctionalState NewState);
388→void USART_IrDAConfig(USART_TypeDef* USARTx, uint16_t USART_IrDAMode);
389→void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
390→FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
391→void USART_ClearFlag(USART_TypeDef* USARTx, uint16_t USART_FLAG);
392→ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT);
393→void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);
394→
395→#ifdef __cplusplus
396→}
397→#endif
398→
399→#endif /* __STM32F10x_USART_H */
400→/**
401→  * @}
402→  */ 
403→
404→/**
405→  * @}
406→  */ 
407→
408→/**
409→  * @}
410→  */ 
411→
412→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/