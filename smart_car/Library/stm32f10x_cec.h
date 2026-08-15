  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_cec.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the CEC firmware 
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
 24→#ifndef __STM32F10x_CEC_H
 25→#define __STM32F10x_CEC_H
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
 38→/** @addtogroup CEC
 39→  * @{
 40→  */
 41→  
 42→
 43→/** @defgroup CEC_Exported_Types
 44→  * @{
 45→  */
 46→   
 47→/** 
 48→  * @brief  CEC Init structure definition  
 49→  */ 
 50→typedef struct
 51→{
 52→  uint16_t CEC_BitTimingMode; /*!< Configures the CEC Bit Timing Error Mode. 
 53→                               This parameter can be a value of @ref CEC_BitTiming_Mode */
 54→  uint16_t CEC_BitPeriodMode; /*!< Configures the CEC Bit Period Error Mode. 
 55→                               This parameter can be a value of @ref CEC_BitPeriod_Mode */
 56→}CEC_InitTypeDef;
 57→
 58→/**
 59→  * @}
 60→  */
 61→
 62→/** @defgroup CEC_Exported_Constants
 63→  * @{
 64→  */ 
 65→  
 66→/** @defgroup CEC_BitTiming_Mode 
 67→  * @{
 68→  */ 
 69→#define CEC_BitTimingStdMode                    ((uint16_t)0x00) /*!< Bit timing error Standard Mode */
 70→#define CEC_BitTimingErrFreeMode                CEC_CFGR_BTEM   /*!< Bit timing error Free Mode */
 71→
 72→#define IS_CEC_BIT_TIMING_ERROR_MODE(MODE) (((MODE) == CEC_BitTimingStdMode) || \
 73→                                            ((MODE) == CEC_BitTimingErrFreeMode))
 74→/**
 75→  * @}
 76→  */
 77→
 78→/** @defgroup CEC_BitPeriod_Mode 
 79→  * @{
 80→  */ 
 81→#define CEC_BitPeriodStdMode                    ((uint16_t)0x00) /*!< Bit period error Standard Mode */
 82→#define CEC_BitPeriodFlexibleMode                CEC_CFGR_BPEM   /*!< Bit period error Flexible Mode */
 83→
 84→#define IS_CEC_BIT_PERIOD_ERROR_MODE(MODE) (((MODE) == CEC_BitPeriodStdMode) || \
 85→                                            ((MODE) == CEC_BitPeriodFlexibleMode))
 86→/**
 87→  * @}
 88→  */ 
 89→
 90→
 91→/** @defgroup CEC_interrupts_definition 
 92→  * @{
 93→  */ 
 94→#define CEC_IT_TERR                              CEC_CSR_TERR
 95→#define CEC_IT_TBTRF                             CEC_CSR_TBTRF
 96→#define CEC_IT_RERR                              CEC_CSR_RERR
 97→#define CEC_IT_RBTF                              CEC_CSR_RBTF
 98→#define IS_CEC_GET_IT(IT) (((IT) == CEC_IT_TERR) || ((IT) == CEC_IT_TBTRF) || \
 99→                           ((IT) == CEC_IT_RERR) || ((IT) == CEC_IT_RBTF))
