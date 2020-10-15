#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    uint8_t size=0;
    if(data < 0)
    {
        data=0-data;
        *ptr++='-';
    }
    while( (data/base) || (data%base) )
    {
        ptr[size++]=data%base+0x30;
        data/=base;
    }
    ptr[size]=0;
    my_reverse(ptr,size);
    return size;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t num=0;
    uint8_t is_negative=0;
    if(*ptr=='-')
     {
	is_negative=1;
	ptr++;
     }
    for(int i = 0; i<digits ;i++)
    {
        num=num*base + (*(ptr+i)  - 0x30 );
    }



    return ( is_negative ? (0-num) : num  );
}
