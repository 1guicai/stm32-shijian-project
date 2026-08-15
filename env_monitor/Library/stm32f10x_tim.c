File content truncated due to size limit (50KB). First 50KB included below:

   1→/**
   2→  ******************************************************************************
   3→  * @file    stm32f10x_tim.c
   4→  * @author  MCD Application Team
   5→  * @version V3.5.0
   6→  * @date    11-March-2011
   7→  * @brief   This file provides all the TIM firmware functions.
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
  23→#include "stm32f10x_tim.h"
  24→#include "stm32f10x_rcc.h"
  25→
  26→/** @addtogroup STM32F10x_StdPeriph_Driver
  27→  * @{
  28→  */
  29→
  30→/** @defgroup TIM 
  31→  * @brief TIM driver modules
  32→  * @{
  33→  */
  34→
  35→/** @defgroup TIM_Private_TypesDefinitions
  36→  * @{
  37→  */
  38→
  39→/**
  40→  * @}
  41→  */
  42→
  43→/** @defgroup TIM_Private_Defines
  44→  * @{
  45→  */
  46→
  47→/* ---------------------- TIM registers bit mask ------------------------ */
  48→#define SMCR_ETR_Mask               ((uint16_t)0x00FF) 
  49→#define CCMR_Offset                 ((uint16_t)0x0018)
  50→#define CCER_CCE_Set                ((uint16_t)0x0001)  
  51→#define	CCER_CCNE_Set               ((uint16_t)0x0004) 
  52→
  53→/**
  54→  * @}
  55→  */
  56→
  57→/** @defgroup TIM_Private_Macros
  58→  * @{
  59→  */
  60→
  61→/**
  62→  * @}
  63→  */
  64→
  65→/** @defgroup TIM_Private_Variables
  66→  * @{
  67→  */
  68→
  69→/**
  70→  * @}
  71→  */
  72→
  73→/** @defgroup TIM_Private_FunctionPrototypes
  74→  * @{
  75→  */
  76→
  77→static void TI1_Config(TIM_TypeDef* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,
  78→                       uint16_t TIM_ICFilter);
  79→static void TI2_Config(TIM_TypeDef* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,
  80→                       uint16_t TIM_ICFilter);
  81→static void TI3_Config(TIM_TypeDef* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,
  82→                       uint16_t TIM_ICFilter);
  83→static void TI4_Config(TIM_TypeDef* TIMx, uint16_t TIM_ICPolarity, uint16_t TIM_ICSelection,
  84→                       uint16_t TIM_ICFilter);
  85→/**
  86→  * @}
  87→  */
  88→
  89→/** @defgroup TIM_Private_Macros
  90→  * @{
  91→  */
  92→
  93→/**
  94→  * @}
  95→  */
  96→
  97→/** @defgroup TIM_Private_Variables
  98→  * @{
  99→  */
 100→
 101→/**
 102→  * @}
 103→  */
 104→
 105→/** @defgroup TIM_Private_FunctionPrototypes
 106→  * @{
 107→  */
 108→
 109→/**
 110→  * @}
 111→  */
 112→
 113→/** @defgroup TIM_Private_Functions
 114→  * @{
 115→  */
 116→
 117→/**
 118→  * @brief  Deinitializes the TIMx peripheral registers to their default reset values.
 119→  * @param  TIMx: where x can be 1 to 17 to select the TIM peripheral.
 120→  * @retval None
 121→  */
 122→void TIM_DeInit(TIM_TypeDef* TIMx)
 123→{
 124→  /* Check the parameters */
 125→  assert_param(IS_TIM_ALL_PERIPH(TIMx)); 
 126→ 
 127→  if (TIMx == TIM1)
 128→  {
 129→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM1, ENABLE);
 130→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM1, DISABLE);  
 131→  }     
 132→  else if (TIMx == TIM2)
 133→  {
 134→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM2, ENABLE);
 135→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM2, DISABLE);
 136→  }
 137→  else if (TIMx == TIM3)
 138→  {
 139→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM3, ENABLE);
 140→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM3, DISABLE);
 141→  }
 142→  else if (TIMx == TIM4)
 143→  {
 144→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM4, ENABLE);
 145→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM4, DISABLE);
 146→  } 
 147→  else if (TIMx == TIM5)
 148→  {
 149→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM5, ENABLE);
 150→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM5, DISABLE);
 151→  } 
 152→  else if (TIMx == TIM6)
 153→  {
 154→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM6, ENABLE);
 155→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM6, DISABLE);
 156→  } 
 157→  else if (TIMx == TIM7)
 158→  {
 159→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM7, ENABLE);
 160→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM7, DISABLE);
 161→  } 
 162→  else if (TIMx == TIM8)
 163→  {
 164→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM8, ENABLE);
 165→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM8, DISABLE);
 166→  }
 167→  else if (TIMx == TIM9)
 168→  {      
 169→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM9, ENABLE);
 170→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM9, DISABLE);  
 171→   }  
 172→  else if (TIMx == TIM10)
 173→  {      
 174→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM10, ENABLE);
 175→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM10, DISABLE);  
 176→  }  
 177→  else if (TIMx == TIM11) 
 178→  {     
 179→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM11, ENABLE);
 180→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM11, DISABLE);  
 181→  }  
 182→  else if (TIMx == TIM12)
 183→  {      
 184→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM12, ENABLE);
 185→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM12, DISABLE);  
 186→  }  
 187→  else if (TIMx == TIM13) 
 188→  {       
 189→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM13, ENABLE);
 190→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM13, DISABLE);  
 191→  }
 192→  else if (TIMx == TIM14) 
 193→  {       
 194→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM14, ENABLE);
 195→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM14, DISABLE);  
 196→  }        
 197→  else if (TIMx == TIM15)
 198→  {
 199→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM15, ENABLE);
 200→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM15, DISABLE);
 201→  } 
 202→  else if (TIMx == TIM16)
 203→  {
 204→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM16, ENABLE);
 205→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM16, DISABLE);
 206→  } 
 207→  else
 208→  {
 209→    if (TIMx == TIM17)
 210→    {
 211→      RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM17, ENABLE);
 212→      RCC_APB2PeriphResetCmd(RCC_APB2Periph_TIM17, DISABLE);
 213→    }  
 214→  }
 215→}
 216→
 217→/**
 218→  * @brief  Initializes the TIMx Time Base Unit peripheral according to 
 219→  *         the specified parameters in the TIM_TimeBaseInitStruct.
 220→  * @param  TIMx: where x can be 1 to 17 to select the TIM peripheral.
 221→  * @param  TIM_TimeBaseInitStruct: pointer to a TIM_TimeBaseInitTypeDef
 222→  *         structure that contains the configuration information for the 
 223→  *         specified TIM peripheral.
 224→  * @retval None
 225→  */
 226→void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
 227→{
 228→  uint16_t tmpcr1 = 0;
 229→
 230→  /* Check the parameters */
 231→  assert_param(IS_TIM_ALL_PERIPH(TIMx)); 
 232→  assert_param(IS_TIM_COUNTER_MODE(TIM_TimeBaseInitStruct->TIM_CounterMode));
 233→  assert_param(IS_TIM_CKD_DIV(TIM_TimeBaseInitStruct->TIM_ClockDivision));
 234→
 235→  tmpcr1 = TIMx->CR1;  
 236→
 237→  if((TIMx == TIM1) || (TIMx == TIM8)|| (TIMx == TIM2) || (TIMx == TIM3)||
 238→     (TIMx == TIM4) || (TIMx == TIM5)) 
 239→  {
 240→    /* Select the Counter Mode */
 241→    tmpcr1 &= (uint16_t)(~((uint16_t)(TIM_CR1_DIR | TIM_CR1_CMS)));
 242→    tmpcr1 |= (uint32_t)TIM_TimeBaseInitStruct->TIM_CounterMode;
 243→  }
 244→ 
 245→  if((TIMx != TIM6) && (TIMx != TIM7))
 246→  {
 247→    /* Set the clock division */
 248→    tmpcr1 &= (uint16_t)(~((uint16_t)TIM_CR1_CKD));
 249→    tmpcr1 |= (uint32_t)TIM_TimeBaseInitStruct->TIM_ClockDivision;
 250→  }
 251→
 252→  TIMx->CR1 = tmpcr1;
 253→
 254→  /* Set the Autoreload value */
 255→  TIMx->ARR = TIM_TimeBaseInitStruct->TIM_Period ;
 256→ 
 257→  /* Set the Prescaler value */
 258→  TIMx->PSC = TIM_TimeBaseInitStruct->TIM_Prescaler;
 259→    
 260→  if ((TIMx == TIM1) || (TIMx == TIM8)|| (TIMx == TIM15)|| (TIMx == TIM16) || (TIMx == TIM17))  
 261→  {
 262→    /* Set the Repetition Counter value */
 263→    TIMx->RCR = TIM_TimeBaseInitStruct->TIM_RepetitionCounter;
 264→  }
 265→
 266→  /* Generate an update event to reload the Prescaler and the Repetition counter
 267→     values immediately */
 268→  TIMx->EGR = TIM_PSCReloadMode_Immediate;           
 269→}
 270→
 271→/**
 272→  * @brief  Initializes the TIMx Channel1 according to the specified
 273→  *         parameters in the TIM_OCInitStruct.
 274→  * @param  TIMx: where x can be  1 to 17 except 6 and 7 to select the TIM peripheral.
 275→  * @param  TIM_OCInitStruct: pointer to a TIM_OCInitTypeDef structure
 276→  *         that contains the configuration information for the specified TIM peripheral.
 277→  * @retval None
 278→  */
 279→void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
 280→{
 281→  uint16_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;
 282→   
 283→  /* Check the parameters */
 284→  assert_param(IS_TIM_LIST8_PERIPH(TIMx));
 285→  assert_param(IS_TIM_OC_MODE(TIM_OCInitStruct->TIM_OCMode));
 286→  assert_param(IS_TIM_OUTPUT_STATE(TIM_OCInitStruct->TIM_OutputState));
 287→  assert_param(IS_TIM_OC_POLARITY(TIM_OCInitStruct->TIM_OCPolarity));   
 288→ /* Disable the Channel 1: Reset the CC1E Bit */
 289→  TIMx->CCER &= (uint16_t)(~(uint16_t)TIM_CCER_CC1E);
 290→  /* Get the TIMx CCER register value */
 291→  tmpccer = TIMx->CCER;
 292→  /* Get the TIMx CR2 register value */
 293→  tmpcr2 =  TIMx->CR2;
 294→  
 295→  /* Get the TIMx CCMR1 register value */
 296→  tmpccmrx = TIMx->CCMR1;
 297→    
 298→  /* Reset the Output Compare Mode Bits */
 299→  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_OC1M));
 300→  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_CC1S));
 301→
 302→  /* Select the Output Compare Mode */
 303→  tmpccmrx |= TIM_OCInitStruct->TIM_OCMode;
 304→  
 305→  /* Reset the Output Polarity level */
 306→  tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC1P));
 307→  /* Set the Output Compare Polarity */
 308→  tmpccer |= TIM_OCInitStruct->TIM_OCPolarity;
 309→  
 310→  /* Set the Output State */
 311→  tmpccer |= TIM_OCInitStruct->TIM_OutputState;
 312→    
 313→  if((TIMx == TIM1) || (TIMx == TIM8)|| (TIMx == TIM15)||
 314→     (TIMx == TIM16)|| (TIMx == TIM17))
 315→  {
 316→    assert_param(IS_TIM_OUTPUTN_STATE(TIM_OCInitStruct->TIM_OutputNState));
 317→    assert_param(IS_TIM_OCN_POLARITY(TIM_OCInitStruct->TIM_OCNPolarity));
 318→    assert_param(IS_TIM_OCNIDLE_STATE(TIM_OCInitStruct->TIM_OCNIdleState));
 319→    assert_param(IS_TIM_OCIDLE_STATE(TIM_OCInitStruct->TIM_OCIdleState));
 320→    
 321→    /* Reset the Output N Polarity level */
 322→    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC1NP));
 323→    /* Set the Output N Polarity */
 324→    tmpccer |= TIM_OCInitStruct->TIM_OCNPolarity;
 325→    
 326→    /* Reset the Output N State */
 327→    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC1NE));    
 328→    /* Set the Output N State */
 329→    tmpccer |= TIM_OCInitStruct->TIM_OutputNState;
 330→    
 331→    /* Reset the Output Compare and Output Compare N IDLE State */
 332→    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS1));
 333→    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS1N));
 334→    
 335→    /* Set the Output Idle state */
 336→    tmpcr2 |= TIM_OCInitStruct->TIM_OCIdleState;
 337→    /* Set the Output N Idle state */
 338→    tmpcr2 |= TIM_OCInitStruct->TIM_OCNIdleState;
 339→  }
 340→  /* Write to TIMx CR2 */
 341→  TIMx->CR2 = tmpcr2;
 342→  
 343→  /* Write to TIMx CCMR1 */
 344→  TIMx->CCMR1 = tmpccmrx;
 345→
 346→  /* Set the Capture Compare Register value */
 347→  TIMx->CCR1 = TIM_OCInitStruct->TIM_Pulse; 
 348→ 
 349→  /* Write to TIMx CCER */
 350→  TIMx->CCER = tmpccer;
 351→}
 352→
 353→/**
 354→  * @brief  Initializes the TIMx Channel2 according to the specified
 355→  *         parameters in the TIM_OCInitStruct.
 356→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 8, 9, 12 or 15 to select 
 357→  *         the TIM peripheral.
 358→  * @param  TIM_OCInitStruct: pointer to a TIM_OCInitTypeDef structure
 359→  *         that contains the configuration information for the specified TIM peripheral.
 360→  * @retval None
 361→  */
 362→void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
 363→{
 364→  uint16_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;
 365→   
 366→  /* Check the parameters */
 367→  assert_param(IS_TIM_LIST6_PERIPH(TIMx)); 
 368→  assert_param(IS_TIM_OC_MODE(TIM_OCInitStruct->TIM_OCMode));
 369→  assert_param(IS_TIM_OUTPUT_STATE(TIM_OCInitStruct->TIM_OutputState));
 370→  assert_param(IS_TIM_OC_POLARITY(TIM_OCInitStruct->TIM_OCPolarity));   
 371→   /* Disable the Channel 2: Reset the CC2E Bit */
 372→  TIMx->CCER &= (uint16_t)(~((uint16_t)TIM_CCER_CC2E));
 373→  
 374→  /* Get the TIMx CCER register value */  
 375→  tmpccer = TIMx->CCER;
 376→  /* Get the TIMx CR2 register value */
 377→  tmpcr2 =  TIMx->CR2;
 378→  
 379→  /* Get the TIMx CCMR1 register value */
 380→  tmpccmrx = TIMx->CCMR1;
 381→    
 382→  /* Reset the Output Compare mode and Capture/Compare selection Bits */
 383→  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_OC2M));
 384→  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_CC2S));
 385→  
 386→  /* Select the Output Compare Mode */
 387→  tmpccmrx |= (uint16_t)(TIM_OCInitStruct->TIM_OCMode << 8);
 388→  
 389→  /* Reset the Output Polarity level */
 390→  tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC2P));
 391→  /* Set the Output Compare Polarity */
 392→  tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OCPolarity << 4);
 393→  
 394→  /* Set the Output State */
 395→  tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OutputState << 4);
 396→    
 397→  if((TIMx == TIM1) || (TIMx == TIM8))
 398→  {
 399→    assert_param(IS_TIM_OUTPUTN_STATE(TIM_OCInitStruct->TIM_OutputNState));
 400→    assert_param(IS_TIM_OCN_POLARITY(TIM_OCInitStruct->TIM_OCNPolarity));
 401→    assert_param(IS_TIM_OCNIDLE_STATE(TIM_OCInitStruct->TIM_OCNIdleState));
 402→    assert_param(IS_TIM_OCIDLE_STATE(TIM_OCInitStruct->TIM_OCIdleState));
 403→    
 404→    /* Reset the Output N Polarity level */
 405→    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC2NP));
 406→    /* Set the Output N Polarity */
 407→    tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OCNPolarity << 4);
 408→    
 409→    /* Reset the Output N State */
 410→    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC2NE));    
 411→    /* Set the Output N State */
 412→    tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OutputNState << 4);
 413→    
 414→    /* Reset the Output Compare and Output Compare N IDLE State */
 415→    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS2));
 416→    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS2N));
 417→    
 418→    /* Set the Output Idle state */
 419→    tmpcr2 |= (uint16_t)(TIM_OCInitStruct->TIM_OCIdleState << 2);
 420→    /* Set the Output N Idle state */
 421→    tmpcr2 |= (uint16_t)(TIM_OCInitStruct->TIM_OCNIdleState << 2);
 422→  }
 423→  /* Write to TIMx CR2 */
 424→  TIMx->CR2 = tmpcr2;
 425→  
 426→  /* Write to TIMx CCMR1 */
 427→  TIMx->CCMR1 = tmpccmrx;
 428→
 429→  /* Set the Capture Compare Register value */
 430→  TIMx->CCR2 = TIM_OCInitStruct->TIM_Pulse;
 431→  
 432→  /* Write to TIMx CCER */
 433→  TIMx->CCER = tmpccer;
 434→}
 435→
 436→/**
 437→  * @brief  Initializes the TIMx Channel3 according to the specified
 438→  *         parameters in the TIM_OCInitStruct.
 439→  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
 440→  * @param  TIM_OCInitStruct: pointer to a TIM_OCInitTypeDef structure
 441→  *         that contains the configuration information for the specified TIM peripheral.
 442→  * @retval None
 443→  */
 444→void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
 445→{
 446→  uint16_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;
 447→   
 448→  /* Check the parameters */
 449→  assert_param(IS_TIM_LIST3_PERIPH(TIMx)); 
 450→  assert_param(IS_TIM_OC_MODE(TIM_OCInitStruct->TIM_OCMode));
 451→  assert_param(IS_TIM_OUTPUT_STATE(TIM_OCInitStruct->TIM_OutputState));
 452→  assert_param(IS_TIM_OC_POLARITY(TIM_OCInitStruct->TIM_OCPolarity));   
 453→  /* Disable the Channel 2: Reset the CC2E Bit */
 454→  TIMx->CCER &= (uint16_t)(~((uint16_t)TIM_CCER_CC3E));
 455→  
 456→  /* Get the TIMx CCER register value */
 457→  tmpccer = TIMx->CCER;
 458→  /* Get the TIMx CR2 register value */
 459→  tmpcr2 =  TIMx->CR2;
 460→  
 461→  /* Get the TIMx CCMR2 register value */
 462→  tmpccmrx = TIMx->CCMR2;
 463→    
 464→  /* Reset the Output Compare mode and Capture/Compare selection Bits */
 465→  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR2_OC3M));
 466→  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR2_CC3S));  
 467→  /* Select the Output Compare Mode */
 468→  tmpccmrx |= TIM_OCInitStruct->TIM_OCMode;
 469→  
 470→  /* Reset the Output Polarity level */
 471→  tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC3P));
 472→  /* Set the Output Compare Polarity */
 473→  tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OCPolarity << 8);
 474→  
 475→  /* Set the Output State */
 476→  tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OutputState << 8);
 477→    
 478→  if((TIMx == TIM1) || (TIMx == TIM8))
 479→  {
 480→    assert_param(IS_TIM_OUTPUTN_STATE(TIM_OCInitStruct->TIM_OutputNState));
 481→    assert_param(IS_TIM_OCN_POLARITY(TIM_OCInitStruct->TIM_OCNPolarity));
 482→    assert_param(IS_TIM_OCNIDLE_STATE(TIM_OCInitStruct->TIM_OCNIdleState));
 483→    assert_param(IS_TIM_OCIDLE_STATE(TIM_OCInitStruct->TIM_OCIdleState));
 484→    
 485→    /* Reset the Output N Polarity level */
 486→    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC3NP));
 487→    /* Set the Output N Polarity */
 488→    tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OCNPolarity << 8);
 489→    /* Reset the Output N State */
 490→    tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC3NE));
 491→    
 492→    /* Set the Output N State */
 493→    tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OutputNState << 8);
 494→    /* Reset the Output Compare and Output Compare N IDLE State */
 495→    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS3));
 496→    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS3N));
 497→    /* Set the Output Idle state */
 498→    tmpcr2 |= (uint16_t)(TIM_OCInitStruct->TIM_OCIdleState << 4);
 499→    /* Set the Output N Idle state */
 500→    tmpcr2 |= (uint16_t)(TIM_OCInitStruct->TIM_OCNIdleState << 4);
 501→  }
 502→  /* Write to TIMx CR2 */
 503→  TIMx->CR2 = tmpcr2;
 504→  
 505→  /* Write to TIMx CCMR2 */
 506→  TIMx->CCMR2 = tmpccmrx;
 507→
 508→  /* Set the Capture Compare Register value */
 509→  TIMx->CCR3 = TIM_OCInitStruct->TIM_Pulse;
 510→  
 511→  /* Write to TIMx CCER */
 512→  TIMx->CCER = tmpccer;
 513→}
 514→
 515→/**
 516→  * @brief  Initializes the TIMx Channel4 according to the specified
 517→  *         parameters in the TIM_OCInitStruct.
 518→  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
 519→  * @param  TIM_OCInitStruct: pointer to a TIM_OCInitTypeDef structure
 520→  *         that contains the configuration information for the specified TIM peripheral.
 521→  * @retval None
 522→  */
 523→void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
 524→{
 525→  uint16_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;
 526→   
 527→  /* Check the parameters */
 528→  assert_param(IS_TIM_LIST3_PERIPH(TIMx)); 
 529→  assert_param(IS_TIM_OC_MODE(TIM_OCInitStruct->TIM_OCMode));
 530→  assert_param(IS_TIM_OUTPUT_STATE(TIM_OCInitStruct->TIM_OutputState));
 531→  assert_param(IS_TIM_OC_POLARITY(TIM_OCInitStruct->TIM_OCPolarity));   
 532→  /* Disable the Channel 2: Reset the CC4E Bit */
 533→  TIMx->CCER &= (uint16_t)(~((uint16_t)TIM_CCER_CC4E));
 534→  
 535→  /* Get the TIMx CCER register value */
 536→  tmpccer = TIMx->CCER;
 537→  /* Get the TIMx CR2 register value */
 538→  tmpcr2 =  TIMx->CR2;
 539→  
 540→  /* Get the TIMx CCMR2 register value */
 541→  tmpccmrx = TIMx->CCMR2;
 542→    
 543→  /* Reset the Output Compare mode and Capture/Compare selection Bits */
 544→  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR2_OC4M));
 545→  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR2_CC4S));
 546→  
 547→  /* Select the Output Compare Mode */
 548→  tmpccmrx |= (uint16_t)(TIM_OCInitStruct->TIM_OCMode << 8);
 549→  
 550→  /* Reset the Output Polarity level */
 551→  tmpccer &= (uint16_t)(~((uint16_t)TIM_CCER_CC4P));
 552→  /* Set the Output Compare Polarity */
 553→  tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OCPolarity << 12);
 554→  
 555→  /* Set the Output State */
 556→  tmpccer |= (uint16_t)(TIM_OCInitStruct->TIM_OutputState << 12);
 557→    
 558→  if((TIMx == TIM1) || (TIMx == TIM8))
 559→  {
 560→    assert_param(IS_TIM_OCIDLE_STATE(TIM_OCInitStruct->TIM_OCIdleState));
 561→    /* Reset the Output Compare IDLE State */
 562→    tmpcr2 &= (uint16_t)(~((uint16_t)TIM_CR2_OIS4));
 563→    /* Set the Output Idle state */
 564→    tmpcr2 |= (uint16_t)(TIM_OCInitStruct->TIM_OCIdleState << 6);
 565→  }
 566→  /* Write to TIMx CR2 */
 567→  TIMx->CR2 = tmpcr2;
 568→  
 569→  /* Write to TIMx CCMR2 */  
 570→  TIMx->CCMR2 = tmpccmrx;
 571→
 572→  /* Set the Capture Compare Register value */
 573→  TIMx->CCR4 = TIM_OCInitStruct->TIM_Pulse;
 574→  
 575→  /* Write to TIMx CCER */
 576→  TIMx->CCER = tmpccer;
 577→}
 578→
 579→/**
 580→  * @brief  Initializes the TIM peripheral according to the specified
 581→  *         parameters in the TIM_ICInitStruct.
 582→  * @param  TIMx: where x can be  1 to 17 except 6 and 7 to select the TIM peripheral.
 583→  * @param  TIM_ICInitStruct: pointer to a TIM_ICInitTypeDef structure
 584→  *         that contains the configuration information for the specified TIM peripheral.
 585→  * @retval None
 586→  */
 587→void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct)
 588→{
 589→  /* Check the parameters */
 590→  assert_param(IS_TIM_CHANNEL(TIM_ICInitStruct->TIM_Channel));  
 591→  assert_param(IS_TIM_IC_SELECTION(TIM_ICInitStruct->TIM_ICSelection));
 592→  assert_param(IS_TIM_IC_PRESCALER(TIM_ICInitStruct->TIM_ICPrescaler));
 593→  assert_param(IS_TIM_IC_FILTER(TIM_ICInitStruct->TIM_ICFilter));
 594→  
 595→  if((TIMx == TIM1) || (TIMx == TIM8) || (TIMx == TIM2) || (TIMx == TIM3) ||
 596→     (TIMx == TIM4) ||(TIMx == TIM5))
 597→  {
 598→    assert_param(IS_TIM_IC_POLARITY(TIM_ICInitStruct->TIM_ICPolarity));
 599→  }
 600→  else
 601→  {
 602→    assert_param(IS_TIM_IC_POLARITY_LITE(TIM_ICInitStruct->TIM_ICPolarity));
 603→  }
 604→  if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_1)
 605→  {
 606→    assert_param(IS_TIM_LIST8_PERIPH(TIMx));
 607→    /* TI1 Configuration */
 608→    TI1_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
 609→               TIM_ICInitStruct->TIM_ICSelection,
 610→               TIM_ICInitStruct->TIM_ICFilter);
 611→    /* Set the Input Capture Prescaler value */
 612→    TIM_SetIC1Prescaler(TIMx, TIM_ICInitStruct->TIM_ICPrescaler);
 613→  }
 614→  else if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_2)
 615→  {
 616→    assert_param(IS_TIM_LIST6_PERIPH(TIMx));
 617→    /* TI2 Configuration */
 618→    TI2_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
 619→               TIM_ICInitStruct->TIM_ICSelection,
 620→               TIM_ICInitStruct->TIM_ICFilter);
 621→    /* Set the Input Capture Prescaler value */
 622→    TIM_SetIC2Prescaler(TIMx, TIM_ICInitStruct->TIM_ICPrescaler);
 623→  }
 624→  else if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_3)
 625→  {
 626→    assert_param(IS_TIM_LIST3_PERIPH(TIMx));
 627→    /* TI3 Configuration */
 628→    TI3_Config(TIMx,  TIM_ICInitStruct->TIM_ICPolarity,
 629→               TIM_ICInitStruct->TIM_ICSelection,
 630→               TIM_ICInitStruct->TIM_ICFilter);
 631→    /* Set the Input Capture Prescaler value */
 632→    TIM_SetIC3Prescaler(TIMx, TIM_ICInitStruct->TIM_ICPrescaler);
 633→  }
 634→  else
 635→  {
 636→    assert_param(IS_TIM_LIST3_PERIPH(TIMx));
 637→    /* TI4 Configuration */
 638→    TI4_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
 639→               TIM_ICInitStruct->TIM_ICSelection,
 640→               TIM_ICInitStruct->TIM_ICFilter);
 641→    /* Set the Input Capture Prescaler value */
 642→    TIM_SetIC4Prescaler(TIMx, TIM_ICInitStruct->TIM_ICPrescaler);
 643→  }
 644→}
 645→
 646→/**
 647→  * @brief  Configures the TIM peripheral according to the specified
 648→  *         parameters in the TIM_ICInitStruct to measure an external PWM signal.
 649→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 8, 9, 12 or 15 to select the TIM peripheral.
 650→  * @param  TIM_ICInitStruct: pointer to a TIM_ICInitTypeDef structure
 651→  *         that contains the configuration information for the specified TIM peripheral.
 652→  * @retval None
 653→  */
 654→void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct)
 655→{
 656→  uint16_t icoppositepolarity = TIM_ICPolarity_Rising;
 657→  uint16_t icoppositeselection = TIM_ICSelection_DirectTI;
 658→  /* Check the parameters */
 659→  assert_param(IS_TIM_LIST6_PERIPH(TIMx));
 660→  /* Select the Opposite Input Polarity */
 661→  if (TIM_ICInitStruct->TIM_ICPolarity == TIM_ICPolarity_Rising)
 662→  {
 663→    icoppositepolarity = TIM_ICPolarity_Falling;
 664→  }
 665→  else
 666→  {
 667→    icoppositepolarity = TIM_ICPolarity_Rising;
 668→  }
 669→  /* Select the Opposite Input */
 670→  if (TIM_ICInitStruct->TIM_ICSelection == TIM_ICSelection_DirectTI)
 671→  {
 672→    icoppositeselection = TIM_ICSelection_IndirectTI;
 673→  }
 674→  else
 675→  {
 676→    icoppositeselection = TIM_ICSelection_DirectTI;
 677→  }
 678→  if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_1)
 679→  {
 680→    /* TI1 Configuration */
 681→    TI1_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity, TIM_ICInitStruct->TIM_ICSelection,
 682→               TIM_ICInitStruct->TIM_ICFilter);
 683→    /* Set the Input Capture Prescaler value */
 684→    TIM_SetIC1Prescaler(TIMx, TIM_ICInitStruct->TIM_ICPrescaler);
 685→    /* TI2 Configuration */
 686→    TI2_Config(TIMx, icoppositepolarity, icoppositeselection, TIM_ICInitStruct->TIM_ICFilter);
 687→    /* Set the Input Capture Prescaler value */
 688→    TIM_SetIC2Prescaler(TIMx, TIM_ICInitStruct->TIM_ICPrescaler);
 689→  }
 690→  else
 691→  { 
 692→    /* TI2 Configuration */
 693→    TI2_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity, TIM_ICInitStruct->TIM_ICSelection,
 694→               TIM_ICInitStruct->TIM_ICFilter);
 695→    /* Set the Input Capture Prescaler value */
 696→    TIM_SetIC2Prescaler(TIMx, TIM_ICInitStruct->TIM_ICPrescaler);
 697→    /* TI1 Configuration */
 698→    TI1_Config(TIMx, icoppositepolarity, icoppositeselection, TIM_ICInitStruct->TIM_ICFilter);
 699→    /* Set the Input Capture Prescaler value */
 700→    TIM_SetIC1Prescaler(TIMx, TIM_ICInitStruct->TIM_ICPrescaler);
 701→  }
 702→}
 703→
 704→/**
 705→  * @brief  Configures the: Break feature, dead time, Lock level, the OSSI,
 706→  *         the OSSR State and the AOE(automatic output enable).
 707→  * @param  TIMx: where x can be  1 or 8 to select the TIM 
 708→  * @param  TIM_BDTRInitStruct: pointer to a TIM_BDTRInitTypeDef structure that
 709→  *         contains the BDTR Register configuration  information for the TIM peripheral.
 710→  * @retval None
 711→  */
 712→void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct)
 713→{
 714→  /* Check the parameters */
 715→  assert_param(IS_TIM_LIST2_PERIPH(TIMx));
 716→  assert_param(IS_TIM_OSSR_STATE(TIM_BDTRInitStruct->TIM_OSSRState));
 717→  assert_param(IS_TIM_OSSI_STATE(TIM_BDTRInitStruct->TIM_OSSIState));
 718→  assert_param(IS_TIM_LOCK_LEVEL(TIM_BDTRInitStruct->TIM_LOCKLevel));
 719→  assert_param(IS_TIM_BREAK_STATE(TIM_BDTRInitStruct->TIM_Break));
 720→  assert_param(IS_TIM_BREAK_POLARITY(TIM_BDTRInitStruct->TIM_BreakPolarity));
 721→  assert_param(IS_TIM_AUTOMATIC_OUTPUT_STATE(TIM_BDTRInitStruct->TIM_AutomaticOutput));
 722→  /* Set the Lock level, the Break enable Bit and the Ploarity, the OSSR State,
 723→     the OSSI State, the dead time value and the Automatic Output Enable Bit */
 724→  TIMx->BDTR = (uint32_t)TIM_BDTRInitStruct->TIM_OSSRState | TIM_BDTRInitStruct->TIM_OSSIState |
 725→             TIM_BDTRInitStruct->TIM_LOCKLevel | TIM_BDTRInitStruct->TIM_DeadTime |
 726→             TIM_BDTRInitStruct->TIM_Break | TIM_BDTRInitStruct->TIM_BreakPolarity |
 727→             TIM_BDTRInitStruct->TIM_AutomaticOutput;
 728→}
 729→
 730→/**
 731→  * @brief  Fills each TIM_TimeBaseInitStruct member with its default value.
 732→  * @param  TIM_TimeBaseInitStruct : pointer to a TIM_TimeBaseInitTypeDef
 733→  *         structure which will be initialized.
 734→  * @retval None
 735→  */
 736→void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
 737→{
 738→  /* Set the default configuration */
 739→  TIM_TimeBaseInitStruct->TIM_Period = 0xFFFF;
 740→  TIM_TimeBaseInitStruct->TIM_Prescaler = 0x0000;
 741→  TIM_TimeBaseInitStruct->TIM_ClockDivision = TIM_CKD_DIV1;
 742→  TIM_TimeBaseInitStruct->TIM_CounterMode = TIM_CounterMode_Up;
 743→  TIM_TimeBaseInitStruct->TIM_RepetitionCounter = 0x0000;
 744→}
 745→
 746→/**
 747→  * @brief  Fills each TIM_OCInitStruct member with its default value.
 748→  * @param  TIM_OCInitStruct : pointer to a TIM_OCInitTypeDef structure which will
 749→  *         be initialized.
 750→  * @retval None
 751→  */
 752→void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct)
 753→{
 754→  /* Set the default configuration */
 755→  TIM_OCInitStruct->TIM_OCMode = TIM_OCMode_Timing;
 756→  TIM_OCInitStruct->TIM_OutputState = TIM_OutputState_Disable;
 757→  TIM_OCInitStruct->TIM_OutputNState = TIM_OutputNState_Disable;
 758→  TIM_OCInitStruct->TIM_Pulse = 0x0000;
 759→  TIM_OCInitStruct->TIM_OCPolarity = TIM_OCPolarity_High;
 760→  TIM_OCInitStruct->TIM_OCNPolarity = TIM_OCPolarity_High;
 761→  TIM_OCInitStruct->TIM_OCIdleState = TIM_OCIdleState_Reset;
 762→  TIM_OCInitStruct->TIM_OCNIdleState = TIM_OCNIdleState_Reset;
 763→}
 764→
 765→/**
 766→  * @brief  Fills each TIM_ICInitStruct member with its default value.
 767→  * @param  TIM_ICInitStruct: pointer to a TIM_ICInitTypeDef structure which will
 768→  *         be initialized.
 769→  * @retval None
 770→  */
 771→void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct)
 772→{
 773→  /* Set the default configuration */
 774→  TIM_ICInitStruct->TIM_Channel = TIM_Channel_1;
 775→  TIM_ICInitStruct->TIM_ICPolarity = TIM_ICPolarity_Rising;
 776→  TIM_ICInitStruct->TIM_ICSelection = TIM_ICSelection_DirectTI;
 777→  TIM_ICInitStruct->TIM_ICPrescaler = TIM_ICPSC_DIV1;
 778→  TIM_ICInitStruct->TIM_ICFilter = 0x00;
 779→}
 780→
 781→/**
 782→  * @brief  Fills each TIM_BDTRInitStruct member with its default value.
 783→  * @param  TIM_BDTRInitStruct: pointer to a TIM_BDTRInitTypeDef structure which
 784→  *         will be initialized.
 785→  * @retval None
 786→  */
 787→void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct)
 788→{
 789→  /* Set the default configuration */
 790→  TIM_BDTRInitStruct->TIM_OSSRState = TIM_OSSRState_Disable;
 791→  TIM_BDTRInitStruct->TIM_OSSIState = TIM_OSSIState_Disable;
 792→  TIM_BDTRInitStruct->TIM_LOCKLevel = TIM_LOCKLevel_OFF;
 793→  TIM_BDTRInitStruct->TIM_DeadTime = 0x00;
 794→  TIM_BDTRInitStruct->TIM_Break = TIM_Break_Disable;
 795→  TIM_BDTRInitStruct->TIM_BreakPolarity = TIM_BreakPolarity_Low;
 796→  TIM_BDTRInitStruct->TIM_AutomaticOutput = TIM_AutomaticOutput_Disable;
 797→}
 798→
 799→/**
 800→  * @brief  Enables or disables the specified TIM peripheral.
 801→  * @param  TIMx: where x can be 1 to 17 to select the TIMx peripheral.
 802→  * @param  NewState: new state of the TIMx peripheral.
 803→  *   This parameter can be: ENABLE or DISABLE.
 804→  * @retval None
 805→  */
 806→void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState)
 807→{
 808→  /* Check the parameters */
 809→  assert_param(IS_TIM_ALL_PERIPH(TIMx));
 810→  assert_param(IS_FUNCTIONAL_STATE(NewState));
 811→  
 812→  if (NewState != DISABLE)
 813→  {
 814→    /* Enable the TIM Counter */
 815→    TIMx->CR1 |= TIM_CR1_CEN;
 816→  }
 817→  else
 818→  {
 819→    /* Disable the TIM Counter */
 820→    TIMx->CR1 &= (uint16_t)(~((uint16_t)TIM_CR1_CEN));
 821→  }
 822→}
 823→
 824→/**
 825→  * @brief  Enables or disables the TIM peripheral Main Outputs.
 826→  * @param  TIMx: where x can be 1, 8, 15, 16 or 17 to select the TIMx peripheral.
 827→  * @param  NewState: new state of the TIM peripheral Main Outputs.
 828→  *   This parameter can be: ENABLE or DISABLE.
 829→  * @retval None
 830→  */
 831→void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState)
 832→{
 833→  /* Check the parameters */
 834→  assert_param(IS_TIM_LIST2_PERIPH(TIMx));
 835→  assert_param(IS_FUNCTIONAL_STATE(NewState));
 836→  if (NewState != DISABLE)
 837→  {
 838→    /* Enable the TIM Main Output */
 839→    TIMx->BDTR |= TIM_BDTR_MOE;
 840→  }
 841→  else
 842→  {
 843→    /* Disable the TIM Main Output */
 844→    TIMx->BDTR &= (uint16_t)(~((uint16_t)TIM_BDTR_MOE));
 845→  }  
 846→}
 847→
 848→/**
 849→  * @brief  Enables or disables the specified TIM interrupts.
 850→  * @param  TIMx: where x can be 1 to 17 to select the TIMx peripheral.
 851→  * @param  TIM_IT: specifies the TIM interrupts sources to be enabled or disabled.
 852→  *   This parameter can be any combination of the following values:
 853→  *     @arg TIM_IT_Update: TIM update Interrupt source
 854→  *     @arg TIM_IT_CC1: TIM Capture Compare 1 Interrupt source
 855→  *     @arg TIM_IT_CC2: TIM Capture Compare 2 Interrupt source
 856→  *     @arg TIM_IT_CC3: TIM Capture Compare 3 Interrupt source
 857→  *     @arg TIM_IT_CC4: TIM Capture Compare 4 Interrupt source
 858→  *     @arg TIM_IT_COM: TIM Commutation Interrupt source
 859→  *     @arg TIM_IT_Trigger: TIM Trigger Interrupt source
 860→  *     @arg TIM_IT_Break: TIM Break Interrupt source
 861→  * @note 
 862→  *   - TIM6 and TIM7 can only generate an update interrupt.
 863→  *   - TIM9, TIM12 and TIM15 can have only TIM_IT_Update, TIM_IT_CC1,
 864→  *      TIM_IT_CC2 or TIM_IT_Trigger. 
 865→  *   - TIM10, TIM11, TIM13, TIM14, TIM16 and TIM17 can have TIM_IT_Update or TIM_IT_CC1.   
 866→  *   - TIM_IT_Break is used only with TIM1, TIM8 and TIM15. 
 867→  *   - TIM_IT_COM is used only with TIM1, TIM8, TIM15, TIM16 and TIM17.    
 868→  * @param  NewState: new state of the TIM interrupts.
 869→  *   This parameter can be: ENABLE or DISABLE.
 870→  * @retval None
 871→  */
 872→void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState)
 873→{  
 874→  /* Check the parameters */
 875→  assert_param(IS_TIM_ALL_PERIPH(TIMx));
 876→  assert_param(IS_TIM_IT(TIM_IT));
 877→  assert_param(IS_FUNCTIONAL_STATE(NewState));
 878→  
 879→  if (NewState != DISABLE)
 880→  {
 881→    /* Enable the Interrupt sources */
 882→    TIMx->DIER |= TIM_IT;
 883→  }
 884→  else
 885→  {
 886→    /* Disable the Interrupt sources */
 887→    TIMx->DIER &= (uint16_t)~TIM_IT;
 888→  }
 889→}
 890→
 891→/**
 892→  * @brief  Configures the TIMx event to be generate by software.
 893→  * @param  TIMx: where x can be 1 to 17 to select the TIM peripheral.
 894→  * @param  TIM_EventSource: specifies the event source.
 895→  *   This parameter can be one or more of the following values:	   
 896→  *     @arg TIM_EventSource_Update: Timer update Event source
 897→  *     @arg TIM_EventSource_CC1: Timer Capture Compare 1 Event source
 898→  *     @arg TIM_EventSource_CC2: Timer Capture Compare 2 Event source
 899→  *     @arg TIM_EventSource_CC3: Timer Capture Compare 3 Event source
 900→  *     @arg TIM_EventSource_CC4: Timer Capture Compare 4 Event source
 901→  *     @arg TIM_EventSource_COM: Timer COM event source  
 902→  *     @arg TIM_EventSource_Trigger: Timer Trigger Event source
 903→  *     @arg TIM_EventSource_Break: Timer Break event source
 904→  * @note 
 905→  *   - TIM6 and TIM7 can only generate an update event. 
 906→  *   - TIM_EventSource_COM and TIM_EventSource_Break are used only with TIM1 and TIM8.      
 907→  * @retval None
 908→  */
 909→void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource)
 910→{ 
 911→  /* Check the parameters */
 912→  assert_param(IS_TIM_ALL_PERIPH(TIMx));
 913→  assert_param(IS_TIM_EVENT_SOURCE(TIM_EventSource));
 914→  
 915→  /* Set the event sources */
 916→  TIMx->EGR = TIM_EventSource;
 917→}
 918→
 919→/**
 920→  * @brief  Configures the TIMx's DMA interface.
 921→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 8, 15, 16 or 17 to select 
 922→  *   the TIM peripheral.
 923→  * @param  TIM_DMABase: DMA Base address.
 924→  *   This parameter can be one of the following values:
 925→  *     @arg TIM_DMABase_CR, TIM_DMABase_CR2, TIM_DMABase_SMCR,
 926→  *          TIM_DMABase_DIER, TIM1_DMABase_SR, TIM_DMABase_EGR,
 927→  *          TIM_DMABase_CCMR1, TIM_DMABase_CCMR2, TIM_DMABase_CCER,
 928→  *          TIM_DMABase_CNT, TIM_DMABase_PSC, TIM_DMABase_ARR,
 929→  *          TIM_DMABase_RCR, TIM_DMABase_CCR1, TIM_DMABase_CCR2,
 930→  *          TIM_DMABase_CCR3, TIM_DMABase_CCR4, TIM_DMABase_BDTR,
 931→  *          TIM_DMABase_DCR.
 932→  * @param  TIM_DMABurstLength: DMA Burst length.
 933→  *   This parameter can be one value between:
 934→  *   TIM_DMABurstLength_1Transfer and TIM_DMABurstLength_18Transfers.
 935→  * @retval None
 936→  */
 937→void TIM_DMAConfig(TIM_TypeDef* TIMx, uint16_t TIM_DMABase, uint16_t TIM_DMABurstLength)
 938→{
 939→  /* Check the parameters */
 940→  assert_param(IS_TIM_LIST4_PERIPH(TIMx));
 941→  assert_param(IS_TIM_DMA_BASE(TIM_DMABase));
 942→  assert_param(IS_TIM_DMA_LENGTH(TIM_DMABurstLength));
 943→  /* Set the DMA Base and the DMA Burst Length */
 944→  TIMx->DCR = TIM_DMABase | TIM_DMABurstLength;
 945→}
 946→
 947→/**
 948→  * @brief  Enables or disables the TIMx's DMA Requests.
 949→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 6, 7, 8, 15, 16 or 17 
 950→  *   to select the TIM peripheral. 
 951→  * @param  TIM_DMASource: specifies the DMA Request sources.
 952→  *   This parameter can be any combination of the following values:
 953→  *     @arg TIM_DMA_Update: TIM update Interrupt source
 954→  *     @arg TIM_DMA_CC1: TIM Capture Compare 1 DMA source
 955→  *     @arg TIM_DMA_CC2: TIM Capture Compare 2 DMA source
 956→  *     @arg TIM_DMA_CC3: TIM Capture Compare 3 DMA source
 957→  *     @arg TIM_DMA_CC4: TIM Capture Compare 4 DMA source
 958→  *     @arg TIM_DMA_COM: TIM Commutation DMA source
 959→  *     @arg TIM_DMA_Trigger: TIM Trigger DMA source
 960→  * @param  NewState: new state of the DMA Request sources.
 961→  *   This parameter can be: ENABLE or DISABLE.
 962→  * @retval None
 963→  */
 964→void TIM_DMACmd(TIM_TypeDef* TIMx, uint16_t TIM_DMASource, FunctionalState NewState)
 965→{ 
 966→  /* Check the parameters */
 967→  assert_param(IS_TIM_LIST9_PERIPH(TIMx));
 968→  assert_param(IS_TIM_DMA_SOURCE(TIM_DMASource));
 969→  assert_param(IS_FUNCTIONAL_STATE(NewState));
 970→  
 971→  if (NewState != DISABLE)
 972→  {
 973→    /* Enable the DMA sources */
 974→    TIMx->DIER |= TIM_DMASource; 
 975→  }
 976→  else
 977→  {
 978→    /* Disable the DMA sources */
 979→    TIMx->DIER &= (uint16_t)~TIM_DMASource;
 980→  }
 981→}
 982→
 983→/**
 984→  * @brief  Configures the TIMx internal Clock
 985→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 8, 9, 12 or 15
 986→  *         to select the TIM peripheral.
 987→  * @retval None
 988→  */
 989→void TIM_InternalClockConfig(TIM_TypeDef* TIMx)
 990→{
 991→  /* Check the parameters */
 992→  assert_param(IS_TIM_LIST6_PERIPH(TIMx));
 993→  /* Disable slave mode to clock the prescaler directly with the internal clock */
 994→  TIMx->SMCR &=  (uint16_t)(~((uint16_t)TIM_SMCR_SMS));
 995→}
 996→
 997→/**
 998→  * @brief  Configures the TIMx Internal Trigger as External Clock
 999→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 9, 12 or 15 to select the TIM peripheral.
1000→  * @param  TIM_ITRSource: Trigger source.
1001→  *   This parameter can be one of the following values:
1002→  * @param  TIM_TS_ITR0: Internal Trigger 0
1003→  * @param  TIM_TS_ITR1: Internal Trigger 1
1004→  * @param  TIM_TS_ITR2: Internal Trigger 2
1005→  * @param  TIM_TS_ITR3: Internal Trigger 3
1006→  * @retval None
1007→  */
1008→void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource)
1009→{
1010→  /* Check the parameters */
1011→  assert_param(IS_TIM_LIST6_PERIPH(TIMx));
1012→  assert_param(IS_TIM_INTERNAL_TRIGGER_SELECTION(TIM_InputTriggerSource));
1013→  /* Select the Internal Trigger */
1014→  TIM_SelectInputTrigger(TIMx, TIM_InputTriggerSource);
1015→  /* Select the External clock mode1 */
1016→  TIMx->SMCR |= TIM_SlaveMode_External1;
1017→}
1018→
1019→/**
1020→  * @brief  Configures the TIMx Trigger as External Clock
1021→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 9, 12 or 15 to select the TIM peripheral.
1022→  * @param  TIM_TIxExternalCLKSource: Trigger source.
1023→  *   This parameter can be one of the following values:
1024→  *     @arg TIM_TIxExternalCLK1Source_TI1ED: TI1 Edge Detector
1025→  *     @arg TIM_TIxExternalCLK1Source_TI1: Filtered Timer Input 1
1026→  *     @arg TIM_TIxExternalCLK1Source_TI2: Filtered Timer Input 2
1027→  * @param  TIM_ICPolarity: specifies the TIx Polarity.
1028→  *   This parameter can be one of the following values:
1029→  *     @arg TIM_ICPolarity_Rising
1030→  *     @arg TIM_ICPolarity_Falling
1031→  * @param  ICFilter : specifies the filter value.
1032→  *   This parameter must be a value between 0x0 and 0xF.
1033→  * @retval None
1034→  */
1035→void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
1036→                                uint16_t TIM_ICPolarity, uint16_t ICFilter)
1037→{
1038→  /* Check the parameters */
1039→  assert_param(IS_TIM_LIST6_PERIPH(TIMx));
1040→  assert_param(IS_TIM_TIXCLK_SOURCE(TIM_TIxExternalCLKSource));
1041→  assert_param(IS_TIM_IC_POLARITY(TIM_ICPolarity));
1042→  assert_param(IS_TIM_IC_FILTER(ICFilter));
1043→  /* Configure the Timer Input Clock Source */
1044→  if (TIM_TIxExternalCLKSource == TIM_TIxExternalCLK1Source_TI2)
1045→  {
1046→    TI2_Config(TIMx, TIM_ICPolarity, TIM_ICSelection_DirectTI, ICFilter);
1047→  }
1048→  else
1049→  {
1050→    TI1_Config(TIMx, TIM_ICPolarity, TIM_ICSelection_DirectTI, ICFilter);
1051→  }
1052→  /* Select the Trigger source */
1053→  TIM_SelectInputTrigger(TIMx, TIM_TIxExternalCLKSource);
1054→  /* Select the External clock mode1 */
1055→  TIMx->SMCR |= TIM_SlaveMode_External1;
1056→}
1057→
1058→/**
1059→  * @brief  Configures the External clock Mode1
1060→  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
1061→  * @param  TIM_ExtTRGPrescaler: The external Trigger Prescaler.
1062→  *   This parameter can be one of the following values:
1063→  *     @arg TIM_ExtTRGPSC_OFF: ETRP Prescaler OFF.
1064→  *     @arg TIM_ExtTRGPSC_DIV2: ETRP frequency divided by 2.
1065→  *     @arg TIM_ExtTRGPSC_DIV4: ETRP frequency divided by 4.
1066→  *     @arg TIM_ExtTRGPSC_DIV8: ETRP frequency divided by 8.
1067→  * @param  TIM_ExtTRGPolarity: The external Trigger Polarity.
1068→  *   This parameter can be one of the following values:
1069→  *     @arg TIM_ExtTRGPolarity_Inverted: active low or falling edge active.
1070→  *     @arg TIM_ExtTRGPolarity_NonInverted: active high or rising edge active.
1071→  * @param  ExtTRGFilter: External Trigger Filter.
1072→  *   This parameter must be a value between 0x00 and 0x0F
1073→  * @retval None
1074→  */
1075→void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
1076→                             uint16_t ExtTRGFilter)
1077→{
1078→  uint16_t tmpsmcr = 0;
1079→  /* Check the parameters */
1080→  assert_param(IS_TIM_LIST3_PERIPH(TIMx));
1081→  assert_param(IS_TIM_EXT_PRESCALER(TIM_ExtTRGPrescaler));
1082→  assert_param(IS_TIM_EXT_POLARITY(TIM_ExtTRGPolarity));
1083→  assert_param(IS_TIM_EXT_FILTER(ExtTRGFilter));
1084→  /* Configure the ETR Clock source */
1085→  TIM_ETRConfig(TIMx, TIM_ExtTRGPrescaler, TIM_ExtTRGPolarity, ExtTRGFilter);
1086→  
1087→  /* Get the TIMx SMCR register value */
1088→  tmpsmcr = TIMx->SMCR;
1089→  /* Reset the SMS Bits */
1090→  tmpsmcr &= (uint16_t)(~((uint16_t)TIM_SMCR_SMS));
1091→  /* Select the External clock mode1 */
1092→  tmpsmcr |= TIM_SlaveMode_External1;
1093→  /* Select the Trigger selection : ETRF */
1094→  tmpsmcr &= (uint16_t)(~((uint16_t)TIM_SMCR_TS));
1095→  tmpsmcr |= TIM_TS_ETRF;
1096→  /* Write to TIMx SMCR */
1097→  TIMx->SMCR = tmpsmcr;
1098→}
1099→
1100→/**
1101→  * @brief  Configures the External clock Mode2
1102→  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
1103→  * @param  TIM_ExtTRGPrescaler: The external Trigger Prescaler.
1104→  *   This parameter can be one of the following values:
1105→  *     @arg TIM_ExtTRGPSC_OFF: ETRP Prescaler OFF.
1106→  *     @arg TIM_ExtTRGPSC_DIV2: ETRP frequency divided by 2.
1107→  *     @arg TIM_ExtTRGPSC_DIV4: ETRP frequency divided by 4.
1108→  *     @arg TIM_ExtTRGPSC_DIV8: ETRP frequency divided by 8.
1109→  * @param  TIM_ExtTRGPolarity: The external Trigger Polarity.
1110→  *   This parameter can be one of the following values:
1111→  *     @arg TIM_ExtTRGPolarity_Inverted: active low or falling edge active.
1112→  *     @arg TIM_ExtTRGPolarity_NonInverted: active high or rising edge active.
1113→  * @param  ExtTRGFilter: External Trigger Filter.
1114→  *   This parameter must be a value between 0x00 and 0x0F
1115→  * @retval None
1116→  */
1117→void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
1118→                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter)
1119→{
1120→  /* Check the parameters */
1121→  assert_param(IS_TIM_LIST3_PERIPH(TIMx));
1122→  assert_param(IS_TIM_EXT_PRESCALER(TIM_ExtTRGPrescaler));
1123→  assert_param(IS_TIM_EXT_POLARITY(TIM_ExtTRGPolarity));
1124→  assert_param(IS_TIM_EXT_FILTER(ExtTRGFilter));
1125→  /* Configure the ETR Clock source */
1126→  TIM_ETRConfig(TIMx, TIM_ExtTRGPrescaler, TIM_ExtTRGPolarity, ExtTRGFilter);
1127→  /* Enable the External clock mode2 */
1128→  TIMx->SMCR |= TIM_SMCR_ECE;
1129→}
1130→
1131→/**
1132→  * @brief  Configures the TIMx External Trigger (ETR).
1133→  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
1134→  * @param  TIM_ExtTRGPrescaler: The external Trigger Prescaler.
1135→  *   This parameter can be one of the following values:
1136→  *     @arg TIM_ExtTRGPSC_OFF: ETRP Prescaler OFF.
1137→  *     @arg TIM_ExtTRGPSC_DIV2: ETRP frequency divided by 2.
1138→  *     @arg TIM_ExtTRGPSC_DIV4: ETRP frequency divided by 4.
1139→  *     @arg TIM_ExtTRGPSC_DIV8: ETRP frequency divided by 8.
1140→  * @param  TIM_ExtTRGPolarity: The external Trigger Polarity.
1141→  *   This parameter can be one of the following values:
1142→  *     @arg TIM_ExtTRGPolarity_Inverted: active low or falling edge active.
1143→  *     @arg TIM_ExtTRGPolarity_NonInverted: active high or rising edge active.
1144→  * @param  ExtTRGFilter: External Trigger Filter.
1145→  *   This parameter must be a value between 0x00 and 0x0F
1146→  * @retval None
1147→  */
1148→void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
1149→                   uint16_t ExtTRGFilter)
1150→{
1151→  uint16_t tmpsmcr = 0;
1152→  /* Check the parameters */
1153→  assert_param(IS_TIM_LIST3_PERIPH(TIMx));
1154→  assert_param(IS_TIM_EXT_PRESCALER(TIM_ExtTRGPrescaler));
1155→  assert_param(IS_TIM_EXT_POLARITY(TIM_ExtTRGPolarity));
1156→  assert_param(IS_TIM_EXT_FILTER(ExtTRGFilter));
1157→  tmpsmcr = TIMx->SMCR;
1158→  /* Reset the ETR Bits */
1159→  tmpsmcr &= SMCR_ETR_Mask;
1160→  /* Set the Prescaler, the Filter value and the Polarity */
1161→  tmpsmcr |= (uint16_t)(TIM_ExtTRGPrescaler | (uint16_t)(TIM_ExtTRGPolarity | (uint16_t)(ExtTRGFilter << (uint16_t)8)));
1162→  /* Write to TIMx SMCR */
1163→  TIMx->SMCR = tmpsmcr;
1164→}
1165→
1166→/**
1167→  * @brief  Configures the TIMx Prescaler.
1168→  * @param  TIMx: where x can be 1 to 17 to select the TIM peripheral.
1169→  * @param  Prescaler: specifies the Prescaler Register value
1170→  * @param  TIM_PSCReloadMode: specifies the TIM Prescaler Reload mode
1171→  *   This parameter can be one of the following values:
1172→  *     @arg TIM_PSCReloadMode_Update: The Prescaler is loaded at the update event.
1173→  *     @arg TIM_PSCReloadMode_Immediate: The Prescaler is loaded immediately.
1174→  * @retval None
1175→  */
1176→void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode)
1177→{
1178→  /* Check the parameters */
1179→  assert_param(IS_TIM_ALL_PERIPH(TIMx));
1180→  assert_param(IS_TIM_PRESCALER_RELOAD(TIM_PSCReloadMode));
1181→  /* Set the Prescaler value */
1182→  TIMx->PSC = Prescaler;
1183→  /* Set or reset the UG Bit */
1184→  TIMx->EGR = TIM_PSCReloadMode;
1185→}
1186→
1187→/**
1188→  * @brief  Specifies the TIMx Counter Mode to be used.
1189→  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
1190→  * @param  TIM_CounterMode: specifies the Counter Mode to be used
1191→  *   This parameter can be one of the following values:
1192→  *     @arg TIM_CounterMode_Up: TIM Up Counting Mode
1193→  *     @arg TIM_CounterMode_Down: TIM Down Counting Mode
1194→  *     @arg TIM_CounterMode_CenterAligned1: TIM Center Aligned Mode1
1195→  *     @arg TIM_CounterMode_CenterAligned2: TIM Center Aligned Mode2
1196→  *     @arg TIM_CounterMode_CenterAligned3: TIM Center Aligned Mode3
1197→  * @retval None
1198→  */
1199→void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode)
1200→{
1201→  uint16_t tmpcr1 = 0;
1202→  /* Check the parameters */
1203→  assert_param(IS_TIM_LIST3_PERIPH(TIMx));
1204→  assert_param(IS_TIM_COUNTER_MODE(TIM_CounterMode));
1205→  tmpcr1 = TIMx->CR1;
1206→  /* Reset the CMS and DIR Bits */
1207→  tmpcr1 &= (uint16_t)(~((uint16_t)(TIM_CR1_DIR | TIM_CR1_CMS)));
1208→  /* Set the Counter Mode */
1209→  tmpcr1 |= TIM_CounterMode;
1210→  /* Write to TIMx CR1 register */
1211→  TIMx->CR1 = tmpcr1;
1212→}
1213→
1214→/**
1215→  * @brief  Selects the Input Trigger source
1216→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 8, 9, 12 or 15 to select the TIM peripheral.
1217→  * @param  TIM_InputTriggerSource: The Input Trigger source.
1218→  *   This parameter can be one of the following values:
1219→  *     @arg TIM_TS_ITR0: Internal Trigger 0
1220→  *     @arg TIM_TS_ITR1: Internal Trigger 1
1221→  *     @arg TIM_TS_ITR2: Internal Trigger 2
1222→  *     @arg TIM_TS_ITR3: Internal Trigger 3
1223→  *     @arg TIM_TS_TI1F_ED: TI1 Edge Detector
1224→  *     @arg TIM_TS_TI1FP1: Filtered Timer Input 1
1225→  *     @arg TIM_TS_TI2FP2: Filtered Timer Input 2
1226→  *     @arg TIM_TS_ETRF: External Trigger input
1227→  * @retval None
1228→  */
1229→void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource)
1230→{
1231→  uint16_t tmpsmcr = 0;
1232→  /* Check the parameters */
1233→  assert_param(IS_TIM_LIST6_PERIPH(TIMx));
1234→  assert_param(IS_TIM_TRIGGER_SELECTION(TIM_InputTriggerSource));
1235→  /* Get the TIMx SMCR register value */
1236→  tmpsmcr = TIMx->SMCR;
1237→  /* Reset the TS Bits */
1238→  tmpsmcr &= (uint16_t)(~((uint16_t)TIM_SMCR_TS));
1239→  /* Set the Input Trigger source */
1240→  tmpsmcr |= TIM_InputTriggerSource;
1241→  /* Write to TIMx SMCR */
1242→  TIMx->SMCR = tmpsmcr;
1243→}
1244→
1245→/**
1246→  * @brief  Configures the TIMx Encoder Interface.
1247→  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
1248→  * @param  TIM_EncoderMode: specifies the TIMx Encoder Mode.
1249→  *   This parameter can be one of the following values:
1250→  *     @arg TIM_EncoderMode_TI1: Counter counts on TI1FP1 edge depending on TI2FP2 level.
1251→  *     @arg TIM_EncoderMode_TI2: Counter counts on TI2FP2 edge depending on TI1FP1 level.
1252→  *     @arg TIM_EncoderMode_TI12: Counter counts on both TI1FP1 and TI2FP2 edges depending
1253→  *                                on the level of the other input.
1254→  * @param  TIM_IC1Polarity: specifies the IC1 Polarity
1255→  *   This parameter can be one of the following values:
1256→  *     @arg TIM_ICPolarity_Falling: IC Falling edge.
1257→  *     @arg TIM_ICPolarity_Rising: IC Rising edge.
1258→  * @param  TIM_IC2Polarity: specifies the IC2 Polarity
1259→  *   This parameter can be one of the following values:
1260→  *     @arg TIM_ICPolarity_Falling: IC Falling edge.
1261→  *     @arg TIM_ICPolarity_Rising: IC Rising edge.
1262→  * @retval None
1263→  */
1264→void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
1265→                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity)
1266→{
1267→  uint16_t tmpsmcr = 0;
1268→  uint16_t tmpccmr1 = 0;
1269→  uint16_t tmpccer = 0;
1270→    
1271→  /* Check the parameters */
1272→  assert_param(IS_TIM_LIST5_PERIPH(TIMx));
1273→  assert_param(IS_TIM_ENCODER_MODE(TIM_EncoderMode));
1274→  assert_param(IS_TIM_IC_POLARITY(TIM_IC1Polarity));
1275→  assert_param(IS_TIM_IC_POLARITY(TIM_IC2Polarity));
1276→
1277→  /* Get the TIMx SMCR register value */
1278→  tmpsmcr = TIMx->SMCR;
1279→  
1280→  /* Get the TIMx CCMR1 register value */
1281→  tmpccmr1 = TIMx->CCMR1;
1282→  
1283→  /* Get the TIMx CCER register value */
1284→  tmpccer = TIMx->CCER;
1285→  
1286→  /* Set the encoder Mode */
1287→  tmpsmcr &= (uint16_t)(~((uint16_t)TIM_SMCR_SMS));
1288→  tmpsmcr |= TIM_EncoderMode;
1289→  
1290→  /* Select the Capture Compare 1 and the Capture Compare 2 as input */
1291→  tmpccmr1 &= (uint16_t)(((uint16_t)~((uint16_t)TIM_CCMR1_CC1S)) & (uint16_t)(~((uint16_t)TIM_CCMR1_CC2S)));
1292→  tmpccmr1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0;
1293→  
1294→  /* Set the TI1 and the TI2 Polarities */
1295→  tmpccer &= (uint16_t)(((uint16_t)~((uint16_t)TIM_CCER_CC1P)) & ((uint16_t)~((uint16_t)TIM_CCER_CC2P)));
1296→  tmpccer |= (uint16_t)(TIM_IC1Polarity | (uint16_t)(TIM_IC2Polarity << (uint16_t)4));
1297→  
1298→  /* Write to TIMx SMCR */
1299→  TIMx->SMCR = tmpsmcr;
1300→  /* Write to TIMx CCMR1 */
1301→  TIMx->CCMR1 = tmpccmr1;
1302→  /* Write to TIMx CCER */
1303→  TIMx->CCER = tmpccer;
1304→}
1305→
1306→/**
1307→  * @brief  Forces the TIMx output 1 waveform to active or inactive level.
1308→  * @param  TIMx: where x can be  1 to 17 except 6 and 7 to select the TIM peripheral.
1309→  * @param  TIM_ForcedAction: specifies the forced Action to be set to the output waveform.
1310→  *   This parameter can be one of the following values:
1311→  *     @arg TIM_ForcedAction_Active: Force active level on OC1REF
1312→  *     @arg TIM_ForcedAction_InActive: Force inactive level on OC1REF.
1313→  * @retval None
1314→  */
1315→void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction)
1316→{
1317→  uint16_t tmpccmr1 = 0;
1318→  /* Check the parameters */
1319→  assert_param(IS_TIM_LIST8_PERIPH(TIMx));
1320→  assert_param(IS_TIM_FORCED_ACTION(TIM_ForcedAction));
1321→  tmpccmr1 = TIMx->CCMR1;
1322→  /* Reset the OC1M Bits */
1323→  tmpccmr1 &= (uint16_t)~((uint16_t)TIM_CCMR1_OC1M);
1324→  /* Configure The Forced output Mode */
1325→  tmpccmr1 |= TIM_ForcedAction;
1326→  /* Write to TIMx CCMR1 register */
1327→  TIMx->CCMR1 = tmpccmr1;
1328→}
1329→
1330→/**
1331→  * @brief  Forces the TIMx output 2 waveform to active or inactive level.
1332→  * @param  TIMx: where x can be  1, 2, 3, 4, 5, 8, 9, 12 or 15 to select the TIM peripheral.
1333→  * @param  TIM_ForcedAction: specifies the forced Action to be set to the output waveform.
1334→  *   This parameter can be one of the following values:
1335→  *     @arg TIM_ForcedAction_Active: Force active level on OC2REF
1336→  *     @arg TIM_ForcedAction_InActive: Force inactive level on OC2REF.
1337→  * @retval None
1338→  */
1339→void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction)
1340→{
1341→  uint16_t tmpccmr1 = 0;
1342→  /* Check the parameters */
1343→  assert_param(IS_TIM_LIST6_PERIPH(TIMx));
1344→  assert_param(IS_TIM_FORCED_ACTION(TIM_ForcedAction));
1345→  tmpccmr1 = TIMx->CCMR1;
1346→  /* Reset the OC2M Bits */
1347→  tmpccmr1 &= (uint16_t)~((uint16_t)TIM_CCMR1_OC2M);
1348→  /* Configure The Forced output Mode */
1349→  tmpccmr1 |= (uint16_t)(TIM_ForcedAction << 8);
1350→  /* Write to TIMx CCMR1 register */
1351→  TIMx->CCMR1 = tmpccmr1;
1352→}
1353→
1354→/**
1355→  * @brief  Forces the TIMx output 3 waveform to active or inactive level.
1356→  * @param  TIMx: where x can be  1, 2, 3, 4, 5 or 8 to select the TIM peripheral.
1357→  * @param  TIM_ForcedAction: specifies the forced Action to be set to the output waveform.
1358→  *   This parameter can be one of the following values:
1359→  *     @arg TIM_ForcedAction_Active: Force active level on OC3REF
1360→  *     @arg TIM_ForcedAction_InActive: Force inactive level on OC3REF.
1361→  * @retval None
1362→  */
1363→void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction)
1364→{
1365→  uint16_t tmpccmr2 = 0;
1366→  /* Check the parameters */
1367→  assert_param(IS_TIM_LIST3_PERIPH(TIMx));
1368→  assert_param(IS_TIM_FORCED_ACTION(TIM_ForcedAction));
1369→  tmpccmr2 = TIMx->CCMR2;
1370→  /* Reset the OC1M Bits */
1371→  tmpccmr2 &= (uint16_t)~((uint16_t)TIM_CCMR2_OC3M);
1372→  /* Configure The Forced output Mode */