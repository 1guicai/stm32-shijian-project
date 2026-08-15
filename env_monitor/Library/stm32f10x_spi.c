  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_spi.c
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file provides all the SPI firmware functions.
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
 23→#include "stm32f10x_spi.h"
 24→#include "stm32f10x_rcc.h"
 25→
 26→/** @addtogroup STM32F10x_StdPeriph_Driver
 27→  * @{
 28→  */
 29→
 30→/** @defgroup SPI 
 31→  * @brief SPI driver modules
 32→  * @{
 33→  */ 
 34→
 35→/** @defgroup SPI_Private_TypesDefinitions
 36→  * @{
 37→  */
 38→
 39→/**
 40→  * @}
 41→  */ 
 42→
 43→
 44→/** @defgroup SPI_Private_Defines
 45→  * @{
 46→  */
 47→
 48→/* SPI SPE mask */
 49→#define CR1_SPE_Set          ((uint16_t)0x0040)
 50→#define CR1_SPE_Reset        ((uint16_t)0xFFBF)
 51→
 52→/* I2S I2SE mask */
 53→#define I2SCFGR_I2SE_Set     ((uint16_t)0x0400)
 54→#define I2SCFGR_I2SE_Reset   ((uint16_t)0xFBFF)
 55→
 56→/* SPI CRCNext mask */
 57→#define CR1_CRCNext_Set      ((uint16_t)0x1000)
 58→
 59→/* SPI CRCEN mask */
 60→#define CR1_CRCEN_Set        ((uint16_t)0x2000)
 61→#define CR1_CRCEN_Reset      ((uint16_t)0xDFFF)
 62→
 63→/* SPI SSOE mask */
 64→#define CR2_SSOE_Set         ((uint16_t)0x0004)
 65→#define CR2_SSOE_Reset       ((uint16_t)0xFFFB)
 66→
 67→/* SPI registers Masks */
 68→#define CR1_CLEAR_Mask       ((uint16_t)0x3040)
 69→#define I2SCFGR_CLEAR_Mask   ((uint16_t)0xF040)
 70→
 71→/* SPI or I2S mode selection masks */
 72→#define SPI_Mode_Select      ((uint16_t)0xF7FF)
 73→#define I2S_Mode_Select      ((uint16_t)0x0800) 
 74→
 75→/* I2S clock source selection masks */
 76→#define I2S2_CLOCK_SRC       ((uint32_t)(0x00020000))
 77→#define I2S3_CLOCK_SRC       ((uint32_t)(0x00040000))
 78→#define I2S_MUL_MASK         ((uint32_t)(0x0000F000))
 79→#define I2S_DIV_MASK         ((uint32_t)(0x000000F0))
 80→
 81→/**
 82→  * @}
 83→  */
 84→
 85→/** @defgroup SPI_Private_Macros
 86→  * @{
 87→  */
 88→
 89→/**
 90→  * @}
 91→  */
 92→
 93→/** @defgroup SPI_Private_Variables
 94→  * @{
 95→  */
 96→
 97→/**
 98→  * @}
 99→  */
