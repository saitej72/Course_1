#include "memory.h"

/**************Function Definitions******************/

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	if( dst > src )                     //if overlapped is from the start
    {
        for(int i=length-1; i >= 0 ; i--)
        {
            *(dst+i)=*(src+i);
        }
    }
    else                                //if overlapped from end or non-overlapped
    {
        for(int i=0;i<length;i++)
        {
            *(dst+i)=*(src+i);
        }
    }
    return dst;
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
    for(int i=0; i <length ; i++)
        {
                *(dst+i)=*(src+i);
        }
    return dst;
}


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	for (int i=0; i<length; i++)
	{
		*(src+i)=value;
	}
    return src;
}


uint8_t * my_memzero(uint8_t * src, uint32_t length)
{
   for(int i=0;i<length;i++)
    {
        *(src+i)=0;
    }
return src;
}

uint8_t * my_reverse(uint8_t * src, uint32_t length){

    int mid=(length+1)/2;
    uint8_t temp;
    for(int i=0; i<mid ;i++)
    {
        temp=*(src+i);
        *(src+i)=*(src+length-1-i);
        *(src+length-1-i)=temp;
    }
    return src;
}


int32_t * reserve_words(uint32_t length)
{
    int32_t *ptr=(int32_t *)malloc(length * sizeof(int32_t));
    return ptr;
}


void free_words(uint32_t * src)
{
    free((void*)src);
}

