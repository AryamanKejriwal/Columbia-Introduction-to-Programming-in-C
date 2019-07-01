/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1 Bonus 14

Recieves a quadratic equation and determines the roots.
*/

#include <stdio.h>
#include <math.h>

int main() {
  double a = 0;
  double b = 0;
  double c = 0;

  //Prompts user for coefficients
  printf("What is a?\n");
  scanf("%lf", &a);
  printf("What is b?\n");
  scanf("%lf", &b);
  printf("What is c?\n");
  scanf("%lf", &c);

  printf("\n");

  double D = (b * b) - (4 * a * c);

  //if D is negative, there are only complex roots and C would throw an error
  if(D < 0) {
    printf("This equation has no real roots.\n");
  } else {
    double root1 = (-b + sqrt(D))/(2 * a);
    double root2 = (-b - sqrt(D))/(2 * a);

    printf("The roots of the equation are %lf and %lf\n", root1, root2);
  }

  return(0);
}
