# STM32WB Emulated UART

This repository contains the library under _./Middlewares_ of the example STM32CubeIDE project.

This project is the adaptation for STM32WB of the [STSW-STM32156](https://www.st.com/en/embedded-software/stsw-stm32156.html) firmware package made for STM32F4.

## How does it works ?

Emulation logic is well explained in [ST AN4457](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.st.com/resource/en/application_note/an4457-implementing-an-emulated-uart-on-stm32f4-microcontrollers-stmicroelectronics.pdf&ved=2ahUKEwi8if3147WFAxWdU6QEHan_AdUQFnoECBQQAQ&usg=AOvVaw0MJFVRMsqLAeEkhiaodCn6)

## How to use the example project ?

The example uses the emulated uart library to send and receive. The LED1 blink if the received data are same as transmitted.
Use a jumper to short TX pin (PB8) and RX pin (PB4), pin 3 & 4 of CN10 for STM32WB Nucleo boards.

## How to integrate the library into another project ?

- Add _./Middlewares/STM32_UART_EMUl_Library_
- Implement _HAL_UART_Emul_MspInit_ and _HAL_UART_Emul_MspDeInit_ weak functions to initialize GPIO for TX and RX pins.
- Add the needed defines for pins and handlers (example in _main.h_)

## What are the performances ?

Maximum tested speeds rounded to the nearest lower standard baudrate :

|Direction | Baudrate |
|----|--------|
| TX | 115200 |
| RX | 28800  |

## Which peripherals are used ?

This implementation use DMA1 Channels 1 & 2 and TIM1 Channel 1 & 2
