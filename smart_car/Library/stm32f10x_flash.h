  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_flash.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the FLASH 
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
 24→#ifndef __STM32F10x_FLASH_H
 25→#define __STM32F10x_FLASH_H
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
 38→/** @addtogroup FLASH
 39→  * @{
 40→  */
 41→
 42→/** @defgroup FLASH_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  FLASH Status  
 48→  */
 49→
 50→typedef enum
 51→{ 
 52→  FLASH_BUSY = 1,
 53→  FLASH_ERROR_PG,
 54→  FLASH_ERROR_WRP,
 55→  FLASH_COMPLETE,
 56→  FLASH_TIMEOUT
 57→}FLASH_Status;
 58→
 59→/**
 60→  * @}
 61→  */
 62→
 63→/** @defgroup FLASH_Exported_Constants
 64→  * @{
 65→  */
 66→
 67→/** @defgroup Flash_Latency 
 68→  * @{
 69→  */
 70→
 71→#define FLASH_Latency_0                ((uint32_t)0x00000000)  /*!< FLASH Zero Latency cycle */
 72→#define FLASH_Latency_1                ((uint32_t)0x00000001)  /*!< FLASH One Latency cycle */
 73→#define FLASH_Latency_2                ((uint32_t)0x00000002)  /*!< FLASH Two Latency cycles */
 74→#define IS_FLASH_LATENCY(LATENCY) (((LATENCY) == FLASH_Latency_0) || \
 75→                                   ((LATENCY) == FLASH_Latency_1) || \
 76→                                   ((LATENCY) == FLASH_Latency_2))
 77→/**
 78→  * @}
 79→  */
 80→
 81→/** @defgroup Half_Cycle_Enable_Disable 
 82→  * @{
 83→  */
 84→
 85→#define FLASH_HalfCycleAccess_Enable   ((uint32_t)0x00000008)  /*!< FLASH Half Cycle Enable */
 86→#define FLASH_HalfCycleAccess_Disable  ((uint32_t)0x00000000)  /*!< FLASH Half Cycle Disable */
 87→#define IS_FLASH_HALFCYCLEACCESS_STATE(STATE) (((STATE) == FLASH_HalfCycleAccess_Enable) || \
 88→                                               ((STATE) == FLASH_HalfCycleAccess_Disable)) 
 89→/**
 90→  * @}
 91→  */
 92→
 93→/** @defgroup Prefetch_Buffer_Enable_Disable 
 94→  * @{
 95→  */
 96→
 97→#define FLASH_PrefetchBuffer_Enable    ((uint32_t)0x00000010)  /*!< FLASH Prefetch Buffer Enable */
 98→#define FLASH_PrefetchBuffer_Disable   ((uint32_t)0x00000000)  /*!< FLASH Prefetch Buffer Disable */
 99→#define IS_FLASH_PREFETCHBUFFER_STATE(STATE) (((STATE) == FLASH_PrefetchBuffer_Enable) || \
