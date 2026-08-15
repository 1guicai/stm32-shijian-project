  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_spi.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the SPI firmware 
  8→  *          library.
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
 24→#ifndef __STM32F10x_SPI_H
 25→#define __STM32F10x_SPI_H
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
 38→/** @addtogroup SPI
 39→  * @{
 40→  */ 
 41→
 42→/** @defgroup SPI_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  SPI Init structure definition  
 48→  */
 49→
 50→typedef struct
 51→{
 52→  uint16_t SPI_Direction;           /*!< Specifies the SPI unidirectional or bidirectional data mode.
 53→                                         This parameter can be a value of @ref SPI_data_direction */
 54→
 55→  uint16_t SPI_Mode;                /*!< Specifies the SPI operating mode.
 56→                                         This parameter can be a value of @ref SPI_mode */
 57→
 58→  uint16_t SPI_DataSize;            /*!< Specifies the SPI data size.
 59→                                         This parameter can be a value of @ref SPI_data_size */
 60→
 61→  uint16_t SPI_CPOL;                /*!< Specifies the serial clock steady state.
 62→                                         This parameter can be a value of @ref SPI_Clock_Polarity */
 63→
 64→  uint16_t SPI_CPHA;                /*!< Specifies the clock active edge for the bit capture.
 65→                                         This parameter can be a value of @ref SPI_Clock_Phase */
 66→
 67→  uint16_t SPI_NSS;                 /*!< Specifies whether the NSS signal is managed by
 68→                                         hardware (NSS pin) or by software using the SSI bit.
 69→                                         This parameter can be a value of @ref SPI_Slave_Select_management */
 70→ 
 71→  uint16_t SPI_BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
 72→                                         used to configure the transmit and receive SCK clock.
 73→                                         This parameter can be a value of @ref SPI_BaudRate_Prescaler.
 74→                                         @note The communication clock is derived from the master
 75→                                               clock. The slave clock does not need to be set. */
 76→
 77→  uint16_t SPI_FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.
 78→                                         This parameter can be a value of @ref SPI_MSB_LSB_transmission */
 79→
 80→  uint16_t SPI_CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation. */
 81→}SPI_InitTypeDef;
 82→
 83→/** 
 84→  * @brief  I2S Init structure definition  
 85→  */
 86→
 87→typedef struct
 88→{
 89→
 90→  uint16_t I2S_Mode;         /*!< Specifies the I2S operating mode.
 91→                                  This parameter can be a value of @ref I2S_Mode */
 92→
 93→  uint16_t I2S_Standard;     /*!< Specifies the standard used for the I2S communication.
 94→                                  This parameter can be a value of @ref I2S_Standard */
 95→
 96→  uint16_t I2S_DataFormat;   /*!< Specifies the data format for the I2S communication.
 97→                                  This parameter can be a value of @ref I2S_Data_Format */
 98→
 99→  uint16_t I2S_MCLKOutput;   /*!< Specifies whether the I2S MCLK output is enabled or not.
100→                                  This parameter can be a value of @ref I2S_MCLK_Output */
101→
102→  uint32_t I2S_AudioFreq;    /*!< Specifies the frequency selected for the I2S communication.
103→                                  This parameter can be a value of @ref I2S_Audio_Frequency */
104→
105→  uint16_t I2S_CPOL;         /*!< Specifies the idle state of the I2S clock.
106→                                  This parameter can be a value of @ref I2S_Clock_Polarity */
107→}I2S_InitTypeDef;
108→
109→/**
110→  * @}
111→  */
112→
113→/** @defgroup SPI_Exported_Constants
114→  * @{
115→  */
116→
117→#define IS_SPI_ALL_PERIPH(PERIPH) (((PERIPH) == SPI1) || \
118→                                   ((PERIPH) == SPI2) || \
119→                                   ((PERIPH) == SPI3))
120→
121→#define IS_SPI_23_PERIPH(PERIPH) (((PERIPH) == SPI2) || \
122→                                  ((PERIPH) == SPI3))
123→
124→/** @defgroup SPI_data_direction 
125→  * @{
126→  */
127→  
128→#define SPI_Direction_2Lines_FullDuplex ((uint16_t)0x0000)
129→#define SPI_Direction_2Lines_RxOnly     ((uint16_t)0x0400)
130→#define SPI_Direction_1Line_Rx          ((uint16_t)0x8000)
131→#define SPI_Direction_1Line_Tx          ((uint16_t)0xC000)
132→#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_Direction_2Lines_FullDuplex) || \
133→                                     ((MODE) == SPI_Direction_2Lines_RxOnly) || \
134→                                     ((MODE) == SPI_Direction_1Line_Rx) || \
135→                                     ((MODE) == SPI_Direction_1Line_Tx))
136→/**
137→  * @}
138→  */
139→
140→/** @defgroup SPI_mode 
141→  * @{
142→  */
143→
144→#define SPI_Mode_Master                 ((uint16_t)0x0104)
145→#define SPI_Mode_Slave                  ((uint16_t)0x0000)
146→#define IS_SPI_MODE(MODE) (((MODE) == SPI_Mode_Master) || \
147→                           ((MODE) == SPI_Mode_Slave))
148→/**
149→  * @}
150→  */
151→
152→/** @defgroup SPI_data_size 
153→  * @{
154→  */
155→
156→#define SPI_DataSize_16b                ((uint16_t)0x0800)
157→#define SPI_DataSize_8b                 ((uint16_t)0x0000)
158→#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DataSize_16b) || \
159→                                   ((DATASIZE) == SPI_DataSize_8b))
160→/**
161→  * @}
162→  */ 
163→
164→/** @defgroup SPI_Clock_Polarity 
165→  * @{
166→  */
167→
168→#define SPI_CPOL_Low                    ((uint16_t)0x0000)
169→#define SPI_CPOL_High                   ((uint16_t)0x0002)
170→#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_Low) || \
171→                           ((CPOL) == SPI_CPOL_High))
172→/**
173→  * @}
174→  */
175→
176→/** @defgroup SPI_Clock_Phase 
177→  * @{
178→  */
179→
180→#define SPI_CPHA_1Edge                  ((uint16_t)0x0000)
181→#define SPI_CPHA_2Edge                  ((uint16_t)0x0001)
182→#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1Edge) || \
183→                           ((CPHA) == SPI_CPHA_2Edge))
184→/**
185→  * @}
186→  */
187→
188→/** @defgroup SPI_Slave_Select_management 
189→  * @{
190→  */
191→
192→#define SPI_NSS_Soft                    ((uint16_t)0x0200)
193→#define SPI_NSS_Hard                    ((uint16_t)0x0000)
194→#define IS_SPI_NSS(NSS) (((NSS) == SPI_NSS_Soft) || \
195→                         ((NSS) == SPI_NSS_Hard))
196→/**
197→  * @}
198→  */ 
199→
200→/** @defgroup SPI_BaudRate_Prescaler 
201→  * @{
202→  */
203→
204→#define SPI_BaudRatePrescaler_2         ((uint16_t)0x0000)
205→#define SPI_BaudRatePrescaler_4         ((uint16_t)0x0008)
206→#define SPI_BaudRatePrescaler_8         ((uint16_t)0x0010)
207→#define SPI_BaudRatePrescaler_16        ((uint16_t)0x0018)
208→#define SPI_BaudRatePrescaler_32        ((uint16_t)0x0020)
209→#define SPI_BaudRatePrescaler_64        ((uint16_t)0x0028)
210→#define SPI_BaudRatePrescaler_128       ((uint16_t)0x0030)
211→#define SPI_BaudRatePrescaler_256       ((uint16_t)0x0038)
212→#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) (((PRESCALER) == SPI_BaudRatePrescaler_2) || \
213→                                              ((PRESCALER) == SPI_BaudRatePrescaler_4) || \
214→                                              ((PRESCALER) == SPI_BaudRatePrescaler_8) || \
215→                                              ((PRESCALER) == SPI_BaudRatePrescaler_16) || \
216→                                              ((PRESCALER) == SPI_BaudRatePrescaler_32) || \
217→                                              ((PRESCALER) == SPI_BaudRatePrescaler_64) || \
218→                                              ((PRESCALER) == SPI_BaudRatePrescaler_128) || \
219→                                              ((PRESCALER) == SPI_BaudRatePrescaler_256))
220→/**
221→  * @}
222→  */ 
223→
224→/** @defgroup SPI_MSB_LSB_transmission 
225→  * @{
226→  */
227→
228→#define SPI_FirstBit_MSB                ((uint16_t)0x0000)
229→#define SPI_FirstBit_LSB                ((uint16_t)0x0080)
230→#define IS_SPI_FIRST_BIT(BIT) (((BIT) == SPI_FirstBit_MSB) || \
231→                               ((BIT) == SPI_FirstBit_LSB))
232→/**
233→  * @}
234→  */
235→
236→/** @defgroup I2S_Mode 
237→  * @{
238→  */
239→
240→#define I2S_Mode_SlaveTx                ((uint16_t)0x0000)
241→#define I2S_Mode_SlaveRx                ((uint16_t)0x0100)
242→#define I2S_Mode_MasterTx               ((uint16_t)0x0200)
243→#define I2S_Mode_MasterRx               ((uint16_t)0x0300)
244→#define IS_I2S_MODE(MODE) (((MODE) == I2S_Mode_SlaveTx) || \
245→                           ((MODE) == I2S_Mode_SlaveRx) || \
246→                           ((MODE) == I2S_Mode_MasterTx) || \
247→                           ((MODE) == I2S_Mode_MasterRx) )
248→/**
249→  * @}
250→  */
251→
252→/** @defgroup I2S_Standard 
253→  * @{
254→  */
255→
256→#define I2S_Standard_Phillips           ((uint16_t)0x0000)
257→#define I2S_Standard_MSB                ((uint16_t)0x0010)
258→#define I2S_Standard_LSB                ((uint16_t)0x0020)
259→#define I2S_Standard_PCMShort           ((uint16_t)0x0030)
260→#define I2S_Standard_PCMLong            ((uint16_t)0x00B0)
261→#define IS_I2S_STANDARD(STANDARD) (((STANDARD) == I2S_Standard_Phillips) || \
262→                                   ((STANDARD) == I2S_Standard_MSB) || \
263→                                   ((STANDARD) == I2S_Standard_LSB) || \
264→                                   ((STANDARD) == I2S_Standard_PCMShort) || \
265→                                   ((STANDARD) == I2S_Standard_PCMLong))
266→/**
267→  * @}
268→  */
269→
270→/** @defgroup I2S_Data_Format 
271→  * @{
272→  */
273→
274→#define I2S_DataFormat_16b              ((uint16_t)0x0000)
275→#define I2S_DataFormat_16bextended      ((uint16_t)0x0001)
276→#define I2S_DataFormat_24b              ((uint16_t)0x0003)
277→#define I2S_DataFormat_32b              ((uint16_t)0x0005)
278→#define IS_I2S_DATA_FORMAT(FORMAT) (((FORMAT) == I2S_DataFormat_16b) || \
279→                                    ((FORMAT) == I2S_DataFormat_16bextended) || \
280→                                    ((FORMAT) == I2S_DataFormat_24b) || \
281→                                    ((FORMAT) == I2S_DataFormat_32b))
282→/**
283→  * @}
284→  */ 
285→
286→/** @defgroup I2S_MCLK_Output 
287→  * @{
288→  */
289→
290→#define I2S_MCLKOutput_Enable           ((uint16_t)0x0200)
291→#define I2S_MCLKOutput_Disable          ((uint16_t)0x0000)
292→#define IS_I2S_MCLK_OUTPUT(OUTPUT) (((OUTPUT) == I2S_MCLKOutput_Enable) || \
293→                                    ((OUTPUT) == I2S_MCLKOutput_Disable))
294→/**
295→  * @}
296→  */
297→
298→/** @defgroup I2S_Audio_Frequency 
299→  * @{
300→  */
301→
302→#define I2S_AudioFreq_192k               ((uint32_t)192000)
303→#define I2S_AudioFreq_96k                ((uint32_t)96000)
304→#define I2S_AudioFreq_48k                ((uint32_t)48000)
305→#define I2S_AudioFreq_44k                ((uint32_t)44100)
306→#define I2S_AudioFreq_32k                ((uint32_t)32000)
307→#define I2S_AudioFreq_22k                ((uint32_t)22050)
308→#define I2S_AudioFreq_16k                ((uint32_t)16000)
309→#define I2S_AudioFreq_11k                ((uint32_t)11025)
310→#define I2S_AudioFreq_8k                 ((uint32_t)8000)
311→#define I2S_AudioFreq_Default            ((uint32_t)2)
312→
313→#define IS_I2S_AUDIO_FREQ(FREQ) ((((FREQ) >= I2S_AudioFreq_8k) && \
314→                                  ((FREQ) <= I2S_AudioFreq_192k)) || \
315→                                 ((FREQ) == I2S_AudioFreq_Default))
316→/**
317→  * @}
318→  */ 
319→
320→/** @defgroup I2S_Clock_Polarity 
321→  * @{
322→  */
323→
324→#define I2S_CPOL_Low                    ((uint16_t)0x0000)
325→#define I2S_CPOL_High                   ((uint16_t)0x0008)
326→#define IS_I2S_CPOL(CPOL) (((CPOL) == I2S_CPOL_Low) || \
327→                           ((CPOL) == I2S_CPOL_High))
328→/**
329→  * @}
330→  */
331→
332→/** @defgroup SPI_I2S_DMA_transfer_requests 
333→  * @{
334→  */
335→
336→#define SPI_I2S_DMAReq_Tx               ((uint16_t)0x0002)
337→#define SPI_I2S_DMAReq_Rx               ((uint16_t)0x0001)
338→#define IS_SPI_I2S_DMAREQ(DMAREQ) ((((DMAREQ) & (uint16_t)0xFFFC) == 0x00) && ((DMAREQ) != 0x00))
339→/**
340→  * @}
341→  */
342→
343→/** @defgroup SPI_NSS_internal_software_management 
344→  * @{
345→  */
346→
347→#define SPI_NSSInternalSoft_Set         ((uint16_t)0x0100)
348→#define SPI_NSSInternalSoft_Reset       ((uint16_t)0xFEFF)
349→#define IS_SPI_NSS_INTERNAL(INTERNAL) (((INTERNAL) == SPI_NSSInternalSoft_Set) || \
350→                                       ((INTERNAL) == SPI_NSSInternalSoft_Reset))
351→/**
352→  * @}
353→  */
354→
355→/** @defgroup SPI_CRC_Transmit_Receive 
356→  * @{
357→  */
358→
359→#define SPI_CRC_Tx                      ((uint8_t)0x00)
360→#define SPI_CRC_Rx                      ((uint8_t)0x01)
361→#define IS_SPI_CRC(CRC) (((CRC) == SPI_CRC_Tx) || ((CRC) == SPI_CRC_Rx))
362→/**
363→  * @}
364→  */
365→
366→/** @defgroup SPI_direction_transmit_receive 
367→  * @{
368→  */
369→
370→#define SPI_Direction_Rx                ((uint16_t)0xBFFF)
371→#define SPI_Direction_Tx                ((uint16_t)0x4000)
372→#define IS_SPI_DIRECTION(DIRECTION) (((DIRECTION) == SPI_Direction_Rx) || \
373→                                     ((DIRECTION) == SPI_Direction_Tx))
374→/**
375→  * @}
376→  */
377→
378→/** @defgroup SPI_I2S_interrupts_definition 
379→  * @{
380→  */
381→
382→#define SPI_I2S_IT_TXE                  ((uint8_t)0x71)
383→#define SPI_I2S_IT_RXNE                 ((uint8_t)0x60)
384→#define SPI_I2S_IT_ERR                  ((uint8_t)0x50)
385→#define IS_SPI_I2S_CONFIG_IT(IT) (((IT) == SPI_I2S_IT_TXE) || \
386→                                 ((IT) == SPI_I2S_IT_RXNE) || \
387→                                 ((IT) == SPI_I2S_IT_ERR))
388→#define SPI_I2S_IT_OVR                  ((uint8_t)0x56)
389→#define SPI_IT_MODF                     ((uint8_t)0x55)
390→#define SPI_IT_CRCERR                   ((uint8_t)0x54)
391→#define I2S_IT_UDR                      ((uint8_t)0x53)
392→#define IS_SPI_I2S_CLEAR_IT(IT) (((IT) == SPI_IT_CRCERR))
393→#define IS_SPI_I2S_GET_IT(IT) (((IT) == SPI_I2S_IT_RXNE) || ((IT) == SPI_I2S_IT_TXE) || \
394→                               ((IT) == I2S_IT_UDR) || ((IT) == SPI_IT_CRCERR) || \
395→                               ((IT) == SPI_IT_MODF) || ((IT) == SPI_I2S_IT_OVR))
396→/**
397→  * @}
398→  */
399→
400→/** @defgroup SPI_I2S_flags_definition 
401→  * @{
402→  */
403→
404→#define SPI_I2S_FLAG_RXNE               ((uint16_t)0x0001)
405→#define SPI_I2S_FLAG_TXE                ((uint16_t)0x0002)
406→#define I2S_FLAG_CHSIDE                 ((uint16_t)0x0004)
407→#define I2S_FLAG_UDR                    ((uint16_t)0x0008)
408→#define SPI_FLAG_CRCERR                 ((uint16_t)0x0010)
409→#define SPI_FLAG_MODF                   ((uint16_t)0x0020)
410→#define SPI_I2S_FLAG_OVR                ((uint16_t)0x0040)
411→#define SPI_I2S_FLAG_BSY                ((uint16_t)0x0080)
412→#define IS_SPI_I2S_CLEAR_FLAG(FLAG) (((FLAG) == SPI_FLAG_CRCERR))
413→#define IS_SPI_I2S_GET_FLAG(FLAG) (((FLAG) == SPI_I2S_FLAG_BSY) || ((FLAG) == SPI_I2S_FLAG_OVR) || \
414→                                   ((FLAG) == SPI_FLAG_MODF) || ((FLAG) == SPI_FLAG_CRCERR) || \
415→                                   ((FLAG) == I2S_FLAG_UDR) || ((FLAG) == I2S_FLAG_CHSIDE) || \
416→                                   ((FLAG) == SPI_I2S_FLAG_TXE) || ((FLAG) == SPI_I2S_FLAG_RXNE))
417→/**
418→  * @}
419→  */
420→
421→/** @defgroup SPI_CRC_polynomial 
422→  * @{
423→  */
424→
425→#define IS_SPI_CRC_POLYNOMIAL(POLYNOMIAL) ((POLYNOMIAL) >= 0x1)
426→/**
427→  * @}
428→  */
429→
430→/**
431→  * @}
432→  */
433→
434→/** @defgroup SPI_Exported_Macros
435→  * @{
436→  */
437→
438→/**
439→  * @}
440→  */
441→
442→/** @defgroup SPI_Exported_Functions
443→  * @{
444→  */
445→
446→void SPI_I2S_DeInit(SPI_TypeDef* SPIx);
447→void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
448→void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct);
449→void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
450→void I2S_StructInit(I2S_InitTypeDef* I2S_InitStruct);
451→void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
452→void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
453→void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState);
454→void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_I2S_DMAReq, FunctionalState NewState);
455→void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data);
456→uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx);
457→void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, uint16_t SPI_NSSInternalSoft);
458→void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState);
459→void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize);
460→void SPI_TransmitCRC(SPI_TypeDef* SPIx);
461→void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState);
462→uint16_t SPI_GetCRC(SPI_TypeDef* SPIx, uint8_t SPI_CRC);
463→uint16_t SPI_GetCRCPolynomial(SPI_TypeDef* SPIx);
464→void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, uint16_t SPI_Direction);
465→FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
466→void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
467→ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);
468→void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);
469→
470→#ifdef __cplusplus
471→}
472→#endif
473→
474→#endif /*__STM32F10x_SPI_H */
475→/**
476→  * @}
477→  */
478→
479→/**
480→  * @}
481→  */
482→
483→/**
484→  * @}
485→  */
486→
487→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/