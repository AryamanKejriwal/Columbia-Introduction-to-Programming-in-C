/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1.1

This program asks the user for 3 numbers and outputs whether
the third number is in between the first and second.
*/

#include <stdio.h>

int main() {
  double first  = 0;
  double second = 0;
  double third  = 0;

  //Asking for an input
  printf("What is your first number?\n");
  scanf("%lf", &first);

  printf("What is your second number?\n");
  scanf("%lf", &second);

  printf("What is your third number?\n");
  scanf("%lf", &third);

  //Checks the numbers and prints the output.
  if(first < third && third < second) {
    printf("%f is between %f and %f\n", third, first, second);
  } else {
    printf("%f is not between %f and %f\n", third, first, second);
  }

  return(0);

}
