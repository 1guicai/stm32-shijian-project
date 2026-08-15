  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_gpio.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the GPIO 
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
 24→#ifndef __STM32F10x_GPIO_H
 25→#define __STM32F10x_GPIO_H
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
 38→/** @addtogroup GPIO
 39→  * @{
 40→  */
 41→
 42→/** @defgroup GPIO_Exported_Types
 43→  * @{
 44→  */
 45→
 46→#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
 47→                                    ((PERIPH) == GPIOB) || \
 48→                                    ((PERIPH) == GPIOC) || \
 49→                                    ((PERIPH) == GPIOD) || \
 50→                                    ((PERIPH) == GPIOE) || \
 51→                                    ((PERIPH) == GPIOF) || \
 52→                                    ((PERIPH) == GPIOG))
 53→                                     
 54→/** 
 55→  * @brief  Output Maximum frequency selection  
 56→  */
 57→
 58→typedef enum
 59→{ 
 60→  GPIO_Speed_10MHz = 1,
 61→  GPIO_Speed_2MHz, 
 62→  GPIO_Speed_50MHz
 63→}GPIOSpeed_TypeDef;
 64→#define IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_Speed_10MHz) || ((SPEED) == GPIO_Speed_2MHz) || \
 65→                              ((SPEED) == GPIO_Speed_50MHz))
 66→
 67→/** 
 68→  * @brief  Configuration Mode enumeration  
 69→  */
 70→
 71→typedef enum
 72→{ GPIO_Mode_AIN = 0x0,
 73→  GPIO_Mode_IN_FLOATING = 0x04,
 74→  GPIO_Mode_IPD = 0x28,
 75→  GPIO_Mode_IPU = 0x48,
 76→  GPIO_Mode_Out_OD = 0x14,
 77→  GPIO_Mode_Out_PP = 0x10,
 78→  GPIO_Mode_AF_OD = 0x1C,
 79→  GPIO_Mode_AF_PP = 0x18
 80→}GPIOMode_TypeDef;
 81→
 82→#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_AIN) || ((MODE) == GPIO_Mode_IN_FLOATING) || \
 83→                            ((MODE) == GPIO_Mode_IPD) || ((MODE) == GPIO_Mode_IPU) || \
 84→                            ((MODE) == GPIO_Mode_Out_OD) || ((MODE) == GPIO_Mode_Out_PP) || \
 85→                            ((MODE) == GPIO_Mode_AF_OD) || ((MODE) == GPIO_Mode_AF_PP))
 86→
 87→/** 
 88→  * @brief  GPIO Init structure definition  
 89→  */
 90→
 91→typedef struct
 92→{
 93→  uint16_t GPIO_Pin;             /*!< Specifies the GPIO pins to be configured.
 94→                                      This parameter can be any value of @ref GPIO_pins_define */
 95→
 96→  GPIOSpeed_TypeDef GPIO_Speed;  /*!< Specifies the speed for the selected pins.
 97→                                      This parameter can be a value of @ref GPIOSpeed_TypeDef */
 98→
 99→  GPIOMode_TypeDef GPIO_Mode;    /*!< Specifies the operating mode for the selected pins.
100→                                      This parameter can be a value of @ref GPIOMode_TypeDef */
101→}GPIO_InitTypeDef;
102→
103→
104→/** 
105→  * @brief  Bit_SET and Bit_RESET enumeration  
106→  */
107→
108→typedef enum
109→{ Bit_RESET = 0,
110→  Bit_SET
111→}BitAction;
112→
113→#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))
114→
115→/**
116→  * @}
117→  */
118→
119→/** @defgroup GPIO_Exported_Constants
120→  * @{
121→  */
122→
123→/** @defgroup GPIO_pins_define 
124→  * @{
125→  */
126→
127→#define GPIO_Pin_0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
128→#define GPIO_Pin_1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
129→#define GPIO_Pin_2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
130→#define GPIO_Pin_3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
131→#define GPIO_Pin_4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
132→#define GPIO_Pin_5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
133→#define GPIO_Pin_6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
134→#define GPIO_Pin_7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
135→#define GPIO_Pin_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
136→#define GPIO_Pin_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
137→#define GPIO_Pin_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
138→#define GPIO_Pin_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
139→#define GPIO_Pin_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
140→#define GPIO_Pin_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
141→#define GPIO_Pin_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
142→#define GPIO_Pin_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
143→#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */
144→
145→#define IS_GPIO_PIN(PIN) ((((PIN) & (uint16_t)0x00) == 0x00) && ((PIN) != (uint16_t)0x00))
146→
147→#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_Pin_0) || \
148→                              ((PIN) == GPIO_Pin_1) || \
149→                              ((PIN) == GPIO_Pin_2) || \
150→                              ((PIN) == GPIO_Pin_3) || \
151→                              ((PIN) == GPIO_Pin_4) || \
152→                              ((PIN) == GPIO_Pin_5) || \
153→                              ((PIN) == GPIO_Pin_6) || \
154→                              ((PIN) == GPIO_Pin_7) || \
155→                              ((PIN) == GPIO_Pin_8) || \
156→                              ((PIN) == GPIO_Pin_9) || \
157→                              ((PIN) == GPIO_Pin_10) || \
158→                              ((PIN) == GPIO_Pin_11) || \
159→                              ((PIN) == GPIO_Pin_12) || \
160→                              ((PIN) == GPIO_Pin_13) || \
161→                              ((PIN) == GPIO_Pin_14) || \
162→                              ((PIN) == GPIO_Pin_15))
163→
164→/**
165→  * @}
166→  */
167→
168→/** @defgroup GPIO_Remap_define 
169→  * @{
170→  */
171→
172→#define GPIO_Remap_SPI1             ((uint32_t)0x00000001)  /*!< SPI1 Alternate Function mapping */
173→#define GPIO_Remap_I2C1             ((uint32_t)0x00000002)  /*!< I2C1 Alternate Function mapping */
174→#define GPIO_Remap_USART1           ((uint32_t)0x00000004)  /*!< USART1 Alternate Function mapping */
175→#define GPIO_Remap_USART2           ((uint32_t)0x00000008)  /*!< USART2 Alternate Function mapping */
176→#define GPIO_PartialRemap_USART3    ((uint32_t)0x00140010)  /*!< USART3 Partial Alternate Function mapping */
177→#define GPIO_FullRemap_USART3       ((uint32_t)0x00140030)  /*!< USART3 Full Alternate Function mapping */
178→#define GPIO_PartialRemap_TIM1      ((uint32_t)0x00160040)  /*!< TIM1 Partial Alternate Function mapping */
179→#define GPIO_FullRemap_TIM1         ((uint32_t)0x001600C0)  /*!< TIM1 Full Alternate Function mapping */
180→#define GPIO_PartialRemap1_TIM2     ((uint32_t)0x00180100)  /*!< TIM2 Partial1 Alternate Function mapping */
181→#define GPIO_PartialRemap2_TIM2     ((uint32_t)0x00180200)  /*!< TIM2 Partial2 Alternate Function mapping */
182→#define GPIO_FullRemap_TIM2         ((uint32_t)0x00180300)  /*!< TIM2 Full Alternate Function mapping */
183→#define GPIO_PartialRemap_TIM3      ((uint32_t)0x001A0800)  /*!< TIM3 Partial Alternate Function mapping */
184→#define GPIO_FullRemap_TIM3         ((uint32_t)0x001A0C00)  /*!< TIM3 Full Alternate Function mapping */
185→#define GPIO_Remap_TIM4             ((uint32_t)0x00001000)  /*!< TIM4 Alternate Function mapping */
186→#define GPIO_Remap1_CAN1            ((uint32_t)0x001D4000)  /*!< CAN1 Alternate Function mapping */
187→#define GPIO_Remap2_CAN1            ((uint32_t)0x001D6000)  /*!< CAN1 Alternate Function mapping */
188→#define GPIO_Remap_PD01             ((uint32_t)0x00008000)  /*!< PD01 Alternate Function mapping */
189→#define GPIO_Remap_TIM5CH4_LSI      ((uint32_t)0x00200001)  /*!< LSI connected to TIM5 Channel4 input capture for calibration */
190→#define GPIO_Remap_ADC1_ETRGINJ     ((uint32_t)0x00200002)  /*!< ADC1 External Trigger Injected Conversion remapping */
191→#define GPIO_Remap_ADC1_ETRGREG     ((uint32_t)0x00200004)  /*!< ADC1 External Trigger Regular Conversion remapping */
192→#define GPIO_Remap_ADC2_ETRGINJ     ((uint32_t)0x00200008)  /*!< ADC2 External Trigger Injected Conversion remapping */
193→#define GPIO_Remap_ADC2_ETRGREG     ((uint32_t)0x00200010)  /*!< ADC2 External Trigger Regular Conversion remapping */
194→#define GPIO_Remap_ETH              ((uint32_t)0x00200020)  /*!< Ethernet remapping (only for Connectivity line devices) */
195→#define GPIO_Remap_CAN2             ((uint32_t)0x00200040)  /*!< CAN2 remapping (only for Connectivity line devices) */
196→#define GPIO_Remap_SWJ_NoJTRST      ((uint32_t)0x00300100)  /*!< Full SWJ Enabled (JTAG-DP + SW-DP) but without JTRST */
197→#define GPIO_Remap_SWJ_JTAGDisable  ((uint32_t)0x00300200)  /*!< JTAG-DP Disabled and SW-DP Enabled */
198→#define GPIO_Remap_SWJ_Disable      ((uint32_t)0x00300400)  /*!< Full SWJ Disabled (JTAG-DP + SW-DP) */
199→#define GPIO_Remap_SPI3             ((uint32_t)0x00201100)  /*!< SPI3/I2S3 Alternate Function mapping (only for Connectivity line devices) */
200→#define GPIO_Remap_TIM2ITR1_PTP_SOF ((uint32_t)0x00202000)  /*!< Ethernet PTP output or USB OTG SOF (Start of Frame) connected
201→                                                                 to TIM2 Internal Trigger 1 for calibration
202→                                                                 (only for Connectivity line devices) */
203→#define GPIO_Remap_PTP_PPS          ((uint32_t)0x00204000)  /*!< Ethernet MAC PPS_PTS output on PB05 (only for Connectivity line devices) */
204→
205→#define GPIO_Remap_TIM15            ((uint32_t)0x80000001)  /*!< TIM15 Alternate Function mapping (only for Value line devices) */
206→#define GPIO_Remap_TIM16            ((uint32_t)0x80000002)  /*!< TIM16 Alternate Function mapping (only for Value line devices) */
207→#define GPIO_Remap_TIM17            ((uint32_t)0x80000004)  /*!< TIM17 Alternate Function mapping (only for Value line devices) */
208→#define GPIO_Remap_CEC              ((uint32_t)0x80000008)  /*!< CEC Alternate Function mapping (only for Value line devices) */
209→#define GPIO_Remap_TIM1_DMA         ((uint32_t)0x80000010)  /*!< TIM1 DMA requests mapping (only for Value line devices) */
210→
211→#define GPIO_Remap_TIM9             ((uint32_t)0x80000020)  /*!< TIM9 Alternate Function mapping (only for XL-density devices) */
212→#define GPIO_Remap_TIM10            ((uint32_t)0x80000040)  /*!< TIM10 Alternate Function mapping (only for XL-density devices) */
213→#define GPIO_Remap_TIM11            ((uint32_t)0x80000080)  /*!< TIM11 Alternate Function mapping (only for XL-density devices) */
214→#define GPIO_Remap_TIM13            ((uint32_t)0x80000100)  /*!< TIM13 Alternate Function mapping (only for High density Value line and XL-density devices) */
215→#define GPIO_Remap_TIM14            ((uint32_t)0x80000200)  /*!< TIM14 Alternate Function mapping (only for High density Value line and XL-density devices) */
216→#define GPIO_Remap_FSMC_NADV        ((uint32_t)0x80000400)  /*!< FSMC_NADV Alternate Function mapping (only for High density Value line and XL-density devices) */
217→
218→#define GPIO_Remap_TIM67_DAC_DMA    ((uint32_t)0x80000800)  /*!< TIM6/TIM7 and DAC DMA requests remapping (only for High density Value line devices) */
219→#define GPIO_Remap_TIM12            ((uint32_t)0x80001000)  /*!< TIM12 Alternate Function mapping (only for High density Value line devices) */
220→#define GPIO_Remap_MISC             ((uint32_t)0x80002000)  /*!< Miscellaneous Remap (DMA2 Channel5 Position and DAC Trigger remapping, 
221→                                                                 only for High density Value line devices) */                                                       
222→
223→#define IS_GPIO_REMAP(REMAP) (((REMAP) == GPIO_Remap_SPI1) || ((REMAP) == GPIO_Remap_I2C1) || \
224→                              ((REMAP) == GPIO_Remap_USART1) || ((REMAP) == GPIO_Remap_USART2) || \
225→                              ((REMAP) == GPIO_PartialRemap_USART3) || ((REMAP) == GPIO_FullRemap_USART3) || \
226→                              ((REMAP) == GPIO_PartialRemap_TIM1) || ((REMAP) == GPIO_FullRemap_TIM1) || \
227→                              ((REMAP) == GPIO_PartialRemap1_TIM2) || ((REMAP) == GPIO_PartialRemap2_TIM2) || \
228→                              ((REMAP) == GPIO_FullRemap_TIM2) || ((REMAP) == GPIO_PartialRemap_TIM3) || \
229→                              ((REMAP) == GPIO_FullRemap_TIM3) || ((REMAP) == GPIO_Remap_TIM4) || \
230→                              ((REMAP) == GPIO_Remap1_CAN1) || ((REMAP) == GPIO_Remap2_CAN1) || \
231→                              ((REMAP) == GPIO_Remap_PD01) || ((REMAP) == GPIO_Remap_TIM5CH4_LSI) || \
232→                              ((REMAP) == GPIO_Remap_ADC1_ETRGINJ) ||((REMAP) == GPIO_Remap_ADC1_ETRGREG) || \
233→                              ((REMAP) == GPIO_Remap_ADC2_ETRGINJ) ||((REMAP) == GPIO_Remap_ADC2_ETRGREG) || \
234→                              ((REMAP) == GPIO_Remap_ETH) ||((REMAP) == GPIO_Remap_CAN2) || \
235→                              ((REMAP) == GPIO_Remap_SWJ_NoJTRST) || ((REMAP) == GPIO_Remap_SWJ_JTAGDisable) || \
236→                              ((REMAP) == GPIO_Remap_SWJ_Disable)|| ((REMAP) == GPIO_Remap_SPI3) || \
237→                              ((REMAP) == GPIO_Remap_TIM2ITR1_PTP_SOF) || ((REMAP) == GPIO_Remap_PTP_PPS) || \
238→                              ((REMAP) == GPIO_Remap_TIM15) || ((REMAP) == GPIO_Remap_TIM16) || \
239→                              ((REMAP) == GPIO_Remap_TIM17) || ((REMAP) == GPIO_Remap_CEC) || \
240→                              ((REMAP) == GPIO_Remap_TIM1_DMA) || ((REMAP) == GPIO_Remap_TIM9) || \
241→                              ((REMAP) == GPIO_Remap_TIM10) || ((REMAP) == GPIO_Remap_TIM11) || \
242→                              ((REMAP) == GPIO_Remap_TIM13) || ((REMAP) == GPIO_Remap_TIM14) || \
243→                              ((REMAP) == GPIO_Remap_FSMC_NADV) || ((REMAP) == GPIO_Remap_TIM67_DAC_DMA) || \
244→                              ((REMAP) == GPIO_Remap_TIM12) || ((REMAP) == GPIO_Remap_MISC))
245→                              
246→/**
247→  * @}
248→  */ 
249→
250→/** @defgroup GPIO_Port_Sources 
251→  * @{
252→  */
253→
254→#define GPIO_PortSourceGPIOA       ((uint8_t)0x00)
255→#define GPIO_PortSourceGPIOB       ((uint8_t)0x01)
256→#define GPIO_PortSourceGPIOC       ((uint8_t)0x02)
257→#define GPIO_PortSourceGPIOD       ((uint8_t)0x03)
258→#define GPIO_PortSourceGPIOE       ((uint8_t)0x04)
259→#define GPIO_PortSourceGPIOF       ((uint8_t)0x05)
260→#define GPIO_PortSourceGPIOG       ((uint8_t)0x06)
261→#define IS_GPIO_EVENTOUT_PORT_SOURCE(PORTSOURCE) (((PORTSOURCE) == GPIO_PortSourceGPIOA) || \
262→                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOB) || \
263→                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOC) || \
264→                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOD) || \
265→                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOE))
266→
267→#define IS_GPIO_EXTI_PORT_SOURCE(PORTSOURCE) (((PORTSOURCE) == GPIO_PortSourceGPIOA) || \
268→                                              ((PORTSOURCE) == GPIO_PortSourceGPIOB) || \
269→                                              ((PORTSOURCE) == GPIO_PortSourceGPIOC) || \
270→                                              ((PORTSOURCE) == GPIO_PortSourceGPIOD) || \
271→                                              ((PORTSOURCE) == GPIO_PortSourceGPIOE) || \
272→                                              ((PORTSOURCE) == GPIO_PortSourceGPIOF) || \
273→                                              ((PORTSOURCE) == GPIO_PortSourceGPIOG))
274→
275→/**
276→  * @}
277→  */
278→
279→/** @defgroup GPIO_Pin_sources 
280→  * @{
281→  */
282→
283→#define GPIO_PinSource0            ((uint8_t)0x00)
284→#define GPIO_PinSource1            ((uint8_t)0x01)
285→#define GPIO_PinSource2            ((uint8_t)0x02)
286→#define GPIO_PinSource3            ((uint8_t)0x03)
287→#define GPIO_PinSource4            ((uint8_t)0x04)
288→#define GPIO_PinSource5            ((uint8_t)0x05)
289→#define GPIO_PinSource6            ((uint8_t)0x06)
290→#define GPIO_PinSource7            ((uint8_t)0x07)
291→#define GPIO_PinSource8            ((uint8_t)0x08)
292→#define GPIO_PinSource9            ((uint8_t)0x09)
293→#define GPIO_PinSource10           ((uint8_t)0x0A)
294→#define GPIO_PinSource11           ((uint8_t)0x0B)
295→#define GPIO_PinSource12           ((uint8_t)0x0C)
296→#define GPIO_PinSource13           ((uint8_t)0x0D)
297→#define GPIO_PinSource14           ((uint8_t)0x0E)
298→#define GPIO_PinSource15           ((uint8_t)0x0F)
299→
300→#define IS_GPIO_PIN_SOURCE(PINSOURCE) (((PINSOURCE) == GPIO_PinSource0) || \
301→                                       ((PINSOURCE) == GPIO_PinSource1) || \
302→                                       ((PINSOURCE) == GPIO_PinSource2) || \
303→                                       ((PINSOURCE) == GPIO_PinSource3) || \
304→                                       ((PINSOURCE) == GPIO_PinSource4) || \
305→                                       ((PINSOURCE) == GPIO_PinSource5) || \
306→                                       ((PINSOURCE) == GPIO_PinSource6) || \
307→                                       ((PINSOURCE) == GPIO_PinSource7) || \
308→                                       ((PINSOURCE) == GPIO_PinSource8) || \
309→                                       ((PINSOURCE) == GPIO_PinSource9) || \
310→                                       ((PINSOURCE) == GPIO_PinSource10) || \
311→                                       ((PINSOURCE) == GPIO_PinSource11) || \
312→                                       ((PINSOURCE) == GPIO_PinSource12) || \
313→                                       ((PINSOURCE) == GPIO_PinSource13) || \
314→                                       ((PINSOURCE) == GPIO_PinSource14) || \
315→                                       ((PINSOURCE) == GPIO_PinSource15))
316→
317→/**
318→  * @}
319→  */
320→
321→/** @defgroup Ethernet_Media_Interface 
322→  * @{
323→  */ 
324→#define GPIO_ETH_MediaInterface_MII    ((u32)0x00000000) 
325→#define GPIO_ETH_MediaInterface_RMII   ((u32)0x00000001)                                       
326→
327→#define IS_GPIO_ETH_MEDIA_INTERFACE(INTERFACE) (((INTERFACE) == GPIO_ETH_MediaInterface_MII) || \
328→                                                ((INTERFACE) == GPIO_ETH_MediaInterface_RMII))
329→
330→/**
331→  * @}
332→  */                                                
333→/**
334→  * @}
335→  */
336→
337→/** @defgroup GPIO_Exported_Macros
338→  * @{
339→  */
340→
341→/**
342→  * @}
343→  */
344→
345→/** @defgroup GPIO_Exported_Functions
346→  * @{
347→  */
348→
349→void GPIO_DeInit(GPIO_TypeDef* GPIOx);
350→void GPIO_AFIODeInit(void);
351→void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
352→void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
353→uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
354→uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
355→uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
356→uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
357→void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
358→void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
359→void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
360→void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
361→void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
362→void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
363→void GPIO_EventOutputCmd(FunctionalState NewState);
364→void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);
365→void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
366→void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);
367→
368→#ifdef __cplusplus
369→}
370→#endif
371→
372→#endif /* __STM32F10x_GPIO_H */
373→/**
374→  * @}
375→  */
376→
377→/**
378→  * @}
379→  */
380→
381→/**
382→  * @}
383→  */
384→
385→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/