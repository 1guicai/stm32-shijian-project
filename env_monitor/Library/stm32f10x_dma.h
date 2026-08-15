  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_dma.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the DMA firmware 
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
 24→#ifndef __STM32F10x_DMA_H
 25→#define __STM32F10x_DMA_H
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
 38→/** @addtogroup DMA
 39→  * @{
 40→  */
 41→
 42→/** @defgroup DMA_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  DMA Init structure definition
 48→  */
 49→
 50→typedef struct
 51→{
 52→  uint32_t DMA_PeripheralBaseAddr; /*!< Specifies the peripheral base address for DMAy Channelx. */
 53→
 54→  uint32_t DMA_MemoryBaseAddr;     /*!< Specifies the memory base address for DMAy Channelx. */
 55→
 56→  uint32_t DMA_DIR;                /*!< Specifies if the peripheral is the source or destination.
 57→                                        This parameter can be a value of @ref DMA_data_transfer_direction */
 58→
 59→  uint32_t DMA_BufferSize;         /*!< Specifies the buffer size, in data unit, of the specified Channel. 
 60→                                        The data unit is equal to the configuration set in DMA_PeripheralDataSize
 61→                                        or DMA_MemoryDataSize members depending in the transfer direction. */
 62→
 63→  uint32_t DMA_PeripheralInc;      /*!< Specifies whether the Peripheral address register is incremented or not.
 64→                                        This parameter can be a value of @ref DMA_peripheral_incremented_mode */
 65→
 66→  uint32_t DMA_MemoryInc;          /*!< Specifies whether the memory address register is incremented or not.
 67→                                        This parameter can be a value of @ref DMA_memory_incremented_mode */
 68→
 69→  uint32_t DMA_PeripheralDataSize; /*!< Specifies the Peripheral data width.
 70→                                        This parameter can be a value of @ref DMA_peripheral_data_size */
 71→
 72→  uint32_t DMA_MemoryDataSize;     /*!< Specifies the Memory data width.
 73→                                        This parameter can be a value of @ref DMA_memory_data_size */
 74→
 75→  uint32_t DMA_Mode;               /*!< Specifies the operation mode of the DMAy Channelx.
 76→                                        This parameter can be a value of @ref DMA_circular_normal_mode.
 77→                                        @note: The circular buffer mode cannot be used if the memory-to-memory
 78→                                              data transfer is configured on the selected Channel */
 79→
 80→  uint32_t DMA_Priority;           /*!< Specifies the software priority for the DMAy Channelx.
 81→                                        This parameter can be a value of @ref DMA_priority_level */
 82→
 83→  uint32_t DMA_M2M;                /*!< Specifies if the DMAy Channelx will be used in memory-to-memory transfer.
 84→                                        This parameter can be a value of @ref DMA_memory_to_memory */
 85→}DMA_InitTypeDef;
 86→
 87→/**
 88→  * @}
 89→  */
 90→
 91→/** @defgroup DMA_Exported_Constants
 92→  * @{
 93→  */
 94→
 95→#define IS_DMA_ALL_PERIPH(PERIPH) (((PERIPH) == DMA1_Channel1) || \
 96→                                   ((PERIPH) == DMA1_Channel2) || \
 97→                                   ((PERIPH) == DMA1_Channel3) || \
 98→                                   ((PERIPH) == DMA1_Channel4) || \
 99→                                   ((PERIPH) == DMA1_Channel5) || \
