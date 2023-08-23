#include <port.h>
#include <usart.h>

uint8_t IO_input_timer_up_flag = 0;
uint16_t IO_input_timer = 0;
uint8_t IO_input_flag = 0;

uint8_t input[6] = {0};
uint8_t input_old[6] = {0};

void GPIO_initialization(void)
{
    GPIO_InitTypeDef GPIO_Initstructure;

    RCC_APB2PeriphClockCmd(MAX485_EN_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = MAX485_EN_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MAX485_EN_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(IO_OUT_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = IO_OUT_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(IO_OUT_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(IO_IN_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = IO_IN_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(IO_IN_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(LED_STATE_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = LED_STATE_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_STATE_PORT,&GPIO_Initstructure);
    
    //输入端口配置
    RCC_APB2PeriphClockCmd(INPUT_1_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = INPUT_1_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(INPUT_1_PORT,&GPIO_Initstructure);

    RCC_APB2PeriphClockCmd(INPUT_2_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = INPUT_2_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(INPUT_2_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(INPUT_3_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = INPUT_3_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(INPUT_3_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(INPUT_4_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = INPUT_4_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(INPUT_4_PORT,&GPIO_Initstructure);

    RCC_APB2PeriphClockCmd(INPUT_5_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = INPUT_5_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(INPUT_5_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(INPUT_6_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = INPUT_6_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(INPUT_6_PORT,&GPIO_Initstructure);
    
    //输出端口配置
    RCC_APB2PeriphClockCmd(OUTPUT_1_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = OUTPUT_1_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUTPUT_1_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(OUTPUT_2_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = OUTPUT_2_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUTPUT_2_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(OUTPUT_3_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = OUTPUT_3_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUTPUT_3_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(OUTPUT_4_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = OUTPUT_4_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUTPUT_4_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(OUTPUT_5_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = OUTPUT_5_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUTPUT_5_PORT,&GPIO_Initstructure);
    
    RCC_APB2PeriphClockCmd(OUTPUT_6_CLOCK,ENABLE);
    GPIO_Initstructure.GPIO_Pin = OUTPUT_6_PINS;
    GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUTPUT_6_PORT,&GPIO_Initstructure);
}

void port_set(uint8_t port,uint8_t state)
{
    switch(port)
    {       
        case 1:
            if(state == 1)
            {
                OUTPUT_1_LOW;
            }
            else
            {
                OUTPUT_1_HIGH;
            }
            break;
        case 2:
            if(state == 1)
            {
                OUTPUT_2_LOW;
            }
            else
            {
                OUTPUT_2_HIGH;
            }
            break;
        case 3:
            if(state == 1)
            {
                OUTPUT_3_LOW;
            }
            else
            {
                OUTPUT_3_HIGH;
            }
            break;
        case 4:
            if(state == 1)
            {
                OUTPUT_4_LOW;
            }
            else
            {
                OUTPUT_4_HIGH;
            }
            break;
        case 5:
            if(state == 1)
            {
                OUTPUT_5_LOW;
            }
            else
            {
                OUTPUT_5_HIGH;
            }
            break;
        case 6:
            if(state == 1)
            {
                OUTPUT_6_LOW;
            }
            else
            {
                OUTPUT_6_HIGH;
            }
            break;
    }
}

void input_scan(void)//输入扫描
{
    if(IO_IN_READ == 1 && IO_input_timer_up_flag == 0)
    {
        IO_input_timer++;
        if(IO_input_timer > 10)
        {
            IO_input_flag = 1;
            IO_input_timer_up_flag = 1;
        }
    }
    else if(IO_IN_READ == 0)
    {
        IO_input_timer = 0;
        IO_input_timer_up_flag = 0;
    }
}