100→
101→/** @defgroup SPI_Private_FunctionPrototypes
102→  * @{
103→  */
104→
105→/**
106→  * @}
107→  */
108→
109→/** @defgroup SPI_Private_Functions
110→  * @{
111→  */
112→
113→/**
114→  * @brief  Deinitializes the SPIx peripheral registers to their default
115→  *         reset values (Affects also the I2Ss).
116→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
117→  * @retval None
118→  */
119→void SPI_I2S_DeInit(SPI_TypeDef* SPIx)
120→{
121→  /* Check the parameters */
122→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
123→
124→  if (SPIx == SPI1)
125→  {
126→    /* Enable SPI1 reset state */
127→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1, ENABLE);
128→    /* Release SPI1 from reset state */
129→    RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1, DISABLE);
130→  }
131→  else if (SPIx == SPI2)
132→  {
133→    /* Enable SPI2 reset state */
134→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI2, ENABLE);
135→    /* Release SPI2 from reset state */
136→    RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI2, DISABLE);
137→  }
138→  else
139→  {
140→    if (SPIx == SPI3)
141→    {
142→      /* Enable SPI3 reset state */
143→      RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI3, ENABLE);
144→      /* Release SPI3 from reset state */
145→      RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI3, DISABLE);
146→    }
147→  }
148→}
149→
150→/**
151→  * @brief  Initializes the SPIx peripheral according to the specified 
152→  *         parameters in the SPI_InitStruct.
153→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
154→  * @param  SPI_InitStruct: pointer to a SPI_InitTypeDef structure that
155→  *         contains the configuration information for the specified SPI peripheral.
156→  * @retval None
157→  */
158→void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct)
159→{
160→  uint16_t tmpreg = 0;
161→  
162→  /* check the parameters */
163→  assert_param(IS_SPI_ALL_PERIPH(SPIx));   
164→  
165→  /* Check the SPI parameters */
166→  assert_param(IS_SPI_DIRECTION_MODE(SPI_InitStruct->SPI_Direction));
167→  assert_param(IS_SPI_MODE(SPI_InitStruct->SPI_Mode));
168→  assert_param(IS_SPI_DATASIZE(SPI_InitStruct->SPI_DataSize));
169→  assert_param(IS_SPI_CPOL(SPI_InitStruct->SPI_CPOL));
170→  assert_param(IS_SPI_CPHA(SPI_InitStruct->SPI_CPHA));
171→  assert_param(IS_SPI_NSS(SPI_InitStruct->SPI_NSS));
172→  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_InitStruct->SPI_BaudRatePrescaler));
173→  assert_param(IS_SPI_FIRST_BIT(SPI_InitStruct->SPI_FirstBit));
174→  assert_param(IS_SPI_CRC_POLYNOMIAL(SPI_InitStruct->SPI_CRCPolynomial));
175→
176→/*---------------------------- SPIx CR1 Configuration ------------------------*/
177→  /* Get the SPIx CR1 value */
178→  tmpreg = SPIx->CR1;
179→  /* Clear BIDIMode, BIDIOE, RxONLY, SSM, SSI, LSBFirst, BR, MSTR, CPOL and CPHA bits */
180→  tmpreg &= CR1_CLEAR_Mask;
181→  /* Configure SPIx: direction, NSS management, first transmitted bit, BaudRate prescaler
182→     master/salve mode, CPOL and CPHA */
183→  /* Set BIDImode, BIDIOE and RxONLY bits according to SPI_Direction value */
184→  /* Set SSM, SSI and MSTR bits according to SPI_Mode and SPI_NSS values */
185→  /* Set LSBFirst bit according to SPI_FirstBit value */
186→  /* Set BR bits according to SPI_BaudRatePrescaler value */
187→  /* Set CPOL bit according to SPI_CPOL value */
188→  /* Set CPHA bit according to SPI_CPHA value */
189→  tmpreg |= (uint16_t)((uint32_t)SPI_InitStruct->SPI_Direction | SPI_InitStruct->SPI_Mode |
190→                  SPI_InitStruct->SPI_DataSize | SPI_InitStruct->SPI_CPOL |  
191→                  SPI_InitStruct->SPI_CPHA | SPI_InitStruct->SPI_NSS |  
192→                  SPI_InitStruct->SPI_BaudRatePrescaler | SPI_InitStruct->SPI_FirstBit);
193→  /* Write to SPIx CR1 */
194→  SPIx->CR1 = tmpreg;
195→  
196→  /* Activate the SPI mode (Reset I2SMOD bit in I2SCFGR register) */
197→  SPIx->I2SCFGR &= SPI_Mode_Select;		
198→
199→/*---------------------------- SPIx CRCPOLY Configuration --------------------*/
200→  /* Write to SPIx CRCPOLY */
201→  SPIx->CRCPR = SPI_InitStruct->SPI_CRCPolynomial;
202→}
203→
204→/**
205→  * @brief  Initializes the SPIx peripheral according to the specified 
206→  *         parameters in the I2S_InitStruct.
207→  * @param  SPIx: where x can be  2 or 3 to select the SPI peripheral
208→  *         (configured in I2S mode).
209→  * @param  I2S_InitStruct: pointer to an I2S_InitTypeDef structure that
210→  *         contains the configuration information for the specified SPI peripheral
211→  *         configured in I2S mode.
212→  * @note
213→  *  The function calculates the optimal prescaler needed to obtain the most 
214→  *  accurate audio frequency (depending on the I2S clock source, the PLL values 
215→  *  and the product configuration). But in case the prescaler value is greater 
216→  *  than 511, the default value (0x02) will be configured instead.  *   
217→  * @retval None
218→  */
219→void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct)
220→{
221→  uint16_t tmpreg = 0, i2sdiv = 2, i2sodd = 0, packetlength = 1;
222→  uint32_t tmp = 0;
223→  RCC_ClocksTypeDef RCC_Clocks;
224→  uint32_t sourceclock = 0;
225→  
226→  /* Check the I2S parameters */
227→  assert_param(IS_SPI_23_PERIPH(SPIx));
228→  assert_param(IS_I2S_MODE(I2S_InitStruct->I2S_Mode));
229→  assert_param(IS_I2S_STANDARD(I2S_InitStruct->I2S_Standard));
230→  assert_param(IS_I2S_DATA_FORMAT(I2S_InitStruct->I2S_DataFormat));
231→  assert_param(IS_I2S_MCLK_OUTPUT(I2S_InitStruct->I2S_MCLKOutput));
232→  assert_param(IS_I2S_AUDIO_FREQ(I2S_InitStruct->I2S_AudioFreq));
233→  assert_param(IS_I2S_CPOL(I2S_InitStruct->I2S_CPOL));  
234→
235→/*----------------------- SPIx I2SCFGR & I2SPR Configuration -----------------*/
236→  /* Clear I2SMOD, I2SE, I2SCFG, PCMSYNC, I2SSTD, CKPOL, DATLEN and CHLEN bits */
237→  SPIx->I2SCFGR &= I2SCFGR_CLEAR_Mask; 
238→  SPIx->I2SPR = 0x0002;
239→  
240→  /* Get the I2SCFGR register value */
241→  tmpreg = SPIx->I2SCFGR;
242→  
243→  /* If the default value has to be written, reinitialize i2sdiv and i2sodd*/
244→  if(I2S_InitStruct->I2S_AudioFreq == I2S_AudioFreq_Default)
245→  {
246→    i2sodd = (uint16_t)0;
247→    i2sdiv = (uint16_t)2;   
248→  }
249→  /* If the requested audio frequency is not the default, compute the prescaler */
250→  else
251→  {
252→    /* Check the frame length (For the Prescaler computing) */
253→    if(I2S_InitStruct->I2S_DataFormat == I2S_DataFormat_16b)
254→    {
255→      /* Packet length is 16 bits */
256→      packetlength = 1;
257→    }
258→    else
259→    {
260→      /* Packet length is 32 bits */
261→      packetlength = 2;
262→    }
263→
264→    /* Get the I2S clock source mask depending on the peripheral number */
265→    if(((uint32_t)SPIx) == SPI2_BASE)
266→    {
267→      /* The mask is relative to I2S2 */
268→      tmp = I2S2_CLOCK_SRC;
269→    }
270→    else 
271→    {
272→      /* The mask is relative to I2S3 */      
273→      tmp = I2S3_CLOCK_SRC;
274→    }
275→
276→    /* Check the I2S clock source configuration depending on the Device:
277→       Only Connectivity line devices have the PLL3 VCO clock */
278→#ifdef STM32F10X_CL
279→    if((RCC->CFGR2 & tmp) != 0)
280→    {
281→      /* Get the configuration bits of RCC PLL3 multiplier */
282→      tmp = (uint32_t)((RCC->CFGR2 & I2S_MUL_MASK) >> 12);
283→
284→      /* Get the value of the PLL3 multiplier */      
285→      if((tmp > 5) && (tmp < 15))
286→      {
287→        /* Multiplier is between 8 and 14 (value 15 is forbidden) */
288→        tmp += 2;
289→      }
290→      else
291→      {
292→        if (tmp == 15)
293→        {
294→          /* Multiplier is 20 */
295→          tmp = 20;
296→        }
297→      }      
298→      /* Get the PREDIV2 value */
299→      sourceclock = (uint32_t)(((RCC->CFGR2 & I2S_DIV_MASK) >> 4) + 1);
300→      
301→      /* Calculate the Source Clock frequency based on PLL3 and PREDIV2 values */
302→      sourceclock = (uint32_t) ((HSE_Value / sourceclock) * tmp * 2); 
303→    }
304→    else
305→    {
306→      /* I2S Clock source is System clock: Get System Clock frequency */
307→      RCC_GetClocksFreq(&RCC_Clocks);      
308→      
309→      /* Get the source clock value: based on System Clock value */
310→      sourceclock = RCC_Clocks.SYSCLK_Frequency;
311→    }        
312→#else /* STM32F10X_HD */
313→    /* I2S Clock source is System clock: Get System Clock frequency */
314→    RCC_GetClocksFreq(&RCC_Clocks);      
315→      
316→    /* Get the source clock value: based on System Clock value */
317→    sourceclock = RCC_Clocks.SYSCLK_Frequency;    
318→#endif /* STM32F10X_CL */    
319→
320→    /* Compute the Real divider depending on the MCLK output state with a floating point */
321→    if(I2S_InitStruct->I2S_MCLKOutput == I2S_MCLKOutput_Enable)
322→    {
323→      /* MCLK output is enabled */
324→      tmp = (uint16_t)(((((sourceclock / 256) * 10) / I2S_InitStruct->I2S_AudioFreq)) + 5);
325→    }
326→    else
327→    {
328→      /* MCLK output is disabled */
329→      tmp = (uint16_t)(((((sourceclock / (32 * packetlength)) *10 ) / I2S_InitStruct->I2S_AudioFreq)) + 5);
330→    }
331→    
332→    /* Remove the floating point */
333→    tmp = tmp / 10;  
334→      
335→    /* Check the parity of the divider */
336→    i2sodd = (uint16_t)(tmp & (uint16_t)0x0001);
337→   
338→    /* Compute the i2sdiv prescaler */
339→    i2sdiv = (uint16_t)((tmp - i2sodd) / 2);
340→   
341→    /* Get the Mask for the Odd bit (SPI_I2SPR[8]) register */
342→    i2sodd = (uint16_t) (i2sodd << 8);
343→  }
344→  
345→  /* Test if the divider is 1 or 0 or greater than 0xFF */
346→  if ((i2sdiv < 2) || (i2sdiv > 0xFF))
347→  {
348→    /* Set the default values */
349→    i2sdiv = 2;
350→    i2sodd = 0;
351→  }
352→
353→  /* Write to SPIx I2SPR register the computed value */
354→  SPIx->I2SPR = (uint16_t)(i2sdiv | (uint16_t)(i2sodd | (uint16_t)I2S_InitStruct->I2S_MCLKOutput));  
355→ 
356→  /* Configure the I2S with the SPI_InitStruct values */
357→  tmpreg |= (uint16_t)(I2S_Mode_Select | (uint16_t)(I2S_InitStruct->I2S_Mode | \
358→                  (uint16_t)(I2S_InitStruct->I2S_Standard | (uint16_t)(I2S_InitStruct->I2S_DataFormat | \
359→                  (uint16_t)I2S_InitStruct->I2S_CPOL))));
360→ 
361→  /* Write to SPIx I2SCFGR */  
362→  SPIx->I2SCFGR = tmpreg;   
363→}
364→
365→/**
366→  * @brief  Fills each SPI_InitStruct member with its default value.
367→  * @param  SPI_InitStruct : pointer to a SPI_InitTypeDef structure which will be initialized.
368→  * @retval None
369→  */
370→void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct)
371→{
372→/*--------------- Reset SPI init structure parameters values -----------------*/
373→  /* Initialize the SPI_Direction member */
374→  SPI_InitStruct->SPI_Direction = SPI_Direction_2Lines_FullDuplex;
375→  /* initialize the SPI_Mode member */
376→  SPI_InitStruct->SPI_Mode = SPI_Mode_Slave;
377→  /* initialize the SPI_DataSize member */
378→  SPI_InitStruct->SPI_DataSize = SPI_DataSize_8b;
379→  /* Initialize the SPI_CPOL member */
380→  SPI_InitStruct->SPI_CPOL = SPI_CPOL_Low;
381→  /* Initialize the SPI_CPHA member */
382→  SPI_InitStruct->SPI_CPHA = SPI_CPHA_1Edge;
383→  /* Initialize the SPI_NSS member */
384→  SPI_InitStruct->SPI_NSS = SPI_NSS_Hard;
385→  /* Initialize the SPI_BaudRatePrescaler member */
386→  SPI_InitStruct->SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
387→  /* Initialize the SPI_FirstBit member */
388→  SPI_InitStruct->SPI_FirstBit = SPI_FirstBit_MSB;
389→  /* Initialize the SPI_CRCPolynomial member */
390→  SPI_InitStruct->SPI_CRCPolynomial = 7;
391→}
392→
393→/**
394→  * @brief  Fills each I2S_InitStruct member with its default value.
395→  * @param  I2S_InitStruct : pointer to a I2S_InitTypeDef structure which will be initialized.
396→  * @retval None
397→  */
398→void I2S_StructInit(I2S_InitTypeDef* I2S_InitStruct)
399→{
400→/*--------------- Reset I2S init structure parameters values -----------------*/
401→  /* Initialize the I2S_Mode member */
402→  I2S_InitStruct->I2S_Mode = I2S_Mode_SlaveTx;
403→  
404→  /* Initialize the I2S_Standard member */
405→  I2S_InitStruct->I2S_Standard = I2S_Standard_Phillips;
406→  
407→  /* Initialize the I2S_DataFormat member */
408→  I2S_InitStruct->I2S_DataFormat = I2S_DataFormat_16b;
409→  
410→  /* Initialize the I2S_MCLKOutput member */
411→  I2S_InitStruct->I2S_MCLKOutput = I2S_MCLKOutput_Disable;
412→  
413→  /* Initialize the I2S_AudioFreq member */
414→  I2S_InitStruct->I2S_AudioFreq = I2S_AudioFreq_Default;
415→  
416→  /* Initialize the I2S_CPOL member */
417→  I2S_InitStruct->I2S_CPOL = I2S_CPOL_Low;
418→}
419→
420→/**
421→  * @brief  Enables or disables the specified SPI peripheral.
422→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
423→  * @param  NewState: new state of the SPIx peripheral. 
424→  *   This parameter can be: ENABLE or DISABLE.
425→  * @retval None
426→  */
427→void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState)
428→{
429→  /* Check the parameters */
430→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
431→  assert_param(IS_FUNCTIONAL_STATE(NewState));
432→  if (NewState != DISABLE)
433→  {
434→    /* Enable the selected SPI peripheral */
435→    SPIx->CR1 |= CR1_SPE_Set;
436→  }
437→  else
438→  {
439→    /* Disable the selected SPI peripheral */
440→    SPIx->CR1 &= CR1_SPE_Reset;
441→  }
442→}
443→
444→/**
445→  * @brief  Enables or disables the specified SPI peripheral (in I2S mode).
446→  * @param  SPIx: where x can be 2 or 3 to select the SPI peripheral.
447→  * @param  NewState: new state of the SPIx peripheral. 
448→  *   This parameter can be: ENABLE or DISABLE.
449→  * @retval None
450→  */
451→void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState)
452→{
453→  /* Check the parameters */
454→  assert_param(IS_SPI_23_PERIPH(SPIx));
455→  assert_param(IS_FUNCTIONAL_STATE(NewState));
456→  if (NewState != DISABLE)
457→  {
458→    /* Enable the selected SPI peripheral (in I2S mode) */
459→    SPIx->I2SCFGR |= I2SCFGR_I2SE_Set;
460→  }
461→  else
462→  {
463→    /* Disable the selected SPI peripheral (in I2S mode) */
464→    SPIx->I2SCFGR &= I2SCFGR_I2SE_Reset;
465→  }
466→}
467→
468→/**
469→  * @brief  Enables or disables the specified SPI/I2S interrupts.
470→  * @param  SPIx: where x can be
471→  *   - 1, 2 or 3 in SPI mode 
472→  *   - 2 or 3 in I2S mode
473→  * @param  SPI_I2S_IT: specifies the SPI/I2S interrupt source to be enabled or disabled. 
474→  *   This parameter can be one of the following values:
475→  *     @arg SPI_I2S_IT_TXE: Tx buffer empty interrupt mask
476→  *     @arg SPI_I2S_IT_RXNE: Rx buffer not empty interrupt mask
477→  *     @arg SPI_I2S_IT_ERR: Error interrupt mask
478→  * @param  NewState: new state of the specified SPI/I2S interrupt.
479→  *   This parameter can be: ENABLE or DISABLE.
480→  * @retval None
481→  */
482→void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState)
483→{
484→  uint16_t itpos = 0, itmask = 0 ;
485→  /* Check the parameters */
486→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
487→  assert_param(IS_FUNCTIONAL_STATE(NewState));
488→  assert_param(IS_SPI_I2S_CONFIG_IT(SPI_I2S_IT));
489→
490→  /* Get the SPI/I2S IT index */
491→  itpos = SPI_I2S_IT >> 4;
492→
493→  /* Set the IT mask */
494→  itmask = (uint16_t)1 << (uint16_t)itpos;
495→
496→  if (NewState != DISABLE)
497→  {
498→    /* Enable the selected SPI/I2S interrupt */
499→    SPIx->CR2 |= itmask;
500→  }
501→  else
502→  {
503→    /* Disable the selected SPI/I2S interrupt */
504→    SPIx->CR2 &= (uint16_t)~itmask;
505→  }
506→}
507→
508→/**
509→  * @brief  Enables or disables the SPIx/I2Sx DMA interface.
510→  * @param  SPIx: where x can be
511→  *   - 1, 2 or 3 in SPI mode 
512→  *   - 2 or 3 in I2S mode
513→  * @param  SPI_I2S_DMAReq: specifies the SPI/I2S DMA transfer request to be enabled or disabled. 
514→  *   This parameter can be any combination of the following values:
515→  *     @arg SPI_I2S_DMAReq_Tx: Tx buffer DMA transfer request
516→  *     @arg SPI_I2S_DMAReq_Rx: Rx buffer DMA transfer request
517→  * @param  NewState: new state of the selected SPI/I2S DMA transfer request.
518→  *   This parameter can be: ENABLE or DISABLE.
519→  * @retval None
520→  */
521→void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_I2S_DMAReq, FunctionalState NewState)
522→{
523→  /* Check the parameters */
524→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
525→  assert_param(IS_FUNCTIONAL_STATE(NewState));
526→  assert_param(IS_SPI_I2S_DMAREQ(SPI_I2S_DMAReq));
527→  if (NewState != DISABLE)
528→  {
529→    /* Enable the selected SPI/I2S DMA requests */
530→    SPIx->CR2 |= SPI_I2S_DMAReq;
531→  }
532→  else
533→  {
534→    /* Disable the selected SPI/I2S DMA requests */
535→    SPIx->CR2 &= (uint16_t)~SPI_I2S_DMAReq;
536→  }
537→}
538→
539→/**
540→  * @brief  Transmits a Data through the SPIx/I2Sx peripheral.
541→  * @param  SPIx: where x can be
542→  *   - 1, 2 or 3 in SPI mode 
543→  *   - 2 or 3 in I2S mode
544→  * @param  Data : Data to be transmitted.
545→  * @retval None
546→  */
547→void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data)
548→{
549→  /* Check the parameters */
550→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
551→  
552→  /* Write in the DR register the data to be sent */
553→  SPIx->DR = Data;
554→}
555→
556→/**
557→  * @brief  Returns the most recent received data by the SPIx/I2Sx peripheral. 
558→  * @param  SPIx: where x can be
559→  *   - 1, 2 or 3 in SPI mode 
560→  *   - 2 or 3 in I2S mode
561→  * @retval The value of the received data.
562→  */
563→uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx)
564→{
565→  /* Check the parameters */
566→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
567→  
568→  /* Return the data in the DR register */
569→  return SPIx->DR;
570→}
571→
572→/**
573→  * @brief  Configures internally by software the NSS pin for the selected SPI.
574→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
575→  * @param  SPI_NSSInternalSoft: specifies the SPI NSS internal state.
576→  *   This parameter can be one of the following values:
577→  *     @arg SPI_NSSInternalSoft_Set: Set NSS pin internally
578→  *     @arg SPI_NSSInternalSoft_Reset: Reset NSS pin internally
579→  * @retval None
580→  */
581→void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, uint16_t SPI_NSSInternalSoft)
582→{
583→  /* Check the parameters */
584→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
585→  assert_param(IS_SPI_NSS_INTERNAL(SPI_NSSInternalSoft));
586→  if (SPI_NSSInternalSoft != SPI_NSSInternalSoft_Reset)
587→  {
588→    /* Set NSS pin internally by software */
589→    SPIx->CR1 |= SPI_NSSInternalSoft_Set;
590→  }
591→  else
592→  {
593→    /* Reset NSS pin internally by software */
594→    SPIx->CR1 &= SPI_NSSInternalSoft_Reset;
595→  }
596→}
597→
598→/**
599→  * @brief  Enables or disables the SS output for the selected SPI.
600→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
601→  * @param  NewState: new state of the SPIx SS output. 
602→  *   This parameter can be: ENABLE or DISABLE.
603→  * @retval None
604→  */
605→void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState)
606→{
607→  /* Check the parameters */
608→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
609→  assert_param(IS_FUNCTIONAL_STATE(NewState));
610→  if (NewState != DISABLE)
611→  {
612→    /* Enable the selected SPI SS output */
613→    SPIx->CR2 |= CR2_SSOE_Set;
614→  }
615→  else
616→  {
617→    /* Disable the selected SPI SS output */
618→    SPIx->CR2 &= CR2_SSOE_Reset;
619→  }
620→}
621→
622→/**
623→  * @brief  Configures the data size for the selected SPI.
624→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
625→  * @param  SPI_DataSize: specifies the SPI data size.
626→  *   This parameter can be one of the following values:
627→  *     @arg SPI_DataSize_16b: Set data frame format to 16bit
628→  *     @arg SPI_DataSize_8b: Set data frame format to 8bit
629→  * @retval None
630→  */
631→void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize)
632→{
633→  /* Check the parameters */
634→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
635→  assert_param(IS_SPI_DATASIZE(SPI_DataSize));
636→  /* Clear DFF bit */
637→  SPIx->CR1 &= (uint16_t)~SPI_DataSize_16b;
638→  /* Set new DFF bit value */
639→  SPIx->CR1 |= SPI_DataSize;
640→}
641→
642→/**
643→  * @brief  Transmit the SPIx CRC value.
644→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
645→  * @retval None
646→  */
647→void SPI_TransmitCRC(SPI_TypeDef* SPIx)
648→{
649→  /* Check the parameters */
650→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
651→  
652→  /* Enable the selected SPI CRC transmission */
653→  SPIx->CR1 |= CR1_CRCNext_Set;
654→}
655→
656→/**
657→  * @brief  Enables or disables the CRC value calculation of the transferred bytes.
658→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
659→  * @param  NewState: new state of the SPIx CRC value calculation.
660→  *   This parameter can be: ENABLE or DISABLE.
661→  * @retval None
662→  */
663→void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState)
664→{
665→  /* Check the parameters */
666→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
667→  assert_param(IS_FUNCTIONAL_STATE(NewState));
668→  if (NewState != DISABLE)
669→  {
670→    /* Enable the selected SPI CRC calculation */
671→    SPIx->CR1 |= CR1_CRCEN_Set;
672→  }
673→  else
674→  {
675→    /* Disable the selected SPI CRC calculation */
676→    SPIx->CR1 &= CR1_CRCEN_Reset;
677→  }
678→}
679→
680→/**
681→  * @brief  Returns the transmit or the receive CRC register value for the specified SPI.
682→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
683→  * @param  SPI_CRC: specifies the CRC register to be read.
684→  *   This parameter can be one of the following values:
685→  *     @arg SPI_CRC_Tx: Selects Tx CRC register
686→  *     @arg SPI_CRC_Rx: Selects Rx CRC register
687→  * @retval The selected CRC register value..
688→  */
689→uint16_t SPI_GetCRC(SPI_TypeDef* SPIx, uint8_t SPI_CRC)
690→{
691→  uint16_t crcreg = 0;
692→  /* Check the parameters */
693→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
694→  assert_param(IS_SPI_CRC(SPI_CRC));
695→  if (SPI_CRC != SPI_CRC_Rx)
696→  {
697→    /* Get the Tx CRC register */
698→    crcreg = SPIx->TXCRCR;
699→  }
700→  else
701→  {
702→    /* Get the Rx CRC register */
703→    crcreg = SPIx->RXCRCR;
704→  }
705→  /* Return the selected CRC register */
706→  return crcreg;
707→}
708→
709→/**
710→  * @brief  Returns the CRC Polynomial register value for the specified SPI.
711→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
712→  * @retval The CRC Polynomial register value.
713→  */
714→uint16_t SPI_GetCRCPolynomial(SPI_TypeDef* SPIx)
715→{
716→  /* Check the parameters */
717→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
718→  
719→  /* Return the CRC polynomial register */
720→  return SPIx->CRCPR;
721→}
722→
723→/**
724→  * @brief  Selects the data transfer direction in bi-directional mode for the specified SPI.
725→  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
726→  * @param  SPI_Direction: specifies the data transfer direction in bi-directional mode. 
727→  *   This parameter can be one of the following values:
728→  *     @arg SPI_Direction_Tx: Selects Tx transmission direction
729→  *     @arg SPI_Direction_Rx: Selects Rx receive direction
730→  * @retval None
731→  */
732→void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, uint16_t SPI_Direction)
733→{
734→  /* Check the parameters */
735→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
736→  assert_param(IS_SPI_DIRECTION(SPI_Direction));
737→  if (SPI_Direction == SPI_Direction_Tx)
738→  {
739→    /* Set the Tx only mode */
740→    SPIx->CR1 |= SPI_Direction_Tx;
741→  }
742→  else
743→  {
744→    /* Set the Rx only mode */
745→    SPIx->CR1 &= SPI_Direction_Rx;
746→  }
747→}
748→
749→/**
750→  * @brief  Checks whether the specified SPI/I2S flag is set or not.
751→  * @param  SPIx: where x can be
752→  *   - 1, 2 or 3 in SPI mode 
753→  *   - 2 or 3 in I2S mode
754→  * @param  SPI_I2S_FLAG: specifies the SPI/I2S flag to check. 
755→  *   This parameter can be one of the following values:
756→  *     @arg SPI_I2S_FLAG_TXE: Transmit buffer empty flag.
757→  *     @arg SPI_I2S_FLAG_RXNE: Receive buffer not empty flag.
758→  *     @arg SPI_I2S_FLAG_BSY: Busy flag.
759→  *     @arg SPI_I2S_FLAG_OVR: Overrun flag.
760→  *     @arg SPI_FLAG_MODF: Mode Fault flag.
761→  *     @arg SPI_FLAG_CRCERR: CRC Error flag.
762→  *     @arg I2S_FLAG_UDR: Underrun Error flag.
763→  *     @arg I2S_FLAG_CHSIDE: Channel Side flag.
764→  * @retval The new state of SPI_I2S_FLAG (SET or RESET).
765→  */
766→FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
767→{
768→  FlagStatus bitstatus = RESET;
769→  /* Check the parameters */
770→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
771→  assert_param(IS_SPI_I2S_GET_FLAG(SPI_I2S_FLAG));
772→  /* Check the status of the specified SPI/I2S flag */
773→  if ((SPIx->SR & SPI_I2S_FLAG) != (uint16_t)RESET)
774→  {
775→    /* SPI_I2S_FLAG is set */
776→    bitstatus = SET;
777→  }
778→  else
779→  {
780→    /* SPI_I2S_FLAG is reset */
781→    bitstatus = RESET;
782→  }
783→  /* Return the SPI_I2S_FLAG status */
784→  return  bitstatus;
785→}
786→
787→/**
788→  * @brief  Clears the SPIx CRC Error (CRCERR) flag.
789→  * @param  SPIx: where x can be
790→  *   - 1, 2 or 3 in SPI mode 
791→  * @param  SPI_I2S_FLAG: specifies the SPI flag to clear. 
792→  *   This function clears only CRCERR flag.
793→  * @note
794→  *   - OVR (OverRun error) flag is cleared by software sequence: a read 
795→  *     operation to SPI_DR register (SPI_I2S_ReceiveData()) followed by a read 
796→  *     operation to SPI_SR register (SPI_I2S_GetFlagStatus()).
797→  *   - UDR (UnderRun error) flag is cleared by a read operation to 
798→  *     SPI_SR register (SPI_I2S_GetFlagStatus()).
799→  *   - MODF (Mode Fault) flag is cleared by software sequence: a read/write 
800→  *     operation to SPI_SR register (SPI_I2S_GetFlagStatus()) followed by a 
801→  *     write operation to SPI_CR1 register (SPI_Cmd() to enable the SPI).
802→  * @retval None
803→  */
804→void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
805→{
806→  /* Check the parameters */
807→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
808→  assert_param(IS_SPI_I2S_CLEAR_FLAG(SPI_I2S_FLAG));
809→    
810→    /* Clear the selected SPI CRC Error (CRCERR) flag */
811→    SPIx->SR = (uint16_t)~SPI_I2S_FLAG;
812→}
813→
814→/**
815→  * @brief  Checks whether the specified SPI/I2S interrupt has occurred or not.
816→  * @param  SPIx: where x can be
817→  *   - 1, 2 or 3 in SPI mode 
818→  *   - 2 or 3 in I2S mode
819→  * @param  SPI_I2S_IT: specifies the SPI/I2S interrupt source to check. 
820→  *   This parameter can be one of the following values:
821→  *     @arg SPI_I2S_IT_TXE: Transmit buffer empty interrupt.
822→  *     @arg SPI_I2S_IT_RXNE: Receive buffer not empty interrupt.
823→  *     @arg SPI_I2S_IT_OVR: Overrun interrupt.
824→  *     @arg SPI_IT_MODF: Mode Fault interrupt.
825→  *     @arg SPI_IT_CRCERR: CRC Error interrupt.
826→  *     @arg I2S_IT_UDR: Underrun Error interrupt.
827→  * @retval The new state of SPI_I2S_IT (SET or RESET).
828→  */
829→ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT)
830→{
831→  ITStatus bitstatus = RESET;
832→  uint16_t itpos = 0, itmask = 0, enablestatus = 0;
833→
834→  /* Check the parameters */
835→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
836→  assert_param(IS_SPI_I2S_GET_IT(SPI_I2S_IT));
837→
838→  /* Get the SPI/I2S IT index */
839→  itpos = 0x01 << (SPI_I2S_IT & 0x0F);
840→
841→  /* Get the SPI/I2S IT mask */
842→  itmask = SPI_I2S_IT >> 4;
843→
844→  /* Set the IT mask */
845→  itmask = 0x01 << itmask;
846→
847→  /* Get the SPI_I2S_IT enable bit status */
848→  enablestatus = (SPIx->CR2 & itmask) ;
849→
850→  /* Check the status of the specified SPI/I2S interrupt */
851→  if (((SPIx->SR & itpos) != (uint16_t)RESET) && enablestatus)
852→  {
853→    /* SPI_I2S_IT is set */
854→    bitstatus = SET;
855→  }
856→  else
857→  {
858→    /* SPI_I2S_IT is reset */
859→    bitstatus = RESET;
860→  }
861→  /* Return the SPI_I2S_IT status */
862→  return bitstatus;
863→}
864→
865→/**
866→  * @brief  Clears the SPIx CRC Error (CRCERR) interrupt pending bit.
867→  * @param  SPIx: where x can be
868→  *   - 1, 2 or 3 in SPI mode 
869→  * @param  SPI_I2S_IT: specifies the SPI interrupt pending bit to clear.
870→  *   This function clears only CRCERR interrupt pending bit.   
871→  * @note
872→  *   - OVR (OverRun Error) interrupt pending bit is cleared by software 
873→  *     sequence: a read operation to SPI_DR register (SPI_I2S_ReceiveData()) 
874→  *     followed by a read operation to SPI_SR register (SPI_I2S_GetITStatus()).
875→  *   - UDR (UnderRun Error) interrupt pending bit is cleared by a read 
876→  *     operation to SPI_SR register (SPI_I2S_GetITStatus()).
877→  *   - MODF (Mode Fault) interrupt pending bit is cleared by software sequence:
878→  *     a read/write operation to SPI_SR register (SPI_I2S_GetITStatus()) 
879→  *     followed by a write operation to SPI_CR1 register (SPI_Cmd() to enable 
880→  *     the SPI).
881→  * @retval None
882→  */
883→void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT)
884→{
885→  uint16_t itpos = 0;
886→  /* Check the parameters */
887→  assert_param(IS_SPI_ALL_PERIPH(SPIx));
888→  assert_param(IS_SPI_I2S_CLEAR_IT(SPI_I2S_IT));
889→
890→  /* Get the SPI IT index */
891→  itpos = 0x01 << (SPI_I2S_IT & 0x0F);
892→
893→  /* Clear the selected SPI CRC Error (CRCERR) interrupt pending bit */
894→  SPIx->SR = (uint16_t)~itpos;
895→}
896→/**
897→  * @}
898→  */ 
899→
900→/**
901→  * @}
902→  */ 
903→
904→/**
905→  * @}
906→  */ 
907→
908→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/