  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_rcc.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the RCC firmware 
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
 24→#ifndef __STM32F10x_RCC_H
 25→#define __STM32F10x_RCC_H
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
 38→/** @addtogroup RCC
 39→  * @{
 40→  */
 41→
 42→/** @defgroup RCC_Exported_Types
 43→  * @{
 44→  */
 45→
 46→typedef struct
 47→{
 48→  uint32_t SYSCLK_Frequency;  /*!< returns SYSCLK clock frequency expressed in Hz */
 49→  uint32_t HCLK_Frequency;    /*!< returns HCLK clock frequency expressed in Hz */
 50→  uint32_t PCLK1_Frequency;   /*!< returns PCLK1 clock frequency expressed in Hz */
 51→  uint32_t PCLK2_Frequency;   /*!< returns PCLK2 clock frequency expressed in Hz */
 52→  uint32_t ADCCLK_Frequency;  /*!< returns ADCCLK clock frequency expressed in Hz */
 53→}RCC_ClocksTypeDef;
 54→
 55→/**
 56→  * @}
 57→  */
 58→
 59→/** @defgroup RCC_Exported_Constants
 60→  * @{
 61→  */
 62→
 63→/** @defgroup HSE_configuration 
 64→  * @{
 65→  */
 66→
 67→#define RCC_HSE_OFF                      ((uint32_t)0x00000000)
 68→#define RCC_HSE_ON                       ((uint32_t)0x00010000)
 69→#define RCC_HSE_Bypass                   ((uint32_t)0x00040000)
 70→#define IS_RCC_HSE(HSE) (((HSE) == RCC_HSE_OFF) || ((HSE) == RCC_HSE_ON) || \
 71→                         ((HSE) == RCC_HSE_Bypass))
 72→
 73→/**
 74→  * @}
 75→  */ 
 76→
 77→/** @defgroup PLL_entry_clock_source 
 78→  * @{
 79→  */
 80→
 81→#define RCC_PLLSource_HSI_Div2           ((uint32_t)0x00000000)
 82→
 83→#if !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD_VL) && !defined (STM32F10X_CL)
 84→ #define RCC_PLLSource_HSE_Div1           ((uint32_t)0x00010000)
 85→ #define RCC_PLLSource_HSE_Div2           ((uint32_t)0x00030000)
 86→ #define IS_RCC_PLL_SOURCE(SOURCE) (((SOURCE) == RCC_PLLSource_HSI_Div2) || \
 87→                                   ((SOURCE) == RCC_PLLSource_HSE_Div1) || \
 88→                                   ((SOURCE) == RCC_PLLSource_HSE_Div2))
 89→#else
 90→ #define RCC_PLLSource_PREDIV1            ((uint32_t)0x00010000)
 91→ #define IS_RCC_PLL_SOURCE(SOURCE) (((SOURCE) == RCC_PLLSource_HSI_Div2) || \
 92→                                   ((SOURCE) == RCC_PLLSource_PREDIV1))
 93→#endif /* STM32F10X_CL */ 
 94→
 95→/**
 96→  * @}
 97→  */ 
 98→
 99→/** @defgroup PLL_multiplication_factor 
100→  * @{
101→  */
102→#ifndef STM32F10X_CL
103→ #define RCC_PLLMul_2                    ((uint32_t)0x00000000)
104→ #define RCC_PLLMul_3                    ((uint32_t)0x00040000)
105→ #define RCC_PLLMul_4                    ((uint32_t)0x00080000)
106→ #define RCC_PLLMul_5                    ((uint32_t)0x000C0000)
107→ #define RCC_PLLMul_6                    ((uint32_t)0x00100000)
108→ #define RCC_PLLMul_7                    ((uint32_t)0x00140000)
109→ #define RCC_PLLMul_8                    ((uint32_t)0x00180000)
110→ #define RCC_PLLMul_9                    ((uint32_t)0x001C0000)
111→ #define RCC_PLLMul_10                   ((uint32_t)0x00200000)
112→ #define RCC_PLLMul_11                   ((uint32_t)0x00240000)
113→ #define RCC_PLLMul_12                   ((uint32_t)0x00280000)
114→ #define RCC_PLLMul_13                   ((uint32_t)0x002C0000)
115→ #define RCC_PLLMul_14                   ((uint32_t)0x00300000)
116→ #define RCC_PLLMul_15                   ((uint32_t)0x00340000)
117→ #define RCC_PLLMul_16                   ((uint32_t)0x00380000)
118→ #define IS_RCC_PLL_MUL(MUL) (((MUL) == RCC_PLLMul_2) || ((MUL) == RCC_PLLMul_3)   || \
119→                              ((MUL) == RCC_PLLMul_4) || ((MUL) == RCC_PLLMul_5)   || \
120→                              ((MUL) == RCC_PLLMul_6) || ((MUL) == RCC_PLLMul_7)   || \
121→                              ((MUL) == RCC_PLLMul_8) || ((MUL) == RCC_PLLMul_9)   || \
122→                              ((MUL) == RCC_PLLMul_10) || ((MUL) == RCC_PLLMul_11) || \
123→                              ((MUL) == RCC_PLLMul_12) || ((MUL) == RCC_PLLMul_13) || \
124→                              ((MUL) == RCC_PLLMul_14) || ((MUL) == RCC_PLLMul_15) || \
125→                              ((MUL) == RCC_PLLMul_16))
126→
127→#else
128→ #define RCC_PLLMul_4                    ((uint32_t)0x00080000)
129→ #define RCC_PLLMul_5                    ((uint32_t)0x000C0000)
130→ #define RCC_PLLMul_6                    ((uint32_t)0x00100000)
131→ #define RCC_PLLMul_7                    ((uint32_t)0x00140000)
132→ #define RCC_PLLMul_8                    ((uint32_t)0x00180000)
133→ #define RCC_PLLMul_9                    ((uint32_t)0x001C0000)
134→ #define RCC_PLLMul_6_5                  ((uint32_t)0x00340000)
135→
136→ #define IS_RCC_PLL_MUL(MUL) (((MUL) == RCC_PLLMul_4) || ((MUL) == RCC_PLLMul_5) || \
137→                              ((MUL) == RCC_PLLMul_6) || ((MUL) == RCC_PLLMul_7) || \
138→                              ((MUL) == RCC_PLLMul_8) || ((MUL) == RCC_PLLMul_9) || \
139→                              ((MUL) == RCC_PLLMul_6_5))
140→#endif /* STM32F10X_CL */                              
141→/**
142→  * @}
143→  */
144→
145→/** @defgroup PREDIV1_division_factor
146→  * @{
147→  */
148→#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL) || defined (STM32F10X_CL)
149→ #define  RCC_PREDIV1_Div1               ((uint32_t)0x00000000)
150→ #define  RCC_PREDIV1_Div2               ((uint32_t)0x00000001)
151→ #define  RCC_PREDIV1_Div3               ((uint32_t)0x00000002)
152→ #define  RCC_PREDIV1_Div4               ((uint32_t)0x00000003)
153→ #define  RCC_PREDIV1_Div5               ((uint32_t)0x00000004)
154→ #define  RCC_PREDIV1_Div6               ((uint32_t)0x00000005)
155→ #define  RCC_PREDIV1_Div7               ((uint32_t)0x00000006)
156→ #define  RCC_PREDIV1_Div8               ((uint32_t)0x00000007)
157→ #define  RCC_PREDIV1_Div9               ((uint32_t)0x00000008)
158→ #define  RCC_PREDIV1_Div10              ((uint32_t)0x00000009)
159→ #define  RCC_PREDIV1_Div11              ((uint32_t)0x0000000A)
160→ #define  RCC_PREDIV1_Div12              ((uint32_t)0x0000000B)
161→ #define  RCC_PREDIV1_Div13              ((uint32_t)0x0000000C)
162→ #define  RCC_PREDIV1_Div14              ((uint32_t)0x0000000D)
163→ #define  RCC_PREDIV1_Div15              ((uint32_t)0x0000000E)
164→ #define  RCC_PREDIV1_Div16              ((uint32_t)0x0000000F)
165→
166→ #define IS_RCC_PREDIV1(PREDIV1) (((PREDIV1) == RCC_PREDIV1_Div1) || ((PREDIV1) == RCC_PREDIV1_Div2) || \
167→                                  ((PREDIV1) == RCC_PREDIV1_Div3) || ((PREDIV1) == RCC_PREDIV1_Div4) || \
168→                                  ((PREDIV1) == RCC_PREDIV1_Div5) || ((PREDIV1) == RCC_PREDIV1_Div6) || \
169→                                  ((PREDIV1) == RCC_PREDIV1_Div7) || ((PREDIV1) == RCC_PREDIV1_Div8) || \
170→                                  ((PREDIV1) == RCC_PREDIV1_Div9) || ((PREDIV1) == RCC_PREDIV1_Div10) || \
171→                                  ((PREDIV1) == RCC_PREDIV1_Div11) || ((PREDIV1) == RCC_PREDIV1_Div12) || \
172→                                  ((PREDIV1) == RCC_PREDIV1_Div13) || ((PREDIV1) == RCC_PREDIV1_Div14) || \
173→                                  ((PREDIV1) == RCC_PREDIV1_Div15) || ((PREDIV1) == RCC_PREDIV1_Div16))
174→#endif
175→/**
176→  * @}
177→  */
178→
179→
180→/** @defgroup PREDIV1_clock_source
181→  * @{
182→  */
183→#ifdef STM32F10X_CL
184→/* PREDIV1 clock source (for STM32 connectivity line devices) */
185→ #define  RCC_PREDIV1_Source_HSE         ((uint32_t)0x00000000) 
186→ #define  RCC_PREDIV1_Source_PLL2        ((uint32_t)0x00010000) 
187→
188→ #define IS_RCC_PREDIV1_SOURCE(SOURCE) (((SOURCE) == RCC_PREDIV1_Source_HSE) || \
189→                                        ((SOURCE) == RCC_PREDIV1_Source_PLL2)) 
190→#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
191→/* PREDIV1 clock source (for STM32 Value line devices) */
192→ #define  RCC_PREDIV1_Source_HSE         ((uint32_t)0x00000000) 
193→
194→ #define IS_RCC_PREDIV1_SOURCE(SOURCE) (((SOURCE) == RCC_PREDIV1_Source_HSE)) 
195→#endif
196→/**
197→  * @}
198→  */
199→
200→#ifdef STM32F10X_CL
201→/** @defgroup PREDIV2_division_factor
202→  * @{
203→  */
204→  
205→ #define  RCC_PREDIV2_Div1               ((uint32_t)0x00000000)
206→ #define  RCC_PREDIV2_Div2               ((uint32_t)0x00000010)
207→ #define  RCC_PREDIV2_Div3               ((uint32_t)0x00000020)
208→ #define  RCC_PREDIV2_Div4               ((uint32_t)0x00000030)
209→ #define  RCC_PREDIV2_Div5               ((uint32_t)0x00000040)
210→ #define  RCC_PREDIV2_Div6               ((uint32_t)0x00000050)
211→ #define  RCC_PREDIV2_Div7               ((uint32_t)0x00000060)
212→ #define  RCC_PREDIV2_Div8               ((uint32_t)0x00000070)
213→ #define  RCC_PREDIV2_Div9               ((uint32_t)0x00000080)
214→ #define  RCC_PREDIV2_Div10              ((uint32_t)0x00000090)
215→ #define  RCC_PREDIV2_Div11              ((uint32_t)0x000000A0)
216→ #define  RCC_PREDIV2_Div12              ((uint32_t)0x000000B0)
217→ #define  RCC_PREDIV2_Div13              ((uint32_t)0x000000C0)
218→ #define  RCC_PREDIV2_Div14              ((uint32_t)0x000000D0)
219→ #define  RCC_PREDIV2_Div15              ((uint32_t)0x000000E0)
220→ #define  RCC_PREDIV2_Div16              ((uint32_t)0x000000F0)
221→
222→ #define IS_RCC_PREDIV2(PREDIV2) (((PREDIV2) == RCC_PREDIV2_Div1) || ((PREDIV2) == RCC_PREDIV2_Div2) || \
223→                                  ((PREDIV2) == RCC_PREDIV2_Div3) || ((PREDIV2) == RCC_PREDIV2_Div4) || \
224→                                  ((PREDIV2) == RCC_PREDIV2_Div5) || ((PREDIV2) == RCC_PREDIV2_Div6) || \
225→                                  ((PREDIV2) == RCC_PREDIV2_Div7) || ((PREDIV2) == RCC_PREDIV2_Div8) || \
226→                                  ((PREDIV2) == RCC_PREDIV2_Div9) || ((PREDIV2) == RCC_PREDIV2_Div10) || \
227→                                  ((PREDIV2) == RCC_PREDIV2_Div11) || ((PREDIV2) == RCC_PREDIV2_Div12) || \
228→                                  ((PREDIV2) == RCC_PREDIV2_Div13) || ((PREDIV2) == RCC_PREDIV2_Div14) || \
229→                                  ((PREDIV2) == RCC_PREDIV2_Div15) || ((PREDIV2) == RCC_PREDIV2_Div16))
230→/**
231→  * @}
232→  */
233→
234→
235→/** @defgroup PLL2_multiplication_factor
236→  * @{
237→  */
238→  
239→ #define  RCC_PLL2Mul_8                  ((uint32_t)0x00000600)
240→ #define  RCC_PLL2Mul_9                  ((uint32_t)0x00000700)
241→ #define  RCC_PLL2Mul_10                 ((uint32_t)0x00000800)
242→ #define  RCC_PLL2Mul_11                 ((uint32_t)0x00000900)
243→ #define  RCC_PLL2Mul_12                 ((uint32_t)0x00000A00)
244→ #define  RCC_PLL2Mul_13                 ((uint32_t)0x00000B00)
245→ #define  RCC_PLL2Mul_14                 ((uint32_t)0x00000C00)
246→ #define  RCC_PLL2Mul_16                 ((uint32_t)0x00000E00)
247→ #define  RCC_PLL2Mul_20                 ((uint32_t)0x00000F00)
248→
249→ #define IS_RCC_PLL2_MUL(MUL) (((MUL) == RCC_PLL2Mul_8) || ((MUL) == RCC_PLL2Mul_9)  || \
250→                               ((MUL) == RCC_PLL2Mul_10) || ((MUL) == RCC_PLL2Mul_11) || \
251→                               ((MUL) == RCC_PLL2Mul_12) || ((MUL) == RCC_PLL2Mul_13) || \
252→                               ((MUL) == RCC_PLL2Mul_14) || ((MUL) == RCC_PLL2Mul_16) || \
253→                               ((MUL) == RCC_PLL2Mul_20))
254→/**
255→  * @}
256→  */
257→
258→
259→/** @defgroup PLL3_multiplication_factor
260→  * @{
261→  */
262→
263→ #define  RCC_PLL3Mul_8                  ((uint32_t)0x00006000)
264→ #define  RCC_PLL3Mul_9                  ((uint32_t)0x00007000)
265→ #define  RCC_PLL3Mul_10                 ((uint32_t)0x00008000)
266→ #define  RCC_PLL3Mul_11                 ((uint32_t)0x00009000)
267→ #define  RCC_PLL3Mul_12                 ((uint32_t)0x0000A000)
268→ #define  RCC_PLL3Mul_13                 ((uint32_t)0x0000B000)
269→ #define  RCC_PLL3Mul_14                 ((uint32_t)0x0000C000)
270→ #define  RCC_PLL3Mul_16                 ((uint32_t)0x0000E000)
271→ #define  RCC_PLL3Mul_20                 ((uint32_t)0x0000F000)
272→
273→ #define IS_RCC_PLL3_MUL(MUL) (((MUL) == RCC_PLL3Mul_8) || ((MUL) == RCC_PLL3Mul_9)  || \
274→                               ((MUL) == RCC_PLL3Mul_10) || ((MUL) == RCC_PLL3Mul_11) || \
275→                               ((MUL) == RCC_PLL3Mul_12) || ((MUL) == RCC_PLL3Mul_13) || \
276→                               ((MUL) == RCC_PLL3Mul_14) || ((MUL) == RCC_PLL3Mul_16) || \
277→                               ((MUL) == RCC_PLL3Mul_20))
278→/**
279→  * @}
280→  */
281→
282→#endif /* STM32F10X_CL */
283→
284→
285→/** @defgroup System_clock_source 
286→  * @{
287→  */
288→
289→#define RCC_SYSCLKSource_HSI             ((uint32_t)0x00000000)
290→#define RCC_SYSCLKSource_HSE             ((uint32_t)0x00000001)
291→#define RCC_SYSCLKSource_PLLCLK          ((uint32_t)0x00000002)
292→#define IS_RCC_SYSCLK_SOURCE(SOURCE) (((SOURCE) == RCC_SYSCLKSource_HSI) || \
293→                                      ((SOURCE) == RCC_SYSCLKSource_HSE) || \
294→                                      ((SOURCE) == RCC_SYSCLKSource_PLLCLK))
295→/**
296→  * @}
297→  */
298→
299→/** @defgroup AHB_clock_source 
300→  * @{
301→  */
302→
303→#define RCC_SYSCLK_Div1                  ((uint32_t)0x00000000)
304→#define RCC_SYSCLK_Div2                  ((uint32_t)0x00000080)
305→#define RCC_SYSCLK_Div4                  ((uint32_t)0x00000090)
306→#define RCC_SYSCLK_Div8                  ((uint32_t)0x000000A0)
307→#define RCC_SYSCLK_Div16                 ((uint32_t)0x000000B0)
308→#define RCC_SYSCLK_Div64                 ((uint32_t)0x000000C0)
309→#define RCC_SYSCLK_Div128                ((uint32_t)0x000000D0)
310→#define RCC_SYSCLK_Div256                ((uint32_t)0x000000E0)
311→#define RCC_SYSCLK_Div512                ((uint32_t)0x000000F0)
312→#define IS_RCC_HCLK(HCLK) (((HCLK) == RCC_SYSCLK_Div1) || ((HCLK) == RCC_SYSCLK_Div2) || \
313→                           ((HCLK) == RCC_SYSCLK_Div4) || ((HCLK) == RCC_SYSCLK_Div8) || \
314→                           ((HCLK) == RCC_SYSCLK_Div16) || ((HCLK) == RCC_SYSCLK_Div64) || \
315→                           ((HCLK) == RCC_SYSCLK_Div128) || ((HCLK) == RCC_SYSCLK_Div256) || \
316→                           ((HCLK) == RCC_SYSCLK_Div512))
317→/**
318→  * @}
319→  */ 
320→
321→/** @defgroup APB1_APB2_clock_source 
322→  * @{
323→  */
324→
325→#define RCC_HCLK_Div1                    ((uint32_t)0x00000000)
326→#define RCC_HCLK_Div2                    ((uint32_t)0x00000400)
327→#define RCC_HCLK_Div4                    ((uint32_t)0x00000500)
328→#define RCC_HCLK_Div8                    ((uint32_t)0x00000600)
329→#define RCC_HCLK_Div16                   ((uint32_t)0x00000700)
330→#define IS_RCC_PCLK(PCLK) (((PCLK) == RCC_HCLK_Div1) || ((PCLK) == RCC_HCLK_Div2) || \
331→                           ((PCLK) == RCC_HCLK_Div4) || ((PCLK) == RCC_HCLK_Div8) || \
332→                           ((PCLK) == RCC_HCLK_Div16))
333→/**
334→  * @}
335→  */
336→
337→/** @defgroup RCC_Interrupt_source 
338→  * @{
339→  */
340→
341→#define RCC_IT_LSIRDY                    ((uint8_t)0x01)
342→#define RCC_IT_LSERDY                    ((uint8_t)0x02)
343→#define RCC_IT_HSIRDY                    ((uint8_t)0x04)
344→#define RCC_IT_HSERDY                    ((uint8_t)0x08)
345→#define RCC_IT_PLLRDY                    ((uint8_t)0x10)
346→#define RCC_IT_CSS                       ((uint8_t)0x80)
347→
348→#ifndef STM32F10X_CL
349→ #define IS_RCC_IT(IT) ((((IT) & (uint8_t)0xE0) == 0x00) && ((IT) != 0x00))
350→ #define IS_RCC_GET_IT(IT) (((IT) == RCC_IT_LSIRDY) || ((IT) == RCC_IT_LSERDY) || \
351→                            ((IT) == RCC_IT_HSIRDY) || ((IT) == RCC_IT_HSERDY) || \
352→                            ((IT) == RCC_IT_PLLRDY) || ((IT) == RCC_IT_CSS))
353→ #define IS_RCC_CLEAR_IT(IT) ((((IT) & (uint8_t)0x60) == 0x00) && ((IT) != 0x00))
354→#else
355→ #define RCC_IT_PLL2RDY                  ((uint8_t)0x20)
356→ #define RCC_IT_PLL3RDY                  ((uint8_t)0x40)
357→ #define IS_RCC_IT(IT) ((((IT) & (uint8_t)0x80) == 0x00) && ((IT) != 0x00))
358→ #define IS_RCC_GET_IT(IT) (((IT) == RCC_IT_LSIRDY) || ((IT) == RCC_IT_LSERDY) || \
359→                            ((IT) == RCC_IT_HSIRDY) || ((IT) == RCC_IT_HSERDY) || \
360→                            ((IT) == RCC_IT_PLLRDY) || ((IT) == RCC_IT_CSS) || \
361→                            ((IT) == RCC_IT_PLL2RDY) || ((IT) == RCC_IT_PLL3RDY))
362→ #define IS_RCC_CLEAR_IT(IT) ((IT) != 0x00)
363→#endif /* STM32F10X_CL */ 
364→
365→
366→/**
367→  * @}
368→  */
369→
370→#ifndef STM32F10X_CL
371→/** @defgroup USB_Device_clock_source 
372→  * @{
373→  */
374→
375→ #define RCC_USBCLKSource_PLLCLK_1Div5   ((uint8_t)0x00)
376→ #define RCC_USBCLKSource_PLLCLK_Div1    ((uint8_t)0x01)
377→
378→ #define IS_RCC_USBCLK_SOURCE(SOURCE) (((SOURCE) == RCC_USBCLKSource_PLLCLK_1Div5) || \
379→                                      ((SOURCE) == RCC_USBCLKSource_PLLCLK_Div1))
380→/**
381→  * @}
382→  */
383→#else
384→/** @defgroup USB_OTG_FS_clock_source 
385→  * @{
386→  */
387→ #define RCC_OTGFSCLKSource_PLLVCO_Div3    ((uint8_t)0x00)
388→ #define RCC_OTGFSCLKSource_PLLVCO_Div2    ((uint8_t)0x01)
389→
390→ #define IS_RCC_OTGFSCLK_SOURCE(SOURCE) (((SOURCE) == RCC_OTGFSCLKSource_PLLVCO_Div3) || \
391→                                         ((SOURCE) == RCC_OTGFSCLKSource_PLLVCO_Div2))
392→/**
393→  * @}
394→  */
395→#endif /* STM32F10X_CL */ 
396→
397→
398→#ifdef STM32F10X_CL
399→/** @defgroup I2S2_clock_source 
400→  * @{
401→  */
402→ #define RCC_I2S2CLKSource_SYSCLK        ((uint8_t)0x00)
403→ #define RCC_I2S2CLKSource_PLL3_VCO      ((uint8_t)0x01)
404→
405→ #define IS_RCC_I2S2CLK_SOURCE(SOURCE) (((SOURCE) == RCC_I2S2CLKSource_SYSCLK) || \
406→                                        ((SOURCE) == RCC_I2S2CLKSource_PLL3_VCO))
407→/**
408→  * @}
409→  */
410→
411→/** @defgroup I2S3_clock_source 
412→  * @{
413→  */
414→ #define RCC_I2S3CLKSource_SYSCLK        ((uint8_t)0x00)
415→ #define RCC_I2S3CLKSource_PLL3_VCO      ((uint8_t)0x01)
416→
417→ #define IS_RCC_I2S3CLK_SOURCE(SOURCE) (((SOURCE) == RCC_I2S3CLKSource_SYSCLK) || \
418→                                        ((SOURCE) == RCC_I2S3CLKSource_PLL3_VCO))    
419→/**
420→  * @}
421→  */
422→#endif /* STM32F10X_CL */  
423→  
424→
425→/** @defgroup ADC_clock_source 
426→  * @{
427→  */
428→
429→#define RCC_PCLK2_Div2                   ((uint32_t)0x00000000)
430→#define RCC_PCLK2_Div4                   ((uint32_t)0x00004000)
431→#define RCC_PCLK2_Div6                   ((uint32_t)0x00008000)
432→#define RCC_PCLK2_Div8                   ((uint32_t)0x0000C000)
433→#define IS_RCC_ADCCLK(ADCCLK) (((ADCCLK) == RCC_PCLK2_Div2) || ((ADCCLK) == RCC_PCLK2_Div4) || \
434→                               ((ADCCLK) == RCC_PCLK2_Div6) || ((ADCCLK) == RCC_PCLK2_Div8))
435→/**
436→  * @}
437→  */
438→
439→/** @defgroup LSE_configuration 
440→  * @{
441→  */
442→
443→#define RCC_LSE_OFF                      ((uint8_t)0x00)
444→#define RCC_LSE_ON                       ((uint8_t)0x01)
445→#define RCC_LSE_Bypass                   ((uint8_t)0x04)
446→#define IS_RCC_LSE(LSE) (((LSE) == RCC_LSE_OFF) || ((LSE) == RCC_LSE_ON) || \
447→                         ((LSE) == RCC_LSE_Bypass))
448→/**
449→  * @}
450→  */
451→
452→/** @defgroup RTC_clock_source 
453→  * @{
454→  */
455→
456→#define RCC_RTCCLKSource_LSE             ((uint32_t)0x00000100)
457→#define RCC_RTCCLKSource_LSI             ((uint32_t)0x00000200)
458→#define RCC_RTCCLKSource_HSE_Div128      ((uint32_t)0x00000300)
459→#define IS_RCC_RTCCLK_SOURCE(SOURCE) (((SOURCE) == RCC_RTCCLKSource_LSE) || \
460→                                      ((SOURCE) == RCC_RTCCLKSource_LSI) || \
461→                                      ((SOURCE) == RCC_RTCCLKSource_HSE_Div128))
462→/**
463→  * @}
464→  */
465→
466→/** @defgroup AHB_peripheral 
467→  * @{
468→  */
469→
470→#define RCC_AHBPeriph_DMA1               ((uint32_t)0x00000001)
471→#define RCC_AHBPeriph_DMA2               ((uint32_t)0x00000002)
472→#define RCC_AHBPeriph_SRAM               ((uint32_t)0x00000004)
473→#define RCC_AHBPeriph_FLITF              ((uint32_t)0x00000010)
474→#define RCC_AHBPeriph_CRC                ((uint32_t)0x00000040)
475→
476→#ifndef STM32F10X_CL
477→ #define RCC_AHBPeriph_FSMC              ((uint32_t)0x00000100)
478→ #define RCC_AHBPeriph_SDIO              ((uint32_t)0x00000400)
479→ #define IS_RCC_AHB_PERIPH(PERIPH) ((((PERIPH) & 0xFFFFFAA8) == 0x00) && ((PERIPH) != 0x00))
480→#else
481→ #define RCC_AHBPeriph_OTG_FS            ((uint32_t)0x00001000)
482→ #define RCC_AHBPeriph_ETH_MAC           ((uint32_t)0x00004000)
483→ #define RCC_AHBPeriph_ETH_MAC_Tx        ((uint32_t)0x00008000)
484→ #define RCC_AHBPeriph_ETH_MAC_Rx        ((uint32_t)0x00010000)
485→
486→ #define IS_RCC_AHB_PERIPH(PERIPH) ((((PERIPH) & 0xFFFE2FA8) == 0x00) && ((PERIPH) != 0x00))
487→ #define IS_RCC_AHB_PERIPH_RESET(PERIPH) ((((PERIPH) & 0xFFFFAFFF) == 0x00) && ((PERIPH) != 0x00))
488→#endif /* STM32F10X_CL */
489→/**
490→  * @}
491→  */
492→
493→/** @defgroup APB2_peripheral 
494→  * @{
495→  */
496→
497→#define RCC_APB2Periph_AFIO              ((uint32_t)0x00000001)
498→#define RCC_APB2Periph_GPIOA             ((uint32_t)0x00000004)
499→#define RCC_APB2Periph_GPIOB             ((uint32_t)0x00000008)
500→#define RCC_APB2Periph_GPIOC             ((uint32_t)0x00000010)
501→#define RCC_APB2Periph_GPIOD             ((uint32_t)0x00000020)
502→#define RCC_APB2Periph_GPIOE             ((uint32_t)0x00000040)
503→#define RCC_APB2Periph_GPIOF             ((uint32_t)0x00000080)
504→#define RCC_APB2Periph_GPIOG             ((uint32_t)0x00000100)
505→#define RCC_APB2Periph_ADC1              ((uint32_t)0x00000200)
506→#define RCC_APB2Periph_ADC2              ((uint32_t)0x00000400)
507→#define RCC_APB2Periph_TIM1              ((uint32_t)0x00000800)
508→#define RCC_APB2Periph_SPI1              ((uint32_t)0x00001000)
509→#define RCC_APB2Periph_TIM8              ((uint32_t)0x00002000)
510→#define RCC_APB2Periph_USART1            ((uint32_t)0x00004000)
511→#define RCC_APB2Periph_ADC3              ((uint32_t)0x00008000)
512→#define RCC_APB2Periph_TIM15             ((uint32_t)0x00010000)
513→#define RCC_APB2Periph_TIM16             ((uint32_t)0x00020000)
514→#define RCC_APB2Periph_TIM17             ((uint32_t)0x00040000)
515→#define RCC_APB2Periph_TIM9              ((uint32_t)0x00080000)
516→#define RCC_APB2Periph_TIM10             ((uint32_t)0x00100000)
517→#define RCC_APB2Periph_TIM11             ((uint32_t)0x00200000)
518→
519→#define IS_RCC_APB2_PERIPH(PERIPH) ((((PERIPH) & 0xFFC00002) == 0x00) && ((PERIPH) != 0x00))
520→/**
521→  * @}
522→  */ 
523→
524→/** @defgroup APB1_peripheral 
525→  * @{
526→  */
527→
528→#define RCC_APB1Periph_TIM2              ((uint32_t)0x00000001)
529→#define RCC_APB1Periph_TIM3              ((uint32_t)0x00000002)
530→#define RCC_APB1Periph_TIM4              ((uint32_t)0x00000004)
531→#define RCC_APB1Periph_TIM5              ((uint32_t)0x00000008)
532→#define RCC_APB1Periph_TIM6              ((uint32_t)0x00000010)
533→#define RCC_APB1Periph_TIM7              ((uint32_t)0x00000020)
534→#define RCC_APB1Periph_TIM12             ((uint32_t)0x00000040)
535→#define RCC_APB1Periph_TIM13             ((uint32_t)0x00000080)
536→#define RCC_APB1Periph_TIM14             ((uint32_t)0x00000100)
537→#define RCC_APB1Periph_WWDG              ((uint32_t)0x00000800)
538→#define RCC_APB1Periph_SPI2              ((uint32_t)0x00004000)
539→#define RCC_APB1Periph_SPI3              ((uint32_t)0x00008000)
540→#define RCC_APB1Periph_USART2            ((uint32_t)0x00020000)
541→#define RCC_APB1Periph_USART3            ((uint32_t)0x00040000)
542→#define RCC_APB1Periph_UART4             ((uint32_t)0x00080000)
543→#define RCC_APB1Periph_UART5             ((uint32_t)0x00100000)
544→#define RCC_APB1Periph_I2C1              ((uint32_t)0x00200000)
545→#define RCC_APB1Periph_I2C2              ((uint32_t)0x00400000)
546→#define RCC_APB1Periph_USB               ((uint32_t)0x00800000)
547→#define RCC_APB1Periph_CAN1              ((uint32_t)0x02000000)
548→#define RCC_APB1Periph_CAN2              ((uint32_t)0x04000000)
549→#define RCC_APB1Periph_BKP               ((uint32_t)0x08000000)
550→#define RCC_APB1Periph_PWR               ((uint32_t)0x10000000)
551→#define RCC_APB1Periph_DAC               ((uint32_t)0x20000000)
552→#define RCC_APB1Periph_CEC               ((uint32_t)0x40000000)
553→ 
554→#define IS_RCC_APB1_PERIPH(PERIPH) ((((PERIPH) & 0x81013600) == 0x00) && ((PERIPH) != 0x00))
555→
556→/**
557→  * @}
558→  */
559→
560→/** @defgroup Clock_source_to_output_on_MCO_pin 
561→  * @{
562→  */
563→
564→#define RCC_MCO_NoClock                  ((uint8_t)0x00)
565→#define RCC_MCO_SYSCLK                   ((uint8_t)0x04)
566→#define RCC_MCO_HSI                      ((uint8_t)0x05)
567→#define RCC_MCO_HSE                      ((uint8_t)0x06)
568→#define RCC_MCO_PLLCLK_Div2              ((uint8_t)0x07)
569→
570→#ifndef STM32F10X_CL
571→ #define IS_RCC_MCO(MCO) (((MCO) == RCC_MCO_NoClock) || ((MCO) == RCC_MCO_HSI) || \
572→                          ((MCO) == RCC_MCO_SYSCLK)  || ((MCO) == RCC_MCO_HSE) || \
573→                          ((MCO) == RCC_MCO_PLLCLK_Div2))
574→#else
575→ #define RCC_MCO_PLL2CLK                 ((uint8_t)0x08)
576→ #define RCC_MCO_PLL3CLK_Div2            ((uint8_t)0x09)
577→ #define RCC_MCO_XT1                     ((uint8_t)0x0A)
578→ #define RCC_MCO_PLL3CLK                 ((uint8_t)0x0B)
579→
580→ #define IS_RCC_MCO(MCO) (((MCO) == RCC_MCO_NoClock) || ((MCO) == RCC_MCO_HSI) || \
581→                          ((MCO) == RCC_MCO_SYSCLK)  || ((MCO) == RCC_MCO_HSE) || \
582→                          ((MCO) == RCC_MCO_PLLCLK_Div2) || ((MCO) == RCC_MCO_PLL2CLK) || \
583→                          ((MCO) == RCC_MCO_PLL3CLK_Div2) || ((MCO) == RCC_MCO_XT1) || \
584→                          ((MCO) == RCC_MCO_PLL3CLK))
585→#endif /* STM32F10X_CL */ 
586→
587→/**
588→  * @}
589→  */
590→
591→/** @defgroup RCC_Flag 
592→  * @{
593→  */
594→
595→#define RCC_FLAG_HSIRDY                  ((uint8_t)0x21)
596→#define RCC_FLAG_HSERDY                  ((uint8_t)0x31)
597→#define RCC_FLAG_PLLRDY                  ((uint8_t)0x39)
598→#define RCC_FLAG_LSERDY                  ((uint8_t)0x41)
599→#define RCC_FLAG_LSIRDY                  ((uint8_t)0x61)
600→#define RCC_FLAG_PINRST                  ((uint8_t)0x7A)
601→#define RCC_FLAG_PORRST                  ((uint8_t)0x7B)
602→#define RCC_FLAG_SFTRST                  ((uint8_t)0x7C)
603→#define RCC_FLAG_IWDGRST                 ((uint8_t)0x7D)
604→#define RCC_FLAG_WWDGRST                 ((uint8_t)0x7E)
605→#define RCC_FLAG_LPWRRST                 ((uint8_t)0x7F)
606→
607→#ifndef STM32F10X_CL
608→ #define IS_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_HSIRDY) || ((FLAG) == RCC_FLAG_HSERDY) || \
609→                            ((FLAG) == RCC_FLAG_PLLRDY) || ((FLAG) == RCC_FLAG_LSERDY) || \
610→                            ((FLAG) == RCC_FLAG_LSIRDY) || ((FLAG) == RCC_FLAG_PINRST) || \
611→                            ((FLAG) == RCC_FLAG_PORRST) || ((FLAG) == RCC_FLAG_SFTRST) || \
612→                            ((FLAG) == RCC_FLAG_IWDGRST)|| ((FLAG) == RCC_FLAG_WWDGRST)|| \
613→                            ((FLAG) == RCC_FLAG_LPWRRST))
614→#else
615→ #define RCC_FLAG_PLL2RDY                ((uint8_t)0x3B) 
616→ #define RCC_FLAG_PLL3RDY                ((uint8_t)0x3D) 
617→ #define IS_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_HSIRDY) || ((FLAG) == RCC_FLAG_HSERDY) || \
618→                            ((FLAG) == RCC_FLAG_PLLRDY) || ((FLAG) == RCC_FLAG_LSERDY) || \
619→                            ((FLAG) == RCC_FLAG_PLL2RDY) || ((FLAG) == RCC_FLAG_PLL3RDY) || \
620→                            ((FLAG) == RCC_FLAG_LSIRDY) || ((FLAG) == RCC_FLAG_PINRST) || \
621→                            ((FLAG) == RCC_FLAG_PORRST) || ((FLAG) == RCC_FLAG_SFTRST) || \
622→                            ((FLAG) == RCC_FLAG_IWDGRST)|| ((FLAG) == RCC_FLAG_WWDGRST)|| \
623→                            ((FLAG) == RCC_FLAG_LPWRRST))
624→#endif /* STM32F10X_CL */ 
625→
626→#define IS_RCC_CALIBRATION_VALUE(VALUE) ((VALUE) <= 0x1F)
627→/**
628→  * @}
629→  */
630→
631→/**
632→  * @}
633→  */
634→
635→/** @defgroup RCC_Exported_Macros
636→  * @{
637→  */
638→
639→/**
640→  * @}
641→  */
642→
643→/** @defgroup RCC_Exported_Functions
644→  * @{
645→  */
646→
647→void RCC_DeInit(void);
648→void RCC_HSEConfig(uint32_t RCC_HSE);
649→ErrorStatus RCC_WaitForHSEStartUp(void);
650→void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
651→void RCC_HSICmd(FunctionalState NewState);
652→void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
653→void RCC_PLLCmd(FunctionalState NewState);
654→
655→#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL) || defined (STM32F10X_CL)
656→ void RCC_PREDIV1Config(uint32_t RCC_PREDIV1_Source, uint32_t RCC_PREDIV1_Div);
657→#endif
658→
659→#ifdef  STM32F10X_CL
660→ void RCC_PREDIV2Config(uint32_t RCC_PREDIV2_Div);
661→ void RCC_PLL2Config(uint32_t RCC_PLL2Mul);
662→ void RCC_PLL2Cmd(FunctionalState NewState);
663→ void RCC_PLL3Config(uint32_t RCC_PLL3Mul);
664→ void RCC_PLL3Cmd(FunctionalState NewState);
665→#endif /* STM32F10X_CL */ 
666→
667→void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
668→uint8_t RCC_GetSYSCLKSource(void);
669→void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
670→void RCC_PCLK1Config(uint32_t RCC_HCLK);
671→void RCC_PCLK2Config(uint32_t RCC_HCLK);
672→void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);
673→
674→#ifndef STM32F10X_CL
675→ void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);
676→#else
677→ void RCC_OTGFSCLKConfig(uint32_t RCC_OTGFSCLKSource);
678→#endif /* STM32F10X_CL */ 
679→
680→void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);
681→
682→#ifdef STM32F10X_CL
683→ void RCC_I2S2CLKConfig(uint32_t RCC_I2S2CLKSource);                                  
684→ void RCC_I2S3CLKConfig(uint32_t RCC_I2S3CLKSource);
685→#endif /* STM32F10X_CL */ 
686→
687→void RCC_LSEConfig(uint8_t RCC_LSE);
688→void RCC_LSICmd(FunctionalState NewState);
689→void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
690→void RCC_RTCCLKCmd(FunctionalState NewState);
691→void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
692→void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
693→void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
694→void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
695→
696→#ifdef STM32F10X_CL
697→void RCC_AHBPeriphResetCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
698→#endif /* STM32F10X_CL */ 
699→
700→void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
701→void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
702→void RCC_BackupResetCmd(FunctionalState NewState);
703→void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
704→void RCC_MCOConfig(uint8_t RCC_MCO);
705→FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
706→void RCC_ClearFlag(void);
707→ITStatus RCC_GetITStatus(uint8_t RCC_IT);
708→void RCC_ClearITPendingBit(uint8_t RCC_IT);
709→
710→#ifdef __cplusplus
711→}
712→#endif
713→
714→#endif /* __STM32F10x_RCC_H */
715→/**
716→  * @}
717→  */
718→
719→/**
720→  * @}
721→  */
722→
723→/**
724→  * @}
725→  */ 
726→
727→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/