/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 10

This program prints the number of digits in a given number
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter the Number> ");
  scanf("%d", &n);

  int N = n; //Copy of n

  int count = 0;

  if(n == 0) {
    count = 1;
  } else {
    while(N != 0) {
      count++;
      N = N/10;
    }
  }

  printf("There are %d digits in %d.\n", count, n);

  return(0);
}
