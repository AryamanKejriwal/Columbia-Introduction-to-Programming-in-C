/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 4

This program prints whether a given number is odd or even
*/

#include <stdio.h>

int isOdd(int);

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter the number> ");
  scanf("%d", &n);

  //makes sure that input is not negative
  if(n < 0) {
    printf("That is not a valid input");
  } else {
    //prints whether n is odd or even
    if(isOdd(n)) {
      printf("%d is odd.\n", n);
    } else {
      printf("%d is even.\n", n);
    }
  }

  return(0);
}

//Precondition: n >= 0
//Postcondition: returns 1 if n is odd and 0 if n is even
int isOdd(int n) {
  return(n % 2);
}
