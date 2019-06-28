/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 11

This program prints the first and last digit of a given number
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

  N = n; //Reset N

  int last = n % 10;
  int first = 0;

  while(N > 9) {
    N = N/10;
  }

  first = N;

  printf("The first digit is %d and the last digit is %d.\n", first, last);

  return(0);
}
