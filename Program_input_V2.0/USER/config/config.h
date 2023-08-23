#ifndef __CONFIG_H_
#define __CONFIG_H_

#include "stm32f10x.h"

#define WATCH_DOG               1       //看门狗
#define CONFIG_DATA_ADDR        ((uint32_t)0x08008000)//配置数据储存

#define         CONFIG_FILE             1       //配置文件夹
#define         MUSIC_FILE              2       //音乐文件夹

//配置文件夹中的音乐
#define         ENTER_INTO_CONFIG_MUSIC                 1       //进入配置模式音乐    
#define         ORDER_TRIGGER_MUSIC                     2       //顺序触发模式音乐  
#define         SAME_TRIGGER_MUSIC                      3       //同时触发模式音乐  
#define         ENTER_INTO_ORDER_TRIGGER_MUSIC          4       //进入顺序触发模式音乐  
#define         ENTER_INTO_SAME_TRIGGER_MUSIC           5       //进入同时触发模式音乐  
#define         CHOOSE_PORT_NUM_MUSIC                   6       //选择输入端口音乐
#define         PORT_NUM_ONE_MUSIC                      7       //一个端口音乐  
#define         PORT_NUM_TWO_MUSIC                      8       //两个端口音乐  
#define         PORT_NUM_THREE_MUSIC                    9       //三个端口音乐  
#define         PORT_NUM_FOUR_MUSIC                     10      //四个端口音乐  
#define         PORT_NUM_FIVE_MUSIC                     11      //五个端口音乐  
#define         PORT_NUM_SIX_MUSIC                      12      //六个端口音乐  
#define         PORT_NUM_SEVEN_MUSIC                    13      //七个端口音乐  
#define         PORT_NUM_EIGHT_MUSIC                    14      //八个端口音乐
#define         TRIGGER_PORT_IN_ORDER_MUSIC             15      //按照顺序触发输入端口音乐
#define         TRIGGER_ALL_PORT_MUSIC                  16      //将所有端口依次触发音乐
#define         FINISH_INPUT_MUSIC                      17      //输入完成音乐
#define         CHOOSE_RELAY_JUMP_MUSIC                 18      //选择机关触发后继电器是否跳变音乐
#define         RELAY_JUMP_MUSIC                        19      //触发后继电器跳变音乐
#define         RELAY_NO_JUMP_MUSIC                     20      //触发后继电器不跳变音乐
#define         CHOOSE_MUSIC                            21      //选择机关触发后播放音乐
#define         CONFIG_MUSIC_ONE                        22      //音乐一
#define         CONFIG_MUSIC_TWO                        23      //音乐二
#define         CONFIG_MUSIC_THREE                      24      //音乐三
#define         CONFIG_MUSIC_FOUR                       25      //音乐四
#define         CONFIG_MUSIC_FIVE                       26      //音乐五
#define         CONFIG_MUSIC_SIX                        27      //音乐六
#define         CONFIG_MUSIC_SEVEN                      28      //音乐七
#define         CONFIG_MUSIC_EIGHT                      29      //音乐八
#define         CONFIG_MUSIC_NONE                       30      //不播放音乐
#define         CHOOSE_RELAY_WHEN_TRIGGER_MUSIC         31      //选择继电器何时触发音乐
#define         RELAY_MUSIC_TRIGGER_SAME_MUSIC          32      //继电器和音乐同时触发音乐
#define         RELAY_TRIGGER_AFTER_MUSIC               33      //继电器在音乐播放完毕后触发
#define         CONFIG_OK_MUSIC                         34      //配置完成音乐
#define         WEICOME_MUSIC                           35      //欢迎音乐      
#define         PORT_ONE_MUSIC                          36      //端口一音效
#define         PORT_TWO_MUSIC                          37      //端口二音效
#define         PORT_THREE_MUSIC                        38      //端口三音效
#define         PORT_FOUR_MUSIC                         39      //端口四音效
#define         PORT_FIVE_MUSIC                         40      //端口五音效
#define         PORT_SIX_MUSIC                          41      //端口六音效
#define         PORT_SEVEN_MUSIC                        42      //端口七音效
#define         PORT_EIGHT_MUSIC                        43      //端口八音效
#define         EMPTY_MUSIC                             44      //空音乐
#define         CHOOSE_PORT_LIGHT_PATTERN_MUSIC         45      //选择端口灯模式音乐
#define         PORT_LIGHT_ALWAYS_BRIGHT_MUSIC          46      //端口灯常亮音乐
#define         PORT_LIGHT_BRIGHT_AFTER_TRIGGER_MUSIC   47      //端口灯在端口触发时亮音乐
#define         PRODUCT_KEY_DOWNLOAD_OK_MUSIC           48      //产品序列号下载成功音乐
#define         PRODUCT_KEY_READ_OK_MUSIC               49      //产品序列号读取成功音乐
#define         PORT_NUM_SET_TO_ONE                     50      //端口数量成功设置为一个
#define         PORT_NUM_SET_TO_TWO                     51      //端口数量成功设置为两个
#define         PORT_NUM_SET_TO_THREE                   52      //端口数量成功设置为三个
#define         PORT_NUM_SET_TO_FOUR                    53      //端口数量成功设置为四个
#define         PORT_NUM_SET_TO_FIVE                    54      //端口数量成功设置为五个
#define         PORT_NUM_SET_TO_SIX                     55      //端口数量成功设置为六个
#define         PORT_NUM_SET_TO_SEVEN                   56      //端口数量成功设置为七个
#define         PORT_NUM_SET_TO_EIGHT                   57      //端口数量成功设置为八个
#define         PORT_NUM_SET_FAIL                       58      //端口数量设置失败
//音乐文件夹中的音乐
#define         MUSIC_ONE                               1       //音乐一
#define         MUSIC_TWO                               2       //音乐二
#define         MUSIC_THREE                             3       //音乐三
#define         MUSIC_FOUR                              4       //音乐四
#define         MUSIC_FIVE                              5       //音乐五
#define         MUSIC_SIX                               6       //音乐六
#define         MUSIC_SEVEN                             7       //音乐七
#define         MUSIC_EIGHT                             8       //音乐八

extern void config_menu(void);
extern void key_scan(void);//按键扫描
extern void IWDG_Feed(void);//喂狗

extern uint8_t port_num_config(uint8_t key_word[],uint8_t array[]);

extern uint8_t first_password;//顺序触发模式下的第一位密码
extern uint8_t light_show_config;//端口灯显示的状态  1：端口灯常亮  2：端口灯在端口触发时亮

extern uint8_t music_play_flag;//音乐是否播放的标志位

extern uint8_t port_num;//端口数量

#endif