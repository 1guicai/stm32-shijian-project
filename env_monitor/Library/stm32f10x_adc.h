  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_adc.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the ADC firmware 
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
 24→#ifndef __STM32F10x_ADC_H
 25→#define __STM32F10x_ADC_H
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
 38→/** @addtogroup ADC
 39→  * @{
 40→  */
 41→
 42→/** @defgroup ADC_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  ADC Init structure definition  
 48→  */
 49→
 50→typedef struct
 51→{
 52→  uint32_t ADC_Mode;                      /*!< Configures the ADC to operate in independent or
 53→                                               dual mode. 
 54→                                               This parameter can be a value of @ref ADC_mode */
 55→
 56→  FunctionalState ADC_ScanConvMode;       /*!< Specifies whether the conversion is performed in
 57→                                               Scan (multichannels) or Single (one channel) mode.
 58→                                               This parameter can be set to ENABLE or DISABLE */
 59→
 60→  FunctionalState ADC_ContinuousConvMode; /*!< Specifies whether the conversion is performed in
 61→                                               Continuous or Single mode.
 62→                                               This parameter can be set to ENABLE or DISABLE. */
 63→
 64→  uint32_t ADC_ExternalTrigConv;          /*!< Defines the external trigger used to start the analog
 65→                                               to digital conversion of regular channels. This parameter
 66→                                               can be a value of @ref ADC_external_trigger_sources_for_regular_channels_conversion */
 67→
 68→  uint32_t ADC_DataAlign;                 /*!< Specifies whether the ADC data alignment is left or right.
 69→                                               This parameter can be a value of @ref ADC_data_align */
 70→
 71→  uint8_t ADC_NbrOfChannel;               /*!< Specifies the number of ADC channels that will be converted
 72→                                               using the sequencer for regular channel group.
 73→                                               This parameter must range from 1 to 16. */
 74→}ADC_InitTypeDef;
 75→/**
 76→  * @}
 77→  */
 78→
 79→/** @defgroup ADC_Exported_Constants
 80→  * @{
 81→  */
 82→
 83→#define IS_ADC_ALL_PERIPH(PERIPH) (((PERIPH) == ADC1) || \
 84→                                   ((PERIPH) == ADC2) || \
 85→                                   ((PERIPH) == ADC3))
 86→
 87→#define IS_ADC_DMA_PERIPH(PERIPH) (((PERIPH) == ADC1) || \
 88→                                   ((PERIPH) == ADC3))
 89→
 90→/** @defgroup ADC_mode 
 91→  * @{
 92→  */
 93→
 94→#define ADC_Mode_Independent                       ((uint32_t)0x00000000)
 95→#define ADC_Mode_RegInjecSimult                    ((uint32_t)0x00010000)
 96→#define ADC_Mode_RegSimult_AlterTrig               ((uint32_t)0x00020000)
 97→#define ADC_Mode_InjecSimult_FastInterl            ((uint32_t)0x00030000)
 98→#define ADC_Mode_InjecSimult_SlowInterl            ((uint32_t)0x00040000)
 99→#define ADC_Mode_InjecSimult                       ((uint32_t)0x00050000)
