  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_can.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the CAN firmware 
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
 24→#ifndef __STM32F10x_CAN_H
 25→#define __STM32F10x_CAN_H
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
 38→/** @addtogroup CAN
 39→  * @{
 40→  */
 41→
 42→/** @defgroup CAN_Exported_Types
 43→  * @{
 44→  */
 45→
 46→#define IS_CAN_ALL_PERIPH(PERIPH) (((PERIPH) == CAN1) || \
 47→                                   ((PERIPH) == CAN2))
 48→
 49→/** 
 50→  * @brief  CAN init structure definition
 51→  */
 52→
 53→typedef struct
 54→{
 55→  uint16_t CAN_Prescaler;   /*!< Specifies the length of a time quantum. 
 56→                                 It ranges from 1 to 1024. */
 57→  
 58→  uint8_t CAN_Mode;         /*!< Specifies the CAN operating mode.
 59→                                 This parameter can be a value of 
 60→                                @ref CAN_operating_mode */
 61→
 62→  uint8_t CAN_SJW;          /*!< Specifies the maximum number of time quanta 
 63→                                 the CAN hardware is allowed to lengthen or 
 64→                                 shorten a bit to perform resynchronization.
 65→                                 This parameter can be a value of 
 66→                                 @ref CAN_synchronisation_jump_width */
 67→
 68→  uint8_t CAN_BS1;          /*!< Specifies the number of time quanta in Bit 
 69→                                 Segment 1. This parameter can be a value of 
 70→                                 @ref CAN_time_quantum_in_bit_segment_1 */
 71→
 72→  uint8_t CAN_BS2;          /*!< Specifies the number of time quanta in Bit 
 73→                                 Segment 2.
 74→                                 This parameter can be a value of 
 75→                                 @ref CAN_time_quantum_in_bit_segment_2 */
 76→  
 77→  FunctionalState CAN_TTCM; /*!< Enable or disable the time triggered 
 78→                                 communication mode. This parameter can be set 
 79→                                 either to ENABLE or DISABLE. */
 80→  
 81→  FunctionalState CAN_ABOM;  /*!< Enable or disable the automatic bus-off 
 82→                                  management. This parameter can be set either 
 83→                                  to ENABLE or DISABLE. */
 84→
 85→  FunctionalState CAN_AWUM;  /*!< Enable or disable the automatic wake-up mode. 
 86→                                  This parameter can be set either to ENABLE or 
 87→                                  DISABLE. */
 88→
 89→  FunctionalState CAN_NART;  /*!< Enable or disable the no-automatic 
 90→                                  retransmission mode. This parameter can be 
 91→                                  set either to ENABLE or DISABLE. */
 92→
 93→  FunctionalState CAN_RFLM;  /*!< Enable or disable the Receive FIFO Locked mode.
 94→                                  This parameter can be set either to ENABLE 
 95→                                  or DISABLE. */
 96→
 97→  FunctionalState CAN_TXFP;  /*!< Enable or disable the transmit FIFO priority.
 98→                                  This parameter can be set either to ENABLE 
 99→                                  or DISABLE. */
100→} CAN_InitTypeDef;
101→
102→/** 
103→  * @brief  CAN filter init structure definition
104→  */
105→
106→typedef struct
107→{
108→  uint16_t CAN_FilterIdHigh;         /*!< Specifies the filter identification number (MSBs for a 32-bit
109→                                              configuration, first one for a 16-bit configuration).
110→                                              This parameter can be a value between 0x0000 and 0xFFFF */
111→
112→  uint16_t CAN_FilterIdLow;          /*!< Specifies the filter identification number (LSBs for a 32-bit
113→                                              configuration, second one for a 16-bit configuration).
114→                                              This parameter can be a value between 0x0000 and 0xFFFF */
115→
116→  uint16_t CAN_FilterMaskIdHigh;     /*!< Specifies the filter mask number or identification number,
117→                                              according to the mode (MSBs for a 32-bit configuration,
118→                                              first one for a 16-bit configuration).
119→                                              This parameter can be a value between 0x0000 and 0xFFFF */
120→
121→  uint16_t CAN_FilterMaskIdLow;      /*!< Specifies the filter mask number or identification number,
122→                                              according to the mode (LSBs for a 32-bit configuration,
123→                                              second one for a 16-bit configuration).
124→                                              This parameter can be a value between 0x0000 and 0xFFFF */
125→
126→  uint16_t CAN_FilterFIFOAssignment; /*!< Specifies the FIFO (0 or 1) which will be assigned to the filter.
127→                                              This parameter can be a value of @ref CAN_filter_FIFO */
128→  
129→  uint8_t CAN_FilterNumber;          /*!< Specifies the filter which will be initialized. It ranges from 0 to 13. */
130→
131→  uint8_t CAN_FilterMode;            /*!< Specifies the filter mode to be initialized.
132→                                              This parameter can be a value of @ref CAN_filter_mode */
133→
134→  uint8_t CAN_FilterScale;           /*!< Specifies the filter scale.
135→                                              This parameter can be a value of @ref CAN_filter_scale */
136→
137→  FunctionalState CAN_FilterActivation; /*!< Enable or disable the filter.
138→                                              This parameter can be set either to ENABLE or DISABLE. */
139→} CAN_FilterInitTypeDef;
140→
141→/** 
142→  * @brief  CAN Tx message structure definition  
143→  */
144→
145→typedef struct
146→{
147→  uint32_t StdId;  /*!< Specifies the standard identifier.
148→                        This parameter can be a value between 0 to 0x7FF. */
149→
150→  uint32_t ExtId;  /*!< Specifies the extended identifier.
151→                        This parameter can be a value between 0 to 0x1FFFFFFF. */
152→
153→  uint8_t IDE;     /*!< Specifies the type of identifier for the message that 
154→                        will be transmitted. This parameter can be a value 
155→                        of @ref CAN_identifier_type */
156→
157→  uint8_t RTR;     /*!< Specifies the type of frame for the message that will 
158→                        be transmitted. This parameter can be a value of 
159→                        @ref CAN_remote_transmission_request */
160→
161→  uint8_t DLC;     /*!< Specifies the length of the frame that will be 
162→                        transmitted. This parameter can be a value between 
163→                        0 to 8 */
164→
165→  uint8_t Data[8]; /*!< Contains the data to be transmitted. It ranges from 0 
166→                        to 0xFF. */
167→} CanTxMsg;
168→
169→/** 
170→  * @brief  CAN Rx message structure definition  
171→  */
172→
173→typedef struct
174→{
175→  uint32_t StdId;  /*!< Specifies the standard identifier.
176→                        This parameter can be a value between 0 to 0x7FF. */
177→
178→  uint32_t ExtId;  /*!< Specifies the extended identifier.
179→                        This parameter can be a value between 0 to 0x1FFFFFFF. */
180→
181→  uint8_t IDE;     /*!< Specifies the type of identifier for the message that 
182→                        will be received. This parameter can be a value of 
183→                        @ref CAN_identifier_type */
184→
185→  uint8_t RTR;     /*!< Specifies the type of frame for the received message.
186→                        This parameter can be a value of 
187→                        @ref CAN_remote_transmission_request */
188→
189→  uint8_t DLC;     /*!< Specifies the length of the frame that will be received.
190→                        This parameter can be a value between 0 to 8 */
191→
192→  uint8_t Data[8]; /*!< Contains the data to be received. It ranges from 0 to 
193→                        0xFF. */
194→
195→  uint8_t FMI;     /*!< Specifies the index of the filter the message stored in 
196→                        the mailbox passes through. This parameter can be a 
197→                        value between 0 to 0xFF */
198→} CanRxMsg;
199→
200→/**
201→  * @}
202→  */
203→
204→/** @defgroup CAN_Exported_Constants
205→  * @{
206→  */
207→
208→/** @defgroup CAN_sleep_constants 
209→  * @{
210→  */
211→
212→#define CAN_InitStatus_Failed              ((uint8_t)0x00) /*!< CAN initialization failed */
213→#define CAN_InitStatus_Success             ((uint8_t)0x01) /*!< CAN initialization OK */
214→
215→/**
216→  * @}
217→  */
218→
219→/** @defgroup CAN_Mode 
220→  * @{
221→  */
222→
223→#define CAN_Mode_Normal             ((uint8_t)0x00)  /*!< normal mode */
224→#define CAN_Mode_LoopBack           ((uint8_t)0x01)  /*!< loopback mode */
225→#define CAN_Mode_Silent             ((uint8_t)0x02)  /*!< silent mode */
226→#define CAN_Mode_Silent_LoopBack    ((uint8_t)0x03)  /*!< loopback combined with silent mode */
227→
228→#define IS_CAN_MODE(MODE) (((MODE) == CAN_Mode_Normal) || \
229→                           ((MODE) == CAN_Mode_LoopBack)|| \
230→                           ((MODE) == CAN_Mode_Silent) || \
231→                           ((MODE) == CAN_Mode_Silent_LoopBack))
232→/**
233→  * @}
234→  */
235→
236→
237→/**
238→  * @defgroup CAN_Operating_Mode 
239→  * @{
240→  */  
241→#define CAN_OperatingMode_Initialization  ((uint8_t)0x00) /*!< Initialization mode */
242→#define CAN_OperatingMode_Normal          ((uint8_t)0x01) /*!< Normal mode */
243→#define CAN_OperatingMode_Sleep           ((uint8_t)0x02) /*!< sleep mode */
244→
245→
246→#define IS_CAN_OPERATING_MODE(MODE) (((MODE) == CAN_OperatingMode_Initialization) ||\
247→                                    ((MODE) == CAN_OperatingMode_Normal)|| \
248→																		((MODE) == CAN_OperatingMode_Sleep))
249→/**
250→  * @}
251→  */
252→  
253→/**
254→  * @defgroup CAN_Mode_Status
255→  * @{
256→  */  
257→
258→#define CAN_ModeStatus_Failed    ((uint8_t)0x00)                /*!< CAN entering the specific mode failed */
259→#define CAN_ModeStatus_Success   ((uint8_t)!CAN_ModeStatus_Failed)   /*!< CAN entering the specific mode Succeed */
260→
261→
262→/**
263→  * @}
264→  */
265→
266→/** @defgroup CAN_synchronisation_jump_width 
267→  * @{
268→  */
269→
270→#define CAN_SJW_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
271→#define CAN_SJW_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
272→#define CAN_SJW_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
273→#define CAN_SJW_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */
274→
275→#define IS_CAN_SJW(SJW) (((SJW) == CAN_SJW_1tq) || ((SJW) == CAN_SJW_2tq)|| \
276→                         ((SJW) == CAN_SJW_3tq) || ((SJW) == CAN_SJW_4tq))
277→/**
278→  * @}
279→  */
280→
281→/** @defgroup CAN_time_quantum_in_bit_segment_1 
282→  * @{
283→  */
284→
285→#define CAN_BS1_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
286→#define CAN_BS1_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
287→#define CAN_BS1_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
288→#define CAN_BS1_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */
289→#define CAN_BS1_5tq                 ((uint8_t)0x04)  /*!< 5 time quantum */
290→#define CAN_BS1_6tq                 ((uint8_t)0x05)  /*!< 6 time quantum */
291→#define CAN_BS1_7tq                 ((uint8_t)0x06)  /*!< 7 time quantum */
292→#define CAN_BS1_8tq                 ((uint8_t)0x07)  /*!< 8 time quantum */
293→#define CAN_BS1_9tq                 ((uint8_t)0x08)  /*!< 9 time quantum */
294→#define CAN_BS1_10tq                ((uint8_t)0x09)  /*!< 10 time quantum */
295→#define CAN_BS1_11tq                ((uint8_t)0x0A)  /*!< 11 time quantum */
296→#define CAN_BS1_12tq                ((uint8_t)0x0B)  /*!< 12 time quantum */
297→#define CAN_BS1_13tq                ((uint8_t)0x0C)  /*!< 13 time quantum */
298→#define CAN_BS1_14tq                ((uint8_t)0x0D)  /*!< 14 time quantum */
299→#define CAN_BS1_15tq                ((uint8_t)0x0E)  /*!< 15 time quantum */
300→#define CAN_BS1_16tq                ((uint8_t)0x0F)  /*!< 16 time quantum */
301→
302→#define IS_CAN_BS1(BS1) ((BS1) <= CAN_BS1_16tq)
303→/**
304→  * @}
305→  */
306→
307→/** @defgroup CAN_time_quantum_in_bit_segment_2 
308→  * @{
309→  */
310→
311→#define CAN_BS2_1tq                 ((uint8_t)0x00)  /*!< 1 time quantum */
312→#define CAN_BS2_2tq                 ((uint8_t)0x01)  /*!< 2 time quantum */
313→#define CAN_BS2_3tq                 ((uint8_t)0x02)  /*!< 3 time quantum */
314→#define CAN_BS2_4tq                 ((uint8_t)0x03)  /*!< 4 time quantum */
315→#define CAN_BS2_5tq                 ((uint8_t)0x04)  /*!< 5 time quantum */
316→#define CAN_BS2_6tq                 ((uint8_t)0x05)  /*!< 6 time quantum */
317→#define CAN_BS2_7tq                 ((uint8_t)0x06)  /*!< 7 time quantum */
318→#define CAN_BS2_8tq                 ((uint8_t)0x07)  /*!< 8 time quantum */
319→
320→#define IS_CAN_BS2(BS2) ((BS2) <= CAN_BS2_8tq)
321→
322→/**
323→  * @}
324→  */
325→
326→/** @defgroup CAN_clock_prescaler 
327→  * @{
328→  */
329→
330→#define IS_CAN_PRESCALER(PRESCALER) (((PRESCALER) >= 1) && ((PRESCALER) <= 1024))
331→
332→/**
333→  * @}
334→  */
335→
336→/** @defgroup CAN_filter_number 
337→  * @{
338→  */
339→#ifndef STM32F10X_CL
340→  #define IS_CAN_FILTER_NUMBER(NUMBER) ((NUMBER) <= 13)
341→#else
342→  #define IS_CAN_FILTER_NUMBER(NUMBER) ((NUMBER) <= 27)
343→#endif /* STM32F10X_CL */ 
344→/**
345→  * @}
346→  */
347→
348→/** @defgroup CAN_filter_mode 
349→  * @{
350→  */
351→
352→#define CAN_FilterMode_IdMask       ((uint8_t)0x00)  /*!< identifier/mask mode */
353→#define CAN_FilterMode_IdList       ((uint8_t)0x01)  /*!< identifier list mode */
354→
355→#define IS_CAN_FILTER_MODE(MODE) (((MODE) == CAN_FilterMode_IdMask) || \
356→                                  ((MODE) == CAN_FilterMode_IdList))
357→/**
358→  * @}
359→  */
360→
361→/** @defgroup CAN_filter_scale 
362→  * @{
363→  */
364→
365→#define CAN_FilterScale_16bit       ((uint8_t)0x00) /*!< Two 16-bit filters */
366→#define CAN_FilterScale_32bit       ((uint8_t)0x01) /*!< One 32-bit filter */
367→
368→#define IS_CAN_FILTER_SCALE(SCALE) (((SCALE) == CAN_FilterScale_16bit) || \
369→                                    ((SCALE) == CAN_FilterScale_32bit))
370→
371→/**
372→  * @}
373→  */
374→
375→/** @defgroup CAN_filter_FIFO
376→  * @{
377→  */
378→
379→#define CAN_Filter_FIFO0             ((uint8_t)0x00)  /*!< Filter FIFO 0 assignment for filter x */
380→#define CAN_Filter_FIFO1             ((uint8_t)0x01)  /*!< Filter FIFO 1 assignment for filter x */
381→#define IS_CAN_FILTER_FIFO(FIFO) (((FIFO) == CAN_FilterFIFO0) || \
382→                                  ((FIFO) == CAN_FilterFIFO1))
383→/**
384→  * @}
385→  */
386→
387→/** @defgroup Start_bank_filter_for_slave_CAN 
388→  * @{
389→  */
390→#define IS_CAN_BANKNUMBER(BANKNUMBER) (((BANKNUMBER) >= 1) && ((BANKNUMBER) <= 27))
391→/**
392→  * @}
393→  */
394→
395→/** @defgroup CAN_Tx 
396→  * @{
397→  */
398→
399→#define IS_CAN_TRANSMITMAILBOX(TRANSMITMAILBOX) ((TRANSMITMAILBOX) <= ((uint8_t)0x02))
400→#define IS_CAN_STDID(STDID)   ((STDID) <= ((uint32_t)0x7FF))
401→#define IS_CAN_EXTID(EXTID)   ((EXTID) <= ((uint32_t)0x1FFFFFFF))
402→#define IS_CAN_DLC(DLC)       ((DLC) <= ((uint8_t)0x08))
403→
404→/**
405→  * @}
406→  */
407→
408→/** @defgroup CAN_identifier_type 
409→  * @{
410→  */
411→
412→#define CAN_Id_Standard             ((uint32_t)0x00000000)  /*!< Standard Id */
413→#define CAN_Id_Extended             ((uint32_t)0x00000004)  /*!< Extended Id */
414→#define IS_CAN_IDTYPE(IDTYPE) (((IDTYPE) == CAN_Id_Standard) || \
415→                               ((IDTYPE) == CAN_Id_Extended))
416→/**
417→  * @}
418→  */
419→
420→/** @defgroup CAN_remote_transmission_request 
421→  * @{
422→  */
423→
424→#define CAN_RTR_Data                ((uint32_t)0x00000000)  /*!< Data frame */
425→#define CAN_RTR_Remote              ((uint32_t)0x00000002)  /*!< Remote frame */
426→#define IS_CAN_RTR(RTR) (((RTR) == CAN_RTR_Data) || ((RTR) == CAN_RTR_Remote))
427→
428→/**
429→  * @}
430→  */
431→
432→/** @defgroup CAN_transmit_constants 
433→  * @{
434→  */
435→
436→#define CAN_TxStatus_Failed         ((uint8_t)0x00)/*!< CAN transmission failed */
437→#define CAN_TxStatus_Ok             ((uint8_t)0x01) /*!< CAN transmission succeeded */
438→#define CAN_TxStatus_Pending        ((uint8_t)0x02) /*!< CAN transmission pending */
439→#define CAN_TxStatus_NoMailBox      ((uint8_t)0x04) /*!< CAN cell did not provide an empty mailbox */
440→
441→/**
442→  * @}
443→  */
444→
445→/** @defgroup CAN_receive_FIFO_number_constants 
446→  * @{
447→  */
448→
449→#define CAN_FIFO0                 ((uint8_t)0x00) /*!< CAN FIFO 0 used to receive */
450→#define CAN_FIFO1                 ((uint8_t)0x01) /*!< CAN FIFO 1 used to receive */
451→
452→#define IS_CAN_FIFO(FIFO) (((FIFO) == CAN_FIFO0) || ((FIFO) == CAN_FIFO1))
453→
454→/**
455→  * @}
456→  */
457→
458→/** @defgroup CAN_sleep_constants 
459→  * @{
460→  */
461→
462→#define CAN_Sleep_Failed     ((uint8_t)0x00) /*!< CAN did not enter the sleep mode */
463→#define CAN_Sleep_Ok         ((uint8_t)0x01) /*!< CAN entered the sleep mode */
464→
465→/**
466→  * @}
467→  */
468→
469→/** @defgroup CAN_wake_up_constants 
470→  * @{
471→  */
472→
473→#define CAN_WakeUp_Failed        ((uint8_t)0x00) /*!< CAN did not leave the sleep mode */
474→#define CAN_WakeUp_Ok            ((uint8_t)0x01) /*!< CAN leaved the sleep mode */
475→
476→/**
477→  * @}
478→  */
479→
480→/**
481→  * @defgroup   CAN_Error_Code_constants
482→  * @{
483→  */  
484→                                                                
485→#define CAN_ErrorCode_NoErr           ((uint8_t)0x00) /*!< No Error */ 
486→#define	CAN_ErrorCode_StuffErr        ((uint8_t)0x10) /*!< Stuff Error */ 
487→#define	CAN_ErrorCode_FormErr         ((uint8_t)0x20) /*!< Form Error */ 
488→#define	CAN_ErrorCode_ACKErr          ((uint8_t)0x30) /*!< Acknowledgment Error */ 
489→#define	CAN_ErrorCode_BitRecessiveErr ((uint8_t)0x40) /*!< Bit Recessive Error */ 
490→#define	CAN_ErrorCode_BitDominantErr  ((uint8_t)0x50) /*!< Bit Dominant Error */ 
491→#define	CAN_ErrorCode_CRCErr          ((uint8_t)0x60) /*!< CRC Error  */ 
492→#define	CAN_ErrorCode_SoftwareSetErr  ((uint8_t)0x70) /*!< Software Set Error */ 
493→
494→
495→/**
496→  * @}
497→  */
498→
499→/** @defgroup CAN_flags 
500→  * @{
501→  */
502→/* If the flag is 0x3XXXXXXX, it means that it can be used with CAN_GetFlagStatus()
503→   and CAN_ClearFlag() functions. */
504→/* If the flag is 0x1XXXXXXX, it means that it can only be used with CAN_GetFlagStatus() function.  */
505→
506→/* Transmit Flags */
507→#define CAN_FLAG_RQCP0             ((uint32_t)0x38000001) /*!< Request MailBox0 Flag */
508→#define CAN_FLAG_RQCP1             ((uint32_t)0x38000100) /*!< Request MailBox1 Flag */
509→#define CAN_FLAG_RQCP2             ((uint32_t)0x38010000) /*!< Request MailBox2 Flag */
510→
511→/* Receive Flags */
512→#define CAN_FLAG_FMP0              ((uint32_t)0x12000003) /*!< FIFO 0 Message Pending Flag */
513→#define CAN_FLAG_FF0               ((uint32_t)0x32000008) /*!< FIFO 0 Full Flag            */
514→#define CAN_FLAG_FOV0              ((uint32_t)0x32000010) /*!< FIFO 0 Overrun Flag         */
515→#define CAN_FLAG_FMP1              ((uint32_t)0x14000003) /*!< FIFO 1 Message Pending Flag */
516→#define CAN_FLAG_FF1               ((uint32_t)0x34000008) /*!< FIFO 1 Full Flag            */
517→#define CAN_FLAG_FOV1              ((uint32_t)0x34000010) /*!< FIFO 1 Overrun Flag         */
518→
519→/* Operating Mode Flags */
520→#define CAN_FLAG_WKU               ((uint32_t)0x31000008) /*!< Wake up Flag */
521→#define CAN_FLAG_SLAK              ((uint32_t)0x31000012) /*!< Sleep acknowledge Flag */
522→/* Note: When SLAK intterupt is disabled (SLKIE=0), no polling on SLAKI is possible. 
523→         In this case the SLAK bit can be polled.*/
524→
525→/* Error Flags */
526→#define CAN_FLAG_EWG               ((uint32_t)0x10F00001) /*!< Error Warning Flag   */
527→#define CAN_FLAG_EPV               ((uint32_t)0x10F00002) /*!< Error Passive Flag   */
528→#define CAN_FLAG_BOF               ((uint32_t)0x10F00004) /*!< Bus-Off Flag         */
529→#define CAN_FLAG_LEC               ((uint32_t)0x30F00070) /*!< Last error code Flag */
530→
531→#define IS_CAN_GET_FLAG(FLAG) (((FLAG) == CAN_FLAG_LEC)  || ((FLAG) == CAN_FLAG_BOF)   || \
532→                               ((FLAG) == CAN_FLAG_EPV)  || ((FLAG) == CAN_FLAG_EWG)   || \
533→                               ((FLAG) == CAN_FLAG_WKU)  || ((FLAG) == CAN_FLAG_FOV0)  || \
534→                               ((FLAG) == CAN_FLAG_FF0)  || ((FLAG) == CAN_FLAG_FMP0)  || \
535→                               ((FLAG) == CAN_FLAG_FOV1) || ((FLAG) == CAN_FLAG_FF1)   || \
536→                               ((FLAG) == CAN_FLAG_FMP1) || ((FLAG) == CAN_FLAG_RQCP2) || \
537→                               ((FLAG) == CAN_FLAG_RQCP1)|| ((FLAG) == CAN_FLAG_RQCP0) || \
538→                               ((FLAG) == CAN_FLAG_SLAK ))
539→
540→#define IS_CAN_CLEAR_FLAG(FLAG)(((FLAG) == CAN_FLAG_LEC) || ((FLAG) == CAN_FLAG_RQCP2) || \
541→                                ((FLAG) == CAN_FLAG_RQCP1)  || ((FLAG) == CAN_FLAG_RQCP0) || \
542→                                ((FLAG) == CAN_FLAG_FF0)  || ((FLAG) == CAN_FLAG_FOV0) ||\
543→                                ((FLAG) == CAN_FLAG_FF1) || ((FLAG) == CAN_FLAG_FOV1) || \
544→                                ((FLAG) == CAN_FLAG_WKU) || ((FLAG) == CAN_FLAG_SLAK))
545→/**
546→  * @}
547→  */
548→
549→  
550→/** @defgroup CAN_interrupts 
551→  * @{
552→  */
553→
554→
555→  
556→#define CAN_IT_TME                  ((uint32_t)0x00000001) /*!< Transmit mailbox empty Interrupt*/
557→
558→/* Receive Interrupts */
559→#define CAN_IT_FMP0                 ((uint32_t)0x00000002) /*!< FIFO 0 message pending Interrupt*/
560→#define CAN_IT_FF0                  ((uint32_t)0x00000004) /*!< FIFO 0 full Interrupt*/
561→#define CAN_IT_FOV0                 ((uint32_t)0x00000008) /*!< FIFO 0 overrun Interrupt*/
562→#define CAN_IT_FMP1                 ((uint32_t)0x00000010) /*!< FIFO 1 message pending Interrupt*/
563→#define CAN_IT_FF1                  ((uint32_t)0x00000020) /*!< FIFO 1 full Interrupt*/
564→#define CAN_IT_FOV1                 ((uint32_t)0x00000040) /*!< FIFO 1 overrun Interrupt*/
565→
566→/* Operating Mode Interrupts */
567→#define CAN_IT_WKU                  ((uint32_t)0x00010000) /*!< Wake-up Interrupt*/
568→#define CAN_IT_SLK                  ((uint32_t)0x00020000) /*!< Sleep acknowledge Interrupt*/
569→
570→/* Error Interrupts */
571→#define CAN_IT_EWG                  ((uint32_t)0x00000100) /*!< Error warning Interrupt*/
572→#define CAN_IT_EPV                  ((uint32_t)0x00000200) /*!< Error passive Interrupt*/
573→#define CAN_IT_BOF                  ((uint32_t)0x00000400) /*!< Bus-off Interrupt*/
574→#define CAN_IT_LEC                  ((uint32_t)0x00000800) /*!< Last error code Interrupt*/
575→#define CAN_IT_ERR                  ((uint32_t)0x00008000) /*!< Error Interrupt*/
576→
577→/* Flags named as Interrupts : kept only for FW compatibility */
578→#define CAN_IT_RQCP0   CAN_IT_TME
579→#define CAN_IT_RQCP1   CAN_IT_TME
580→#define CAN_IT_RQCP2   CAN_IT_TME
581→
582→
583→#define IS_CAN_IT(IT)        (((IT) == CAN_IT_TME) || ((IT) == CAN_IT_FMP0)  ||\
584→                             ((IT) == CAN_IT_FF0)  || ((IT) == CAN_IT_FOV0)  ||\
585→                             ((IT) == CAN_IT_FMP1) || ((IT) == CAN_IT_FF1)   ||\
586→                             ((IT) == CAN_IT_FOV1) || ((IT) == CAN_IT_EWG)   ||\
587→                             ((IT) == CAN_IT_EPV)  || ((IT) == CAN_IT_BOF)   ||\
588→                             ((IT) == CAN_IT_LEC)  || ((IT) == CAN_IT_ERR)   ||\
589→                             ((IT) == CAN_IT_WKU)  || ((IT) == CAN_IT_SLK))
590→
591→#define IS_CAN_CLEAR_IT(IT) (((IT) == CAN_IT_TME) || ((IT) == CAN_IT_FF0)    ||\
592→                             ((IT) == CAN_IT_FOV0)|| ((IT) == CAN_IT_FF1)    ||\
593→                             ((IT) == CAN_IT_FOV1)|| ((IT) == CAN_IT_EWG)    ||\
594→                             ((IT) == CAN_IT_EPV) || ((IT) == CAN_IT_BOF)    ||\
595→                             ((IT) == CAN_IT_LEC) || ((IT) == CAN_IT_ERR)    ||\
596→                             ((IT) == CAN_IT_WKU) || ((IT) == CAN_IT_SLK))
597→
598→/**
599→  * @}
600→  */
601→
602→/** @defgroup CAN_Legacy 
603→  * @{
604→  */
605→#define CANINITFAILED               CAN_InitStatus_Failed
606→#define CANINITOK                   CAN_InitStatus_Success
607→#define CAN_FilterFIFO0             CAN_Filter_FIFO0
608→#define CAN_FilterFIFO1             CAN_Filter_FIFO1
609→#define CAN_ID_STD                  CAN_Id_Standard           
610→#define CAN_ID_EXT                  CAN_Id_Extended
611→#define CAN_RTR_DATA                CAN_RTR_Data         
612→#define CAN_RTR_REMOTE              CAN_RTR_Remote
613→#define CANTXFAILE                  CAN_TxStatus_Failed
614→#define CANTXOK                     CAN_TxStatus_Ok
615→#define CANTXPENDING                CAN_TxStatus_Pending
616→#define CAN_NO_MB                   CAN_TxStatus_NoMailBox
617→#define CANSLEEPFAILED              CAN_Sleep_Failed
618→#define CANSLEEPOK                  CAN_Sleep_Ok
619→#define CANWAKEUPFAILED             CAN_WakeUp_Failed        
620→#define CANWAKEUPOK                 CAN_WakeUp_Ok        
621→
622→/**
623→  * @}
624→  */
625→
626→/**
627→  * @}
628→  */
629→
630→/** @defgroup CAN_Exported_Macros
631→  * @{
632→  */
633→
634→/**
635→  * @}
636→  */
637→
638→/** @defgroup CAN_Exported_Functions
639→  * @{
640→  */
641→/*  Function used to set the CAN configuration to the default reset state *****/ 
642→void CAN_DeInit(CAN_TypeDef* CANx);
643→
644→/* Initialization and Configuration functions *********************************/ 
645→uint8_t CAN_Init(CAN_TypeDef* CANx, CAN_InitTypeDef* CAN_InitStruct);
646→void CAN_FilterInit(CAN_FilterInitTypeDef* CAN_FilterInitStruct);
647→void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct);
648→void CAN_SlaveStartBank(uint8_t CAN_BankNumber); 
649→void CAN_DBGFreeze(CAN_TypeDef* CANx, FunctionalState NewState);
650→void CAN_TTComModeCmd(CAN_TypeDef* CANx, FunctionalState NewState);
651→
652→/* Transmit functions *********************************************************/
653→uint8_t CAN_Transmit(CAN_TypeDef* CANx, CanTxMsg* TxMessage);
654→uint8_t CAN_TransmitStatus(CAN_TypeDef* CANx, uint8_t TransmitMailbox);
655→void CAN_CancelTransmit(CAN_TypeDef* CANx, uint8_t Mailbox);
656→
657→/* Receive functions **********************************************************/
658→void CAN_Receive(CAN_TypeDef* CANx, uint8_t FIFONumber, CanRxMsg* RxMessage);
659→void CAN_FIFORelease(CAN_TypeDef* CANx, uint8_t FIFONumber);
660→uint8_t CAN_MessagePending(CAN_TypeDef* CANx, uint8_t FIFONumber);
661→
662→
663→/* Operation modes functions **************************************************/
664→uint8_t CAN_OperatingModeRequest(CAN_TypeDef* CANx, uint8_t CAN_OperatingMode);
665→uint8_t CAN_Sleep(CAN_TypeDef* CANx);
666→uint8_t CAN_WakeUp(CAN_TypeDef* CANx);
667→
668→/* Error management functions *************************************************/
669→uint8_t CAN_GetLastErrorCode(CAN_TypeDef* CANx);
670→uint8_t CAN_GetReceiveErrorCounter(CAN_TypeDef* CANx);
671→uint8_t CAN_GetLSBTransmitErrorCounter(CAN_TypeDef* CANx);
672→
673→/* Interrupts and flags management functions **********************************/
674→void CAN_ITConfig(CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState);
675→FlagStatus CAN_GetFlagStatus(CAN_TypeDef* CANx, uint32_t CAN_FLAG);
676→void CAN_ClearFlag(CAN_TypeDef* CANx, uint32_t CAN_FLAG);
677→ITStatus CAN_GetITStatus(CAN_TypeDef* CANx, uint32_t CAN_IT);
678→void CAN_ClearITPendingBit(CAN_TypeDef* CANx, uint32_t CAN_IT);
679→
680→#ifdef __cplusplus
681→}
682→#endif
683→
684→#endif /* __STM32F10x_CAN_H */
685→/**
686→  * @}
687→  */
688→
689→/**
690→  * @}
691→  */
692→
693→/**
694→  * @}
695→  */
696→
697→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/