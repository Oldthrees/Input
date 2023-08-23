#include <usart.h>
#include "stm32f10x_it.h" 
#include "stm32f10x_usart.h"

uint8_t sum(uint8_t *array, uint8_t n)//对数组a的前n个元素求和，并返回和值
{
    uint8_t add = 0;
    for(uint8_t i=0;i<n;++i)
        add+=array[i];
    return add;
}

void data_send(USART_TypeDef* USARTx,uint8_t *array,uint16_t num)
{
    for(int j=0;j<num;j++) 
    {
        while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);  
        USART_SendData(USARTx,array[j]);  
    }
}

void USART2_Configuration(void)
{
    USART_InitTypeDef USART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
    
    NVIC_SetVectorTable(NVIC_VectTab_FLASH,0x0);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; 
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    //USART2
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    USART_InitStructure.USART_BaudRate = 57600;//串口波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
    USART_Init(USART2, &USART_InitStructure); //初始化串口
    
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//开启串口接受中断
    USART_ITConfig(USART2, USART_IT_IDLE, ENABLE);//开启串口帧中断
    
    USART_Cmd(USART2, ENABLE);                    //使能串口
    
    USART_ClearFlag(USART2,USART_FLAG_TC);
}

void uart_recv(void)
{ 
    if(Usart2_recv_state==FINISH)
    {
        if(Usart2_RecvBuffer[0] == 0x01 && IO_IN_READ == 1 && config.addr == 0)//地址配置
        {
            if((Usart2_RecvBuffer[1] == Usart2_RecvPointer) && (Usart2_RecvPointer == 5))
            {
                if(Usart2_RecvBuffer[4] == sum(Usart2_RecvBuffer,4))
                {   
                    if(Usart2_RecvBuffer[2] == TYPE)
                    {
                        config.addr = Usart2_RecvBuffer[3];//配置地址
                        
                        /******将配置好的地址写入flash中******/
                        uint8_t data[1] = {0};
                        uint32_t Address = 0;
                        unsigned char *data_para;
                        
                        data[0] = config.addr;
                        data_para = data;
                        FLASH_Unlock();
                        FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
                        FLASH_ErasePage(COMMUNICATION_ADDR_ADDR);

                        Address = COMMUNICATION_ADDR_ADDR;

                        for(uint8_t k=0;k<1;k++)
                        {
                            FLASH_ProgramHalfWord(Address,*((uint16_t*)data_para));
                            Address += 2;
                            data_para += 2;
                        }
                        FLASH_Lock();
                        /**************************************/
                        
                        delay_ms(10);
                        
                        IO_OUT_HIGH;
                    }
                }
            }
        }
        if(Usart2_RecvBuffer[0] == 0x01 && config.addr != 0)//地址清空
        {
            if((Usart2_RecvBuffer[1] == Usart2_RecvPointer) && (Usart2_RecvPointer == 4))
            {
                if(Usart2_RecvBuffer[3] == sum(Usart2_RecvBuffer,3))
                {   
                    if(Usart2_RecvBuffer[2] == 0xff)
                    {
                        config.addr = 0;//地址清空
                        config.state = 0;//地址尚未配置完成
                        config.send_flag = 0;
                        timer = 0;
                    }
                }
            }
        }
        if(Usart2_RecvBuffer[0] == 0x02 && config.addr != 0)//地址配置完成
        {
            if((Usart2_RecvBuffer[1] == Usart2_RecvPointer) && (Usart2_RecvPointer == 3))
            {
                if(Usart2_RecvBuffer[2] == sum(Usart2_RecvBuffer,2))
                {   
                    IO_OUT_LOW;
                    
                    config.state = 1;//地址配置完成
                }
            }
        }
        if(Usart2_RecvBuffer[0] == 0x04 && config.addr == Usart2_RecvBuffer[3])//输出
        {
            if((Usart2_RecvBuffer[1] == Usart2_RecvPointer) && (Usart2_RecvPointer == 7))
            {
                if(Usart2_RecvBuffer[6] == sum(Usart2_RecvBuffer,6))
                {   
                    if(Usart2_RecvBuffer[2] == TYPE)
                    {
                        port_set(Usart2_RecvBuffer[4],Usart2_RecvBuffer[5]);
                    }
                }
            }
        }
        memset(Usart2_RecvBuffer,0,100);
        Usart2_RecvPointer = 0;
        Usart2_recv_state=FREE;
    }
}




