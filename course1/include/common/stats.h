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
 * @file <stats.h> 
 * @brief <embedded software functions declaration >
 *
 * <this file includes all prototypes of functions needed in stat.c to calculate the statistics for a certain array>
 *
 * @author <Mohamed Amer>
 * @date <October 2nd 2020 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void print_statistics(unsigned char med,unsigned char mean,unsigned char max,unsigned char min);

/**
 * @brief <calculates stats of an array>
 *
 * <calculates median, mean, maximum and minimum of the array and printing them>
 *
 * @param <med> <calculates median of the array>
 * @param <mean> <calculates mean of the array>
 * @param <max> <calculates maximum of the array>
 * @param <min> <calculates minimum of the array>
 *
 * @return <printing all four stats which were calculated>
 */

void print_array(unsigned char *test,int len);

/**
 * @brief <printing an array>
 *
 * <nice printing of elements of an array each every line>
 *
 * @param <*test> <the array>
 * @param <len> <lenght of array elements>
 *
 * @return <printing all elements of the array>
 */
unsigned char find_median(unsigned char *test,int len);

/**
 * @brief <calc median of an array>
 *
 *
 * @param <*test> <the array>
 * @param <len> <lenght of array elements>
 *
 * @return <value of median of the array>
 */

unsigned char find_mean(unsigned char *test,int len);

/**
 * @brief <calc mean of an array>
 *
 *
 * @param <*test> <the array>
 * @param <len> <lenght of array elements>
 *
 * @return <value of mean of the array>
 */

unsigned char find_maximum(unsigned char *test,int len);

/**
 * @brief <calc maximum of an array>
 *
 *
 * @param <*test> <the array>
 * @param <len> <lenght of array elements>
 *
 * @return <value of maximum of the array>
 */

unsigned char find_minimum(unsigned char *test,int len);

/**
 * @brief <calc minimum of an array>
 *
 *
 * @param <*test> <the array>
 * @param <len> <lenght of array elements>
 *
 * @return <value of minimum of the array>
 */

void swap(int* xp, int* yp);

/**
 * @brief <swapping between any two elements of an array>
 *
 *
 * @param <*xp> <first element>
 * @param <*yp> <second element>
 *
 * @return <exchange of values between two elements>
 */

void sort_array(unsigned char *test,int len);

/**
 * @brief <sorting and printing of an array>
 *
 *
 * @param <*test> <the array>
 * @param <len> <lenght of array elements>
 *
 * @return <printing of sorted array>
 */

#endif /* __STATS_H__ */
