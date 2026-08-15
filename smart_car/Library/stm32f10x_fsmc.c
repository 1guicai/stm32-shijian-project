  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_fsmc.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the FSMC firmware functions.
  8→  ******************************************************************************
  9→  * @attention
 10→  *
 11→  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 12→  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 13→  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 14→  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 15→  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 16→  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 17→  *
 18→  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 19→  ******************************************************************************
 20→  */
 21→
 22→/* Includes ------------------------------------------------------------------*/
 23→#include "stm32f10x_fsmc.h"
 24→#include "stm32f10x_rcc.h"
 25→
 26→/** @addtogroup STM32F10x_StdPeriph_Driver
 27→  * @{
 28→  */
 29→
 30→/** @defgroup FSMC 
 31→  * @brief FSMC driver modules
 32→  * @{
 33→  */ 
 34→
 35→/** @defgroup FSMC_Private_TypesDefinitions
 36→  * @{
 37→  */ 
 38→/**
 39→  * @}
 40→  */
 41→
 42→/** @defgroup FSMC_Private_Defines
 43→  * @{
 44→  */
 45→
 46→/* --------------------- FSMC registers bit mask ---------------------------- */
 47→
 48→/* FSMC BCRx Mask */
 49→#define BCR_MBKEN_Set                       ((uint32_t)0x00000001)
 50→#define BCR_MBKEN_Reset                     ((uint32_t)0x000FFFFE)
 51→#define BCR_FACCEN_Set                      ((uint32_t)0x00000040)
 52→
 53→/* FSMC PCRx Mask */
 54→#define PCR_PBKEN_Set                       ((uint32_t)0x00000004)
 55→#define PCR_PBKEN_Reset                     ((uint32_t)0x000FFFFB)
 56→#define PCR_ECCEN_Set                       ((uint32_t)0x00000040)
 57→#define PCR_ECCEN_Reset                     ((uint32_t)0x000FFFBF)
 58→#define PCR_MemoryType_NAND                 ((uint32_t)0x00000008)
 59→/**
 60→  * @}
 61→  */
 62→
 63→/** @defgroup FSMC_Private_Macros
 64→  * @{
 65→  */
 66→
 67→/**
 68→  * @}
 69→  */
 70→
 71→/** @defgroup FSMC_Private_Variables
 72→  * @{
 73→  */
 74→
 75→/**
 76→  * @}
 77→  */
 78→
 79→/** @defgroup FSMC_Private_FunctionPrototypes
 80→  * @{
 81→  */
 82→
 83→/**
 84→  * @}
 85→  */
 86→
 87→/** @defgroup FSMC_Private_Functions
 88→  * @{
 89→  */
 90→
 91→/**
 92→  * @brief  Deinitializes the FSMC NOR/SRAM Banks registers to their default 
 93→  *         reset values.
 94→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
 95→  *   This parameter can be one of the following values:
 96→  *     @arg FSMC_Bank1_NORSRAM1: FSMC Bank1 NOR/SRAM1  
 97→  *     @arg FSMC_Bank1_NORSRAM2: FSMC Bank1 NOR/SRAM2 
 98→  *     @arg FSMC_Bank1_NORSRAM3: FSMC Bank1 NOR/SRAM3 
 99→  *     @arg FSMC_Bank1_NORSRAM4: FSMC Bank1 NOR/SRAM4 
100→  * @retval None
101→  */
102→void FSMC_NORSRAMDeInit(uint32_t FSMC_Bank)
103→{
104→  /* Check the parameter */
105→  assert_param(IS_FSMC_NORSRAM_BANK(FSMC_Bank));
106→  
107→  /* FSMC_Bank1_NORSRAM1 */
108→  if(FSMC_Bank == FSMC_Bank1_NORSRAM1)
109→  {
110→    FSMC_Bank1->BTCR[FSMC_Bank] = 0x000030DB;    
111→  }
112→  /* FSMC_Bank1_NORSRAM2,  FSMC_Bank1_NORSRAM3 or FSMC_Bank1_NORSRAM4 */
113→  else
114→  {   
115→    FSMC_Bank1->BTCR[FSMC_Bank] = 0x000030D2; 
116→  }
117→  FSMC_Bank1->BTCR[FSMC_Bank + 1] = 0x0FFFFFFF;
118→  FSMC_Bank1E->BWTR[FSMC_Bank] = 0x0FFFFFFF;  
119→}
120→
121→/**
122→  * @brief  Deinitializes the FSMC NAND Banks registers to their default reset values.
123→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
124→  *   This parameter can be one of the following values:
125→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
126→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND 
127→  * @retval None
128→  */
129→void FSMC_NANDDeInit(uint32_t FSMC_Bank)
130→{
131→  /* Check the parameter */
132→  assert_param(IS_FSMC_NAND_BANK(FSMC_Bank));
133→  
134→  if(FSMC_Bank == FSMC_Bank2_NAND)
135→  {
136→    /* Set the FSMC_Bank2 registers to their reset values */
137→    FSMC_Bank2->PCR2 = 0x00000018;
138→    FSMC_Bank2->SR2 = 0x00000040;
139→    FSMC_Bank2->PMEM2 = 0xFCFCFCFC;
140→    FSMC_Bank2->PATT2 = 0xFCFCFCFC;  
141→  }
142→  /* FSMC_Bank3_NAND */  
143→  else
144→  {
145→    /* Set the FSMC_Bank3 registers to their reset values */
146→    FSMC_Bank3->PCR3 = 0x00000018;
147→    FSMC_Bank3->SR3 = 0x00000040;
148→    FSMC_Bank3->PMEM3 = 0xFCFCFCFC;
149→    FSMC_Bank3->PATT3 = 0xFCFCFCFC; 
150→  }  
151→}
152→
153→/**
154→  * @brief  Deinitializes the FSMC PCCARD Bank registers to their default reset values.
155→  * @param  None                       
156→  * @retval None
157→  */
158→void FSMC_PCCARDDeInit(void)
159→{
160→  /* Set the FSMC_Bank4 registers to their reset values */
161→  FSMC_Bank4->PCR4 = 0x00000018; 
162→  FSMC_Bank4->SR4 = 0x00000000;	
163→  FSMC_Bank4->PMEM4 = 0xFCFCFCFC;
164→  FSMC_Bank4->PATT4 = 0xFCFCFCFC;
165→  FSMC_Bank4->PIO4 = 0xFCFCFCFC;
166→}
167→
168→/**
169→  * @brief  Initializes the FSMC NOR/SRAM Banks according to the specified
170→  *         parameters in the FSMC_NORSRAMInitStruct.
171→  * @param  FSMC_NORSRAMInitStruct : pointer to a FSMC_NORSRAMInitTypeDef
172→  *         structure that contains the configuration information for 
173→  *        the FSMC NOR/SRAM specified Banks.                       
174→  * @retval None
175→  */
176→void FSMC_NORSRAMInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct)
177→{ 
178→  /* Check the parameters */
179→  assert_param(IS_FSMC_NORSRAM_BANK(FSMC_NORSRAMInitStruct->FSMC_Bank));
180→  assert_param(IS_FSMC_MUX(FSMC_NORSRAMInitStruct->FSMC_DataAddressMux));
181→  assert_param(IS_FSMC_MEMORY(FSMC_NORSRAMInitStruct->FSMC_MemoryType));
182→  assert_param(IS_FSMC_MEMORY_WIDTH(FSMC_NORSRAMInitStruct->FSMC_MemoryDataWidth));
183→  assert_param(IS_FSMC_BURSTMODE(FSMC_NORSRAMInitStruct->FSMC_BurstAccessMode));
184→  assert_param(IS_FSMC_ASYNWAIT(FSMC_NORSRAMInitStruct->FSMC_AsynchronousWait));
185→  assert_param(IS_FSMC_WAIT_POLARITY(FSMC_NORSRAMInitStruct->FSMC_WaitSignalPolarity));
186→  assert_param(IS_FSMC_WRAP_MODE(FSMC_NORSRAMInitStruct->FSMC_WrapMode));
187→  assert_param(IS_FSMC_WAIT_SIGNAL_ACTIVE(FSMC_NORSRAMInitStruct->FSMC_WaitSignalActive));
188→  assert_param(IS_FSMC_WRITE_OPERATION(FSMC_NORSRAMInitStruct->FSMC_WriteOperation));
189→  assert_param(IS_FSMC_WAITE_SIGNAL(FSMC_NORSRAMInitStruct->FSMC_WaitSignal));
190→  assert_param(IS_FSMC_EXTENDED_MODE(FSMC_NORSRAMInitStruct->FSMC_ExtendedMode));
191→  assert_param(IS_FSMC_WRITE_BURST(FSMC_NORSRAMInitStruct->FSMC_WriteBurst));  
192→  assert_param(IS_FSMC_ADDRESS_SETUP_TIME(FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AddressSetupTime));
193→  assert_param(IS_FSMC_ADDRESS_HOLD_TIME(FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AddressHoldTime));
194→  assert_param(IS_FSMC_DATASETUP_TIME(FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_DataSetupTime));
195→  assert_param(IS_FSMC_TURNAROUND_TIME(FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_BusTurnAroundDuration));
196→  assert_param(IS_FSMC_CLK_DIV(FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_CLKDivision));
197→  assert_param(IS_FSMC_DATA_LATENCY(FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_DataLatency));
198→  assert_param(IS_FSMC_ACCESS_MODE(FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AccessMode)); 
199→  
200→  /* Bank1 NOR/SRAM control register configuration */ 
201→  FSMC_Bank1->BTCR[FSMC_NORSRAMInitStruct->FSMC_Bank] = 
202→            (uint32_t)FSMC_NORSRAMInitStruct->FSMC_DataAddressMux |
203→            FSMC_NORSRAMInitStruct->FSMC_MemoryType |
204→            FSMC_NORSRAMInitStruct->FSMC_MemoryDataWidth |
205→            FSMC_NORSRAMInitStruct->FSMC_BurstAccessMode |
206→            FSMC_NORSRAMInitStruct->FSMC_AsynchronousWait |
207→            FSMC_NORSRAMInitStruct->FSMC_WaitSignalPolarity |
208→            FSMC_NORSRAMInitStruct->FSMC_WrapMode |
209→            FSMC_NORSRAMInitStruct->FSMC_WaitSignalActive |
210→            FSMC_NORSRAMInitStruct->FSMC_WriteOperation |
211→            FSMC_NORSRAMInitStruct->FSMC_WaitSignal |
212→            FSMC_NORSRAMInitStruct->FSMC_ExtendedMode |
213→            FSMC_NORSRAMInitStruct->FSMC_WriteBurst;
214→
215→  if(FSMC_NORSRAMInitStruct->FSMC_MemoryType == FSMC_MemoryType_NOR)
216→  {
217→    FSMC_Bank1->BTCR[FSMC_NORSRAMInitStruct->FSMC_Bank] |= (uint32_t)BCR_FACCEN_Set;
218→  }
219→  
220→  /* Bank1 NOR/SRAM timing register configuration */
221→  FSMC_Bank1->BTCR[FSMC_NORSRAMInitStruct->FSMC_Bank+1] = 
222→            (uint32_t)FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AddressSetupTime |
223→            (FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AddressHoldTime << 4) |
224→            (FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_DataSetupTime << 8) |
225→            (FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_BusTurnAroundDuration << 16) |
226→            (FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_CLKDivision << 20) |
227→            (FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_DataLatency << 24) |
228→             FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AccessMode;
229→            
230→    
231→  /* Bank1 NOR/SRAM timing register for write configuration, if extended mode is used */
232→  if(FSMC_NORSRAMInitStruct->FSMC_ExtendedMode == FSMC_ExtendedMode_Enable)
233→  {
234→    assert_param(IS_FSMC_ADDRESS_SETUP_TIME(FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AddressSetupTime));
235→    assert_param(IS_FSMC_ADDRESS_HOLD_TIME(FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AddressHoldTime));
236→    assert_param(IS_FSMC_DATASETUP_TIME(FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_DataSetupTime));
237→    assert_param(IS_FSMC_CLK_DIV(FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_CLKDivision));
238→    assert_param(IS_FSMC_DATA_LATENCY(FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_DataLatency));
239→    assert_param(IS_FSMC_ACCESS_MODE(FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AccessMode));
240→    FSMC_Bank1E->BWTR[FSMC_NORSRAMInitStruct->FSMC_Bank] = 
241→              (uint32_t)FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AddressSetupTime |
242→              (FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AddressHoldTime << 4 )|
243→              (FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_DataSetupTime << 8) |
244→              (FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_CLKDivision << 20) |
245→              (FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_DataLatency << 24) |
246→               FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AccessMode;
247→  }
248→  else
249→  {
250→    FSMC_Bank1E->BWTR[FSMC_NORSRAMInitStruct->FSMC_Bank] = 0x0FFFFFFF;
251→  }
252→}
253→
254→/**
255→  * @brief  Initializes the FSMC NAND Banks according to the specified 
256→  *         parameters in the FSMC_NANDInitStruct.
257→  * @param  FSMC_NANDInitStruct : pointer to a FSMC_NANDInitTypeDef 
258→  *         structure that contains the configuration information for the FSMC 
259→  *         NAND specified Banks.                       
260→  * @retval None
261→  */
262→void FSMC_NANDInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct)
263→{
264→  uint32_t tmppcr = 0x00000000, tmppmem = 0x00000000, tmppatt = 0x00000000; 
265→    
266→  /* Check the parameters */
267→  assert_param( IS_FSMC_NAND_BANK(FSMC_NANDInitStruct->FSMC_Bank));
268→  assert_param( IS_FSMC_WAIT_FEATURE(FSMC_NANDInitStruct->FSMC_Waitfeature));
269→  assert_param( IS_FSMC_MEMORY_WIDTH(FSMC_NANDInitStruct->FSMC_MemoryDataWidth));
270→  assert_param( IS_FSMC_ECC_STATE(FSMC_NANDInitStruct->FSMC_ECC));
271→  assert_param( IS_FSMC_ECCPAGE_SIZE(FSMC_NANDInitStruct->FSMC_ECCPageSize));
272→  assert_param( IS_FSMC_TCLR_TIME(FSMC_NANDInitStruct->FSMC_TCLRSetupTime));
273→  assert_param( IS_FSMC_TAR_TIME(FSMC_NANDInitStruct->FSMC_TARSetupTime));
274→  assert_param(IS_FSMC_SETUP_TIME(FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_SetupTime));
275→  assert_param(IS_FSMC_WAIT_TIME(FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_WaitSetupTime));
276→  assert_param(IS_FSMC_HOLD_TIME(FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HoldSetupTime));
277→  assert_param(IS_FSMC_HIZ_TIME(FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HiZSetupTime));
278→  assert_param(IS_FSMC_SETUP_TIME(FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_SetupTime));
279→  assert_param(IS_FSMC_WAIT_TIME(FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_WaitSetupTime));
280→  assert_param(IS_FSMC_HOLD_TIME(FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HoldSetupTime));
281→  assert_param(IS_FSMC_HIZ_TIME(FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HiZSetupTime));
282→  
283→  /* Set the tmppcr value according to FSMC_NANDInitStruct parameters */
284→  tmppcr = (uint32_t)FSMC_NANDInitStruct->FSMC_Waitfeature |
285→            PCR_MemoryType_NAND |
286→            FSMC_NANDInitStruct->FSMC_MemoryDataWidth |
287→            FSMC_NANDInitStruct->FSMC_ECC |
288→            FSMC_NANDInitStruct->FSMC_ECCPageSize |
289→            (FSMC_NANDInitStruct->FSMC_TCLRSetupTime << 9 )|
290→            (FSMC_NANDInitStruct->FSMC_TARSetupTime << 13);
291→            
292→  /* Set tmppmem value according to FSMC_CommonSpaceTimingStructure parameters */
293→  tmppmem = (uint32_t)FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_SetupTime |
294→            (FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_WaitSetupTime << 8) |
295→            (FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HoldSetupTime << 16)|
296→            (FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HiZSetupTime << 24); 
297→            
298→  /* Set tmppatt value according to FSMC_AttributeSpaceTimingStructure parameters */
299→  tmppatt = (uint32_t)FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_SetupTime |
300→            (FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_WaitSetupTime << 8) |
301→            (FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HoldSetupTime << 16)|
302→            (FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HiZSetupTime << 24);
303→  
304→  if(FSMC_NANDInitStruct->FSMC_Bank == FSMC_Bank2_NAND)
305→  {
306→    /* FSMC_Bank2_NAND registers configuration */
307→    FSMC_Bank2->PCR2 = tmppcr;
308→    FSMC_Bank2->PMEM2 = tmppmem;
309→    FSMC_Bank2->PATT2 = tmppatt;
310→  }
311→  else
312→  {
313→    /* FSMC_Bank3_NAND registers configuration */
314→    FSMC_Bank3->PCR3 = tmppcr;
315→    FSMC_Bank3->PMEM3 = tmppmem;
316→    FSMC_Bank3->PATT3 = tmppatt;
317→  }
318→}
319→
320→/**
321→  * @brief  Initializes the FSMC PCCARD Bank according to the specified 
322→  *         parameters in the FSMC_PCCARDInitStruct.
323→  * @param  FSMC_PCCARDInitStruct : pointer to a FSMC_PCCARDInitTypeDef
324→  *         structure that contains the configuration information for the FSMC 
325→  *         PCCARD Bank.                       
326→  * @retval None
327→  */
328→void FSMC_PCCARDInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct)
329→{
330→  /* Check the parameters */
331→  assert_param(IS_FSMC_WAIT_FEATURE(FSMC_PCCARDInitStruct->FSMC_Waitfeature));
332→  assert_param(IS_FSMC_TCLR_TIME(FSMC_PCCARDInitStruct->FSMC_TCLRSetupTime));
333→  assert_param(IS_FSMC_TAR_TIME(FSMC_PCCARDInitStruct->FSMC_TARSetupTime));
334→ 
335→  assert_param(IS_FSMC_SETUP_TIME(FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_SetupTime));
336→  assert_param(IS_FSMC_WAIT_TIME(FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_WaitSetupTime));
337→  assert_param(IS_FSMC_HOLD_TIME(FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HoldSetupTime));
338→  assert_param(IS_FSMC_HIZ_TIME(FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HiZSetupTime));
339→  
340→  assert_param(IS_FSMC_SETUP_TIME(FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_SetupTime));
341→  assert_param(IS_FSMC_WAIT_TIME(FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_WaitSetupTime));
342→  assert_param(IS_FSMC_HOLD_TIME(FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HoldSetupTime));
343→  assert_param(IS_FSMC_HIZ_TIME(FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HiZSetupTime));
344→  assert_param(IS_FSMC_SETUP_TIME(FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_SetupTime));
345→  assert_param(IS_FSMC_WAIT_TIME(FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_WaitSetupTime));
346→  assert_param(IS_FSMC_HOLD_TIME(FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_HoldSetupTime));
347→  assert_param(IS_FSMC_HIZ_TIME(FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_HiZSetupTime));
348→  
349→  /* Set the PCR4 register value according to FSMC_PCCARDInitStruct parameters */
350→  FSMC_Bank4->PCR4 = (uint32_t)FSMC_PCCARDInitStruct->FSMC_Waitfeature |
351→                     FSMC_MemoryDataWidth_16b |  
352→                     (FSMC_PCCARDInitStruct->FSMC_TCLRSetupTime << 9) |
353→                     (FSMC_PCCARDInitStruct->FSMC_TARSetupTime << 13);
354→            
355→  /* Set PMEM4 register value according to FSMC_CommonSpaceTimingStructure parameters */
356→  FSMC_Bank4->PMEM4 = (uint32_t)FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_SetupTime |
357→                      (FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_WaitSetupTime << 8) |
358→                      (FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HoldSetupTime << 16)|
359→                      (FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HiZSetupTime << 24); 
360→            
361→  /* Set PATT4 register value according to FSMC_AttributeSpaceTimingStructure parameters */
362→  FSMC_Bank4->PATT4 = (uint32_t)FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_SetupTime |
363→                      (FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_WaitSetupTime << 8) |
364→                      (FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HoldSetupTime << 16)|
365→                      (FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HiZSetupTime << 24);	
366→            
367→  /* Set PIO4 register value according to FSMC_IOSpaceTimingStructure parameters */
368→  FSMC_Bank4->PIO4 = (uint32_t)FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_SetupTime |
369→                     (FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_WaitSetupTime << 8) |
370→                     (FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_HoldSetupTime << 16)|
371→                     (FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_HiZSetupTime << 24);             
372→}
373→
374→/**
375→  * @brief  Fills each FSMC_NORSRAMInitStruct member with its default value.
376→  * @param  FSMC_NORSRAMInitStruct: pointer to a FSMC_NORSRAMInitTypeDef 
377→  *         structure which will be initialized.
378→  * @retval None
379→  */
380→void FSMC_NORSRAMStructInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct)
381→{  
382→  /* Reset NOR/SRAM Init structure parameters values */
383→  FSMC_NORSRAMInitStruct->FSMC_Bank = FSMC_Bank1_NORSRAM1;
384→  FSMC_NORSRAMInitStruct->FSMC_DataAddressMux = FSMC_DataAddressMux_Enable;
385→  FSMC_NORSRAMInitStruct->FSMC_MemoryType = FSMC_MemoryType_SRAM;
386→  FSMC_NORSRAMInitStruct->FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
387→  FSMC_NORSRAMInitStruct->FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
388→  FSMC_NORSRAMInitStruct->FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
389→  FSMC_NORSRAMInitStruct->FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
390→  FSMC_NORSRAMInitStruct->FSMC_WrapMode = FSMC_WrapMode_Disable;
391→  FSMC_NORSRAMInitStruct->FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
392→  FSMC_NORSRAMInitStruct->FSMC_WriteOperation = FSMC_WriteOperation_Enable;
393→  FSMC_NORSRAMInitStruct->FSMC_WaitSignal = FSMC_WaitSignal_Enable;
394→  FSMC_NORSRAMInitStruct->FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
395→  FSMC_NORSRAMInitStruct->FSMC_WriteBurst = FSMC_WriteBurst_Disable;
396→  FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AddressSetupTime = 0xF;
397→  FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AddressHoldTime = 0xF;
398→  FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_DataSetupTime = 0xFF;
399→  FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_BusTurnAroundDuration = 0xF;
400→  FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_CLKDivision = 0xF;
401→  FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_DataLatency = 0xF;
402→  FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AccessMode = FSMC_AccessMode_A; 
403→  FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AddressSetupTime = 0xF;
404→  FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AddressHoldTime = 0xF;
405→  FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_DataSetupTime = 0xFF;
406→  FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_BusTurnAroundDuration = 0xF;
407→  FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_CLKDivision = 0xF;
408→  FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_DataLatency = 0xF;
409→  FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AccessMode = FSMC_AccessMode_A;
410→}
411→
412→/**
413→  * @brief  Fills each FSMC_NANDInitStruct member with its default value.
414→  * @param  FSMC_NANDInitStruct: pointer to a FSMC_NANDInitTypeDef 
415→  *         structure which will be initialized.
416→  * @retval None
417→  */
418→void FSMC_NANDStructInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct)
419→{ 
420→  /* Reset NAND Init structure parameters values */
421→  FSMC_NANDInitStruct->FSMC_Bank = FSMC_Bank2_NAND;
422→  FSMC_NANDInitStruct->FSMC_Waitfeature = FSMC_Waitfeature_Disable;
423→  FSMC_NANDInitStruct->FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
424→  FSMC_NANDInitStruct->FSMC_ECC = FSMC_ECC_Disable;
425→  FSMC_NANDInitStruct->FSMC_ECCPageSize = FSMC_ECCPageSize_256Bytes;
426→  FSMC_NANDInitStruct->FSMC_TCLRSetupTime = 0x0;
427→  FSMC_NANDInitStruct->FSMC_TARSetupTime = 0x0;
428→  FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_SetupTime = 0xFC;
429→  FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_WaitSetupTime = 0xFC;
430→  FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HoldSetupTime = 0xFC;
431→  FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HiZSetupTime = 0xFC;
432→  FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_SetupTime = 0xFC;
433→  FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_WaitSetupTime = 0xFC;
434→  FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HoldSetupTime = 0xFC;
435→  FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HiZSetupTime = 0xFC;	  
436→}
437→
438→/**
439→  * @brief  Fills each FSMC_PCCARDInitStruct member with its default value.
440→  * @param  FSMC_PCCARDInitStruct: pointer to a FSMC_PCCARDInitTypeDef 
441→  *         structure which will be initialized.
442→  * @retval None
443→  */
444→void FSMC_PCCARDStructInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct)
445→{
446→  /* Reset PCCARD Init structure parameters values */
447→  FSMC_PCCARDInitStruct->FSMC_Waitfeature = FSMC_Waitfeature_Disable;
448→  FSMC_PCCARDInitStruct->FSMC_TCLRSetupTime = 0x0;
449→  FSMC_PCCARDInitStruct->FSMC_TARSetupTime = 0x0;
450→  FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_SetupTime = 0xFC;
451→  FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_WaitSetupTime = 0xFC;
452→  FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HoldSetupTime = 0xFC;
453→  FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_HiZSetupTime = 0xFC;
454→  FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_SetupTime = 0xFC;
455→  FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_WaitSetupTime = 0xFC;
456→  FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HoldSetupTime = 0xFC;
457→  FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HiZSetupTime = 0xFC;	
458→  FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_SetupTime = 0xFC;
459→  FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_WaitSetupTime = 0xFC;
460→  FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_HoldSetupTime = 0xFC;
461→  FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_HiZSetupTime = 0xFC;
462→}
463→
464→/**
465→  * @brief  Enables or disables the specified NOR/SRAM Memory Bank.
466→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
467→  *   This parameter can be one of the following values:
468→  *     @arg FSMC_Bank1_NORSRAM1: FSMC Bank1 NOR/SRAM1  
469→  *     @arg FSMC_Bank1_NORSRAM2: FSMC Bank1 NOR/SRAM2 
470→  *     @arg FSMC_Bank1_NORSRAM3: FSMC Bank1 NOR/SRAM3 
471→  *     @arg FSMC_Bank1_NORSRAM4: FSMC Bank1 NOR/SRAM4 
472→  * @param  NewState: new state of the FSMC_Bank. This parameter can be: ENABLE or DISABLE.
473→  * @retval None
474→  */
475→void FSMC_NORSRAMCmd(uint32_t FSMC_Bank, FunctionalState NewState)
476→{
477→  assert_param(IS_FSMC_NORSRAM_BANK(FSMC_Bank));
478→  assert_param(IS_FUNCTIONAL_STATE(NewState));
479→  
480→  if (NewState != DISABLE)
481→  {
482→    /* Enable the selected NOR/SRAM Bank by setting the PBKEN bit in the BCRx register */
483→    FSMC_Bank1->BTCR[FSMC_Bank] |= BCR_MBKEN_Set;
484→  }
485→  else
486→  {
487→    /* Disable the selected NOR/SRAM Bank by clearing the PBKEN bit in the BCRx register */
488→    FSMC_Bank1->BTCR[FSMC_Bank] &= BCR_MBKEN_Reset;
489→  }
490→}
491→
492→/**
493→  * @brief  Enables or disables the specified NAND Memory Bank.
494→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
495→  *   This parameter can be one of the following values:
496→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
497→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
498→  * @param  NewState: new state of the FSMC_Bank. This parameter can be: ENABLE or DISABLE.
499→  * @retval None
500→  */
501→void FSMC_NANDCmd(uint32_t FSMC_Bank, FunctionalState NewState)
502→{
503→  assert_param(IS_FSMC_NAND_BANK(FSMC_Bank));
504→  assert_param(IS_FUNCTIONAL_STATE(NewState));
505→  
506→  if (NewState != DISABLE)
507→  {
508→    /* Enable the selected NAND Bank by setting the PBKEN bit in the PCRx register */
509→    if(FSMC_Bank == FSMC_Bank2_NAND)
510→    {
511→      FSMC_Bank2->PCR2 |= PCR_PBKEN_Set;
512→    }
513→    else
514→    {
515→      FSMC_Bank3->PCR3 |= PCR_PBKEN_Set;
516→    }
517→  }
518→  else
519→  {
520→    /* Disable the selected NAND Bank by clearing the PBKEN bit in the PCRx register */
521→    if(FSMC_Bank == FSMC_Bank2_NAND)
522→    {
523→      FSMC_Bank2->PCR2 &= PCR_PBKEN_Reset;
524→    }
525→    else
526→    {
527→      FSMC_Bank3->PCR3 &= PCR_PBKEN_Reset;
528→    }
529→  }
530→}
531→
532→/**
533→  * @brief  Enables or disables the PCCARD Memory Bank.
534→  * @param  NewState: new state of the PCCARD Memory Bank.  
535→  *   This parameter can be: ENABLE or DISABLE.
536→  * @retval None
537→  */
538→void FSMC_PCCARDCmd(FunctionalState NewState)
539→{
540→  assert_param(IS_FUNCTIONAL_STATE(NewState));
541→  
542→  if (NewState != DISABLE)
543→  {
544→    /* Enable the PCCARD Bank by setting the PBKEN bit in the PCR4 register */
545→    FSMC_Bank4->PCR4 |= PCR_PBKEN_Set;
546→  }
547→  else
548→  {
549→    /* Disable the PCCARD Bank by clearing the PBKEN bit in the PCR4 register */
550→    FSMC_Bank4->PCR4 &= PCR_PBKEN_Reset;
551→  }
552→}
553→
554→/**
555→  * @brief  Enables or disables the FSMC NAND ECC feature.
556→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
557→  *   This parameter can be one of the following values:
558→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
559→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
560→  * @param  NewState: new state of the FSMC NAND ECC feature.  
561→  *   This parameter can be: ENABLE or DISABLE.
562→  * @retval None
563→  */
564→void FSMC_NANDECCCmd(uint32_t FSMC_Bank, FunctionalState NewState)
565→{
566→  assert_param(IS_FSMC_NAND_BANK(FSMC_Bank));
567→  assert_param(IS_FUNCTIONAL_STATE(NewState));
568→  
569→  if (NewState != DISABLE)
570→  {
571→    /* Enable the selected NAND Bank ECC function by setting the ECCEN bit in the PCRx register */
572→    if(FSMC_Bank == FSMC_Bank2_NAND)
573→    {
574→      FSMC_Bank2->PCR2 |= PCR_ECCEN_Set;
575→    }
576→    else
577→    {
578→      FSMC_Bank3->PCR3 |= PCR_ECCEN_Set;
579→    }
580→  }
581→  else
582→  {
583→    /* Disable the selected NAND Bank ECC function by clearing the ECCEN bit in the PCRx register */
584→    if(FSMC_Bank == FSMC_Bank2_NAND)
585→    {
586→      FSMC_Bank2->PCR2 &= PCR_ECCEN_Reset;
587→    }
588→    else
589→    {
590→      FSMC_Bank3->PCR3 &= PCR_ECCEN_Reset;
591→    }
592→  }
593→}
594→
595→/**
596→  * @brief  Returns the error correction code register value.
597→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
598→  *   This parameter can be one of the following values:
599→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
600→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
601→  * @retval The Error Correction Code (ECC) value.
602→  */
603→uint32_t FSMC_GetECC(uint32_t FSMC_Bank)
604→{
605→  uint32_t eccval = 0x00000000;
606→  
607→  if(FSMC_Bank == FSMC_Bank2_NAND)
608→  {
609→    /* Get the ECCR2 register value */
610→    eccval = FSMC_Bank2->ECCR2;
611→  }
612→  else
613→  {
614→    /* Get the ECCR3 register value */
615→    eccval = FSMC_Bank3->ECCR3;
616→  }
617→  /* Return the error correction code value */
618→  return(eccval);
619→}
620→
621→/**
622→  * @brief  Enables or disables the specified FSMC interrupts.
623→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
624→  *   This parameter can be one of the following values:
625→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
626→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
627→  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
628→  * @param  FSMC_IT: specifies the FSMC interrupt sources to be enabled or disabled.
629→  *   This parameter can be any combination of the following values:
630→  *     @arg FSMC_IT_RisingEdge: Rising edge detection interrupt. 
631→  *     @arg FSMC_IT_Level: Level edge detection interrupt.
632→  *     @arg FSMC_IT_FallingEdge: Falling edge detection interrupt.
633→  * @param  NewState: new state of the specified FSMC interrupts.
634→  *   This parameter can be: ENABLE or DISABLE.
635→  * @retval None
636→  */
637→void FSMC_ITConfig(uint32_t FSMC_Bank, uint32_t FSMC_IT, FunctionalState NewState)
638→{
639→  assert_param(IS_FSMC_IT_BANK(FSMC_Bank));
640→  assert_param(IS_FSMC_IT(FSMC_IT));	
641→  assert_param(IS_FUNCTIONAL_STATE(NewState));
642→  
643→  if (NewState != DISABLE)
644→  {
645→    /* Enable the selected FSMC_Bank2 interrupts */
646→    if(FSMC_Bank == FSMC_Bank2_NAND)
647→    {
648→      FSMC_Bank2->SR2 |= FSMC_IT;
649→    }
650→    /* Enable the selected FSMC_Bank3 interrupts */
651→    else if (FSMC_Bank == FSMC_Bank3_NAND)
652→    {
653→      FSMC_Bank3->SR3 |= FSMC_IT;
654→    }
655→    /* Enable the selected FSMC_Bank4 interrupts */
656→    else
657→    {
658→      FSMC_Bank4->SR4 |= FSMC_IT;    
659→    }
660→  }
661→  else
662→  {
663→    /* Disable the selected FSMC_Bank2 interrupts */
664→    if(FSMC_Bank == FSMC_Bank2_NAND)
665→    {
666→      
667→      FSMC_Bank2->SR2 &= (uint32_t)~FSMC_IT;
668→    }
669→    /* Disable the selected FSMC_Bank3 interrupts */
670→    else if (FSMC_Bank == FSMC_Bank3_NAND)
671→    {
672→      FSMC_Bank3->SR3 &= (uint32_t)~FSMC_IT;
673→    }
674→    /* Disable the selected FSMC_Bank4 interrupts */
675→    else
676→    {
677→      FSMC_Bank4->SR4 &= (uint32_t)~FSMC_IT;    
678→    }
679→  }
680→}
681→
682→/**
683→  * @brief  Checks whether the specified FSMC flag is set or not.
684→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
685→  *   This parameter can be one of the following values:
686→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
687→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
688→  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
689→  * @param  FSMC_FLAG: specifies the flag to check.
690→  *   This parameter can be one of the following values:
691→  *     @arg FSMC_FLAG_RisingEdge: Rising egde detection Flag.
692→  *     @arg FSMC_FLAG_Level: Level detection Flag.
693→  *     @arg FSMC_FLAG_FallingEdge: Falling egde detection Flag.
694→  *     @arg FSMC_FLAG_FEMPT: Fifo empty Flag. 
695→  * @retval The new state of FSMC_FLAG (SET or RESET).
696→  */
697→FlagStatus FSMC_GetFlagStatus(uint32_t FSMC_Bank, uint32_t FSMC_FLAG)
698→{
699→  FlagStatus bitstatus = RESET;
700→  uint32_t tmpsr = 0x00000000;
701→  
702→  /* Check the parameters */
703→  assert_param(IS_FSMC_GETFLAG_BANK(FSMC_Bank));
704→  assert_param(IS_FSMC_GET_FLAG(FSMC_FLAG));
705→  
706→  if(FSMC_Bank == FSMC_Bank2_NAND)
707→  {
708→    tmpsr = FSMC_Bank2->SR2;
709→  }  
710→  else if(FSMC_Bank == FSMC_Bank3_NAND)
711→  {
712→    tmpsr = FSMC_Bank3->SR3;
713→  }
714→  /* FSMC_Bank4_PCCARD*/
715→  else
716→  {
717→    tmpsr = FSMC_Bank4->SR4;
718→  } 
719→  
720→  /* Get the flag status */
721→  if ((tmpsr & FSMC_FLAG) != (uint16_t)RESET )
722→  {
723→    bitstatus = SET;
724→  }
725→  else
726→  {
727→    bitstatus = RESET;
728→  }
729→  /* Return the flag status */
730→  return bitstatus;
731→}
732→
733→/**
734→  * @brief  Clears the FSMC's pending flags.
735→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
736→  *   This parameter can be one of the following values:
737→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
738→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
739→  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
740→  * @param  FSMC_FLAG: specifies the flag to clear.
741→  *   This parameter can be any combination of the following values:
742→  *     @arg FSMC_FLAG_RisingEdge: Rising egde detection Flag.
743→  *     @arg FSMC_FLAG_Level: Level detection Flag.
744→  *     @arg FSMC_FLAG_FallingEdge: Falling egde detection Flag.
745→  * @retval None
746→  */
747→void FSMC_ClearFlag(uint32_t FSMC_Bank, uint32_t FSMC_FLAG)
748→{
749→ /* Check the parameters */
750→  assert_param(IS_FSMC_GETFLAG_BANK(FSMC_Bank));
751→  assert_param(IS_FSMC_CLEAR_FLAG(FSMC_FLAG)) ;
752→    
753→  if(FSMC_Bank == FSMC_Bank2_NAND)
754→  {
755→    FSMC_Bank2->SR2 &= ~FSMC_FLAG; 
756→  }  
757→  else if(FSMC_Bank == FSMC_Bank3_NAND)
758→  {
759→    FSMC_Bank3->SR3 &= ~FSMC_FLAG;
760→  }
761→  /* FSMC_Bank4_PCCARD*/
762→  else
763→  {
764→    FSMC_Bank4->SR4 &= ~FSMC_FLAG;
765→  }
766→}
767→
768→/**
769→  * @brief  Checks whether the specified FSMC interrupt has occurred or not.
770→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
771→  *   This parameter can be one of the following values:
772→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
773→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
774→  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
775→  * @param  FSMC_IT: specifies the FSMC interrupt source to check.
776→  *   This parameter can be one of the following values:
777→  *     @arg FSMC_IT_RisingEdge: Rising edge detection interrupt. 
778→  *     @arg FSMC_IT_Level: Level edge detection interrupt.
779→  *     @arg FSMC_IT_FallingEdge: Falling edge detection interrupt. 
780→  * @retval The new state of FSMC_IT (SET or RESET).
781→  */
782→ITStatus FSMC_GetITStatus(uint32_t FSMC_Bank, uint32_t FSMC_IT)
783→{
784→  ITStatus bitstatus = RESET;
785→  uint32_t tmpsr = 0x0, itstatus = 0x0, itenable = 0x0; 
786→  
787→  /* Check the parameters */
788→  assert_param(IS_FSMC_IT_BANK(FSMC_Bank));
789→  assert_param(IS_FSMC_GET_IT(FSMC_IT));
790→  
791→  if(FSMC_Bank == FSMC_Bank2_NAND)
792→  {
793→    tmpsr = FSMC_Bank2->SR2;
794→  }  
795→  else if(FSMC_Bank == FSMC_Bank3_NAND)
796→  {
797→    tmpsr = FSMC_Bank3->SR3;
798→  }
799→  /* FSMC_Bank4_PCCARD*/
800→  else
801→  {
802→    tmpsr = FSMC_Bank4->SR4;
803→  } 
804→  
805→  itstatus = tmpsr & FSMC_IT;
806→  
807→  itenable = tmpsr & (FSMC_IT >> 3);
808→  if ((itstatus != (uint32_t)RESET)  && (itenable != (uint32_t)RESET))
809→  {
810→    bitstatus = SET;
811→  }
812→  else
813→  {
814→    bitstatus = RESET;
815→  }
816→  return bitstatus; 
817→}
818→
819→/**
820→  * @brief  Clears the FSMC's interrupt pending bits.
821→  * @param  FSMC_Bank: specifies the FSMC Bank to be used
822→  *   This parameter can be one of the following values:
823→  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
824→  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
825→  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
826→  * @param  FSMC_IT: specifies the interrupt pending bit to clear.
827→  *   This parameter can be any combination of the following values:
828→  *     @arg FSMC_IT_RisingEdge: Rising edge detection interrupt. 
829→  *     @arg FSMC_IT_Level: Level edge detection interrupt.
830→  *     @arg FSMC_IT_FallingEdge: Falling edge detection interrupt.
831→  * @retval None
832→  */
833→void FSMC_ClearITPendingBit(uint32_t FSMC_Bank, uint32_t FSMC_IT)
834→{
835→  /* Check the parameters */
836→  assert_param(IS_FSMC_IT_BANK(FSMC_Bank));
837→  assert_param(IS_FSMC_IT(FSMC_IT));
838→    
839→  if(FSMC_Bank == FSMC_Bank2_NAND)
840→  {
841→    FSMC_Bank2->SR2 &= ~(FSMC_IT >> 3); 
842→  }  
843→  else if(FSMC_Bank == FSMC_Bank3_NAND)
844→  {
845→    FSMC_Bank3->SR3 &= ~(FSMC_IT >> 3);
846→  }
847→  /* FSMC_Bank4_PCCARD*/
848→  else
849→  {
850→    FSMC_Bank4->SR4 &= ~(FSMC_IT >> 3);
851→  }
852→}
853→
854→/**
855→  * @}
856→  */ 
857→
858→/**
859→  * @}
860→  */
861→
862→/**
863→  * @}
864→  */
865→
866→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/