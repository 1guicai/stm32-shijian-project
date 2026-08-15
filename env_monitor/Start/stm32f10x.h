File content truncated due to size limit (50KB). First 50KB included below:

   1→/**
   2→  ******************************************************************************
   3→  * @file    stm32f10x.h
   4→  * @author  MCD Application Team
   5→  * @version V3.5.0
   6→  * @date    11-March-2011
   7→  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File. 
   8→  *          This file contains all the peripheral register's definitions, bits 
   9→  *          definitions and memory mapping for STM32F10x Connectivity line, 
  10→  *          High density, High density value line, Medium density, 
  11→  *          Medium density Value line, Low density, Low density Value line 
  12→  *          and XL-density devices.
  13→  *
  14→  *          The file is the unique include file that the application programmer
  15→  *          is using in the C source code, usually in main.c. This file contains:
  16→  *           - Configuration section that allows to select:
  17→  *              - The device used in the target application
  18→  *              - To use or not the peripheral�s drivers in application code(i.e. 
  19→  *                code will be based on direct access to peripheral�s registers 
  20→  *                rather than drivers API), this option is controlled by 
  21→  *                "#define USE_STDPERIPH_DRIVER"
  22→  *              - To change few application-specific parameters such as the HSE 
  23→  *                crystal frequency
  24→  *           - Data structures and the address mapping for all peripherals
  25→  *           - Peripheral's registers declarations and bits definition
  26→  *           - Macros to access peripheral�s registers hardware
  27→  *
  28→  ******************************************************************************
  29→  * @attention
  30→  *
  31→  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  32→  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  33→  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  34→  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  35→  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  36→  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  37→  *
  38→  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  39→  ******************************************************************************
  40→  */
  41→
  42→/** @addtogroup CMSIS
  43→  * @{
  44→  */
  45→
  46→/** @addtogroup stm32f10x
  47→  * @{
  48→  */
  49→    
  50→#ifndef __STM32F10x_H
  51→#define __STM32F10x_H
  52→
  53→#ifdef __cplusplus
  54→ extern "C" {
  55→#endif 
  56→  
  57→/** @addtogroup Library_configuration_section
  58→  * @{
  59→  */
  60→  
  61→/* Uncomment the line below according to the target STM32 device used in your
  62→   application 
  63→  */
  64→
  65→#if !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD) && !defined (STM32F10X_HD_VL) && !defined (STM32F10X_XL) && !defined (STM32F10X_CL) 
  66→  /* #define STM32F10X_LD */     /*!< STM32F10X_LD: STM32 Low density devices */
  67→  /* #define STM32F10X_LD_VL */  /*!< STM32F10X_LD_VL: STM32 Low density Value Line devices */  
  68→  /* #define STM32F10X_MD */     /*!< STM32F10X_MD: STM32 Medium density devices */
  69→  /* #define STM32F10X_MD_VL */  /*!< STM32F10X_MD_VL: STM32 Medium density Value Line devices */  
  70→  /* #define STM32F10X_HD */     /*!< STM32F10X_HD: STM32 High density devices */
  71→  /* #define STM32F10X_HD_VL */  /*!< STM32F10X_HD_VL: STM32 High density value line devices */  
  72→  /* #define STM32F10X_XL */     /*!< STM32F10X_XL: STM32 XL-density devices */
  73→  /* #define STM32F10X_CL */     /*!< STM32F10X_CL: STM32 Connectivity line devices */
  74→#endif
  75→/*  Tip: To avoid modifying this file each time you need to switch between these
  76→        devices, you can define the device in your toolchain compiler preprocessor.
  77→
  78→ - Low-density devices are STM32F101xx, STM32F102xx and STM32F103xx microcontrollers
  79→   where the Flash memory density ranges between 16 and 32 Kbytes.
  80→ - Low-density value line devices are STM32F100xx microcontrollers where the Flash
  81→   memory density ranges between 16 and 32 Kbytes.
  82→ - Medium-density devices are STM32F101xx, STM32F102xx and STM32F103xx microcontrollers
  83→   where the Flash memory density ranges between 64 and 128 Kbytes.
  84→ - Medium-density value line devices are STM32F100xx microcontrollers where the 
  85→   Flash memory density ranges between 64 and 128 Kbytes.   
  86→ - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
  87→   the Flash memory density ranges between 256 and 512 Kbytes.
  88→ - High-density value line devices are STM32F100xx microcontrollers where the 
  89→   Flash memory density ranges between 256 and 512 Kbytes.   
  90→ - XL-density devices are STM32F101xx and STM32F103xx microcontrollers where
  91→   the Flash memory density ranges between 512 and 1024 Kbytes.
  92→ - Connectivity line devices are STM32F105xx and STM32F107xx microcontrollers.
  93→  */
  94→
  95→#if !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD) && !defined (STM32F10X_HD_VL) && !defined (STM32F10X_XL) && !defined (STM32F10X_CL)
  96→ #error "Please select first the target STM32F10x device used in your application (in stm32f10x.h file)"
  97→#endif
  98→
  99→#if !defined  USE_STDPERIPH_DRIVER
 100→/**
 101→ * @brief Comment the line below if you will not use the peripherals drivers.
 102→   In this case, these drivers will not be included and the application code will 
 103→   be based on direct access to peripherals registers 
 104→   */
 105→  /*#define USE_STDPERIPH_DRIVER*/
 106→#endif
 107→
 108→/**
 109→ * @brief In the following line adjust the value of External High Speed oscillator (HSE)
 110→   used in your application 
 111→   
 112→   Tip: To avoid modifying this file each time you need to use different HSE, you
 113→        can define the HSE value in your toolchain compiler preprocessor.
 114→  */           
 115→#if !defined  HSE_VALUE
 116→ #ifdef STM32F10X_CL   
 117→  #define HSE_VALUE    ((uint32_t)25000000) /*!< Value of the External oscillator in Hz */
 118→ #else 
 119→  #define HSE_VALUE    ((uint32_t)8000000) /*!< Value of the External oscillator in Hz */
 120→ #endif /* STM32F10X_CL */
 121→#endif /* HSE_VALUE */
 122→
 123→
 124→/**
 125→ * @brief In the following line adjust the External High Speed oscillator (HSE) Startup 
 126→   Timeout value 
 127→   */
 128→#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x0500) /*!< Time out for HSE start up */
 129→
 130→#define HSI_VALUE    ((uint32_t)8000000) /*!< Value of the Internal oscillator in Hz*/
 131→
 132→/**
 133→ * @brief STM32F10x Standard Peripheral Library version number
 134→   */
 135→#define __STM32F10X_STDPERIPH_VERSION_MAIN   (0x03) /*!< [31:24] main version */                                  
 136→#define __STM32F10X_STDPERIPH_VERSION_SUB1   (0x05) /*!< [23:16] sub1 version */
 137→#define __STM32F10X_STDPERIPH_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
 138→#define __STM32F10X_STDPERIPH_VERSION_RC     (0x00) /*!< [7:0]  release candidate */ 
 139→#define __STM32F10X_STDPERIPH_VERSION       ( (__STM32F10X_STDPERIPH_VERSION_MAIN << 24)\
 140→                                             |(__STM32F10X_STDPERIPH_VERSION_SUB1 << 16)\
 141→                                             |(__STM32F10X_STDPERIPH_VERSION_SUB2 << 8)\
 142→                                             |(__STM32F10X_STDPERIPH_VERSION_RC))
 143→
 144→/**
 145→  * @}
 146→  */
 147→
 148→/** @addtogroup Configuration_section_for_CMSIS
 149→  * @{
 150→  */
 151→
 152→/**
 153→ * @brief Configuration of the Cortex-M3 Processor and Core Peripherals 
 154→ */
 155→#ifdef STM32F10X_XL
 156→ #define __MPU_PRESENT             1 /*!< STM32 XL-density devices provide an MPU */
 157→#else
 158→ #define __MPU_PRESENT             0 /*!< Other STM32 devices does not provide an MPU */
 159→#endif /* STM32F10X_XL */
 160→#define __NVIC_PRIO_BITS          4 /*!< STM32 uses 4 Bits for the Priority Levels    */
 161→#define __Vendor_SysTickConfig    0 /*!< Set to 1 if different SysTick Config is used */
 162→
 163→/**
 164→ * @brief STM32F10x Interrupt Number Definition, according to the selected device 
 165→ *        in @ref Library_configuration_section 
 166→ */
 167→typedef enum IRQn
 168→{
 169→/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
 170→  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
 171→  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
 172→  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
 173→  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
 174→  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
 175→  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
 176→  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
 177→  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */
 178→
 179→/******  STM32 specific Interrupt Numbers *********************************************************/
 180→  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
 181→  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
 182→  TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                     */
 183→  RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                 */
 184→  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
 185→  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                 */
 186→  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                 */
 187→  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                 */
 188→  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                 */
 189→  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                 */
 190→  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                 */
 191→  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
 192→  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
 193→  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
 194→  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
 195→  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
 196→  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
 197→  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
 198→
 199→#ifdef STM32F10X_LD
 200→  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
 201→  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
 202→  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
 203→  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
 204→  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
 205→  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 206→  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
 207→  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
 208→  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
 209→  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 210→  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 211→  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 212→  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 213→  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 214→  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 215→  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 216→  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 217→  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 218→  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 219→  USBWakeUp_IRQn              = 42      /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */    
 220→#endif /* STM32F10X_LD */  
 221→
 222→#ifdef STM32F10X_LD_VL
 223→  ADC1_IRQn                   = 18,     /*!< ADC1 global Interrupt                                */
 224→  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 225→  TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 Break and TIM15 Interrupts                      */
 226→  TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 Update and TIM16 Interrupts                     */
 227→  TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt     */
 228→  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 229→  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 230→  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 231→  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 232→  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 233→  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 234→  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 235→  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 236→  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 237→  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 238→  CEC_IRQn                    = 42,     /*!< HDMI-CEC Interrupt                                   */
 239→  TIM6_DAC_IRQn               = 54,     /*!< TIM6 and DAC underrun Interrupt                      */
 240→  TIM7_IRQn                   = 55      /*!< TIM7 Interrupt                                       */       
 241→#endif /* STM32F10X_LD_VL */
 242→
 243→#ifdef STM32F10X_MD
 244→  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
 245→  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
 246→  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
 247→  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
 248→  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
 249→  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 250→  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
 251→  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
 252→  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
 253→  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 254→  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 255→  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 256→  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
 257→  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 258→  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 259→  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
 260→  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
 261→  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 262→  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
 263→  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 264→  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 265→  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
 266→  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 267→  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 268→  USBWakeUp_IRQn              = 42      /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */  
 269→#endif /* STM32F10X_MD */  
 270→
 271→#ifdef STM32F10X_MD_VL
 272→  ADC1_IRQn                   = 18,     /*!< ADC1 global Interrupt                                */
 273→  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 274→  TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 Break and TIM15 Interrupts                      */
 275→  TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 Update and TIM16 Interrupts                     */
 276→  TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt     */
 277→  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 278→  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 279→  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 280→  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
 281→  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 282→  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 283→  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
 284→  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
 285→  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 286→  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
 287→  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 288→  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 289→  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
 290→  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 291→  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 292→  CEC_IRQn                    = 42,     /*!< HDMI-CEC Interrupt                                   */
 293→  TIM6_DAC_IRQn               = 54,     /*!< TIM6 and DAC underrun Interrupt                      */
 294→  TIM7_IRQn                   = 55      /*!< TIM7 Interrupt                                       */       
 295→#endif /* STM32F10X_MD_VL */
 296→
 297→#ifdef STM32F10X_HD
 298→  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
 299→  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
 300→  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
 301→  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
 302→  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
 303→  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 304→  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
 305→  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
 306→  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
 307→  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 308→  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 309→  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 310→  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
 311→  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 312→  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 313→  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
 314→  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
 315→  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 316→  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
 317→  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 318→  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 319→  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
 320→  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 321→  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 322→  USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
 323→  TIM8_BRK_IRQn               = 43,     /*!< TIM8 Break Interrupt                                 */
 324→  TIM8_UP_IRQn                = 44,     /*!< TIM8 Update Interrupt                                */
 325→  TIM8_TRG_COM_IRQn           = 45,     /*!< TIM8 Trigger and Commutation Interrupt               */
 326→  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                       */
 327→  ADC3_IRQn                   = 47,     /*!< ADC3 global Interrupt                                */
 328→  FSMC_IRQn                   = 48,     /*!< FSMC global Interrupt                                */
 329→  SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                */
 330→  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                */
 331→  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
 332→  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
 333→  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */
 334→  TIM6_IRQn                   = 54,     /*!< TIM6 global Interrupt                                */
 335→  TIM7_IRQn                   = 55,     /*!< TIM7 global Interrupt                                */
 336→  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
 337→  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
 338→  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
 339→  DMA2_Channel4_5_IRQn        = 59      /*!< DMA2 Channel 4 and Channel 5 global Interrupt        */
 340→#endif /* STM32F10X_HD */  
 341→
 342→#ifdef STM32F10X_HD_VL
 343→  ADC1_IRQn                   = 18,     /*!< ADC1 global Interrupt                                */
 344→  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 345→  TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 Break and TIM15 Interrupts                      */
 346→  TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 Update and TIM16 Interrupts                     */
 347→  TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt     */
 348→  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 349→  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 350→  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 351→  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
 352→  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 353→  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 354→  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
 355→  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
 356→  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 357→  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
 358→  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 359→  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 360→  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
 361→  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 362→  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 363→  CEC_IRQn                    = 42,     /*!< HDMI-CEC Interrupt                                   */
 364→  TIM12_IRQn                  = 43,     /*!< TIM12 global Interrupt                               */
 365→  TIM13_IRQn                  = 44,     /*!< TIM13 global Interrupt                               */
 366→  TIM14_IRQn                  = 45,     /*!< TIM14 global Interrupt                               */
 367→  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                */
 368→  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
 369→  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
 370→  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */  
 371→  TIM6_DAC_IRQn               = 54,     /*!< TIM6 and DAC underrun Interrupt                      */
 372→  TIM7_IRQn                   = 55,     /*!< TIM7 Interrupt                                       */  
 373→  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
 374→  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
 375→  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
 376→  DMA2_Channel4_5_IRQn        = 59,     /*!< DMA2 Channel 4 and Channel 5 global Interrupt        */
 377→  DMA2_Channel5_IRQn          = 60      /*!< DMA2 Channel 5 global Interrupt (DMA2 Channel 5 is 
 378→                                             mapped at position 60 only if the MISC_REMAP bit in 
 379→                                             the AFIO_MAPR2 register is set)                      */       
 380→#endif /* STM32F10X_HD_VL */
 381→
 382→#ifdef STM32F10X_XL
 383→  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
 384→  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
 385→  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
 386→  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
 387→  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
 388→  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 389→  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break Interrupt and TIM9 global Interrupt       */
 390→  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global Interrupt     */
 391→  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
 392→  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 393→  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 394→  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 395→  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
 396→  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 397→  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 398→  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
 399→  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
 400→  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 401→  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
 402→  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 403→  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 404→  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
 405→  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 406→  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 407→  USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
 408→  TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global Interrupt      */
 409→  TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global Interrupt     */
 410→  TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
 411→  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                       */
 412→  ADC3_IRQn                   = 47,     /*!< ADC3 global Interrupt                                */
 413→  FSMC_IRQn                   = 48,     /*!< FSMC global Interrupt                                */
 414→  SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                */
 415→  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                */
 416→  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
 417→  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
 418→  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */
 419→  TIM6_IRQn                   = 54,     /*!< TIM6 global Interrupt                                */
 420→  TIM7_IRQn                   = 55,     /*!< TIM7 global Interrupt                                */
 421→  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
 422→  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
 423→  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
 424→  DMA2_Channel4_5_IRQn        = 59      /*!< DMA2 Channel 4 and Channel 5 global Interrupt        */
 425→#endif /* STM32F10X_XL */  
 426→
 427→#ifdef STM32F10X_CL
 428→  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
 429→  CAN1_TX_IRQn                = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
 430→  CAN1_RX0_IRQn               = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
 431→  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
 432→  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
 433→  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 434→  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
 435→  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
 436→  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
 437→  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 438→  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 439→  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 440→  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
 441→  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 442→  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 443→  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
 444→  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
 445→  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 446→  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
 447→  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 448→  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 449→  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
 450→  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 451→  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 452→  OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS WakeUp from suspend through EXTI Line Interrupt */
 453→  TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                */
 454→  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                */
 455→  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                               */
 456→  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                               */
 457→  TIM6_IRQn                   = 54,     /*!< TIM6 global Interrupt                                */
 458→  TIM7_IRQn                   = 55,     /*!< TIM7 global Interrupt                                */
 459→  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                      */
 460→  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                      */
 461→  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                      */
 462→  DMA2_Channel4_IRQn          = 59,     /*!< DMA2 Channel 4 global Interrupt                      */
 463→  DMA2_Channel5_IRQn          = 60,     /*!< DMA2 Channel 5 global Interrupt                      */
 464→  ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                            */
 465→  ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt          */
 466→  CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                    */
 467→  CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                   */
 468→  CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                   */
 469→  CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                   */
 470→  OTG_FS_IRQn                 = 67      /*!< USB OTG FS global Interrupt                          */
 471→#endif /* STM32F10X_CL */     
 472→} IRQn_Type;
 473→
 474→/**
 475→  * @}
 476→  */
 477→
 478→#include "core_cm3.h"
 479→#include "system_stm32f10x.h"
 480→#include <stdint.h>
 481→
 482→/** @addtogroup Exported_types
 483→  * @{
 484→  */  
 485→
 486→/*!< STM32F10x Standard Peripheral Library old types (maintained for legacy purpose) */
 487→typedef int32_t  s32;
 488→typedef int16_t s16;
 489→typedef int8_t  s8;
 490→
 491→typedef const int32_t sc32;  /*!< Read Only */
 492→typedef const int16_t sc16;  /*!< Read Only */
 493→typedef const int8_t sc8;   /*!< Read Only */
 494→
 495→typedef __IO int32_t  vs32;
 496→typedef __IO int16_t  vs16;
 497→typedef __IO int8_t   vs8;
 498→
 499→typedef __I int32_t vsc32;  /*!< Read Only */
 500→typedef __I int16_t vsc16;  /*!< Read Only */
 501→typedef __I int8_t vsc8;   /*!< Read Only */
 502→
 503→typedef uint32_t  u32;
 504→typedef uint16_t u16;
 505→typedef uint8_t  u8;
 506→
 507→typedef const uint32_t uc32;  /*!< Read Only */
 508→typedef const uint16_t uc16;  /*!< Read Only */
 509→typedef const uint8_t uc8;   /*!< Read Only */
 510→
 511→typedef __IO uint32_t  vu32;
 512→typedef __IO uint16_t vu16;
 513→typedef __IO uint8_t  vu8;
 514→
 515→typedef __I uint32_t vuc32;  /*!< Read Only */
 516→typedef __I uint16_t vuc16;  /*!< Read Only */
 517→typedef __I uint8_t vuc8;   /*!< Read Only */
 518→
 519→typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
 520→
 521→typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
 522→#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))
 523→
 524→typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;
 525→
 526→/*!< STM32F10x Standard Peripheral Library old definitions (maintained for legacy purpose) */
 527→#define HSEStartUp_TimeOut   HSE_STARTUP_TIMEOUT
 528→#define HSE_Value            HSE_VALUE
 529→#define HSI_Value            HSI_VALUE
 530→/**
 531→  * @}
 532→  */
 533→
 534→/** @addtogroup Peripheral_registers_structures
 535→  * @{
 536→  */   
 537→
 538→/** 
 539→  * @brief Analog to Digital Converter  
 540→  */
 541→
 542→typedef struct
 543→{
 544→  __IO uint32_t SR;
 545→  __IO uint32_t CR1;
 546→  __IO uint32_t CR2;
 547→  __IO uint32_t SMPR1;
 548→  __IO uint32_t SMPR2;
 549→  __IO uint32_t JOFR1;
 550→  __IO uint32_t JOFR2;
 551→  __IO uint32_t JOFR3;
 552→  __IO uint32_t JOFR4;
 553→  __IO uint32_t HTR;
 554→  __IO uint32_t LTR;
 555→  __IO uint32_t SQR1;
 556→  __IO uint32_t SQR2;
 557→  __IO uint32_t SQR3;
 558→  __IO uint32_t JSQR;
 559→  __IO uint32_t JDR1;
 560→  __IO uint32_t JDR2;
 561→  __IO uint32_t JDR3;
 562→  __IO uint32_t JDR4;
 563→  __IO uint32_t DR;
 564→} ADC_TypeDef;
 565→
 566→/** 
 567→  * @brief Backup Registers  
 568→  */
 569→
 570→typedef struct
 571→{
 572→  uint32_t  RESERVED0;
 573→  __IO uint16_t DR1;
 574→  uint16_t  RESERVED1;
 575→  __IO uint16_t DR2;
 576→  uint16_t  RESERVED2;
 577→  __IO uint16_t DR3;
 578→  uint16_t  RESERVED3;
 579→  __IO uint16_t DR4;
 580→  uint16_t  RESERVED4;
 581→  __IO uint16_t DR5;
 582→  uint16_t  RESERVED5;
 583→  __IO uint16_t DR6;
 584→  uint16_t  RESERVED6;
 585→  __IO uint16_t DR7;
 586→  uint16_t  RESERVED7;
 587→  __IO uint16_t DR8;
 588→  uint16_t  RESERVED8;
 589→  __IO uint16_t DR9;
 590→  uint16_t  RESERVED9;
 591→  __IO uint16_t DR10;
 592→  uint16_t  RESERVED10; 
 593→  __IO uint16_t RTCCR;
 594→  uint16_t  RESERVED11;
 595→  __IO uint16_t CR;
 596→  uint16_t  RESERVED12;
 597→  __IO uint16_t CSR;
 598→  uint16_t  RESERVED13[5];
 599→  __IO uint16_t DR11;
 600→  uint16_t  RESERVED14;
 601→  __IO uint16_t DR12;
 602→  uint16_t  RESERVED15;
 603→  __IO uint16_t DR13;
 604→  uint16_t  RESERVED16;
 605→  __IO uint16_t DR14;
 606→  uint16_t  RESERVED17;
 607→  __IO uint16_t DR15;
 608→  uint16_t  RESERVED18;
 609→  __IO uint16_t DR16;
 610→  uint16_t  RESERVED19;
 611→  __IO uint16_t DR17;
 612→  uint16_t  RESERVED20;
 613→  __IO uint16_t DR18;
 614→  uint16_t  RESERVED21;
 615→  __IO uint16_t DR19;
 616→  uint16_t  RESERVED22;
 617→  __IO uint16_t DR20;
 618→  uint16_t  RESERVED23;
 619→  __IO uint16_t DR21;
 620→  uint16_t  RESERVED24;
 621→  __IO uint16_t DR22;
 622→  uint16_t  RESERVED25;
 623→  __IO uint16_t DR23;
 624→  uint16_t  RESERVED26;
 625→  __IO uint16_t DR24;
 626→  uint16_t  RESERVED27;
 627→  __IO uint16_t DR25;
 628→  uint16_t  RESERVED28;
 629→  __IO uint16_t DR26;
 630→  uint16_t  RESERVED29;
 631→  __IO uint16_t DR27;
 632→  uint16_t  RESERVED30;
 633→  __IO uint16_t DR28;
 634→  uint16_t  RESERVED31;
 635→  __IO uint16_t DR29;
 636→  uint16_t  RESERVED32;
 637→  __IO uint16_t DR30;
 638→  uint16_t  RESERVED33; 
 639→  __IO uint16_t DR31;
 640→  uint16_t  RESERVED34;
 641→  __IO uint16_t DR32;
 642→  uint16_t  RESERVED35;
 643→  __IO uint16_t DR33;
 644→  uint16_t  RESERVED36;
 645→  __IO uint16_t DR34;
 646→  uint16_t  RESERVED37;
 647→  __IO uint16_t DR35;
 648→  uint16_t  RESERVED38;
 649→  __IO uint16_t DR36;
 650→  uint16_t  RESERVED39;
 651→  __IO uint16_t DR37;
 652→  uint16_t  RESERVED40;
 653→  __IO uint16_t DR38;
 654→  uint16_t  RESERVED41;
 655→  __IO uint16_t DR39;
 656→  uint16_t  RESERVED42;
 657→  __IO uint16_t DR40;
 658→  uint16_t  RESERVED43;
 659→  __IO uint16_t DR41;
 660→  uint16_t  RESERVED44;
 661→  __IO uint16_t DR42;
 662→  uint16_t  RESERVED45;    
 663→} BKP_TypeDef;
 664→  
 665→/** 
 666→  * @brief Controller Area Network TxMailBox 
 667→  */
 668→
 669→typedef struct
 670→{
 671→  __IO uint32_t TIR;
 672→  __IO uint32_t TDTR;
 673→  __IO uint32_t TDLR;
 674→  __IO uint32_t TDHR;
 675→} CAN_TxMailBox_TypeDef;
 676→
 677→/** 
 678→  * @brief Controller Area Network FIFOMailBox 
 679→  */
 680→  
 681→typedef struct
 682→{
 683→  __IO uint32_t RIR;
 684→  __IO uint32_t RDTR;
 685→  __IO uint32_t RDLR;
 686→  __IO uint32_t RDHR;
 687→} CAN_FIFOMailBox_TypeDef;
 688→
 689→/** 
 690→  * @brief Controller Area Network FilterRegister 
 691→  */
 692→  
 693→typedef struct
 694→{
 695→  __IO uint32_t FR1;
 696→  __IO uint32_t FR2;
 697→} CAN_FilterRegister_TypeDef;
 698→
 699→/** 
 700→  * @brief Controller Area Network 
 701→  */
 702→  
 703→typedef struct
 704→{
 705→  __IO uint32_t MCR;
 706→  __IO uint32_t MSR;
 707→  __IO uint32_t TSR;
 708→  __IO uint32_t RF0R;
 709→  __IO uint32_t RF1R;
 710→  __IO uint32_t IER;
 711→  __IO uint32_t ESR;
 712→  __IO uint32_t BTR;
 713→  uint32_t  RESERVED0[88];
 714→  CAN_TxMailBox_TypeDef sTxMailBox[3];
 715→  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
 716→  uint32_t  RESERVED1[12];
 717→  __IO uint32_t FMR;
 718→  __IO uint32_t FM1R;
 719→  uint32_t  RESERVED2;
 720→  __IO uint32_t FS1R;
 721→  uint32_t  RESERVED3;
 722→  __IO uint32_t FFA1R;
 723→  uint32_t  RESERVED4;
 724→  __IO uint32_t FA1R;
 725→  uint32_t  RESERVED5[8];
 726→#ifndef STM32F10X_CL
 727→  CAN_FilterRegister_TypeDef sFilterRegister[14];
 728→#else
 729→  CAN_FilterRegister_TypeDef sFilterRegister[28];
 730→#endif /* STM32F10X_CL */  
 731→} CAN_TypeDef;
 732→
 733→/** 
 734→  * @brief Consumer Electronics Control (CEC)
 735→  */
 736→typedef struct
 737→{
 738→  __IO uint32_t CFGR;
 739→  __IO uint32_t OAR;
 740→  __IO uint32_t PRES;
 741→  __IO uint32_t ESR;
 742→  __IO uint32_t CSR;
 743→  __IO uint32_t TXD;
 744→  __IO uint32_t RXD;  
 745→} CEC_TypeDef;
 746→
 747→/** 
 748→  * @brief CRC calculation unit 
 749→  */
 750→
 751→typedef struct
 752→{
 753→  __IO uint32_t DR;
 754→  __IO uint8_t  IDR;
 755→  uint8_t   RESERVED0;
 756→  uint16_t  RESERVED1;
 757→  __IO uint32_t CR;
 758→} CRC_TypeDef;
 759→
 760→/** 
 761→  * @brief Digital to Analog Converter
 762→  */
 763→
 764→typedef struct
 765→{
 766→  __IO uint32_t CR;
 767→  __IO uint32_t SWTRIGR;
 768→  __IO uint32_t DHR12R1;
 769→  __IO uint32_t DHR12L1;
 770→  __IO uint32_t DHR8R1;
 771→  __IO uint32_t DHR12R2;
 772→  __IO uint32_t DHR12L2;
 773→  __IO uint32_t DHR8R2;
 774→  __IO uint32_t DHR12RD;
 775→  __IO uint32_t DHR12LD;
 776→  __IO uint32_t DHR8RD;
 777→  __IO uint32_t DOR1;
 778→  __IO uint32_t DOR2;
 779→#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
 780→  __IO uint32_t SR;
 781→#endif
 782→} DAC_TypeDef;
 783→
 784→/** 
 785→  * @brief Debug MCU
 786→  */
 787→
 788→typedef struct
 789→{
 790→  __IO uint32_t IDCODE;
 791→  __IO uint32_t CR;	
 792→}DBGMCU_TypeDef;
 793→
 794→/** 
 795→  * @brief DMA Controller
 796→  */
 797→
 798→typedef struct
 799→{
 800→  __IO uint32_t CCR;
 801→  __IO uint32_t CNDTR;
 802→  __IO uint32_t CPAR;
 803→  __IO uint32_t CMAR;
 804→} DMA_Channel_TypeDef;
 805→
 806→typedef struct
 807→{
 808→  __IO uint32_t ISR;
 809→  __IO uint32_t IFCR;
 810→} DMA_TypeDef;
 811→
 812→/** 
 813→  * @brief Ethernet MAC
 814→  */
 815→
 816→typedef struct
 817→{
 818→  __IO uint32_t MACCR;
 819→  __IO uint32_t MACFFR;
 820→  __IO uint32_t MACHTHR;
 821→  __IO uint32_t MACHTLR;
 822→  __IO uint32_t MACMIIAR;
 823→  __IO uint32_t MACMIIDR;
 824→  __IO uint32_t MACFCR;
 825→  __IO uint32_t MACVLANTR;             /*    8 */
 826→       uint32_t RESERVED0[2];
 827→  __IO uint32_t MACRWUFFR;             /*   11 */
 828→  __IO uint32_t MACPMTCSR;
 829→       uint32_t RESERVED1[2];
 830→  __IO uint32_t MACSR;                 /*   15 */
 831→  __IO uint32_t MACIMR;
 832→  __IO uint32_t MACA0HR;
 833→  __IO uint32_t MACA0LR;
 834→  __IO uint32_t MACA1HR;
 835→  __IO uint32_t MACA1LR;
 836→  __IO uint32_t MACA2HR;
 837→  __IO uint32_t MACA2LR;
 838→  __IO uint32_t MACA3HR;
 839→  __IO uint32_t MACA3LR;               /*   24 */
 840→       uint32_t RESERVED2[40];
 841→  __IO uint32_t MMCCR;                 /*   65 */
 842→  __IO uint32_t MMCRIR;
 843→  __IO uint32_t MMCTIR;
 844→  __IO uint32_t MMCRIMR;
 845→  __IO uint32_t MMCTIMR;               /*   69 */
 846→       uint32_t RESERVED3[14];
 847→  __IO uint32_t MMCTGFSCCR;            /*   84 */
 848→  __IO uint32_t MMCTGFMSCCR;
 849→       uint32_t RESERVED4[5];
 850→  __IO uint32_t MMCTGFCR;
 851→       uint32_t RESERVED5[10];
 852→  __IO uint32_t MMCRFCECR;
 853→  __IO uint32_t MMCRFAECR;
 854→       uint32_t RESERVED6[10];
 855→  __IO uint32_t MMCRGUFCR;
 856→       uint32_t RESERVED7[334];
 857→  __IO uint32_t PTPTSCR;
 858→  __IO uint32_t PTPSSIR;
 859→  __IO uint32_t PTPTSHR;
 860→  __IO uint32_t PTPTSLR;
 861→  __IO uint32_t PTPTSHUR;
 862→  __IO uint32_t PTPTSLUR;
 863→  __IO uint32_t PTPTSAR;
 864→  __IO uint32_t PTPTTHR;
 865→  __IO uint32_t PTPTTLR;
 866→       uint32_t RESERVED8[567];
 867→  __IO uint32_t DMABMR;
 868→  __IO uint32_t DMATPDR;
 869→  __IO uint32_t DMARPDR;
 870→  __IO uint32_t DMARDLAR;
 871→  __IO uint32_t DMATDLAR;
 872→  __IO uint32_t DMASR;
 873→  __IO uint32_t DMAOMR;
 874→  __IO uint32_t DMAIER;
 875→  __IO uint32_t DMAMFBOCR;
 876→       uint32_t RESERVED9[9];
 877→  __IO uint32_t DMACHTDR;
 878→  __IO uint32_t DMACHRDR;
 879→  __IO uint32_t DMACHTBAR;
 880→  __IO uint32_t DMACHRBAR;
 881→} ETH_TypeDef;
 882→
 883→/** 
 884→  * @brief External Interrupt/Event Controller
 885→  */
 886→
 887→typedef struct
 888→{
 889→  __IO uint32_t IMR;
 890→  __IO uint32_t EMR;
 891→  __IO uint32_t RTSR;
 892→  __IO uint32_t FTSR;
 893→  __IO uint32_t SWIER;
 894→  __IO uint32_t PR;
 895→} EXTI_TypeDef;
 896→
 897→/** 
 898→  * @brief FLASH Registers
 899→  */
 900→
 901→typedef struct
 902→{
 903→  __IO uint32_t ACR;
 904→  __IO uint32_t KEYR;
 905→  __IO uint32_t OPTKEYR;
 906→  __IO uint32_t SR;
 907→  __IO uint32_t CR;
 908→  __IO uint32_t AR;
 909→  __IO uint32_t RESERVED;
 910→  __IO uint32_t OBR;
 911→  __IO uint32_t WRPR;
 912→#ifdef STM32F10X_XL
 913→  uint32_t RESERVED1[8]; 
 914→  __IO uint32_t KEYR2;
 915→  uint32_t RESERVED2;   
 916→  __IO uint32_t SR2;
 917→  __IO uint32_t CR2;
 918→  __IO uint32_t AR2; 
 919→#endif /* STM32F10X_XL */  
 920→} FLASH_TypeDef;
 921→
 922→/** 
 923→  * @brief Option Bytes Registers
 924→  */
 925→  
 926→typedef struct
 927→{
 928→  __IO uint16_t RDP;
 929→  __IO uint16_t USER;
 930→  __IO uint16_t Data0;
 931→  __IO uint16_t Data1;
 932→  __IO uint16_t WRP0;
 933→  __IO uint16_t WRP1;
 934→  __IO uint16_t WRP2;
 935→  __IO uint16_t WRP3;
 936→} OB_TypeDef;
 937→
 938→/** 
 939→  * @brief Flexible Static Memory Controller
 940→  */
 941→
 942→typedef struct
 943→{
 944→  __IO uint32_t BTCR[8];   
 945→} FSMC_Bank1_TypeDef; 
 946→
 947→/** 
 948→  * @brief Flexible Static Memory Controller Bank1E
 949→  */
 950→  
 951→typedef struct
 952→{
 953→  __IO uint32_t BWTR[7];
 954→} FSMC_Bank1E_TypeDef;
 955→
 956→/** 
 957→  * @brief Flexible Static Memory Controller Bank2
 958→  */
 959→  
 960→typedef struct
 961→{
 962→  __IO uint32_t PCR2;
 963→  __IO uint32_t SR2;
 964→  __IO uint32_t PMEM2;
 965→  __IO uint32_t PATT2;
 966→  uint32_t  RESERVED0;   
 967→  __IO uint32_t ECCR2; 
 968→} FSMC_Bank2_TypeDef;  
 969→
 970→/** 
 971→  * @brief Flexible Static Memory Controller Bank3
 972→  */
 973→  
 974→typedef struct
 975→{
 976→  __IO uint32_t PCR3;
 977→  __IO uint32_t SR3;
 978→  __IO uint32_t PMEM3;
 979→  __IO uint32_t PATT3;
 980→  uint32_t  RESERVED0;   
 981→  __IO uint32_t ECCR3; 
 982→} FSMC_Bank3_TypeDef; 
 983→
 984→/** 
 985→  * @brief Flexible Static Memory Controller Bank4
 986→  */
 987→  
 988→typedef struct
 989→{
 990→  __IO uint32_t PCR4;
 991→  __IO uint32_t SR4;
 992→  __IO uint32_t PMEM4;
 993→  __IO uint32_t PATT4;
 994→  __IO uint32_t PIO4; 
 995→} FSMC_Bank4_TypeDef; 
 996→
 997→/** 
 998→  * @brief General Purpose I/O
 999→  */
