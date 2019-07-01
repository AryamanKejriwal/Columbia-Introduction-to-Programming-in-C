/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 15

This program prints the product of the digits of a given number
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter your number> ");
  scanf("%d", &n);

  int N = n; //Copy of n

  int product = 1;

  while(N != 0) {
    int digit = N % 10;
    product *= digit;
    N = N / 10;
  }

  if(n % 10 == 0 && n > 9) {
    product = 0;
  }

  printf("The product of the digits in %d is %d.\n", n, product);

  return(0);
}
