/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief < embedded practise >
 *
 * <this function report analytics on the maximum, minimum, mean, and median of the data set and reorder from large to small.>
 *
 * @author <Mohamed Amer>
 * @date <October 2nd 2020 >
 *
 */


#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)


//starting main func 

int main() {
  //decalaring elements of array
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  //declaring statistics of array
  unsigned char max=0,min=0,med=0,mean=0;

  //printing the old array
	printf("unsorted array:\n");
  print_array(test,SIZE);

  //calculating the statistics of the array
	med = find_median(test,SIZE);
	mean = find_mean(test,SIZE);
	max = find_maximum(test,SIZE);
	min = find_minimum(test,SIZE);

  //printing the statistics of old array
  print_statistics(med,mean,max,min);

  //sorting and printing the new array
  sort_array(test,SIZE);
  print_array(test,SIZE);
}

//defining all helping functions

void print_array(unsigned char *test,int len)
{
	PRINTF("Array elements are : ");
	for (int i = 0; i<len;i++)
	{
	printf(" %d",test[i]); 
	PRINTF("\n");
	}
}

unsigned char find_median(unsigned char *test,int len)
{
	unsigned char med;
	if (len%2==1)
	med = test[len/2];
	else
	med = (test[len/2] + test[len/2-1] )/2;
return med;
}


unsigned char find_mean(unsigned char *test,int len)
{	unsigned char total=0;
	for (int i = 0; i<len; i++)
	{
	  	total+=test[i];
	}
	unsigned char mean=total/len;
return mean;
}


unsigned char find_maximum(unsigned char *test,int len)
{
	unsigned char max=test[0];
	for (int i = 1; i<len; i++)
	{
	  if (test[i]>max)
	     max=test[i];
	}
return max;
}

unsigned char find_minimum(unsigned char *test,int len)
{
	unsigned char min=test[0];
	for (int i = 1; i<len; i++)
	{
	  if (test[i]<min)
	     min=test[i];
	}
return min;
}

void print_statistics(unsigned char med,unsigned char mean,unsigned char max,unsigned char min)
{

	printf ("\nthe array has median = %d, \t mean = %d, \t maximum = %d, \t minimum = %d\n\n",med,mean,max,min);
}


void sort_array(unsigned char *test,int len)
{
    unsigned char temp;
	for (int i = 0; i<len; i++)
	{
	  for (int j =i; j<len; j++)
	    	{
		  if (test [j] > test [i])
		    { temp = test[j];
                               test[j] = test[i];
                               test[i] = temp;}
		}
	}
       printf("after sorting\n\n");

}






