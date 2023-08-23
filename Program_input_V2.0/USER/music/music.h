#ifndef __MUSIC_H_
#define __MUSIC_H_

#include "stm32f10x.h"

#define         ENTER_IN_CONFIG_MUSIC           1       //
#define         ORDER_TRIGGER_MUSIC             2       //

extern void play_music(uint8_t file,uint8_t num);

#endif