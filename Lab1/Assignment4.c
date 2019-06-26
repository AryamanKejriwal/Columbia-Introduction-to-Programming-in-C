/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1.4

The user decides what shape to compute the volume of. This program
then computes the volume based on a given input.
*/

#include <stdio.h>

int main() {
  char letter = 'a';
  double volume = 0;

  //Asks the user to input his/her choice
  printf("Do you want to compute the volume of a cube or a sphere?\n");
  printf("C->Cube\tS->Sphere\n");
  scanf("%c", &letter);

  //Computes and prints volume
  if(letter == 'C') {
    //Computes volume of a cube with given side length
    double side = 0;

    printf("What is the side length of the cube?\n");
    scanf("%lf", &side);

    volume = side * side * side;
    printf("The volume of the cube is %f\n", volume);

  } else if(letter == 'S') {
    //Computes volume of a cube with given side length
    double radius = 0;

    printf("What is the radius of the cube?\n");
    scanf("%lf", &radius);

    volume = 4.0/3.0 * 3.14159 *radius * radius * radius;

    printf("The volume of the sphere is %f\n", volume);
  } else {
    printf("That is not a valid shape!\n");
  }
  return(0);
}
