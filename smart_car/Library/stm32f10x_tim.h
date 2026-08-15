File content truncated due to size limit (50KB). First 50KB included below:

   1→/**
   2→  ******************************************************************************
   3→  * @file    stm32f10x_tim.h
   4→  * @author  MCD Application Team
   5→  * @version V3.5.0
   6→  * @date    11-March-2011
   7→  * @brief   This file contains all the functions prototypes for the TIM firmware 
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
  24→#ifndef __STM32F10x_TIM_H
  25→#define __STM32F10x_TIM_H
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
  38→/** @addtogroup TIM
  39→  * @{
  40→  */ 
  41→
  42→/** @defgroup TIM_Exported_Types
  43→  * @{
  44→  */ 
  45→
  46→/** 
  47→  * @brief  TIM Time Base Init structure definition
  48→  * @note   This structure is used with all TIMx except for TIM6 and TIM7.    
  49→  */
  50→
  51→typedef struct
  52→{
  53→  uint16_t TIM_Prescaler;         /*!< Specifies the prescaler value used to divide the TIM clock.
  54→                                       This parameter can be a number between 0x0000 and 0xFFFF */
  55→
  56→  uint16_t TIM_CounterMode;       /*!< Specifies the counter mode.
  57→                                       This parameter can be a value of @ref TIM_Counter_Mode */
  58→
  59→  uint16_t TIM_Period;            /*!< Specifies the period value to be loaded into the active
  60→                                       Auto-Reload Register at the next update event.
  61→                                       This parameter must be a number between 0x0000 and 0xFFFF.  */ 
  62→
  63→  uint16_t TIM_ClockDivision;     /*!< Specifies the clock division.
  64→                                      This parameter can be a value of @ref TIM_Clock_Division_CKD */
  65→
  66→  uint8_t TIM_RepetitionCounter;  /*!< Specifies the repetition counter value. Each time the RCR downcounter
  67→                                       reaches zero, an update event is generated and counting restarts
  68→                                       from the RCR value (N).
  69→                                       This means in PWM mode that (N+1) corresponds to:
  70→                                          - the number of PWM periods in edge-aligned mode
  71→                                          - the number of half PWM period in center-aligned mode
  72→                                       This parameter must be a number between 0x00 and 0xFF. 
  73→                                       @note This parameter is valid only for TIM1 and TIM8. */
  74→} TIM_TimeBaseInitTypeDef;       
  75→
  76→/** 
  77→  * @brief  TIM Output Compare Init structure definition  
  78→  */
  79→
  80→typedef struct
  81→{
  82→  uint16_t TIM_OCMode;        /*!< Specifies the TIM mode.
  83→                                   This parameter can be a value of @ref TIM_Output_Compare_and_PWM_modes */
  84→
  85→  uint16_t TIM_OutputState;   /*!< Specifies the TIM Output Compare state.
  86→                                   This parameter can be a value of @ref TIM_Output_Compare_state */
  87→
  88→  uint16_t TIM_OutputNState;  /*!< Specifies the TIM complementary Output Compare state.
  89→                                   This parameter can be a value of @ref TIM_Output_Compare_N_state
  90→                                   @note This parameter is valid only for TIM1 and TIM8. */
  91→
  92→  uint16_t TIM_Pulse;         /*!< Specifies the pulse value to be loaded into the Capture Compare Register. 
  93→                                   This parameter can be a number between 0x0000 and 0xFFFF */
  94→
  95→  uint16_t TIM_OCPolarity;    /*!< Specifies the output polarity.
  96→                                   This parameter can be a value of @ref TIM_Output_Compare_Polarity */
  97→
  98→  uint16_t TIM_OCNPolarity;   /*!< Specifies the complementary output polarity.
  99→                                   This parameter can be a value of @ref TIM_Output_Compare_N_Polarity
 100→                                   @note This parameter is valid only for TIM1 and TIM8. */
 101→
 102→  uint16_t TIM_OCIdleState;   /*!< Specifies the TIM Output Compare pin state during Idle state.
 103→                                   This parameter can be a value of @ref TIM_Output_Compare_Idle_State
 104→                                   @note This parameter is valid only for TIM1 and TIM8. */
 105→
 106→  uint16_t TIM_OCNIdleState;  /*!< Specifies the TIM Output Compare pin state during Idle state.
 107→                                   This parameter can be a value of @ref TIM_Output_Compare_N_Idle_State
 108→                                   @note This parameter is valid only for TIM1 and TIM8. */
 109→} TIM_OCInitTypeDef;
 110→
 111→/** 
 112→  * @brief  TIM Input Capture Init structure definition  
 113→  */
 114→
 115→typedef struct
 116→{
 117→
 118→  uint16_t TIM_Channel;      /*!< Specifies the TIM channel.
 119→                                  This parameter can be a value of @ref TIM_Channel */
 120→
 121→  uint16_t TIM_ICPolarity;   /*!< Specifies the active edge of the input signal.
 122→                                  This parameter can be a value of @ref TIM_Input_Capture_Polarity */
 123→
 124→  uint16_t TIM_ICSelection;  /*!< Specifies the input.
 125→                                  This parameter can be a value of @ref TIM_Input_Capture_Selection */
 126→
 127→  uint16_t TIM_ICPrescaler;  /*!< Specifies the Input Capture Prescaler.
 128→                                  This parameter can be a value of @ref TIM_Input_Capture_Prescaler */
 129→
 130→  uint16_t TIM_ICFilter;     /*!< Specifies the input capture filter.
 131→                                  This parameter can be a number between 0x0 and 0xF */
 132→} TIM_ICInitTypeDef;
 133→
 134→/** 
 135→  * @brief  BDTR structure definition 
 136→  * @note   This structure is used only with TIM1 and TIM8.    
 137→  */
 138→
 139→typedef struct
 140→{
 141→
 142→  uint16_t TIM_OSSRState;        /*!< Specifies the Off-State selection used in Run mode.
 143→                                      This parameter can be a value of @ref OSSR_Off_State_Selection_for_Run_mode_state */
 144→
 145→  uint16_t TIM_OSSIState;        /*!< Specifies the Off-State used in Idle state.
 146→                                      This parameter can be a value of @ref OSSI_Off_State_Selection_for_Idle_mode_state */
 147→
 148→  uint16_t TIM_LOCKLevel;        /*!< Specifies the LOCK level parameters.
 149→                                      This parameter can be a value of @ref Lock_level */ 
 150→
 151→  uint16_t TIM_DeadTime;         /*!< Specifies the delay time between the switching-off and the
 152→                                      switching-on of the outputs.
 153→                                      This parameter can be a number between 0x00 and 0xFF  */
 154→
 155→  uint16_t TIM_Break;            /*!< Specifies whether the TIM Break input is enabled or not. 
 156→                                      This parameter can be a value of @ref Break_Input_enable_disable */
 157→
 158→  uint16_t TIM_BreakPolarity;    /*!< Specifies the TIM Break Input pin polarity.
 159→                                      This parameter can be a value of @ref Break_Polarity */
 160→
 161→  uint16_t TIM_AutomaticOutput;  /*!< Specifies whether the TIM Automatic Output feature is enabled or not. 
 162→                                      This parameter can be a value of @ref TIM_AOE_Bit_Set_Reset */
 163→} TIM_BDTRInitTypeDef;
 164→
 165→/** @defgroup TIM_Exported_constants 
 166→  * @{
 167→  */
 168→
 169→#define IS_TIM_ALL_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
 170→                                   ((PERIPH) == TIM2) || \
 171→                                   ((PERIPH) == TIM3) || \
 172→                                   ((PERIPH) == TIM4) || \
 173→                                   ((PERIPH) == TIM5) || \
 174→                                   ((PERIPH) == TIM6) || \
 175→                                   ((PERIPH) == TIM7) || \
 176→                                   ((PERIPH) == TIM8) || \
 177→                                   ((PERIPH) == TIM9) || \
 178→                                   ((PERIPH) == TIM10)|| \
 179→                                   ((PERIPH) == TIM11)|| \
 180→                                   ((PERIPH) == TIM12)|| \
 181→                                   ((PERIPH) == TIM13)|| \
 182→                                   ((PERIPH) == TIM14)|| \
 183→                                   ((PERIPH) == TIM15)|| \
 184→                                   ((PERIPH) == TIM16)|| \
 185→                                   ((PERIPH) == TIM17))
 186→
 187→/* LIST1: TIM 1 and 8 */
 188→#define IS_TIM_LIST1_PERIPH(PERIPH)  (((PERIPH) == TIM1) || \
 189→                                      ((PERIPH) == TIM8))
 190→
 191→/* LIST2: TIM 1, 8, 15 16 and 17 */
 192→#define IS_TIM_LIST2_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
 193→                                     ((PERIPH) == TIM8) || \
 194→                                     ((PERIPH) == TIM15)|| \
 195→                                     ((PERIPH) == TIM16)|| \
 196→                                     ((PERIPH) == TIM17)) 
 197→
 198→/* LIST3: TIM 1, 2, 3, 4, 5 and 8 */
 199→#define IS_TIM_LIST3_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
 200→                                     ((PERIPH) == TIM2) || \
 201→                                     ((PERIPH) == TIM3) || \
 202→                                     ((PERIPH) == TIM4) || \
 203→                                     ((PERIPH) == TIM5) || \
 204→                                     ((PERIPH) == TIM8)) 
 205→									                                 
 206→/* LIST4: TIM 1, 2, 3, 4, 5, 8, 15, 16 and 17 */
 207→#define IS_TIM_LIST4_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
 208→                                     ((PERIPH) == TIM2) || \
 209→                                     ((PERIPH) == TIM3) || \
 210→                                     ((PERIPH) == TIM4) || \
 211→                                     ((PERIPH) == TIM5) || \
 212→                                     ((PERIPH) == TIM8) || \
 213→                                     ((PERIPH) == TIM15)|| \
 214→                                     ((PERIPH) == TIM16)|| \
 215→                                     ((PERIPH) == TIM17))
 216→
 217→/* LIST5: TIM 1, 2, 3, 4, 5, 8 and 15 */                                            
 218→#define IS_TIM_LIST5_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
 219→                                     ((PERIPH) == TIM2) || \
 220→                                     ((PERIPH) == TIM3) || \
 221→                                     ((PERIPH) == TIM4) || \
 222→                                     ((PERIPH) == TIM5) || \
 223→                                     ((PERIPH) == TIM8) || \
 224→                                     ((PERIPH) == TIM15)) 
 225→
 226→/* LIST6: TIM 1, 2, 3, 4, 5, 8, 9, 12 and 15 */
 227→#define IS_TIM_LIST6_PERIPH(PERIPH)  (((PERIPH) == TIM1) || \
 228→                                      ((PERIPH) == TIM2) || \
 229→                                      ((PERIPH) == TIM3) || \
 230→                                      ((PERIPH) == TIM4) || \
 231→                                      ((PERIPH) == TIM5) || \
 232→                                      ((PERIPH) == TIM8) || \
 233→                                      ((PERIPH) == TIM9) || \
 234→									  ((PERIPH) == TIM12)|| \
 235→                                      ((PERIPH) == TIM15))
 236→
 237→/* LIST7: TIM 1, 2, 3, 4, 5, 6, 7, 8, 9, 12 and 15 */
 238→#define IS_TIM_LIST7_PERIPH(PERIPH)  (((PERIPH) == TIM1) || \
 239→                                      ((PERIPH) == TIM2) || \
 240→                                      ((PERIPH) == TIM3) || \
 241→                                      ((PERIPH) == TIM4) || \
 242→                                      ((PERIPH) == TIM5) || \
 243→                                      ((PERIPH) == TIM6) || \
 244→                                      ((PERIPH) == TIM7) || \
 245→                                      ((PERIPH) == TIM8) || \
 246→                                      ((PERIPH) == TIM9) || \
 247→                                      ((PERIPH) == TIM12)|| \
 248→                                      ((PERIPH) == TIM15))                                    
 249→
 250→/* LIST8: TIM 1, 2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, 16 and 17 */                                        
 251→#define IS_TIM_LIST8_PERIPH(PERIPH)  (((PERIPH) == TIM1) || \
 252→                                      ((PERIPH) == TIM2) || \
 253→                                      ((PERIPH) == TIM3) || \
 254→                                      ((PERIPH) == TIM4) || \
 255→                                      ((PERIPH) == TIM5) || \
 256→                                      ((PERIPH) == TIM8) || \
 257→                                      ((PERIPH) == TIM9) || \
 258→                                      ((PERIPH) == TIM10)|| \
 259→                                      ((PERIPH) == TIM11)|| \
 260→                                      ((PERIPH) == TIM12)|| \
 261→                                      ((PERIPH) == TIM13)|| \
 262→                                      ((PERIPH) == TIM14)|| \
 263→                                      ((PERIPH) == TIM15)|| \
 264→                                      ((PERIPH) == TIM16)|| \
 265→                                      ((PERIPH) == TIM17))
 266→
 267→/* LIST9: TIM 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, and 17 */
 268→#define IS_TIM_LIST9_PERIPH(PERIPH)  (((PERIPH) == TIM1) || \
 269→                                      ((PERIPH) == TIM2) || \
 270→                                      ((PERIPH) == TIM3) || \
 271→                                      ((PERIPH) == TIM4) || \
 272→                                      ((PERIPH) == TIM5) || \
 273→                                      ((PERIPH) == TIM6) || \
 274→                                      ((PERIPH) == TIM7) || \
 275→                                      ((PERIPH) == TIM8) || \
 276→                                      ((PERIPH) == TIM15)|| \
 277→                                      ((PERIPH) == TIM16)|| \
 278→                                      ((PERIPH) == TIM17))  
 279→                                                                                                                                                                                                                          
 280→/**
 281→  * @}
 282→  */ 
 283→
 284→/** @defgroup TIM_Output_Compare_and_PWM_modes 
 285→  * @{
 286→  */
 287→
 288→#define TIM_OCMode_Timing                  ((uint16_t)0x0000)
 289→#define TIM_OCMode_Active                  ((uint16_t)0x0010)
 290→#define TIM_OCMode_Inactive                ((uint16_t)0x0020)
 291→#define TIM_OCMode_Toggle                  ((uint16_t)0x0030)
 292→#define TIM_OCMode_PWM1                    ((uint16_t)0x0060)
 293→#define TIM_OCMode_PWM2                    ((uint16_t)0x0070)
 294→#define IS_TIM_OC_MODE(MODE) (((MODE) == TIM_OCMode_Timing) || \
 295→                              ((MODE) == TIM_OCMode_Active) || \
 296→                              ((MODE) == TIM_OCMode_Inactive) || \
 297→                              ((MODE) == TIM_OCMode_Toggle)|| \
 298→                              ((MODE) == TIM_OCMode_PWM1) || \
 299→                              ((MODE) == TIM_OCMode_PWM2))
 300→#define IS_TIM_OCM(MODE) (((MODE) == TIM_OCMode_Timing) || \
 301→                          ((MODE) == TIM_OCMode_Active) || \
 302→                          ((MODE) == TIM_OCMode_Inactive) || \
 303→                          ((MODE) == TIM_OCMode_Toggle)|| \
 304→                          ((MODE) == TIM_OCMode_PWM1) || \
 305→                          ((MODE) == TIM_OCMode_PWM2) ||	\
 306→                          ((MODE) == TIM_ForcedAction_Active) || \
 307→                          ((MODE) == TIM_ForcedAction_InActive))
 308→/**
 309→  * @}
 310→  */
 311→
 312→/** @defgroup TIM_One_Pulse_Mode 
 313→  * @{
 314→  */
 315→
 316→#define TIM_OPMode_Single                  ((uint16_t)0x0008)
 317→#define TIM_OPMode_Repetitive              ((uint16_t)0x0000)
 318→#define IS_TIM_OPM_MODE(MODE) (((MODE) == TIM_OPMode_Single) || \
 319→                               ((MODE) == TIM_OPMode_Repetitive))
 320→/**
 321→  * @}
 322→  */ 
 323→
 324→/** @defgroup TIM_Channel 
 325→  * @{
 326→  */
 327→
 328→#define TIM_Channel_1                      ((uint16_t)0x0000)
 329→#define TIM_Channel_2                      ((uint16_t)0x0004)
 330→#define TIM_Channel_3                      ((uint16_t)0x0008)
 331→#define TIM_Channel_4                      ((uint16_t)0x000C)
 332→#define IS_TIM_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
 333→                                 ((CHANNEL) == TIM_Channel_2) || \
 334→                                 ((CHANNEL) == TIM_Channel_3) || \
 335→                                 ((CHANNEL) == TIM_Channel_4))
 336→#define IS_TIM_PWMI_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
 337→                                      ((CHANNEL) == TIM_Channel_2))
 338→#define IS_TIM_COMPLEMENTARY_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
 339→                                               ((CHANNEL) == TIM_Channel_2) || \
 340→                                               ((CHANNEL) == TIM_Channel_3))
 341→/**
 342→  * @}
 343→  */ 
 344→
 345→/** @defgroup TIM_Clock_Division_CKD 
 346→  * @{
 347→  */
 348→
 349→#define TIM_CKD_DIV1                       ((uint16_t)0x0000)
 350→#define TIM_CKD_DIV2                       ((uint16_t)0x0100)
 351→#define TIM_CKD_DIV4                       ((uint16_t)0x0200)
 352→#define IS_TIM_CKD_DIV(DIV) (((DIV) == TIM_CKD_DIV1) || \
 353→                             ((DIV) == TIM_CKD_DIV2) || \
 354→                             ((DIV) == TIM_CKD_DIV4))
 355→/**
 356→  * @}
 357→  */
 358→
 359→/** @defgroup TIM_Counter_Mode 
 360→  * @{
 361→  */
 362→
 363→#define TIM_CounterMode_Up                 ((uint16_t)0x0000)
 364→#define TIM_CounterMode_Down               ((uint16_t)0x0010)
 365→#define TIM_CounterMode_CenterAligned1     ((uint16_t)0x0020)
 366→#define TIM_CounterMode_CenterAligned2     ((uint16_t)0x0040)
 367→#define TIM_CounterMode_CenterAligned3     ((uint16_t)0x0060)
 368→#define IS_TIM_COUNTER_MODE(MODE) (((MODE) == TIM_CounterMode_Up) ||  \
 369→                                   ((MODE) == TIM_CounterMode_Down) || \
 370→                                   ((MODE) == TIM_CounterMode_CenterAligned1) || \
 371→                                   ((MODE) == TIM_CounterMode_CenterAligned2) || \
 372→                                   ((MODE) == TIM_CounterMode_CenterAligned3))
 373→/**
 374→  * @}
 375→  */ 
 376→
 377→/** @defgroup TIM_Output_Compare_Polarity 
 378→  * @{
 379→  */
 380→
 381→#define TIM_OCPolarity_High                ((uint16_t)0x0000)
 382→#define TIM_OCPolarity_Low                 ((uint16_t)0x0002)
 383→#define IS_TIM_OC_POLARITY(POLARITY) (((POLARITY) == TIM_OCPolarity_High) || \
 384→                                      ((POLARITY) == TIM_OCPolarity_Low))
 385→/**
 386→  * @}
 387→  */
 388→
 389→/** @defgroup TIM_Output_Compare_N_Polarity 
 390→  * @{
 391→  */
 392→  
 393→#define TIM_OCNPolarity_High               ((uint16_t)0x0000)
 394→#define TIM_OCNPolarity_Low                ((uint16_t)0x0008)
 395→#define IS_TIM_OCN_POLARITY(POLARITY) (((POLARITY) == TIM_OCNPolarity_High) || \
 396→                                       ((POLARITY) == TIM_OCNPolarity_Low))
 397→/**
 398→  * @}
 399→  */
 400→
 401→/** @defgroup TIM_Output_Compare_state 
 402→  * @{
 403→  */
 404→
 405→#define TIM_OutputState_Disable            ((uint16_t)0x0000)
 406→#define TIM_OutputState_Enable             ((uint16_t)0x0001)
 407→#define IS_TIM_OUTPUT_STATE(STATE) (((STATE) == TIM_OutputState_Disable) || \
 408→                                    ((STATE) == TIM_OutputState_Enable))
 409→/**
 410→  * @}
 411→  */ 
 412→
 413→/** @defgroup TIM_Output_Compare_N_state 
 414→  * @{
 415→  */
 416→
 417→#define TIM_OutputNState_Disable           ((uint16_t)0x0000)
 418→#define TIM_OutputNState_Enable            ((uint16_t)0x0004)
 419→#define IS_TIM_OUTPUTN_STATE(STATE) (((STATE) == TIM_OutputNState_Disable) || \
 420→                                     ((STATE) == TIM_OutputNState_Enable))
 421→/**
 422→  * @}
 423→  */ 
 424→
 425→/** @defgroup TIM_Capture_Compare_state 
 426→  * @{
 427→  */
 428→
 429→#define TIM_CCx_Enable                      ((uint16_t)0x0001)
 430→#define TIM_CCx_Disable                     ((uint16_t)0x0000)
 431→#define IS_TIM_CCX(CCX) (((CCX) == TIM_CCx_Enable) || \
 432→                         ((CCX) == TIM_CCx_Disable))
 433→/**
 434→  * @}
 435→  */ 
 436→
 437→/** @defgroup TIM_Capture_Compare_N_state 
 438→  * @{
 439→  */
 440→
 441→#define TIM_CCxN_Enable                     ((uint16_t)0x0004)
 442→#define TIM_CCxN_Disable                    ((uint16_t)0x0000)
 443→#define IS_TIM_CCXN(CCXN) (((CCXN) == TIM_CCxN_Enable) || \
 444→                           ((CCXN) == TIM_CCxN_Disable))
 445→/**
 446→  * @}
 447→  */ 
 448→
 449→/** @defgroup Break_Input_enable_disable 
 450→  * @{
 451→  */
 452→
 453→#define TIM_Break_Enable                   ((uint16_t)0x1000)
 454→#define TIM_Break_Disable                  ((uint16_t)0x0000)
 455→#define IS_TIM_BREAK_STATE(STATE) (((STATE) == TIM_Break_Enable) || \
 456→                                   ((STATE) == TIM_Break_Disable))
 457→/**
 458→  * @}
 459→  */ 
 460→
 461→/** @defgroup Break_Polarity 
 462→  * @{
 463→  */
 464→
 465→#define TIM_BreakPolarity_Low              ((uint16_t)0x0000)
 466→#define TIM_BreakPolarity_High             ((uint16_t)0x2000)
 467→#define IS_TIM_BREAK_POLARITY(POLARITY) (((POLARITY) == TIM_BreakPolarity_Low) || \
 468→                                         ((POLARITY) == TIM_BreakPolarity_High))
 469→/**
 470→  * @}
 471→  */ 
 472→
 473→/** @defgroup TIM_AOE_Bit_Set_Reset 
 474→  * @{
 475→  */
 476→
 477→#define TIM_AutomaticOutput_Enable         ((uint16_t)0x4000)
 478→#define TIM_AutomaticOutput_Disable        ((uint16_t)0x0000)
 479→#define IS_TIM_AUTOMATIC_OUTPUT_STATE(STATE) (((STATE) == TIM_AutomaticOutput_Enable) || \
 480→                                              ((STATE) == TIM_AutomaticOutput_Disable))
 481→/**
 482→  * @}
 483→  */ 
 484→
 485→/** @defgroup Lock_level 
 486→  * @{
 487→  */
 488→
 489→#define TIM_LOCKLevel_OFF                  ((uint16_t)0x0000)
 490→#define TIM_LOCKLevel_1                    ((uint16_t)0x0100)
 491→#define TIM_LOCKLevel_2                    ((uint16_t)0x0200)
 492→#define TIM_LOCKLevel_3                    ((uint16_t)0x0300)
 493→#define IS_TIM_LOCK_LEVEL(LEVEL) (((LEVEL) == TIM_LOCKLevel_OFF) || \
 494→                                  ((LEVEL) == TIM_LOCKLevel_1) || \
 495→                                  ((LEVEL) == TIM_LOCKLevel_2) || \
 496→                                  ((LEVEL) == TIM_LOCKLevel_3))
 497→/**
 498→  * @}
 499→  */ 
 500→
 501→/** @defgroup OSSI_Off_State_Selection_for_Idle_mode_state 
 502→  * @{
 503→  */
 504→
 505→#define TIM_OSSIState_Enable               ((uint16_t)0x0400)
 506→#define TIM_OSSIState_Disable              ((uint16_t)0x0000)
 507→#define IS_TIM_OSSI_STATE(STATE) (((STATE) == TIM_OSSIState_Enable) || \
 508→                                  ((STATE) == TIM_OSSIState_Disable))
 509→/**
 510→  * @}
 511→  */
 512→
 513→/** @defgroup OSSR_Off_State_Selection_for_Run_mode_state 
 514→  * @{
 515→  */
 516→
 517→#define TIM_OSSRState_Enable               ((uint16_t)0x0800)
 518→#define TIM_OSSRState_Disable              ((uint16_t)0x0000)
 519→#define IS_TIM_OSSR_STATE(STATE) (((STATE) == TIM_OSSRState_Enable) || \
 520→                                  ((STATE) == TIM_OSSRState_Disable))
 521→/**
 522→  * @}
 523→  */ 
 524→
 525→/** @defgroup TIM_Output_Compare_Idle_State 
 526→  * @{
 527→  */
 528→
 529→#define TIM_OCIdleState_Set                ((uint16_t)0x0100)
 530→#define TIM_OCIdleState_Reset              ((uint16_t)0x0000)
 531→#define IS_TIM_OCIDLE_STATE(STATE) (((STATE) == TIM_OCIdleState_Set) || \
 532→                                    ((STATE) == TIM_OCIdleState_Reset))
 533→/**
 534→  * @}
 535→  */ 
 536→
 537→/** @defgroup TIM_Output_Compare_N_Idle_State 
 538→  * @{
 539→  */
 540→
 541→#define TIM_OCNIdleState_Set               ((uint16_t)0x0200)
 542→#define TIM_OCNIdleState_Reset             ((uint16_t)0x0000)
 543→#define IS_TIM_OCNIDLE_STATE(STATE) (((STATE) == TIM_OCNIdleState_Set) || \
 544→                                     ((STATE) == TIM_OCNIdleState_Reset))
 545→/**
 546→  * @}
 547→  */ 
 548→
 549→/** @defgroup TIM_Input_Capture_Polarity 
 550→  * @{
 551→  */
 552→
 553→#define  TIM_ICPolarity_Rising             ((uint16_t)0x0000)
 554→#define  TIM_ICPolarity_Falling            ((uint16_t)0x0002)
 555→#define  TIM_ICPolarity_BothEdge           ((uint16_t)0x000A)
 556→#define IS_TIM_IC_POLARITY(POLARITY) (((POLARITY) == TIM_ICPolarity_Rising) || \
 557→                                      ((POLARITY) == TIM_ICPolarity_Falling))
 558→#define IS_TIM_IC_POLARITY_LITE(POLARITY) (((POLARITY) == TIM_ICPolarity_Rising) || \
 559→                                           ((POLARITY) == TIM_ICPolarity_Falling)|| \
 560→                                           ((POLARITY) == TIM_ICPolarity_BothEdge))                                      
 561→/**
 562→  * @}
 563→  */ 
 564→
 565→/** @defgroup TIM_Input_Capture_Selection 
 566→  * @{
 567→  */
 568→
 569→#define TIM_ICSelection_DirectTI           ((uint16_t)0x0001) /*!< TIM Input 1, 2, 3 or 4 is selected to be 
 570→                                                                   connected to IC1, IC2, IC3 or IC4, respectively */
 571→#define TIM_ICSelection_IndirectTI         ((uint16_t)0x0002) /*!< TIM Input 1, 2, 3 or 4 is selected to be
 572→                                                                   connected to IC2, IC1, IC4 or IC3, respectively. */
 573→#define TIM_ICSelection_TRC                ((uint16_t)0x0003) /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to TRC. */
 574→#define IS_TIM_IC_SELECTION(SELECTION) (((SELECTION) == TIM_ICSelection_DirectTI) || \
 575→                                        ((SELECTION) == TIM_ICSelection_IndirectTI) || \
 576→                                        ((SELECTION) == TIM_ICSelection_TRC))
 577→/**
 578→  * @}
 579→  */ 
 580→
 581→/** @defgroup TIM_Input_Capture_Prescaler 
 582→  * @{
 583→  */
 584→
 585→#define TIM_ICPSC_DIV1                     ((uint16_t)0x0000) /*!< Capture performed each time an edge is detected on the capture input. */
 586→#define TIM_ICPSC_DIV2                     ((uint16_t)0x0004) /*!< Capture performed once every 2 events. */
 587→#define TIM_ICPSC_DIV4                     ((uint16_t)0x0008) /*!< Capture performed once every 4 events. */
 588→#define TIM_ICPSC_DIV8                     ((uint16_t)0x000C) /*!< Capture performed once every 8 events. */
 589→#define IS_TIM_IC_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ICPSC_DIV1) || \
 590→                                        ((PRESCALER) == TIM_ICPSC_DIV2) || \
 591→                                        ((PRESCALER) == TIM_ICPSC_DIV4) || \
 592→                                        ((PRESCALER) == TIM_ICPSC_DIV8))
 593→/**
 594→  * @}
 595→  */ 
 596→
 597→/** @defgroup TIM_interrupt_sources 
 598→  * @{
 599→  */
 600→
 601→#define TIM_IT_Update                      ((uint16_t)0x0001)
 602→#define TIM_IT_CC1                         ((uint16_t)0x0002)
 603→#define TIM_IT_CC2                         ((uint16_t)0x0004)
 604→#define TIM_IT_CC3                         ((uint16_t)0x0008)
 605→#define TIM_IT_CC4                         ((uint16_t)0x0010)
 606→#define TIM_IT_COM                         ((uint16_t)0x0020)
 607→#define TIM_IT_Trigger                     ((uint16_t)0x0040)
 608→#define TIM_IT_Break                       ((uint16_t)0x0080)
 609→#define IS_TIM_IT(IT) ((((IT) & (uint16_t)0xFF00) == 0x0000) && ((IT) != 0x0000))
 610→
 611→#define IS_TIM_GET_IT(IT) (((IT) == TIM_IT_Update) || \
 612→                           ((IT) == TIM_IT_CC1) || \
 613→                           ((IT) == TIM_IT_CC2) || \
 614→                           ((IT) == TIM_IT_CC3) || \
 615→                           ((IT) == TIM_IT_CC4) || \
 616→                           ((IT) == TIM_IT_COM) || \
 617→                           ((IT) == TIM_IT_Trigger) || \
 618→                           ((IT) == TIM_IT_Break))
 619→/**
 620→  * @}
 621→  */ 
 622→
 623→/** @defgroup TIM_DMA_Base_address 
 624→  * @{
 625→  */
 626→
 627→#define TIM_DMABase_CR1                    ((uint16_t)0x0000)
 628→#define TIM_DMABase_CR2                    ((uint16_t)0x0001)
 629→#define TIM_DMABase_SMCR                   ((uint16_t)0x0002)
 630→#define TIM_DMABase_DIER                   ((uint16_t)0x0003)
 631→#define TIM_DMABase_SR                     ((uint16_t)0x0004)
 632→#define TIM_DMABase_EGR                    ((uint16_t)0x0005)
 633→#define TIM_DMABase_CCMR1                  ((uint16_t)0x0006)
 634→#define TIM_DMABase_CCMR2                  ((uint16_t)0x0007)
 635→#define TIM_DMABase_CCER                   ((uint16_t)0x0008)
 636→#define TIM_DMABase_CNT                    ((uint16_t)0x0009)
 637→#define TIM_DMABase_PSC                    ((uint16_t)0x000A)
 638→#define TIM_DMABase_ARR                    ((uint16_t)0x000B)
 639→#define TIM_DMABase_RCR                    ((uint16_t)0x000C)
 640→#define TIM_DMABase_CCR1                   ((uint16_t)0x000D)
 641→#define TIM_DMABase_CCR2                   ((uint16_t)0x000E)
 642→#define TIM_DMABase_CCR3                   ((uint16_t)0x000F)
 643→#define TIM_DMABase_CCR4                   ((uint16_t)0x0010)
 644→#define TIM_DMABase_BDTR                   ((uint16_t)0x0011)
 645→#define TIM_DMABase_DCR                    ((uint16_t)0x0012)
 646→#define IS_TIM_DMA_BASE(BASE) (((BASE) == TIM_DMABase_CR1) || \
 647→                               ((BASE) == TIM_DMABase_CR2) || \
 648→                               ((BASE) == TIM_DMABase_SMCR) || \
 649→                               ((BASE) == TIM_DMABase_DIER) || \
 650→                               ((BASE) == TIM_DMABase_SR) || \
 651→                               ((BASE) == TIM_DMABase_EGR) || \
 652→                               ((BASE) == TIM_DMABase_CCMR1) || \
 653→                               ((BASE) == TIM_DMABase_CCMR2) || \
 654→                               ((BASE) == TIM_DMABase_CCER) || \
 655→                               ((BASE) == TIM_DMABase_CNT) || \
 656→                               ((BASE) == TIM_DMABase_PSC) || \
 657→                               ((BASE) == TIM_DMABase_ARR) || \
 658→                               ((BASE) == TIM_DMABase_RCR) || \
 659→                               ((BASE) == TIM_DMABase_CCR1) || \
 660→                               ((BASE) == TIM_DMABase_CCR2) || \
 661→                               ((BASE) == TIM_DMABase_CCR3) || \
 662→                               ((BASE) == TIM_DMABase_CCR4) || \
 663→                               ((BASE) == TIM_DMABase_BDTR) || \
 664→                               ((BASE) == TIM_DMABase_DCR))
 665→/**
 666→  * @}
 667→  */ 
 668→
 669→/** @defgroup TIM_DMA_Burst_Length 
 670→  * @{
 671→  */
 672→
 673→#define TIM_DMABurstLength_1Transfer           ((uint16_t)0x0000)
 674→#define TIM_DMABurstLength_2Transfers          ((uint16_t)0x0100)
 675→#define TIM_DMABurstLength_3Transfers          ((uint16_t)0x0200)
 676→#define TIM_DMABurstLength_4Transfers          ((uint16_t)0x0300)
 677→#define TIM_DMABurstLength_5Transfers          ((uint16_t)0x0400)
 678→#define TIM_DMABurstLength_6Transfers          ((uint16_t)0x0500)
 679→#define TIM_DMABurstLength_7Transfers          ((uint16_t)0x0600)
 680→#define TIM_DMABurstLength_8Transfers          ((uint16_t)0x0700)
 681→#define TIM_DMABurstLength_9Transfers          ((uint16_t)0x0800)
 682→#define TIM_DMABurstLength_10Transfers         ((uint16_t)0x0900)
 683→#define TIM_DMABurstLength_11Transfers         ((uint16_t)0x0A00)
 684→#define TIM_DMABurstLength_12Transfers         ((uint16_t)0x0B00)
 685→#define TIM_DMABurstLength_13Transfers         ((uint16_t)0x0C00)
 686→#define TIM_DMABurstLength_14Transfers         ((uint16_t)0x0D00)
 687→#define TIM_DMABurstLength_15Transfers         ((uint16_t)0x0E00)
 688→#define TIM_DMABurstLength_16Transfers         ((uint16_t)0x0F00)
 689→#define TIM_DMABurstLength_17Transfers         ((uint16_t)0x1000)
 690→#define TIM_DMABurstLength_18Transfers         ((uint16_t)0x1100)
 691→#define IS_TIM_DMA_LENGTH(LENGTH) (((LENGTH) == TIM_DMABurstLength_1Transfer) || \
 692→                                   ((LENGTH) == TIM_DMABurstLength_2Transfers) || \
 693→                                   ((LENGTH) == TIM_DMABurstLength_3Transfers) || \
 694→                                   ((LENGTH) == TIM_DMABurstLength_4Transfers) || \
 695→                                   ((LENGTH) == TIM_DMABurstLength_5Transfers) || \
 696→                                   ((LENGTH) == TIM_DMABurstLength_6Transfers) || \
 697→                                   ((LENGTH) == TIM_DMABurstLength_7Transfers) || \
 698→                                   ((LENGTH) == TIM_DMABurstLength_8Transfers) || \
 699→                                   ((LENGTH) == TIM_DMABurstLength_9Transfers) || \
 700→                                   ((LENGTH) == TIM_DMABurstLength_10Transfers) || \
 701→                                   ((LENGTH) == TIM_DMABurstLength_11Transfers) || \
 702→                                   ((LENGTH) == TIM_DMABurstLength_12Transfers) || \
 703→                                   ((LENGTH) == TIM_DMABurstLength_13Transfers) || \
 704→                                   ((LENGTH) == TIM_DMABurstLength_14Transfers) || \
 705→                                   ((LENGTH) == TIM_DMABurstLength_15Transfers) || \
 706→                                   ((LENGTH) == TIM_DMABurstLength_16Transfers) || \
 707→                                   ((LENGTH) == TIM_DMABurstLength_17Transfers) || \
 708→                                   ((LENGTH) == TIM_DMABurstLength_18Transfers))
 709→/**
 710→  * @}
 711→  */ 
 712→
 713→/** @defgroup TIM_DMA_sources 
 714→  * @{
 715→  */
 716→
 717→#define TIM_DMA_Update                     ((uint16_t)0x0100)
 718→#define TIM_DMA_CC1                        ((uint16_t)0x0200)
 719→#define TIM_DMA_CC2                        ((uint16_t)0x0400)
 720→#define TIM_DMA_CC3                        ((uint16_t)0x0800)
 721→#define TIM_DMA_CC4                        ((uint16_t)0x1000)
 722→#define TIM_DMA_COM                        ((uint16_t)0x2000)
 723→#define TIM_DMA_Trigger                    ((uint16_t)0x4000)
 724→#define IS_TIM_DMA_SOURCE(SOURCE) ((((SOURCE) & (uint16_t)0x80FF) == 0x0000) && ((SOURCE) != 0x0000))
 725→
 726→/**
 727→  * @}
 728→  */ 
 729→
 730→/** @defgroup TIM_External_Trigger_Prescaler 
 731→  * @{
 732→  */
 733→
 734→#define TIM_ExtTRGPSC_OFF                  ((uint16_t)0x0000)
 735→#define TIM_ExtTRGPSC_DIV2                 ((uint16_t)0x1000)
 736→#define TIM_ExtTRGPSC_DIV4                 ((uint16_t)0x2000)
 737→#define TIM_ExtTRGPSC_DIV8                 ((uint16_t)0x3000)
 738→#define IS_TIM_EXT_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ExtTRGPSC_OFF) || \
 739→                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV2) || \
 740→                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV4) || \
 741→                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV8))
 742→/**
 743→  * @}
 744→  */ 
 745→
 746→/** @defgroup TIM_Internal_Trigger_Selection 
 747→  * @{
 748→  */
 749→
 750→#define TIM_TS_ITR0                        ((uint16_t)0x0000)
 751→#define TIM_TS_ITR1                        ((uint16_t)0x0010)
 752→#define TIM_TS_ITR2                        ((uint16_t)0x0020)
 753→#define TIM_TS_ITR3                        ((uint16_t)0x0030)
 754→#define TIM_TS_TI1F_ED                     ((uint16_t)0x0040)
 755→#define TIM_TS_TI1FP1                      ((uint16_t)0x0050)
 756→#define TIM_TS_TI2FP2                      ((uint16_t)0x0060)
 757→#define TIM_TS_ETRF                        ((uint16_t)0x0070)
 758→#define IS_TIM_TRIGGER_SELECTION(SELECTION) (((SELECTION) == TIM_TS_ITR0) || \
 759→                                             ((SELECTION) == TIM_TS_ITR1) || \
 760→                                             ((SELECTION) == TIM_TS_ITR2) || \
 761→                                             ((SELECTION) == TIM_TS_ITR3) || \
 762→                                             ((SELECTION) == TIM_TS_TI1F_ED) || \
 763→                                             ((SELECTION) == TIM_TS_TI1FP1) || \
 764→                                             ((SELECTION) == TIM_TS_TI2FP2) || \
 765→                                             ((SELECTION) == TIM_TS_ETRF))
 766→#define IS_TIM_INTERNAL_TRIGGER_SELECTION(SELECTION) (((SELECTION) == TIM_TS_ITR0) || \
 767→                                                      ((SELECTION) == TIM_TS_ITR1) || \
 768→                                                      ((SELECTION) == TIM_TS_ITR2) || \
 769→                                                      ((SELECTION) == TIM_TS_ITR3))
 770→/**
 771→  * @}
 772→  */ 
 773→
 774→/** @defgroup TIM_TIx_External_Clock_Source 
 775→  * @{
 776→  */
 777→
 778→#define TIM_TIxExternalCLK1Source_TI1      ((uint16_t)0x0050)
 779→#define TIM_TIxExternalCLK1Source_TI2      ((uint16_t)0x0060)
 780→#define TIM_TIxExternalCLK1Source_TI1ED    ((uint16_t)0x0040)
 781→#define IS_TIM_TIXCLK_SOURCE(SOURCE) (((SOURCE) == TIM_TIxExternalCLK1Source_TI1) || \
 782→                                      ((SOURCE) == TIM_TIxExternalCLK1Source_TI2) || \
 783→                                      ((SOURCE) == TIM_TIxExternalCLK1Source_TI1ED))
 784→/**
 785→  * @}
 786→  */ 
 787→
 788→/** @defgroup TIM_External_Trigger_Polarity 
 789→  * @{
 790→  */ 
 791→#define TIM_ExtTRGPolarity_Inverted        ((uint16_t)0x8000)
 792→#define TIM_ExtTRGPolarity_NonInverted     ((uint16_t)0x0000)
 793→#define IS_TIM_EXT_POLARITY(POLARITY) (((POLARITY) == TIM_ExtTRGPolarity_Inverted) || \
 794→                                       ((POLARITY) == TIM_ExtTRGPolarity_NonInverted))
 795→/**
 796→  * @}
 797→  */
 798→
 799→/** @defgroup TIM_Prescaler_Reload_Mode 
 800→  * @{
 801→  */
 802→
 803→#define TIM_PSCReloadMode_Update           ((uint16_t)0x0000)
 804→#define TIM_PSCReloadMode_Immediate        ((uint16_t)0x0001)
 805→#define IS_TIM_PRESCALER_RELOAD(RELOAD) (((RELOAD) == TIM_PSCReloadMode_Update) || \
 806→                                         ((RELOAD) == TIM_PSCReloadMode_Immediate))
 807→/**
 808→  * @}
 809→  */ 
 810→
 811→/** @defgroup TIM_Forced_Action 
 812→  * @{
 813→  */
 814→
 815→#define TIM_ForcedAction_Active            ((uint16_t)0x0050)
 816→#define TIM_ForcedAction_InActive          ((uint16_t)0x0040)
 817→#define IS_TIM_FORCED_ACTION(ACTION) (((ACTION) == TIM_ForcedAction_Active) || \
 818→                                      ((ACTION) == TIM_ForcedAction_InActive))
 819→/**
 820→  * @}
 821→  */ 
 822→
 823→/** @defgroup TIM_Encoder_Mode 
 824→  * @{
 825→  */
 826→
 827→#define TIM_EncoderMode_TI1                ((uint16_t)0x0001)
 828→#define TIM_EncoderMode_TI2                ((uint16_t)0x0002)
 829→#define TIM_EncoderMode_TI12               ((uint16_t)0x0003)
 830→#define IS_TIM_ENCODER_MODE(MODE) (((MODE) == TIM_EncoderMode_TI1) || \
 831→                                   ((MODE) == TIM_EncoderMode_TI2) || \
 832→                                   ((MODE) == TIM_EncoderMode_TI12))
 833→/**
 834→  * @}
 835→  */ 
 836→
 837→
 838→/** @defgroup TIM_Event_Source 
 839→  * @{
 840→  */
 841→
 842→#define TIM_EventSource_Update             ((uint16_t)0x0001)
 843→#define TIM_EventSource_CC1                ((uint16_t)0x0002)
 844→#define TIM_EventSource_CC2                ((uint16_t)0x0004)
 845→#define TIM_EventSource_CC3                ((uint16_t)0x0008)
 846→#define TIM_EventSource_CC4                ((uint16_t)0x0010)
 847→#define TIM_EventSource_COM                ((uint16_t)0x0020)
 848→#define TIM_EventSource_Trigger            ((uint16_t)0x0040)
 849→#define TIM_EventSource_Break              ((uint16_t)0x0080)
 850→#define IS_TIM_EVENT_SOURCE(SOURCE) ((((SOURCE) & (uint16_t)0xFF00) == 0x0000) && ((SOURCE) != 0x0000))
 851→
 852→/**
 853→  * @}
 854→  */ 
 855→
 856→/** @defgroup TIM_Update_Source 
 857→  * @{
 858→  */
 859→
 860→#define TIM_UpdateSource_Global            ((uint16_t)0x0000) /*!< Source of update is the counter overflow/underflow
 861→                                                                   or the setting of UG bit, or an update generation
 862→                                                                   through the slave mode controller. */
 863→#define TIM_UpdateSource_Regular           ((uint16_t)0x0001) /*!< Source of update is counter overflow/underflow. */
 864→#define IS_TIM_UPDATE_SOURCE(SOURCE) (((SOURCE) == TIM_UpdateSource_Global) || \
 865→                                      ((SOURCE) == TIM_UpdateSource_Regular))
 866→/**
 867→  * @}
 868→  */ 
 869→
 870→/** @defgroup TIM_Output_Compare_Preload_State 
 871→  * @{
 872→  */
 873→
 874→#define TIM_OCPreload_Enable               ((uint16_t)0x0008)
 875→#define TIM_OCPreload_Disable              ((uint16_t)0x0000)
 876→#define IS_TIM_OCPRELOAD_STATE(STATE) (((STATE) == TIM_OCPreload_Enable) || \
 877→                                       ((STATE) == TIM_OCPreload_Disable))
 878→/**
 879→  * @}
 880→  */ 
 881→
 882→/** @defgroup TIM_Output_Compare_Fast_State 
 883→  * @{
 884→  */
 885→
 886→#define TIM_OCFast_Enable                  ((uint16_t)0x0004)
 887→#define TIM_OCFast_Disable                 ((uint16_t)0x0000)
 888→#define IS_TIM_OCFAST_STATE(STATE) (((STATE) == TIM_OCFast_Enable) || \
 889→                                    ((STATE) == TIM_OCFast_Disable))
 890→                                     
 891→/**
 892→  * @}
 893→  */ 
 894→
 895→/** @defgroup TIM_Output_Compare_Clear_State 
 896→  * @{
 897→  */
 898→
 899→#define TIM_OCClear_Enable                 ((uint16_t)0x0080)
 900→#define TIM_OCClear_Disable                ((uint16_t)0x0000)
 901→#define IS_TIM_OCCLEAR_STATE(STATE) (((STATE) == TIM_OCClear_Enable) || \
 902→                                     ((STATE) == TIM_OCClear_Disable))
 903→/**
 904→  * @}
 905→  */ 
 906→
 907→/** @defgroup TIM_Trigger_Output_Source 
 908→  * @{
 909→  */
 910→
 911→#define TIM_TRGOSource_Reset               ((uint16_t)0x0000)
 912→#define TIM_TRGOSource_Enable              ((uint16_t)0x0010)
 913→#define TIM_TRGOSource_Update              ((uint16_t)0x0020)
 914→#define TIM_TRGOSource_OC1                 ((uint16_t)0x0030)
 915→#define TIM_TRGOSource_OC1Ref              ((uint16_t)0x0040)
 916→#define TIM_TRGOSource_OC2Ref              ((uint16_t)0x0050)
 917→#define TIM_TRGOSource_OC3Ref              ((uint16_t)0x0060)
 918→#define TIM_TRGOSource_OC4Ref              ((uint16_t)0x0070)
 919→#define IS_TIM_TRGO_SOURCE(SOURCE) (((SOURCE) == TIM_TRGOSource_Reset) || \
 920→                                    ((SOURCE) == TIM_TRGOSource_Enable) || \
 921→                                    ((SOURCE) == TIM_TRGOSource_Update) || \
 922→                                    ((SOURCE) == TIM_TRGOSource_OC1) || \
 923→                                    ((SOURCE) == TIM_TRGOSource_OC1Ref) || \
 924→                                    ((SOURCE) == TIM_TRGOSource_OC2Ref) || \
 925→                                    ((SOURCE) == TIM_TRGOSource_OC3Ref) || \
 926→                                    ((SOURCE) == TIM_TRGOSource_OC4Ref))
 927→/**
 928→  * @}
 929→  */ 
 930→
 931→/** @defgroup TIM_Slave_Mode 
 932→  * @{
 933→  */
 934→
 935→#define TIM_SlaveMode_Reset                ((uint16_t)0x0004)
 936→#define TIM_SlaveMode_Gated                ((uint16_t)0x0005)
 937→#define TIM_SlaveMode_Trigger              ((uint16_t)0x0006)
 938→#define TIM_SlaveMode_External1            ((uint16_t)0x0007)
 939→#define IS_TIM_SLAVE_MODE(MODE) (((MODE) == TIM_SlaveMode_Reset) || \
 940→                                 ((MODE) == TIM_SlaveMode_Gated) || \
 941→                                 ((MODE) == TIM_SlaveMode_Trigger) || \
 942→                                 ((MODE) == TIM_SlaveMode_External1))
 943→/**
 944→  * @}
 945→  */ 
 946→
 947→/** @defgroup TIM_Master_Slave_Mode 
 948→  * @{
 949→  */
 950→
 951→#define TIM_MasterSlaveMode_Enable         ((uint16_t)0x0080)
 952→#define TIM_MasterSlaveMode_Disable        ((uint16_t)0x0000)
 953→#define IS_TIM_MSM_STATE(STATE) (((STATE) == TIM_MasterSlaveMode_Enable) || \
 954→                                 ((STATE) == TIM_MasterSlaveMode_Disable))
 955→/**
 956→  * @}
 957→  */ 
 958→
 959→/** @defgroup TIM_Flags 
 960→  * @{
 961→  */
 962→
 963→#define TIM_FLAG_Update                    ((uint16_t)0x0001)
 964→#define TIM_FLAG_CC1                       ((uint16_t)0x0002)
 965→#define TIM_FLAG_CC2                       ((uint16_t)0x0004)
 966→#define TIM_FLAG_CC3                       ((uint16_t)0x0008)
 967→#define TIM_FLAG_CC4                       ((uint16_t)0x0010)
 968→#define TIM_FLAG_COM                       ((uint16_t)0x0020)
 969→#define TIM_FLAG_Trigger                   ((uint16_t)0x0040)
 970→#define TIM_FLAG_Break                     ((uint16_t)0x0080)
 971→#define TIM_FLAG_CC1OF                     ((uint16_t)0x0200)
 972→#define TIM_FLAG_CC2OF                     ((uint16_t)0x0400)
 973→#define TIM_FLAG_CC3OF                     ((uint16_t)0x0800)
 974→#define TIM_FLAG_CC4OF                     ((uint16_t)0x1000)
 975→#define IS_TIM_GET_FLAG(FLAG) (((FLAG) == TIM_FLAG_Update) || \
 976→                               ((FLAG) == TIM_FLAG_CC1) || \
 977→                               ((FLAG) == TIM_FLAG_CC2) || \
 978→                               ((FLAG) == TIM_FLAG_CC3) || \
 979→                               ((FLAG) == TIM_FLAG_CC4) || \
 980→                               ((FLAG) == TIM_FLAG_COM) || \
 981→                               ((FLAG) == TIM_FLAG_Trigger) || \
 982→                               ((FLAG) == TIM_FLAG_Break) || \
 983→                               ((FLAG) == TIM_FLAG_CC1OF) || \
 984→                               ((FLAG) == TIM_FLAG_CC2OF) || \
 985→                               ((FLAG) == TIM_FLAG_CC3OF) || \
 986→                               ((FLAG) == TIM_FLAG_CC4OF))
 987→                               
 988→                               
 989→#define IS_TIM_CLEAR_FLAG(TIM_FLAG) ((((TIM_FLAG) & (uint16_t)0xE100) == 0x0000) && ((TIM_FLAG) != 0x0000))
 990→/**
 991→  * @}
 992→  */ 
 993→
 994→/** @defgroup TIM_Input_Capture_Filer_Value 
 995→  * @{
 996→  */
 997→
 998→#define IS_TIM_IC_FILTER(ICFILTER) ((ICFILTER) <= 0xF) 
 999→/**
1000→  * @}
1001→  */ 
1002→
1003→/** @defgroup TIM_External_Trigger_Filter 
1004→  * @{
1005→  */
1006→
1007→#define IS_TIM_EXT_FILTER(EXTFILTER) ((EXTFILTER) <= 0xF)
1008→/**
1009→  * @}
1010→  */ 
1011→
1012→/** @defgroup TIM_Legacy 
1013→  * @{
1014→  */
1015→
1016→#define TIM_DMABurstLength_1Byte           TIM_DMABurstLength_1Transfer
1017→#define TIM_DMABurstLength_2Bytes          TIM_DMABurstLength_2Transfers
1018→#define TIM_DMABurstLength_3Bytes          TIM_DMABurstLength_3Transfers
1019→#define TIM_DMABurstLength_4Bytes          TIM_DMABurstLength_4Transfers
1020→#define TIM_DMABurstLength_5Bytes          TIM_DMABurstLength_5Transfers
1021→#define TIM_DMABurstLength_6Bytes          TIM_DMABurstLength_6Transfers
1022→#define TIM_DMABurstLength_7Bytes          TIM_DMABurstLength_7Transfers
1023→#define TIM_DMABurstLength_8Bytes          TIM_DMABurstLength_8Transfers
1024→#define TIM_DMABurstLength_9Bytes          TIM_DMABurstLength_9Transfers
1025→#define TIM_DMABurstLength_10Bytes         TIM_DMABurstLength_10Transfers
1026→#define TIM_DMABurstLength_11Bytes         TIM_DMABurstLength_11Transfers
1027→#define TIM_DMABurstLength_12Bytes         TIM_DMABurstLength_12Transfers
1028→#define TIM_DMABurstLength_13Bytes         TIM_DMABurstLength_13Transfers
1029→#define TIM_DMABurstLength_14Bytes         TIM_DMABurstLength_14Transfers
1030→#define TIM_DMABurstLength_15Bytes         TIM_DMABurstLength_15Transfers
1031→#define TIM_DMABurstLength_16Bytes         TIM_DMABurstLength_16Transfers
1032→#define TIM_DMABurstLength_17Bytes         TIM_DMABurstLength_17Transfers
1033→#define TIM_DMABurstLength_18Bytes         TIM_DMABurstLength_18Transfers
1034→/**
1035→  * @}
1036→  */
1037→
1038→/**
1039→  * @}
1040→  */
1041→
1042→/** @defgroup TIM_Exported_Macros
1043→  * @{
1044→  */
1045→
1046→/**
1047→  * @}
1048→  */ 
1049→
1050→/** @defgroup TIM_Exported_Functions
1051→  * @{
1052→  */
1053→
1054→void TIM_DeInit(TIM_TypeDef* TIMx);
1055→void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
1056→void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
1057→void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
1058→void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
1059→void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
1060→void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
1061→void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
1062→void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
1063→void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
1064→void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
1065→void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
1066→void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
1067→void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
1068→void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
1069→void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);
1070→void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource);
1071→void TIM_DMAConfig(TIM_TypeDef* TIMx, uint16_t TIM_DMABase, uint16_t TIM_DMABurstLength);
1072→void TIM_DMACmd(TIM_TypeDef* TIMx, uint16_t TIM_DMASource, FunctionalState NewState);
1073→void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
1074→void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
1075→void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
1076→                                uint16_t TIM_ICPolarity, uint16_t ICFilter);
1077→void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
1078→                             uint16_t ExtTRGFilter);
1079→void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
1080→                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);
1081→void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
1082→                   uint16_t ExtTRGFilter);
1083→void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode);
1084→void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);
1085→void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
1086→void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
1087→                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity);
1088→void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
1089→void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
1090→void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
1091→void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
1092→void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
1093→void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);
1094→void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);
1095→void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
1096→void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
1097→void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
1098→void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
1099→void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
1100→void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
1101→void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
1102→void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
1103→void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
1104→void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
1105→void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
1106→void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
1107→void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
1108→void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
1109→void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
1110→void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
1111→void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
1112→void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
1113→void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
1114→void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
1115→void TIM_CCxCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCx);
1116→void TIM_CCxNCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCxN);
1117→void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);
1118→void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
1119→void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, uint16_t TIM_UpdateSource);
1120→void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);
1121→void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, uint16_t TIM_OPMode);
1122→void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_TRGOSource);
1123→void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_SlaveMode);
1124→void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_MasterSlaveMode);
1125→void TIM_SetCounter(TIM_TypeDef* TIMx, uint16_t Counter);
1126→void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint16_t Autoreload);
1127→void TIM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1);
1128→void TIM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2);
1129→void TIM_SetCompare3(TIM_TypeDef* TIMx, uint16_t Compare3);
1130→void TIM_SetCompare4(TIM_TypeDef* TIMx, uint16_t Compare4);
1131→void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
1132→void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
1133→void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
1134→void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
1135→void TIM_SetClockDivision(TIM_TypeDef* TIMx, uint16_t TIM_CKD);
1136→uint16_t TIM_GetCapture1(TIM_TypeDef* TIMx);
1137→uint16_t TIM_GetCapture2(TIM_TypeDef* TIMx);
1138→uint16_t TIM_GetCapture3(TIM_TypeDef* TIMx);
1139→uint16_t TIM_GetCapture4(TIM_TypeDef* TIMx);
1140→uint16_t TIM_GetCounter(TIM_TypeDef* TIMx);
1141→uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);
1142→FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
1143→void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
1144→ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
1145→void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
1146→
1147→#ifdef __cplusplus
1148→}
1149→#endif
1150→
1151→#endif /*__STM32F10x_TIM_H */
1152→/**
1153→  * @}
1154→  */ 
1155→
1156→/**
1157→  * @}
1158→  */ 
1159→
1160→/**
1161→  * @}
1162→  */