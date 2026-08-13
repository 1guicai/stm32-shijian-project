# smart_car · 增量 PID 闭环调速智能小车

> **项目定位（面试）**：体现"**实时控制 + 多传感器融合 + 参数可调试**"的典型机电一体化项目。自己写增量式 PID（抗积分饱和）、硬件编码器接口测速、1ms 非阻塞调度，支持 OLED 双界面实时看参数 + **串口在线热调参**——面试官一看就懂、能聊半小时。

- MCU：STM32F103C8T6 @72MHz
- 编译：Keil MDK5 + STM32F10x 标准外设库
- 源码量：≈ 1500 行；**裸机，无 RTOS**，全部手写调度

---

## 1. 功能列表 & 量化指标

| 类别 | 功能 | 指标/实现 |
|------|------|----------|
| ⚡ 驱动 | PWM 直流电机双通道 | TIM2_CH1/CH2 (PA0/PA1) 0~100% 占空比，频率 1kHz |
| 📏 测速 | 正交编码器（TIM3 编码器接口）| 4 倍频计数，50Hz 采样 → ±rpm / cm/s |
| 🚗 里程 | 红外对射（EXTI）计数 | 每圈 20 格 → 累计里程 mm 级精度 |
| 🎛️ 控制 | **增量式 PID 闭环调速** | `Out = Kp·e + Ki·∑e + Kd·Δe`，抗积分饱和裁剪，输出 0~100% |
| 📺 显示 | OLED 双界面 | 界面1：目标速度/实际速度/PWM；界面2：里程/运行时间/PID 参数 |
| 🔘 输入 | KEY1 + KEY2 | KEY1：切屏；KEY2：界面1=目标速度±10；界面2=启动/停车 |
| 📡 通信 | USART1 9600bps `@CMD\r\n` | `@SPD=xx` 设目标；`@PID=kp,ki,kd,max` 在线热调参 |
| ⏱️ 调度 | TIM2 1ms 非阻塞调度器 | 50Hz PID / 1Hz 秒计数 / 2Hz LED 心跳 |

**典型参数（默认）**：Kp=1.2，Ki=0.3，Kd=0.05，OutMax=100（%）。空载电机 6V 时目标速度 80 rpm，稳态误差 < ±3 rpm。

---

## 2. 硬件接线表

| 外设 | 引脚 | 模式 |
|------|------|------|
| 电机A PWM | PA0 (TIM2_CH1) | AF_PP → TB6612 PWMA |
| 电机B PWM | PA1 (TIM2_CH2) | AF_PP → TB6612 PWMB |
| 电机方向 | PA2=AIN1, PA3=AIN2, PA4=BIN1, PA5=BIN2 | Out_PP（正转=10，反转=01，刹车=11）|
| **编码器 A/B** | PA6 (TIM3_CH1), PA7 (TIM3_CH2) | IPU 编码器接口 | 硬件 4 倍频！不用软件数脉冲 |
| **红外对射** | PB14 / EXTI14 | IPU 下降沿触发 | 车轮码盘每转 N 脉冲 → 累计里程 |
| OLED SSD1306 | PB8=SCL, PB9=SDA | 软件 I²C | 0.96" 128×64 |
| KEY1 | PB5 | IPU 低有效 | 切屏 |
| KEY2 | PB4 | IPU 低有效 | 上下文动作（调速/启停）|
| CH340 串口 | PA9=TX, PA10=RX | USART1 9600bps | 调参/监控 |
| 电源 | 外部 6~12V → TB6612 VM；MCU 5V/3.3V | GND 共地 | ⚠️ 驱动与 MCU 必须共地 |

> 面试可讲：为什么选 **TIM 硬件编码器接口**？——软件数脉冲在高速下丢脉冲、占 CPU；硬件编码器接口自动 4 倍频、16 位计数器，CPU 只读寄存器，零中断开销。

---

## 3. 串口命令 & 在线调参

| 命令 | 示例 | 说明 |
|------|------|------|
| `HELP` | `@HELP\r\n` | 命令列表 |
| `INFO?` | `@INFO?\r\n` | 打印当前 Kp/Ki/Kd/OutMax、目标速度、里程、秒计数 |
| `GO/STOP` | `@GO\r\n` | 启动闭环 / 停止（PWM=0）|
| `SPD=` | `@SPD=80\r\n` | 设定目标速度（pulse/100ms）|
| `SPD?` | `@SPD?\r\n` | 当前目标+实际速度+PWM |
| `PID=` | `@PID=1.2,0.3,0.05,100\r\n` | **在线热写 PID 参数 + 输出上限** |
| `PID?` | `@PID?\r\n` | 读回当前参数 |
| `ODO?` | `@ODO?\r\n` | 总里程（脉冲数 / mm）+ 运行秒数 |
| `ODO=0` | `@ODO=0\r\n` | 里程清零 |

---

## 4. 核心算法

### 增量式 PID（Hardware/PID.c）
```c
float PID_Step(PID_t *p, float Measure) {
    float Err   = p->Setpoint - Measure;
    p->Integral += Err;
    if (p->Integral*p->Ki >  p->OutMax) p->Integral =  p->OutMax/p->Ki;
    if (p->Integral*p->Ki < -p->OutMax) p->Integral = -p->OutMax/p->Ki;
    float Deriv = Err - p->LastErr;
    float Out = p->Kp*Err + p->Ki*p->Integral + p->Kd*Deriv;
    p->LastErr = Err;
    Out = (Out>p->OutMax)?p->OutMax:(Out<p->OutMin?p->OutMin:Out);
    return Out;
}
```
> 面试可讲：位置式 vs 增量式？——增量式输出是"**本次要加/减多少**"，对执行器冲击小，需要执行器有积分（电机 PWM→转速是惯性环节=天然积分）。

### 1ms 非阻塞调度器（System/Timer.c）
```c
volatile uint16_t Timer_Tick;  // TIM2 中断每 1ms++
if(Timer_Tick - last_pid  >= 20)   { /* 50Hz PID */ }
if(Timer_Tick - last_sec  >= 1000) { /* 1Hz  秒计数 */ }
```

---

## 5. 面试延伸点

1. **双轮差速闭环独立**：左右轮各一个 PID → 差速转直角弯、弧线。
2. **加 MPU6050**：Z 轴角速度积分航向角 → 航向闭环（平衡车方向基础）。
3. **灰度循迹 + 5 路红外**：位置 PD（循迹）嵌套速度 PID（串级 PID），面试官超爱问。
4. **蓝牙 HC-05**：手机 APP 实时曲线（Serial 不变，把 CH340 换蓝牙）。
5. **工程化**：PID 参数掉电保存在 Flash/BKP；上位机一键整定（Ziegler-Nichols 法）。
