/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 3

This program finds the maximum and minimum between 2 given numbers
*/

#include <stdio.h>

double max(double, double);
double min(double, double);

int main() {
  double a = 0;
  double b = 0;

  //Asks the user for input
  printf("Enter first number> ");
  scanf("%lf", &a);
  printf("Enter second number> ");
  scanf("%lf", &b);

  //prints the maximum and minimum
  printf("The maximum is %lf and the minimum is %lf", max(a, b), min(a, b));

  return(0);
}

//Returns maximum between a and b
double max(double a, double b) {
  return(a > b? a : b);
}

//Returns minimum between a and b
double min(double a, double b) {
  return(a < b? a : b);
}
