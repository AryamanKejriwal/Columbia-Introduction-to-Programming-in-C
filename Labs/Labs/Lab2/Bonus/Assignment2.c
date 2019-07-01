/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 2

This program prints all natural numbers from a given number (Inclusive) to a 1 (in reverse)
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter your Number>");
  scanf("%d", &n);

  //Loops through and prints required numbers
  for(int i = n; i >= 1; i--) {
    printf("%d\n", i);
  }
  return(0);
}
