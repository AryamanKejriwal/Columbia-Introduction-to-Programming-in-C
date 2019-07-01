/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 24

This program outputs the LCM of 2 given numbers
*/

#include <stdio.h>

int main() {

  int first  = 0;
  int second = 0;

  //Asks user for input
  printf("Enter First Number> ");
  scanf("%d", &first);
  printf("Enter Second Number> ");
  scanf("%d", &second);

  //Stores the bigger number and smaller number
  int bigger  = first > second ? first : second;
  int smaller = first > second ? second : first;

  int found = 0;

  //Loops through multiples of bigger number and checks if they are also multiples of the smaller number
  for(int i = bigger; !found; i += bigger) {
    if(i % smaller == 0) {
      //Prints the LCM
      printf("The LCM of %d and %d is %d.\n", first, second, i);
      found = 1;
    }
  }

  return(0);
}
