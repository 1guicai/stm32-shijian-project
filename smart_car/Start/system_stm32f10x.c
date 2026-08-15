   1→/**
   2→  ******************************************************************************
   3→  * @file    system_stm32f10x.c
   4→  * @author  MCD Application Team
   5→  * @version V3.5.0
   6→  * @date    11-March-2011
   7→  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer System Source File.
   8→  * 
   9→  * 1.  This file provides two functions and one global variable to be called from 
  10→  *     user application:
  11→  *      - SystemInit(): Setups the system clock (System clock source, PLL Multiplier
  12→  *                      factors, AHB/APBx prescalers and Flash settings). 
  13→  *                      This function is called at startup just after reset and 
  14→  *                      before branch to main program. This call is made inside
  15→  *                      the "startup_stm32f10x_xx.s" file.
  16→  *
  17→  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  18→  *                                  by the user application to setup the SysTick 
  19→  *                                  timer or configure other parameters.
  20→  *                                     
  21→  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  22→  *                                 be called whenever the core clock is changed
  23→  *                                 during program execution.
  24→  *
  25→  * 2. After each device reset the HSI (8 MHz) is used as system clock source.
  26→  *    Then SystemInit() function is called, in "startup_stm32f10x_xx.s" file, to
  27→  *    configure the system clock before to branch to main program.
  28→  *
  29→  * 3. If the system clock source selected by user fails to startup, the SystemInit()
  30→  *    function will do nothing and HSI still used as system clock source. User can 
  31→  *    add some code to deal with this issue inside the SetSysClock() function.
  32→  *
  33→  * 4. The default value of HSE crystal is set to 8 MHz (or 25 MHz, depedning on
  34→  *    the product used), refer to "HSE_VALUE" define in "stm32f10x.h" file. 
  35→  *    When HSE is used as system clock source, directly or through PLL, and you
  36→  *    are using different crystal you have to adapt the HSE value to your own
  37→  *    configuration.
  38→  *        
  39→  ******************************************************************************
  40→  * @attention
  41→  *
  42→  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  43→  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  44→  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  45→  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  46→  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  47→  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  48→  *
  49→  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  50→  ******************************************************************************
  51→  */
  52→
  53→/** @addtogroup CMSIS
  54→  * @{
  55→  */
  56→
  57→/** @addtogroup stm32f10x_system
  58→  * @{
  59→  */  
  60→  
  61→/** @addtogroup STM32F10x_System_Private_Includes
  62→  * @{
  63→  */
  64→
  65→#include "stm32f10x.h"
  66→
  67→/**
  68→  * @}
  69→  */
  70→
  71→/** @addtogroup STM32F10x_System_Private_TypesDefinitions
  72→  * @{
  73→  */
  74→
  75→/**
  76→  * @}
  77→  */
  78→
  79→/** @addtogroup STM32F10x_System_Private_Defines
  80→  * @{
  81→  */
  82→
  83→/*!< Uncomment the line corresponding to the desired System clock (SYSCLK)
  84→   frequency (after reset the HSI is used as SYSCLK source)
  85→   
  86→   IMPORTANT NOTE:
  87→   ============== 
  88→   1. After each device reset the HSI is used as System clock source.
  89→
  90→   2. Please make sure that the selected System clock doesn't exceed your device's
  91→      maximum frequency.
  92→      
  93→   3. If none of the define below is enabled, the HSI is used as System clock
  94→    source.
  95→
  96→   4. The System clock configuration functions provided within this file assume that:
  97→        - For Low, Medium and High density Value line devices an external 8MHz 
  98→          crystal is used to drive the System clock.
  99→        - For Low, Medium and High density devices an external 8MHz crystal is
 100→          used to drive the System clock.
 101→        - For Connectivity line devices an external 25MHz crystal is used to drive
 102→          the System clock.
 103→     If you are using different crystal you have to adapt those functions accordingly.
 104→    */
 105→    
 106→#if defined (STM32F10X_LD_VL) || (defined STM32F10X_MD_VL) || (defined STM32F10X_HD_VL)
 107→/* #define SYSCLK_FREQ_HSE    HSE_VALUE */
 108→ #define SYSCLK_FREQ_24MHz  24000000
 109→#else
 110→/* #define SYSCLK_FREQ_HSE    HSE_VALUE */
 111→/* #define SYSCLK_FREQ_24MHz  24000000 */ 
 112→/* #define SYSCLK_FREQ_36MHz  36000000 */
 113→/* #define SYSCLK_FREQ_48MHz  48000000 */
 114→/* #define SYSCLK_FREQ_56MHz  56000000 */
 115→#define SYSCLK_FREQ_72MHz  72000000
 116→#endif
 117→
 118→/*!< Uncomment the following line if you need to use external SRAM mounted
 119→     on STM3210E-EVAL board (STM32 High density and XL-density devices) or on 
 120→     STM32100E-EVAL board (STM32 High-density value line devices) as data memory */ 
 121→#if defined (STM32F10X_HD) || (defined STM32F10X_XL) || (defined STM32F10X_HD_VL)
 122→/* #define DATA_IN_ExtSRAM */
 123→#endif
 124→
 125→/*!< Uncomment the following line if you need to relocate your vector Table in
 126→     Internal SRAM. */ 
 127→/* #define VECT_TAB_SRAM */
 128→#define VECT_TAB_OFFSET  0x0 /*!< Vector Table base offset field. 
 129→                                  This value must be a multiple of 0x200. */
 130→
 131→
 132→/**
 133→  * @}
 134→  */
 135→
 136→/** @addtogroup STM32F10x_System_Private_Macros
 137→  * @{
 138→  */
 139→
 140→/**
 141→  * @}
 142→  */
 143→
 144→/** @addtogroup STM32F10x_System_Private_Variables
 145→  * @{
 146→  */
 147→
 148→/*******************************************************************************
 149→*  Clock Definitions
 150→*******************************************************************************/
 151→#ifdef SYSCLK_FREQ_HSE
 152→  uint32_t SystemCoreClock         = SYSCLK_FREQ_HSE;        /*!< System Clock Frequency (Core Clock) */
 153→#elif defined SYSCLK_FREQ_24MHz
 154→  uint32_t SystemCoreClock         = SYSCLK_FREQ_24MHz;        /*!< System Clock Frequency (Core Clock) */
 155→#elif defined SYSCLK_FREQ_36MHz
 156→  uint32_t SystemCoreClock         = SYSCLK_FREQ_36MHz;        /*!< System Clock Frequency (Core Clock) */
 157→#elif defined SYSCLK_FREQ_48MHz
 158→  uint32_t SystemCoreClock         = SYSCLK_FREQ_48MHz;        /*!< System Clock Frequency (Core Clock) */
 159→#elif defined SYSCLK_FREQ_56MHz
 160→  uint32_t SystemCoreClock         = SYSCLK_FREQ_56MHz;        /*!< System Clock Frequency (Core Clock) */
 161→#elif defined SYSCLK_FREQ_72MHz
 162→  uint32_t SystemCoreClock         = SYSCLK_FREQ_72MHz;        /*!< System Clock Frequency (Core Clock) */
 163→#else /*!< HSI Selected as System Clock source */
 164→  uint32_t SystemCoreClock         = HSI_VALUE;        /*!< System Clock Frequency (Core Clock) */
 165→#endif
 166→
 167→__I uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
 168→/**
 169→  * @}
 170→  */
 171→
 172→/** @addtogroup STM32F10x_System_Private_FunctionPrototypes
 173→  * @{
 174→  */
 175→
 176→static void SetSysClock(void);
 177→
 178→#ifdef SYSCLK_FREQ_HSE
 179→  static void SetSysClockToHSE(void);
 180→#elif defined SYSCLK_FREQ_24MHz
 181→  static void SetSysClockTo24(void);
 182→#elif defined SYSCLK_FREQ_36MHz
 183→  static void SetSysClockTo36(void);
 184→#elif defined SYSCLK_FREQ_48MHz
 185→  static void SetSysClockTo48(void);
 186→#elif defined SYSCLK_FREQ_56MHz
 187→  static void SetSysClockTo56(void);  
 188→#elif defined SYSCLK_FREQ_72MHz
 189→  static void SetSysClockTo72(void);
 190→#endif
 191→
 192→#ifdef DATA_IN_ExtSRAM
 193→  static void SystemInit_ExtMemCtl(void); 
 194→#endif /* DATA_IN_ExtSRAM */
 195→
 196→/**
 197→  * @}
 198→  */
 199→
 200→/** @addtogroup STM32F10x_System_Private_Functions
 201→  * @{
 202→  */
 203→
 204→/**
 205→  * @brief  Setup the microcontroller system
 206→  *         Initialize the Embedded Flash Interface, the PLL and update the 
 207→  *         SystemCoreClock variable.
 208→  * @note   This function should be used only after reset.
 209→  * @param  None
 210→  * @retval None
 211→  */
 212→void SystemInit (void)
 213→{
 214→  /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
 215→  /* Set HSION bit */
 216→  RCC->CR |= (uint32_t)0x00000001;
 217→
 218→  /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
 219→#ifndef STM32F10X_CL
 220→  RCC->CFGR &= (uint32_t)0xF8FF0000;
 221→#else
 222→  RCC->CFGR &= (uint32_t)0xF0FF0000;
 223→#endif /* STM32F10X_CL */   
 224→  
 225→  /* Reset HSEON, CSSON and PLLON bits */
 226→  RCC->CR &= (uint32_t)0xFEF6FFFF;
 227→
 228→  /* Reset HSEBYP bit */
 229→  RCC->CR &= (uint32_t)0xFFFBFFFF;
 230→
 231→  /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
 232→  RCC->CFGR &= (uint32_t)0xFF80FFFF;
 233→
 234→#ifdef STM32F10X_CL
 235→  /* Reset PLL2ON and PLL3ON bits */
 236→  RCC->CR &= (uint32_t)0xEBFFFFFF;
 237→
 238→  /* Disable all interrupts and clear pending bits  */
 239→  RCC->CIR = 0x00FF0000;
 240→
 241→  /* Reset CFGR2 register */
 242→  RCC->CFGR2 = 0x00000000;
 243→#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || (defined STM32F10X_HD_VL)
 244→  /* Disable all interrupts and clear pending bits  */
 245→  RCC->CIR = 0x009F0000;
 246→
 247→  /* Reset CFGR2 register */
 248→  RCC->CFGR2 = 0x00000000;      
 249→#else
 250→  /* Disable all interrupts and clear pending bits  */
 251→  RCC->CIR = 0x009F0000;
 252→#endif /* STM32F10X_CL */
 253→    
 254→#if defined (STM32F10X_HD) || (defined STM32F10X_XL) || (defined STM32F10X_HD_VL)
 255→  #ifdef DATA_IN_ExtSRAM
 256→    SystemInit_ExtMemCtl(); 
 257→  #endif /* DATA_IN_ExtSRAM */
 258→#endif 
 259→
 260→  /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
 261→  /* Configure the Flash Latency cycles and enable prefetch buffer */
 262→  SetSysClock();
 263→
 264→#ifdef VECT_TAB_SRAM
 265→  SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM. */
 266→#else
 267→  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH. */
 268→#endif 
 269→}
 270→
 271→/**
 272→  * @brief  Update SystemCoreClock variable according to Clock Register Values.
 273→  *         The SystemCoreClock variable contains the core clock (HCLK), it can
 274→  *         be used by the user application to setup the SysTick timer or configure
 275→  *         other parameters.
 276→  *           
 277→  * @note   Each time the core clock (HCLK) changes, this function must be called
 278→  *         to update SystemCoreClock variable value. Otherwise, any configuration
 279→  *         based on this variable will be incorrect.         
 280→  *     
 281→  * @note   - The system frequency computed by this function is not the real 
 282→  *           frequency in the chip. It is calculated based on the predefined 
 283→  *           constant and the selected clock source:
 284→  *             
 285→  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(*)
 286→  *                                              
 287→  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(**)
 288→  *                          
 289→  *           - If SYSCLK source is PLL, SystemCoreClock will contain the HSE_VALUE(**) 
 290→  *             or HSI_VALUE(*) multiplied by the PLL factors.
 291→  *         
 292→  *         (*) HSI_VALUE is a constant defined in stm32f1xx.h file (default value
 293→  *             8 MHz) but the real value may vary depending on the variations
 294→  *             in voltage and temperature.   
 295→  *    
 296→  *         (**) HSE_VALUE is a constant defined in stm32f1xx.h file (default value
 297→  *              8 MHz or 25 MHz, depedning on the product used), user has to ensure
 298→  *              that HSE_VALUE is same as the real frequency of the crystal used.
 299→  *              Otherwise, this function may have wrong result.
 300→  *                
 301→  *         - The result of this function could be not correct when using fractional
 302→  *           value for HSE crystal.
 303→  * @param  None
 304→  * @retval None
 305→  */
 306→void SystemCoreClockUpdate (void)
 307→{
 308→  uint32_t tmp = 0, pllmull = 0, pllsource = 0;
 309→
 310→#ifdef  STM32F10X_CL
 311→  uint32_t prediv1source = 0, prediv1factor = 0, prediv2factor = 0, pll2mull = 0;
 312→#endif /* STM32F10X_CL */
 313→
 314→#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || (defined STM32F10X_HD_VL)
 315→  uint32_t prediv1factor = 0;
 316→#endif /* STM32F10X_LD_VL or STM32F10X_MD_VL or STM32F10X_HD_VL */
 317→    
 318→  /* Get SYSCLK source -------------------------------------------------------*/
 319→  tmp = RCC->CFGR & RCC_CFGR_SWS;
 320→  
 321→  switch (tmp)
 322→  {
 323→    case 0x00:  /* HSI used as system clock */
 324→      SystemCoreClock = HSI_VALUE;
 325→      break;
 326→    case 0x04:  /* HSE used as system clock */
 327→      SystemCoreClock = HSE_VALUE;
 328→      break;
 329→    case 0x08:  /* PLL used as system clock */
 330→
 331→      /* Get PLL clock source and multiplication factor ----------------------*/
 332→      pllmull = RCC->CFGR & RCC_CFGR_PLLMULL;
 333→      pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
 334→      
 335→#ifndef STM32F10X_CL      
 336→      pllmull = ( pllmull >> 18) + 2;
 337→      
 338→      if (pllsource == 0x00)
 339→      {
 340→        /* HSI oscillator clock divided by 2 selected as PLL clock entry */
 341→        SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
 342→      }
 343→      else
 344→      {
 345→ #if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || (defined STM32F10X_HD_VL)
 346→       prediv1factor = (RCC->CFGR2 & RCC_CFGR2_PREDIV1) + 1;
 347→       /* HSE oscillator clock selected as PREDIV1 clock entry */
 348→       SystemCoreClock = (HSE_VALUE / prediv1factor) * pllmull; 
 349→ #else
 350→        /* HSE selected as PLL clock entry */
 351→        if ((RCC->CFGR & RCC_CFGR_PLLXTPRE) != (uint32_t)RESET)
 352→        {/* HSE oscillator clock divided by 2 */
 353→          SystemCoreClock = (HSE_VALUE >> 1) * pllmull;
 354→        }
 355→        else
 356→        {
 357→          SystemCoreClock = HSE_VALUE * pllmull;
 358→        }
 359→ #endif
 360→      }
 361→#else
 362→      pllmull = pllmull >> 18;
 363→      
 364→      if (pllmull != 0x0D)
 365→      {
 366→         pllmull += 2;
 367→      }
 368→      else
 369→      { /* PLL multiplication factor = PLL input clock * 6.5 */
 370→        pllmull = 13 / 2; 
 371→      }
 372→            
 373→      if (pllsource == 0x00)
 374→      {
 375→        /* HSI oscillator clock divided by 2 selected as PLL clock entry */
 376→        SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
 377→      }
 378→      else
 379→      {/* PREDIV1 selected as PLL clock entry */
 380→        
 381→        /* Get PREDIV1 clock source and division factor */
 382→        prediv1source = RCC->CFGR2 & RCC_CFGR2_PREDIV1SRC;
 383→        prediv1factor = (RCC->CFGR2 & RCC_CFGR2_PREDIV1) + 1;
 384→        
 385→        if (prediv1source == 0)
 386→        { 
 387→          /* HSE oscillator clock selected as PREDIV1 clock entry */
 388→          SystemCoreClock = (HSE_VALUE / prediv1factor) * pllmull;          
 389→        }
 390→        else
 391→        {/* PLL2 clock selected as PREDIV1 clock entry */
 392→          
 393→          /* Get PREDIV2 division factor and PLL2 multiplication factor */
 394→          prediv2factor = ((RCC->CFGR2 & RCC_CFGR2_PREDIV2) >> 4) + 1;
 395→          pll2mull = ((RCC->CFGR2 & RCC_CFGR2_PLL2MUL) >> 8 ) + 2; 
 396→          SystemCoreClock = (((HSE_VALUE / prediv2factor) * pll2mull) / prediv1factor) * pllmull;                         
 397→        }
 398→      }
 399→#endif /* STM32F10X_CL */ 
 400→      break;
 401→
 402→    default:
 403→      SystemCoreClock = HSI_VALUE;
 404→      break;
 405→  }
 406→  
 407→  /* Compute HCLK clock frequency ----------------*/
 408→  /* Get HCLK prescaler */
 409→  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
 410→  /* HCLK clock frequency */
 411→  SystemCoreClock >>= tmp;  
 412→}
 413→
 414→/**
 415→  * @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
 416→  * @param  None
 417→  * @retval None
 418→  */
 419→static void SetSysClock(void)
 420→{
 421→#ifdef SYSCLK_FREQ_HSE
 422→  SetSysClockToHSE();
 423→#elif defined SYSCLK_FREQ_24MHz
 424→  SetSysClockTo24();
 425→#elif defined SYSCLK_FREQ_36MHz
 426→  SetSysClockTo36();
 427→#elif defined SYSCLK_FREQ_48MHz
 428→  SetSysClockTo48();
 429→#elif defined SYSCLK_FREQ_56MHz
 430→  SetSysClockTo56();  
 431→#elif defined SYSCLK_FREQ_72MHz
 432→  SetSysClockTo72();
 433→#endif
 434→ 
 435→ /* If none of the define above is enabled, the HSI is used as System clock
 436→    source (default after reset) */ 
 437→}
 438→
 439→/**
 440→  * @brief  Setup the external memory controller. Called in startup_stm32f10x.s 
 441→  *          before jump to __main
 442→  * @param  None
 443→  * @retval None
 444→  */ 
 445→#ifdef DATA_IN_ExtSRAM
 446→/**
 447→  * @brief  Setup the external memory controller. 
 448→  *         Called in startup_stm32f10x_xx.s/.c before jump to main.
 449→  * 	      This function configures the external SRAM mounted on STM3210E-EVAL
 450→  *         board (STM32 High density devices). This SRAM will be used as program
 451→  *         data memory (including heap and stack).
 452→  * @param  None
 453→  * @retval None
 454→  */ 
 455→void SystemInit_ExtMemCtl(void) 
 456→{
 457→/*!< FSMC Bank1 NOR/SRAM3 is used for the STM3210E-EVAL, if another Bank is 
 458→  required, then adjust the Register Addresses */
 459→
 460→  /* Enable FSMC clock */
 461→  RCC->AHBENR = 0x00000114;
 462→  
 463→  /* Enable GPIOD, GPIOE, GPIOF and GPIOG clocks */  
 464→  RCC->APB2ENR = 0x000001E0;
 465→  
 466→/* ---------------  SRAM Data lines, NOE and NWE configuration ---------------*/
 467→/*----------------  SRAM Address lines configuration -------------------------*/
 468→/*----------------  NOE and NWE configuration --------------------------------*/  
 469→/*----------------  NE3 configuration ----------------------------------------*/
 470→/*----------------  NBL0, NBL1 configuration ---------------------------------*/
 471→  
 472→  GPIOD->CRL = 0x44BB44BB;  
 473→  GPIOD->CRH = 0xBBBBBBBB;
 474→
 475→  GPIOE->CRL = 0xB44444BB;  
 476→  GPIOE->CRH = 0xBBBBBBBB;
 477→
 478→  GPIOF->CRL = 0x44BBBBBB;  
 479→  GPIOF->CRH = 0xBBBB4444;
 480→
 481→  GPIOG->CRL = 0x44BBBBBB;  
 482→  GPIOG->CRH = 0x44444B44;
 483→   
 484→/*----------------  FSMC Configuration ---------------------------------------*/  
 485→/*----------------  Enable FSMC Bank1_SRAM Bank ------------------------------*/
 486→  
 487→  FSMC_Bank1->BTCR[4] = 0x00001011;
 488→  FSMC_Bank1->BTCR[5] = 0x00000200;
 489→}
 490→#endif /* DATA_IN_ExtSRAM */
 491→
 492→#ifdef SYSCLK_FREQ_HSE
 493→/**
 494→  * @brief  Selects HSE as System clock source and configure HCLK, PCLK2
 495→  *         and PCLK1 prescalers.
 496→  * @note   This function should be used only after reset.
 497→  * @param  None
 498→  * @retval None
 499→  */
 500→static void SetSysClockToHSE(void)
 501→{
 502→  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
 503→  
 504→  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/    
 505→  /* Enable HSE */    
 506→  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 507→ 
 508→  /* Wait till HSE is ready and if Time out is reached exit */
 509→  do
 510→  {
 511→    HSEStatus = RCC->CR & RCC_CR_HSERDY;
 512→    StartUpCounter++;  
 513→  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
 514→
 515→  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
 516→  {
 517→    HSEStatus = (uint32_t)0x01;
 518→  }
 519→  else
 520→  {
 521→    HSEStatus = (uint32_t)0x00;
 522→  }  
 523→
 524→  if (HSEStatus == (uint32_t)0x01)
 525→  {
 526→
 527→#if !defined STM32F10X_LD_VL && !defined STM32F10X_MD_VL && !defined STM32F10X_HD_VL
 528→    /* Enable Prefetch Buffer */
 529→    FLASH->ACR |= FLASH_ACR_PRFTBE;
 530→
 531→    /* Flash 0 wait state */
 532→    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
 533→
 534→#ifndef STM32F10X_CL
 535→    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_0;
 536→#else
 537→    if (HSE_VALUE <= 24000000)
 538→	{
 539→      FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_0;
 540→	}
 541→	else
 542→	{
 543→      FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_1;
 544→	}
 545→#endif /* STM32F10X_CL */
 546→#endif
 547→ 
 548→    /* HCLK = SYSCLK */
 549→    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
 550→      
 551→    /* PCLK2 = HCLK */
 552→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
 553→    
 554→    /* PCLK1 = HCLK */
 555→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV1;
 556→    
 557→    /* Select HSE as system clock source */
 558→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
 559→    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_HSE;    
 560→
 561→    /* Wait till HSE is used as system clock source */
 562→    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x04)
 563→    {
 564→    }
 565→  }
 566→  else
 567→  { /* If HSE fails to start-up, the application will have wrong clock 
 568→         configuration. User can add here some code to deal with this error */
 569→  }  
 570→}
 571→#elif defined SYSCLK_FREQ_24MHz
 572→/**
 573→  * @brief  Sets System clock frequency to 24MHz and configure HCLK, PCLK2 
 574→  *         and PCLK1 prescalers.
 575→  * @note   This function should be used only after reset.
 576→  * @param  None
 577→  * @retval None
 578→  */
 579→static void SetSysClockTo24(void)
 580→{
 581→  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
 582→  
 583→  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/    
 584→  /* Enable HSE */    
 585→  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 586→ 
 587→  /* Wait till HSE is ready and if Time out is reached exit */
 588→  do
 589→  {
 590→    HSEStatus = RCC->CR & RCC_CR_HSERDY;
 591→    StartUpCounter++;  
 592→  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
 593→
 594→  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
 595→  {
 596→    HSEStatus = (uint32_t)0x01;
 597→  }
 598→  else
 599→  {
 600→    HSEStatus = (uint32_t)0x00;
 601→  }  
 602→
 603→  if (HSEStatus == (uint32_t)0x01)
 604→  {
 605→#if !defined STM32F10X_LD_VL && !defined STM32F10X_MD_VL && !defined STM32F10X_HD_VL 
 606→    /* Enable Prefetch Buffer */
 607→    FLASH->ACR |= FLASH_ACR_PRFTBE;
 608→
 609→    /* Flash 0 wait state */
 610→    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
 611→    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_0;    
 612→#endif
 613→ 
 614→    /* HCLK = SYSCLK */
 615→    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
 616→      
 617→    /* PCLK2 = HCLK */
 618→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
 619→    
 620→    /* PCLK1 = HCLK */
 621→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV1;
 622→    
 623→#ifdef STM32F10X_CL
 624→    /* Configure PLLs ------------------------------------------------------*/
 625→    /* PLL configuration: PLLCLK = PREDIV1 * 6 = 24 MHz */ 
 626→    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
 627→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
 628→                            RCC_CFGR_PLLMULL6); 
 629→
 630→    /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */
 631→    /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 10 = 4 MHz */       
 632→    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
 633→                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
 634→    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
 635→                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV10);
 636→  
 637→    /* Enable PLL2 */
 638→    RCC->CR |= RCC_CR_PLL2ON;
 639→    /* Wait till PLL2 is ready */
 640→    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
 641→    {
 642→    }   
 643→#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
 644→    /*  PLL configuration:  = (HSE / 2) * 6 = 24 MHz */
 645→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
 646→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_PREDIV1 | RCC_CFGR_PLLXTPRE_PREDIV1_Div2 | RCC_CFGR_PLLMULL6);
 647→#else    
 648→    /*  PLL configuration:  = (HSE / 2) * 6 = 24 MHz */
 649→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
 650→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLXTPRE_HSE_Div2 | RCC_CFGR_PLLMULL6);
 651→#endif /* STM32F10X_CL */
 652→
 653→    /* Enable PLL */
 654→    RCC->CR |= RCC_CR_PLLON;
 655→
 656→    /* Wait till PLL is ready */
 657→    while((RCC->CR & RCC_CR_PLLRDY) == 0)
 658→    {
 659→    }
 660→
 661→    /* Select PLL as system clock source */
 662→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
 663→    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    
 664→
 665→    /* Wait till PLL is used as system clock source */
 666→    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
 667→    {
 668→    }
 669→  }
 670→  else
 671→  { /* If HSE fails to start-up, the application will have wrong clock 
 672→         configuration. User can add here some code to deal with this error */
 673→  } 
 674→}
 675→#elif defined SYSCLK_FREQ_36MHz
 676→/**
 677→  * @brief  Sets System clock frequency to 36MHz and configure HCLK, PCLK2 
 678→  *         and PCLK1 prescalers. 
 679→  * @note   This function should be used only after reset.
 680→  * @param  None
 681→  * @retval None
 682→  */
 683→static void SetSysClockTo36(void)
 684→{
 685→  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
 686→  
 687→  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/    
 688→  /* Enable HSE */    
 689→  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 690→ 
 691→  /* Wait till HSE is ready and if Time out is reached exit */
 692→  do
 693→  {
 694→    HSEStatus = RCC->CR & RCC_CR_HSERDY;
 695→    StartUpCounter++;  
 696→  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
 697→
 698→  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
 699→  {
 700→    HSEStatus = (uint32_t)0x01;
 701→  }
 702→  else
 703→  {
 704→    HSEStatus = (uint32_t)0x00;
 705→  }  
 706→
 707→  if (HSEStatus == (uint32_t)0x01)
 708→  {
 709→    /* Enable Prefetch Buffer */
 710→    FLASH->ACR |= FLASH_ACR_PRFTBE;
 711→
 712→    /* Flash 1 wait state */
 713→    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
 714→    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_1;    
 715→ 
 716→    /* HCLK = SYSCLK */
 717→    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
 718→      
 719→    /* PCLK2 = HCLK */
 720→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
 721→    
 722→    /* PCLK1 = HCLK */
 723→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV1;
 724→    
 725→#ifdef STM32F10X_CL
 726→    /* Configure PLLs ------------------------------------------------------*/
 727→    
 728→    /* PLL configuration: PLLCLK = PREDIV1 * 9 = 36 MHz */ 
 729→    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
 730→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
 731→                            RCC_CFGR_PLLMULL9); 
 732→
 733→	/*!< PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */
 734→    /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 10 = 4 MHz */
 735→        
 736→    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
 737→                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
 738→    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
 739→                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV10);
 740→  
 741→    /* Enable PLL2 */
 742→    RCC->CR |= RCC_CR_PLL2ON;
 743→    /* Wait till PLL2 is ready */
 744→    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
 745→    {
 746→    }
 747→    
 748→#else    
 749→    /*  PLL configuration: PLLCLK = (HSE / 2) * 9 = 36 MHz */
 750→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
 751→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLXTPRE_HSE_Div2 | RCC_CFGR_PLLMULL9);
 752→#endif /* STM32F10X_CL */
 753→
 754→    /* Enable PLL */
 755→    RCC->CR |= RCC_CR_PLLON;
 756→
 757→    /* Wait till PLL is ready */
 758→    while((RCC->CR & RCC_CR_PLLRDY) == 0)
 759→    {
 760→    }
 761→
 762→    /* Select PLL as system clock source */
 763→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
 764→    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    
 765→
 766→    /* Wait till PLL is used as system clock source */
 767→    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
 768→    {
 769→    }
 770→  }
 771→  else
 772→  { /* If HSE fails to start-up, the application will have wrong clock 
 773→         configuration. User can add here some code to deal with this error */
 774→  } 
 775→}
 776→#elif defined SYSCLK_FREQ_48MHz
 777→/**
 778→  * @brief  Sets System clock frequency to 48MHz and configure HCLK, PCLK2 
 779→  *         and PCLK1 prescalers. 
 780→  * @note   This function should be used only after reset.
 781→  * @param  None
 782→  * @retval None
 783→  */
 784→static void SetSysClockTo48(void)
 785→{
 786→  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
 787→  
 788→  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/    
 789→  /* Enable HSE */    
 790→  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 791→ 
 792→  /* Wait till HSE is ready and if Time out is reached exit */
 793→  do
 794→  {
 795→    HSEStatus = RCC->CR & RCC_CR_HSERDY;
 796→    StartUpCounter++;  
 797→  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
 798→
 799→  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
 800→  {
 801→    HSEStatus = (uint32_t)0x01;
 802→  }
 803→  else
 804→  {
 805→    HSEStatus = (uint32_t)0x00;
 806→  }  
 807→
 808→  if (HSEStatus == (uint32_t)0x01)
 809→  {
 810→    /* Enable Prefetch Buffer */
 811→    FLASH->ACR |= FLASH_ACR_PRFTBE;
 812→
 813→    /* Flash 1 wait state */
 814→    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
 815→    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_1;    
 816→ 
 817→    /* HCLK = SYSCLK */
 818→    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
 819→      
 820→    /* PCLK2 = HCLK */
 821→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
 822→    
 823→    /* PCLK1 = HCLK */
 824→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;
 825→    
 826→#ifdef STM32F10X_CL
 827→    /* Configure PLLs ------------------------------------------------------*/
 828→    /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */
 829→    /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 5 = 8 MHz */
 830→        
 831→    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
 832→                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
 833→    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
 834→                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV5);
 835→  
 836→    /* Enable PLL2 */
 837→    RCC->CR |= RCC_CR_PLL2ON;
 838→    /* Wait till PLL2 is ready */
 839→    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
 840→    {
 841→    }
 842→    
 843→   
 844→    /* PLL configuration: PLLCLK = PREDIV1 * 6 = 48 MHz */ 
 845→    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
 846→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
 847→                            RCC_CFGR_PLLMULL6); 
 848→#else    
 849→    /*  PLL configuration: PLLCLK = HSE * 6 = 48 MHz */
 850→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
 851→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL6);
 852→#endif /* STM32F10X_CL */
 853→
 854→    /* Enable PLL */
 855→    RCC->CR |= RCC_CR_PLLON;
 856→
 857→    /* Wait till PLL is ready */
 858→    while((RCC->CR & RCC_CR_PLLRDY) == 0)
 859→    {
 860→    }
 861→
 862→    /* Select PLL as system clock source */
 863→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
 864→    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    
 865→
 866→    /* Wait till PLL is used as system clock source */
 867→    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
 868→    {
 869→    }
 870→  }
 871→  else
 872→  { /* If HSE fails to start-up, the application will have wrong clock 
 873→         configuration. User can add here some code to deal with this error */
 874→  } 
 875→}
 876→
 877→#elif defined SYSCLK_FREQ_56MHz
 878→/**
 879→  * @brief  Sets System clock frequency to 56MHz and configure HCLK, PCLK2 
 880→  *         and PCLK1 prescalers. 
 881→  * @note   This function should be used only after reset.
 882→  * @param  None
 883→  * @retval None
 884→  */
 885→static void SetSysClockTo56(void)
 886→{
 887→  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
 888→  
 889→  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/   
 890→  /* Enable HSE */    
 891→  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 892→ 
 893→  /* Wait till HSE is ready and if Time out is reached exit */
 894→  do
 895→  {
 896→    HSEStatus = RCC->CR & RCC_CR_HSERDY;
 897→    StartUpCounter++;  
 898→  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
 899→
 900→  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
 901→  {
 902→    HSEStatus = (uint32_t)0x01;
 903→  }
 904→  else
 905→  {
 906→    HSEStatus = (uint32_t)0x00;
 907→  }  
 908→
 909→  if (HSEStatus == (uint32_t)0x01)
 910→  {
 911→    /* Enable Prefetch Buffer */
 912→    FLASH->ACR |= FLASH_ACR_PRFTBE;
 913→
 914→    /* Flash 2 wait state */
 915→    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
 916→    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    
 917→ 
 918→    /* HCLK = SYSCLK */
 919→    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
 920→      
 921→    /* PCLK2 = HCLK */
 922→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
 923→    
 924→    /* PCLK1 = HCLK */
 925→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;
 926→
 927→#ifdef STM32F10X_CL
 928→    /* Configure PLLs ------------------------------------------------------*/
 929→    /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */
 930→    /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 5 = 8 MHz */
 931→        
 932→    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
 933→                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
 934→    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
 935→                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV5);
 936→  
 937→    /* Enable PLL2 */
 938→    RCC->CR |= RCC_CR_PLL2ON;
 939→    /* Wait till PLL2 is ready */
 940→    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
 941→    {
 942→    }
 943→    
 944→   
 945→    /* PLL configuration: PLLCLK = PREDIV1 * 7 = 56 MHz */ 
 946→    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
 947→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
 948→                            RCC_CFGR_PLLMULL7); 
 949→#else     
 950→    /* PLL configuration: PLLCLK = HSE * 7 = 56 MHz */
 951→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
 952→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL7);
 953→
 954→#endif /* STM32F10X_CL */
 955→
 956→    /* Enable PLL */
 957→    RCC->CR |= RCC_CR_PLLON;
 958→
 959→    /* Wait till PLL is ready */
 960→    while((RCC->CR & RCC_CR_PLLRDY) == 0)
 961→    {
 962→    }
 963→
 964→    /* Select PLL as system clock source */
 965→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
 966→    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    
 967→
 968→    /* Wait till PLL is used as system clock source */
 969→    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
 970→    {
 971→    }
 972→  }
 973→  else
 974→  { /* If HSE fails to start-up, the application will have wrong clock 
 975→         configuration. User can add here some code to deal with this error */
 976→  } 
 977→}
 978→
 979→#elif defined SYSCLK_FREQ_72MHz
 980→/**
 981→  * @brief  Sets System clock frequency to 72MHz and configure HCLK, PCLK2 
 982→  *         and PCLK1 prescalers. 
 983→  * @note   This function should be used only after reset.
 984→  * @param  None
 985→  * @retval None
 986→  */
 987→static void SetSysClockTo72(void)
 988→{
 989→  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
 990→  
 991→  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/    
 992→  /* Enable HSE */    
 993→  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 994→ 
 995→  /* Wait till HSE is ready and if Time out is reached exit */
 996→  do
 997→  {
 998→    HSEStatus = RCC->CR & RCC_CR_HSERDY;
 999→    StartUpCounter++;  
1000→  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
1001→
1002→  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
1003→  {
1004→    HSEStatus = (uint32_t)0x01;
1005→  }
1006→  else
1007→  {
1008→    HSEStatus = (uint32_t)0x00;
1009→  }  
1010→
1011→  if (HSEStatus == (uint32_t)0x01)
1012→  {
1013→    /* Enable Prefetch Buffer */
1014→    FLASH->ACR |= FLASH_ACR_PRFTBE;
1015→
1016→    /* Flash 2 wait state */
1017→    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
1018→    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    
1019→
1020→ 
1021→    /* HCLK = SYSCLK */
1022→    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
1023→      
1024→    /* PCLK2 = HCLK */
1025→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
1026→    
1027→    /* PCLK1 = HCLK */
1028→    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;
1029→
1030→#ifdef STM32F10X_CL
1031→    /* Configure PLLs ------------------------------------------------------*/
1032→    /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */
1033→    /* PREDIV1 configuration: PREDIV1CLK = PLL2 / 5 = 8 MHz */
1034→        
1035→    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
1036→                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
1037→    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
1038→                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV5);
1039→  
1040→    /* Enable PLL2 */
1041→    RCC->CR |= RCC_CR_PLL2ON;
1042→    /* Wait till PLL2 is ready */
1043→    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
1044→    {
1045→    }
1046→    
1047→   
1048→    /* PLL configuration: PLLCLK = PREDIV1 * 9 = 72 MHz */ 
1049→    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
1050→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
1051→                            RCC_CFGR_PLLMULL9); 
1052→#else    
1053→    /*  PLL configuration: PLLCLK = HSE * 9 = 72 MHz */
1054→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE |
1055→                                        RCC_CFGR_PLLMULL));
1056→    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9);
1057→#endif /* STM32F10X_CL */
1058→
1059→    /* Enable PLL */
1060→    RCC->CR |= RCC_CR_PLLON;
1061→
1062→    /* Wait till PLL is ready */
1063→    while((RCC->CR & RCC_CR_PLLRDY) == 0)
1064→    {
1065→    }
1066→    
1067→    /* Select PLL as system clock source */
1068→    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
1069→    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    
1070→
1071→    /* Wait till PLL is used as system clock source */
1072→    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
1073→    {
1074→    }
1075→  }
1076→  else
1077→  { /* If HSE fails to start-up, the application will have wrong clock 
1078→         configuration. User can add here some code to deal with this error */
1079→  }
1080→}
1081→#endif
1082→
1083→/**
1084→  * @}
1085→  */
1086→
1087→/**
1088→  * @}
1089→  */
1090→  
1091→/**
1092→  * @}
1093→  */    
1094→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/