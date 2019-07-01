/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.2

This program prints the last element of the array
*/

#include <stdio.h>

int main() {
  int arr[10];
  int *aptr = arr+3;

  printf("The last element of the array is %d", *(aptr + 6));

  return(0);
}