100→                                              ((STATE) == FLASH_PrefetchBuffer_Disable)) 
101→/**
102→  * @}
103→  */
104→
105→/** @defgroup Option_Bytes_Write_Protection 
106→  * @{
107→  */
108→
109→/* Values to be used with STM32 Low and Medium density devices */
110→#define FLASH_WRProt_Pages0to3         ((uint32_t)0x00000001) /*!< STM32 Low and Medium density devices: Write protection of page 0 to 3 */
111→#define FLASH_WRProt_Pages4to7         ((uint32_t)0x00000002) /*!< STM32 Low and Medium density devices: Write protection of page 4 to 7 */
112→#define FLASH_WRProt_Pages8to11        ((uint32_t)0x00000004) /*!< STM32 Low and Medium density devices: Write protection of page 8 to 11 */
113→#define FLASH_WRProt_Pages12to15       ((uint32_t)0x00000008) /*!< STM32 Low and Medium density devices: Write protection of page 12 to 15 */
114→#define FLASH_WRProt_Pages16to19       ((uint32_t)0x00000010) /*!< STM32 Low and Medium density devices: Write protection of page 16 to 19 */
115→#define FLASH_WRProt_Pages20to23       ((uint32_t)0x00000020) /*!< STM32 Low and Medium density devices: Write protection of page 20 to 23 */
116→#define FLASH_WRProt_Pages24to27       ((uint32_t)0x00000040) /*!< STM32 Low and Medium density devices: Write protection of page 24 to 27 */
117→#define FLASH_WRProt_Pages28to31       ((uint32_t)0x00000080) /*!< STM32 Low and Medium density devices: Write protection of page 28 to 31 */
118→
119→/* Values to be used with STM32 Medium-density devices */
120→#define FLASH_WRProt_Pages32to35       ((uint32_t)0x00000100) /*!< STM32 Medium-density devices: Write protection of page 32 to 35 */
121→#define FLASH_WRProt_Pages36to39       ((uint32_t)0x00000200) /*!< STM32 Medium-density devices: Write protection of page 36 to 39 */
122→#define FLASH_WRProt_Pages40to43       ((uint32_t)0x00000400) /*!< STM32 Medium-density devices: Write protection of page 40 to 43 */
123→#define FLASH_WRProt_Pages44to47       ((uint32_t)0x00000800) /*!< STM32 Medium-density devices: Write protection of page 44 to 47 */
124→#define FLASH_WRProt_Pages48to51       ((uint32_t)0x00001000) /*!< STM32 Medium-density devices: Write protection of page 48 to 51 */
125→#define FLASH_WRProt_Pages52to55       ((uint32_t)0x00002000) /*!< STM32 Medium-density devices: Write protection of page 52 to 55 */
126→#define FLASH_WRProt_Pages56to59       ((uint32_t)0x00004000) /*!< STM32 Medium-density devices: Write protection of page 56 to 59 */
127→#define FLASH_WRProt_Pages60to63       ((uint32_t)0x00008000) /*!< STM32 Medium-density devices: Write protection of page 60 to 63 */
128→#define FLASH_WRProt_Pages64to67       ((uint32_t)0x00010000) /*!< STM32 Medium-density devices: Write protection of page 64 to 67 */
129→#define FLASH_WRProt_Pages68to71       ((uint32_t)0x00020000) /*!< STM32 Medium-density devices: Write protection of page 68 to 71 */
130→#define FLASH_WRProt_Pages72to75       ((uint32_t)0x00040000) /*!< STM32 Medium-density devices: Write protection of page 72 to 75 */
131→#define FLASH_WRProt_Pages76to79       ((uint32_t)0x00080000) /*!< STM32 Medium-density devices: Write protection of page 76 to 79 */
132→#define FLASH_WRProt_Pages80to83       ((uint32_t)0x00100000) /*!< STM32 Medium-density devices: Write protection of page 80 to 83 */
133→#define FLASH_WRProt_Pages84to87       ((uint32_t)0x00200000) /*!< STM32 Medium-density devices: Write protection of page 84 to 87 */
134→#define FLASH_WRProt_Pages88to91       ((uint32_t)0x00400000) /*!< STM32 Medium-density devices: Write protection of page 88 to 91 */
135→#define FLASH_WRProt_Pages92to95       ((uint32_t)0x00800000) /*!< STM32 Medium-density devices: Write protection of page 92 to 95 */
136→#define FLASH_WRProt_Pages96to99       ((uint32_t)0x01000000) /*!< STM32 Medium-density devices: Write protection of page 96 to 99 */
137→#define FLASH_WRProt_Pages100to103     ((uint32_t)0x02000000) /*!< STM32 Medium-density devices: Write protection of page 100 to 103 */
138→#define FLASH_WRProt_Pages104to107     ((uint32_t)0x04000000) /*!< STM32 Medium-density devices: Write protection of page 104 to 107 */
139→#define FLASH_WRProt_Pages108to111     ((uint32_t)0x08000000) /*!< STM32 Medium-density devices: Write protection of page 108 to 111 */
140→#define FLASH_WRProt_Pages112to115     ((uint32_t)0x10000000) /*!< STM32 Medium-density devices: Write protection of page 112 to 115 */
141→#define FLASH_WRProt_Pages116to119     ((uint32_t)0x20000000) /*!< STM32 Medium-density devices: Write protection of page 115 to 119 */
142→#define FLASH_WRProt_Pages120to123     ((uint32_t)0x40000000) /*!< STM32 Medium-density devices: Write protection of page 120 to 123 */
143→#define FLASH_WRProt_Pages124to127     ((uint32_t)0x80000000) /*!< STM32 Medium-density devices: Write protection of page 124 to 127 */
144→
145→/* Values to be used with STM32 High-density and STM32F10X Connectivity line devices */
146→#define FLASH_WRProt_Pages0to1         ((uint32_t)0x00000001) /*!< STM32 High-density, XL-density and Connectivity line devices:
147→                                                                   Write protection of page 0 to 1 */
148→#define FLASH_WRProt_Pages2to3         ((uint32_t)0x00000002) /*!< STM32 High-density, XL-density and Connectivity line devices:
149→                                                                   Write protection of page 2 to 3 */
150→#define FLASH_WRProt_Pages4to5         ((uint32_t)0x00000004) /*!< STM32 High-density, XL-density and Connectivity line devices:
151→                                                                   Write protection of page 4 to 5 */
152→#define FLASH_WRProt_Pages6to7         ((uint32_t)0x00000008) /*!< STM32 High-density, XL-density and Connectivity line devices:
153→                                                                   Write protection of page 6 to 7 */
154→#define FLASH_WRProt_Pages8to9         ((uint32_t)0x00000010) /*!< STM32 High-density, XL-density and Connectivity line devices:
155→                                                                   Write protection of page 8 to 9 */
156→#define FLASH_WRProt_Pages10to11       ((uint32_t)0x00000020) /*!< STM32 High-density, XL-density and Connectivity line devices:
157→                                                                   Write protection of page 10 to 11 */
158→#define FLASH_WRProt_Pages12to13       ((uint32_t)0x00000040) /*!< STM32 High-density, XL-density and Connectivity line devices:
159→                                                                   Write protection of page 12 to 13 */
160→#define FLASH_WRProt_Pages14to15       ((uint32_t)0x00000080) /*!< STM32 High-density, XL-density and Connectivity line devices:
161→                                                                   Write protection of page 14 to 15 */
162→#define FLASH_WRProt_Pages16to17       ((uint32_t)0x00000100) /*!< STM32 High-density, XL-density and Connectivity line devices:
163→                                                                   Write protection of page 16 to 17 */
164→#define FLASH_WRProt_Pages18to19       ((uint32_t)0x00000200) /*!< STM32 High-density, XL-density and Connectivity line devices:
165→                                                                   Write protection of page 18 to 19 */
166→#define FLASH_WRProt_Pages20to21       ((uint32_t)0x00000400) /*!< STM32 High-density, XL-density and Connectivity line devices:
167→                                                                   Write protection of page 20 to 21 */
168→#define FLASH_WRProt_Pages22to23       ((uint32_t)0x00000800) /*!< STM32 High-density, XL-density and Connectivity line devices:
169→                                                                   Write protection of page 22 to 23 */
170→#define FLASH_WRProt_Pages24to25       ((uint32_t)0x00001000) /*!< STM32 High-density, XL-density and Connectivity line devices:
171→                                                                   Write protection of page 24 to 25 */
172→#define FLASH_WRProt_Pages26to27       ((uint32_t)0x00002000) /*!< STM32 High-density, XL-density and Connectivity line devices:
173→                                                                   Write protection of page 26 to 27 */
174→#define FLASH_WRProt_Pages28to29       ((uint32_t)0x00004000) /*!< STM32 High-density, XL-density and Connectivity line devices:
175→                                                                   Write protection of page 28 to 29 */
176→#define FLASH_WRProt_Pages30to31       ((uint32_t)0x00008000) /*!< STM32 High-density, XL-density and Connectivity line devices:
177→                                                                   Write protection of page 30 to 31 */
178→#define FLASH_WRProt_Pages32to33       ((uint32_t)0x00010000) /*!< STM32 High-density, XL-density and Connectivity line devices:
179→                                                                   Write protection of page 32 to 33 */
180→#define FLASH_WRProt_Pages34to35       ((uint32_t)0x00020000) /*!< STM32 High-density, XL-density and Connectivity line devices:
181→                                                                   Write protection of page 34 to 35 */
182→#define FLASH_WRProt_Pages36to37       ((uint32_t)0x00040000) /*!< STM32 High-density, XL-density and Connectivity line devices:
183→                                                                   Write protection of page 36 to 37 */
184→#define FLASH_WRProt_Pages38to39       ((uint32_t)0x00080000) /*!< STM32 High-density, XL-density and Connectivity line devices:
185→                                                                   Write protection of page 38 to 39 */
186→#define FLASH_WRProt_Pages40to41       ((uint32_t)0x00100000) /*!< STM32 High-density, XL-density and Connectivity line devices:
187→                                                                   Write protection of page 40 to 41 */
188→#define FLASH_WRProt_Pages42to43       ((uint32_t)0x00200000) /*!< STM32 High-density, XL-density and Connectivity line devices:
189→                                                                   Write protection of page 42 to 43 */
190→#define FLASH_WRProt_Pages44to45       ((uint32_t)0x00400000) /*!< STM32 High-density, XL-density and Connectivity line devices:
191→                                                                   Write protection of page 44 to 45 */
192→#define FLASH_WRProt_Pages46to47       ((uint32_t)0x00800000) /*!< STM32 High-density, XL-density and Connectivity line devices:
193→                                                                   Write protection of page 46 to 47 */
194→#define FLASH_WRProt_Pages48to49       ((uint32_t)0x01000000) /*!< STM32 High-density, XL-density and Connectivity line devices:
195→                                                                   Write protection of page 48 to 49 */
196→#define FLASH_WRProt_Pages50to51       ((uint32_t)0x02000000) /*!< STM32 High-density, XL-density and Connectivity line devices:
197→                                                                   Write protection of page 50 to 51 */
198→#define FLASH_WRProt_Pages52to53       ((uint32_t)0x04000000) /*!< STM32 High-density, XL-density and Connectivity line devices:
199→                                                                   Write protection of page 52 to 53 */
200→#define FLASH_WRProt_Pages54to55       ((uint32_t)0x08000000) /*!< STM32 High-density, XL-density and Connectivity line devices:
201→                                                                   Write protection of page 54 to 55 */
202→#define FLASH_WRProt_Pages56to57       ((uint32_t)0x10000000) /*!< STM32 High-density, XL-density and Connectivity line devices:
203→                                                                   Write protection of page 56 to 57 */
204→#define FLASH_WRProt_Pages58to59       ((uint32_t)0x20000000) /*!< STM32 High-density, XL-density and Connectivity line devices:
205→                                                                   Write protection of page 58 to 59 */
206→#define FLASH_WRProt_Pages60to61       ((uint32_t)0x40000000) /*!< STM32 High-density, XL-density and Connectivity line devices:
207→                                                                   Write protection of page 60 to 61 */
208→#define FLASH_WRProt_Pages62to127      ((uint32_t)0x80000000) /*!< STM32 Connectivity line devices: Write protection of page 62 to 127 */
209→#define FLASH_WRProt_Pages62to255      ((uint32_t)0x80000000) /*!< STM32 Medium-density devices: Write protection of page 62 to 255 */
210→#define FLASH_WRProt_Pages62to511      ((uint32_t)0x80000000) /*!< STM32 XL-density devices: Write protection of page 62 to 511 */
211→
212→#define FLASH_WRProt_AllPages          ((uint32_t)0xFFFFFFFF) /*!< Write protection of all Pages */
213→
214→#define IS_FLASH_WRPROT_PAGE(PAGE) (((PAGE) != 0x00000000))
215→
216→#define IS_FLASH_ADDRESS(ADDRESS) (((ADDRESS) >= 0x08000000) && ((ADDRESS) < 0x080FFFFF))
217→
218→#define IS_OB_DATA_ADDRESS(ADDRESS) (((ADDRESS) == 0x1FFFF804) || ((ADDRESS) == 0x1FFFF806))
219→
220→/**
221→  * @}
222→  */
223→
224→/** @defgroup Option_Bytes_IWatchdog 
225→  * @{
226→  */
227→
228→#define OB_IWDG_SW                     ((uint16_t)0x0001)  /*!< Software IWDG selected */
229→#define OB_IWDG_HW                     ((uint16_t)0x0000)  /*!< Hardware IWDG selected */
230→#define IS_OB_IWDG_SOURCE(SOURCE) (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))
231→
232→/**
233→  * @}
234→  */
235→
236→/** @defgroup Option_Bytes_nRST_STOP 
237→  * @{
238→  */
239→
240→#define OB_STOP_NoRST                  ((uint16_t)0x0002) /*!< No reset generated when entering in STOP */
241→#define OB_STOP_RST                    ((uint16_t)0x0000) /*!< Reset generated when entering in STOP */
242→#define IS_OB_STOP_SOURCE(SOURCE) (((SOURCE) == OB_STOP_NoRST) || ((SOURCE) == OB_STOP_RST))
243→
244→/**
245→  * @}
246→  */
247→
248→/** @defgroup Option_Bytes_nRST_STDBY 
249→  * @{
250→  */
251→
252→#define OB_STDBY_NoRST                 ((uint16_t)0x0004) /*!< No reset generated when entering in STANDBY */
253→#define OB_STDBY_RST                   ((uint16_t)0x0000) /*!< Reset generated when entering in STANDBY */
254→#define IS_OB_STDBY_SOURCE(SOURCE) (((SOURCE) == OB_STDBY_NoRST) || ((SOURCE) == OB_STDBY_RST))
255→
256→#ifdef STM32F10X_XL
257→/**
258→  * @}
259→  */
260→/** @defgroup FLASH_Boot
261→  * @{
262→  */
263→#define FLASH_BOOT_Bank1  ((uint16_t)0x0000) /*!< At startup, if boot pins are set in boot from user Flash position
264→                                                  and this parameter is selected the device will boot from Bank1(Default) */
265→#define FLASH_BOOT_Bank2  ((uint16_t)0x0001) /*!< At startup, if boot pins are set in boot from user Flash position
266→                                                  and this parameter is selected the device will boot from Bank 2 or Bank 1,
267→                                                  depending on the activation of the bank */
268→#define IS_FLASH_BOOT(BOOT) (((BOOT) == FLASH_BOOT_Bank1) || ((BOOT) == FLASH_BOOT_Bank2))
269→#endif
270→/**
271→  * @}
272→  */
273→/** @defgroup FLASH_Interrupts 
274→  * @{
275→  */
276→#ifdef STM32F10X_XL
277→#define FLASH_IT_BANK2_ERROR                 ((uint32_t)0x80000400)  /*!< FPEC BANK2 error interrupt source */
278→#define FLASH_IT_BANK2_EOP                   ((uint32_t)0x80001000)  /*!< End of FLASH BANK2 Operation Interrupt source */
279→
280→#define FLASH_IT_BANK1_ERROR                 FLASH_IT_ERROR          /*!< FPEC BANK1 error interrupt source */
281→#define FLASH_IT_BANK1_EOP                   FLASH_IT_EOP            /*!< End of FLASH BANK1 Operation Interrupt source */
282→
283→#define FLASH_IT_ERROR                 ((uint32_t)0x00000400)  /*!< FPEC BANK1 error interrupt source */
284→#define FLASH_IT_EOP                   ((uint32_t)0x00001000)  /*!< End of FLASH BANK1 Operation Interrupt source */
285→#define IS_FLASH_IT(IT) ((((IT) & (uint32_t)0x7FFFEBFF) == 0x00000000) && (((IT) != 0x00000000)))
286→#else
287→#define FLASH_IT_ERROR                 ((uint32_t)0x00000400)  /*!< FPEC error interrupt source */
288→#define FLASH_IT_EOP                   ((uint32_t)0x00001000)  /*!< End of FLASH Operation Interrupt source */
289→#define FLASH_IT_BANK1_ERROR           FLASH_IT_ERROR          /*!< FPEC BANK1 error interrupt source */
290→#define FLASH_IT_BANK1_EOP             FLASH_IT_EOP            /*!< End of FLASH BANK1 Operation Interrupt source */
291→
292→#define IS_FLASH_IT(IT) ((((IT) & (uint32_t)0xFFFFEBFF) == 0x00000000) && (((IT) != 0x00000000)))
293→#endif
294→
295→/**
296→  * @}
297→  */
298→
299→/** @defgroup FLASH_Flags 
300→  * @{
301→  */
302→#ifdef STM32F10X_XL
303→#define FLASH_FLAG_BANK2_BSY                 ((uint32_t)0x80000001)  /*!< FLASH BANK2 Busy flag */
304→#define FLASH_FLAG_BANK2_EOP                 ((uint32_t)0x80000020)  /*!< FLASH BANK2 End of Operation flag */
305→#define FLASH_FLAG_BANK2_PGERR               ((uint32_t)0x80000004)  /*!< FLASH BANK2 Program error flag */
306→#define FLASH_FLAG_BANK2_WRPRTERR            ((uint32_t)0x80000010)  /*!< FLASH BANK2 Write protected error flag */
307→
308→#define FLASH_FLAG_BANK1_BSY                 FLASH_FLAG_BSY       /*!< FLASH BANK1 Busy flag*/
309→#define FLASH_FLAG_BANK1_EOP                 FLASH_FLAG_EOP       /*!< FLASH BANK1 End of Operation flag */
310→#define FLASH_FLAG_BANK1_PGERR               FLASH_FLAG_PGERR     /*!< FLASH BANK1 Program error flag */
311→#define FLASH_FLAG_BANK1_WRPRTERR            FLASH_FLAG_WRPRTERR  /*!< FLASH BANK1 Write protected error flag */
312→
313→#define FLASH_FLAG_BSY                 ((uint32_t)0x00000001)  /*!< FLASH Busy flag */
314→#define FLASH_FLAG_EOP                 ((uint32_t)0x00000020)  /*!< FLASH End of Operation flag */
315→#define FLASH_FLAG_PGERR               ((uint32_t)0x00000004)  /*!< FLASH Program error flag */
316→#define FLASH_FLAG_WRPRTERR            ((uint32_t)0x00000010)  /*!< FLASH Write protected error flag */
317→#define FLASH_FLAG_OPTERR              ((uint32_t)0x00000001)  /*!< FLASH Option Byte error flag */
318→ 
319→#define IS_FLASH_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0x7FFFFFCA) == 0x00000000) && ((FLAG) != 0x00000000))
320→#define IS_FLASH_GET_FLAG(FLAG)  (((FLAG) == FLASH_FLAG_BSY) || ((FLAG) == FLASH_FLAG_EOP) || \
321→                                  ((FLAG) == FLASH_FLAG_PGERR) || ((FLAG) == FLASH_FLAG_WRPRTERR) || \
322→                                  ((FLAG) == FLASH_FLAG_OPTERR)|| \
323→                                  ((FLAG) == FLASH_FLAG_BANK1_BSY) || ((FLAG) == FLASH_FLAG_BANK1_EOP) || \
324→                                  ((FLAG) == FLASH_FLAG_BANK1_PGERR) || ((FLAG) == FLASH_FLAG_BANK1_WRPRTERR) || \
325→                                  ((FLAG) == FLASH_FLAG_BANK2_BSY) || ((FLAG) == FLASH_FLAG_BANK2_EOP) || \
326→                                  ((FLAG) == FLASH_FLAG_BANK2_PGERR) || ((FLAG) == FLASH_FLAG_BANK2_WRPRTERR))
327→#else
328→#define FLASH_FLAG_BSY                 ((uint32_t)0x00000001)  /*!< FLASH Busy flag */
329→#define FLASH_FLAG_EOP                 ((uint32_t)0x00000020)  /*!< FLASH End of Operation flag */
330→#define FLASH_FLAG_PGERR               ((uint32_t)0x00000004)  /*!< FLASH Program error flag */
331→#define FLASH_FLAG_WRPRTERR            ((uint32_t)0x00000010)  /*!< FLASH Write protected error flag */
332→#define FLASH_FLAG_OPTERR              ((uint32_t)0x00000001)  /*!< FLASH Option Byte error flag */
333→
334→#define FLASH_FLAG_BANK1_BSY                 FLASH_FLAG_BSY       /*!< FLASH BANK1 Busy flag*/
335→#define FLASH_FLAG_BANK1_EOP                 FLASH_FLAG_EOP       /*!< FLASH BANK1 End of Operation flag */
336→#define FLASH_FLAG_BANK1_PGERR               FLASH_FLAG_PGERR     /*!< FLASH BANK1 Program error flag */
337→#define FLASH_FLAG_BANK1_WRPRTERR            FLASH_FLAG_WRPRTERR  /*!< FLASH BANK1 Write protected error flag */
338→ 
339→#define IS_FLASH_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFFCA) == 0x00000000) && ((FLAG) != 0x00000000))
340→#define IS_FLASH_GET_FLAG(FLAG)  (((FLAG) == FLASH_FLAG_BSY) || ((FLAG) == FLASH_FLAG_EOP) || \
341→                                  ((FLAG) == FLASH_FLAG_PGERR) || ((FLAG) == FLASH_FLAG_WRPRTERR) || \
342→								  ((FLAG) == FLASH_FLAG_BANK1_BSY) || ((FLAG) == FLASH_FLAG_BANK1_EOP) || \
343→                                  ((FLAG) == FLASH_FLAG_BANK1_PGERR) || ((FLAG) == FLASH_FLAG_BANK1_WRPRTERR) || \
344→                                  ((FLAG) == FLASH_FLAG_OPTERR))
345→#endif
346→
347→/**
348→  * @}
349→  */
350→
351→/**
352→  * @}
353→  */
354→
355→/** @defgroup FLASH_Exported_Macros
356→  * @{
357→  */
358→
359→/**
360→  * @}
361→  */
362→
363→/** @defgroup FLASH_Exported_Functions
364→  * @{
365→  */
366→
367→/*------------ Functions used for all STM32F10x devices -----*/
368→void FLASH_SetLatency(uint32_t FLASH_Latency);
369→void FLASH_HalfCycleAccessCmd(uint32_t FLASH_HalfCycleAccess);
370→void FLASH_PrefetchBufferCmd(uint32_t FLASH_PrefetchBuffer);
371→void FLASH_Unlock(void);
372→void FLASH_Lock(void);
373→FLASH_Status FLASH_ErasePage(uint32_t Page_Address);
374→FLASH_Status FLASH_EraseAllPages(void);
375→FLASH_Status FLASH_EraseOptionBytes(void);
376→FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
377→FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data);
378→FLASH_Status FLASH_ProgramOptionByteData(uint32_t Address, uint8_t Data);
379→FLASH_Status FLASH_EnableWriteProtection(uint32_t FLASH_Pages);
380→FLASH_Status FLASH_ReadOutProtection(FunctionalState NewState);
381→FLASH_Status FLASH_UserOptionByteConfig(uint16_t OB_IWDG, uint16_t OB_STOP, uint16_t OB_STDBY);
382→uint32_t FLASH_GetUserOptionByte(void);
383→uint32_t FLASH_GetWriteProtectionOptionByte(void);
384→FlagStatus FLASH_GetReadOutProtectionStatus(void);
385→FlagStatus FLASH_GetPrefetchBufferStatus(void);
386→void FLASH_ITConfig(uint32_t FLASH_IT, FunctionalState NewState);
387→FlagStatus FLASH_GetFlagStatus(uint32_t FLASH_FLAG);
388→void FLASH_ClearFlag(uint32_t FLASH_FLAG);
389→FLASH_Status FLASH_GetStatus(void);
390→FLASH_Status FLASH_WaitForLastOperation(uint32_t Timeout);
391→
392→/*------------ New function used for all STM32F10x devices -----*/
393→void FLASH_UnlockBank1(void);
394→void FLASH_LockBank1(void);
395→FLASH_Status FLASH_EraseAllBank1Pages(void);
396→FLASH_Status FLASH_GetBank1Status(void);
397→FLASH_Status FLASH_WaitForLastBank1Operation(uint32_t Timeout);
398→
399→#ifdef STM32F10X_XL
400→/*---- New Functions used only with STM32F10x_XL density devices -----*/
401→void FLASH_UnlockBank2(void);
402→void FLASH_LockBank2(void);
403→FLASH_Status FLASH_EraseAllBank2Pages(void);
404→FLASH_Status FLASH_GetBank2Status(void);
405→FLASH_Status FLASH_WaitForLastBank2Operation(uint32_t Timeout);
406→FLASH_Status FLASH_BootConfig(uint16_t FLASH_BOOT);
407→#endif
408→
409→#ifdef __cplusplus
410→}
411→#endif
412→
413→#endif /* __STM32F10x_FLASH_H */
414→/**
415→  * @}
416→  */
417→
418→/**
419→  * @}
420→  */
421→
422→/**
423→  * @}
424→  */
425→
426→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/