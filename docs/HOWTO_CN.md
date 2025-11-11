# STM32-NexstarMountLib 使用指南 (HOWTO_CN)

## 1. 介绍
STM32-NexstarMountLib 是一个专为 STM32 开发的库，旨在提供对 Nexstar Mount 控制的简便访问，提高用户的天文观测体验。

## 2. 前提条件
- 硬件：STM32 微控制器
- 软件：Keil, STM32CubeIDE 或 Arduino IDE
- 工具：USB 转串口适配器及其驱动程序

## 3. 开始使用
1. 下载 STM32-NexstarMountLib 源代码。
2. 在您的开发环境中打开项目。
3. 配置您的 STM32 环境并确保所有的库和驱动已正确安装。

## 4. 基本用法
- 初始化库：
  ```c
  NexstarMount_Init();
  ```
- 控制马达：
  ```c
  NexstarMount_MoveUp();
  ```

## 5. GPS 集成
1. 连接 GPS 模块到 STM32。
2. 在代码中初始化 GPS 模块：
  ```c
  GPS_Init();
  ```
3. 获取当前位置：
  ```c
  GPS_GetLocation();
  ```

## 6. 故障排除
- 如果设备无法连接，请检查串口设置是否正确。
- 如果 GPS 信号弱，请尝试在开阔区域使用。

## 7. 高级功能
- 自动寻星：利用 GPS 数据自动设置目标星体。
- 自定义设置：通过配置文件调整库的行为，将其适应您的需求。 

## 8. 版本信息
- 当前版本：1.0.0
- 更新日期：2025-11-11

请确保根据需要定期检查库的更新与维护。