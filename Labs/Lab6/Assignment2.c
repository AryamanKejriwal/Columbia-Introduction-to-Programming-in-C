/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 6.2

This program outputs the smallest number in an array of integers
*/

#include <stdio.h>

#define min(a, b) (a) < (b) ? (a) : (b)

int smallest(int arr[], int last_index);

int main() {
  int size = 8;
  int arr[size];

  //Prompts user for input
  for(int i = 0; i < size; i++) {
    printf("Enter the value at index %d> ", i);
    scanf("%d", &arr[i]);
  }

  int s = smallest(arr, size - 1);
  printf("The smallest value in the array is %d.\n", s);
  return(0);
}

int smallest(int arr[], int last_index) {
  if(last_index == 0) {
    return(arr[0]);
  } else {
    return(min(arr[last_index], smallest(arr, last_index - 1)));
  }
}
