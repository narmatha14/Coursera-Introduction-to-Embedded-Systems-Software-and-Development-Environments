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
 * @brief this file contains the actual implementations of eight functions
 * to get the statistics of given array elements and its length
 * 
 *
 * @author Mohamed Baidaq
/ * @date 7/28/2017 
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);
}

void print_statistics(unsigned char arr[], unsigned char arr_length)
{
  printf("Max of test array = %i\n", find_minimum(arr, arr_length)); 
  printf("MIN of test array = %i\n", find_maximum(arr, arr_length));
  printf("Mean of test array = %f\n", find_mean(arr, arr_length));
  printf("Median of test array = %f\n", find_median(arr, arr_length));
}

void print_array(unsigned char arr[], unsigned char arr_length)
{
  unsigned char idx; 
  for(idx = 0; idx < arr_length; idx++)
  {
    printf("%i ", arr[idx]);
  }
}

float find_median(unsigned char arr[], unsigned char arr_length)
{
  sort_array(arr, arr_length);
  if(arr_length % 2 == 0)
    return (float)(((float)arr[arr_length/2] + (float)arr[arr_length/2 - 1])/2.0);
  else
    return (float)arr[arr_length/2];
}

float find_mean(unsigned char arr[], unsigned char arr_length)
{
  unsigned char idx; 
  unsigned int sum = 0; 
  float average = 0.00; 
  for(idx = 0; idx < arr_length; idx++)
  {
    sum += arr[idx];
  }
  average = (float)sum/(float)arr_length; 
  return average; 
}

unsigned char find_maximum(unsigned char arr[], unsigned char arr_length)
{
  unsigned char idx; 
  unsigned char maximum = arr[0]; 
  for(idx = 0; idx < arr_length; idx++)
  {
    if(arr[idx] > maximum)
       maximum = arr[idx]; 
  }
  return maximum; 
}

unsigned char find_minimum(unsigned char arr[], unsigned char arr_length)
{
  unsigned char idx; 
  unsigned char minimum = arr[0]; 
  for(idx = 0; idx < arr_length; idx++)
  {
    if(arr[idx] < minimum)
       minimum = arr[idx]; 
  }
  return minimum;
}

void sort_array(unsigned char arr[], unsigned char arr_length)
{
  unsigned char outter_idx;
  unsigned char inner_idx;
  unsigned char temp;
  for(outter_idx = 0; outter_idx < arr_length - 1; outter_idx++)
  {
    for(inner_idx = outter_idx; inner_idx < arr_length - 1; inner_idx++)
      {
        if(arr[inner_idx] < arr[inner_idx + 1])
        {
          temp = arr[inner_idx + 1];
          arr[inner_idx + 1] = arr[inner_idx];
          arr[inner_idx] = temp;
        } 
      } 
  }
}

