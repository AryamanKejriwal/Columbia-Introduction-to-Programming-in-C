/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 1

This program prints the cube of a given number
*/

#include <stdio.h>

double cube(double);

int main() {
  double n = 0;

  //Gets user input
  printf("What number do you want to find the cube of?\n");
  scanf("%lf", &n);

  //prints the cube
  printf("The cube of %lf is %lf\n", n, cube(n));
  return(0);
}

//computes and returns the cube of n
double cube(double n) {
  return(n * n * n);
}
