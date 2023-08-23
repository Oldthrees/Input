#ifndef __FLASH_H_
#define __FLASH_H_

#include "stm32f10x.h"

extern void flash_write(uint32_t addr,uint8_t data[],uint16_t num);
extern void flash_read(uint32_t addr,uint8_t data[],uint16_t point,uint16_t num);

#endif