100→#define ADC_Mode_RegSimult                         ((uint32_t)0x00060000)
101→#define ADC_Mode_FastInterl                        ((uint32_t)0x00070000)
102→#define ADC_Mode_SlowInterl                        ((uint32_t)0x00080000)
103→#define ADC_Mode_AlterTrig                         ((uint32_t)0x00090000)
104→
105→#define IS_ADC_MODE(MODE) (((MODE) == ADC_Mode_Independent) || \
106→                           ((MODE) == ADC_Mode_RegInjecSimult) || \
107→                           ((MODE) == ADC_Mode_RegSimult_AlterTrig) || \
108→                           ((MODE) == ADC_Mode_InjecSimult_FastInterl) || \
109→                           ((MODE) == ADC_Mode_InjecSimult_SlowInterl) || \
110→                           ((MODE) == ADC_Mode_InjecSimult) || \
111→                           ((MODE) == ADC_Mode_RegSimult) || \
112→                           ((MODE) == ADC_Mode_FastInterl) || \
113→                           ((MODE) == ADC_Mode_SlowInterl) || \
114→                           ((MODE) == ADC_Mode_AlterTrig))
115→/**
116→  * @}
117→  */
118→
119→/** @defgroup ADC_external_trigger_sources_for_regular_channels_conversion 
120→  * @{
121→  */
122→
123→#define ADC_ExternalTrigConv_T1_CC1                ((uint32_t)0x00000000) /*!< For ADC1 and ADC2 */
124→#define ADC_ExternalTrigConv_T1_CC2                ((uint32_t)0x00020000) /*!< For ADC1 and ADC2 */
125→#define ADC_ExternalTrigConv_T2_CC2                ((uint32_t)0x00060000) /*!< For ADC1 and ADC2 */
126→#define ADC_ExternalTrigConv_T3_TRGO               ((uint32_t)0x00080000) /*!< For ADC1 and ADC2 */
127→#define ADC_ExternalTrigConv_T4_CC4                ((uint32_t)0x000A0000) /*!< For ADC1 and ADC2 */
128→#define ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO    ((uint32_t)0x000C0000) /*!< For ADC1 and ADC2 */
129→
130→#define ADC_ExternalTrigConv_T1_CC3                ((uint32_t)0x00040000) /*!< For ADC1, ADC2 and ADC3 */
131→#define ADC_ExternalTrigConv_None                  ((uint32_t)0x000E0000) /*!< For ADC1, ADC2 and ADC3 */
132→
133→#define ADC_ExternalTrigConv_T3_CC1                ((uint32_t)0x00000000) /*!< For ADC3 only */
134→#define ADC_ExternalTrigConv_T2_CC3                ((uint32_t)0x00020000) /*!< For ADC3 only */
135→#define ADC_ExternalTrigConv_T8_CC1                ((uint32_t)0x00060000) /*!< For ADC3 only */
136→#define ADC_ExternalTrigConv_T8_TRGO               ((uint32_t)0x00080000) /*!< For ADC3 only */
137→#define ADC_ExternalTrigConv_T5_CC1                ((uint32_t)0x000A0000) /*!< For ADC3 only */
138→#define ADC_ExternalTrigConv_T5_CC3                ((uint32_t)0x000C0000) /*!< For ADC3 only */
139→
140→#define IS_ADC_EXT_TRIG(REGTRIG) (((REGTRIG) == ADC_ExternalTrigConv_T1_CC1) || \
141→                                  ((REGTRIG) == ADC_ExternalTrigConv_T1_CC2) || \
142→                                  ((REGTRIG) == ADC_ExternalTrigConv_T1_CC3) || \
143→                                  ((REGTRIG) == ADC_ExternalTrigConv_T2_CC2) || \
144→                                  ((REGTRIG) == ADC_ExternalTrigConv_T3_TRGO) || \
145→                                  ((REGTRIG) == ADC_ExternalTrigConv_T4_CC4) || \
146→                                  ((REGTRIG) == ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO) || \
147→                                  ((REGTRIG) == ADC_ExternalTrigConv_None) || \
148→                                  ((REGTRIG) == ADC_ExternalTrigConv_T3_CC1) || \
149→                                  ((REGTRIG) == ADC_ExternalTrigConv_T2_CC3) || \
150→                                  ((REGTRIG) == ADC_ExternalTrigConv_T8_CC1) || \
151→                                  ((REGTRIG) == ADC_ExternalTrigConv_T8_TRGO) || \
152→                                  ((REGTRIG) == ADC_ExternalTrigConv_T5_CC1) || \
153→                                  ((REGTRIG) == ADC_ExternalTrigConv_T5_CC3))
154→/**
155→  * @}
156→  */
157→
158→/** @defgroup ADC_data_align 
159→  * @{
160→  */
161→
162→#define ADC_DataAlign_Right                        ((uint32_t)0x00000000)
163→#define ADC_DataAlign_Left                         ((uint32_t)0x00000800)
164→#define IS_ADC_DATA_ALIGN(ALIGN) (((ALIGN) == ADC_DataAlign_Right) || \
165→                                  ((ALIGN) == ADC_DataAlign_Left))
166→/**
167→  * @}
168→  */
169→
170→/** @defgroup ADC_channels 
171→  * @{
172→  */
173→
174→#define ADC_Channel_0                               ((uint8_t)0x00)
175→#define ADC_Channel_1                               ((uint8_t)0x01)
176→#define ADC_Channel_2                               ((uint8_t)0x02)
177→#define ADC_Channel_3                               ((uint8_t)0x03)
178→#define ADC_Channel_4                               ((uint8_t)0x04)
179→#define ADC_Channel_5                               ((uint8_t)0x05)
180→#define ADC_Channel_6                               ((uint8_t)0x06)
181→#define ADC_Channel_7                               ((uint8_t)0x07)
182→#define ADC_Channel_8                               ((uint8_t)0x08)
183→#define ADC_Channel_9                               ((uint8_t)0x09)
184→#define ADC_Channel_10                              ((uint8_t)0x0A)
185→#define ADC_Channel_11                              ((uint8_t)0x0B)
186→#define ADC_Channel_12                              ((uint8_t)0x0C)
187→#define ADC_Channel_13                              ((uint8_t)0x0D)
188→#define ADC_Channel_14                              ((uint8_t)0x0E)
189→#define ADC_Channel_15                              ((uint8_t)0x0F)
190→#define ADC_Channel_16                              ((uint8_t)0x10)
191→#define ADC_Channel_17                              ((uint8_t)0x11)
192→
193→#define ADC_Channel_TempSensor                      ((uint8_t)ADC_Channel_16)
194→#define ADC_Channel_Vrefint                         ((uint8_t)ADC_Channel_17)
195→
196→#define IS_ADC_CHANNEL(CHANNEL) (((CHANNEL) == ADC_Channel_0) || ((CHANNEL) == ADC_Channel_1) || \
197→                                 ((CHANNEL) == ADC_Channel_2) || ((CHANNEL) == ADC_Channel_3) || \
198→                                 ((CHANNEL) == ADC_Channel_4) || ((CHANNEL) == ADC_Channel_5) || \
199→                                 ((CHANNEL) == ADC_Channel_6) || ((CHANNEL) == ADC_Channel_7) || \
200→                                 ((CHANNEL) == ADC_Channel_8) || ((CHANNEL) == ADC_Channel_9) || \
201→                                 ((CHANNEL) == ADC_Channel_10) || ((CHANNEL) == ADC_Channel_11) || \
202→                                 ((CHANNEL) == ADC_Channel_12) || ((CHANNEL) == ADC_Channel_13) || \
203→                                 ((CHANNEL) == ADC_Channel_14) || ((CHANNEL) == ADC_Channel_15) || \
204→                                 ((CHANNEL) == ADC_Channel_16) || ((CHANNEL) == ADC_Channel_17))
205→/**
206→  * @}
207→  */
208→
209→/** @defgroup ADC_sampling_time 
210→  * @{
211→  */
212→
213→#define ADC_SampleTime_1Cycles5                    ((uint8_t)0x00)
214→#define ADC_SampleTime_7Cycles5                    ((uint8_t)0x01)
215→#define ADC_SampleTime_13Cycles5                   ((uint8_t)0x02)
216→#define ADC_SampleTime_28Cycles5                   ((uint8_t)0x03)
217→#define ADC_SampleTime_41Cycles5                   ((uint8_t)0x04)
218→#define ADC_SampleTime_55Cycles5                   ((uint8_t)0x05)
219→#define ADC_SampleTime_71Cycles5                   ((uint8_t)0x06)
220→#define ADC_SampleTime_239Cycles5                  ((uint8_t)0x07)
221→#define IS_ADC_SAMPLE_TIME(TIME) (((TIME) == ADC_SampleTime_1Cycles5) || \
222→                                  ((TIME) == ADC_SampleTime_7Cycles5) || \
223→                                  ((TIME) == ADC_SampleTime_13Cycles5) || \
224→                                  ((TIME) == ADC_SampleTime_28Cycles5) || \
225→                                  ((TIME) == ADC_SampleTime_41Cycles5) || \
226→                                  ((TIME) == ADC_SampleTime_55Cycles5) || \
227→                                  ((TIME) == ADC_SampleTime_71Cycles5) || \
228→                                  ((TIME) == ADC_SampleTime_239Cycles5))
229→/**
230→  * @}
231→  */
232→
233→/** @defgroup ADC_external_trigger_sources_for_injected_channels_conversion 
234→  * @{
235→  */
236→
237→#define ADC_ExternalTrigInjecConv_T2_TRGO           ((uint32_t)0x00002000) /*!< For ADC1 and ADC2 */
238→#define ADC_ExternalTrigInjecConv_T2_CC1            ((uint32_t)0x00003000) /*!< For ADC1 and ADC2 */
239→#define ADC_ExternalTrigInjecConv_T3_CC4            ((uint32_t)0x00004000) /*!< For ADC1 and ADC2 */
240→#define ADC_ExternalTrigInjecConv_T4_TRGO           ((uint32_t)0x00005000) /*!< For ADC1 and ADC2 */
241→#define ADC_ExternalTrigInjecConv_Ext_IT15_TIM8_CC4 ((uint32_t)0x00006000) /*!< For ADC1 and ADC2 */
242→
243→#define ADC_ExternalTrigInjecConv_T1_TRGO           ((uint32_t)0x00000000) /*!< For ADC1, ADC2 and ADC3 */
244→#define ADC_ExternalTrigInjecConv_T1_CC4            ((uint32_t)0x00001000) /*!< For ADC1, ADC2 and ADC3 */
245→#define ADC_ExternalTrigInjecConv_None              ((uint32_t)0x00007000) /*!< For ADC1, ADC2 and ADC3 */
246→
247→#define ADC_ExternalTrigInjecConv_T4_CC3            ((uint32_t)0x00002000) /*!< For ADC3 only */
248→#define ADC_ExternalTrigInjecConv_T8_CC2            ((uint32_t)0x00003000) /*!< For ADC3 only */
249→#define ADC_ExternalTrigInjecConv_T8_CC4            ((uint32_t)0x00004000) /*!< For ADC3 only */
250→#define ADC_ExternalTrigInjecConv_T5_TRGO           ((uint32_t)0x00005000) /*!< For ADC3 only */
251→#define ADC_ExternalTrigInjecConv_T5_CC4            ((uint32_t)0x00006000) /*!< For ADC3 only */
252→
253→#define IS_ADC_EXT_INJEC_TRIG(INJTRIG) (((INJTRIG) == ADC_ExternalTrigInjecConv_T1_TRGO) || \
254→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T1_CC4) || \
255→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T2_TRGO) || \
256→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T2_CC1) || \
257→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T3_CC4) || \
258→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T4_TRGO) || \
259→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_Ext_IT15_TIM8_CC4) || \
260→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_None) || \
261→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T4_CC3) || \
262→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T8_CC2) || \
263→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T8_CC4) || \
264→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T5_TRGO) || \
265→                                        ((INJTRIG) == ADC_ExternalTrigInjecConv_T5_CC4))
266→/**
267→  * @}
268→  */
269→
270→/** @defgroup ADC_injected_channel_selection 
271→  * @{
272→  */
273→
274→#define ADC_InjectedChannel_1                       ((uint8_t)0x14)
275→#define ADC_InjectedChannel_2                       ((uint8_t)0x18)
276→#define ADC_InjectedChannel_3                       ((uint8_t)0x1C)
277→#define ADC_InjectedChannel_4                       ((uint8_t)0x20)
278→#define IS_ADC_INJECTED_CHANNEL(CHANNEL) (((CHANNEL) == ADC_InjectedChannel_1) || \
279→                                          ((CHANNEL) == ADC_InjectedChannel_2) || \
280→                                          ((CHANNEL) == ADC_InjectedChannel_3) || \
281→                                          ((CHANNEL) == ADC_InjectedChannel_4))
282→/**
283→  * @}
284→  */
285→
286→/** @defgroup ADC_analog_watchdog_selection 
287→  * @{
288→  */
289→
290→#define ADC_AnalogWatchdog_SingleRegEnable         ((uint32_t)0x00800200)
291→#define ADC_AnalogWatchdog_SingleInjecEnable       ((uint32_t)0x00400200)
292→#define ADC_AnalogWatchdog_SingleRegOrInjecEnable  ((uint32_t)0x00C00200)
293→#define ADC_AnalogWatchdog_AllRegEnable            ((uint32_t)0x00800000)
294→#define ADC_AnalogWatchdog_AllInjecEnable          ((uint32_t)0x00400000)
295→#define ADC_AnalogWatchdog_AllRegAllInjecEnable    ((uint32_t)0x00C00000)
296→#define ADC_AnalogWatchdog_None                    ((uint32_t)0x00000000)
297→
298→#define IS_ADC_ANALOG_WATCHDOG(WATCHDOG) (((WATCHDOG) == ADC_AnalogWatchdog_SingleRegEnable) || \
299→                                          ((WATCHDOG) == ADC_AnalogWatchdog_SingleInjecEnable) || \
300→                                          ((WATCHDOG) == ADC_AnalogWatchdog_SingleRegOrInjecEnable) || \
301→                                          ((WATCHDOG) == ADC_AnalogWatchdog_AllRegEnable) || \
302→                                          ((WATCHDOG) == ADC_AnalogWatchdog_AllInjecEnable) || \
303→                                          ((WATCHDOG) == ADC_AnalogWatchdog_AllRegAllInjecEnable) || \
304→                                          ((WATCHDOG) == ADC_AnalogWatchdog_None))
305→/**
306→  * @}
307→  */
308→
309→/** @defgroup ADC_interrupts_definition 
310→  * @{
311→  */
312→
313→#define ADC_IT_EOC                                 ((uint16_t)0x0220)
314→#define ADC_IT_AWD                                 ((uint16_t)0x0140)
315→#define ADC_IT_JEOC                                ((uint16_t)0x0480)
316→
317→#define IS_ADC_IT(IT) ((((IT) & (uint16_t)0xF81F) == 0x00) && ((IT) != 0x00))
318→
319→#define IS_ADC_GET_IT(IT) (((IT) == ADC_IT_EOC) || ((IT) == ADC_IT_AWD) || \
320→                           ((IT) == ADC_IT_JEOC))
321→/**
322→  * @}
323→  */
324→
325→/** @defgroup ADC_flags_definition 
326→  * @{
327→  */
328→
329→#define ADC_FLAG_AWD                               ((uint8_t)0x01)
330→#define ADC_FLAG_EOC                               ((uint8_t)0x02)
331→#define ADC_FLAG_JEOC                              ((uint8_t)0x04)
332→#define ADC_FLAG_JSTRT                             ((uint8_t)0x08)
333→#define ADC_FLAG_STRT                              ((uint8_t)0x10)
334→#define IS_ADC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint8_t)0xE0) == 0x00) && ((FLAG) != 0x00))
335→#define IS_ADC_GET_FLAG(FLAG) (((FLAG) == ADC_FLAG_AWD) || ((FLAG) == ADC_FLAG_EOC) || \
336→                               ((FLAG) == ADC_FLAG_JEOC) || ((FLAG)== ADC_FLAG_JSTRT) || \
337→                               ((FLAG) == ADC_FLAG_STRT))
338→/**
339→  * @}
340→  */
341→
342→/** @defgroup ADC_thresholds 
343→  * @{
344→  */
345→
346→#define IS_ADC_THRESHOLD(THRESHOLD) ((THRESHOLD) <= 0xFFF)
347→
348→/**
349→  * @}
350→  */
351→
352→/** @defgroup ADC_injected_offset 
353→  * @{
354→  */
355→
356→#define IS_ADC_OFFSET(OFFSET) ((OFFSET) <= 0xFFF)
357→
358→/**
359→  * @}
360→  */
361→
362→/** @defgroup ADC_injected_length 
363→  * @{
364→  */
365→
366→#define IS_ADC_INJECTED_LENGTH(LENGTH) (((LENGTH) >= 0x1) && ((LENGTH) <= 0x4))
367→
368→/**
369→  * @}
370→  */
371→
372→/** @defgroup ADC_injected_rank 
373→  * @{
374→  */
375→
376→#define IS_ADC_INJECTED_RANK(RANK) (((RANK) >= 0x1) && ((RANK) <= 0x4))
377→
378→/**
379→  * @}
380→  */ 
381→
382→
383→/** @defgroup ADC_regular_length 
384→  * @{
385→  */
386→
387→#define IS_ADC_REGULAR_LENGTH(LENGTH) (((LENGTH) >= 0x1) && ((LENGTH) <= 0x10))
388→/**
389→  * @}
390→  */
391→
392→/** @defgroup ADC_regular_rank 
393→  * @{
394→  */
395→
396→#define IS_ADC_REGULAR_RANK(RANK) (((RANK) >= 0x1) && ((RANK) <= 0x10))
397→
398→/**
399→  * @}
400→  */
401→
402→/** @defgroup ADC_regular_discontinuous_mode_number 
403→  * @{
404→  */
405→
406→#define IS_ADC_REGULAR_DISC_NUMBER(NUMBER) (((NUMBER) >= 0x1) && ((NUMBER) <= 0x8))
407→
408→/**
409→  * @}
410→  */
411→
412→/**
413→  * @}
414→  */
415→
416→/** @defgroup ADC_Exported_Macros
417→  * @{
418→  */
419→
420→/**
421→  * @}
422→  */
423→
424→/** @defgroup ADC_Exported_Functions
425→  * @{
426→  */
427→
428→void ADC_DeInit(ADC_TypeDef* ADCx);
429→void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
430→void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
431→void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
432→void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
433→void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
434→void ADC_ResetCalibration(ADC_TypeDef* ADCx);
435→FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx);
436→void ADC_StartCalibration(ADC_TypeDef* ADCx);
437→FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx);
438→void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
439→FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
440→void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, uint8_t Number);
441→void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
442→void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
443→void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
444→uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx);
445→uint32_t ADC_GetDualModeConversionValue(void);
446→void ADC_AutoInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
447→void ADC_InjectedDiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
448→void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
449→void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
450→void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
451→FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(ADC_TypeDef* ADCx);
452→void ADC_InjectedChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
453→void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* ADCx, uint8_t Length);
454→void ADC_SetInjectedOffset(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset);
455→uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel);
456→void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
457→void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
458→void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel);
459→void ADC_TempSensorVrefintCmd(FunctionalState NewState);
460→FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
461→void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
462→ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT);
463→void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT);
464→
465→#ifdef __cplusplus
466→}
467→#endif
468→
469→#endif /*__STM32F10x_ADC_H */
470→
471→/**
472→  * @}
473→  */
474→
475→/**
476→  * @}
477→  */
478→
479→/**
480→  * @}
481→  */
482→
483→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/