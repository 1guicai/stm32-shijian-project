  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_fsmc.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the FSMC firmware 
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
 24→#ifndef __STM32F10x_FSMC_H
 25→#define __STM32F10x_FSMC_H
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
 38→/** @addtogroup FSMC
 39→  * @{
 40→  */
 41→
 42→/** @defgroup FSMC_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  Timing parameters For NOR/SRAM Banks  
 48→  */
 49→
 50→typedef struct
 51→{
 52→  uint32_t FSMC_AddressSetupTime;       /*!< Defines the number of HCLK cycles to configure
 53→                                             the duration of the address setup time. 
 54→                                             This parameter can be a value between 0 and 0xF.
 55→                                             @note: It is not used with synchronous NOR Flash memories. */
 56→
 57→  uint32_t FSMC_AddressHoldTime;        /*!< Defines the number of HCLK cycles to configure
 58→                                             the duration of the address hold time.
 59→                                             This parameter can be a value between 0 and 0xF. 
 60→                                             @note: It is not used with synchronous NOR Flash memories.*/
 61→
 62→  uint32_t FSMC_DataSetupTime;          /*!< Defines the number of HCLK cycles to configure
 63→                                             the duration of the data setup time.
 64→                                             This parameter can be a value between 0 and 0xFF.
 65→                                             @note: It is used for SRAMs, ROMs and asynchronous multiplexed NOR Flash memories. */
 66→
 67→  uint32_t FSMC_BusTurnAroundDuration;  /*!< Defines the number of HCLK cycles to configure
 68→                                             the duration of the bus turnaround.
 69→                                             This parameter can be a value between 0 and 0xF.
 70→                                             @note: It is only used for multiplexed NOR Flash memories. */
 71→
 72→  uint32_t FSMC_CLKDivision;            /*!< Defines the period of CLK clock output signal, expressed in number of HCLK cycles.
 73→                                             This parameter can be a value between 1 and 0xF.
 74→                                             @note: This parameter is not used for asynchronous NOR Flash, SRAM or ROM accesses. */
 75→
 76→  uint32_t FSMC_DataLatency;            /*!< Defines the number of memory clock cycles to issue
 77→                                             to the memory before getting the first data.
 78→                                             The value of this parameter depends on the memory type as shown below:
 79→                                              - It must be set to 0 in case of a CRAM
 80→                                              - It is don't care in asynchronous NOR, SRAM or ROM accesses
 81→                                              - It may assume a value between 0 and 0xF in NOR Flash memories
 82→                                                with synchronous burst mode enable */
 83→
 84→  uint32_t FSMC_AccessMode;             /*!< Specifies the asynchronous access mode. 
 85→                                             This parameter can be a value of @ref FSMC_Access_Mode */
 86→}FSMC_NORSRAMTimingInitTypeDef;
 87→
 88→/** 
 89→  * @brief  FSMC NOR/SRAM Init structure definition
 90→  */
 91→
 92→typedef struct
 93→{
 94→  uint32_t FSMC_Bank;                /*!< Specifies the NOR/SRAM memory bank that will be used.
 95→                                          This parameter can be a value of @ref FSMC_NORSRAM_Bank */
 96→
 97→  uint32_t FSMC_DataAddressMux;      /*!< Specifies whether the address and data values are
 98→                                          multiplexed on the databus or not. 
 99→                                          This parameter can be a value of @ref FSMC_Data_Address_Bus_Multiplexing */
100→
101→  uint32_t FSMC_MemoryType;          /*!< Specifies the type of external memory attached to
102→                                          the corresponding memory bank.
103→                                          This parameter can be a value of @ref FSMC_Memory_Type */
104→
105→  uint32_t FSMC_MemoryDataWidth;     /*!< Specifies the external memory device width.
106→                                          This parameter can be a value of @ref FSMC_Data_Width */
107→
108→  uint32_t FSMC_BurstAccessMode;     /*!< Enables or disables the burst access mode for Flash memory,
109→                                          valid only with synchronous burst Flash memories.
110→                                          This parameter can be a value of @ref FSMC_Burst_Access_Mode */
111→                                       
112→  uint32_t FSMC_AsynchronousWait;     /*!< Enables or disables wait signal during asynchronous transfers,
113→                                          valid only with asynchronous Flash memories.
114→                                          This parameter can be a value of @ref FSMC_AsynchronousWait */
115→
116→  uint32_t FSMC_WaitSignalPolarity;  /*!< Specifies the wait signal polarity, valid only when accessing
117→                                          the Flash memory in burst mode.
118→                                          This parameter can be a value of @ref FSMC_Wait_Signal_Polarity */
119→
120→  uint32_t FSMC_WrapMode;            /*!< Enables or disables the Wrapped burst access mode for Flash
121→                                          memory, valid only when accessing Flash memories in burst mode.
122→                                          This parameter can be a value of @ref FSMC_Wrap_Mode */
123→
124→  uint32_t FSMC_WaitSignalActive;    /*!< Specifies if the wait signal is asserted by the memory one
125→                                          clock cycle before the wait state or during the wait state,
126→                                          valid only when accessing memories in burst mode. 
127→                                          This parameter can be a value of @ref FSMC_Wait_Timing */
128→
129→  uint32_t FSMC_WriteOperation;      /*!< Enables or disables the write operation in the selected bank by the FSMC. 
130→                                          This parameter can be a value of @ref FSMC_Write_Operation */
131→
132→  uint32_t FSMC_WaitSignal;          /*!< Enables or disables the wait-state insertion via wait
133→                                          signal, valid for Flash memory access in burst mode. 
134→                                          This parameter can be a value of @ref FSMC_Wait_Signal */
135→
136→  uint32_t FSMC_ExtendedMode;        /*!< Enables or disables the extended mode.
137→                                          This parameter can be a value of @ref FSMC_Extended_Mode */
138→
139→  uint32_t FSMC_WriteBurst;          /*!< Enables or disables the write burst operation.
140→                                          This parameter can be a value of @ref FSMC_Write_Burst */ 
141→
142→  FSMC_NORSRAMTimingInitTypeDef* FSMC_ReadWriteTimingStruct; /*!< Timing Parameters for write and read access if the  ExtendedMode is not used*/  
143→
144→  FSMC_NORSRAMTimingInitTypeDef* FSMC_WriteTimingStruct;     /*!< Timing Parameters for write access if the  ExtendedMode is used*/      
145→}FSMC_NORSRAMInitTypeDef;
146→
147→/** 
148→  * @brief  Timing parameters For FSMC NAND and PCCARD Banks
149→  */
150→
151→typedef struct
152→{
153→  uint32_t FSMC_SetupTime;      /*!< Defines the number of HCLK cycles to setup address before
154→                                     the command assertion for NAND-Flash read or write access
155→                                     to common/Attribute or I/O memory space (depending on
156→                                     the memory space timing to be configured).
157→                                     This parameter can be a value between 0 and 0xFF.*/
158→
159→  uint32_t FSMC_WaitSetupTime;  /*!< Defines the minimum number of HCLK cycles to assert the
160→                                     command for NAND-Flash read or write access to
161→                                     common/Attribute or I/O memory space (depending on the
162→                                     memory space timing to be configured). 
163→                                     This parameter can be a number between 0x00 and 0xFF */
164→
165→  uint32_t FSMC_HoldSetupTime;  /*!< Defines the number of HCLK clock cycles to hold address
166→                                     (and data for write access) after the command deassertion
167→                                     for NAND-Flash read or write access to common/Attribute
168→                                     or I/O memory space (depending on the memory space timing
169→                                     to be configured).
170→                                     This parameter can be a number between 0x00 and 0xFF */
171→
172→  uint32_t FSMC_HiZSetupTime;   /*!< Defines the number of HCLK clock cycles during which the
173→                                     databus is kept in HiZ after the start of a NAND-Flash
174→                                     write access to common/Attribute or I/O memory space (depending
175→                                     on the memory space timing to be configured).
176→                                     This parameter can be a number between 0x00 and 0xFF */
177→}FSMC_NAND_PCCARDTimingInitTypeDef;
178→
179→/** 
180→  * @brief  FSMC NAND Init structure definition
181→  */
182→
183→typedef struct
184→{
185→  uint32_t FSMC_Bank;              /*!< Specifies the NAND memory bank that will be used.
186→                                      This parameter can be a value of @ref FSMC_NAND_Bank */
187→
188→  uint32_t FSMC_Waitfeature;      /*!< Enables or disables the Wait feature for the NAND Memory Bank.
189→                                       This parameter can be any value of @ref FSMC_Wait_feature */
190→
191→  uint32_t FSMC_MemoryDataWidth;  /*!< Specifies the external memory device width.
192→                                       This parameter can be any value of @ref FSMC_Data_Width */
193→
194→  uint32_t FSMC_ECC;              /*!< Enables or disables the ECC computation.
195→                                       This parameter can be any value of @ref FSMC_ECC */
196→
197→  uint32_t FSMC_ECCPageSize;      /*!< Defines the page size for the extended ECC.
198→                                       This parameter can be any value of @ref FSMC_ECC_Page_Size */
199→
200→  uint32_t FSMC_TCLRSetupTime;    /*!< Defines the number of HCLK cycles to configure the
201→                                       delay between CLE low and RE low.
202→                                       This parameter can be a value between 0 and 0xFF. */
203→
204→  uint32_t FSMC_TARSetupTime;     /*!< Defines the number of HCLK cycles to configure the
205→                                       delay between ALE low and RE low.
206→                                       This parameter can be a number between 0x0 and 0xFF */ 
207→
208→  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;   /*!< FSMC Common Space Timing */ 
209→
210→  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct; /*!< FSMC Attribute Space Timing */
211→}FSMC_NANDInitTypeDef;
212→
213→/** 
214→  * @brief  FSMC PCCARD Init structure definition
215→  */
216→
217→typedef struct
218→{
219→  uint32_t FSMC_Waitfeature;    /*!< Enables or disables the Wait feature for the Memory Bank.
220→                                    This parameter can be any value of @ref FSMC_Wait_feature */
221→
222→  uint32_t FSMC_TCLRSetupTime;  /*!< Defines the number of HCLK cycles to configure the
223→                                     delay between CLE low and RE low.
224→                                     This parameter can be a value between 0 and 0xFF. */
225→
226→  uint32_t FSMC_TARSetupTime;   /*!< Defines the number of HCLK cycles to configure the
227→                                     delay between ALE low and RE low.
228→                                     This parameter can be a number between 0x0 and 0xFF */ 
229→
230→  
231→  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct; /*!< FSMC Common Space Timing */
232→
233→  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;  /*!< FSMC Attribute Space Timing */ 
234→  
235→  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_IOSpaceTimingStruct; /*!< FSMC IO Space Timing */  
236→}FSMC_PCCARDInitTypeDef;
237→
238→/**
239→  * @}
240→  */
241→
242→/** @defgroup FSMC_Exported_Constants
243→  * @{
244→  */
245→
246→/** @defgroup FSMC_NORSRAM_Bank 
247→  * @{
248→  */
249→#define FSMC_Bank1_NORSRAM1                             ((uint32_t)0x00000000)
250→#define FSMC_Bank1_NORSRAM2                             ((uint32_t)0x00000002)
251→#define FSMC_Bank1_NORSRAM3                             ((uint32_t)0x00000004)
252→#define FSMC_Bank1_NORSRAM4                             ((uint32_t)0x00000006)
253→/**
254→  * @}
255→  */
256→
257→/** @defgroup FSMC_NAND_Bank 
258→  * @{
259→  */  
260→#define FSMC_Bank2_NAND                                 ((uint32_t)0x00000010)
261→#define FSMC_Bank3_NAND                                 ((uint32_t)0x00000100)
262→/**
263→  * @}
264→  */
265→
266→/** @defgroup FSMC_PCCARD_Bank 
267→  * @{
268→  */    
269→#define FSMC_Bank4_PCCARD                               ((uint32_t)0x00001000)
270→/**
271→  * @}
272→  */
273→
274→#define IS_FSMC_NORSRAM_BANK(BANK) (((BANK) == FSMC_Bank1_NORSRAM1) || \
275→                                    ((BANK) == FSMC_Bank1_NORSRAM2) || \
276→                                    ((BANK) == FSMC_Bank1_NORSRAM3) || \
277→                                    ((BANK) == FSMC_Bank1_NORSRAM4))
278→
279→#define IS_FSMC_NAND_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
280→                                 ((BANK) == FSMC_Bank3_NAND))
281→
282→#define IS_FSMC_GETFLAG_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
283→                                    ((BANK) == FSMC_Bank3_NAND) || \
284→                                    ((BANK) == FSMC_Bank4_PCCARD))
285→
286→#define IS_FSMC_IT_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
287→                               ((BANK) == FSMC_Bank3_NAND) || \
288→                               ((BANK) == FSMC_Bank4_PCCARD))
289→
290→/** @defgroup NOR_SRAM_Controller 
291→  * @{
292→  */
293→
294→/** @defgroup FSMC_Data_Address_Bus_Multiplexing 
295→  * @{
296→  */
297→
298→#define FSMC_DataAddressMux_Disable                       ((uint32_t)0x00000000)
299→#define FSMC_DataAddressMux_Enable                        ((uint32_t)0x00000002)
300→#define IS_FSMC_MUX(MUX) (((MUX) == FSMC_DataAddressMux_Disable) || \
301→                          ((MUX) == FSMC_DataAddressMux_Enable))
302→
303→/**
304→  * @}
305→  */
306→
307→/** @defgroup FSMC_Memory_Type 
308→  * @{
309→  */
310→
311→#define FSMC_MemoryType_SRAM                            ((uint32_t)0x00000000)
312→#define FSMC_MemoryType_PSRAM                           ((uint32_t)0x00000004)
313→#define FSMC_MemoryType_NOR                             ((uint32_t)0x00000008)
314→#define IS_FSMC_MEMORY(MEMORY) (((MEMORY) == FSMC_MemoryType_SRAM) || \
315→                                ((MEMORY) == FSMC_MemoryType_PSRAM)|| \
316→                                ((MEMORY) == FSMC_MemoryType_NOR))
317→
318→/**
319→  * @}
320→  */
321→
322→/** @defgroup FSMC_Data_Width 
323→  * @{
324→  */
325→
326→#define FSMC_MemoryDataWidth_8b                         ((uint32_t)0x00000000)
327→#define FSMC_MemoryDataWidth_16b                        ((uint32_t)0x00000010)
328→#define IS_FSMC_MEMORY_WIDTH(WIDTH) (((WIDTH) == FSMC_MemoryDataWidth_8b) || \
329→                                     ((WIDTH) == FSMC_MemoryDataWidth_16b))
330→
331→/**
332→  * @}
333→  */
334→
335→/** @defgroup FSMC_Burst_Access_Mode 
336→  * @{
337→  */
338→
339→#define FSMC_BurstAccessMode_Disable                    ((uint32_t)0x00000000) 
340→#define FSMC_BurstAccessMode_Enable                     ((uint32_t)0x00000100)
341→#define IS_FSMC_BURSTMODE(STATE) (((STATE) == FSMC_BurstAccessMode_Disable) || \
342→                                  ((STATE) == FSMC_BurstAccessMode_Enable))
343→/**
344→  * @}
345→  */
346→  
347→/** @defgroup FSMC_AsynchronousWait 
348→  * @{
349→  */
350→#define FSMC_AsynchronousWait_Disable                   ((uint32_t)0x00000000)
351→#define FSMC_AsynchronousWait_Enable                    ((uint32_t)0x00008000)
352→#define IS_FSMC_ASYNWAIT(STATE) (((STATE) == FSMC_AsynchronousWait_Disable) || \
353→                                 ((STATE) == FSMC_AsynchronousWait_Enable))
354→
355→/**
356→  * @}
357→  */
358→  
359→/** @defgroup FSMC_Wait_Signal_Polarity 
360→  * @{
361→  */
362→
363→#define FSMC_WaitSignalPolarity_Low                     ((uint32_t)0x00000000)
364→#define FSMC_WaitSignalPolarity_High                    ((uint32_t)0x00000200)
365→#define IS_FSMC_WAIT_POLARITY(POLARITY) (((POLARITY) == FSMC_WaitSignalPolarity_Low) || \
366→                                         ((POLARITY) == FSMC_WaitSignalPolarity_High)) 
367→
368→/**
369→  * @}
370→  */
371→
372→/** @defgroup FSMC_Wrap_Mode 
373→  * @{
374→  */
375→
376→#define FSMC_WrapMode_Disable                           ((uint32_t)0x00000000)
377→#define FSMC_WrapMode_Enable                            ((uint32_t)0x00000400) 
378→#define IS_FSMC_WRAP_MODE(MODE) (((MODE) == FSMC_WrapMode_Disable) || \
379→                                 ((MODE) == FSMC_WrapMode_Enable))
380→
381→/**
382→  * @}
383→  */
384→
385→/** @defgroup FSMC_Wait_Timing 
386→  * @{
387→  */
388→
389→#define FSMC_WaitSignalActive_BeforeWaitState           ((uint32_t)0x00000000)
390→#define FSMC_WaitSignalActive_DuringWaitState           ((uint32_t)0x00000800) 
391→#define IS_FSMC_WAIT_SIGNAL_ACTIVE(ACTIVE) (((ACTIVE) == FSMC_WaitSignalActive_BeforeWaitState) || \
392→                                            ((ACTIVE) == FSMC_WaitSignalActive_DuringWaitState))
393→
394→/**
395→  * @}
396→  */
397→
398→/** @defgroup FSMC_Write_Operation 
399→  * @{
400→  */
401→
402→#define FSMC_WriteOperation_Disable                     ((uint32_t)0x00000000)
403→#define FSMC_WriteOperation_Enable                      ((uint32_t)0x00001000)
404→#define IS_FSMC_WRITE_OPERATION(OPERATION) (((OPERATION) == FSMC_WriteOperation_Disable) || \
405→                                            ((OPERATION) == FSMC_WriteOperation_Enable))
406→                              
407→/**
408→  * @}
409→  */
410→
411→/** @defgroup FSMC_Wait_Signal 
412→  * @{
413→  */
414→
415→#define FSMC_WaitSignal_Disable                         ((uint32_t)0x00000000)
416→#define FSMC_WaitSignal_Enable                          ((uint32_t)0x00002000) 
417→#define IS_FSMC_WAITE_SIGNAL(SIGNAL) (((SIGNAL) == FSMC_WaitSignal_Disable) || \
418→                                      ((SIGNAL) == FSMC_WaitSignal_Enable))
419→/**
420→  * @}
421→  */
422→
423→/** @defgroup FSMC_Extended_Mode 
424→  * @{
425→  */
426→
427→#define FSMC_ExtendedMode_Disable                       ((uint32_t)0x00000000)
428→#define FSMC_ExtendedMode_Enable                        ((uint32_t)0x00004000)
429→
430→#define IS_FSMC_EXTENDED_MODE(MODE) (((MODE) == FSMC_ExtendedMode_Disable) || \
431→                                     ((MODE) == FSMC_ExtendedMode_Enable)) 
432→
433→/**
434→  * @}
435→  */
436→
437→/** @defgroup FSMC_Write_Burst 
438→  * @{
439→  */
440→
441→#define FSMC_WriteBurst_Disable                         ((uint32_t)0x00000000)
442→#define FSMC_WriteBurst_Enable                          ((uint32_t)0x00080000) 
443→#define IS_FSMC_WRITE_BURST(BURST) (((BURST) == FSMC_WriteBurst_Disable) || \
444→                                    ((BURST) == FSMC_WriteBurst_Enable))
445→/**
446→  * @}
447→  */
448→
449→/** @defgroup FSMC_Address_Setup_Time 
450→  * @{
451→  */
452→
453→#define IS_FSMC_ADDRESS_SETUP_TIME(TIME) ((TIME) <= 0xF)
454→
455→/**
456→  * @}
457→  */
458→
459→/** @defgroup FSMC_Address_Hold_Time 
460→  * @{
461→  */
462→
463→#define IS_FSMC_ADDRESS_HOLD_TIME(TIME) ((TIME) <= 0xF)
464→
465→/**
466→  * @}
467→  */
468→
469→/** @defgroup FSMC_Data_Setup_Time 
470→  * @{
471→  */
472→
473→#define IS_FSMC_DATASETUP_TIME(TIME) (((TIME) > 0) && ((TIME) <= 0xFF))
474→
475→/**
476→  * @}
477→  */
478→
479→/** @defgroup FSMC_Bus_Turn_around_Duration 
480→  * @{
481→  */
482→
483→#define IS_FSMC_TURNAROUND_TIME(TIME) ((TIME) <= 0xF)
484→
485→/**
486→  * @}
487→  */
488→
489→/** @defgroup FSMC_CLK_Division 
490→  * @{
491→  */
492→
493→#define IS_FSMC_CLK_DIV(DIV) ((DIV) <= 0xF)
494→
495→/**
496→  * @}
497→  */
498→
499→/** @defgroup FSMC_Data_Latency 
500→  * @{
501→  */
502→
503→#define IS_FSMC_DATA_LATENCY(LATENCY) ((LATENCY) <= 0xF)
504→
505→/**
506→  * @}
507→  */
508→
509→/** @defgroup FSMC_Access_Mode 
510→  * @{
511→  */
512→
513→#define FSMC_AccessMode_A                               ((uint32_t)0x00000000)
514→#define FSMC_AccessMode_B                               ((uint32_t)0x10000000) 
515→#define FSMC_AccessMode_C                               ((uint32_t)0x20000000)
516→#define FSMC_AccessMode_D                               ((uint32_t)0x30000000)
517→#define IS_FSMC_ACCESS_MODE(MODE) (((MODE) == FSMC_AccessMode_A) || \
518→                                   ((MODE) == FSMC_AccessMode_B) || \
519→                                   ((MODE) == FSMC_AccessMode_C) || \
520→                                   ((MODE) == FSMC_AccessMode_D)) 
521→
522→/**
523→  * @}
524→  */
525→
526→/**
527→  * @}
528→  */
529→  
530→/** @defgroup NAND_PCCARD_Controller 
531→  * @{
532→  */
533→
534→/** @defgroup FSMC_Wait_feature 
535→  * @{
536→  */
537→
538→#define FSMC_Waitfeature_Disable                        ((uint32_t)0x00000000)
539→#define FSMC_Waitfeature_Enable                         ((uint32_t)0x00000002)
540→#define IS_FSMC_WAIT_FEATURE(FEATURE) (((FEATURE) == FSMC_Waitfeature_Disable) || \
541→                                       ((FEATURE) == FSMC_Waitfeature_Enable))
542→
543→/**
544→  * @}
545→  */
546→
547→
548→/** @defgroup FSMC_ECC 
549→  * @{
550→  */
551→
552→#define FSMC_ECC_Disable                                ((uint32_t)0x00000000)
553→#define FSMC_ECC_Enable                                 ((uint32_t)0x00000040)
554→#define IS_FSMC_ECC_STATE(STATE) (((STATE) == FSMC_ECC_Disable) || \
555→                                  ((STATE) == FSMC_ECC_Enable))
556→
557→/**
558→  * @}
559→  */
560→
561→/** @defgroup FSMC_ECC_Page_Size 
562→  * @{
563→  */
564→
565→#define FSMC_ECCPageSize_256Bytes                       ((uint32_t)0x00000000)
566→#define FSMC_ECCPageSize_512Bytes                       ((uint32_t)0x00020000)
567→#define FSMC_ECCPageSize_1024Bytes                      ((uint32_t)0x00040000)
568→#define FSMC_ECCPageSize_2048Bytes                      ((uint32_t)0x00060000)
569→#define FSMC_ECCPageSize_4096Bytes                      ((uint32_t)0x00080000)
570→#define FSMC_ECCPageSize_8192Bytes                      ((uint32_t)0x000A0000)
571→#define IS_FSMC_ECCPAGE_SIZE(SIZE) (((SIZE) == FSMC_ECCPageSize_256Bytes) || \
572→                                    ((SIZE) == FSMC_ECCPageSize_512Bytes) || \
573→                                    ((SIZE) == FSMC_ECCPageSize_1024Bytes) || \
574→                                    ((SIZE) == FSMC_ECCPageSize_2048Bytes) || \
575→                                    ((SIZE) == FSMC_ECCPageSize_4096Bytes) || \
576→                                    ((SIZE) == FSMC_ECCPageSize_8192Bytes))
577→
578→/**
579→  * @}
580→  */
581→
582→/** @defgroup FSMC_TCLR_Setup_Time 
583→  * @{
584→  */
585→
586→#define IS_FSMC_TCLR_TIME(TIME) ((TIME) <= 0xFF)
587→
588→/**
589→  * @}
590→  */
591→
592→/** @defgroup FSMC_TAR_Setup_Time 
593→  * @{
594→  */
595→
596→#define IS_FSMC_TAR_TIME(TIME) ((TIME) <= 0xFF)
597→
598→/**
599→  * @}
600→  */
601→
602→/** @defgroup FSMC_Setup_Time 
603→  * @{
604→  */
605→
606→#define IS_FSMC_SETUP_TIME(TIME) ((TIME) <= 0xFF)
607→
608→/**
609→  * @}
610→  */
611→
612→/** @defgroup FSMC_Wait_Setup_Time 
613→  * @{
614→  */
615→
616→#define IS_FSMC_WAIT_TIME(TIME) ((TIME) <= 0xFF)
617→
618→/**
619→  * @}
620→  */
621→
622→/** @defgroup FSMC_Hold_Setup_Time 
623→  * @{
624→  */
625→
626→#define IS_FSMC_HOLD_TIME(TIME) ((TIME) <= 0xFF)
627→
628→/**
629→  * @}
630→  */
631→
632→/** @defgroup FSMC_HiZ_Setup_Time 
633→  * @{
634→  */
635→
636→#define IS_FSMC_HIZ_TIME(TIME) ((TIME) <= 0xFF)
637→
638→/**
639→  * @}
640→  */
641→
642→/** @defgroup FSMC_Interrupt_sources 
643→  * @{
644→  */
645→
646→#define FSMC_IT_RisingEdge                              ((uint32_t)0x00000008)
647→#define FSMC_IT_Level                                   ((uint32_t)0x00000010)
648→#define FSMC_IT_FallingEdge                             ((uint32_t)0x00000020)
649→#define IS_FSMC_IT(IT) ((((IT) & (uint32_t)0xFFFFFFC7) == 0x00000000) && ((IT) != 0x00000000))
650→#define IS_FSMC_GET_IT(IT) (((IT) == FSMC_IT_RisingEdge) || \
651→                            ((IT) == FSMC_IT_Level) || \
652→                            ((IT) == FSMC_IT_FallingEdge)) 
653→/**
654→  * @}
655→  */
656→
657→/** @defgroup FSMC_Flags 
658→  * @{
659→  */
660→
661→#define FSMC_FLAG_RisingEdge                            ((uint32_t)0x00000001)
662→#define FSMC_FLAG_Level                                 ((uint32_t)0x00000002)
663→#define FSMC_FLAG_FallingEdge                           ((uint32_t)0x00000004)
664→#define FSMC_FLAG_FEMPT                                 ((uint32_t)0x00000040)
665→#define IS_FSMC_GET_FLAG(FLAG) (((FLAG) == FSMC_FLAG_RisingEdge) || \
666→                                ((FLAG) == FSMC_FLAG_Level) || \
667→                                ((FLAG) == FSMC_FLAG_FallingEdge) || \
668→                                ((FLAG) == FSMC_FLAG_FEMPT))
669→
670→#define IS_FSMC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFFF8) == 0x00000000) && ((FLAG) != 0x00000000))
671→
672→/**
673→  * @}
674→  */
675→
676→/**
677→  * @}
678→  */
679→
680→/**
681→  * @}
682→  */
683→
684→/** @defgroup FSMC_Exported_Macros
685→  * @{
686→  */
687→
688→/**
689→  * @}
690→  */
691→
692→/** @defgroup FSMC_Exported_Functions
693→  * @{
694→  */
695→
696→void FSMC_NORSRAMDeInit(uint32_t FSMC_Bank);
697→void FSMC_NANDDeInit(uint32_t FSMC_Bank);
698→void FSMC_PCCARDDeInit(void);
699→void FSMC_NORSRAMInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
700→void FSMC_NANDInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
701→void FSMC_PCCARDInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
702→void FSMC_NORSRAMStructInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
703→void FSMC_NANDStructInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
704→void FSMC_PCCARDStructInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
705→void FSMC_NORSRAMCmd(uint32_t FSMC_Bank, FunctionalState NewState);
706→void FSMC_NANDCmd(uint32_t FSMC_Bank, FunctionalState NewState);
707→void FSMC_PCCARDCmd(FunctionalState NewState);
708→void FSMC_NANDECCCmd(uint32_t FSMC_Bank, FunctionalState NewState);
709→uint32_t FSMC_GetECC(uint32_t FSMC_Bank);
710→void FSMC_ITConfig(uint32_t FSMC_Bank, uint32_t FSMC_IT, FunctionalState NewState);
711→FlagStatus FSMC_GetFlagStatus(uint32_t FSMC_Bank, uint32_t FSMC_FLAG);
712→void FSMC_ClearFlag(uint32_t FSMC_Bank, uint32_t FSMC_FLAG);
713→ITStatus FSMC_GetITStatus(uint32_t FSMC_Bank, uint32_t FSMC_IT);
714→void FSMC_ClearITPendingBit(uint32_t FSMC_Bank, uint32_t FSMC_IT);
715→
716→#ifdef __cplusplus
717→}
718→#endif
719→
720→#endif /*__STM32F10x_FSMC_H */
721→/**
722→  * @}
723→  */
724→
725→/**
726→  * @}
727→  */
728→
729→/**
730→  * @}
731→  */ 
732→
733→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/