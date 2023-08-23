#ifndef __IWDG_H_
#define __IWDG_H_

#define WATCH_DOG               1       //ø¥√≈π∑

#include "stm32f10x.h"

extern void IWDG_Config(uint8_t prv ,uint16_t rlv);
extern void IWDG_Feed(void);
#endif