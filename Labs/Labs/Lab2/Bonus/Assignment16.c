/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 16

This program prints the reverse of a given number
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter your number> ");
  scanf("%d", &n);

  int N = n; //Copy of n

  printf("The reverse of %d is ", n);

  while(N != 0) {
    printf("%d", (N%10));
    N = N / 10;
  }

  printf(".\n");
  
  return(0);
}