100→/**
101→  * @}
102→  */ 
103→
104→
105→/** @defgroup CEC_Own_Address 
106→  * @{
107→  */ 
108→#define IS_CEC_ADDRESS(ADDRESS) ((ADDRESS) < 0x10)
109→/**
110→  * @}
111→  */ 
112→
113→/** @defgroup CEC_Prescaler 
114→  * @{
115→  */ 
116→#define IS_CEC_PRESCALER(PRESCALER) ((PRESCALER) <= 0x3FFF)
117→
118→/**
119→  * @}
120→  */
121→
122→/** @defgroup CEC_flags_definition 
123→  * @{
124→  */
125→   
126→/** 
127→  * @brief  ESR register flags  
128→  */ 
129→#define CEC_FLAG_BTE                            ((uint32_t)0x10010000)
130→#define CEC_FLAG_BPE                            ((uint32_t)0x10020000)
131→#define CEC_FLAG_RBTFE                          ((uint32_t)0x10040000)
132→#define CEC_FLAG_SBE                            ((uint32_t)0x10080000)
133→#define CEC_FLAG_ACKE                           ((uint32_t)0x10100000)
134→#define CEC_FLAG_LINE                           ((uint32_t)0x10200000)
135→#define CEC_FLAG_TBTFE                          ((uint32_t)0x10400000)
136→
137→/** 
138→  * @brief  CSR register flags  
139→  */ 
140→#define CEC_FLAG_TEOM                           ((uint32_t)0x00000002)  
141→#define CEC_FLAG_TERR                           ((uint32_t)0x00000004)
142→#define CEC_FLAG_TBTRF                          ((uint32_t)0x00000008)
143→#define CEC_FLAG_RSOM                           ((uint32_t)0x00000010)
144→#define CEC_FLAG_REOM                           ((uint32_t)0x00000020)
145→#define CEC_FLAG_RERR                           ((uint32_t)0x00000040)
146→#define CEC_FLAG_RBTF                           ((uint32_t)0x00000080)
147→
148→#define IS_CEC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFF03) == 0x00) && ((FLAG) != 0x00))
149→                               
150→#define IS_CEC_GET_FLAG(FLAG) (((FLAG) == CEC_FLAG_BTE) || ((FLAG) == CEC_FLAG_BPE) || \
151→                               ((FLAG) == CEC_FLAG_RBTFE) || ((FLAG)== CEC_FLAG_SBE) || \
152→                               ((FLAG) == CEC_FLAG_ACKE) || ((FLAG) == CEC_FLAG_LINE) || \
153→                               ((FLAG) == CEC_FLAG_TBTFE) || ((FLAG) == CEC_FLAG_TEOM) || \
154→                               ((FLAG) == CEC_FLAG_TERR) || ((FLAG) == CEC_FLAG_TBTRF) || \
155→                               ((FLAG) == CEC_FLAG_RSOM) || ((FLAG) == CEC_FLAG_REOM) || \
156→                               ((FLAG) == CEC_FLAG_RERR) || ((FLAG) == CEC_FLAG_RBTF))
157→
158→/**
159→  * @}
160→  */ 
161→
162→/**
163→  * @}
164→  */ 
165→
166→/** @defgroup CEC_Exported_Macros
167→  * @{
168→  */
169→ 
170→/**
171→  * @}
172→  */
173→
174→/** @defgroup CEC_Exported_Functions
175→  * @{
176→  */ 
177→void CEC_DeInit(void);
178→void CEC_Init(CEC_InitTypeDef* CEC_InitStruct);
179→void CEC_Cmd(FunctionalState NewState);
180→void CEC_ITConfig(FunctionalState NewState);
181→void CEC_OwnAddressConfig(uint8_t CEC_OwnAddress);
182→void CEC_SetPrescaler(uint16_t CEC_Prescaler);
183→void CEC_SendDataByte(uint8_t Data);
184→uint8_t CEC_ReceiveDataByte(void);
185→void CEC_StartOfMessage(void);
186→void CEC_EndOfMessageCmd(FunctionalState NewState);
187→FlagStatus CEC_GetFlagStatus(uint32_t CEC_FLAG);
188→void CEC_ClearFlag(uint32_t CEC_FLAG);
189→ITStatus CEC_GetITStatus(uint8_t CEC_IT);
190→void CEC_ClearITPendingBit(uint16_t CEC_IT);
191→
192→#ifdef __cplusplus
193→}
194→#endif
195→
196→#endif /* __STM32F10x_CEC_H */
197→
198→/**
199→  * @}
200→  */ 
201→
202→/**
203→  * @}
204→  */ 
205→
206→/**
207→  * @}
208→  */ 
209→
210→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/