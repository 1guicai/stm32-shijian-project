 1→/**
 2→  ******************************************************************************
 3→  * @file    system_stm32f10x.h
 4→  * @author  MCD Application Team
 5→  * @version V3.5.0
 6→  * @date    11-March-2011
 7→  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer System Header File.
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
22→/** @addtogroup CMSIS
23→  * @{
24→  */
25→
26→/** @addtogroup stm32f10x_system
27→  * @{
28→  */  
29→  
30→/**
31→  * @brief Define to prevent recursive inclusion
32→  */
33→#ifndef __SYSTEM_STM32F10X_H
34→#define __SYSTEM_STM32F10X_H
35→
36→#ifdef __cplusplus
37→ extern "C" {
38→#endif 
39→
40→/** @addtogroup STM32F10x_System_Includes
41→  * @{
42→  */
43→
44→/**
45→  * @}
46→  */
47→
48→
49→/** @addtogroup STM32F10x_System_Exported_types
50→  * @{
51→  */
52→
53→extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */
54→
55→/**
56→  * @}
57→  */
58→
59→/** @addtogroup STM32F10x_System_Exported_Constants
60→  * @{
61→  */
62→
63→/**
64→  * @}
65→  */
66→
67→/** @addtogroup STM32F10x_System_Exported_Macros
68→  * @{
69→  */
70→
71→/**
72→  * @}
73→  */
74→
75→/** @addtogroup STM32F10x_System_Exported_Functions
76→  * @{
77→  */
78→  
79→extern void SystemInit(void);
80→extern void SystemCoreClockUpdate(void);
81→/**
82→  * @}
83→  */
84→
85→#ifdef __cplusplus
86→}
87→#endif
88→
89→#endif /*__SYSTEM_STM32F10X_H */
90→
91→/**
92→  * @}
93→  */
94→  
95→/**
96→  * @}
97→  */  
98→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/