/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1.3

Tells the user the education level based on years educated.
*/

#include <stdio.h>

int main() {
  int years = 0;

  //Asks the user to input years of schooling
  printf("How many years have you been schooled for?\n");
  scanf("%d", &years);

  //Prints the education level
  if(years == 0) {
    printf("None\n");
  }else if(years < 0) {
    printf("That\'s not a valid number of years!\n");
  } else if(years <= 5) {
    printf("Elementary School\n");
  } else if(years <= 8) {
    printf("Middle School\n");
  } else if(years <= 12) {
    printf("High School\n");
  } else {
    printf("College\n");
  }

  return(0);
}
