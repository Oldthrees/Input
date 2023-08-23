#ifndef __PORT_H_
#define __PORT_H_

#include "stm32f10x.h"

#define MAX485_EN_CLOCK         (RCC_APB2Periph_GPIOB)
#define MAX485_EN_PORT          (GPIOB)
#define MAX485_EN_PINS          (GPIO_Pin_9)
#define MAX485_SEND             GPIO_SetBits(MAX485_EN_PORT,MAX485_EN_PINS)
#define MAX485_RECV             GPIO_ResetBits(MAX485_EN_PORT,MAX485_EN_PINS)

#define IO_IN_CLOCK             (RCC_APB2Periph_GPIOB)
#define IO_IN_PORT              (GPIOB)
#define IO_IN_PINS              (GPIO_Pin_1)
#define IO_IN_READ              GPIO_ReadInputDataBit(IO_IN_PORT,IO_IN_PINS)

#define IO_OUT_CLOCK            (RCC_APB2Periph_GPIOB)
#define IO_OUT_PORT             (GPIOB)
#define IO_OUT_PINS             (GPIO_Pin_8)
#define IO_OUT_HIGH             GPIO_SetBits(IO_OUT_PORT,IO_OUT_PINS)
#define IO_OUT_LOW              GPIO_ResetBits(IO_OUT_PORT,IO_OUT_PINS)

#define LED_STATE_CLOCK         (RCC_APB2Periph_GPIOA)
#define LED_STATE_PORT          (GPIOA)
#define LED_STATE_PINS          (GPIO_Pin_4)
#define LED_STATE_HIGH          GPIO_SetBits(LED_STATE_PORT,LED_STATE_PINS)
#define LED_STATE_LOW           GPIO_ResetBits(LED_STATE_PORT,LED_STATE_PINS)

#define INPUT_6_CLOCK        (RCC_APB2Periph_GPIOB)
#define INPUT_6_PORT         (GPIOB)
#define INPUT_6_PINS         (GPIO_Pin_6)
#define INPUT_6_READ         GPIO_ReadInputDataBit(INPUT_6_PORT,INPUT_6_PINS)

#define INPUT_5_CLOCK        (RCC_APB2Periph_GPIOA)
#define INPUT_5_PORT         (GPIOA)
#define INPUT_5_PINS         (GPIO_Pin_11)
#define INPUT_5_READ         GPIO_ReadInputDataBit(INPUT_5_PORT,INPUT_5_PINS)

#define INPUT_4_CLOCK        (RCC_APB2Periph_GPIOA)
#define INPUT_4_PORT         (GPIOA)
#define INPUT_4_PINS         (GPIO_Pin_9)
#define INPUT_4_READ         GPIO_ReadInputDataBit(INPUT_4_PORT,INPUT_4_PINS)

#define INPUT_3_CLOCK        (RCC_APB2Periph_GPIOB)
#define INPUT_3_PORT         (GPIOB)
#define INPUT_3_PINS         (GPIO_Pin_15)
#define INPUT_3_READ         GPIO_ReadInputDataBit(INPUT_3_PORT,INPUT_3_PINS)

#define INPUT_2_CLOCK        (RCC_APB2Periph_GPIOB)
#define INPUT_2_PORT         (GPIOB)
#define INPUT_2_PINS         (GPIO_Pin_13)
#define INPUT_2_READ         GPIO_ReadInputDataBit(INPUT_2_PORT,INPUT_2_PINS)

#define INPUT_1_CLOCK        (RCC_APB2Periph_GPIOB)
#define INPUT_1_PORT         (GPIOB)
#define INPUT_1_PINS         (GPIO_Pin_10)
#define INPUT_1_READ         GPIO_ReadInputDataBit(INPUT_1_PORT,INPUT_1_PINS)

#define OUTPUT_6_CLOCK         (RCC_APB2Periph_GPIOB)
#define OUTPUT_6_PORT          (GPIOB)
#define OUTPUT_6_PINS          (GPIO_Pin_7)
#define OUTPUT_6_HIGH          GPIO_SetBits(OUTPUT_6_PORT,OUTPUT_6_PINS)
#define OUTPUT_6_LOW           GPIO_ResetBits(OUTPUT_6_PORT,OUTPUT_6_PINS)

#define OUTPUT_5_CLOCK         (RCC_APB2Periph_GPIOA)
#define OUTPUT_5_PORT          (GPIOA)
#define OUTPUT_5_PINS          (GPIO_Pin_12)
#define OUTPUT_5_HIGH          GPIO_SetBits(OUTPUT_5_PORT,OUTPUT_5_PINS)
#define OUTPUT_5_LOW           GPIO_ResetBits(OUTPUT_5_PORT,OUTPUT_5_PINS)

#define OUTPUT_4_CLOCK         (RCC_APB2Periph_GPIOA)
#define OUTPUT_4_PORT          (GPIOA)
#define OUTPUT_4_PINS          (GPIO_Pin_10)
#define OUTPUT_4_HIGH          GPIO_SetBits(OUTPUT_4_PORT,OUTPUT_4_PINS)
#define OUTPUT_4_LOW           GPIO_ResetBits(OUTPUT_4_PORT,OUTPUT_4_PINS)

#define OUTPUT_3_CLOCK         (RCC_APB2Periph_GPIOA)
#define OUTPUT_3_PORT          (GPIOA)
#define OUTPUT_3_PINS          (GPIO_Pin_8)
#define OUTPUT_3_HIGH          GPIO_SetBits(OUTPUT_3_PORT,OUTPUT_3_PINS)
#define OUTPUT_3_LOW           GPIO_ResetBits(OUTPUT_3_PORT,OUTPUT_3_PINS)

#define OUTPUT_2_CLOCK         (RCC_APB2Periph_GPIOB)
#define OUTPUT_2_PORT          (GPIOB)
#define OUTPUT_2_PINS          (GPIO_Pin_14)
#define OUTPUT_2_HIGH          GPIO_SetBits(OUTPUT_2_PORT,OUTPUT_2_PINS)
#define OUTPUT_2_LOW           GPIO_ResetBits(OUTPUT_2_PORT,OUTPUT_2_PINS)

#define OUTPUT_1_CLOCK         (RCC_APB2Periph_GPIOB)
#define OUTPUT_1_PORT          (GPIOB)
#define OUTPUT_1_PINS          (GPIO_Pin_11)
#define OUTPUT_1_HIGH          GPIO_SetBits(OUTPUT_1_PORT,OUTPUT_1_PINS)
#define OUTPUT_1_LOW           GPIO_ResetBits(OUTPUT_1_PORT,OUTPUT_1_PINS)

extern void GPIO_initialization(void);
extern void input_scan(void);//输入扫描
extern void port_set(uint8_t port,uint8_t state);

extern uint8_t IO_input_timer_up_flag;
extern uint16_t IO_input_timer;
extern uint8_t IO_input_flag;

extern uint8_t input[6];
extern uint8_t input_old[6];

#endif