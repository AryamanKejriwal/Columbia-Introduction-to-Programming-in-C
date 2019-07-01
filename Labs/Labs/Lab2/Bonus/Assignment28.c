/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 24

This program outputs the prime factors of a given number
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter the number you want to check> ");
  scanf("%d", &n);

  printf("%d =", n);

  int first = 1;

  //Finds and Prints prime factors and number of each prime factor
  for(int i = 2; i <= n; i++) {
    while(n % i == 0) {
      if(first) {
        printf(" %d", i);
        first = 0;
      } else {
        printf(" * %d", i);
      }

      n = n / i;
    }
  }

  printf("\n");
  return(0);
}
