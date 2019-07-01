/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 6

This program prints the sum of all natural numbers from 1 to a given number (Inclusive)
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter your Number>");
  scanf("%d", &n);

  int sum = 0;

  //Loops through and adds required numbers
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
  printf("The sum of all natural numbers from 1 to %d is %d.\n", n, sum);
  return(0);
}
