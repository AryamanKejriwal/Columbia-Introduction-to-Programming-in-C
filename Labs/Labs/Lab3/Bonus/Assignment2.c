/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 2

This program prints the diameter, circumference, and area of a circle with a given radius
*/

#include <stdio.h>

#define PI 3.14159

double diameter(double);
double circumference(double);
double area(double);

int main() {
  double r = 0;

  //Gets user input
  printf("Enter the radius of the circle> ");
  scanf("%lf", &r);

  //computes and prints the properties of the circle
  printf("A circle with radius %lf has diameter %ld, circumference %lf, and area %lf\n", r, diameter(r), circumference(r), area(r));

  return(0);
}

//Computes diameter of a circle with radius r
double diameter(double r) {
  return(2 * r);
}

//Computes circumference of a circle with radius r
double circumference(double r) {
  return(2 * PI * r);
}

//Computes area of a circle with radius r
double area(double r) {
  return(r * r * PI)
}
