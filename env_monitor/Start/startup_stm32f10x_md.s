  1→;******************** (C) COPYRIGHT 2011 STMicroelectronics ********************
  2→;* File Name          : startup_stm32f10x_md.s
  3→;* Author             : MCD Application Team
  4→;* Version            : V3.5.0
  5→;* Date               : 11-March-2011
  6→;* Description        : STM32F10x Medium Density Devices vector table for MDK-ARM 
  7→;*                      toolchain.  
  8→;*                      This module performs:
  9→;*                      - Set the initial SP
 10→;*                      - Set the initial PC == Reset_Handler
 11→;*                      - Set the vector table entries with the exceptions ISR address
 12→;*                      - Configure the clock system
 13→;*                      - Branches to __main in the C library (which eventually
 14→;*                        calls main()).
 15→;*                      After Reset the CortexM3 processor is in Thread mode,
 16→;*                      priority is Privileged, and the Stack is set to Main.
 17→;* <<< Use Configuration Wizard in Context Menu >>>   
 18→;*******************************************************************************
 19→; THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 20→; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
 21→; AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
 22→; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
 23→; CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
 24→; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 25→;*******************************************************************************
 26→
 27→; Amount of memory (in bytes) allocated for Stack
 28→; Tailor this value to your application needs
 29→; <h> Stack Configuration
 30→;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
 31→; </h>
 32→
 33→Stack_Size      EQU     0x00000400
 34→
 35→                AREA    STACK, NOINIT, READWRITE, ALIGN=3
 36→Stack_Mem       SPACE   Stack_Size
 37→__initial_sp
 38→
 39→
 40→; <h> Heap Configuration
 41→;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
 42→; </h>
 43→
 44→Heap_Size       EQU     0x00000200
 45→
 46→                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
 47→__heap_base
 48→Heap_Mem        SPACE   Heap_Size
 49→__heap_limit
 50→
 51→                PRESERVE8
 52→                THUMB
 53→
 54→
 55→; Vector Table Mapped to Address 0 at Reset
 56→                AREA    RESET, DATA, READONLY
 57→                EXPORT  __Vectors
 58→                EXPORT  __Vectors_End
 59→                EXPORT  __Vectors_Size
 60→
 61→__Vectors       DCD     __initial_sp               ; Top of Stack
 62→                DCD     Reset_Handler              ; Reset Handler
 63→                DCD     NMI_Handler                ; NMI Handler
 64→                DCD     HardFault_Handler          ; Hard Fault Handler
 65→                DCD     MemManage_Handler          ; MPU Fault Handler
 66→                DCD     BusFault_Handler           ; Bus Fault Handler
 67→                DCD     UsageFault_Handler         ; Usage Fault Handler
 68→                DCD     0                          ; Reserved
 69→                DCD     0                          ; Reserved
 70→                DCD     0                          ; Reserved
 71→                DCD     0                          ; Reserved
 72→                DCD     SVC_Handler                ; SVCall Handler
 73→                DCD     DebugMon_Handler           ; Debug Monitor Handler
 74→                DCD     0                          ; Reserved
 75→                DCD     PendSV_Handler             ; PendSV Handler
 76→                DCD     SysTick_Handler            ; SysTick Handler
 77→
 78→                ; External Interrupts
 79→                DCD     WWDG_IRQHandler            ; Window Watchdog
 80→                DCD     PVD_IRQHandler             ; PVD through EXTI Line detect
 81→                DCD     TAMPER_IRQHandler          ; Tamper
 82→                DCD     RTC_IRQHandler             ; RTC
 83→                DCD     FLASH_IRQHandler           ; Flash
 84→                DCD     RCC_IRQHandler             ; RCC
 85→                DCD     EXTI0_IRQHandler           ; EXTI Line 0
 86→                DCD     EXTI1_IRQHandler           ; EXTI Line 1
 87→                DCD     EXTI2_IRQHandler           ; EXTI Line 2
 88→                DCD     EXTI3_IRQHandler           ; EXTI Line 3
 89→                DCD     EXTI4_IRQHandler           ; EXTI Line 4
 90→                DCD     DMA1_Channel1_IRQHandler   ; DMA1 Channel 1
 91→                DCD     DMA1_Channel2_IRQHandler   ; DMA1 Channel 2
 92→                DCD     DMA1_Channel3_IRQHandler   ; DMA1 Channel 3
 93→                DCD     DMA1_Channel4_IRQHandler   ; DMA1 Channel 4
 94→                DCD     DMA1_Channel5_IRQHandler   ; DMA1 Channel 5
 95→                DCD     DMA1_Channel6_IRQHandler   ; DMA1 Channel 6
 96→                DCD     DMA1_Channel7_IRQHandler   ; DMA1 Channel 7
 97→                DCD     ADC1_2_IRQHandler          ; ADC1_2
 98→                DCD     USB_HP_CAN1_TX_IRQHandler  ; USB High Priority or CAN1 TX
 99→                DCD     USB_LP_CAN1_RX0_IRQHandler ; USB Low  Priority or CAN1 RX0
