#include <flash.h>

void flash_write(uint32_t addr,uint8_t data[],uint16_t num)
{
    uint32_t Address = 0;
    unsigned char *data_para;
    
    if(num % 2 == 1)
    {
        num++;
    }
    data_para = data;
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
    FLASH_ErasePage(addr);

    Address = addr;

    for(uint8_t k=0;k<(num/2);k++)
    {
        FLASH_ProgramHalfWord(Address,*((uint16_t*)data_para));
        Address += 2;
        data_para += 2;
    }
    FLASH_Lock();
    /************************/
}

void flash_read(uint32_t addr,uint8_t data[],uint16_t point,uint16_t num)
{
    uint32_t Address = 0;
    
    Address = addr + point;
    
    for(uint16_t j=0;j<num;j++)
    {
        data[j] = (*(__IO uint32_t*) Address);
        Address++;
    }
}