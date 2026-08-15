File content truncated due to size limit (50KB). First 50KB included below:

  1→/**************************************************************************//**
  2→ * @file     core_cm3.h
  3→ * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Header File
  4→ * @version  V1.30
  5→ * @date     30. October 2009
  6→ *
  7→ * @note
  8→ * Copyright (C) 2009 ARM Limited. All rights reserved.
  9→ *
 10→ * @par
 11→ * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 12→ * processor based microcontrollers.  This file can be freely distributed 
 13→ * within development tools that are supporting such ARM based processors. 
 14→ *
 15→ * @par
 16→ * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 17→ * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 18→ * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 19→ * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 20→ * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 21→ *
 22→ ******************************************************************************/
 23→
 24→#ifndef __CM3_CORE_H__
 25→#define __CM3_CORE_H__
 26→
 27→/** @addtogroup CMSIS_CM3_core_LintCinfiguration CMSIS CM3 Core Lint Configuration
 28→ *
 29→ * List of Lint messages which will be suppressed and not shown:
 30→ *   - Error 10: \n
 31→ *     register uint32_t __regBasePri         __asm("basepri"); \n
 32→ *     Error 10: Expecting ';'
 33→ * .
 34→ *   - Error 530: \n
 35→ *     return(__regBasePri); \n
 36→ *     Warning 530: Symbol '__regBasePri' (line 264) not initialized
 37→ * . 
 38→ *   - Error 550: \n
 39→ *     __regBasePri = (basePri & 0x1ff); \n
 40→ *     Warning 550: Symbol '__regBasePri' (line 271) not accessed
 41→ * .
 42→ *   - Error 754: \n
 43→ *     uint32_t RESERVED0[24]; \n
 44→ *     Info 754: local structure member '<some, not used in the HAL>' (line 109, file ./cm3_core.h) not referenced
 45→ * .
 46→ *   - Error 750: \n
 47→ *     #define __CM3_CORE_H__ \n
 48→ *     Info 750: local macro '__CM3_CORE_H__' (line 43, file./cm3_core.h) not referenced
 49→ * .
 50→ *   - Error 528: \n
 51→ *     static __INLINE void NVIC_DisableIRQ(uint32_t IRQn) \n
 52→ *     Warning 528: Symbol 'NVIC_DisableIRQ(unsigned int)' (line 419, file ./cm3_core.h) not referenced
 53→ * .
 54→ *   - Error 751: \n
 55→ *     } InterruptType_Type; \n
 56→ *     Info 751: local typedef 'InterruptType_Type' (line 170, file ./cm3_core.h) not referenced
 57→ * .
 58→ * Note:  To re-enable a Message, insert a space before 'lint' *
 59→ *
 60→ */
 61→
 62→/*lint -save */
 63→/*lint -e10  */
 64→/*lint -e530 */
 65→/*lint -e550 */
 66→/*lint -e754 */
 67→/*lint -e750 */
 68→/*lint -e528 */
 69→/*lint -e751 */
 70→
 71→
 72→/** @addtogroup CMSIS_CM3_core_definitions CM3 Core Definitions
 73→  This file defines all structures and symbols for CMSIS core:
 74→    - CMSIS version number
 75→    - Cortex-M core registers and bitfields
 76→    - Cortex-M core peripheral base address
 77→  @{
 78→ */
 79→
 80→#ifdef __cplusplus
 81→ extern "C" {
 82→#endif 
 83→
 84→#define __CM3_CMSIS_VERSION_MAIN  (0x01)                                                       /*!< [31:16] CMSIS HAL main version */
 85→#define __CM3_CMSIS_VERSION_SUB   (0x30)                                                       /*!< [15:0]  CMSIS HAL sub version  */
 86→#define __CM3_CMSIS_VERSION       ((__CM3_CMSIS_VERSION_MAIN << 16) | __CM3_CMSIS_VERSION_SUB) /*!< CMSIS HAL version number       */
 87→
 88→#define __CORTEX_M                (0x03)                                                       /*!< Cortex core                    */
 89→
 90→#include <stdint.h>                           /* Include standard types */
 91→
 92→#if defined (__ICCARM__)
 93→  #include <intrinsics.h>                     /* IAR Intrinsics   */
 94→#endif
 95→
 96→
 97→#ifndef __NVIC_PRIO_BITS
 98→  #define __NVIC_PRIO_BITS    4               /*!< standard definition for NVIC Priority Bits */
 99→#endif
100→
101→
102→
103→
104→/**
105→ * IO definitions
106→ *
107→ * define access restrictions to peripheral registers
108→ */
109→
110→#ifdef __cplusplus
111→  #define     __I     volatile                /*!< defines 'read only' permissions      */
112→#else
113→  #define     __I     volatile const          /*!< defines 'read only' permissions      */
114→#endif
115→#define     __O     volatile                  /*!< defines 'write only' permissions     */
116→#define     __IO    volatile                  /*!< defines 'read / write' permissions   */
117→
118→
119→
120→/*******************************************************************************
121→ *                 Register Abstraction
122→ ******************************************************************************/
123→/** @addtogroup CMSIS_CM3_core_register CMSIS CM3 Core Register
124→ @{
125→*/
126→
127→
128→/** @addtogroup CMSIS_CM3_NVIC CMSIS CM3 NVIC
129→  memory mapped structure for Nested Vectored Interrupt Controller (NVIC)
130→  @{
131→ */
132→typedef struct
133→{
134→  __IO uint32_t ISER[8];                      /*!< Offset: 0x000  Interrupt Set Enable Register           */
135→       uint32_t RESERVED0[24];                                   
136→  __IO uint32_t ICER[8];                      /*!< Offset: 0x080  Interrupt Clear Enable Register         */
137→       uint32_t RSERVED1[24];                                    
138→  __IO uint32_t ISPR[8];                      /*!< Offset: 0x100  Interrupt Set Pending Register          */
139→       uint32_t RESERVED2[24];                                   
140→  __IO uint32_t ICPR[8];                      /*!< Offset: 0x180  Interrupt Clear Pending Register        */
141→       uint32_t RESERVED3[24];                                   
142→  __IO uint32_t IABR[8];                      /*!< Offset: 0x200  Interrupt Active bit Register           */
143→       uint32_t RESERVED4[56];                                   
144→  __IO uint8_t  IP[240];                      /*!< Offset: 0x300  Interrupt Priority Register (8Bit wide) */
145→       uint32_t RESERVED5[644];                                  
146→  __O  uint32_t STIR;                         /*!< Offset: 0xE00  Software Trigger Interrupt Register     */
147→}  NVIC_Type;                                               
148→/*@}*/ /* end of group CMSIS_CM3_NVIC */
149→
150→
151→/** @addtogroup CMSIS_CM3_SCB CMSIS CM3 SCB
152→  memory mapped structure for System Control Block (SCB)
153→  @{
154→ */
155→typedef struct
156→{
157→  __I  uint32_t CPUID;                        /*!< Offset: 0x00  CPU ID Base Register                                  */
158→  __IO uint32_t ICSR;                         /*!< Offset: 0x04  Interrupt Control State Register                      */
159→  __IO uint32_t VTOR;                         /*!< Offset: 0x08  Vector Table Offset Register                          */
160→  __IO uint32_t AIRCR;                        /*!< Offset: 0x0C  Application Interrupt / Reset Control Register        */
161→  __IO uint32_t SCR;                          /*!< Offset: 0x10  System Control Register                               */
162→  __IO uint32_t CCR;                          /*!< Offset: 0x14  Configuration Control Register                        */
163→  __IO uint8_t  SHP[12];                      /*!< Offset: 0x18  System Handlers Priority Registers (4-7, 8-11, 12-15) */
164→  __IO uint32_t SHCSR;                        /*!< Offset: 0x24  System Handler Control and State Register             */
165→  __IO uint32_t CFSR;                         /*!< Offset: 0x28  Configurable Fault Status Register                    */
166→  __IO uint32_t HFSR;                         /*!< Offset: 0x2C  Hard Fault Status Register                            */
167→  __IO uint32_t DFSR;                         /*!< Offset: 0x30  Debug Fault Status Register                           */
168→  __IO uint32_t MMFAR;                        /*!< Offset: 0x34  Mem Manage Address Register                           */
169→  __IO uint32_t BFAR;                         /*!< Offset: 0x38  Bus Fault Address Register                            */
170→  __IO uint32_t AFSR;                         /*!< Offset: 0x3C  Auxiliary Fault Status Register                       */
171→  __I  uint32_t PFR[2];                       /*!< Offset: 0x40  Processor Feature Register                            */
172→  __I  uint32_t DFR;                          /*!< Offset: 0x48  Debug Feature Register                                */
173→  __I  uint32_t ADR;                          /*!< Offset: 0x4C  Auxiliary Feature Register                            */
174→  __I  uint32_t MMFR[4];                      /*!< Offset: 0x50  Memory Model Feature Register                         */
175→  __I  uint32_t ISAR[5];                      /*!< Offset: 0x60  ISA Feature Register                                  */
176→} SCB_Type;                                                
177→
178→/* SCB CPUID Register Definitions */
179→#define SCB_CPUID_IMPLEMENTER_Pos          24                                             /*!< SCB CPUID: IMPLEMENTER Position */
180→#define SCB_CPUID_IMPLEMENTER_Msk          (0xFFul << SCB_CPUID_IMPLEMENTER_Pos)          /*!< SCB CPUID: IMPLEMENTER Mask */
181→
182→#define SCB_CPUID_VARIANT_Pos              20                                             /*!< SCB CPUID: VARIANT Position */
183→#define SCB_CPUID_VARIANT_Msk              (0xFul << SCB_CPUID_VARIANT_Pos)               /*!< SCB CPUID: VARIANT Mask */
184→
185→#define SCB_CPUID_PARTNO_Pos                4                                             /*!< SCB CPUID: PARTNO Position */
186→#define SCB_CPUID_PARTNO_Msk               (0xFFFul << SCB_CPUID_PARTNO_Pos)              /*!< SCB CPUID: PARTNO Mask */
187→
188→#define SCB_CPUID_REVISION_Pos              0                                             /*!< SCB CPUID: REVISION Position */
189→#define SCB_CPUID_REVISION_Msk             (0xFul << SCB_CPUID_REVISION_Pos)              /*!< SCB CPUID: REVISION Mask */
190→
191→/* SCB Interrupt Control State Register Definitions */
192→#define SCB_ICSR_NMIPENDSET_Pos            31                                             /*!< SCB ICSR: NMIPENDSET Position */
193→#define SCB_ICSR_NMIPENDSET_Msk            (1ul << SCB_ICSR_NMIPENDSET_Pos)               /*!< SCB ICSR: NMIPENDSET Mask */
194→
195→#define SCB_ICSR_PENDSVSET_Pos             28                                             /*!< SCB ICSR: PENDSVSET Position */
196→#define SCB_ICSR_PENDSVSET_Msk             (1ul << SCB_ICSR_PENDSVSET_Pos)                /*!< SCB ICSR: PENDSVSET Mask */
197→
198→#define SCB_ICSR_PENDSVCLR_Pos             27                                             /*!< SCB ICSR: PENDSVCLR Position */
199→#define SCB_ICSR_PENDSVCLR_Msk             (1ul << SCB_ICSR_PENDSVCLR_Pos)                /*!< SCB ICSR: PENDSVCLR Mask */
200→
201→#define SCB_ICSR_PENDSTSET_Pos             26                                             /*!< SCB ICSR: PENDSTSET Position */
202→#define SCB_ICSR_PENDSTSET_Msk             (1ul << SCB_ICSR_PENDSTSET_Pos)                /*!< SCB ICSR: PENDSTSET Mask */
203→
204→#define SCB_ICSR_PENDSTCLR_Pos             25                                             /*!< SCB ICSR: PENDSTCLR Position */
205→#define SCB_ICSR_PENDSTCLR_Msk             (1ul << SCB_ICSR_PENDSTCLR_Pos)                /*!< SCB ICSR: PENDSTCLR Mask */
206→
207→#define SCB_ICSR_ISRPREEMPT_Pos            23                                             /*!< SCB ICSR: ISRPREEMPT Position */
208→#define SCB_ICSR_ISRPREEMPT_Msk            (1ul << SCB_ICSR_ISRPREEMPT_Pos)               /*!< SCB ICSR: ISRPREEMPT Mask */
209→
210→#define SCB_ICSR_ISRPENDING_Pos            22                                             /*!< SCB ICSR: ISRPENDING Position */
211→#define SCB_ICSR_ISRPENDING_Msk            (1ul << SCB_ICSR_ISRPENDING_Pos)               /*!< SCB ICSR: ISRPENDING Mask */
212→
213→#define SCB_ICSR_VECTPENDING_Pos           12                                             /*!< SCB ICSR: VECTPENDING Position */
214→#define SCB_ICSR_VECTPENDING_Msk           (0x1FFul << SCB_ICSR_VECTPENDING_Pos)          /*!< SCB ICSR: VECTPENDING Mask */
215→
216→#define SCB_ICSR_RETTOBASE_Pos             11                                             /*!< SCB ICSR: RETTOBASE Position */
217→#define SCB_ICSR_RETTOBASE_Msk             (1ul << SCB_ICSR_RETTOBASE_Pos)                /*!< SCB ICSR: RETTOBASE Mask */
218→
219→#define SCB_ICSR_VECTACTIVE_Pos             0                                             /*!< SCB ICSR: VECTACTIVE Position */
220→#define SCB_ICSR_VECTACTIVE_Msk            (0x1FFul << SCB_ICSR_VECTACTIVE_Pos)           /*!< SCB ICSR: VECTACTIVE Mask */
221→
222→/* SCB Interrupt Control State Register Definitions */
223→#define SCB_VTOR_TBLBASE_Pos               29                                             /*!< SCB VTOR: TBLBASE Position */
224→#define SCB_VTOR_TBLBASE_Msk               (0x1FFul << SCB_VTOR_TBLBASE_Pos)              /*!< SCB VTOR: TBLBASE Mask */
225→
226→#define SCB_VTOR_TBLOFF_Pos                 7                                             /*!< SCB VTOR: TBLOFF Position */
227→#define SCB_VTOR_TBLOFF_Msk                (0x3FFFFFul << SCB_VTOR_TBLOFF_Pos)            /*!< SCB VTOR: TBLOFF Mask */
228→
229→/* SCB Application Interrupt and Reset Control Register Definitions */
230→#define SCB_AIRCR_VECTKEY_Pos              16                                             /*!< SCB AIRCR: VECTKEY Position */
231→#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFul << SCB_AIRCR_VECTKEY_Pos)            /*!< SCB AIRCR: VECTKEY Mask */
232→
233→#define SCB_AIRCR_VECTKEYSTAT_Pos          16                                             /*!< SCB AIRCR: VECTKEYSTAT Position */
234→#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFul << SCB_AIRCR_VECTKEYSTAT_Pos)        /*!< SCB AIRCR: VECTKEYSTAT Mask */
235→
236→#define SCB_AIRCR_ENDIANESS_Pos            15                                             /*!< SCB AIRCR: ENDIANESS Position */
237→#define SCB_AIRCR_ENDIANESS_Msk            (1ul << SCB_AIRCR_ENDIANESS_Pos)               /*!< SCB AIRCR: ENDIANESS Mask */
238→
239→#define SCB_AIRCR_PRIGROUP_Pos              8                                             /*!< SCB AIRCR: PRIGROUP Position */
240→#define SCB_AIRCR_PRIGROUP_Msk             (7ul << SCB_AIRCR_PRIGROUP_Pos)                /*!< SCB AIRCR: PRIGROUP Mask */
241→
242→#define SCB_AIRCR_SYSRESETREQ_Pos           2                                             /*!< SCB AIRCR: SYSRESETREQ Position */
243→#define SCB_AIRCR_SYSRESETREQ_Msk          (1ul << SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ Mask */
244→
245→#define SCB_AIRCR_VECTCLRACTIVE_Pos         1                                             /*!< SCB AIRCR: VECTCLRACTIVE Position */
246→#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1ul << SCB_AIRCR_VECTCLRACTIVE_Pos)           /*!< SCB AIRCR: VECTCLRACTIVE Mask */
247→
248→#define SCB_AIRCR_VECTRESET_Pos             0                                             /*!< SCB AIRCR: VECTRESET Position */
249→#define SCB_AIRCR_VECTRESET_Msk            (1ul << SCB_AIRCR_VECTRESET_Pos)               /*!< SCB AIRCR: VECTRESET Mask */
250→
251→/* SCB System Control Register Definitions */
252→#define SCB_SCR_SEVONPEND_Pos               4                                             /*!< SCB SCR: SEVONPEND Position */
253→#define SCB_SCR_SEVONPEND_Msk              (1ul << SCB_SCR_SEVONPEND_Pos)                 /*!< SCB SCR: SEVONPEND Mask */
254→
255→#define SCB_SCR_SLEEPDEEP_Pos               2                                             /*!< SCB SCR: SLEEPDEEP Position */
256→#define SCB_SCR_SLEEPDEEP_Msk              (1ul << SCB_SCR_SLEEPDEEP_Pos)                 /*!< SCB SCR: SLEEPDEEP Mask */
257→
258→#define SCB_SCR_SLEEPONEXIT_Pos             1                                             /*!< SCB SCR: SLEEPONEXIT Position */
259→#define SCB_SCR_SLEEPONEXIT_Msk            (1ul << SCB_SCR_SLEEPONEXIT_Pos)               /*!< SCB SCR: SLEEPONEXIT Mask */
260→
261→/* SCB Configuration Control Register Definitions */
262→#define SCB_CCR_STKALIGN_Pos                9                                             /*!< SCB CCR: STKALIGN Position */
263→#define SCB_CCR_STKALIGN_Msk               (1ul << SCB_CCR_STKALIGN_Pos)                  /*!< SCB CCR: STKALIGN Mask */
264→
265→#define SCB_CCR_BFHFNMIGN_Pos               8                                             /*!< SCB CCR: BFHFNMIGN Position */
266→#define SCB_CCR_BFHFNMIGN_Msk              (1ul << SCB_CCR_BFHFNMIGN_Pos)                 /*!< SCB CCR: BFHFNMIGN Mask */
267→
268→#define SCB_CCR_DIV_0_TRP_Pos               4                                             /*!< SCB CCR: DIV_0_TRP Position */
269→#define SCB_CCR_DIV_0_TRP_Msk              (1ul << SCB_CCR_DIV_0_TRP_Pos)                 /*!< SCB CCR: DIV_0_TRP Mask */
270→
271→#define SCB_CCR_UNALIGN_TRP_Pos             3                                             /*!< SCB CCR: UNALIGN_TRP Position */
272→#define SCB_CCR_UNALIGN_TRP_Msk            (1ul << SCB_CCR_UNALIGN_TRP_Pos)               /*!< SCB CCR: UNALIGN_TRP Mask */
273→
274→#define SCB_CCR_USERSETMPEND_Pos            1                                             /*!< SCB CCR: USERSETMPEND Position */
275→#define SCB_CCR_USERSETMPEND_Msk           (1ul << SCB_CCR_USERSETMPEND_Pos)              /*!< SCB CCR: USERSETMPEND Mask */
276→
277→#define SCB_CCR_NONBASETHRDENA_Pos          0                                             /*!< SCB CCR: NONBASETHRDENA Position */
278→#define SCB_CCR_NONBASETHRDENA_Msk         (1ul << SCB_CCR_NONBASETHRDENA_Pos)            /*!< SCB CCR: NONBASETHRDENA Mask */
279→
280→/* SCB System Handler Control and State Register Definitions */
281→#define SCB_SHCSR_USGFAULTENA_Pos          18                                             /*!< SCB SHCSR: USGFAULTENA Position */
282→#define SCB_SHCSR_USGFAULTENA_Msk          (1ul << SCB_SHCSR_USGFAULTENA_Pos)             /*!< SCB SHCSR: USGFAULTENA Mask */
283→
284→#define SCB_SHCSR_BUSFAULTENA_Pos          17                                             /*!< SCB SHCSR: BUSFAULTENA Position */
285→#define SCB_SHCSR_BUSFAULTENA_Msk          (1ul << SCB_SHCSR_BUSFAULTENA_Pos)             /*!< SCB SHCSR: BUSFAULTENA Mask */
286→
287→#define SCB_SHCSR_MEMFAULTENA_Pos          16                                             /*!< SCB SHCSR: MEMFAULTENA Position */
288→#define SCB_SHCSR_MEMFAULTENA_Msk          (1ul << SCB_SHCSR_MEMFAULTENA_Pos)             /*!< SCB SHCSR: MEMFAULTENA Mask */
289→
290→#define SCB_SHCSR_SVCALLPENDED_Pos         15                                             /*!< SCB SHCSR: SVCALLPENDED Position */
291→#define SCB_SHCSR_SVCALLPENDED_Msk         (1ul << SCB_SHCSR_SVCALLPENDED_Pos)            /*!< SCB SHCSR: SVCALLPENDED Mask */
292→
293→#define SCB_SHCSR_BUSFAULTPENDED_Pos       14                                             /*!< SCB SHCSR: BUSFAULTPENDED Position */
294→#define SCB_SHCSR_BUSFAULTPENDED_Msk       (1ul << SCB_SHCSR_BUSFAULTPENDED_Pos)          /*!< SCB SHCSR: BUSFAULTPENDED Mask */
295→
296→#define SCB_SHCSR_MEMFAULTPENDED_Pos       13                                             /*!< SCB SHCSR: MEMFAULTPENDED Position */
297→#define SCB_SHCSR_MEMFAULTPENDED_Msk       (1ul << SCB_SHCSR_MEMFAULTPENDED_Pos)          /*!< SCB SHCSR: MEMFAULTPENDED Mask */
298→
299→#define SCB_SHCSR_USGFAULTPENDED_Pos       12                                             /*!< SCB SHCSR: USGFAULTPENDED Position */
300→#define SCB_SHCSR_USGFAULTPENDED_Msk       (1ul << SCB_SHCSR_USGFAULTPENDED_Pos)          /*!< SCB SHCSR: USGFAULTPENDED Mask */
301→
302→#define SCB_SHCSR_SYSTICKACT_Pos           11                                             /*!< SCB SHCSR: SYSTICKACT Position */
303→#define SCB_SHCSR_SYSTICKACT_Msk           (1ul << SCB_SHCSR_SYSTICKACT_Pos)              /*!< SCB SHCSR: SYSTICKACT Mask */
304→
305→#define SCB_SHCSR_PENDSVACT_Pos            10                                             /*!< SCB SHCSR: PENDSVACT Position */
306→#define SCB_SHCSR_PENDSVACT_Msk            (1ul << SCB_SHCSR_PENDSVACT_Pos)               /*!< SCB SHCSR: PENDSVACT Mask */
307→
308→#define SCB_SHCSR_MONITORACT_Pos            8                                             /*!< SCB SHCSR: MONITORACT Position */
309→#define SCB_SHCSR_MONITORACT_Msk           (1ul << SCB_SHCSR_MONITORACT_Pos)              /*!< SCB SHCSR: MONITORACT Mask */
310→
311→#define SCB_SHCSR_SVCALLACT_Pos             7                                             /*!< SCB SHCSR: SVCALLACT Position */
312→#define SCB_SHCSR_SVCALLACT_Msk            (1ul << SCB_SHCSR_SVCALLACT_Pos)               /*!< SCB SHCSR: SVCALLACT Mask */
313→                                     
314→#define SCB_SHCSR_USGFAULTACT_Pos           3                                             /*!< SCB SHCSR: USGFAULTACT Position */
315→#define SCB_SHCSR_USGFAULTACT_Msk          (1ul << SCB_SHCSR_USGFAULTACT_Pos)             /*!< SCB SHCSR: USGFAULTACT Mask */
316→
317→#define SCB_SHCSR_BUSFAULTACT_Pos           1                                             /*!< SCB SHCSR: BUSFAULTACT Position */
318→#define SCB_SHCSR_BUSFAULTACT_Msk          (1ul << SCB_SHCSR_BUSFAULTACT_Pos)             /*!< SCB SHCSR: BUSFAULTACT Mask */
319→
320→#define SCB_SHCSR_MEMFAULTACT_Pos           0                                             /*!< SCB SHCSR: MEMFAULTACT Position */
321→#define SCB_SHCSR_MEMFAULTACT_Msk          (1ul << SCB_SHCSR_MEMFAULTACT_Pos)             /*!< SCB SHCSR: MEMFAULTACT Mask */
322→
323→/* SCB Configurable Fault Status Registers Definitions */
324→#define SCB_CFSR_USGFAULTSR_Pos            16                                             /*!< SCB CFSR: Usage Fault Status Register Position */
325→#define SCB_CFSR_USGFAULTSR_Msk            (0xFFFFul << SCB_CFSR_USGFAULTSR_Pos)          /*!< SCB CFSR: Usage Fault Status Register Mask */
326→
327→#define SCB_CFSR_BUSFAULTSR_Pos             8                                             /*!< SCB CFSR: Bus Fault Status Register Position */
328→#define SCB_CFSR_BUSFAULTSR_Msk            (0xFFul << SCB_CFSR_BUSFAULTSR_Pos)            /*!< SCB CFSR: Bus Fault Status Register Mask */
329→
330→#define SCB_CFSR_MEMFAULTSR_Pos             0                                             /*!< SCB CFSR: Memory Manage Fault Status Register Position */
331→#define SCB_CFSR_MEMFAULTSR_Msk            (0xFFul << SCB_CFSR_MEMFAULTSR_Pos)            /*!< SCB CFSR: Memory Manage Fault Status Register Mask */
332→
333→/* SCB Hard Fault Status Registers Definitions */
334→#define SCB_HFSR_DEBUGEVT_Pos              31                                             /*!< SCB HFSR: DEBUGEVT Position */
335→#define SCB_HFSR_DEBUGEVT_Msk              (1ul << SCB_HFSR_DEBUGEVT_Pos)                 /*!< SCB HFSR: DEBUGEVT Mask */
336→
337→#define SCB_HFSR_FORCED_Pos                30                                             /*!< SCB HFSR: FORCED Position */
338→#define SCB_HFSR_FORCED_Msk                (1ul << SCB_HFSR_FORCED_Pos)                   /*!< SCB HFSR: FORCED Mask */
339→
340→#define SCB_HFSR_VECTTBL_Pos                1                                             /*!< SCB HFSR: VECTTBL Position */
341→#define SCB_HFSR_VECTTBL_Msk               (1ul << SCB_HFSR_VECTTBL_Pos)                  /*!< SCB HFSR: VECTTBL Mask */
342→
343→/* SCB Debug Fault Status Register Definitions */
344→#define SCB_DFSR_EXTERNAL_Pos               4                                             /*!< SCB DFSR: EXTERNAL Position */
345→#define SCB_DFSR_EXTERNAL_Msk              (1ul << SCB_DFSR_EXTERNAL_Pos)                 /*!< SCB DFSR: EXTERNAL Mask */
346→
347→#define SCB_DFSR_VCATCH_Pos                 3                                             /*!< SCB DFSR: VCATCH Position */
348→#define SCB_DFSR_VCATCH_Msk                (1ul << SCB_DFSR_VCATCH_Pos)                   /*!< SCB DFSR: VCATCH Mask */
349→
350→#define SCB_DFSR_DWTTRAP_Pos                2                                             /*!< SCB DFSR: DWTTRAP Position */
351→#define SCB_DFSR_DWTTRAP_Msk               (1ul << SCB_DFSR_DWTTRAP_Pos)                  /*!< SCB DFSR: DWTTRAP Mask */
352→
353→#define SCB_DFSR_BKPT_Pos                   1                                             /*!< SCB DFSR: BKPT Position */
354→#define SCB_DFSR_BKPT_Msk                  (1ul << SCB_DFSR_BKPT_Pos)                     /*!< SCB DFSR: BKPT Mask */
355→
356→#define SCB_DFSR_HALTED_Pos                 0                                             /*!< SCB DFSR: HALTED Position */
357→#define SCB_DFSR_HALTED_Msk                (1ul << SCB_DFSR_HALTED_Pos)                   /*!< SCB DFSR: HALTED Mask */
358→/*@}*/ /* end of group CMSIS_CM3_SCB */
359→
360→
361→/** @addtogroup CMSIS_CM3_SysTick CMSIS CM3 SysTick
362→  memory mapped structure for SysTick
363→  @{
364→ */
365→typedef struct
366→{
367→  __IO uint32_t CTRL;                         /*!< Offset: 0x00  SysTick Control and Status Register */
368→  __IO uint32_t LOAD;                         /*!< Offset: 0x04  SysTick Reload Value Register       */
369→  __IO uint32_t VAL;                          /*!< Offset: 0x08  SysTick Current Value Register      */
370→  __I  uint32_t CALIB;                        /*!< Offset: 0x0C  SysTick Calibration Register        */
371→} SysTick_Type;
372→
373→/* SysTick Control / Status Register Definitions */
374→#define SysTick_CTRL_COUNTFLAG_Pos         16                                             /*!< SysTick CTRL: COUNTFLAG Position */
375→#define SysTick_CTRL_COUNTFLAG_Msk         (1ul << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */
376→
377→#define SysTick_CTRL_CLKSOURCE_Pos          2                                             /*!< SysTick CTRL: CLKSOURCE Position */
378→#define SysTick_CTRL_CLKSOURCE_Msk         (1ul << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */
379→
380→#define SysTick_CTRL_TICKINT_Pos            1                                             /*!< SysTick CTRL: TICKINT Position */
381→#define SysTick_CTRL_TICKINT_Msk           (1ul << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */
382→
383→#define SysTick_CTRL_ENABLE_Pos             0                                             /*!< SysTick CTRL: ENABLE Position */
384→#define SysTick_CTRL_ENABLE_Msk            (1ul << SysTick_CTRL_ENABLE_Pos)               /*!< SysTick CTRL: ENABLE Mask */
385→
386→/* SysTick Reload Register Definitions */
387→#define SysTick_LOAD_RELOAD_Pos             0                                             /*!< SysTick LOAD: RELOAD Position */
388→#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFul << SysTick_LOAD_RELOAD_Pos)        /*!< SysTick LOAD: RELOAD Mask */
389→
390→/* SysTick Current Register Definitions */
391→#define SysTick_VAL_CURRENT_Pos             0                                             /*!< SysTick VAL: CURRENT Position */
392→#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFul << SysTick_VAL_CURRENT_Pos)        /*!< SysTick VAL: CURRENT Mask */
393→
394→/* SysTick Calibration Register Definitions */
395→#define SysTick_CALIB_NOREF_Pos            31                                             /*!< SysTick CALIB: NOREF Position */
396→#define SysTick_CALIB_NOREF_Msk            (1ul << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF Mask */
397→
398→#define SysTick_CALIB_SKEW_Pos             30                                             /*!< SysTick CALIB: SKEW Position */
399→#define SysTick_CALIB_SKEW_Msk             (1ul << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW Mask */
400→
401→#define SysTick_CALIB_TENMS_Pos             0                                             /*!< SysTick CALIB: TENMS Position */
402→#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFul << SysTick_VAL_CURRENT_Pos)        /*!< SysTick CALIB: TENMS Mask */
403→/*@}*/ /* end of group CMSIS_CM3_SysTick */
404→
405→
406→/** @addtogroup CMSIS_CM3_ITM CMSIS CM3 ITM
407→  memory mapped structure for Instrumentation Trace Macrocell (ITM)
408→  @{
409→ */
410→typedef struct
411→{
412→  __O  union  
413→  {
414→    __O  uint8_t    u8;                       /*!< Offset:       ITM Stimulus Port 8-bit                   */
415→    __O  uint16_t   u16;                      /*!< Offset:       ITM Stimulus Port 16-bit                  */
416→    __O  uint32_t   u32;                      /*!< Offset:       ITM Stimulus Port 32-bit                  */
417→  }  PORT [32];                               /*!< Offset: 0x00  ITM Stimulus Port Registers               */
418→       uint32_t RESERVED0[864];                                 
419→  __IO uint32_t TER;                          /*!< Offset:       ITM Trace Enable Register                 */
420→       uint32_t RESERVED1[15];                                  
421→  __IO uint32_t TPR;                          /*!< Offset:       ITM Trace Privilege Register              */
422→       uint32_t RESERVED2[15];                                  
423→  __IO uint32_t TCR;                          /*!< Offset:       ITM Trace Control Register                */
424→       uint32_t RESERVED3[29];                                  
425→  __IO uint32_t IWR;                          /*!< Offset:       ITM Integration Write Register            */
426→  __IO uint32_t IRR;                          /*!< Offset:       ITM Integration Read Register             */
427→  __IO uint32_t IMCR;                         /*!< Offset:       ITM Integration Mode Control Register     */
428→       uint32_t RESERVED4[43];                                  
429→  __IO uint32_t LAR;                          /*!< Offset:       ITM Lock Access Register                  */
430→  __IO uint32_t LSR;                          /*!< Offset:       ITM Lock Status Register                  */
431→       uint32_t RESERVED5[6];                                   
432→  __I  uint32_t PID4;                         /*!< Offset:       ITM Peripheral Identification Register #4 */
433→  __I  uint32_t PID5;                         /*!< Offset:       ITM Peripheral Identification Register #5 */
434→  __I  uint32_t PID6;                         /*!< Offset:       ITM Peripheral Identification Register #6 */
435→  __I  uint32_t PID7;                         /*!< Offset:       ITM Peripheral Identification Register #7 */
436→  __I  uint32_t PID0;                         /*!< Offset:       ITM Peripheral Identification Register #0 */
437→  __I  uint32_t PID1;                         /*!< Offset:       ITM Peripheral Identification Register #1 */
438→  __I  uint32_t PID2;                         /*!< Offset:       ITM Peripheral Identification Register #2 */
439→  __I  uint32_t PID3;                         /*!< Offset:       ITM Peripheral Identification Register #3 */
440→  __I  uint32_t CID0;                         /*!< Offset:       ITM Component  Identification Register #0 */
441→  __I  uint32_t CID1;                         /*!< Offset:       ITM Component  Identification Register #1 */
442→  __I  uint32_t CID2;                         /*!< Offset:       ITM Component  Identification Register #2 */
443→  __I  uint32_t CID3;                         /*!< Offset:       ITM Component  Identification Register #3 */
444→} ITM_Type;                                                
445→
446→/* ITM Trace Privilege Register Definitions */
447→#define ITM_TPR_PRIVMASK_Pos                0                                             /*!< ITM TPR: PRIVMASK Position */
448→#define ITM_TPR_PRIVMASK_Msk               (0xFul << ITM_TPR_PRIVMASK_Pos)                /*!< ITM TPR: PRIVMASK Mask */
449→
450→/* ITM Trace Control Register Definitions */
451→#define ITM_TCR_BUSY_Pos                   23                                             /*!< ITM TCR: BUSY Position */
452→#define ITM_TCR_BUSY_Msk                   (1ul << ITM_TCR_BUSY_Pos)                      /*!< ITM TCR: BUSY Mask */
453→
454→#define ITM_TCR_ATBID_Pos                  16                                             /*!< ITM TCR: ATBID Position */
455→#define ITM_TCR_ATBID_Msk                  (0x7Ful << ITM_TCR_ATBID_Pos)                  /*!< ITM TCR: ATBID Mask */
456→
457→#define ITM_TCR_TSPrescale_Pos              8                                             /*!< ITM TCR: TSPrescale Position */
458→#define ITM_TCR_TSPrescale_Msk             (3ul << ITM_TCR_TSPrescale_Pos)                /*!< ITM TCR: TSPrescale Mask */
459→
460→#define ITM_TCR_SWOENA_Pos                  4                                             /*!< ITM TCR: SWOENA Position */
461→#define ITM_TCR_SWOENA_Msk                 (1ul << ITM_TCR_SWOENA_Pos)                    /*!< ITM TCR: SWOENA Mask */
462→
463→#define ITM_TCR_DWTENA_Pos                  3                                             /*!< ITM TCR: DWTENA Position */
464→#define ITM_TCR_DWTENA_Msk                 (1ul << ITM_TCR_DWTENA_Pos)                    /*!< ITM TCR: DWTENA Mask */
465→
466→#define ITM_TCR_SYNCENA_Pos                 2                                             /*!< ITM TCR: SYNCENA Position */
467→#define ITM_TCR_SYNCENA_Msk                (1ul << ITM_TCR_SYNCENA_Pos)                   /*!< ITM TCR: SYNCENA Mask */
468→
469→#define ITM_TCR_TSENA_Pos                   1                                             /*!< ITM TCR: TSENA Position */
470→#define ITM_TCR_TSENA_Msk                  (1ul << ITM_TCR_TSENA_Pos)                     /*!< ITM TCR: TSENA Mask */
471→
472→#define ITM_TCR_ITMENA_Pos                  0                                             /*!< ITM TCR: ITM Enable bit Position */
473→#define ITM_TCR_ITMENA_Msk                 (1ul << ITM_TCR_ITMENA_Pos)                    /*!< ITM TCR: ITM Enable bit Mask */
474→
475→/* ITM Integration Write Register Definitions */
476→#define ITM_IWR_ATVALIDM_Pos                0                                             /*!< ITM IWR: ATVALIDM Position */
477→#define ITM_IWR_ATVALIDM_Msk               (1ul << ITM_IWR_ATVALIDM_Pos)                  /*!< ITM IWR: ATVALIDM Mask */
478→
479→/* ITM Integration Read Register Definitions */
480→#define ITM_IRR_ATREADYM_Pos                0                                             /*!< ITM IRR: ATREADYM Position */
481→#define ITM_IRR_ATREADYM_Msk               (1ul << ITM_IRR_ATREADYM_Pos)                  /*!< ITM IRR: ATREADYM Mask */
482→
483→/* ITM Integration Mode Control Register Definitions */
484→#define ITM_IMCR_INTEGRATION_Pos            0                                             /*!< ITM IMCR: INTEGRATION Position */
485→#define ITM_IMCR_INTEGRATION_Msk           (1ul << ITM_IMCR_INTEGRATION_Pos)              /*!< ITM IMCR: INTEGRATION Mask */
486→
487→/* ITM Lock Status Register Definitions */
488→#define ITM_LSR_ByteAcc_Pos                 2                                             /*!< ITM LSR: ByteAcc Position */
489→#define ITM_LSR_ByteAcc_Msk                (1ul << ITM_LSR_ByteAcc_Pos)                   /*!< ITM LSR: ByteAcc Mask */
490→
491→#define ITM_LSR_Access_Pos                  1                                             /*!< ITM LSR: Access Position */
492→#define ITM_LSR_Access_Msk                 (1ul << ITM_LSR_Access_Pos)                    /*!< ITM LSR: Access Mask */
493→
494→#define ITM_LSR_Present_Pos                 0                                             /*!< ITM LSR: Present Position */
495→#define ITM_LSR_Present_Msk                (1ul << ITM_LSR_Present_Pos)                   /*!< ITM LSR: Present Mask */
496→/*@}*/ /* end of group CMSIS_CM3_ITM */
497→
498→
499→/** @addtogroup CMSIS_CM3_InterruptType CMSIS CM3 Interrupt Type
500→  memory mapped structure for Interrupt Type
501→  @{
502→ */
503→typedef struct
504→{
505→       uint32_t RESERVED0;
506→  __I  uint32_t ICTR;                         /*!< Offset: 0x04  Interrupt Control Type Register */
507→#if ((defined __CM3_REV) && (__CM3_REV >= 0x200))
508→  __IO uint32_t ACTLR;                        /*!< Offset: 0x08  Auxiliary Control Register      */
509→#else
510→       uint32_t RESERVED1;
511→#endif
512→} InterruptType_Type;
513→
514→/* Interrupt Controller Type Register Definitions */
515→#define InterruptType_ICTR_INTLINESNUM_Pos  0                                             /*!< InterruptType ICTR: INTLINESNUM Position */
516→#define InterruptType_ICTR_INTLINESNUM_Msk (0x1Ful << InterruptType_ICTR_INTLINESNUM_Pos) /*!< InterruptType ICTR: INTLINESNUM Mask */
517→
518→/* Auxiliary Control Register Definitions */
519→#define InterruptType_ACTLR_DISFOLD_Pos     2                                             /*!< InterruptType ACTLR: DISFOLD Position */
520→#define InterruptType_ACTLR_DISFOLD_Msk    (1ul << InterruptType_ACTLR_DISFOLD_Pos)       /*!< InterruptType ACTLR: DISFOLD Mask */
521→
522→#define InterruptType_ACTLR_DISDEFWBUF_Pos  1                                             /*!< InterruptType ACTLR: DISDEFWBUF Position */
523→#define InterruptType_ACTLR_DISDEFWBUF_Msk (1ul << InterruptType_ACTLR_DISDEFWBUF_Pos)    /*!< InterruptType ACTLR: DISDEFWBUF Mask */
524→
525→#define InterruptType_ACTLR_DISMCYCINT_Pos  0                                             /*!< InterruptType ACTLR: DISMCYCINT Position */
526→#define InterruptType_ACTLR_DISMCYCINT_Msk (1ul << InterruptType_ACTLR_DISMCYCINT_Pos)    /*!< InterruptType ACTLR: DISMCYCINT Mask */
527→/*@}*/ /* end of group CMSIS_CM3_InterruptType */
528→
529→
530→#if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1)
531→/** @addtogroup CMSIS_CM3_MPU CMSIS CM3 MPU
532→  memory mapped structure for Memory Protection Unit (MPU)
533→  @{
534→ */
535→typedef struct
536→{
537→  __I  uint32_t TYPE;                         /*!< Offset: 0x00  MPU Type Register                              */
538→  __IO uint32_t CTRL;                         /*!< Offset: 0x04  MPU Control Register                           */
539→  __IO uint32_t RNR;                          /*!< Offset: 0x08  MPU Region RNRber Register                     */
540→  __IO uint32_t RBAR;                         /*!< Offset: 0x0C  MPU Region Base Address Register               */
541→  __IO uint32_t RASR;                         /*!< Offset: 0x10  MPU Region Attribute and Size Register         */
542→  __IO uint32_t RBAR_A1;                      /*!< Offset: 0x14  MPU Alias 1 Region Base Address Register       */
543→  __IO uint32_t RASR_A1;                      /*!< Offset: 0x18  MPU Alias 1 Region Attribute and Size Register */
544→  __IO uint32_t RBAR_A2;                      /*!< Offset: 0x1C  MPU Alias 2 Region Base Address Register       */
545→  __IO uint32_t RASR_A2;                      /*!< Offset: 0x20  MPU Alias 2 Region Attribute and Size Register */
546→  __IO uint32_t RBAR_A3;                      /*!< Offset: 0x24  MPU Alias 3 Region Base Address Register       */
547→  __IO uint32_t RASR_A3;                      /*!< Offset: 0x28  MPU Alias 3 Region Attribute and Size Register */
548→} MPU_Type;                                                
549→
550→/* MPU Type Register */
551→#define MPU_TYPE_IREGION_Pos               16                                             /*!< MPU TYPE: IREGION Position */
552→#define MPU_TYPE_IREGION_Msk               (0xFFul << MPU_TYPE_IREGION_Pos)               /*!< MPU TYPE: IREGION Mask */
553→
554→#define MPU_TYPE_DREGION_Pos                8                                             /*!< MPU TYPE: DREGION Position */
555→#define MPU_TYPE_DREGION_Msk               (0xFFul << MPU_TYPE_DREGION_Pos)               /*!< MPU TYPE: DREGION Mask */
556→
557→#define MPU_TYPE_SEPARATE_Pos               0                                             /*!< MPU TYPE: SEPARATE Position */
558→#define MPU_TYPE_SEPARATE_Msk              (1ul << MPU_TYPE_SEPARATE_Pos)                 /*!< MPU TYPE: SEPARATE Mask */
559→
560→/* MPU Control Register */
561→#define MPU_CTRL_PRIVDEFENA_Pos             2                                             /*!< MPU CTRL: PRIVDEFENA Position */
562→#define MPU_CTRL_PRIVDEFENA_Msk            (1ul << MPU_CTRL_PRIVDEFENA_Pos)               /*!< MPU CTRL: PRIVDEFENA Mask */
563→
564→#define MPU_CTRL_HFNMIENA_Pos               1                                             /*!< MPU CTRL: HFNMIENA Position */
565→#define MPU_CTRL_HFNMIENA_Msk              (1ul << MPU_CTRL_HFNMIENA_Pos)                 /*!< MPU CTRL: HFNMIENA Mask */
566→
567→#define MPU_CTRL_ENABLE_Pos                 0                                             /*!< MPU CTRL: ENABLE Position */
568→#define MPU_CTRL_ENABLE_Msk                (1ul << MPU_CTRL_ENABLE_Pos)                   /*!< MPU CTRL: ENABLE Mask */
569→
570→/* MPU Region Number Register */
571→#define MPU_RNR_REGION_Pos                  0                                             /*!< MPU RNR: REGION Position */
572→#define MPU_RNR_REGION_Msk                 (0xFFul << MPU_RNR_REGION_Pos)                 /*!< MPU RNR: REGION Mask */
573→
574→/* MPU Region Base Address Register */
575→#define MPU_RBAR_ADDR_Pos                   5                                             /*!< MPU RBAR: ADDR Position */
576→#define MPU_RBAR_ADDR_Msk                  (0x7FFFFFFul << MPU_RBAR_ADDR_Pos)             /*!< MPU RBAR: ADDR Mask */
577→
578→#define MPU_RBAR_VALID_Pos                  4                                             /*!< MPU RBAR: VALID Position */
579→#define MPU_RBAR_VALID_Msk                 (1ul << MPU_RBAR_VALID_Pos)                    /*!< MPU RBAR: VALID Mask */
580→
581→#define MPU_RBAR_REGION_Pos                 0                                             /*!< MPU RBAR: REGION Position */
582→#define MPU_RBAR_REGION_Msk                (0xFul << MPU_RBAR_REGION_Pos)                 /*!< MPU RBAR: REGION Mask */
583→
584→/* MPU Region Attribute and Size Register */
585→#define MPU_RASR_XN_Pos                    28                                             /*!< MPU RASR: XN Position */
586→#define MPU_RASR_XN_Msk                    (1ul << MPU_RASR_XN_Pos)                       /*!< MPU RASR: XN Mask */
587→
588→#define MPU_RASR_AP_Pos                    24                                             /*!< MPU RASR: AP Position */
589→#define MPU_RASR_AP_Msk                    (7ul << MPU_RASR_AP_Pos)                       /*!< MPU RASR: AP Mask */
590→
591→#define MPU_RASR_TEX_Pos                   19                                             /*!< MPU RASR: TEX Position */
592→#define MPU_RASR_TEX_Msk                   (7ul << MPU_RASR_TEX_Pos)                      /*!< MPU RASR: TEX Mask */
593→
594→#define MPU_RASR_S_Pos                     18                                             /*!< MPU RASR: Shareable bit Position */
595→#define MPU_RASR_S_Msk                     (1ul << MPU_RASR_S_Pos)                        /*!< MPU RASR: Shareable bit Mask */
596→
597→#define MPU_RASR_C_Pos                     17                                             /*!< MPU RASR: Cacheable bit Position */
598→#define MPU_RASR_C_Msk                     (1ul << MPU_RASR_C_Pos)                        /*!< MPU RASR: Cacheable bit Mask */
599→
600→#define MPU_RASR_B_Pos                     16                                             /*!< MPU RASR: Bufferable bit Position */
601→#define MPU_RASR_B_Msk                     (1ul << MPU_RASR_B_Pos)                        /*!< MPU RASR: Bufferable bit Mask */
602→
603→#define MPU_RASR_SRD_Pos                    8                                             /*!< MPU RASR: Sub-Region Disable Position */
604→#define MPU_RASR_SRD_Msk                   (0xFFul << MPU_RASR_SRD_Pos)                   /*!< MPU RASR: Sub-Region Disable Mask */
605→
606→#define MPU_RASR_SIZE_Pos                   1                                             /*!< MPU RASR: Region Size Field Position */
607→#define MPU_RASR_SIZE_Msk                  (0x1Ful << MPU_RASR_SIZE_Pos)                  /*!< MPU RASR: Region Size Field Mask */
608→
609→#define MPU_RASR_ENA_Pos                     0                                            /*!< MPU RASR: Region enable bit Position */
610→#define MPU_RASR_ENA_Msk                    (0x1Ful << MPU_RASR_ENA_Pos)                  /*!< MPU RASR: Region enable bit Disable Mask */
611→
612→/*@}*/ /* end of group CMSIS_CM3_MPU */
613→#endif
614→
615→
616→/** @addtogroup CMSIS_CM3_CoreDebug CMSIS CM3 Core Debug
617→  memory mapped structure for Core Debug Register
618→  @{
619→ */
620→typedef struct
621→{
622→  __IO uint32_t DHCSR;                        /*!< Offset: 0x00  Debug Halting Control and Status Register    */
623→  __O  uint32_t DCRSR;                        /*!< Offset: 0x04  Debug Core Register Selector Register        */
624→  __IO uint32_t DCRDR;                        /*!< Offset: 0x08  Debug Core Register Data Register            */
625→  __IO uint32_t DEMCR;                        /*!< Offset: 0x0C  Debug Exception and Monitor Control Register */
626→} CoreDebug_Type;
627→
628→/* Debug Halting Control and Status Register */
629→#define CoreDebug_DHCSR_DBGKEY_Pos         16                                             /*!< CoreDebug DHCSR: DBGKEY Position */
630→#define CoreDebug_DHCSR_DBGKEY_Msk         (0xFFFFul << CoreDebug_DHCSR_DBGKEY_Pos)       /*!< CoreDebug DHCSR: DBGKEY Mask */
631→
632→#define CoreDebug_DHCSR_S_RESET_ST_Pos     25                                             /*!< CoreDebug DHCSR: S_RESET_ST Position */
633→#define CoreDebug_DHCSR_S_RESET_ST_Msk     (1ul << CoreDebug_DHCSR_S_RESET_ST_Pos)        /*!< CoreDebug DHCSR: S_RESET_ST Mask */
634→
635→#define CoreDebug_DHCSR_S_RETIRE_ST_Pos    24                                             /*!< CoreDebug DHCSR: S_RETIRE_ST Position */
636→#define CoreDebug_DHCSR_S_RETIRE_ST_Msk    (1ul << CoreDebug_DHCSR_S_RETIRE_ST_Pos)       /*!< CoreDebug DHCSR: S_RETIRE_ST Mask */
637→
638→#define CoreDebug_DHCSR_S_LOCKUP_Pos       19                                             /*!< CoreDebug DHCSR: S_LOCKUP Position */
639→#define CoreDebug_DHCSR_S_LOCKUP_Msk       (1ul << CoreDebug_DHCSR_S_LOCKUP_Pos)          /*!< CoreDebug DHCSR: S_LOCKUP Mask */
640→
641→#define CoreDebug_DHCSR_S_SLEEP_Pos        18                                             /*!< CoreDebug DHCSR: S_SLEEP Position */
642→#define CoreDebug_DHCSR_S_SLEEP_Msk        (1ul << CoreDebug_DHCSR_S_SLEEP_Pos)           /*!< CoreDebug DHCSR: S_SLEEP Mask */
643→
644→#define CoreDebug_DHCSR_S_HALT_Pos         17                                             /*!< CoreDebug DHCSR: S_HALT Position */
645→#define CoreDebug_DHCSR_S_HALT_Msk         (1ul << CoreDebug_DHCSR_S_HALT_Pos)            /*!< CoreDebug DHCSR: S_HALT Mask */
646→
647→#define CoreDebug_DHCSR_S_REGRDY_Pos       16                                             /*!< CoreDebug DHCSR: S_REGRDY Position */
648→#define CoreDebug_DHCSR_S_REGRDY_Msk       (1ul << CoreDebug_DHCSR_S_REGRDY_Pos)          /*!< CoreDebug DHCSR: S_REGRDY Mask */
649→
650→#define CoreDebug_DHCSR_C_SNAPSTALL_Pos     5                                             /*!< CoreDebug DHCSR: C_SNAPSTALL Position */
651→#define CoreDebug_DHCSR_C_SNAPSTALL_Msk    (1ul << CoreDebug_DHCSR_C_SNAPSTALL_Pos)       /*!< CoreDebug DHCSR: C_SNAPSTALL Mask */
652→
653→#define CoreDebug_DHCSR_C_MASKINTS_Pos      3                                             /*!< CoreDebug DHCSR: C_MASKINTS Position */
654→#define CoreDebug_DHCSR_C_MASKINTS_Msk     (1ul << CoreDebug_DHCSR_C_MASKINTS_Pos)        /*!< CoreDebug DHCSR: C_MASKINTS Mask */
655→
656→#define CoreDebug_DHCSR_C_STEP_Pos          2                                             /*!< CoreDebug DHCSR: C_STEP Position */
657→#define CoreDebug_DHCSR_C_STEP_Msk         (1ul << CoreDebug_DHCSR_C_STEP_Pos)            /*!< CoreDebug DHCSR: C_STEP Mask */
658→
659→#define CoreDebug_DHCSR_C_HALT_Pos          1                                             /*!< CoreDebug DHCSR: C_HALT Position */
660→#define CoreDebug_DHCSR_C_HALT_Msk         (1ul << CoreDebug_DHCSR_C_HALT_Pos)            /*!< CoreDebug DHCSR: C_HALT Mask */
661→
662→#define CoreDebug_DHCSR_C_DEBUGEN_Pos       0                                             /*!< CoreDebug DHCSR: C_DEBUGEN Position */
663→#define CoreDebug_DHCSR_C_DEBUGEN_Msk      (1ul << CoreDebug_DHCSR_C_DEBUGEN_Pos)         /*!< CoreDebug DHCSR: C_DEBUGEN Mask */
664→
665→/* Debug Core Register Selector Register */
666→#define CoreDebug_DCRSR_REGWnR_Pos         16                                             /*!< CoreDebug DCRSR: REGWnR Position */
667→#define CoreDebug_DCRSR_REGWnR_Msk         (1ul << CoreDebug_DCRSR_REGWnR_Pos)            /*!< CoreDebug DCRSR: REGWnR Mask */
668→
669→#define CoreDebug_DCRSR_REGSEL_Pos          0                                             /*!< CoreDebug DCRSR: REGSEL Position */
670→#define CoreDebug_DCRSR_REGSEL_Msk         (0x1Ful << CoreDebug_DCRSR_REGSEL_Pos)         /*!< CoreDebug DCRSR: REGSEL Mask */
671→
672→/* Debug Exception and Monitor Control Register */
673→#define CoreDebug_DEMCR_TRCENA_Pos         24                                             /*!< CoreDebug DEMCR: TRCENA Position */
674→#define CoreDebug_DEMCR_TRCENA_Msk         (1ul << CoreDebug_DEMCR_TRCENA_Pos)            /*!< CoreDebug DEMCR: TRCENA Mask */
675→
676→#define CoreDebug_DEMCR_MON_REQ_Pos        19                                             /*!< CoreDebug DEMCR: MON_REQ Position */
677→#define CoreDebug_DEMCR_MON_REQ_Msk        (1ul << CoreDebug_DEMCR_MON_REQ_Pos)           /*!< CoreDebug DEMCR: MON_REQ Mask */
678→
679→#define CoreDebug_DEMCR_MON_STEP_Pos       18                                             /*!< CoreDebug DEMCR: MON_STEP Position */
680→#define CoreDebug_DEMCR_MON_STEP_Msk       (1ul << CoreDebug_DEMCR_MON_STEP_Pos)          /*!< CoreDebug DEMCR: MON_STEP Mask */
681→
682→#define CoreDebug_DEMCR_MON_PEND_Pos       17                                             /*!< CoreDebug DEMCR: MON_PEND Position */
683→#define CoreDebug_DEMCR_MON_PEND_Msk       (1ul << CoreDebug_DEMCR_MON_PEND_Pos)          /*!< CoreDebug DEMCR: MON_PEND Mask */
684→
685→#define CoreDebug_DEMCR_MON_EN_Pos         16                                             /*!< CoreDebug DEMCR: MON_EN Position */
686→#define CoreDebug_DEMCR_MON_EN_Msk         (1ul << CoreDebug_DEMCR_MON_EN_Pos)            /*!< CoreDebug DEMCR: MON_EN Mask */
687→
688→#define CoreDebug_DEMCR_VC_HARDERR_Pos     10                                             /*!< CoreDebug DEMCR: VC_HARDERR Position */
689→#define CoreDebug_DEMCR_VC_HARDERR_Msk     (1ul << CoreDebug_DEMCR_VC_HARDERR_Pos)        /*!< CoreDebug DEMCR: VC_HARDERR Mask */
690→
691→#define CoreDebug_DEMCR_VC_INTERR_Pos       9                                             /*!< CoreDebug DEMCR: VC_INTERR Position */
692→#define CoreDebug_DEMCR_VC_INTERR_Msk      (1ul << CoreDebug_DEMCR_VC_INTERR_Pos)         /*!< CoreDebug DEMCR: VC_INTERR Mask */
693→
694→#define CoreDebug_DEMCR_VC_BUSERR_Pos       8                                             /*!< CoreDebug DEMCR: VC_BUSERR Position */
695→#define CoreDebug_DEMCR_VC_BUSERR_Msk      (1ul << CoreDebug_DEMCR_VC_BUSERR_Pos)         /*!< CoreDebug DEMCR: VC_BUSERR Mask */
696→
697→#define CoreDebug_DEMCR_VC_STATERR_Pos      7                                             /*!< CoreDebug DEMCR: VC_STATERR Position */
698→#define CoreDebug_DEMCR_VC_STATERR_Msk     (1ul << CoreDebug_DEMCR_VC_STATERR_Pos)        /*!< CoreDebug DEMCR: VC_STATERR Mask */
699→
700→#define CoreDebug_DEMCR_VC_CHKERR_Pos       6                                             /*!< CoreDebug DEMCR: VC_CHKERR Position */
701→#define CoreDebug_DEMCR_VC_CHKERR_Msk      (1ul << CoreDebug_DEMCR_VC_CHKERR_Pos)         /*!< CoreDebug DEMCR: VC_CHKERR Mask */
702→
703→#define CoreDebug_DEMCR_VC_NOCPERR_Pos      5                                             /*!< CoreDebug DEMCR: VC_NOCPERR Position */
704→#define CoreDebug_DEMCR_VC_NOCPERR_Msk     (1ul << CoreDebug_DEMCR_VC_NOCPERR_Pos)        /*!< CoreDebug DEMCR: VC_NOCPERR Mask */
705→
706→#define CoreDebug_DEMCR_VC_MMERR_Pos        4                                             /*!< CoreDebug DEMCR: VC_MMERR Position */
707→#define CoreDebug_DEMCR_VC_MMERR_Msk       (1ul << CoreDebug_DEMCR_VC_MMERR_Pos)          /*!< CoreDebug DEMCR: VC_MMERR Mask */
708→
709→#define CoreDebug_DEMCR_VC_CORERESET_Pos    0                                             /*!< CoreDebug DEMCR: VC_CORERESET Position */
710→#define CoreDebug_DEMCR_VC_CORERESET_Msk   (1ul << CoreDebug_DEMCR_VC_CORERESET_Pos)      /*!< CoreDebug DEMCR: VC_CORERESET Mask */
711→/*@}*/ /* end of group CMSIS_CM3_CoreDebug */
712→
713→
714→/* Memory mapping of Cortex-M3 Hardware */
715→#define SCS_BASE            (0xE000E000)                              /*!< System Control Space Base Address */
716→#define ITM_BASE            (0xE0000000)                              /*!< ITM Base Address                  */
717→#define CoreDebug_BASE      (0xE000EDF0)                              /*!< Core Debug Base Address           */
718→#define SysTick_BASE        (SCS_BASE +  0x0010)                      /*!< SysTick Base Address              */
719→#define NVIC_BASE           (SCS_BASE +  0x0100)                      /*!< NVIC Base Address                 */
720→#define SCB_BASE            (SCS_BASE +  0x0D00)                      /*!< System Control Block Base Address */
721→
722→#define InterruptType       ((InterruptType_Type *) SCS_BASE)         /*!< Interrupt Type Register           */
723→#define SCB                 ((SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct          */
724→#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick configuration struct      */
725→#define NVIC                ((NVIC_Type *)          NVIC_BASE)        /*!< NVIC configuration struct         */
726→#define ITM                 ((ITM_Type *)           ITM_BASE)         /*!< ITM configuration struct          */