  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_sdio.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the SDIO firmware
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
 24→#ifndef __STM32F10x_SDIO_H
 25→#define __STM32F10x_SDIO_H
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
 38→/** @addtogroup SDIO
 39→  * @{
 40→  */
 41→
 42→/** @defgroup SDIO_Exported_Types
 43→  * @{
 44→  */
 45→
 46→typedef struct
 47→{
 48→  uint32_t SDIO_ClockEdge;            /*!< Specifies the clock transition on which the bit capture is made.
 49→                                           This parameter can be a value of @ref SDIO_Clock_Edge */
 50→
 51→  uint32_t SDIO_ClockBypass;          /*!< Specifies whether the SDIO Clock divider bypass is
 52→                                           enabled or disabled.
 53→                                           This parameter can be a value of @ref SDIO_Clock_Bypass */
 54→
 55→  uint32_t SDIO_ClockPowerSave;       /*!< Specifies whether SDIO Clock output is enabled or
 56→                                           disabled when the bus is idle.
 57→                                           This parameter can be a value of @ref SDIO_Clock_Power_Save */
 58→
 59→  uint32_t SDIO_BusWide;              /*!< Specifies the SDIO bus width.
 60→                                           This parameter can be a value of @ref SDIO_Bus_Wide */
 61→
 62→  uint32_t SDIO_HardwareFlowControl;  /*!< Specifies whether the SDIO hardware flow control is enabled or disabled.
 63→                                           This parameter can be a value of @ref SDIO_Hardware_Flow_Control */
 64→
 65→  uint8_t SDIO_ClockDiv;              /*!< Specifies the clock frequency of the SDIO controller.
 66→                                           This parameter can be a value between 0x00 and 0xFF. */
 67→                                           
 68→} SDIO_InitTypeDef;
 69→
 70→typedef struct
 71→{
 72→  uint32_t SDIO_Argument;  /*!< Specifies the SDIO command argument which is sent
 73→                                to a card as part of a command message. If a command
 74→                                contains an argument, it must be loaded into this register
 75→                                before writing the command to the command register */
 76→
 77→  uint32_t SDIO_CmdIndex;  /*!< Specifies the SDIO command index. It must be lower than 0x40. */
 78→
 79→  uint32_t SDIO_Response;  /*!< Specifies the SDIO response type.
 80→                                This parameter can be a value of @ref SDIO_Response_Type */
 81→
 82→  uint32_t SDIO_Wait;      /*!< Specifies whether SDIO wait-for-interrupt request is enabled or disabled.
 83→                                This parameter can be a value of @ref SDIO_Wait_Interrupt_State */
 84→
 85→  uint32_t SDIO_CPSM;      /*!< Specifies whether SDIO Command path state machine (CPSM)
 86→                                is enabled or disabled.
 87→                                This parameter can be a value of @ref SDIO_CPSM_State */
 88→} SDIO_CmdInitTypeDef;
 89→
 90→typedef struct
 91→{
 92→  uint32_t SDIO_DataTimeOut;    /*!< Specifies the data timeout period in card bus clock periods. */
 93→
 94→  uint32_t SDIO_DataLength;     /*!< Specifies the number of data bytes to be transferred. */
 95→ 
 96→  uint32_t SDIO_DataBlockSize;  /*!< Specifies the data block size for block transfer.
 97→                                     This parameter can be a value of @ref SDIO_Data_Block_Size */
 98→ 
 99→  uint32_t SDIO_TransferDir;    /*!< Specifies the data transfer direction, whether the transfer
100→                                     is a read or write.
101→                                     This parameter can be a value of @ref SDIO_Transfer_Direction */
102→ 
103→  uint32_t SDIO_TransferMode;   /*!< Specifies whether data transfer is in stream or block mode.
104→                                     This parameter can be a value of @ref SDIO_Transfer_Type */
105→ 
106→  uint32_t SDIO_DPSM;           /*!< Specifies whether SDIO Data path state machine (DPSM)
107→                                     is enabled or disabled.
108→                                     This parameter can be a value of @ref SDIO_DPSM_State */
109→} SDIO_DataInitTypeDef;
110→
111→/**
112→  * @}
113→  */ 
114→
115→/** @defgroup SDIO_Exported_Constants
116→  * @{
117→  */
118→
119→/** @defgroup SDIO_Clock_Edge 
120→  * @{
121→  */
122→
123→#define SDIO_ClockEdge_Rising               ((uint32_t)0x00000000)
124→#define SDIO_ClockEdge_Falling              ((uint32_t)0x00002000)
125→#define IS_SDIO_CLOCK_EDGE(EDGE) (((EDGE) == SDIO_ClockEdge_Rising) || \
126→                                  ((EDGE) == SDIO_ClockEdge_Falling))
127→/**
128→  * @}
129→  */
130→
131→/** @defgroup SDIO_Clock_Bypass 
132→  * @{
133→  */
134→
135→#define SDIO_ClockBypass_Disable             ((uint32_t)0x00000000)
136→#define SDIO_ClockBypass_Enable              ((uint32_t)0x00000400)    
137→#define IS_SDIO_CLOCK_BYPASS(BYPASS) (((BYPASS) == SDIO_ClockBypass_Disable) || \
138→                                     ((BYPASS) == SDIO_ClockBypass_Enable))
139→/**
140→  * @}
141→  */ 
142→
143→/** @defgroup SDIO_Clock_Power_Save 
144→  * @{
145→  */
146→
147→#define SDIO_ClockPowerSave_Disable         ((uint32_t)0x00000000)
148→#define SDIO_ClockPowerSave_Enable          ((uint32_t)0x00000200) 
149→#define IS_SDIO_CLOCK_POWER_SAVE(SAVE) (((SAVE) == SDIO_ClockPowerSave_Disable) || \
150→                                        ((SAVE) == SDIO_ClockPowerSave_Enable))
151→/**
152→  * @}
153→  */
154→
155→/** @defgroup SDIO_Bus_Wide 
156→  * @{
157→  */
158→
159→#define SDIO_BusWide_1b                     ((uint32_t)0x00000000)
160→#define SDIO_BusWide_4b                     ((uint32_t)0x00000800)
161→#define SDIO_BusWide_8b                     ((uint32_t)0x00001000)
162→#define IS_SDIO_BUS_WIDE(WIDE) (((WIDE) == SDIO_BusWide_1b) || ((WIDE) == SDIO_BusWide_4b) || \
163→                                ((WIDE) == SDIO_BusWide_8b))
164→
165→/**
166→  * @}
167→  */
168→
169→/** @defgroup SDIO_Hardware_Flow_Control 
170→  * @{
171→  */
172→
173→#define SDIO_HardwareFlowControl_Disable    ((uint32_t)0x00000000)
174→#define SDIO_HardwareFlowControl_Enable     ((uint32_t)0x00004000)
175→#define IS_SDIO_HARDWARE_FLOW_CONTROL(CONTROL) (((CONTROL) == SDIO_HardwareFlowControl_Disable) || \
176→                                                ((CONTROL) == SDIO_HardwareFlowControl_Enable))
177→/**
178→  * @}
179→  */
180→
181→/** @defgroup SDIO_Power_State 
182→  * @{
183→  */
184→
185→#define SDIO_PowerState_OFF                 ((uint32_t)0x00000000)
186→#define SDIO_PowerState_ON                  ((uint32_t)0x00000003)
187→#define IS_SDIO_POWER_STATE(STATE) (((STATE) == SDIO_PowerState_OFF) || ((STATE) == SDIO_PowerState_ON)) 
188→/**
189→  * @}
190→  */ 
191→
192→
193→/** @defgroup SDIO_Interrupt_sources 
194→  * @{
195→  */
196→
197→#define SDIO_IT_CCRCFAIL                    ((uint32_t)0x00000001)
198→#define SDIO_IT_DCRCFAIL                    ((uint32_t)0x00000002)
199→#define SDIO_IT_CTIMEOUT                    ((uint32_t)0x00000004)
200→#define SDIO_IT_DTIMEOUT                    ((uint32_t)0x00000008)
201→#define SDIO_IT_TXUNDERR                    ((uint32_t)0x00000010)
202→#define SDIO_IT_RXOVERR                     ((uint32_t)0x00000020)
203→#define SDIO_IT_CMDREND                     ((uint32_t)0x00000040)
204→#define SDIO_IT_CMDSENT                     ((uint32_t)0x00000080)
205→#define SDIO_IT_DATAEND                     ((uint32_t)0x00000100)
206→#define SDIO_IT_STBITERR                    ((uint32_t)0x00000200)
207→#define SDIO_IT_DBCKEND                     ((uint32_t)0x00000400)
208→#define SDIO_IT_CMDACT                      ((uint32_t)0x00000800)
209→#define SDIO_IT_TXACT                       ((uint32_t)0x00001000)
210→#define SDIO_IT_RXACT                       ((uint32_t)0x00002000)
211→#define SDIO_IT_TXFIFOHE                    ((uint32_t)0x00004000)
212→#define SDIO_IT_RXFIFOHF                    ((uint32_t)0x00008000)
213→#define SDIO_IT_TXFIFOF                     ((uint32_t)0x00010000)
214→#define SDIO_IT_RXFIFOF                     ((uint32_t)0x00020000)
215→#define SDIO_IT_TXFIFOE                     ((uint32_t)0x00040000)
216→#define SDIO_IT_RXFIFOE                     ((uint32_t)0x00080000)
217→#define SDIO_IT_TXDAVL                      ((uint32_t)0x00100000)
218→#define SDIO_IT_RXDAVL                      ((uint32_t)0x00200000)
219→#define SDIO_IT_SDIOIT                      ((uint32_t)0x00400000)
220→#define SDIO_IT_CEATAEND                    ((uint32_t)0x00800000)
221→#define IS_SDIO_IT(IT) ((((IT) & (uint32_t)0xFF000000) == 0x00) && ((IT) != (uint32_t)0x00))
222→/**
223→  * @}
224→  */ 
225→
226→/** @defgroup SDIO_Command_Index
227→  * @{
228→  */
229→
230→#define IS_SDIO_CMD_INDEX(INDEX)            ((INDEX) < 0x40)
231→/**
232→  * @}
233→  */
234→
235→/** @defgroup SDIO_Response_Type 
236→  * @{
237→  */
238→
239→#define SDIO_Response_No                    ((uint32_t)0x00000000)
240→#define SDIO_Response_Short                 ((uint32_t)0x00000040)
241→#define SDIO_Response_Long                  ((uint32_t)0x000000C0)
242→#define IS_SDIO_RESPONSE(RESPONSE) (((RESPONSE) == SDIO_Response_No) || \
243→                                    ((RESPONSE) == SDIO_Response_Short) || \
244→                                    ((RESPONSE) == SDIO_Response_Long))
245→/**
246→  * @}
247→  */
248→
249→/** @defgroup SDIO_Wait_Interrupt_State 
250→  * @{
251→  */
252→
253→#define SDIO_Wait_No                        ((uint32_t)0x00000000) /*!< SDIO No Wait, TimeOut is enabled */
254→#define SDIO_Wait_IT                        ((uint32_t)0x00000100) /*!< SDIO Wait Interrupt Request */
255→#define SDIO_Wait_Pend                      ((uint32_t)0x00000200) /*!< SDIO Wait End of transfer */
256→#define IS_SDIO_WAIT(WAIT) (((WAIT) == SDIO_Wait_No) || ((WAIT) == SDIO_Wait_IT) || \
257→                            ((WAIT) == SDIO_Wait_Pend))
258→/**
259→  * @}
260→  */
261→
262→/** @defgroup SDIO_CPSM_State 
263→  * @{
264→  */
265→
266→#define SDIO_CPSM_Disable                    ((uint32_t)0x00000000)
267→#define SDIO_CPSM_Enable                     ((uint32_t)0x00000400)
268→#define IS_SDIO_CPSM(CPSM) (((CPSM) == SDIO_CPSM_Enable) || ((CPSM) == SDIO_CPSM_Disable))
269→/**
270→  * @}
271→  */ 
272→
273→/** @defgroup SDIO_Response_Registers 
274→  * @{
275→  */
276→
277→#define SDIO_RESP1                          ((uint32_t)0x00000000)
278→#define SDIO_RESP2                          ((uint32_t)0x00000004)
279→#define SDIO_RESP3                          ((uint32_t)0x00000008)
280→#define SDIO_RESP4                          ((uint32_t)0x0000000C)
281→#define IS_SDIO_RESP(RESP) (((RESP) == SDIO_RESP1) || ((RESP) == SDIO_RESP2) || \
282→                            ((RESP) == SDIO_RESP3) || ((RESP) == SDIO_RESP4))
283→/**
284→  * @}
285→  */
286→
287→/** @defgroup SDIO_Data_Length 
288→  * @{
289→  */
290→
291→#define IS_SDIO_DATA_LENGTH(LENGTH) ((LENGTH) <= 0x01FFFFFF)
292→/**
293→  * @}
294→  */
295→
296→/** @defgroup SDIO_Data_Block_Size 
297→  * @{
298→  */
299→
300→#define SDIO_DataBlockSize_1b               ((uint32_t)0x00000000)
301→#define SDIO_DataBlockSize_2b               ((uint32_t)0x00000010)
302→#define SDIO_DataBlockSize_4b               ((uint32_t)0x00000020)
303→#define SDIO_DataBlockSize_8b               ((uint32_t)0x00000030)
304→#define SDIO_DataBlockSize_16b              ((uint32_t)0x00000040)
305→#define SDIO_DataBlockSize_32b              ((uint32_t)0x00000050)
306→#define SDIO_DataBlockSize_64b              ((uint32_t)0x00000060)
307→#define SDIO_DataBlockSize_128b             ((uint32_t)0x00000070)
308→#define SDIO_DataBlockSize_256b             ((uint32_t)0x00000080)
309→#define SDIO_DataBlockSize_512b             ((uint32_t)0x00000090)
310→#define SDIO_DataBlockSize_1024b            ((uint32_t)0x000000A0)
311→#define SDIO_DataBlockSize_2048b            ((uint32_t)0x000000B0)
312→#define SDIO_DataBlockSize_4096b            ((uint32_t)0x000000C0)
313→#define SDIO_DataBlockSize_8192b            ((uint32_t)0x000000D0)
314→#define SDIO_DataBlockSize_16384b           ((uint32_t)0x000000E0)
315→#define IS_SDIO_BLOCK_SIZE(SIZE) (((SIZE) == SDIO_DataBlockSize_1b) || \
316→                                  ((SIZE) == SDIO_DataBlockSize_2b) || \
317→                                  ((SIZE) == SDIO_DataBlockSize_4b) || \
318→                                  ((SIZE) == SDIO_DataBlockSize_8b) || \
319→                                  ((SIZE) == SDIO_DataBlockSize_16b) || \
320→                                  ((SIZE) == SDIO_DataBlockSize_32b) || \
321→                                  ((SIZE) == SDIO_DataBlockSize_64b) || \
322→                                  ((SIZE) == SDIO_DataBlockSize_128b) || \
323→                                  ((SIZE) == SDIO_DataBlockSize_256b) || \
324→                                  ((SIZE) == SDIO_DataBlockSize_512b) || \
325→                                  ((SIZE) == SDIO_DataBlockSize_1024b) || \
326→                                  ((SIZE) == SDIO_DataBlockSize_2048b) || \
327→                                  ((SIZE) == SDIO_DataBlockSize_4096b) || \
328→                                  ((SIZE) == SDIO_DataBlockSize_8192b) || \
329→                                  ((SIZE) == SDIO_DataBlockSize_16384b)) 
330→/**
331→  * @}
332→  */
333→
334→/** @defgroup SDIO_Transfer_Direction 
335→  * @{
336→  */
337→
338→#define SDIO_TransferDir_ToCard             ((uint32_t)0x00000000)
339→#define SDIO_TransferDir_ToSDIO             ((uint32_t)0x00000002)
340→#define IS_SDIO_TRANSFER_DIR(DIR) (((DIR) == SDIO_TransferDir_ToCard) || \
341→                                   ((DIR) == SDIO_TransferDir_ToSDIO))
342→/**
343→  * @}
344→  */
345→
346→/** @defgroup SDIO_Transfer_Type 
347→  * @{
348→  */
349→
350→#define SDIO_TransferMode_Block             ((uint32_t)0x00000000)
351→#define SDIO_TransferMode_Stream            ((uint32_t)0x00000004)
352→#define IS_SDIO_TRANSFER_MODE(MODE) (((MODE) == SDIO_TransferMode_Stream) || \
353→                                     ((MODE) == SDIO_TransferMode_Block))
354→/**
355→  * @}
356→  */
357→
358→/** @defgroup SDIO_DPSM_State 
359→  * @{
360→  */
361→
362→#define SDIO_DPSM_Disable                    ((uint32_t)0x00000000)
363→#define SDIO_DPSM_Enable                     ((uint32_t)0x00000001)
364→#define IS_SDIO_DPSM(DPSM) (((DPSM) == SDIO_DPSM_Enable) || ((DPSM) == SDIO_DPSM_Disable))
365→/**
366→  * @}
367→  */
368→
369→/** @defgroup SDIO_Flags 
370→  * @{
371→  */
372→
373→#define SDIO_FLAG_CCRCFAIL                  ((uint32_t)0x00000001)
374→#define SDIO_FLAG_DCRCFAIL                  ((uint32_t)0x00000002)
375→#define SDIO_FLAG_CTIMEOUT                  ((uint32_t)0x00000004)
376→#define SDIO_FLAG_DTIMEOUT                  ((uint32_t)0x00000008)
377→#define SDIO_FLAG_TXUNDERR                  ((uint32_t)0x00000010)
378→#define SDIO_FLAG_RXOVERR                   ((uint32_t)0x00000020)
379→#define SDIO_FLAG_CMDREND                   ((uint32_t)0x00000040)
380→#define SDIO_FLAG_CMDSENT                   ((uint32_t)0x00000080)
381→#define SDIO_FLAG_DATAEND                   ((uint32_t)0x00000100)
382→#define SDIO_FLAG_STBITERR                  ((uint32_t)0x00000200)
383→#define SDIO_FLAG_DBCKEND                   ((uint32_t)0x00000400)
384→#define SDIO_FLAG_CMDACT                    ((uint32_t)0x00000800)
385→#define SDIO_FLAG_TXACT                     ((uint32_t)0x00001000)
386→#define SDIO_FLAG_RXACT                     ((uint32_t)0x00002000)
387→#define SDIO_FLAG_TXFIFOHE                  ((uint32_t)0x00004000)
388→#define SDIO_FLAG_RXFIFOHF                  ((uint32_t)0x00008000)
389→#define SDIO_FLAG_TXFIFOF                   ((uint32_t)0x00010000)
390→#define SDIO_FLAG_RXFIFOF                   ((uint32_t)0x00020000)
391→#define SDIO_FLAG_TXFIFOE                   ((uint32_t)0x00040000)
392→#define SDIO_FLAG_RXFIFOE                   ((uint32_t)0x00080000)
393→#define SDIO_FLAG_TXDAVL                    ((uint32_t)0x00100000)
394→#define SDIO_FLAG_RXDAVL                    ((uint32_t)0x00200000)
395→#define SDIO_FLAG_SDIOIT                    ((uint32_t)0x00400000)
396→#define SDIO_FLAG_CEATAEND                  ((uint32_t)0x00800000)
397→#define IS_SDIO_FLAG(FLAG) (((FLAG)  == SDIO_FLAG_CCRCFAIL) || \
398→                            ((FLAG)  == SDIO_FLAG_DCRCFAIL) || \
399→                            ((FLAG)  == SDIO_FLAG_CTIMEOUT) || \
400→                            ((FLAG)  == SDIO_FLAG_DTIMEOUT) || \
401→                            ((FLAG)  == SDIO_FLAG_TXUNDERR) || \
402→                            ((FLAG)  == SDIO_FLAG_RXOVERR) || \
403→                            ((FLAG)  == SDIO_FLAG_CMDREND) || \
404→                            ((FLAG)  == SDIO_FLAG_CMDSENT) || \
405→                            ((FLAG)  == SDIO_FLAG_DATAEND) || \
406→                            ((FLAG)  == SDIO_FLAG_STBITERR) || \
407→                            ((FLAG)  == SDIO_FLAG_DBCKEND) || \
408→                            ((FLAG)  == SDIO_FLAG_CMDACT) || \
409→                            ((FLAG)  == SDIO_FLAG_TXACT) || \
410→                            ((FLAG)  == SDIO_FLAG_RXACT) || \
411→                            ((FLAG)  == SDIO_FLAG_TXFIFOHE) || \
412→                            ((FLAG)  == SDIO_FLAG_RXFIFOHF) || \
413→                            ((FLAG)  == SDIO_FLAG_TXFIFOF) || \
414→                            ((FLAG)  == SDIO_FLAG_RXFIFOF) || \
415→                            ((FLAG)  == SDIO_FLAG_TXFIFOE) || \
416→                            ((FLAG)  == SDIO_FLAG_RXFIFOE) || \
417→                            ((FLAG)  == SDIO_FLAG_TXDAVL) || \
418→                            ((FLAG)  == SDIO_FLAG_RXDAVL) || \
419→                            ((FLAG)  == SDIO_FLAG_SDIOIT) || \
420→                            ((FLAG)  == SDIO_FLAG_CEATAEND))
421→
422→#define IS_SDIO_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFF3FF800) == 0x00) && ((FLAG) != (uint32_t)0x00))
423→
424→#define IS_SDIO_GET_IT(IT) (((IT)  == SDIO_IT_CCRCFAIL) || \
425→                            ((IT)  == SDIO_IT_DCRCFAIL) || \
426→                            ((IT)  == SDIO_IT_CTIMEOUT) || \
427→                            ((IT)  == SDIO_IT_DTIMEOUT) || \
428→                            ((IT)  == SDIO_IT_TXUNDERR) || \
429→                            ((IT)  == SDIO_IT_RXOVERR) || \
430→                            ((IT)  == SDIO_IT_CMDREND) || \
431→                            ((IT)  == SDIO_IT_CMDSENT) || \
432→                            ((IT)  == SDIO_IT_DATAEND) || \
433→                            ((IT)  == SDIO_IT_STBITERR) || \
434→                            ((IT)  == SDIO_IT_DBCKEND) || \
435→                            ((IT)  == SDIO_IT_CMDACT) || \
436→                            ((IT)  == SDIO_IT_TXACT) || \
437→                            ((IT)  == SDIO_IT_RXACT) || \
438→                            ((IT)  == SDIO_IT_TXFIFOHE) || \
439→                            ((IT)  == SDIO_IT_RXFIFOHF) || \
440→                            ((IT)  == SDIO_IT_TXFIFOF) || \
441→                            ((IT)  == SDIO_IT_RXFIFOF) || \
442→                            ((IT)  == SDIO_IT_TXFIFOE) || \
443→                            ((IT)  == SDIO_IT_RXFIFOE) || \
444→                            ((IT)  == SDIO_IT_TXDAVL) || \
445→                            ((IT)  == SDIO_IT_RXDAVL) || \
446→                            ((IT)  == SDIO_IT_SDIOIT) || \
447→                            ((IT)  == SDIO_IT_CEATAEND))
448→
449→#define IS_SDIO_CLEAR_IT(IT) ((((IT) & (uint32_t)0xFF3FF800) == 0x00) && ((IT) != (uint32_t)0x00))
450→
451→/**
452→  * @}
453→  */
454→
455→/** @defgroup SDIO_Read_Wait_Mode 
456→  * @{
457→  */
458→
459→#define SDIO_ReadWaitMode_CLK               ((uint32_t)0x00000001)
460→#define SDIO_ReadWaitMode_DATA2             ((uint32_t)0x00000000)
461→#define IS_SDIO_READWAIT_MODE(MODE) (((MODE) == SDIO_ReadWaitMode_CLK) || \
462→                                     ((MODE) == SDIO_ReadWaitMode_DATA2))
463→/**
464→  * @}
465→  */
466→
467→/**
468→  * @}
469→  */
470→
471→/** @defgroup SDIO_Exported_Macros
472→  * @{
473→  */
474→
475→/**
476→  * @}
477→  */
478→
479→/** @defgroup SDIO_Exported_Functions
480→  * @{
481→  */
482→
483→void SDIO_DeInit(void);
484→void SDIO_Init(SDIO_InitTypeDef* SDIO_InitStruct);
485→void SDIO_StructInit(SDIO_InitTypeDef* SDIO_InitStruct);
486→void SDIO_ClockCmd(FunctionalState NewState);
487→void SDIO_SetPowerState(uint32_t SDIO_PowerState);
488→uint32_t SDIO_GetPowerState(void);
489→void SDIO_ITConfig(uint32_t SDIO_IT, FunctionalState NewState);
490→void SDIO_DMACmd(FunctionalState NewState);
491→void SDIO_SendCommand(SDIO_CmdInitTypeDef *SDIO_CmdInitStruct);
492→void SDIO_CmdStructInit(SDIO_CmdInitTypeDef* SDIO_CmdInitStruct);
493→uint8_t SDIO_GetCommandResponse(void);
494→uint32_t SDIO_GetResponse(uint32_t SDIO_RESP);
495→void SDIO_DataConfig(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
496→void SDIO_DataStructInit(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
497→uint32_t SDIO_GetDataCounter(void);
498→uint32_t SDIO_ReadData(void);
499→void SDIO_WriteData(uint32_t Data);
500→uint32_t SDIO_GetFIFOCount(void);
501→void SDIO_StartSDIOReadWait(FunctionalState NewState);
502→void SDIO_StopSDIOReadWait(FunctionalState NewState);
503→void SDIO_SetSDIOReadWaitMode(uint32_t SDIO_ReadWaitMode);
504→void SDIO_SetSDIOOperation(FunctionalState NewState);
505→void SDIO_SendSDIOSuspendCmd(FunctionalState NewState);
506→void SDIO_CommandCompletionCmd(FunctionalState NewState);
507→void SDIO_CEATAITCmd(FunctionalState NewState);
508→void SDIO_SendCEATACmd(FunctionalState NewState);
509→FlagStatus SDIO_GetFlagStatus(uint32_t SDIO_FLAG);
510→void SDIO_ClearFlag(uint32_t SDIO_FLAG);
511→ITStatus SDIO_GetITStatus(uint32_t SDIO_IT);
512→void SDIO_ClearITPendingBit(uint32_t SDIO_IT);
513→
514→#ifdef __cplusplus
515→}
516→#endif
517→
518→#endif /* __STM32F10x_SDIO_H */
519→/**
520→  * @}
521→  */
522→
523→/**
524→  * @}
525→  */
526→
527→/**
528→  * @}
529→  */
530→
531→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/