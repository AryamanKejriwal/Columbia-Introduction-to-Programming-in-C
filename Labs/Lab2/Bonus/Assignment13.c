/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 13

This program swaps the first and last digit of a given number
*/

#include <stdio.h>
#include <math.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("What is the number you want to enter\n");
  scanf("%d", &n);

  int N = n; //N stores a copy of n

  //Computes first and last digits and the number of digits.
  int first_digit = 0;
  int last_digit  = 0;

  int digit_num = 1;

  last_digit = N%10;

  while(N > 9) {
    N = N/10;
    digit_num++;
  }

  first_digit = N;

  N = n;

  //Computes the new n
  N = N - last_digit + first_digit;
  N = N - pow(10, digit_num - 1) * (-last_digit + first_digit);

  //printf("%d  %d\n", first_digit, last_digit);

  printf("%d with its first and last digits swapped is %d\n", n, N);

  return(0);
}
