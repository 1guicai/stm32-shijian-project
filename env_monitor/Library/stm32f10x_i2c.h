  1→/**
  2→  ******************************************************************************
  3→  * @file    stm32f10x_i2c.h
  4→  * @author  MCD Application Team
  5→  * @version V3.5.0
  6→  * @date    11-March-2011
  7→  * @brief   This file contains all the functions prototypes for the I2C firmware 
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
 24→#ifndef __STM32F10x_I2C_H
 25→#define __STM32F10x_I2C_H
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
 38→/** @addtogroup I2C
 39→  * @{
 40→  */
 41→
 42→/** @defgroup I2C_Exported_Types
 43→  * @{
 44→  */
 45→
 46→/** 
 47→  * @brief  I2C Init structure definition  
 48→  */
 49→
 50→typedef struct
 51→{
 52→  uint32_t I2C_ClockSpeed;          /*!< Specifies the clock frequency.
 53→                                         This parameter must be set to a value lower than 400kHz */
 54→
 55→  uint16_t I2C_Mode;                /*!< Specifies the I2C mode.
 56→                                         This parameter can be a value of @ref I2C_mode */
 57→
 58→  uint16_t I2C_DutyCycle;           /*!< Specifies the I2C fast mode duty cycle.
 59→                                         This parameter can be a value of @ref I2C_duty_cycle_in_fast_mode */
 60→
 61→  uint16_t I2C_OwnAddress1;         /*!< Specifies the first device own address.
 62→                                         This parameter can be a 7-bit or 10-bit address. */
 63→
 64→  uint16_t I2C_Ack;                 /*!< Enables or disables the acknowledgement.
 65→                                         This parameter can be a value of @ref I2C_acknowledgement */
 66→
 67→  uint16_t I2C_AcknowledgedAddress; /*!< Specifies if 7-bit or 10-bit address is acknowledged.
 68→                                         This parameter can be a value of @ref I2C_acknowledged_address */
 69→}I2C_InitTypeDef;
 70→
 71→/**
 72→  * @}
 73→  */ 
 74→
 75→
 76→/** @defgroup I2C_Exported_Constants
 77→  * @{
 78→  */
 79→
 80→#define IS_I2C_ALL_PERIPH(PERIPH) (((PERIPH) == I2C1) || \
 81→                                   ((PERIPH) == I2C2))
 82→/** @defgroup I2C_mode 
 83→  * @{
 84→  */
 85→
 86→#define I2C_Mode_I2C                    ((uint16_t)0x0000)
 87→#define I2C_Mode_SMBusDevice            ((uint16_t)0x0002)  
 88→#define I2C_Mode_SMBusHost              ((uint16_t)0x000A)
 89→#define IS_I2C_MODE(MODE) (((MODE) == I2C_Mode_I2C) || \
 90→                           ((MODE) == I2C_Mode_SMBusDevice) || \
 91→                           ((MODE) == I2C_Mode_SMBusHost))
 92→/**
 93→  * @}
 94→  */
 95→
 96→/** @defgroup I2C_duty_cycle_in_fast_mode 
 97→  * @{
 98→  */
 99→
