# Platform Software
It provides a firmware foundation on which a different application runs. 
- In the main branch: Temperature Indicator
- In the can-analyzer branch: CAN Analyzer

## Table of Contents
[1. Temperature Indicator](#1-temperature-indicator)

&nbsp;&nbsp;[1.1 Functionalities](#11-functionalities)

&nbsp;&nbsp;[1.2 HW Specification](#12-hw-specification)

&nbsp;&nbsp;[1.3 SW Architecture](#13-sw-architecture)

&nbsp;&nbsp;[1.4 SW Units](#14-sw-units)

&nbsp;&nbsp;&nbsp;&nbsp;[1.4.1 LED](#141-led)

&nbsp;&nbsp;&nbsp;&nbsp;[1.4.2 PSPLY](#142-psply)

&nbsp;&nbsp;&nbsp;&nbsp;[1.4.3 ADC](#143-adc)

&nbsp;&nbsp;&nbsp;&nbsp;[1.4.4 DIO](#144-dio)

&nbsp;&nbsp;&nbsp;&nbsp;[1.4.5 I2C](#145-i2c)

&nbsp;&nbsp;&nbsp;&nbsp;[1.4.6 USART](#146-usart)

[2. CAN Analyzer](#2-can-analyzer)

&nbsp;&nbsp;[2.1 Functionalities](#21-functionalities)

&nbsp;&nbsp;[2.2 HW Specification](#22-hw-specification)

&nbsp;&nbsp;[2.3 SW Architecture](#23-sw-architecture)

&nbsp;&nbsp;[2.4 SW Units](#24-sw-units)

## 1. Temperature Indicator

### 1.1 Functionalities
The main functionality is to indicate the current temperature. When the below pre-conditions are met, the green LED will be on if the temperature is higher than 25 degree. The red LED will be on if the temperature is lower than 25 degree. 
The current temperature value is sent over to the USART hardware. A PC can read it via a COM port using a USB-USART bridge. 

.Pre-condition 1: The MCU gets a stable voltage.

.Pre-condition 2: User pushes the external button connected to the MCU.

### 1.2 HW Specification
Microcontoller: STM32F4

Temperature sensor: MPU-6050

### 1.3 SW Architecture
![plot](./Architecture.jpg)
FreeRTOS is used as Real-time OS and the basic AUTOSAR architecture is applied to decrease hardware dependencies. It consists of the three layers, Application software layer (APPL), Run-time environment (RTE), Basic software layer (BSW). RTE just serves as an interface between APPL and BSW. The architecture decouples APPL from the hardware so that reusability is ensured. Runnables are called by RTOS instead of RTE. 

### 1.4 SWUnits
#### 1.4.1 LED
It implements the main functionality. It checks if the two pre-conditions are fulfilled. It turns the green LED on and the red LED off if the temperature is higher than 25 degree. Otherwise, it turns the green LED off and the red LED on.

#### 1.4.2 PSPLY
It determines the status of power supply. If the MCU gets a stable voltage, the status will be set to Operation mode. Otherwise, it will be set to Non-operation mode.

#### 1.4.3 ADC
It reads the voltage level of power by Analog-to-Digital Converter. Every 5ms the voltage is measured and recorded. Every 50ms recorded voltage values are evaluated to see if it is stable.  

#### 1.4.4 DIO
It forms the interface towards the GPIO hardware by calling the driver APIs. 

#### 1.4.5 I2C
It represents abstraction of signals (Temperature, Accelerometer, Gyroscpoe) measured by the MPU-6050 sensor. It communicates with the sensor via I2C protocol by calling the driver APIs.

#### 1.4.6 USART
It sends a measured temperature value to the USART hardware every 50ms.