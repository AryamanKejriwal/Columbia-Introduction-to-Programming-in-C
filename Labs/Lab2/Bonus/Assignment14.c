/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 14

This program prints the sum of the digits of a given number
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter your number> ");
  scanf("%d", &n);

  int N = n; //Copy of n

  int sum = 0;

  while(N != 0) {
    int digit = N % 10;
    sum += digit;
    N = N / 10;
  }

  printf("The sum of the digits in %d is %d.\n", n, sum);

  return(0);
}