100→                DCD     CAN1_RX1_IRQHandler        ; CAN1 RX1
101→                DCD     CAN1_SCE_IRQHandler        ; CAN1 SCE
102→                DCD     EXTI9_5_IRQHandler         ; EXTI Line 9..5
103→                DCD     TIM1_BRK_IRQHandler        ; TIM1 Break
104→                DCD     TIM1_UP_IRQHandler         ; TIM1 Update
105→                DCD     TIM1_TRG_COM_IRQHandler    ; TIM1 Trigger and Commutation
106→                DCD     TIM1_CC_IRQHandler         ; TIM1 Capture Compare
107→                DCD     TIM2_IRQHandler            ; TIM2
108→                DCD     TIM3_IRQHandler            ; TIM3
109→                DCD     TIM4_IRQHandler            ; TIM4
110→                DCD     I2C1_EV_IRQHandler         ; I2C1 Event
111→                DCD     I2C1_ER_IRQHandler         ; I2C1 Error
112→                DCD     I2C2_EV_IRQHandler         ; I2C2 Event
113→                DCD     I2C2_ER_IRQHandler         ; I2C2 Error
114→                DCD     SPI1_IRQHandler            ; SPI1
115→                DCD     SPI2_IRQHandler            ; SPI2
116→                DCD     USART1_IRQHandler          ; USART1
117→                DCD     USART2_IRQHandler          ; USART2
118→                DCD     USART3_IRQHandler          ; USART3
119→                DCD     EXTI15_10_IRQHandler       ; EXTI Line 15..10
120→                DCD     RTCAlarm_IRQHandler        ; RTC Alarm through EXTI Line
121→                DCD     USBWakeUp_IRQHandler       ; USB Wakeup from suspend
122→__Vectors_End
123→
124→__Vectors_Size  EQU  __Vectors_End - __Vectors
125→
126→                AREA    |.text|, CODE, READONLY
127→
128→; Reset handler
129→Reset_Handler    PROC
130→                 EXPORT  Reset_Handler             [WEAK]
131→     IMPORT  __main
132→     IMPORT  SystemInit
133→                 LDR     R0, =SystemInit
134→                 BLX     R0
135→                 LDR     R0, =__main
136→                 BX      R0
137→                 ENDP
138→
139→; Dummy Exception Handlers (infinite loops which can be modified)
140→
141→NMI_Handler     PROC
142→                EXPORT  NMI_Handler                [WEAK]
143→                B       .
144→                ENDP
145→HardFault_Handler\
146→                PROC
147→                EXPORT  HardFault_Handler          [WEAK]
148→                B       .
149→                ENDP
150→MemManage_Handler\
151→                PROC
152→                EXPORT  MemManage_Handler          [WEAK]
153→                B       .
154→                ENDP
155→BusFault_Handler\
156→                PROC
157→                EXPORT  BusFault_Handler           [WEAK]
158→                B       .
159→                ENDP
160→UsageFault_Handler\
161→                PROC
162→                EXPORT  UsageFault_Handler         [WEAK]
163→                B       .
164→                ENDP
165→SVC_Handler     PROC
166→                EXPORT  SVC_Handler                [WEAK]
167→                B       .
168→                ENDP
169→DebugMon_Handler\
170→                PROC
171→                EXPORT  DebugMon_Handler           [WEAK]
172→                B       .
173→                ENDP
174→PendSV_Handler  PROC
175→                EXPORT  PendSV_Handler             [WEAK]
176→                B       .
177→                ENDP
178→SysTick_Handler PROC
179→                EXPORT  SysTick_Handler            [WEAK]
180→                B       .
181→                ENDP
182→
183→Default_Handler PROC
184→
185→                EXPORT  WWDG_IRQHandler            [WEAK]
186→                EXPORT  PVD_IRQHandler             [WEAK]
187→                EXPORT  TAMPER_IRQHandler          [WEAK]
188→                EXPORT  RTC_IRQHandler             [WEAK]
189→                EXPORT  FLASH_IRQHandler           [WEAK]
190→                EXPORT  RCC_IRQHandler             [WEAK]
191→                EXPORT  EXTI0_IRQHandler           [WEAK]
192→                EXPORT  EXTI1_IRQHandler           [WEAK]
193→                EXPORT  EXTI2_IRQHandler           [WEAK]
194→                EXPORT  EXTI3_IRQHandler           [WEAK]
195→                EXPORT  EXTI4_IRQHandler           [WEAK]
196→                EXPORT  DMA1_Channel1_IRQHandler   [WEAK]
197→                EXPORT  DMA1_Channel2_IRQHandler   [WEAK]
198→                EXPORT  DMA1_Channel3_IRQHandler   [WEAK]
199→                EXPORT  DMA1_Channel4_IRQHandler   [WEAK]
200→                EXPORT  DMA1_Channel5_IRQHandler   [WEAK]
201→                EXPORT  DMA1_Channel6_IRQHandler   [WEAK]
202→                EXPORT  DMA1_Channel7_IRQHandler   [WEAK]
203→                EXPORT  ADC1_2_IRQHandler          [WEAK]
204→                EXPORT  USB_HP_CAN1_TX_IRQHandler  [WEAK]
205→                EXPORT  USB_LP_CAN1_RX0_IRQHandler [WEAK]
206→                EXPORT  CAN1_RX1_IRQHandler        [WEAK]
207→                EXPORT  CAN1_SCE_IRQHandler        [WEAK]
208→                EXPORT  EXTI9_5_IRQHandler         [WEAK]
209→                EXPORT  TIM1_BRK_IRQHandler        [WEAK]
210→                EXPORT  TIM1_UP_IRQHandler         [WEAK]
211→                EXPORT  TIM1_TRG_COM_IRQHandler    [WEAK]
212→                EXPORT  TIM1_CC_IRQHandler         [WEAK]
213→                EXPORT  TIM2_IRQHandler            [WEAK]
214→                EXPORT  TIM3_IRQHandler            [WEAK]
215→                EXPORT  TIM4_IRQHandler            [WEAK]
216→                EXPORT  I2C1_EV_IRQHandler         [WEAK]
217→                EXPORT  I2C1_ER_IRQHandler         [WEAK]
218→                EXPORT  I2C2_EV_IRQHandler         [WEAK]
219→                EXPORT  I2C2_ER_IRQHandler         [WEAK]
220→                EXPORT  SPI1_IRQHandler            [WEAK]
221→                EXPORT  SPI2_IRQHandler            [WEAK]
222→                EXPORT  USART1_IRQHandler          [WEAK]
223→                EXPORT  USART2_IRQHandler          [WEAK]
224→                EXPORT  USART3_IRQHandler          [WEAK]
225→                EXPORT  EXTI15_10_IRQHandler       [WEAK]
226→                EXPORT  RTCAlarm_IRQHandler        [WEAK]
227→                EXPORT  USBWakeUp_IRQHandler       [WEAK]
228→
229→WWDG_IRQHandler
230→PVD_IRQHandler
231→TAMPER_IRQHandler
232→RTC_IRQHandler
233→FLASH_IRQHandler
234→RCC_IRQHandler
235→EXTI0_IRQHandler
236→EXTI1_IRQHandler
237→EXTI2_IRQHandler
238→EXTI3_IRQHandler
239→EXTI4_IRQHandler
240→DMA1_Channel1_IRQHandler
241→DMA1_Channel2_IRQHandler
242→DMA1_Channel3_IRQHandler
243→DMA1_Channel4_IRQHandler
244→DMA1_Channel5_IRQHandler
245→DMA1_Channel6_IRQHandler
246→DMA1_Channel7_IRQHandler
247→ADC1_2_IRQHandler
248→USB_HP_CAN1_TX_IRQHandler
249→USB_LP_CAN1_RX0_IRQHandler
250→CAN1_RX1_IRQHandler
251→CAN1_SCE_IRQHandler
252→EXTI9_5_IRQHandler
253→TIM1_BRK_IRQHandler
254→TIM1_UP_IRQHandler
255→TIM1_TRG_COM_IRQHandler
256→TIM1_CC_IRQHandler
257→TIM2_IRQHandler
258→TIM3_IRQHandler
259→TIM4_IRQHandler
260→I2C1_EV_IRQHandler
261→I2C1_ER_IRQHandler
262→I2C2_EV_IRQHandler
263→I2C2_ER_IRQHandler
264→SPI1_IRQHandler
265→SPI2_IRQHandler
266→USART1_IRQHandler
267→USART2_IRQHandler
268→USART3_IRQHandler
269→EXTI15_10_IRQHandler
270→RTCAlarm_IRQHandler
271→USBWakeUp_IRQHandler
272→
273→                B       .
274→
275→                ENDP
276→
277→                ALIGN
278→
279→;*******************************************************************************
280→; User Stack and Heap initialization
281→;*******************************************************************************
282→                 IF      :DEF:__MICROLIB           
283→                
284→                 EXPORT  __initial_sp
285→                 EXPORT  __heap_base
286→                 EXPORT  __heap_limit
287→                
288→                 ELSE
289→                
290→                 IMPORT  __use_two_region_memory
291→                 EXPORT  __user_initial_stackheap
292→                 
293→__user_initial_stackheap
294→
295→                 LDR     R0, =  Heap_Mem
296→                 LDR     R1, =(Stack_Mem + Stack_Size)
297→                 LDR     R2, = (Heap_Mem +  Heap_Size)
298→                 LDR     R3, = Stack_Mem
299→                 BX      LR
300→
301→                 ALIGN
302→
303→                 ENDIF
304→
305→                 END
306→
307→;******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE*****