1000→
1001→typedef struct
1002→{
1003→  __IO uint32_t CRL;
1004→  __IO uint32_t CRH;
1005→  __IO uint32_t IDR;
1006→  __IO uint32_t ODR;
1007→  __IO uint32_t BSRR;
1008→  __IO uint32_t BRR;
1009→  __IO uint32_t LCKR;
1010→} GPIO_TypeDef;
1011→
1012→/** 
1013→  * @brief Alternate Function I/O
1014→  */
1015→
1016→typedef struct
1017→{
1018→  __IO uint32_t EVCR;
1019→  __IO uint32_t MAPR;
1020→  __IO uint32_t EXTICR[4];
1021→  uint32_t RESERVED0;
1022→  __IO uint32_t MAPR2;  
1023→} AFIO_TypeDef;
1024→/** 
1025→  * @brief Inter Integrated Circuit Interface
1026→  */
1027→
1028→typedef struct
1029→{
1030→  __IO uint16_t CR1;
1031→  uint16_t  RESERVED0;
1032→  __IO uint16_t CR2;
1033→  uint16_t  RESERVED1;
1034→  __IO uint16_t OAR1;
1035→  uint16_t  RESERVED2;
1036→  __IO uint16_t OAR2;
1037→  uint16_t  RESERVED3;
1038→  __IO uint16_t DR;
1039→  uint16_t  RESERVED4;
1040→  __IO uint16_t SR1;
1041→  uint16_t  RESERVED5;
1042→  __IO uint16_t SR2;
1043→  uint16_t  RESERVED6;
1044→  __IO uint16_t CCR;
1045→  uint16_t  RESERVED7;
1046→  __IO uint16_t TRISE;
1047→  uint16_t  RESERVED8;
1048→} I2C_TypeDef;
1049→
1050→/** 
1051→  * @brief Independent WATCHDOG
1052→  */
1053→
1054→typedef struct
1055→{
1056→  __IO uint32_t KR;
1057→  __IO uint32_t PR;
1058→  __IO uint32_t RLR;
1059→  __IO uint32_t SR;
1060→} IWDG_TypeDef;
1061→
1062→/** 
1063→  * @brief Power Control
1064→  */
1065→
1066→typedef struct
1067→{
1068→  __IO uint32_t CR;
1069→  __IO uint32_t CSR;
1070→} PWR_TypeDef;
1071→
1072→/** 
1073→  * @brief Reset and Clock Control
1074→  */
1075→
1076→typedef struct
1077→{
1078→  __IO uint32_t CR;
1079→  __IO uint32_t CFGR;
1080→  __IO uint32_t CIR;
1081→  __IO uint32_t APB2RSTR;
1082→  __IO uint32_t APB1RSTR;
1083→  __IO uint32_t AHBENR;
1084→  __IO uint32_t APB2ENR;
1085→  __IO uint32_t APB1ENR;
1086→  __IO uint32_t BDCR;
1087→  __IO uint32_t CSR;
1088→
1089→#ifdef STM32F10X_CL  
1090→  __IO uint32_t AHBRSTR;
1091→  __IO uint32_t CFGR2;
1092→#endif /* STM32F10X_CL */ 
1093→
1094→#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)   
1095→  uint32_t RESERVED0;
1096→  __IO uint32_t CFGR2;
1097→#endif /* STM32F10X_LD_VL || STM32F10X_MD_VL || STM32F10X_HD_VL */ 
1098→} RCC_TypeDef;
1099→
1100→/** 
1101→  * @brief Real-Time Clock
1102→  */
1103→
1104→typedef struct
1105→{
1106→  __IO uint16_t CRH;
1107→  uint16_t  RESERVED0;
1108→  __IO uint16_t CRL;
1109→  uint16_t  RESERVED1;
1110→  __IO uint16_t PRLH;
1111→  uint16_t  RESERVED2;
1112→  __IO uint16_t PRLL;
1113→  uint16_t  RESERVED3;
1114→  __IO uint16_t DIVH;
1115→  uint16_t  RESERVED4;
1116→  __IO uint16_t DIVL;
1117→  uint16_t  RESERVED5;
1118→  __IO uint16_t CNTH;
1119→  uint16_t  RESERVED6;
1120→  __IO uint16_t CNTL;
1121→  uint16_t  RESERVED7;
1122→  __IO uint16_t ALRH;
1123→  uint16_t  RESERVED8;
1124→  __IO uint16_t ALRL;
1125→  uint16_t  RESERVED9;
1126→} RTC_TypeDef;
1127→
1128→/** 
1129→  * @brief SD host Interface
1130→  */
1131→
1132→typedef struct
1133→{
1134→  __IO uint32_t POWER;
1135→  __IO uint32_t CLKCR;
1136→  __IO uint32_t ARG;
1137→  __IO uint32_t CMD;
1138→  __I uint32_t RESPCMD;
1139→  __I uint32_t RESP1;
1140→  __I uint32_t RESP2;
1141→  __I uint32_t RESP3;
1142→  __I uint32_t RESP4;
1143→  __IO uint32_t DTIMER;
1144→  __IO uint32_t DLEN;
1145→  __IO uint32_t DCTRL;
1146→  __I uint32_t DCOUNT;
1147→  __I uint32_t STA;
1148→  __IO uint32_t ICR;
1149→  __IO uint32_t MASK;
1150→  uint32_t  RESERVED0[2];
1151→  __I uint32_t FIFOCNT;
1152→  uint32_t  RESERVED1[13];
1153→  __IO uint32_t FIFO;
1154→} SDIO_TypeDef;
1155→
1156→/** 
1157→  * @brief Serial Peripheral Interface
1158→  */
1159→
1160→typedef struct
1161→{
1162→  __IO uint16_t CR1;
1163→  uint16_t  RESERVED0;
1164→  __IO uint16_t CR2;
1165→  uint16_t  RESERVED1;
1166→  __IO uint16_t SR;
1167→  uint16_t  RESERVED2;
1168→  __IO uint16_t DR;
1169→  uint16_t  RESERVED3;
1170→  __IO uint16_t CRCPR;
1171→  uint16_t  RESERVED4;
1172→  __IO uint16_t RXCRCR;
1173→  uint16_t  RESERVED5;
1174→  __IO uint16_t TXCRCR;
1175→  uint16_t  RESERVED6;
1176→  __IO uint16_t I2SCFGR;
1177→  uint16_t  RESERVED7;
1178→  __IO uint16_t I2SPR;
1179→  uint16_t  RESERVED8;  
1180→} SPI_TypeDef;
1181→
1182→/** 
1183→  * @brief TIM
1184→  */
1185→
1186→typedef struct
1187→{
1188→  __IO uint16_t CR1;
1189→  uint16_t  RESERVED0;
1190→  __IO uint16_t CR2;
1191→  uint16_t  RESERVED1;
1192→  __IO uint16_t SMCR;
1193→  uint16_t  RESERVED2;
1194→  __IO uint16_t DIER;
1195→  uint16_t  RESERVED3;
1196→  __IO uint16_t SR;
1197→  uint16_t  RESERVED4;
1198→  __IO uint16_t EGR;
1199→  uint16_t  RESERVED5;
1200→  __IO uint16_t CCMR1;
1201→  uint16_t  RESERVED6;
1202→  __IO uint16_t CCMR2;
1203→  uint16_t  RESERVED7;
1204→  __IO uint16_t CCER;
1205→  uint16_t  RESERVED8;
1206→  __IO uint16_t CNT;
1207→  uint16_t  RESERVED9;
1208→  __IO uint16_t PSC;
1209→  uint16_t  RESERVED10;
1210→  __IO uint16_t ARR;
1211→  uint16_t  RESERVED11;
1212→  __IO uint16_t RCR;
1213→  uint16_t  RESERVED12;
1214→  __IO uint16_t CCR1;
1215→  uint16_t  RESERVED13;
1216→  __IO uint16_t CCR2;
1217→  uint16_t  RESERVED14;
1218→  __IO uint16_t CCR3;
1219→  uint16_t  RESERVED15;