100→#define I2C_DutyCycle_16_9              ((uint16_t)0x4000) /*!< I2C fast mode Tlow/Thigh = 16/9 */
101→#define I2C_DutyCycle_2                 ((uint16_t)0xBFFF) /*!< I2C fast mode Tlow/Thigh = 2 */
102→#define IS_I2C_DUTY_CYCLE(CYCLE) (((CYCLE) == I2C_DutyCycle_16_9) || \
103→                                  ((CYCLE) == I2C_DutyCycle_2))
104→/**
105→  * @}
106→  */ 
107→
108→/** @defgroup I2C_acknowledgement
109→  * @{
110→  */
111→
112→#define I2C_Ack_Enable                  ((uint16_t)0x0400)
113→#define I2C_Ack_Disable                 ((uint16_t)0x0000)
114→#define IS_I2C_ACK_STATE(STATE) (((STATE) == I2C_Ack_Enable) || \
115→                                 ((STATE) == I2C_Ack_Disable))
116→/**
117→  * @}
118→  */
119→
120→/** @defgroup I2C_transfer_direction 
121→  * @{
122→  */
123→
124→#define  I2C_Direction_Transmitter      ((uint8_t)0x00)
125→#define  I2C_Direction_Receiver         ((uint8_t)0x01)
126→#define IS_I2C_DIRECTION(DIRECTION) (((DIRECTION) == I2C_Direction_Transmitter) || \
127→                                     ((DIRECTION) == I2C_Direction_Receiver))
128→/**
129→  * @}
130→  */
131→
132→/** @defgroup I2C_acknowledged_address 
133→  * @{
134→  */
135→
136→#define I2C_AcknowledgedAddress_7bit    ((uint16_t)0x4000)
137→#define I2C_AcknowledgedAddress_10bit   ((uint16_t)0xC000)
138→#define IS_I2C_ACKNOWLEDGE_ADDRESS(ADDRESS) (((ADDRESS) == I2C_AcknowledgedAddress_7bit) || \
139→                                             ((ADDRESS) == I2C_AcknowledgedAddress_10bit))
140→/**
141→  * @}
142→  */ 
143→
144→/** @defgroup I2C_registers 
145→  * @{
146→  */
147→
148→#define I2C_Register_CR1                ((uint8_t)0x00)
149→#define I2C_Register_CR2                ((uint8_t)0x04)
150→#define I2C_Register_OAR1               ((uint8_t)0x08)
151→#define I2C_Register_OAR2               ((uint8_t)0x0C)
152→#define I2C_Register_DR                 ((uint8_t)0x10)
153→#define I2C_Register_SR1                ((uint8_t)0x14)
154→#define I2C_Register_SR2                ((uint8_t)0x18)
155→#define I2C_Register_CCR                ((uint8_t)0x1C)
156→#define I2C_Register_TRISE              ((uint8_t)0x20)
157→#define IS_I2C_REGISTER(REGISTER) (((REGISTER) == I2C_Register_CR1) || \
158→                                   ((REGISTER) == I2C_Register_CR2) || \
159→                                   ((REGISTER) == I2C_Register_OAR1) || \
160→                                   ((REGISTER) == I2C_Register_OAR2) || \
161→                                   ((REGISTER) == I2C_Register_DR) || \
162→                                   ((REGISTER) == I2C_Register_SR1) || \
163→                                   ((REGISTER) == I2C_Register_SR2) || \
164→                                   ((REGISTER) == I2C_Register_CCR) || \
165→                                   ((REGISTER) == I2C_Register_TRISE))
166→/**
167→  * @}
168→  */
169→
170→/** @defgroup I2C_SMBus_alert_pin_level 
171→  * @{
172→  */
173→
174→#define I2C_SMBusAlert_Low              ((uint16_t)0x2000)
175→#define I2C_SMBusAlert_High             ((uint16_t)0xDFFF)
176→#define IS_I2C_SMBUS_ALERT(ALERT) (((ALERT) == I2C_SMBusAlert_Low) || \
177→                                   ((ALERT) == I2C_SMBusAlert_High))
178→/**
179→  * @}
180→  */
181→
182→/** @defgroup I2C_PEC_position 
183→  * @{
184→  */
185→
186→#define I2C_PECPosition_Next            ((uint16_t)0x0800)
187→#define I2C_PECPosition_Current         ((uint16_t)0xF7FF)
188→#define IS_I2C_PEC_POSITION(POSITION) (((POSITION) == I2C_PECPosition_Next) || \
189→                                       ((POSITION) == I2C_PECPosition_Current))
190→/**
191→  * @}
192→  */ 
193→
194→/** @defgroup I2C_NCAK_position 
195→  * @{
196→  */
197→
198→#define I2C_NACKPosition_Next           ((uint16_t)0x0800)
199→#define I2C_NACKPosition_Current        ((uint16_t)0xF7FF)
200→#define IS_I2C_NACK_POSITION(POSITION)  (((POSITION) == I2C_NACKPosition_Next) || \
201→                                         ((POSITION) == I2C_NACKPosition_Current))
202→/**
203→  * @}
204→  */ 
205→
206→/** @defgroup I2C_interrupts_definition 
207→  * @{
208→  */
209→
210→#define I2C_IT_BUF                      ((uint16_t)0x0400)
211→#define I2C_IT_EVT                      ((uint16_t)0x0200)
212→#define I2C_IT_ERR                      ((uint16_t)0x0100)
213→#define IS_I2C_CONFIG_IT(IT) ((((IT) & (uint16_t)0xF8FF) == 0x00) && ((IT) != 0x00))
214→/**
215→  * @}
216→  */ 
217→
218→/** @defgroup I2C_interrupts_definition 
219→  * @{
220→  */
221→
222→#define I2C_IT_SMBALERT                 ((uint32_t)0x01008000)
223→#define I2C_IT_TIMEOUT                  ((uint32_t)0x01004000)
224→#define I2C_IT_PECERR                   ((uint32_t)0x01001000)
225→#define I2C_IT_OVR                      ((uint32_t)0x01000800)
226→#define I2C_IT_AF                       ((uint32_t)0x01000400)
227→#define I2C_IT_ARLO                     ((uint32_t)0x01000200)
228→#define I2C_IT_BERR                     ((uint32_t)0x01000100)
229→#define I2C_IT_TXE                      ((uint32_t)0x06000080)
230→#define I2C_IT_RXNE                     ((uint32_t)0x06000040)
231→#define I2C_IT_STOPF                    ((uint32_t)0x02000010)
232→#define I2C_IT_ADD10                    ((uint32_t)0x02000008)
233→#define I2C_IT_BTF                      ((uint32_t)0x02000004)
234→#define I2C_IT_ADDR                     ((uint32_t)0x02000002)
235→#define I2C_IT_SB                       ((uint32_t)0x02000001)
236→
237→#define IS_I2C_CLEAR_IT(IT) ((((IT) & (uint16_t)0x20FF) == 0x00) && ((IT) != (uint16_t)0x00))
238→
239→#define IS_I2C_GET_IT(IT) (((IT) == I2C_IT_SMBALERT) || ((IT) == I2C_IT_TIMEOUT) || \
240→                           ((IT) == I2C_IT_PECERR) || ((IT) == I2C_IT_OVR) || \
241→                           ((IT) == I2C_IT_AF) || ((IT) == I2C_IT_ARLO) || \
242→                           ((IT) == I2C_IT_BERR) || ((IT) == I2C_IT_TXE) || \
243→                           ((IT) == I2C_IT_RXNE) || ((IT) == I2C_IT_STOPF) || \
244→                           ((IT) == I2C_IT_ADD10) || ((IT) == I2C_IT_BTF) || \
245→                           ((IT) == I2C_IT_ADDR) || ((IT) == I2C_IT_SB))
246→/**
247→  * @}
248→  */
249→
250→/** @defgroup I2C_flags_definition 
251→  * @{
252→  */
253→
254→/** 
255→  * @brief  SR2 register flags  
256→  */
257→
258→#define I2C_FLAG_DUALF                  ((uint32_t)0x00800000)
259→#define I2C_FLAG_SMBHOST                ((uint32_t)0x00400000)
260→#define I2C_FLAG_SMBDEFAULT             ((uint32_t)0x00200000)
261→#define I2C_FLAG_GENCALL                ((uint32_t)0x00100000)
262→#define I2C_FLAG_TRA                    ((uint32_t)0x00040000)
263→#define I2C_FLAG_BUSY                   ((uint32_t)0x00020000)
264→#define I2C_FLAG_MSL                    ((uint32_t)0x00010000)
265→
266→/** 
267→  * @brief  SR1 register flags  
268→  */
269→
270→#define I2C_FLAG_SMBALERT               ((uint32_t)0x10008000)
271→#define I2C_FLAG_TIMEOUT                ((uint32_t)0x10004000)
272→#define I2C_FLAG_PECERR                 ((uint32_t)0x10001000)
273→#define I2C_FLAG_OVR                    ((uint32_t)0x10000800)
274→#define I2C_FLAG_AF                     ((uint32_t)0x10000400)
275→#define I2C_FLAG_ARLO                   ((uint32_t)0x10000200)
276→#define I2C_FLAG_BERR                   ((uint32_t)0x10000100)
277→#define I2C_FLAG_TXE                    ((uint32_t)0x10000080)
278→#define I2C_FLAG_RXNE                   ((uint32_t)0x10000040)
279→#define I2C_FLAG_STOPF                  ((uint32_t)0x10000010)
280→#define I2C_FLAG_ADD10                  ((uint32_t)0x10000008)
281→#define I2C_FLAG_BTF                    ((uint32_t)0x10000004)
282→#define I2C_FLAG_ADDR                   ((uint32_t)0x10000002)
283→#define I2C_FLAG_SB                     ((uint32_t)0x10000001)
284→
285→#define IS_I2C_CLEAR_FLAG(FLAG) ((((FLAG) & (uint16_t)0x20FF) == 0x00) && ((FLAG) != (uint16_t)0x00))
286→
287→#define IS_I2C_GET_FLAG(FLAG) (((FLAG) == I2C_FLAG_DUALF) || ((FLAG) == I2C_FLAG_SMBHOST) || \
288→                               ((FLAG) == I2C_FLAG_SMBDEFAULT) || ((FLAG) == I2C_FLAG_GENCALL) || \
289→                               ((FLAG) == I2C_FLAG_TRA) || ((FLAG) == I2C_FLAG_BUSY) || \
290→                               ((FLAG) == I2C_FLAG_MSL) || ((FLAG) == I2C_FLAG_SMBALERT) || \
291→                               ((FLAG) == I2C_FLAG_TIMEOUT) || ((FLAG) == I2C_FLAG_PECERR) || \
292→                               ((FLAG) == I2C_FLAG_OVR) || ((FLAG) == I2C_FLAG_AF) || \
293→                               ((FLAG) == I2C_FLAG_ARLO) || ((FLAG) == I2C_FLAG_BERR) || \
294→                               ((FLAG) == I2C_FLAG_TXE) || ((FLAG) == I2C_FLAG_RXNE) || \
295→                               ((FLAG) == I2C_FLAG_STOPF) || ((FLAG) == I2C_FLAG_ADD10) || \
296→                               ((FLAG) == I2C_FLAG_BTF) || ((FLAG) == I2C_FLAG_ADDR) || \
297→                               ((FLAG) == I2C_FLAG_SB))
298→/**
299→  * @}
300→  */
301→
302→/** @defgroup I2C_Events 
303→  * @{
304→  */
305→
306→/*========================================
307→     
308→                     I2C Master Events (Events grouped in order of communication)
309→                                                        ==========================================*/
310→/** 
311→  * @brief  Communication start
312→  * 
313→  * After sending the START condition (I2C_GenerateSTART() function) the master 
314→  * has to wait for this event. It means that the Start condition has been correctly 
315→  * released on the I2C bus (the bus is free, no other devices is communicating).
316→  * 
317→  */
318→/* --EV5 */
319→#define  I2C_EVENT_MASTER_MODE_SELECT                      ((uint32_t)0x00030001)  /* BUSY, MSL and SB flag */
320→
321→/** 
322→  * @brief  Address Acknowledge
323→  * 
324→  * After checking on EV5 (start condition correctly released on the bus), the 
325→  * master sends the address of the slave(s) with which it will communicate 
326→  * (I2C_Send7bitAddress() function, it also determines the direction of the communication: 
327→  * Master transmitter or Receiver). Then the master has to wait that a slave acknowledges 
328→  * his address. If an acknowledge is sent on the bus, one of the following events will 
329→  * be set:
330→  * 
331→  *  1) In case of Master Receiver (7-bit addressing): the I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED 
332→  *     event is set.
333→  *  
334→  *  2) In case of Master Transmitter (7-bit addressing): the I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED 
335→  *     is set
336→  *  
337→  *  3) In case of 10-Bit addressing mode, the master (just after generating the START 
338→  *  and checking on EV5) has to send the header of 10-bit addressing mode (I2C_SendData() 
339→  *  function). Then master should wait on EV9. It means that the 10-bit addressing 
340→  *  header has been correctly sent on the bus. Then master should send the second part of 
341→  *  the 10-bit address (LSB) using the function I2C_Send7bitAddress(). Then master 
342→  *  should wait for event EV6. 
343→  *     
344→  */
345→
346→/* --EV6 */
347→#define  I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED        ((uint32_t)0x00070082)  /* BUSY, MSL, ADDR, TXE and TRA flags */
348→#define  I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED           ((uint32_t)0x00030002)  /* BUSY, MSL and ADDR flags */
349→/* --EV9 */
350→#define  I2C_EVENT_MASTER_MODE_ADDRESS10                   ((uint32_t)0x00030008)  /* BUSY, MSL and ADD10 flags */
351→
352→/** 
353→  * @brief Communication events
354→  * 
355→  * If a communication is established (START condition generated and slave address 
356→  * acknowledged) then the master has to check on one of the following events for 
357→  * communication procedures:
358→  *  
359→  * 1) Master Receiver mode: The master has to wait on the event EV7 then to read 
360→  *    the data received from the slave (I2C_ReceiveData() function).
361→  * 
362→  * 2) Master Transmitter mode: The master has to send data (I2C_SendData() 
363→  *    function) then to wait on event EV8 or EV8_2.
364→  *    These two events are similar: 
365→  *     - EV8 means that the data has been written in the data register and is 
366→  *       being shifted out.
367→  *     - EV8_2 means that the data has been physically shifted out and output 
368→  *       on the bus.
369→  *     In most cases, using EV8 is sufficient for the application.
370→  *     Using EV8_2 leads to a slower communication but ensure more reliable test.
371→  *     EV8_2 is also more suitable than EV8 for testing on the last data transmission 
372→  *     (before Stop condition generation).
373→  *     
374→  *  @note In case the  user software does not guarantee that this event EV7 is 
375→  *  managed before the current byte end of transfer, then user may check on EV7 
376→  *  and BTF flag at the same time (ie. (I2C_EVENT_MASTER_BYTE_RECEIVED | I2C_FLAG_BTF)).
377→  *  In this case the communication may be slower.
378→  * 
379→  */
380→
381→/* Master RECEIVER mode -----------------------------*/ 
382→/* --EV7 */
383→#define  I2C_EVENT_MASTER_BYTE_RECEIVED                    ((uint32_t)0x00030040)  /* BUSY, MSL and RXNE flags */
384→
385→/* Master TRANSMITTER mode --------------------------*/
386→/* --EV8 */
387→#define I2C_EVENT_MASTER_BYTE_TRANSMITTING                 ((uint32_t)0x00070080) /* TRA, BUSY, MSL, TXE flags */
388→/* --EV8_2 */
389→#define  I2C_EVENT_MASTER_BYTE_TRANSMITTED                 ((uint32_t)0x00070084)  /* TRA, BUSY, MSL, TXE and BTF flags */
390→
391→
392→/*========================================
393→     
394→                     I2C Slave Events (Events grouped in order of communication)
395→                                                        ==========================================*/
396→
397→/** 
398→  * @brief  Communication start events
399→  * 
400→  * Wait on one of these events at the start of the communication. It means that 
401→  * the I2C peripheral detected a Start condition on the bus (generated by master 
402→  * device) followed by the peripheral address. The peripheral generates an ACK 
403→  * condition on the bus (if the acknowledge feature is enabled through function 
404→  * I2C_AcknowledgeConfig()) and the events listed above are set :
405→  *  
406→  * 1) In normal case (only one address managed by the slave), when the address 
407→  *   sent by the master matches the own address of the peripheral (configured by 
408→  *   I2C_OwnAddress1 field) the I2C_EVENT_SLAVE_XXX_ADDRESS_MATCHED event is set 
409→  *   (where XXX could be TRANSMITTER or RECEIVER).
410→  *    
411→  * 2) In case the address sent by the master matches the second address of the 
412→  *   peripheral (configured by the function I2C_OwnAddress2Config() and enabled 
413→  *   by the function I2C_DualAddressCmd()) the events I2C_EVENT_SLAVE_XXX_SECONDADDRESS_MATCHED 
414→  *   (where XXX could be TRANSMITTER or RECEIVER) are set.
415→  *   
416→  * 3) In case the address sent by the master is General Call (address 0x00) and 
417→  *   if the General Call is enabled for the peripheral (using function I2C_GeneralCallCmd()) 
418→  *   the following event is set I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED.   
419→  * 
420→  */
421→
422→/* --EV1  (all the events below are variants of EV1) */   
423→/* 1) Case of One Single Address managed by the slave */
424→#define  I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED          ((uint32_t)0x00020002) /* BUSY and ADDR flags */
425→#define  I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED       ((uint32_t)0x00060082) /* TRA, BUSY, TXE and ADDR flags */
426→
427→/* 2) Case of Dual address managed by the slave */
428→#define  I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED    ((uint32_t)0x00820000)  /* DUALF and BUSY flags */
429→#define  I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED ((uint32_t)0x00860080)  /* DUALF, TRA, BUSY and TXE flags */
430→
431→/* 3) Case of General Call enabled for the slave */
432→#define  I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED        ((uint32_t)0x00120000)  /* GENCALL and BUSY flags */
433→
434→/** 
435→  * @brief  Communication events
436→  * 
437→  * Wait on one of these events when EV1 has already been checked and: 
438→  * 
439→  * - Slave RECEIVER mode:
440→  *     - EV2: When the application is expecting a data byte to be received. 
441→  *     - EV4: When the application is expecting the end of the communication: master 
442→  *       sends a stop condition and data transmission is stopped.
443→  *    
444→  * - Slave Transmitter mode:
445→  *    - EV3: When a byte has been transmitted by the slave and the application is expecting 
446→  *      the end of the byte transmission. The two events I2C_EVENT_SLAVE_BYTE_TRANSMITTED and
447→  *      I2C_EVENT_SLAVE_BYTE_TRANSMITTING are similar. The second one can optionally be 
448→  *      used when the user software doesn't guarantee the EV3 is managed before the
449→  *      current byte end of transfer.
450→  *    - EV3_2: When the master sends a NACK in order to tell slave that data transmission 
451→  *      shall end (before sending the STOP condition). In this case slave has to stop sending 
452→  *      data bytes and expect a Stop condition on the bus.
453→  *      
454→  *  @note In case the  user software does not guarantee that the event EV2 is 
455→  *  managed before the current byte end of transfer, then user may check on EV2 
456→  *  and BTF flag at the same time (ie. (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_BTF)).
457→  * In this case the communication may be slower.
458→  *
459→  */
460→
461→/* Slave RECEIVER mode --------------------------*/ 
462→/* --EV2 */
463→#define  I2C_EVENT_SLAVE_BYTE_RECEIVED                     ((uint32_t)0x00020040)  /* BUSY and RXNE flags */
464→/* --EV4  */
465→#define  I2C_EVENT_SLAVE_STOP_DETECTED                     ((uint32_t)0x00000010)  /* STOPF flag */
466→
467→/* Slave TRANSMITTER mode -----------------------*/
468→/* --EV3 */
469→#define  I2C_EVENT_SLAVE_BYTE_TRANSMITTED                  ((uint32_t)0x00060084)  /* TRA, BUSY, TXE and BTF flags */
470→#define  I2C_EVENT_SLAVE_BYTE_TRANSMITTING                 ((uint32_t)0x00060080)  /* TRA, BUSY and TXE flags */
471→/* --EV3_2 */
472→#define  I2C_EVENT_SLAVE_ACK_FAILURE                       ((uint32_t)0x00000400)  /* AF flag */
473→
474→/*===========================      End of Events Description           ==========================================*/
475→
476→#define IS_I2C_EVENT(EVENT) (((EVENT) == I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED) || \
477→                             ((EVENT) == I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED) || \
478→                             ((EVENT) == I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED) || \
479→                             ((EVENT) == I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED) || \
480→                             ((EVENT) == I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED) || \
481→                             ((EVENT) == I2C_EVENT_SLAVE_BYTE_RECEIVED) || \
482→                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_DUALF)) || \
483→                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_GENCALL)) || \
484→                             ((EVENT) == I2C_EVENT_SLAVE_BYTE_TRANSMITTED) || \
485→                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_DUALF)) || \
486→                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_GENCALL)) || \
487→                             ((EVENT) == I2C_EVENT_SLAVE_STOP_DETECTED) || \
488→                             ((EVENT) == I2C_EVENT_MASTER_MODE_SELECT) || \
489→                             ((EVENT) == I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) || \
490→                             ((EVENT) == I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) || \
491→                             ((EVENT) == I2C_EVENT_MASTER_BYTE_RECEIVED) || \
492→                             ((EVENT) == I2C_EVENT_MASTER_BYTE_TRANSMITTED) || \
493→                             ((EVENT) == I2C_EVENT_MASTER_BYTE_TRANSMITTING) || \
494→                             ((EVENT) == I2C_EVENT_MASTER_MODE_ADDRESS10) || \
495→                             ((EVENT) == I2C_EVENT_SLAVE_ACK_FAILURE))
496→/**
497→  * @}
498→  */
499→
500→/** @defgroup I2C_own_address1 
501→  * @{
502→  */
503→
504→#define IS_I2C_OWN_ADDRESS1(ADDRESS1) ((ADDRESS1) <= 0x3FF)
505→/**
506→  * @}
507→  */
508→
509→/** @defgroup I2C_clock_speed 
510→  * @{
511→  */
512→
513→#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) >= 0x1) && ((SPEED) <= 400000))
514→/**
515→  * @}
516→  */
517→
518→/**
519→  * @}
520→  */
521→
522→/** @defgroup I2C_Exported_Macros
523→  * @{
524→  */
525→
526→/**
527→  * @}
528→  */
529→
530→/** @defgroup I2C_Exported_Functions
531→  * @{
532→  */
533→
534→void I2C_DeInit(I2C_TypeDef* I2Cx);
535→void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
536→void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);
537→void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
538→void I2C_DMACmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
539→void I2C_DMALastTransferCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
540→void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState);
541→void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState);
542→void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState);
543→void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, uint8_t Address);
544→void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
545→void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
546→void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState);
547→void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data);
548→uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx);
549→void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction);
550→uint16_t I2C_ReadRegister(I2C_TypeDef* I2Cx, uint8_t I2C_Register);
551→void I2C_SoftwareResetCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
552→void I2C_NACKPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_NACKPosition);
553→void I2C_SMBusAlertConfig(I2C_TypeDef* I2Cx, uint16_t I2C_SMBusAlert);
554→void I2C_TransmitPEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
555→void I2C_PECPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_PECPosition);
556→void I2C_CalculatePEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
557→uint8_t I2C_GetPEC(I2C_TypeDef* I2Cx);
558→void I2C_ARPCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
559→void I2C_StretchClockCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
560→void I2C_FastModeDutyCycleConfig(I2C_TypeDef* I2Cx, uint16_t I2C_DutyCycle);
561→
562→/**
563→ * @brief
564→ ****************************************************************************************
565→ *
566→ *                         I2C State Monitoring Functions
567→ *                       
568→ ****************************************************************************************   
569→ * This I2C driver provides three different ways for I2C state monitoring
570→ *  depending on the application requirements and constraints:
571→ *        
572→ *  
573→ * 1) Basic state monitoring:
574→ *    Using I2C_CheckEvent() function:
575→ *    It compares the status registers (SR1 and SR2) content to a given event
576→ *    (can be the combination of one or more flags).
577→ *    It returns SUCCESS if the current status includes the given flags 
578→ *    and returns ERROR if one or more flags are missing in the current status.
579→ *    - When to use:
580→ *      - This function is suitable for most applications as well as for startup 
581→ *      activity since the events are fully described in the product reference manual 
582→ *      (RM0008).
583→ *      - It is also suitable for users who need to define their own events.
584→ *    - Limitations:
585→ *      - If an error occurs (ie. error flags are set besides to the monitored flags),
586→ *        the I2C_CheckEvent() function may return SUCCESS despite the communication
587→ *        hold or corrupted real state. 
588→ *        In this case, it is advised to use error interrupts to monitor the error
589→ *        events and handle them in the interrupt IRQ handler.
590→ *        
591→ *        @note 
592→ *        For error management, it is advised to use the following functions:
593→ *          - I2C_ITConfig() to configure and enable the error interrupts (I2C_IT_ERR).
594→ *          - I2Cx_ER_IRQHandler() which is called when the error interrupt occurs.
595→ *            Where x is the peripheral instance (I2C1, I2C2 ...)
596→ *          - I2C_GetFlagStatus() or I2C_GetITStatus() to be called into I2Cx_ER_IRQHandler()
597→ *            in order to determine which error occurred.
598→ *          - I2C_ClearFlag() or I2C_ClearITPendingBit() and/or I2C_SoftwareResetCmd()
599→ *            and/or I2C_GenerateStop() in order to clear the error flag and source,
600→ *            and return to correct communication status.
601→ *            
602→ *
603→ *  2) Advanced state monitoring:
604→ *     Using the function I2C_GetLastEvent() which returns the image of both status 
605→ *     registers in a single word (uint32_t) (Status Register 2 value is shifted left 
606→ *     by 16 bits and concatenated to Status Register 1).
607→ *     - When to use:
608→ *       - This function is suitable for the same applications above but it allows to
609→ *         overcome the limitations of I2C_GetFlagStatus() function (see below).
610→ *         The returned value could be compared to events already defined in the 
611→ *         library (stm32f10x_i2c.h) or to custom values defined by user.
612→ *       - This function is suitable when multiple flags are monitored at the same time.
613→ *       - At the opposite of I2C_CheckEvent() function, this function allows user to
614→ *         choose when an event is accepted (when all events flags are set and no 
615→ *         other flags are set or just when the needed flags are set like 
616→ *         I2C_CheckEvent() function).
617→ *     - Limitations:
618→ *       - User may need to define his own events.
619→ *       - Same remark concerning the error management is applicable for this 
620→ *         function if user decides to check only regular communication flags (and 
621→ *         ignores error flags).
622→ *     
623→ *
624→ *  3) Flag-based state monitoring:
625→ *     Using the function I2C_GetFlagStatus() which simply returns the status of 
626→ *     one single flag (ie. I2C_FLAG_RXNE ...). 
627→ *     - When to use:
628→ *        - This function could be used for specific applications or in debug phase.
629→ *        - It is suitable when only one flag checking is needed (most I2C events 
630→ *          are monitored through multiple flags).
631→ *     - Limitations: 
632→ *        - When calling this function, the Status register is accessed. Some flags are
633→ *          cleared when the status register is accessed. So checking the status
634→ *          of one Flag, may clear other ones.
635→ *        - Function may need to be called twice or more in order to monitor one 
636→ *          single event.
637→ *            
638→ */
639→
640→/**
641→ * 
642→ *  1) Basic state monitoring
643→ *******************************************************************************
644→ */
645→ErrorStatus I2C_CheckEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT);
646→/**
647→ * 
648→ *  2) Advanced state monitoring
649→ *******************************************************************************
650→ */
651→uint32_t I2C_GetLastEvent(I2C_TypeDef* I2Cx);
652→/**
653→ * 
654→ *  3) Flag-based state monitoring
655→ *******************************************************************************
656→ */
657→FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);
658→/**
659→ *
660→ *******************************************************************************
661→ */
662→
663→void I2C_ClearFlag(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);
664→ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
665→void I2C_ClearITPendingBit(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
666→
667→#ifdef __cplusplus
668→}
669→#endif
670→
671→#endif /*__STM32F10x_I2C_H */
672→/**
673→  * @}
674→  */ 
675→
676→/**
677→  * @}
678→  */ 
679→
680→/**
681→  * @}
682→  */ 
683→
684→/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/