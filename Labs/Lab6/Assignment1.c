/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 6.1

This program outputs an array in reverse
*/

#include <stdio.h>

void reverseDisplay(int value[], int size);

int main() {
  int size = 0;
  //Gets input from user
  printf("Enter the size of your array> ");
  scanf("%d", &size);
  int arr[size];

  for(int i = 0; i < size; i++) {
    printf("Enter number at index %d> ", i);
    scanf("%d", &arr[i]);
  }

  printf("The array of numbers in reverse order is:\n");
  reverseDisplay(arr, size);
  printf("\n");
  return(0);
}

//Prints the array in reverse order
void reverseDisplay(int value[], int size) {
  if(size == 1) {
    printf("%d ", value[size - 1]);
  } else {
    printf("%d ", value[size - 1]);
    reverseDisplay(value, size - 1);
  }
}