100→                                   ((PERIPH) == DMA1_Channel6) || \
101→                                   ((PERIPH) == DMA1_Channel7) || \
102→                                   ((PERIPH) == DMA2_Channel1) || \
103→                                   ((PERIPH) == DMA2_Channel2) || \
104→                                   ((PERIPH) == DMA2_Channel3) || \
105→                                   ((PERIPH) == DMA2_Channel4) || \
106→                                   ((PERIPH) == DMA2_Channel5))
107→
108→/** @defgroup DMA_data_transfer_direction 
109→  * @{
110→  */
111→
112→#define DMA_DIR_PeripheralDST              ((uint32_t)0x00000010)
113→#define DMA_DIR_PeripheralSRC              ((uint32_t)0x00000000)
114→#define IS_DMA_DIR(DIR) (((DIR) == DMA_DIR_PeripheralDST) || \
115→                         ((DIR) == DMA_DIR_PeripheralSRC))
116→/**
117→  * @}
118→  */
119→
120→/** @defgroup DMA_peripheral_incremented_mode 
121→  * @{
122→  */
123→
124→#define DMA_PeripheralInc_Enable           ((uint32_t)0x00000040)
125→#define DMA_PeripheralInc_Disable          ((uint32_t)0x00000000)
126→#define IS_DMA_PERIPHERAL_INC_STATE(STATE) (((STATE) == DMA_PeripheralInc_Enable) || \
127→                                            ((STATE) == DMA_PeripheralInc_Disable))
128→/**
129→  * @}
130→  */
131→
132→/** @defgroup DMA_memory_incremented_mode 
133→  * @{
134→  */
135→
136→#define DMA_MemoryInc_Enable               ((uint32_t)0x00000080)
137→#define DMA_MemoryInc_Disable              ((uint32_t)0x00000000)
138→#define IS_DMA_MEMORY_INC_STATE(STATE) (((STATE) == DMA_MemoryInc_Enable) || \
139→                                        ((STATE) == DMA_MemoryInc_Disable))
140→/**
141→  * @}
142→  */
143→
144→/** @defgroup DMA_peripheral_data_size 
145→  * @{
146→  */
147→
148→#define DMA_PeripheralDataSize_Byte        ((uint32_t)0x00000000)
149→#define DMA_PeripheralDataSize_HalfWord    ((uint32_t)0x00000100)
150→#define DMA_PeripheralDataSize_Word        ((uint32_t)0x00000200)
151→#define IS_DMA_PERIPHERAL_DATA_SIZE(SIZE) (((SIZE) == DMA_PeripheralDataSize_Byte) || \
152→                                           ((SIZE) == DMA_PeripheralDataSize_HalfWord) || \
153→                                           ((SIZE) == DMA_PeripheralDataSize_Word))
154→/**
155→  * @}
156→  */
157→
158→/** @defgroup DMA_memory_data_size 
159→  * @{
160→  */
161→
162→#define DMA_MemoryDataSize_Byte            ((uint32_t)0x00000000)
163→#define DMA_MemoryDataSize_HalfWord        ((uint32_t)0x00000400)
164→#define DMA_MemoryDataSize_Word            ((uint32_t)0x00000800)
165→#define IS_DMA_MEMORY_DATA_SIZE(SIZE) (((SIZE) == DMA_MemoryDataSize_Byte) || \
166→                                       ((SIZE) == DMA_MemoryDataSize_HalfWord) || \
167→                                       ((SIZE) == DMA_MemoryDataSize_Word))
168→/**
169→  * @}
170→  */
171→
172→/** @defgroup DMA_circular_normal_mode 
173→  * @{
174→  */
175→
176→#define DMA_Mode_Circular                  ((uint32_t)0x00000020)
177→#define DMA_Mode_Normal                    ((uint32_t)0x00000000)
178→#define IS_DMA_MODE(MODE) (((MODE) == DMA_Mode_Circular) || ((MODE) == DMA_Mode_Normal))
179→/**
180→  * @}
181→  */
182→
183→/** @defgroup DMA_priority_level 
184→  * @{
185→  */
186→
187→#define DMA_Priority_VeryHigh              ((uint32_t)0x00003000)
188→#define DMA_Priority_High                  ((uint32_t)0x00002000)
189→#define DMA_Priority_Medium                ((uint32_t)0x00001000)
190→#define DMA_Priority_Low                   ((uint32_t)0x00000000)
191→#define IS_DMA_PRIORITY(PRIORITY) (((PRIORITY) == DMA_Priority_VeryHigh) || \
192→                                   ((PRIORITY) == DMA_Priority_High) || \
193→                                   ((PRIORITY) == DMA_Priority_Medium) || \
194→                                   ((PRIORITY) == DMA_Priority_Low))
195→/**
196→  * @}
197→  */
198→
199→/** @defgroup DMA_memory_to_memory 
200→  * @{
201→  */
202→
203→#define DMA_M2M_Enable                     ((uint32_t)0x00004000)
204→#define DMA_M2M_Disable                    ((uint32_t)0x00000000)
205→#define IS_DMA_M2M_STATE(STATE) (((STATE) == DMA_M2M_Enable) || ((STATE) == DMA_M2M_Disable))
206→
207→/**
208→  * @}
209→  */
210→
211→/** @defgroup DMA_interrupts_definition 
212→  * @{
213→  */
214→
215→#define DMA_IT_TC                          ((uint32_t)0x00000002)
216→#define DMA_IT_HT                          ((uint32_t)0x00000004)
217→#define DMA_IT_TE                          ((uint32_t)0x00000008)
218→#define IS_DMA_CONFIG_IT(IT) ((((IT) & 0xFFFFFFF1) == 0x00) && ((IT) != 0x00))
219→
220→#define DMA1_IT_GL1                        ((uint32_t)0x00000001)
221→#define DMA1_IT_TC1                        ((uint32_t)0x00000002)
222→#define DMA1_IT_HT1                        ((uint32_t)0x00000004)
223→#define DMA1_IT_TE1                        ((uint32_t)0x00000008)
224→#define DMA1_IT_GL2                        ((uint32_t)0x00000010)
225→#define DMA1_IT_TC2                        ((uint32_t)0x00000020)
226→#define DMA1_IT_HT2                        ((uint32_t)0x00000040)
227→#define DMA1_IT_TE2                        ((uint32_t)0x00000080)
228→#define DMA1_IT_GL3                        ((uint32_t)0x00000100)
229→#define DMA1_IT_TC3                        ((uint32_t)0x00000200)
230→#define DMA1_IT_HT3                        ((uint32_t)0x00000400)
231→#define DMA1_IT_TE3                        ((uint32_t)0x00000800)
232→#define DMA1_IT_GL4                        ((uint32_t)0x00001000)
233→#define DMA1_IT_TC4                        ((uint32_t)0x00002000)
234→#define DMA1_IT_HT4                        ((uint32_t)0x00004000)
235→#define DMA1_IT_TE4                        ((uint32_t)0x00008000)
236→#define DMA1_IT_GL5                        ((uint32_t)0x00010000)
237→#define DMA1_IT_TC5                        ((uint32_t)0x00020000)
238→#define DMA1_IT_HT5                        ((uint32_t)0x00040000)
239→#define DMA1_IT_TE5                        ((uint32_t)0x00080000)
240→#define DMA1_IT_GL6                        ((uint32_t)0x00100000)
241→#define DMA1_IT_TC6                        ((uint32_t)0x00200000)
242→#define DMA1_IT_HT6                        ((uint32_t)0x00400000)
243→#define DMA1_IT_TE6                        ((uint32_t)0x00800000)
244→#define DMA1_IT_GL7                        ((uint32_t)0x01000000)
245→#define DMA1_IT_TC7                        ((uint32_t)0x02000000)
246→#define DMA1_IT_HT7                        ((uint32_t)0x04000000)
247→#define DMA1_IT_TE7                        ((uint32_t)0x08000000)
248→
249→#define DMA2_IT_GL1                        ((uint32_t)0x10000001)
250→#define DMA2_IT_TC1                        ((uint32_t)0x10000002)
251→#define DMA2_IT_HT1                        ((uint32_t)0x10000004)
252→#define DMA2_IT_TE1                        ((uint32_t)0x10000008)
253→#define DMA2_IT_GL2                        ((uint32_t)0x10000010)
254→#define DMA2_IT_TC2                        ((uint32_t)0x10000020)
255→#define DMA2_IT_HT2                        ((uint32_t)0x10000040)
256→#define DMA2_IT_TE2                        ((uint32_t)0x10000080)
257→#define DMA2_IT_GL3                        ((uint32_t)0x10000100)
258→#define DMA2_IT_TC3                        ((uint32_t)0x10000200)
259→#define DMA2_IT_HT3                        ((uint32_t)0x10000400)
260→#define DMA2_IT_TE3                        ((uint32_t)0x10000800)
261→#define DMA2_IT_GL4                        ((uint32_t)0x10001000)
262→#define DMA2_IT_TC4                        ((uint32_t)0x10002000)
263→#define DMA2_IT_HT4                        ((uint32_t)0x10004000)
264→#define DMA2_IT_TE4                        ((uint32_t)0x10008000)
265→#define DMA2_IT_GL5                        ((uint32_t)0x10010000)
266→#define DMA2_IT_TC5                        ((uint32_t)0x10020000)
267→#define DMA2_IT_HT5                        ((uint32_t)0x10040000)
268→#define DMA2_IT_TE5                        ((uint32_t)0x10080000)
269→
270→#define IS_DMA_CLEAR_IT(IT) (((((IT) & 0xF0000000) == 0x00) || (((IT) & 0xEFF00000) == 0x00)) && ((IT) != 0x00))
271→
272→#define IS_DMA_GET_IT(IT) (((IT) == DMA1_IT_GL1) || ((IT) == DMA1_IT_TC1) || \
273→                           ((IT) == DMA1_IT_HT1) || ((IT) == DMA1_IT_TE1) || \
274→                           ((IT) == DMA1_IT_GL2) || ((IT) == DMA1_IT_TC2) || \
275→                           ((IT) == DMA1_IT_HT2) || ((IT) == DMA1_IT_TE2) || \
276→                           ((IT) == DMA1_IT_GL3) || ((IT) == DMA1_IT_TC3) || \
277→                           ((IT) == DMA1_IT_HT3) || ((IT) == DMA1_IT_TE3) || \
278→                           ((IT) == DMA1_IT_GL4) || ((IT) == DMA1_IT_TC4) || \
279→                           ((IT) == DMA1_IT_HT4) || ((IT) == DMA1_IT_TE4) || \
280→                           ((IT) == DMA1_IT_GL5) || ((IT) == DMA1_IT_TC5) || \
281→                           ((IT) == DMA1_IT_HT5) || ((IT) == DMA1_IT_TE5) || \
282→                           ((IT) == DMA1_IT_GL6) || ((IT) == DMA1_IT_TC6) || \
283→                           ((IT) == DMA1_IT_HT6) || ((IT) == DMA1_IT_TE6) || \
284→                           ((IT) == DMA1_IT_GL7) || ((IT) == DMA1_IT_TC7) || \
285→                           ((IT) == DMA1_IT_HT7) || ((IT) == DMA1_IT_TE7) || \
286→                           ((IT) == DMA2_IT_GL1) || ((IT) == DMA2_IT_TC1) || \
287→                           ((IT) == DMA2_IT_HT1) || ((IT) == DMA2_IT_TE1) || \
288→                           ((IT) == DMA2_IT_GL2) || ((IT) == DMA2_IT_TC2) || \
289→                           ((IT) == DMA2_IT_HT2) || ((IT) == DMA2_IT_TE2) || \
290→                           ((IT) == DMA2_IT_GL3) || ((IT) == DMA2_IT_TC3) || \
291→                           ((IT) == DMA2_IT_HT3) || ((IT) == DMA2_IT_TE3) || \
292→                           ((IT) == DMA2_IT_GL4) || ((IT) == DMA2_IT_TC4) || \
293→                           ((IT) == DMA2_IT_HT4) || ((IT) == DMA2_IT_TE4) || \
294→                           ((IT) == DMA2_IT_GL5) || ((IT) == DMA2_IT_TC5) || \
295→                           ((IT) == DMA2_IT_HT5) || ((IT) == DMA2_IT_TE5))
296→
297→/**
298→  * @}
299→  */
300→
301→/** @defgroup DMA_flags_definition 
302→  * @{
303→  */
304→#define DMA1_FLAG_GL1                      ((uint32_t)0x00000001)
305→#define DMA1_FLAG_TC1                      ((uint32_t)0x00000002)
306→#define DMA1_FLAG_HT1                      ((uint32_t)0x00000004)
307→#define DMA1_FLAG_TE1                      ((uint32_t)0x00000008)
308→#define DMA1_FLAG_GL2                      ((uint32_t)0x00000010)
309→#define DMA1_FLAG_TC2                      ((uint32_t)0x00000020)
310→#define DMA1_FLAG_HT2                      ((uint32_t)0x00000040)
311→#define DMA1_FLAG_TE2                      ((uint32_t)0x00000080)
312→#define DMA1_FLAG_GL3                      ((uint32_t)0x00000100)
313→#define DMA1_FLAG_TC3                      ((uint32_t)0x00000200)
314→#define DMA1_FLAG_HT3                      ((uint32_t)0x00000400)
315→#define DMA1_FLAG_TE3                      ((uint32_t)0x00000800)
316→#define DMA1_FLAG_GL4                      ((uint32_t)0x00001000)
317→#define DMA1_FLAG_TC4                      ((uint32_t)0x00002000)
318→#define DMA1_FLAG_HT4                      ((uint32_t)0x00004000)
319→#define DMA1_FLAG_TE4                      ((uint32_t)0x00008000)
320→#define DMA1_FLAG_GL5                      ((uint32_t)0x00010000)
321→#define DMA1_FLAG_TC5                      ((uint32_t)0x00020000)
322→#define DMA1_FLAG_HT5                      ((uint32_t)0x00040000)
323→#define DMA1_FLAG_TE5                      ((uint32_t)0x00080000)
324→#define DMA1_FLAG_GL6                      ((uint32_t)0x00100000)
325→#define DMA1_FLAG_TC6                      ((uint32_t)0x00200000)
326→#define DMA1_FLAG_HT6                      ((uint32_t)0x00400000)
327→#define DMA1_FLAG_TE6                      ((uint32_t)0x00800000)
328→#define DMA1_FLAG_GL7                      ((uint32_t)0x01000000)
329→#define DMA1_FLAG_TC7                      ((uint32_t)0x02000000)
330→#define DMA1_FLAG_HT7                      ((uint32_t)0x04000000)
331→#define DMA1_FLAG_TE7                      ((uint32_t)0x08000000)
332→
333→#define DMA2_FLAG_GL1                      ((uint32_t)0x10000001)
334→#define DMA2_FLAG_TC1                      ((uint32_t)0x10000002)
335→#define DMA2_FLAG_HT1                      ((uint32_t)0x10000004)
336→#define DMA2_FLAG_TE1                      ((uint32_t)0x10000008)
337→#define DMA2_FLAG_GL2                      ((uint32_t)0x10000010)
338→#define DMA2_FLAG_TC2                      ((uint32_t)0x10000020)
339→#define DMA2_FLAG_HT2                      ((uint32_t)0x10000040)
340→#define DMA2_FLAG_TE2                      ((uint32_t)0x10000080)
341→#define DMA2_FLAG_GL3                      ((uint32_t)0x10000100)
342→#define DMA2_FLAG_TC3                      ((uint32_t)0x10000200)
343→#define DMA2_FLAG_HT3                      ((uint32_t)0x10000400)
344→#define DMA2_FLAG_TE3                      ((uint32_t)0x10000800)
345→#define DMA2_FLAG_GL4                      ((uint32_t)0x10001000)
346→#define DMA2_FLAG_TC4                      ((uint32_t)0x10002000)
347→#define DMA2_FLAG_HT4                      ((uint32_t)0x10004000)
348→#define DMA2_FLAG_TE4                      ((uint32_t)0x10008000)
349→#define DMA2_FLAG_GL5                      ((uint32_t)0x10010000)
350→#define DMA2_FLAG_TC5                      ((uint32_t)0x10020000)
351→#define DMA2_FLAG_HT5                      ((uint32_t)0x10040000)
352→#define DMA2_FLAG_TE5                      ((uint32_t)0x10080000)
353→
354→#define IS_DMA_CLEAR_FLAG(FLAG) (((((FLAG) & 0xF0000000) == 0x00) || (((FLAG) & 0xEFF00000) == 0x00)) && ((FLAG) != 0x00))
355→
356→#define IS_DMA_GET_FLAG(FLAG) (((FLAG) == DMA1_FLAG_GL1) || ((FLAG) == DMA1_FLAG_TC1) || \
357→                               ((FLAG) == DMA1_FLAG_HT1) || ((FLAG) == DMA1_FLAG_TE1) || \
358→                               ((FLAG) == DMA1_FLAG_GL2) || ((FLAG) == DMA1_FLAG_TC2) || \
359→                               ((FLAG) == DMA1_FLAG_HT2) || ((FLAG) == DMA1_FLAG_TE2) || \
360→                               ((FLAG) == DMA1_FLAG_GL3) || ((FLAG) == DMA1_FLAG_TC3) || \
361→                               ((FLAG) == DMA1_FLAG_HT3) || ((FLAG) == DMA1_FLAG_TE3) || \
362→                               ((FLAG) == DMA1_FLAG_GL4) || ((FLAG) == DMA1_FLAG_TC4) || \
363→                               ((FLAG) == DMA1_FLAG_HT4) || ((FLAG) == DMA1_FLAG_TE4) || \
364→                               ((FLAG) == DMA1_FLAG_GL5) || ((FLAG) == DMA1_FLAG_TC5) || \
365→                               ((FLAG) == DMA1_FLAG_HT5) || ((FLAG) == DMA1_FLAG_TE5) || \
366→                               ((FLAG) == DMA1_FLAG_GL6) || ((FLAG) == DMA1_FLAG_TC6) || \
367→                               ((FLAG) == DMA1_FLAG_HT6) || ((FLAG) == DMA1_FLAG_TE6) || \
368→                               ((FLAG) == DMA1_FLAG_GL7) || ((FLAG) == DMA1_FLAG_TC7) || \
369→                               ((FLAG) == DMA1_FLAG_HT7) || ((FLAG) == DMA1_FLAG_TE7) || \
370→                               ((FLAG) == DMA2_FLAG_GL1) || ((FLAG) == DMA2_FLAG_TC1) || \
371→                               ((FLAG) == DMA2_FLAG_HT1) || ((FLAG) == DMA2_FLAG_TE1) || \
372→                               ((FLAG) == DMA2_FLAG_GL2) || ((FLAG) == DMA2_FLAG_TC2) || \
373→                               ((FLAG) == DMA2_FLAG_HT2) || ((FLAG) == DMA2_FLAG_TE2) || \
374→                               ((FLAG) == DMA2_FLAG_GL3) || ((FLAG) == DMA2_FLAG_TC3) || \
375→                               ((FLAG) == DMA2_FLAG_HT3) || ((FLAG) == DMA2_FLAG_TE3) || \
376→                               ((FLAG) == DMA2_FLAG_GL4) || ((FLAG) == DMA2_FLAG_TC4) || \
377→                               ((FLAG) == DMA2_FLAG_HT4) || ((FLAG) == DMA2_FLAG_TE4) || \
378→                               ((FLAG) == DMA2_FLAG_GL5) || ((FLAG) == DMA2_FLAG_TC5) || \
379→                               ((FLAG) == DMA2_FLAG_HT5) || ((FLAG) == DMA2_FLAG_TE5))
380→/**
381→  * @}
382→  */
383→
384→/** @defgroup DMA_Buffer_Size 
385→  * @{
386→  */
387→
388→#define IS_DMA_BUFFER_SIZE(SIZE) (((SIZE) >= 0x1) && ((SIZE) < 0x10000))
389→
390→/**
391→  * @}
392→  */
393→
394→/**
395→  * @}
396→  */
397→
398→/** @defgroup DMA_Exported_Macros
399→  * @{
400→  */
401→
402→/**
403→  * @}
404→  */
405→
406→/** @defgroup DMA_Exported_Functions
407→  * @{
408→  */
409→
410→void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx);
411→void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
412→void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct);
413→void DMA_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState);
414→void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT, FunctionalState NewState);
415→void DMA_SetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx, uint16_t DataNumber); 
416→uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx);
417→FlagStatus DMA_GetFlagStatus(uint32_t DMAy_FLAG);
418→void DMA_ClearFlag(uint32_t DMAy_FLAG);
419→ITStatus DMA_GetITStatus(uint32_t DMAy_IT);
420→void DMA_ClearITPendingBit(uint32_t DMAy_IT);
421→
422→#ifdef __cplusplus
423→}
424→#endif
425→
426→#endif /*__STM32F10x_DMA_H */
427→/**
428→  * @}
429→  */
430→
431→/**
432→  * @}
433→  */
434→
435→/**
436→  * @}
437→  */
438→
439→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/