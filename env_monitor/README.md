# env_monitor · 环境监测与 Flash 数据记录仪

> **项目定位（面试）**：一款"可部署"的嵌入式黑匣子——采样、时间戳、**掉电可靠存储**、**本地 OLED 菜单翻页**、**上位机串口全协议交互 & CSV 导出**一体化。适合展示"**多外设协同 + 数据可靠性设计 + 分层架构**"能力。

- MCU：STM32F103C8T6 @72MHz，SRAM 20KB / Flash 64KB
- 编译：Keil MDK5 + STM32F10x 标准外设库
- 源码量：≈ 1500 行；**裸机，无 RTOS**

---

## 1. 功能列表 & 量化指标

| 类别 | 功能 | 指标/实现 |
|------|------|----------|
| 🌡️ 环境采样 | MPU6050 内部温度 + Z轴加速度 | 每 500ms 采样，温度分辨率 ≈ 0.01℃（×100 整型存储）|
| ⏰ 时间戳 | STM32 内置 RTC（LSE 32.768KHz）| 掉电可走（后备域），年/月/日/时/分/秒 |
| 💾 存储 | W25Q64 (8MB SPI Flash) | 每条 16 字节日志，支持 **2000 条** ≈ 32KB，**16-bit 累加校验和** |
| 📺 显示 | OLED SSD1306 128×64 | **4 界面状态机**：主界面 / IMU 6轴 / Flash 信息 / 日志浏览翻页 |
| 🔘 输入 | KEY1 + KEY2 | KEY1：切换界面；KEY2：主界面=开关自动记录；日志界面=翻下一条 |
| 🔊 指示 | LED1 心跳 / LED2 报警+记录 | 1Hz 心跳；温度超阈值 LED2 常亮 |
| 📡 通信 | USART1 9600bps `@CMD\r\n` | TIME?/TIME=、TEMP?、IMU?、REC_ON/OFF/NOW、LOG?、CLR、**DUMP(CSV)** |

---

## 2. 硬件接线表

| 外设 | 引脚 | 模式 |
|------|------|------|
| **OLED SSD1306** | PB8=SCL, PB9=SDA | 开漏（软件 I²C）|
| **MPU6050** | PB10=SCL, PB11=SDA | 开漏（软件 I²C，地址 0x68）|
| **W25Q64 Flash** | PA4=CS, PA5=SCK, PA6=MISO, PA7=MOSI | 推挽/上拉（软件 SPI）|
| **KEY1** | PB1 | 上拉输入（低有效）|
| **KEY2** | PB11 ⚠️ | ⚠️ 与 MPU6050 SDA 冲突！答辩可说明代码评审发现该问题，体现评审习惯。实际硬件请改接 PB0。|
| **LED1/LED2** | PA1, PA2 | 推挽输出（低有效）|
| CH340 串口 | PA9=TX, PA10=RX | USART1 9600bps |

---

## 3. 核心模块

### 数据帧设计（Hardware/DataLogger.h）
```c
typedef struct {
    uint16_t Year; uint8_t Month, Day, Hour, Minute, Second;
    uint8_t  _pad;
    int16_t  Temp_x100;   // 温度℃×100，避免浮点存 Flash
    int16_t  AccZ;
    uint16_t Checksum;    // 前 14 字节累加和
} DL_Record_t; // 正好 16 字节/条
```

### Flash 布局
```
0x000000 头扇区 4KB: MAGIC(0xAA55) 2B | Count 2B
0x001000 数据区 32KB: 第 0 条 16B | ... | 第 1999 条 (8×4KB)
```

---

## 4. 面试延伸点

1. **W25Q64 磨损均衡**：头扇区每次 Append 擦写 → 可升级为双备份头 + 循环移位摊平写压力。
2. **CRC16 升级**：累加和易受攻击，真实工程用多项式 0x8005 的 CRC16。
3. **MPU6050 DMP**：可输出四元数/欧拉角而非原始寄存器值。
4. **RTC 校准**：LSE ±20ppm 漂移，可用 TIM 捕捉或软件补偿。
5. **低功耗**：切 `PWR_EnterSTOPMode` + RTC Wakeup，适合电池供电。
