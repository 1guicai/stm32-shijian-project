  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_dac.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the DAC firmware 
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
 24→#ifndef __STM32F10x_DAC_H
 25→#define __STM32F10x_DAC_H
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
 38→/** @addtogroup DAC
 39→  * @{
 40→  */
 41→
 42→/** @defgroup DAC_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  DAC Init structure definition
 48→  */
 49→
 50→typedef struct
 51→{
 52→  uint32_t DAC_Trigger;                      /*!< Specifies the external trigger for the selected DAC channel.
 53→                                                  This parameter can be a value of @ref DAC_trigger_selection */
 54→
 55→  uint32_t DAC_WaveGeneration;               /*!< Specifies whether DAC channel noise waves or triangle waves
 56→                                                  are generated, or whether no wave is generated.
 57→                                                  This parameter can be a value of @ref DAC_wave_generation */
 58→
 59→  uint32_t DAC_LFSRUnmask_TriangleAmplitude; /*!< Specifies the LFSR mask for noise wave generation or
 60→                                                  the maximum amplitude triangle generation for the DAC channel. 
 61→                                                  This parameter can be a value of @ref DAC_lfsrunmask_triangleamplitude */
 62→
 63→  uint32_t DAC_OutputBuffer;                 /*!< Specifies whether the DAC channel output buffer is enabled or disabled.
 64→                                                  This parameter can be a value of @ref DAC_output_buffer */
 65→}DAC_InitTypeDef;
 66→
 67→/**
 68→  * @}
 69→  */
 70→
 71→/** @defgroup DAC_Exported_Constants
 72→  * @{
 73→  */
 74→
 75→/** @defgroup DAC_trigger_selection 
 76→  * @{
 77→  */
 78→
 79→#define DAC_Trigger_None                   ((uint32_t)0x00000000) /*!< Conversion is automatic once the DAC1_DHRxxxx register 
 80→                                                                       has been loaded, and not by external trigger */
 81→#define DAC_Trigger_T6_TRGO                ((uint32_t)0x00000004) /*!< TIM6 TRGO selected as external conversion trigger for DAC channel */
 82→#define DAC_Trigger_T8_TRGO                ((uint32_t)0x0000000C) /*!< TIM8 TRGO selected as external conversion trigger for DAC channel
 83→                                                                       only in High-density devices*/
 84→#define DAC_Trigger_T3_TRGO                ((uint32_t)0x0000000C) /*!< TIM8 TRGO selected as external conversion trigger for DAC channel
 85→                                                                       only in Connectivity line, Medium-density and Low-density Value Line devices */
 86→#define DAC_Trigger_T7_TRGO                ((uint32_t)0x00000014) /*!< TIM7 TRGO selected as external conversion trigger for DAC channel */
 87→#define DAC_Trigger_T5_TRGO                ((uint32_t)0x0000001C) /*!< TIM5 TRGO selected as external conversion trigger for DAC channel */
 88→#define DAC_Trigger_T15_TRGO               ((uint32_t)0x0000001C) /*!< TIM15 TRGO selected as external conversion trigger for DAC channel 
 89→                                                                       only in Medium-density and Low-density Value Line devices*/
 90→#define DAC_Trigger_T2_TRGO                ((uint32_t)0x00000024) /*!< TIM2 TRGO selected as external conversion trigger for DAC channel */
 91→#define DAC_Trigger_T4_TRGO                ((uint32_t)0x0000002C) /*!< TIM4 TRGO selected as external conversion trigger for DAC channel */
 92→#define DAC_Trigger_Ext_IT9                ((uint32_t)0x00000034) /*!< EXTI Line9 event selected as external conversion trigger for DAC channel */
 93→#define DAC_Trigger_Software               ((uint32_t)0x0000003C) /*!< Conversion started by software trigger for DAC channel */
 94→
 95→#define IS_DAC_TRIGGER(TRIGGER) (((TRIGGER) == DAC_Trigger_None) || \
 96→                                 ((TRIGGER) == DAC_Trigger_T6_TRGO) || \
 97→                                 ((TRIGGER) == DAC_Trigger_T8_TRGO) || \
 98→                                 ((TRIGGER) == DAC_Trigger_T7_TRGO) || \
 99→                                 ((TRIGGER) == DAC_Trigger_T5_TRGO) || \
