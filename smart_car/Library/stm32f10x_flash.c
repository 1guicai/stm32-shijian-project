File content truncated due to size limit (50KB). First 50KB included below:

   1→/**
   2→  ******************************************************************************
   3→  * @file    stm32f10x_flash.c
   4→  * @author  MCD Application Team
   5→  * @version V3.5.0
   6→  * @date    11-March-2011
   7→  * @brief   This file provides all the FLASH firmware functions.
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
  23→#include "stm32f10x_flash.h"
  24→
  25→/** @addtogroup STM32F10x_StdPeriph_Driver
  26→  * @{
  27→  */
  28→
  29→/** @defgroup FLASH 
  30→  * @brief FLASH driver modules
  31→  * @{
  32→  */ 
  33→
  34→/** @defgroup FLASH_Private_TypesDefinitions
  35→  * @{
  36→  */
  37→
  38→/**
  39→  * @}
  40→  */ 
  41→
  42→/** @defgroup FLASH_Private_Defines
  43→  * @{
  44→  */ 
  45→
  46→/* Flash Access Control Register bits */
  47→#define ACR_LATENCY_Mask         ((uint32_t)0x00000038)
  48→#define ACR_HLFCYA_Mask          ((uint32_t)0xFFFFFFF7)
  49→#define ACR_PRFTBE_Mask          ((uint32_t)0xFFFFFFEF)
  50→
  51→/* Flash Access Control Register bits */
  52→#define ACR_PRFTBS_Mask          ((uint32_t)0x00000020) 
  53→
  54→/* Flash Control Register bits */
  55→#define CR_PG_Set                ((uint32_t)0x00000001)
  56→#define CR_PG_Reset              ((uint32_t)0x00001FFE) 
  57→#define CR_PER_Set               ((uint32_t)0x00000002)
  58→#define CR_PER_Reset             ((uint32_t)0x00001FFD)
  59→#define CR_MER_Set               ((uint32_t)0x00000004)
  60→#define CR_MER_Reset             ((uint32_t)0x00001FFB)
  61→#define CR_OPTPG_Set             ((uint32_t)0x00000010)
  62→#define CR_OPTPG_Reset           ((uint32_t)0x00001FEF)
  63→#define CR_OPTER_Set             ((uint32_t)0x00000020)
  64→#define CR_OPTER_Reset           ((uint32_t)0x00001FDF)
  65→#define CR_STRT_Set              ((uint32_t)0x00000040)
  66→#define CR_LOCK_Set              ((uint32_t)0x00000080)
  67→
  68→/* FLASH Mask */
  69→#define RDPRT_Mask               ((uint32_t)0x00000002)
  70→#define WRP0_Mask                ((uint32_t)0x000000FF)
  71→#define WRP1_Mask                ((uint32_t)0x0000FF00)
  72→#define WRP2_Mask                ((uint32_t)0x00FF0000)
  73→#define WRP3_Mask                ((uint32_t)0xFF000000)
  74→#define OB_USER_BFB2             ((uint16_t)0x0008)
  75→
  76→/* FLASH Keys */
  77→#define RDP_Key                  ((uint16_t)0x00A5)
  78→#define FLASH_KEY1               ((uint32_t)0x45670123)
  79→#define FLASH_KEY2               ((uint32_t)0xCDEF89AB)
  80→
  81→/* FLASH BANK address */
  82→#define FLASH_BANK1_END_ADDRESS   ((uint32_t)0x807FFFF)
  83→
  84→/* Delay definition */   
  85→#define EraseTimeout          ((uint32_t)0x000B0000)
  86→#define ProgramTimeout        ((uint32_t)0x00002000)
  87→/**
  88→  * @}
  89→  */ 
  90→
  91→/** @defgroup FLASH_Private_Macros
  92→  * @{
  93→  */
  94→
  95→/**
  96→  * @}
  97→  */ 
  98→
  99→/** @defgroup FLASH_Private_Variables
 100→  * @{
 101→  */
 102→
 103→/**
 104→  * @}
 105→  */ 
 106→
 107→/** @defgroup FLASH_Private_FunctionPrototypes
 108→  * @{
 109→  */
 110→  
 111→/**
 112→  * @}
 113→  */
 114→
 115→/** @defgroup FLASH_Private_Functions
 116→  * @{
 117→  */
 118→
 119→/**
 120→@code  
 121→ 
 122→ This driver provides functions to configure and program the Flash memory of all STM32F10x devices,
 123→ including the latest STM32F10x_XL density devices. 
 124→
 125→ STM32F10x_XL devices feature up to 1 Mbyte with dual bank architecture for read-while-write (RWW) capability:
 126→    - bank1: fixed size of 512 Kbytes (256 pages of 2Kbytes each)
 127→    - bank2: up to 512 Kbytes (up to 256 pages of 2Kbytes each)
 128→ While other STM32F10x devices features only one bank with memory up to 512 Kbytes.
 129→
 130→ In version V3.3.0, some functions were updated and new ones were added to support
 131→ STM32F10x_XL devices. Thus some functions manages all devices, while other are 
 132→ dedicated for XL devices only.
 133→ 
 134→ The table below presents the list of available functions depending on the used STM32F10x devices.  
 135→      
 136→   ***************************************************
 137→   * Legacy functions used for all STM32F10x devices *
 138→   ***************************************************
 139→   +----------------------------------------------------------------------------------------------------------------------------------+
 140→   |       Functions prototypes         |STM32F10x_XL|Other STM32F10x|    Comments                                                    |
 141→   |                                    |   devices  |  devices      |                                                                |
 142→   |----------------------------------------------------------------------------------------------------------------------------------|
 143→   |FLASH_SetLatency                    |    Yes     |      Yes      | No change                                                      |
 144→   |----------------------------------------------------------------------------------------------------------------------------------|
 145→   |FLASH_HalfCycleAccessCmd            |    Yes     |      Yes      | No change                                                      |
 146→   |----------------------------------------------------------------------------------------------------------------------------------|
 147→   |FLASH_PrefetchBufferCmd             |    Yes     |      Yes      | No change                                                      |
 148→   |----------------------------------------------------------------------------------------------------------------------------------|
 149→   |FLASH_Unlock                        |    Yes     |      Yes      | - For STM32F10X_XL devices: unlock Bank1 and Bank2.            |
 150→   |                                    |            |               | - For other devices: unlock Bank1 and it is equivalent         |
 151→   |                                    |            |               |   to FLASH_UnlockBank1 function.                               |
 152→   |----------------------------------------------------------------------------------------------------------------------------------|
 153→   |FLASH_Lock                          |    Yes     |      Yes      | - For STM32F10X_XL devices: lock Bank1 and Bank2.              |
 154→   |                                    |            |               | - For other devices: lock Bank1 and it is equivalent           |
 155→   |                                    |            |               |   to FLASH_LockBank1 function.                                 |
 156→   |----------------------------------------------------------------------------------------------------------------------------------|
 157→   |FLASH_ErasePage                     |    Yes     |      Yes      | - For STM32F10x_XL devices: erase a page in Bank1 and Bank2    |
 158→   |                                    |            |               | - For other devices: erase a page in Bank1                     |
 159→   |----------------------------------------------------------------------------------------------------------------------------------|
 160→   |FLASH_EraseAllPages                 |    Yes     |      Yes      | - For STM32F10x_XL devices: erase all pages in Bank1 and Bank2 |
 161→   |                                    |            |               | - For other devices: erase all pages in Bank1                  |
 162→   |----------------------------------------------------------------------------------------------------------------------------------|
 163→   |FLASH_EraseOptionBytes              |    Yes     |      Yes      | No change                                                      |
 164→   |----------------------------------------------------------------------------------------------------------------------------------|
 165→   |FLASH_ProgramWord                   |    Yes     |      Yes      | Updated to program up to 1MByte (depending on the used device) |
 166→   |----------------------------------------------------------------------------------------------------------------------------------|
 167→   |FLASH_ProgramHalfWord               |    Yes     |      Yes      | Updated to program up to 1MByte (depending on the used device) |
 168→   |----------------------------------------------------------------------------------------------------------------------------------|
 169→   |FLASH_ProgramOptionByteData         |    Yes     |      Yes      | No change                                                      |
 170→   |----------------------------------------------------------------------------------------------------------------------------------|
 171→   |FLASH_EnableWriteProtection         |    Yes     |      Yes      | No change                                                      |
 172→   |----------------------------------------------------------------------------------------------------------------------------------|
 173→   |FLASH_ReadOutProtection             |    Yes     |      Yes      | No change                                                      |
 174→   |----------------------------------------------------------------------------------------------------------------------------------|
 175→   |FLASH_UserOptionByteConfig          |    Yes     |      Yes      | No change                                                      |
 176→   |----------------------------------------------------------------------------------------------------------------------------------|
 177→   |FLASH_GetUserOptionByte             |    Yes     |      Yes      | No change                                                      |
 178→   |----------------------------------------------------------------------------------------------------------------------------------|
 179→   |FLASH_GetWriteProtectionOptionByte  |    Yes     |      Yes      | No change                                                      |
 180→   |----------------------------------------------------------------------------------------------------------------------------------|
 181→   |FLASH_GetReadOutProtectionStatus    |    Yes     |      Yes      | No change                                                      |
 182→   |----------------------------------------------------------------------------------------------------------------------------------|
 183→   |FLASH_GetPrefetchBufferStatus       |    Yes     |      Yes      | No change                                                      |
 184→   |----------------------------------------------------------------------------------------------------------------------------------|
 185→   |FLASH_ITConfig                      |    Yes     |      Yes      | - For STM32F10x_XL devices: enable Bank1 and Bank2's interrupts|
 186→   |                                    |            |               | - For other devices: enable Bank1's interrupts                 |
 187→   |----------------------------------------------------------------------------------------------------------------------------------|
 188→   |FLASH_GetFlagStatus                 |    Yes     |      Yes      | - For STM32F10x_XL devices: return Bank1 and Bank2's flag status|
 189→   |                                    |            |               | - For other devices: return Bank1's flag status                |
 190→   |----------------------------------------------------------------------------------------------------------------------------------|
 191→   |FLASH_ClearFlag                     |    Yes     |      Yes      | - For STM32F10x_XL devices: clear Bank1 and Bank2's flag       |
 192→   |                                    |            |               | - For other devices: clear Bank1's flag                        |
 193→   |----------------------------------------------------------------------------------------------------------------------------------|
 194→   |FLASH_GetStatus                     |    Yes     |      Yes      | - Return the status of Bank1 (for all devices)                 |
 195→   |                                    |            |               |   equivalent to FLASH_GetBank1Status function                  |
 196→   |----------------------------------------------------------------------------------------------------------------------------------|
 197→   |FLASH_WaitForLastOperation          |    Yes     |      Yes      | - Wait for Bank1 last operation (for all devices)              |
 198→   |                                    |            |               |   equivalent to: FLASH_WaitForLastBank1Operation function      |
 199→   +----------------------------------------------------------------------------------------------------------------------------------+
 200→
 201→   ************************************************************************************************************************
 202→   * New functions used for all STM32F10x devices to manage Bank1:                                                        *
 203→   *   - These functions are mainly useful for STM32F10x_XL density devices, to have separate control for Bank1 and bank2 *
 204→   *   - For other devices, these functions are optional (covered by functions listed above)                              *
 205→   ************************************************************************************************************************
 206→   +----------------------------------------------------------------------------------------------------------------------------------+
 207→   |       Functions prototypes         |STM32F10x_XL|Other STM32F10x|    Comments                                                    |
 208→   |                                    |   devices  |  devices      |                                                                |
 209→   |----------------------------------------------------------------------------------------------------------------------------------|
 210→   | FLASH_UnlockBank1                  |    Yes     |      Yes      | - Unlock Bank1                                                 |
 211→   |----------------------------------------------------------------------------------------------------------------------------------|
 212→   |FLASH_LockBank1                     |    Yes     |      Yes      | - Lock Bank1                                                   |
 213→   |----------------------------------------------------------------------------------------------------------------------------------|
 214→   | FLASH_EraseAllBank1Pages           |    Yes     |      Yes      | - Erase all pages in Bank1                                     |
 215→   |----------------------------------------------------------------------------------------------------------------------------------|
 216→   | FLASH_GetBank1Status               |    Yes     |      Yes      | - Return the status of Bank1                                   |
 217→   |----------------------------------------------------------------------------------------------------------------------------------|
 218→   | FLASH_WaitForLastBank1Operation    |    Yes     |      Yes      | - Wait for Bank1 last operation                                |
 219→   +----------------------------------------------------------------------------------------------------------------------------------+
 220→
 221→   *****************************************************************************
 222→   * New Functions used only with STM32F10x_XL density devices to manage Bank2 *
 223→   *****************************************************************************
 224→   +----------------------------------------------------------------------------------------------------------------------------------+
 225→   |       Functions prototypes         |STM32F10x_XL|Other STM32F10x|    Comments                                                    |
 226→   |                                    |   devices  |  devices      |                                                                |
 227→   |----------------------------------------------------------------------------------------------------------------------------------|
 228→   | FLASH_UnlockBank2                  |    Yes     |      No       | - Unlock Bank2                                                 |
 229→   |----------------------------------------------------------------------------------------------------------------------------------|
 230→   |FLASH_LockBank2                     |    Yes     |      No       | - Lock Bank2                                                   |
 231→   |----------------------------------------------------------------------------------------------------------------------------------|
 232→   | FLASH_EraseAllBank2Pages           |    Yes     |      No       | - Erase all pages in Bank2                                     |
 233→   |----------------------------------------------------------------------------------------------------------------------------------|
 234→   | FLASH_GetBank2Status               |    Yes     |      No       | - Return the status of Bank2                                   |
 235→   |----------------------------------------------------------------------------------------------------------------------------------|
 236→   | FLASH_WaitForLastBank2Operation    |    Yes     |      No       | - Wait for Bank2 last operation                                |
 237→   |----------------------------------------------------------------------------------------------------------------------------------|
 238→   | FLASH_BootConfig                   |    Yes     |      No       | - Configure to boot from Bank1 or Bank2                        |
 239→   +----------------------------------------------------------------------------------------------------------------------------------+
 240→@endcode
 241→*/
 242→
 243→
 244→/**
 245→  * @brief  Sets the code latency value.
 246→  * @note   This function can be used for all STM32F10x devices.
 247→  * @param  FLASH_Latency: specifies the FLASH Latency value.
 248→  *   This parameter can be one of the following values:
 249→  *     @arg FLASH_Latency_0: FLASH Zero Latency cycle
 250→  *     @arg FLASH_Latency_1: FLASH One Latency cycle
 251→  *     @arg FLASH_Latency_2: FLASH Two Latency cycles
 252→  * @retval None
 253→  */
 254→void FLASH_SetLatency(uint32_t FLASH_Latency)
 255→{
 256→  uint32_t tmpreg = 0;
 257→  
 258→  /* Check the parameters */
 259→  assert_param(IS_FLASH_LATENCY(FLASH_Latency));
 260→  
 261→  /* Read the ACR register */
 262→  tmpreg = FLASH->ACR;  
 263→  
 264→  /* Sets the Latency value */
 265→  tmpreg &= ACR_LATENCY_Mask;
 266→  tmpreg |= FLASH_Latency;
 267→  
 268→  /* Write the ACR register */
 269→  FLASH->ACR = tmpreg;
 270→}
 271→
 272→/**
 273→  * @brief  Enables or disables the Half cycle flash access.
 274→  * @note   This function can be used for all STM32F10x devices.
 275→  * @param  FLASH_HalfCycleAccess: specifies the FLASH Half cycle Access mode.
 276→  *   This parameter can be one of the following values:
 277→  *     @arg FLASH_HalfCycleAccess_Enable: FLASH Half Cycle Enable
 278→  *     @arg FLASH_HalfCycleAccess_Disable: FLASH Half Cycle Disable
 279→  * @retval None
 280→  */
 281→void FLASH_HalfCycleAccessCmd(uint32_t FLASH_HalfCycleAccess)
 282→{
 283→  /* Check the parameters */
 284→  assert_param(IS_FLASH_HALFCYCLEACCESS_STATE(FLASH_HalfCycleAccess));
 285→  
 286→  /* Enable or disable the Half cycle access */
 287→  FLASH->ACR &= ACR_HLFCYA_Mask;
 288→  FLASH->ACR |= FLASH_HalfCycleAccess;
 289→}
 290→
 291→/**
 292→  * @brief  Enables or disables the Prefetch Buffer.
 293→  * @note   This function can be used for all STM32F10x devices.
 294→  * @param  FLASH_PrefetchBuffer: specifies the Prefetch buffer status.
 295→  *   This parameter can be one of the following values:
 296→  *     @arg FLASH_PrefetchBuffer_Enable: FLASH Prefetch Buffer Enable
 297→  *     @arg FLASH_PrefetchBuffer_Disable: FLASH Prefetch Buffer Disable
 298→  * @retval None
 299→  */
 300→void FLASH_PrefetchBufferCmd(uint32_t FLASH_PrefetchBuffer)
 301→{
 302→  /* Check the parameters */
 303→  assert_param(IS_FLASH_PREFETCHBUFFER_STATE(FLASH_PrefetchBuffer));
 304→  
 305→  /* Enable or disable the Prefetch Buffer */
 306→  FLASH->ACR &= ACR_PRFTBE_Mask;
 307→  FLASH->ACR |= FLASH_PrefetchBuffer;
 308→}
 309→
 310→/**
 311→  * @brief  Unlocks the FLASH Program Erase Controller.
 312→  * @note   This function can be used for all STM32F10x devices.
 313→  *         - For STM32F10X_XL devices this function unlocks Bank1 and Bank2.
 314→  *         - For all other devices it unlocks Bank1 and it is equivalent 
 315→  *           to FLASH_UnlockBank1 function.. 
 316→  * @param  None
 317→  * @retval None
 318→  */
 319→void FLASH_Unlock(void)
 320→{
 321→  /* Authorize the FPEC of Bank1 Access */
 322→  FLASH->KEYR = FLASH_KEY1;
 323→  FLASH->KEYR = FLASH_KEY2;
 324→
 325→#ifdef STM32F10X_XL
 326→  /* Authorize the FPEC of Bank2 Access */
 327→  FLASH->KEYR2 = FLASH_KEY1;
 328→  FLASH->KEYR2 = FLASH_KEY2;
 329→#endif /* STM32F10X_XL */
 330→}
 331→/**
 332→  * @brief  Unlocks the FLASH Bank1 Program Erase Controller.
 333→  * @note   This function can be used for all STM32F10x devices.
 334→  *         - For STM32F10X_XL devices this function unlocks Bank1.
 335→  *         - For all other devices it unlocks Bank1 and it is 
 336→  *           equivalent to FLASH_Unlock function.
 337→  * @param  None
 338→  * @retval None
 339→  */
 340→void FLASH_UnlockBank1(void)
 341→{
 342→  /* Authorize the FPEC of Bank1 Access */
 343→  FLASH->KEYR = FLASH_KEY1;
 344→  FLASH->KEYR = FLASH_KEY2;
 345→}
 346→
 347→#ifdef STM32F10X_XL
 348→/**
 349→  * @brief  Unlocks the FLASH Bank2 Program Erase Controller.
 350→  * @note   This function can be used only for STM32F10X_XL density devices.
 351→  * @param  None
 352→  * @retval None
 353→  */
 354→void FLASH_UnlockBank2(void)
 355→{
 356→  /* Authorize the FPEC of Bank2 Access */
 357→  FLASH->KEYR2 = FLASH_KEY1;
 358→  FLASH->KEYR2 = FLASH_KEY2;
 359→
 360→}
 361→#endif /* STM32F10X_XL */
 362→
 363→/**
 364→  * @brief  Locks the FLASH Program Erase Controller.
 365→  * @note   This function can be used for all STM32F10x devices.
 366→  *         - For STM32F10X_XL devices this function Locks Bank1 and Bank2.
 367→  *         - For all other devices it Locks Bank1 and it is equivalent 
 368→  *           to FLASH_LockBank1 function.
 369→  * @param  None
 370→  * @retval None
 371→  */
 372→void FLASH_Lock(void)
 373→{
 374→  /* Set the Lock Bit to lock the FPEC and the CR of  Bank1 */
 375→  FLASH->CR |= CR_LOCK_Set;
 376→
 377→#ifdef STM32F10X_XL
 378→  /* Set the Lock Bit to lock the FPEC and the CR of  Bank2 */
 379→  FLASH->CR2 |= CR_LOCK_Set;
 380→#endif /* STM32F10X_XL */
 381→}
 382→
 383→/**
 384→  * @brief  Locks the FLASH Bank1 Program Erase Controller.
 385→  * @note   this function can be used for all STM32F10x devices.
 386→  *         - For STM32F10X_XL devices this function Locks Bank1.
 387→  *         - For all other devices it Locks Bank1 and it is equivalent 
 388→  *           to FLASH_Lock function.
 389→  * @param  None
 390→  * @retval None
 391→  */
 392→void FLASH_LockBank1(void)
 393→{
 394→  /* Set the Lock Bit to lock the FPEC and the CR of  Bank1 */
 395→  FLASH->CR |= CR_LOCK_Set;
 396→}
 397→
 398→#ifdef STM32F10X_XL
 399→/**
 400→  * @brief  Locks the FLASH Bank2 Program Erase Controller.
 401→  * @note   This function can be used only for STM32F10X_XL density devices.
 402→  * @param  None
 403→  * @retval None
 404→  */
 405→void FLASH_LockBank2(void)
 406→{
 407→  /* Set the Lock Bit to lock the FPEC and the CR of  Bank2 */
 408→  FLASH->CR2 |= CR_LOCK_Set;
 409→}
 410→#endif /* STM32F10X_XL */
 411→
 412→/**
 413→  * @brief  Erases a specified FLASH page.
 414→  * @note   This function can be used for all STM32F10x devices.
 415→  * @param  Page_Address: The page address to be erased.
 416→  * @retval FLASH Status: The returned value can be: FLASH_BUSY, FLASH_ERROR_PG,
 417→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
 418→  */
 419→FLASH_Status FLASH_ErasePage(uint32_t Page_Address)
 420→{
 421→  FLASH_Status status = FLASH_COMPLETE;
 422→  /* Check the parameters */
 423→  assert_param(IS_FLASH_ADDRESS(Page_Address));
 424→
 425→#ifdef STM32F10X_XL
 426→  if(Page_Address < FLASH_BANK1_END_ADDRESS)  
 427→  {
 428→    /* Wait for last operation to be completed */
 429→    status = FLASH_WaitForLastBank1Operation(EraseTimeout);
 430→    if(status == FLASH_COMPLETE)
 431→    { 
 432→      /* if the previous operation is completed, proceed to erase the page */
 433→      FLASH->CR|= CR_PER_Set;
 434→      FLASH->AR = Page_Address; 
 435→      FLASH->CR|= CR_STRT_Set;
 436→    
 437→      /* Wait for last operation to be completed */
 438→      status = FLASH_WaitForLastBank1Operation(EraseTimeout);
 439→
 440→      /* Disable the PER Bit */
 441→      FLASH->CR &= CR_PER_Reset;
 442→    }
 443→  }
 444→  else
 445→  {
 446→    /* Wait for last operation to be completed */
 447→    status = FLASH_WaitForLastBank2Operation(EraseTimeout);
 448→    if(status == FLASH_COMPLETE)
 449→    { 
 450→      /* if the previous operation is completed, proceed to erase the page */
 451→      FLASH->CR2|= CR_PER_Set;
 452→      FLASH->AR2 = Page_Address; 
 453→      FLASH->CR2|= CR_STRT_Set;
 454→    
 455→      /* Wait for last operation to be completed */
 456→      status = FLASH_WaitForLastBank2Operation(EraseTimeout);
 457→      
 458→      /* Disable the PER Bit */
 459→      FLASH->CR2 &= CR_PER_Reset;
 460→    }
 461→  }
 462→#else
 463→  /* Wait for last operation to be completed */
 464→  status = FLASH_WaitForLastOperation(EraseTimeout);
 465→  
 466→  if(status == FLASH_COMPLETE)
 467→  { 
 468→    /* if the previous operation is completed, proceed to erase the page */
 469→    FLASH->CR|= CR_PER_Set;
 470→    FLASH->AR = Page_Address; 
 471→    FLASH->CR|= CR_STRT_Set;
 472→    
 473→    /* Wait for last operation to be completed */
 474→    status = FLASH_WaitForLastOperation(EraseTimeout);
 475→    
 476→    /* Disable the PER Bit */
 477→    FLASH->CR &= CR_PER_Reset;
 478→  }
 479→#endif /* STM32F10X_XL */
 480→
 481→  /* Return the Erase Status */
 482→  return status;
 483→}
 484→
 485→/**
 486→  * @brief  Erases all FLASH pages.
 487→  * @note   This function can be used for all STM32F10x devices.
 488→  * @param  None
 489→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
 490→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
 491→  */
 492→FLASH_Status FLASH_EraseAllPages(void)
 493→{
 494→  FLASH_Status status = FLASH_COMPLETE;
 495→
 496→#ifdef STM32F10X_XL
 497→  /* Wait for last operation to be completed */
 498→  status = FLASH_WaitForLastBank1Operation(EraseTimeout);
 499→  
 500→  if(status == FLASH_COMPLETE)
 501→  {
 502→    /* if the previous operation is completed, proceed to erase all pages */
 503→     FLASH->CR |= CR_MER_Set;
 504→     FLASH->CR |= CR_STRT_Set;
 505→    
 506→    /* Wait for last operation to be completed */
 507→    status = FLASH_WaitForLastBank1Operation(EraseTimeout);
 508→    
 509→    /* Disable the MER Bit */
 510→    FLASH->CR &= CR_MER_Reset;
 511→  }    
 512→  if(status == FLASH_COMPLETE)
 513→  {
 514→    /* if the previous operation is completed, proceed to erase all pages */
 515→     FLASH->CR2 |= CR_MER_Set;
 516→     FLASH->CR2 |= CR_STRT_Set;
 517→    
 518→    /* Wait for last operation to be completed */
 519→    status = FLASH_WaitForLastBank2Operation(EraseTimeout);
 520→    
 521→    /* Disable the MER Bit */
 522→    FLASH->CR2 &= CR_MER_Reset;
 523→  }
 524→#else
 525→  /* Wait for last operation to be completed */
 526→  status = FLASH_WaitForLastOperation(EraseTimeout);
 527→  if(status == FLASH_COMPLETE)
 528→  {
 529→    /* if the previous operation is completed, proceed to erase all pages */
 530→     FLASH->CR |= CR_MER_Set;
 531→     FLASH->CR |= CR_STRT_Set;
 532→    
 533→    /* Wait for last operation to be completed */
 534→    status = FLASH_WaitForLastOperation(EraseTimeout);
 535→
 536→    /* Disable the MER Bit */
 537→    FLASH->CR &= CR_MER_Reset;
 538→  }
 539→#endif /* STM32F10X_XL */
 540→
 541→  /* Return the Erase Status */
 542→  return status;
 543→}
 544→
 545→/**
 546→  * @brief  Erases all Bank1 FLASH pages.
 547→  * @note   This function can be used for all STM32F10x devices.
 548→  *         - For STM32F10X_XL devices this function erases all Bank1 pages.
 549→  *         - For all other devices it erases all Bank1 pages and it is equivalent 
 550→  *           to FLASH_EraseAllPages function.
 551→  * @param  None
 552→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
 553→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
 554→  */
 555→FLASH_Status FLASH_EraseAllBank1Pages(void)
 556→{
 557→  FLASH_Status status = FLASH_COMPLETE;
 558→  /* Wait for last operation to be completed */
 559→  status = FLASH_WaitForLastBank1Operation(EraseTimeout);
 560→  
 561→  if(status == FLASH_COMPLETE)
 562→  {
 563→    /* if the previous operation is completed, proceed to erase all pages */
 564→     FLASH->CR |= CR_MER_Set;
 565→     FLASH->CR |= CR_STRT_Set;
 566→    
 567→    /* Wait for last operation to be completed */
 568→    status = FLASH_WaitForLastBank1Operation(EraseTimeout);
 569→    
 570→    /* Disable the MER Bit */
 571→    FLASH->CR &= CR_MER_Reset;
 572→  }    
 573→  /* Return the Erase Status */
 574→  return status;
 575→}
 576→
 577→#ifdef STM32F10X_XL
 578→/**
 579→  * @brief  Erases all Bank2 FLASH pages.
 580→  * @note   This function can be used only for STM32F10x_XL density devices.
 581→  * @param  None
 582→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
 583→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
 584→  */
 585→FLASH_Status FLASH_EraseAllBank2Pages(void)
 586→{
 587→  FLASH_Status status = FLASH_COMPLETE;
 588→  /* Wait for last operation to be completed */
 589→  status = FLASH_WaitForLastBank2Operation(EraseTimeout);
 590→  
 591→  if(status == FLASH_COMPLETE)
 592→  {
 593→    /* if the previous operation is completed, proceed to erase all pages */
 594→     FLASH->CR2 |= CR_MER_Set;
 595→     FLASH->CR2 |= CR_STRT_Set;
 596→    
 597→    /* Wait for last operation to be completed */
 598→    status = FLASH_WaitForLastBank2Operation(EraseTimeout);
 599→
 600→    /* Disable the MER Bit */
 601→    FLASH->CR2 &= CR_MER_Reset;
 602→  }    
 603→  /* Return the Erase Status */
 604→  return status;
 605→}
 606→#endif /* STM32F10X_XL */
 607→
 608→/**
 609→  * @brief  Erases the FLASH option bytes.
 610→  * @note   This functions erases all option bytes except the Read protection (RDP). 
 611→  * @note   This function can be used for all STM32F10x devices.
 612→  * @param  None
 613→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
 614→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
 615→  */
 616→FLASH_Status FLASH_EraseOptionBytes(void)
 617→{
 618→  uint16_t rdptmp = RDP_Key;
 619→
 620→  FLASH_Status status = FLASH_COMPLETE;
 621→
 622→  /* Get the actual read protection Option Byte value */ 
 623→  if(FLASH_GetReadOutProtectionStatus() != RESET)
 624→  {
 625→    rdptmp = 0x00;  
 626→  }
 627→
 628→  /* Wait for last operation to be completed */
 629→  status = FLASH_WaitForLastOperation(EraseTimeout);
 630→  if(status == FLASH_COMPLETE)
 631→  {
 632→    /* Authorize the small information block programming */
 633→    FLASH->OPTKEYR = FLASH_KEY1;
 634→    FLASH->OPTKEYR = FLASH_KEY2;
 635→    
 636→    /* if the previous operation is completed, proceed to erase the option bytes */
 637→    FLASH->CR |= CR_OPTER_Set;
 638→    FLASH->CR |= CR_STRT_Set;
 639→    /* Wait for last operation to be completed */
 640→    status = FLASH_WaitForLastOperation(EraseTimeout);
 641→    
 642→    if(status == FLASH_COMPLETE)
 643→    {
 644→      /* if the erase operation is completed, disable the OPTER Bit */
 645→      FLASH->CR &= CR_OPTER_Reset;
 646→       
 647→      /* Enable the Option Bytes Programming operation */
 648→      FLASH->CR |= CR_OPTPG_Set;
 649→      /* Restore the last read protection Option Byte value */
 650→      OB->RDP = (uint16_t)rdptmp; 
 651→      /* Wait for last operation to be completed */
 652→      status = FLASH_WaitForLastOperation(ProgramTimeout);
 653→ 
 654→      if(status != FLASH_TIMEOUT)
 655→      {
 656→        /* if the program operation is completed, disable the OPTPG Bit */
 657→        FLASH->CR &= CR_OPTPG_Reset;
 658→      }
 659→    }
 660→    else
 661→    {
 662→      if (status != FLASH_TIMEOUT)
 663→      {
 664→        /* Disable the OPTPG Bit */
 665→        FLASH->CR &= CR_OPTPG_Reset;
 666→      }
 667→    }  
 668→  }
 669→  /* Return the erase status */
 670→  return status;
 671→}
 672→
 673→/**
 674→  * @brief  Programs a word at a specified address.
 675→  * @note   This function can be used for all STM32F10x devices.
 676→  * @param  Address: specifies the address to be programmed.
 677→  * @param  Data: specifies the data to be programmed.
 678→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
 679→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT. 
 680→  */
 681→FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data)
 682→{
 683→  FLASH_Status status = FLASH_COMPLETE;
 684→  __IO uint32_t tmp = 0;
 685→
 686→  /* Check the parameters */
 687→  assert_param(IS_FLASH_ADDRESS(Address));
 688→
 689→#ifdef STM32F10X_XL
 690→  if(Address < FLASH_BANK1_END_ADDRESS - 2)
 691→  { 
 692→    /* Wait for last operation to be completed */
 693→    status = FLASH_WaitForLastBank1Operation(ProgramTimeout); 
 694→    if(status == FLASH_COMPLETE)
 695→    {
 696→      /* if the previous operation is completed, proceed to program the new first 
 697→        half word */
 698→      FLASH->CR |= CR_PG_Set;
 699→  
 700→      *(__IO uint16_t*)Address = (uint16_t)Data;
 701→      /* Wait for last operation to be completed */
 702→      status = FLASH_WaitForLastOperation(ProgramTimeout);
 703→ 
 704→      if(status == FLASH_COMPLETE)
 705→      {
 706→        /* if the previous operation is completed, proceed to program the new second 
 707→        half word */
 708→        tmp = Address + 2;
 709→
 710→        *(__IO uint16_t*) tmp = Data >> 16;
 711→    
 712→        /* Wait for last operation to be completed */
 713→        status = FLASH_WaitForLastOperation(ProgramTimeout);
 714→        
 715→        /* Disable the PG Bit */
 716→        FLASH->CR &= CR_PG_Reset;
 717→      }
 718→      else
 719→      {
 720→        /* Disable the PG Bit */
 721→        FLASH->CR &= CR_PG_Reset;
 722→       }
 723→    }
 724→  }
 725→  else if(Address == (FLASH_BANK1_END_ADDRESS - 1))
 726→  {
 727→    /* Wait for last operation to be completed */
 728→    status = FLASH_WaitForLastBank1Operation(ProgramTimeout);
 729→
 730→    if(status == FLASH_COMPLETE)
 731→    {
 732→      /* if the previous operation is completed, proceed to program the new first 
 733→        half word */
 734→      FLASH->CR |= CR_PG_Set;
 735→  
 736→      *(__IO uint16_t*)Address = (uint16_t)Data;
 737→
 738→      /* Wait for last operation to be completed */
 739→      status = FLASH_WaitForLastBank1Operation(ProgramTimeout);
 740→      
 741→	  /* Disable the PG Bit */
 742→      FLASH->CR &= CR_PG_Reset;
 743→    }
 744→    else
 745→    {
 746→      /* Disable the PG Bit */
 747→      FLASH->CR &= CR_PG_Reset;
 748→    }
 749→
 750→    /* Wait for last operation to be completed */
 751→    status = FLASH_WaitForLastBank2Operation(ProgramTimeout);
 752→
 753→    if(status == FLASH_COMPLETE)
 754→    {
 755→      /* if the previous operation is completed, proceed to program the new second 
 756→      half word */
 757→      FLASH->CR2 |= CR_PG_Set;
 758→      tmp = Address + 2;
 759→
 760→      *(__IO uint16_t*) tmp = Data >> 16;
 761→    
 762→      /* Wait for last operation to be completed */
 763→      status = FLASH_WaitForLastBank2Operation(ProgramTimeout);
 764→        
 765→      /* Disable the PG Bit */
 766→      FLASH->CR2 &= CR_PG_Reset;
 767→    }
 768→    else
 769→    {
 770→      /* Disable the PG Bit */
 771→      FLASH->CR2 &= CR_PG_Reset;
 772→    }
 773→  }
 774→  else
 775→  {
 776→    /* Wait for last operation to be completed */
 777→    status = FLASH_WaitForLastBank2Operation(ProgramTimeout);
 778→
 779→    if(status == FLASH_COMPLETE)
 780→    {
 781→      /* if the previous operation is completed, proceed to program the new first 
 782→        half word */
 783→      FLASH->CR2 |= CR_PG_Set;
 784→  
 785→      *(__IO uint16_t*)Address = (uint16_t)Data;
 786→      /* Wait for last operation to be completed */
 787→      status = FLASH_WaitForLastBank2Operation(ProgramTimeout);
 788→ 
 789→      if(status == FLASH_COMPLETE)
 790→      {
 791→        /* if the previous operation is completed, proceed to program the new second 
 792→        half word */
 793→        tmp = Address + 2;
 794→
 795→        *(__IO uint16_t*) tmp = Data >> 16;
 796→    
 797→        /* Wait for last operation to be completed */
 798→        status = FLASH_WaitForLastBank2Operation(ProgramTimeout);
 799→        
 800→        /* Disable the PG Bit */
 801→        FLASH->CR2 &= CR_PG_Reset;
 802→      }
 803→      else
 804→      {
 805→        /* Disable the PG Bit */
 806→        FLASH->CR2 &= CR_PG_Reset;
 807→      }
 808→    }
 809→  }
 810→#else
 811→  /* Wait for last operation to be completed */
 812→  status = FLASH_WaitForLastOperation(ProgramTimeout);
 813→  
 814→  if(status == FLASH_COMPLETE)
 815→  {
 816→    /* if the previous operation is completed, proceed to program the new first 
 817→    half word */
 818→    FLASH->CR |= CR_PG_Set;
 819→  
 820→    *(__IO uint16_t*)Address = (uint16_t)Data;
 821→    /* Wait for last operation to be completed */
 822→    status = FLASH_WaitForLastOperation(ProgramTimeout);
 823→ 
 824→    if(status == FLASH_COMPLETE)
 825→    {
 826→      /* if the previous operation is completed, proceed to program the new second 
 827→      half word */
 828→      tmp = Address + 2;
 829→
 830→      *(__IO uint16_t*) tmp = Data >> 16;
 831→    
 832→      /* Wait for last operation to be completed */
 833→      status = FLASH_WaitForLastOperation(ProgramTimeout);
 834→        
 835→      /* Disable the PG Bit */
 836→      FLASH->CR &= CR_PG_Reset;
 837→    }
 838→    else
 839→    {
 840→      /* Disable the PG Bit */
 841→      FLASH->CR &= CR_PG_Reset;
 842→    }
 843→  }         
 844→#endif /* STM32F10X_XL */
 845→   
 846→  /* Return the Program Status */
 847→  return status;
 848→}
 849→
 850→/**
 851→  * @brief  Programs a half word at a specified address.
 852→  * @note   This function can be used for all STM32F10x devices.
 853→  * @param  Address: specifies the address to be programmed.
 854→  * @param  Data: specifies the data to be programmed.
 855→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
 856→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT. 
 857→  */
 858→FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data)
 859→{
 860→  FLASH_Status status = FLASH_COMPLETE;
 861→  /* Check the parameters */
 862→  assert_param(IS_FLASH_ADDRESS(Address));
 863→
 864→#ifdef STM32F10X_XL
 865→  /* Wait for last operation to be completed */
 866→  status = FLASH_WaitForLastOperation(ProgramTimeout);
 867→  
 868→  if(Address < FLASH_BANK1_END_ADDRESS)
 869→  {
 870→    if(status == FLASH_COMPLETE)
 871→    {
 872→      /* if the previous operation is completed, proceed to program the new data */
 873→      FLASH->CR |= CR_PG_Set;
 874→  
 875→      *(__IO uint16_t*)Address = Data;
 876→      /* Wait for last operation to be completed */
 877→      status = FLASH_WaitForLastBank1Operation(ProgramTimeout);
 878→
 879→      /* Disable the PG Bit */
 880→      FLASH->CR &= CR_PG_Reset;
 881→    }
 882→  }
 883→  else
 884→  {
 885→    if(status == FLASH_COMPLETE)
 886→    {
 887→      /* if the previous operation is completed, proceed to program the new data */
 888→      FLASH->CR2 |= CR_PG_Set;
 889→  
 890→      *(__IO uint16_t*)Address = Data;
 891→      /* Wait for last operation to be completed */
 892→      status = FLASH_WaitForLastBank2Operation(ProgramTimeout);
 893→
 894→      /* Disable the PG Bit */
 895→      FLASH->CR2 &= CR_PG_Reset;
 896→    }
 897→  }
 898→#else
 899→  /* Wait for last operation to be completed */
 900→  status = FLASH_WaitForLastOperation(ProgramTimeout);
 901→  
 902→  if(status == FLASH_COMPLETE)
 903→  {
 904→    /* if the previous operation is completed, proceed to program the new data */
 905→    FLASH->CR |= CR_PG_Set;
 906→  
 907→    *(__IO uint16_t*)Address = Data;
 908→    /* Wait for last operation to be completed */
 909→    status = FLASH_WaitForLastOperation(ProgramTimeout);
 910→    
 911→    /* Disable the PG Bit */
 912→    FLASH->CR &= CR_PG_Reset;
 913→  } 
 914→#endif  /* STM32F10X_XL */
 915→  
 916→  /* Return the Program Status */
 917→  return status;
 918→}
 919→
 920→/**
 921→  * @brief  Programs a half word at a specified Option Byte Data address.
 922→  * @note   This function can be used for all STM32F10x devices.
 923→  * @param  Address: specifies the address to be programmed.
 924→  *   This parameter can be 0x1FFFF804 or 0x1FFFF806. 
 925→  * @param  Data: specifies the data to be programmed.
 926→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
 927→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT. 
 928→  */
 929→FLASH_Status FLASH_ProgramOptionByteData(uint32_t Address, uint8_t Data)
 930→{
 931→  FLASH_Status status = FLASH_COMPLETE;
 932→  /* Check the parameters */
 933→  assert_param(IS_OB_DATA_ADDRESS(Address));
 934→  status = FLASH_WaitForLastOperation(ProgramTimeout);
 935→
 936→  if(status == FLASH_COMPLETE)
 937→  {
 938→    /* Authorize the small information block programming */
 939→    FLASH->OPTKEYR = FLASH_KEY1;
 940→    FLASH->OPTKEYR = FLASH_KEY2;
 941→    /* Enables the Option Bytes Programming operation */
 942→    FLASH->CR |= CR_OPTPG_Set; 
 943→    *(__IO uint16_t*)Address = Data;
 944→    
 945→    /* Wait for last operation to be completed */
 946→    status = FLASH_WaitForLastOperation(ProgramTimeout);
 947→    if(status != FLASH_TIMEOUT)
 948→    {
 949→      /* if the program operation is completed, disable the OPTPG Bit */
 950→      FLASH->CR &= CR_OPTPG_Reset;
 951→    }
 952→  }
 953→  /* Return the Option Byte Data Program Status */
 954→  return status;
 955→}
 956→
 957→/**
 958→  * @brief  Write protects the desired pages
 959→  * @note   This function can be used for all STM32F10x devices.
 960→  * @param  FLASH_Pages: specifies the address of the pages to be write protected.
 961→  *   This parameter can be:
 962→  *     @arg For @b STM32_Low-density_devices: value between FLASH_WRProt_Pages0to3 and FLASH_WRProt_Pages28to31  
 963→  *     @arg For @b STM32_Medium-density_devices: value between FLASH_WRProt_Pages0to3
 964→  *       and FLASH_WRProt_Pages124to127
 965→  *     @arg For @b STM32_High-density_devices: value between FLASH_WRProt_Pages0to1 and
 966→  *       FLASH_WRProt_Pages60to61 or FLASH_WRProt_Pages62to255
 967→  *     @arg For @b STM32_Connectivity_line_devices: value between FLASH_WRProt_Pages0to1 and
 968→  *       FLASH_WRProt_Pages60to61 or FLASH_WRProt_Pages62to127    
 969→  *     @arg For @b STM32_XL-density_devices: value between FLASH_WRProt_Pages0to1 and
 970→  *       FLASH_WRProt_Pages60to61 or FLASH_WRProt_Pages62to511
 971→  *     @arg FLASH_WRProt_AllPages
 972→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
 973→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
 974→  */
 975→FLASH_Status FLASH_EnableWriteProtection(uint32_t FLASH_Pages)
 976→{
 977→  uint16_t WRP0_Data = 0xFFFF, WRP1_Data = 0xFFFF, WRP2_Data = 0xFFFF, WRP3_Data = 0xFFFF;
 978→  
 979→  FLASH_Status status = FLASH_COMPLETE;
 980→  
 981→  /* Check the parameters */
 982→  assert_param(IS_FLASH_WRPROT_PAGE(FLASH_Pages));
 983→  
 984→  FLASH_Pages = (uint32_t)(~FLASH_Pages);
 985→  WRP0_Data = (uint16_t)(FLASH_Pages & WRP0_Mask);
 986→  WRP1_Data = (uint16_t)((FLASH_Pages & WRP1_Mask) >> 8);
 987→  WRP2_Data = (uint16_t)((FLASH_Pages & WRP2_Mask) >> 16);
 988→  WRP3_Data = (uint16_t)((FLASH_Pages & WRP3_Mask) >> 24);
 989→  
 990→  /* Wait for last operation to be completed */
 991→  status = FLASH_WaitForLastOperation(ProgramTimeout);
 992→  
 993→  if(status == FLASH_COMPLETE)
 994→  {
 995→    /* Authorizes the small information block programming */
 996→    FLASH->OPTKEYR = FLASH_KEY1;
 997→    FLASH->OPTKEYR = FLASH_KEY2;
 998→    FLASH->CR |= CR_OPTPG_Set;
 999→    if(WRP0_Data != 0xFF)
1000→    {
1001→      OB->WRP0 = WRP0_Data;
1002→      
1003→      /* Wait for last operation to be completed */
1004→      status = FLASH_WaitForLastOperation(ProgramTimeout);
1005→    }
1006→    if((status == FLASH_COMPLETE) && (WRP1_Data != 0xFF))
1007→    {
1008→      OB->WRP1 = WRP1_Data;
1009→      
1010→      /* Wait for last operation to be completed */
1011→      status = FLASH_WaitForLastOperation(ProgramTimeout);
1012→    }
1013→    if((status == FLASH_COMPLETE) && (WRP2_Data != 0xFF))
1014→    {
1015→      OB->WRP2 = WRP2_Data;
1016→      
1017→      /* Wait for last operation to be completed */
1018→      status = FLASH_WaitForLastOperation(ProgramTimeout);
1019→    }
1020→    
1021→    if((status == FLASH_COMPLETE)&& (WRP3_Data != 0xFF))
1022→    {
1023→      OB->WRP3 = WRP3_Data;
1024→     
1025→      /* Wait for last operation to be completed */
1026→      status = FLASH_WaitForLastOperation(ProgramTimeout);
1027→    }
1028→          
1029→    if(status != FLASH_TIMEOUT)
1030→    {
1031→      /* if the program operation is completed, disable the OPTPG Bit */
1032→      FLASH->CR &= CR_OPTPG_Reset;
1033→    }
1034→  } 
1035→  /* Return the write protection operation Status */
1036→  return status;       
1037→}
1038→
1039→/**
1040→  * @brief  Enables or disables the read out protection.
1041→  * @note   If the user has already programmed the other option bytes before calling 
1042→  *   this function, he must re-program them since this function erases all option bytes.
1043→  * @note   This function can be used for all STM32F10x devices.
1044→  * @param  Newstate: new state of the ReadOut Protection.
1045→  *   This parameter can be: ENABLE or DISABLE.
1046→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
1047→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
1048→  */
1049→FLASH_Status FLASH_ReadOutProtection(FunctionalState NewState)
1050→{
1051→  FLASH_Status status = FLASH_COMPLETE;
1052→  /* Check the parameters */
1053→  assert_param(IS_FUNCTIONAL_STATE(NewState));
1054→  status = FLASH_WaitForLastOperation(EraseTimeout);
1055→  if(status == FLASH_COMPLETE)
1056→  {
1057→    /* Authorizes the small information block programming */
1058→    FLASH->OPTKEYR = FLASH_KEY1;
1059→    FLASH->OPTKEYR = FLASH_KEY2;
1060→    FLASH->CR |= CR_OPTER_Set;
1061→    FLASH->CR |= CR_STRT_Set;
1062→    /* Wait for last operation to be completed */
1063→    status = FLASH_WaitForLastOperation(EraseTimeout);
1064→    if(status == FLASH_COMPLETE)
1065→    {
1066→      /* if the erase operation is completed, disable the OPTER Bit */
1067→      FLASH->CR &= CR_OPTER_Reset;
1068→      /* Enable the Option Bytes Programming operation */
1069→      FLASH->CR |= CR_OPTPG_Set; 
1070→      if(NewState != DISABLE)
1071→      {
1072→        OB->RDP = 0x00;
1073→      }
1074→      else
1075→      {
1076→        OB->RDP = RDP_Key;  
1077→      }
1078→      /* Wait for last operation to be completed */
1079→      status = FLASH_WaitForLastOperation(EraseTimeout); 
1080→    
1081→      if(status != FLASH_TIMEOUT)
1082→      {
1083→        /* if the program operation is completed, disable the OPTPG Bit */
1084→        FLASH->CR &= CR_OPTPG_Reset;
1085→      }
1086→    }
1087→    else 
1088→    {
1089→      if(status != FLASH_TIMEOUT)
1090→      {
1091→        /* Disable the OPTER Bit */
1092→        FLASH->CR &= CR_OPTER_Reset;
1093→      }
1094→    }
1095→  }
1096→  /* Return the protection operation Status */
1097→  return status;       
1098→}
1099→
1100→/**
1101→  * @brief  Programs the FLASH User Option Byte: IWDG_SW / RST_STOP / RST_STDBY.
1102→  * @note   This function can be used for all STM32F10x devices.
1103→  * @param  OB_IWDG: Selects the IWDG mode
1104→  *   This parameter can be one of the following values:
1105→  *     @arg OB_IWDG_SW: Software IWDG selected
1106→  *     @arg OB_IWDG_HW: Hardware IWDG selected
1107→  * @param  OB_STOP: Reset event when entering STOP mode.
1108→  *   This parameter can be one of the following values:
1109→  *     @arg OB_STOP_NoRST: No reset generated when entering in STOP
1110→  *     @arg OB_STOP_RST: Reset generated when entering in STOP
1111→  * @param  OB_STDBY: Reset event when entering Standby mode.
1112→  *   This parameter can be one of the following values:
1113→  *     @arg OB_STDBY_NoRST: No reset generated when entering in STANDBY
1114→  *     @arg OB_STDBY_RST: Reset generated when entering in STANDBY
1115→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG, 
1116→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
1117→  */
1118→FLASH_Status FLASH_UserOptionByteConfig(uint16_t OB_IWDG, uint16_t OB_STOP, uint16_t OB_STDBY)
1119→{
1120→  FLASH_Status status = FLASH_COMPLETE; 
1121→
1122→  /* Check the parameters */
1123→  assert_param(IS_OB_IWDG_SOURCE(OB_IWDG));
1124→  assert_param(IS_OB_STOP_SOURCE(OB_STOP));
1125→  assert_param(IS_OB_STDBY_SOURCE(OB_STDBY));
1126→
1127→  /* Authorize the small information block programming */
1128→  FLASH->OPTKEYR = FLASH_KEY1;
1129→  FLASH->OPTKEYR = FLASH_KEY2;
1130→  
1131→  /* Wait for last operation to be completed */
1132→  status = FLASH_WaitForLastOperation(ProgramTimeout);
1133→  
1134→  if(status == FLASH_COMPLETE)
1135→  {  
1136→    /* Enable the Option Bytes Programming operation */
1137→    FLASH->CR |= CR_OPTPG_Set; 
1138→           
1139→    OB->USER = OB_IWDG | (uint16_t)(OB_STOP | (uint16_t)(OB_STDBY | ((uint16_t)0xF8))); 
1140→  
1141→    /* Wait for last operation to be completed */
1142→    status = FLASH_WaitForLastOperation(ProgramTimeout);
1143→    if(status != FLASH_TIMEOUT)
1144→    {
1145→      /* if the program operation is completed, disable the OPTPG Bit */
1146→      FLASH->CR &= CR_OPTPG_Reset;
1147→    }
1148→  }    
1149→  /* Return the Option Byte program Status */
1150→  return status;
1151→}
1152→
1153→#ifdef STM32F10X_XL
1154→/**
1155→  * @brief  Configures to boot from Bank1 or Bank2.  
1156→  * @note   This function can be used only for STM32F10x_XL density devices.
1157→  * @param  FLASH_BOOT: select the FLASH Bank to boot from.
1158→  *   This parameter can be one of the following values:
1159→  *     @arg FLASH_BOOT_Bank1: At startup, if boot pins are set in boot from user Flash
1160→  *        position and this parameter is selected the device will boot from Bank1(Default).
1161→  *     @arg FLASH_BOOT_Bank2: At startup, if boot pins are set in boot from user Flash
1162→  *        position and this parameter is selected the device will boot from Bank2 or Bank1,
1163→  *        depending on the activation of the bank. The active banks are checked in
1164→  *        the following order: Bank2, followed by Bank1.
1165→  *        The active bank is recognized by the value programmed at the base address
1166→  *        of the respective bank (corresponding to the initial stack pointer value
1167→  *        in the interrupt vector table).
1168→  *        For more information, please refer to AN2606 from www.st.com.    
1169→  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG, 
1170→  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
1171→  */
1172→FLASH_Status FLASH_BootConfig(uint16_t FLASH_BOOT)
1173→{ 
1174→  FLASH_Status status = FLASH_COMPLETE; 
1175→  assert_param(IS_FLASH_BOOT(FLASH_BOOT));
1176→  /* Authorize the small information block programming */
1177→  FLASH->OPTKEYR = FLASH_KEY1;
1178→  FLASH->OPTKEYR = FLASH_KEY2;
1179→  
1180→  /* Wait for last operation to be completed */
1181→  status = FLASH_WaitForLastOperation(ProgramTimeout);
1182→  
1183→  if(status == FLASH_COMPLETE)
1184→  {  
1185→    /* Enable the Option Bytes Programming operation */
1186→    FLASH->CR |= CR_OPTPG_Set; 
1187→
1188→    if(FLASH_BOOT == FLASH_BOOT_Bank1)
1189→    {
1190→      OB->USER |= OB_USER_BFB2;
1191→    }
1192→    else
1193→    {
1194→      OB->USER &= (uint16_t)(~(uint16_t)(OB_USER_BFB2));
1195→    }
1196→    /* Wait for last operation to be completed */
1197→    status = FLASH_WaitForLastOperation(ProgramTimeout);
1198→    if(status != FLASH_TIMEOUT)
1199→    {
1200→      /* if the program operation is completed, disable the OPTPG Bit */
1201→      FLASH->CR &= CR_OPTPG_Reset;
1202→    }
1203→  }    
1204→  /* Return the Option Byte program Status */
1205→  return status;
1206→}
1207→#endif /* STM32F10X_XL */
1208→
1209→/**
1210→  * @brief  Returns the FLASH User Option Bytes values.
1211→  * @note   This function can be used for all STM32F10x devices.
1212→  * @param  None
1213→  * @retval The FLASH User Option Bytes values:IWDG_SW(Bit0), RST_STOP(Bit1)
1214→  *         and RST_STDBY(Bit2).
1215→  */
1216→uint32_t FLASH_GetUserOptionByte(void)
1217→{
1218→  /* Return the User Option Byte */
1219→  return (uint32_t)(FLASH->OBR >> 2);
1220→}
1221→
1222→/**
1223→  * @brief  Returns the FLASH Write Protection Option Bytes Register value.
1224→  * @note   This function can be used for all STM32F10x devices.
1225→  * @param  None
1226→  * @retval The FLASH Write Protection  Option Bytes Register value
1227→  */
1228→uint32_t FLASH_GetWriteProtectionOptionByte(void)
1229→{
1230→  /* Return the Flash write protection Register value */
1231→  return (uint32_t)(FLASH->WRPR);
1232→}
1233→
1234→/**
1235→  * @brief  Checks whether the FLASH Read Out Protection Status is set or not.
1236→  * @note   This function can be used for all STM32F10x devices.
1237→  * @param  None
1238→  * @retval FLASH ReadOut Protection Status(SET or RESET)
1239→  */
1240→FlagStatus FLASH_GetReadOutProtectionStatus(void)
1241→{
1242→  FlagStatus readoutstatus = RESET;
1243→  if ((FLASH->OBR & RDPRT_Mask) != (uint32_t)RESET)
1244→  {
1245→    readoutstatus = SET;
1246→  }
1247→  else
1248→  {
1249→    readoutstatus = RESET;
1250→  }
1251→  return readoutstatus;
1252→}
1253→
1254→/**
1255→  * @brief  Checks whether the FLASH Prefetch Buffer status is set or not.
1256→  * @note   This function can be used for all STM32F10x devices.
1257→  * @param  None
1258→  * @retval FLASH Prefetch Buffer Status (SET or RESET).
1259→  */
1260→FlagStatus FLASH_GetPrefetchBufferStatus(void)
1261→{
1262→  FlagStatus bitstatus = RESET;
1263→  
1264→  if ((FLASH->ACR & ACR_PRFTBS_Mask) != (uint32_t)RESET)
1265→  {
1266→    bitstatus = SET;
1267→  }
1268→  else
1269→  {
1270→    bitstatus = RESET;
1271→  }
1272→  /* Return the new state of FLASH Prefetch Buffer Status (SET or RESET) */
1273→  return bitstatus; 
1274→}
1275→
1276→/**
1277→  * @brief  Enables or disables the specified FLASH interrupts.
1278→  * @note   This function can be used for all STM32F10x devices.
1279→  *         - For STM32F10X_XL devices, enables or disables the specified FLASH interrupts
1280→              for Bank1 and Bank2.
1281→  *         - For other devices it enables or disables the specified FLASH interrupts for Bank1.
1282→  * @param  FLASH_IT: specifies the FLASH interrupt sources to be enabled or disabled.
1283→  *   This parameter can be any combination of the following values:
1284→  *     @arg FLASH_IT_ERROR: FLASH Error Interrupt
1285→  *     @arg FLASH_IT_EOP: FLASH end of operation Interrupt
1286→  * @param  NewState: new state of the specified Flash interrupts.
1287→  *   This parameter can be: ENABLE or DISABLE.      
1288→  * @retval None 
1289→  */
1290→void FLASH_ITConfig(uint32_t FLASH_IT, FunctionalState NewState)
1291→{
1292→#ifdef STM32F10X_XL
1293→  /* Check the parameters */
1294→  assert_param(IS_FLASH_IT(FLASH_IT)); 
1295→  assert_param(IS_FUNCTIONAL_STATE(NewState));
1296→
1297→  if((FLASH_IT & 0x80000000) != 0x0)
1298→  {
1299→    if(NewState != DISABLE)
1300→    {
1301→      /* Enable the interrupt sources */
1302→      FLASH->CR2 |= (FLASH_IT & 0x7FFFFFFF);
1303→    }
1304→    else
1305→    {