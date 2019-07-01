/*
Author: Aryaman Kejriwal & Jacob Baer
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.1

This program prints the lower of 2 numbers
*/

#include <stdio.h>

void min(int *x, int *y);

int main() {
  int first  = 0;
  int second = 0;

  //Ask user for input
  printf("Enter the first number> ");
  scanf("%d", &first);
  printf("Enter the second number> ");
  scanf("%d", &second);

  min(&first, &second);

  printf("%d is less than %d.\n", first, second);

  return(0);
}

//Precondition: The arguments are pointers to integer values
//Postcondition: The first argument < the second arguments
void min(int *x, int *y) {
  if(*x > *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }
}