100→                                 ((TRIGGER) == DAC_Trigger_T2_TRGO) || \
101→                                 ((TRIGGER) == DAC_Trigger_T4_TRGO) || \
102→                                 ((TRIGGER) == DAC_Trigger_Ext_IT9) || \
103→                                 ((TRIGGER) == DAC_Trigger_Software))
104→
105→/**
106→  * @}
107→  */
108→
109→/** @defgroup DAC_wave_generation 
110→  * @{
111→  */
112→
113→#define DAC_WaveGeneration_None            ((uint32_t)0x00000000)
114→#define DAC_WaveGeneration_Noise           ((uint32_t)0x00000040)
115→#define DAC_WaveGeneration_Triangle        ((uint32_t)0x00000080)
116→#define IS_DAC_GENERATE_WAVE(WAVE) (((WAVE) == DAC_WaveGeneration_None) || \
117→                                    ((WAVE) == DAC_WaveGeneration_Noise) || \
118→                                    ((WAVE) == DAC_WaveGeneration_Triangle))
119→/**
120→  * @}
121→  */
122→
123→/** @defgroup DAC_lfsrunmask_triangleamplitude
124→  * @{
125→  */
126→
127→#define DAC_LFSRUnmask_Bit0                ((uint32_t)0x00000000) /*!< Unmask DAC channel LFSR bit0 for noise wave generation */
128→#define DAC_LFSRUnmask_Bits1_0             ((uint32_t)0x00000100) /*!< Unmask DAC channel LFSR bit[1:0] for noise wave generation */
129→#define DAC_LFSRUnmask_Bits2_0             ((uint32_t)0x00000200) /*!< Unmask DAC channel LFSR bit[2:0] for noise wave generation */
130→#define DAC_LFSRUnmask_Bits3_0             ((uint32_t)0x00000300) /*!< Unmask DAC channel LFSR bit[3:0] for noise wave generation */
131→#define DAC_LFSRUnmask_Bits4_0             ((uint32_t)0x00000400) /*!< Unmask DAC channel LFSR bit[4:0] for noise wave generation */
132→#define DAC_LFSRUnmask_Bits5_0             ((uint32_t)0x00000500) /*!< Unmask DAC channel LFSR bit[5:0] for noise wave generation */
133→#define DAC_LFSRUnmask_Bits6_0             ((uint32_t)0x00000600) /*!< Unmask DAC channel LFSR bit[6:0] for noise wave generation */
134→#define DAC_LFSRUnmask_Bits7_0             ((uint32_t)0x00000700) /*!< Unmask DAC channel LFSR bit[7:0] for noise wave generation */
135→#define DAC_LFSRUnmask_Bits8_0             ((uint32_t)0x00000800) /*!< Unmask DAC channel LFSR bit[8:0] for noise wave generation */
136→#define DAC_LFSRUnmask_Bits9_0             ((uint32_t)0x00000900) /*!< Unmask DAC channel LFSR bit[9:0] for noise wave generation */
137→#define DAC_LFSRUnmask_Bits10_0            ((uint32_t)0x00000A00) /*!< Unmask DAC channel LFSR bit[10:0] for noise wave generation */
138→#define DAC_LFSRUnmask_Bits11_0            ((uint32_t)0x00000B00) /*!< Unmask DAC channel LFSR bit[11:0] for noise wave generation */
139→#define DAC_TriangleAmplitude_1            ((uint32_t)0x00000000) /*!< Select max triangle amplitude of 1 */
140→#define DAC_TriangleAmplitude_3            ((uint32_t)0x00000100) /*!< Select max triangle amplitude of 3 */
141→#define DAC_TriangleAmplitude_7            ((uint32_t)0x00000200) /*!< Select max triangle amplitude of 7 */
142→#define DAC_TriangleAmplitude_15           ((uint32_t)0x00000300) /*!< Select max triangle amplitude of 15 */
143→#define DAC_TriangleAmplitude_31           ((uint32_t)0x00000400) /*!< Select max triangle amplitude of 31 */
144→#define DAC_TriangleAmplitude_63           ((uint32_t)0x00000500) /*!< Select max triangle amplitude of 63 */
145→#define DAC_TriangleAmplitude_127          ((uint32_t)0x00000600) /*!< Select max triangle amplitude of 127 */
146→#define DAC_TriangleAmplitude_255          ((uint32_t)0x00000700) /*!< Select max triangle amplitude of 255 */
147→#define DAC_TriangleAmplitude_511          ((uint32_t)0x00000800) /*!< Select max triangle amplitude of 511 */
148→#define DAC_TriangleAmplitude_1023         ((uint32_t)0x00000900) /*!< Select max triangle amplitude of 1023 */
149→#define DAC_TriangleAmplitude_2047         ((uint32_t)0x00000A00) /*!< Select max triangle amplitude of 2047 */
150→#define DAC_TriangleAmplitude_4095         ((uint32_t)0x00000B00) /*!< Select max triangle amplitude of 4095 */
151→
152→#define IS_DAC_LFSR_UNMASK_TRIANGLE_AMPLITUDE(VALUE) (((VALUE) == DAC_LFSRUnmask_Bit0) || \
153→                                                      ((VALUE) == DAC_LFSRUnmask_Bits1_0) || \
154→                                                      ((VALUE) == DAC_LFSRUnmask_Bits2_0) || \
155→                                                      ((VALUE) == DAC_LFSRUnmask_Bits3_0) || \
156→                                                      ((VALUE) == DAC_LFSRUnmask_Bits4_0) || \
157→                                                      ((VALUE) == DAC_LFSRUnmask_Bits5_0) || \
158→                                                      ((VALUE) == DAC_LFSRUnmask_Bits6_0) || \
159→                                                      ((VALUE) == DAC_LFSRUnmask_Bits7_0) || \
160→                                                      ((VALUE) == DAC_LFSRUnmask_Bits8_0) || \
161→                                                      ((VALUE) == DAC_LFSRUnmask_Bits9_0) || \
162→                                                      ((VALUE) == DAC_LFSRUnmask_Bits10_0) || \
163→                                                      ((VALUE) == DAC_LFSRUnmask_Bits11_0) || \
164→                                                      ((VALUE) == DAC_TriangleAmplitude_1) || \
165→                                                      ((VALUE) == DAC_TriangleAmplitude_3) || \
166→                                                      ((VALUE) == DAC_TriangleAmplitude_7) || \
167→                                                      ((VALUE) == DAC_TriangleAmplitude_15) || \
168→                                                      ((VALUE) == DAC_TriangleAmplitude_31) || \
169→                                                      ((VALUE) == DAC_TriangleAmplitude_63) || \
170→                                                      ((VALUE) == DAC_TriangleAmplitude_127) || \
171→                                                      ((VALUE) == DAC_TriangleAmplitude_255) || \
172→                                                      ((VALUE) == DAC_TriangleAmplitude_511) || \
173→                                                      ((VALUE) == DAC_TriangleAmplitude_1023) || \
174→                                                      ((VALUE) == DAC_TriangleAmplitude_2047) || \
175→                                                      ((VALUE) == DAC_TriangleAmplitude_4095))
176→/**
177→  * @}
178→  */
179→
180→/** @defgroup DAC_output_buffer 
181→  * @{
182→  */
183→
184→#define DAC_OutputBuffer_Enable            ((uint32_t)0x00000000)
185→#define DAC_OutputBuffer_Disable           ((uint32_t)0x00000002)
186→#define IS_DAC_OUTPUT_BUFFER_STATE(STATE) (((STATE) == DAC_OutputBuffer_Enable) || \
187→                                           ((STATE) == DAC_OutputBuffer_Disable))
188→/**
189→  * @}
190→  */
191→
192→/** @defgroup DAC_Channel_selection 
193→  * @{
194→  */
195→
196→#define DAC_Channel_1                      ((uint32_t)0x00000000)
197→#define DAC_Channel_2                      ((uint32_t)0x00000010)
198→#define IS_DAC_CHANNEL(CHANNEL) (((CHANNEL) == DAC_Channel_1) || \
199→                                 ((CHANNEL) == DAC_Channel_2))
200→/**
201→  * @}
202→  */
203→
204→/** @defgroup DAC_data_alignment 
205→  * @{
206→  */
207→
208→#define DAC_Align_12b_R                    ((uint32_t)0x00000000)
209→#define DAC_Align_12b_L                    ((uint32_t)0x00000004)
210→#define DAC_Align_8b_R                     ((uint32_t)0x00000008)
211→#define IS_DAC_ALIGN(ALIGN) (((ALIGN) == DAC_Align_12b_R) || \
212→                             ((ALIGN) == DAC_Align_12b_L) || \
213→                             ((ALIGN) == DAC_Align_8b_R))
214→/**
215→  * @}
216→  */
217→
218→/** @defgroup DAC_wave_generation 
219→  * @{
220→  */
221→
222→#define DAC_Wave_Noise                     ((uint32_t)0x00000040)
223→#define DAC_Wave_Triangle                  ((uint32_t)0x00000080)
224→#define IS_DAC_WAVE(WAVE) (((WAVE) == DAC_Wave_Noise) || \
225→                           ((WAVE) == DAC_Wave_Triangle))
226→/**
227→  * @}
228→  */
229→
230→/** @defgroup DAC_data 
231→  * @{
232→  */
233→
234→#define IS_DAC_DATA(DATA) ((DATA) <= 0xFFF0) 
235→/**
236→  * @}
237→  */
238→#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL)  || defined (STM32F10X_HD_VL)
239→/** @defgroup DAC_interrupts_definition 
240→  * @{
241→  */ 
242→  
243→#define DAC_IT_DMAUDR                      ((uint32_t)0x00002000)  
244→#define IS_DAC_IT(IT) (((IT) == DAC_IT_DMAUDR)) 
245→
246→/**
247→  * @}
248→  */ 
249→
250→/** @defgroup DAC_flags_definition 
251→  * @{
252→  */ 
253→  
254→#define DAC_FLAG_DMAUDR                    ((uint32_t)0x00002000)  
255→#define IS_DAC_FLAG(FLAG) (((FLAG) == DAC_FLAG_DMAUDR))  
256→
257→/**
258→  * @}
259→  */
260→#endif
261→
262→/**
263→  * @}
264→  */
265→
266→/** @defgroup DAC_Exported_Macros
267→  * @{
268→  */
269→
270→/**
271→  * @}
272→  */
273→
274→/** @defgroup DAC_Exported_Functions
275→  * @{
276→  */
277→
278→void DAC_DeInit(void);
279→void DAC_Init(uint32_t DAC_Channel, DAC_InitTypeDef* DAC_InitStruct);
280→void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);
281→void DAC_Cmd(uint32_t DAC_Channel, FunctionalState NewState);
282→#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
283→void DAC_ITConfig(uint32_t DAC_Channel, uint32_t DAC_IT, FunctionalState NewState);
284→#endif
285→void DAC_DMACmd(uint32_t DAC_Channel, FunctionalState NewState);
286→void DAC_SoftwareTriggerCmd(uint32_t DAC_Channel, FunctionalState NewState);
287→void DAC_DualSoftwareTriggerCmd(FunctionalState NewState);
288→void DAC_WaveGenerationCmd(uint32_t DAC_Channel, uint32_t DAC_Wave, FunctionalState NewState);
289→void DAC_SetChannel1Data(uint32_t DAC_Align, uint16_t Data);
290→void DAC_SetChannel2Data(uint32_t DAC_Align, uint16_t Data);
291→void DAC_SetDualChannelData(uint32_t DAC_Align, uint16_t Data2, uint16_t Data1);
292→uint16_t DAC_GetDataOutputValue(uint32_t DAC_Channel);
293→#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL) 
294→FlagStatus DAC_GetFlagStatus(uint32_t DAC_Channel, uint32_t DAC_FLAG);
295→void DAC_ClearFlag(uint32_t DAC_Channel, uint32_t DAC_FLAG);
296→ITStatus DAC_GetITStatus(uint32_t DAC_Channel, uint32_t DAC_IT);
297→void DAC_ClearITPendingBit(uint32_t DAC_Channel, uint32_t DAC_IT);
298→#endif
299→
300→#ifdef __cplusplus
301→}
302→#endif
303→
304→#endif /*__STM32F10x_DAC_H */
305→/**
306→  * @}
307→  */
308→
309→/**
310→  * @}
311→  */
312→
313→/**
314→  * @}
315→  */
316→
317→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/