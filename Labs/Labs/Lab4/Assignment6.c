/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.6

This program determines if there are any duplicate elements in a given array.
*/

#include <stdio.h>

int main() {
  int N = 0;

  //Gets length of array from user
  printf("Enter the length of the array> ");
  scanf("%d", &N);

  int arr[N];

  //Gets each element of the array from user
  for(int i = 0; i < N; i++) {
    printf("Enter the value of the element at index %d> ", i);
    scanf("%d", &arr[i]);
  }

  int found = 0;

  //Checks for duplicates
  for(int i = 0; !found && i < N; i++) {
    for(int j = i+1; !found && j < N; j++) {
      if(arr[i] == arr[j]) {
        found = 1;
      }
    }
  }

  //Prints answer
  if(found) {
    printf("There is at least one duplicate element in the array.\n");
  } else {
    printf("There are no duplicate elements in the array\n");
  }

  return(0);
}
