/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 6.3

This program outputs the number of occurances of a specific integer in an array
*/

#include <stdio.h>

#define SIZE 9

int count(int ints[], int num, int size);

int main() {
  int arr[] = {3, 2, 3, 4, 5, 2, 3, 3, 3};
  int num = 2;
  printf("The number of %ds in the array is %d.\n", num, count(arr, num, SIZE));
  return(0);
}

int count(int ints[], int num, int size) {
  if(size <= 0) {
    return(0);
  } else {
    if(ints[size - 1] == num) {
      return(count(ints, num, size - 1) + 1);
    } else {
      return(count(ints, num, size - 1));
    }
  }
}
