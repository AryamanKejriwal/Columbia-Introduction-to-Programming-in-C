/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3.1

This program sorts 3 numbers and prints them in decreasing order
*/

#include <stdio.h>

void sort(double, double, double);

int main() {
  double a, b, c;

  printf("Enter first number> ");
  scanf("%lf", &a);
  printf("Enter second number> ");
  scanf("%lf", &b);
  printf("Enter third number> ");
  scanf("%lf", &c);

  sort(a, b, c);

  return(0);
}

void sort(double num1, double num2, double num3) {
  /*if(num1 < num2) {
    if(num2 < num3) {
      printf("%lf, %lf, %lf\n", num1, num2, num3);
    } else {
      printf("%lf, %lf, %lf\n", num1, num3, num2);
    }
  } else if(num2 < num3) {
    if(num1 < num2) {
      printf("%lf, %lf, %lf\n", num2, num1, num3);
    } else {
      printf("%lf, %lf, %lf\n", num2, num3, num1);
    }
  } else {
    if(num1 < num2) {
      printf("%lf, %lf, %lf\n", num3, num1, num2);
    } else {
      printf("%lf, %lf, %lf\n", num3, num2, num1);
    }
  }*/

  if(num1 <= num2 && num2 <= num3) {
    printf("%lf, %lf, %lf\n", num3, num2, num1);
  } else if(num2 <= num3 && num3 <= num1) {
    printf("%lf, %lf, %lf\n", num1, num3, num2);
  } else if(num3 <= num1 && num1 <= num2) {
    printf("%lf, %lf, %lf\n", num2, num1, num3);
  } else if(num3 <= num2 && num2 <= num1) {
    printf("%lf, %lf, %lf\n", num1, num2, num3);
  } else if(num1 <= num3 && num3 <= num2) {
    printf("%lf, %lf, %lf\n", num2, num3, num1);
  } else if(num2 <= num1 && num1 <= num3) {
    printf("%lf, %lf, %lf\n", num3, num1, num2);
  }
}
