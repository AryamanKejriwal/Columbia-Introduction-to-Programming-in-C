/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 1

This program prints all natural numbers from 1 to a given number (Inclusive)
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter your Number>");
  scanf("%d", &n);

  //Loops through and prints required numbers
  for(int i = 1; i <= n; i++) {
    printf("%d\n", i);
  }
  return(0);
}
