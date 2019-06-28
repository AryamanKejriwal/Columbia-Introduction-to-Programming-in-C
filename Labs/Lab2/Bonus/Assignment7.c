/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 7

This program prints the sum all even numbers from 1 to a given number (Inclusive)
*/

#include <stdio.h>

int main() {
  int n = 0;
  int sum = 0;

  //Asks user for input data
  printf("Enter yor number> ");
  scanf("%d", &n);

  //Loops through and adds required numbers
  for(int i = 2; i <= n; i += 2) {
    sum += i;
  }

  printf("The sum of all even numbers from 1 to %d is %d.\n", n, sum);

  return(0);
}
