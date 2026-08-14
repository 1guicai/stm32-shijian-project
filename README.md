# stm32-shijian-project · STM32 综合实战作品集

> **项目作品集**：基于 STM32F103C8T6 标准外设库，两个原创综合应用。每个项目把多个独立知识点串成**可用系统**，特点：驱动分层（Hardware/System/User）、控制算法、数据可靠性、非阻塞调度、人机交互 + 串口协议栈。
>
> 平台：Arm Cortex-M3 / STM32F103C8T6 (72MHz, 20KB SRAM, 64KB Flash) · Keil MDK5 · STM32F10x StdPeriph_Driver

---

## 项目列表（共 2 个）

| 目录 | 项目名 | 一句话定位 | 融合的主要知识点 |
|------|--------|-----------|-----------------|
| [env_monitor/](./env_monitor/) | **环境监测 & Flash 数据记录仪** | RTC 时间戳 + 温度/加速度采集 + SPI Flash 掉电存储 + OLED 菜单 + 串口 CSV 导出 的「可部署黑匣子」 | I2C(MPU6050/OLED) · SPI(W25Q64) · RTC · USART 自定义协议 · Flash 校验和存储 · 多界面状态机 |
| [smart_car/](./smart_car/) | **增量 PID 闭环调速智能小车** | 硬件编码器测速 + 增量式 PID(抗积分饱和) + 红外里程 EXTI + 1ms 非阻塞调度 + 串口在线热调参 | TIM PWM / TIM 编码器接口(4倍频) · EXTI 中断 · 增量式 PID · 1ms 调度器 · USART 协议 |

---

## 亮点

- **源码量**：两个项目合计约 **3000 行 C 语言**，全部裸机手写（无 RTOS）。
- **分层架构**：Hardware / System / User 三层，模块化解耦。
- **存储可靠性**：每条 16 字节 + **16 位累加校验和**，支持 **2000 条**（约 32KB）掉电保存。
- **实时控制**：**50Hz** PID 计算、**100Hz** 编码器速度采样、硬件编码器接口自动 4 倍频，零中断 CPU 开销。
- **人机协议栈**：OLED 多界面 + 按键上下文操作 + USART1 `@CMD\r\n` 自定义协议 + CSV 数据导出。

---

## 编译 & 使用指南（Keil MDK5）

1. 安装 Keil MDK 5.x 与 STM32F1xx DFP。
2. 把 `User/`、`System/`、`Hardware/`、官方 `StdPeriph_Driver`、`CMSIS`、`startup_stm32f10x_md.s` 加入 Keil 工程。
3. Include Paths 加入 `.ser;.ystem;.ardware`；芯片选择 STM32F103C8。
4. 编译下载到最小系统板。
5. CH340 接 PA9/PA10，9600bps，发送 `@HELP\r\n` 查看可用命令。

---

## 技术栈总结

| 维度 | 技能/实现 |
|------|----------|
| MCU | Arm Cortex-M3（STM32F103C8T6，72MHz，20KB SRAM / 64KB Flash）|
| 开发环境 | Keil MDK5 / STM32F10x 标准外设库 / 串口助手命令行交互 |
| 通信协议 | 软件 I²C · 软件 SPI · USART1 自定义帧协议（`@CMD\r\n`，CSV 导出）|
| 外设使用 | GPIO / EXTI / NVIC / TIM（PWM、编码器接口、定时中断）/ RTC / SysTick / USART |
| 控制算法 | **增量式 PID**（抗积分饱和、输出限幅），串口在线热调参 |
| 软件架构 | 三层模块化 + 主循环状态机 + 1ms Tick 非阻塞调度 |
| 数据可靠性 | Flash 16-bit 累加校验和、MAGIC 标识、掉电保存 2000 条 |
| 工程工具 | Git + .gitignore（白名单过滤 Keil 编译产物）| GitHub 仓库管理 |
