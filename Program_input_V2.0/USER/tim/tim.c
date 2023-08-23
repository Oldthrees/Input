#include <tim.h>
#include "stm32f10x_tim.h"

void TIM3_Mode_Config(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
    NVIC_InitTypeDef NVIC_InitStructure;
    
    NVIC_SetVectorTable(NVIC_VectTab_FLASH,0x0);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn; 
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;	 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = 10-1; 
    TIM_TimeBaseStructure.TIM_Prescaler = 7200-1;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;  
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
//    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
    TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM1, ENABLE); 
}