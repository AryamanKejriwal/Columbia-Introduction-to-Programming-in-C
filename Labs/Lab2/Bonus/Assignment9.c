/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 9

This program prints the multiplication table of a given number from 0 to 12
*/

#include <stdio.h>

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter the number you want the multiplication table of> ");
  scanf("%d", &n);

  printf("Multiplication Table of %d\n", n);

  //Loops through and prints multiplication table of the given number
  for(int i = 0; i <= 12; i++) {
    printf("%d x %d = %d\n", n, i, (n*i));
  }

  return(0);
}
