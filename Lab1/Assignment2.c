/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1.2

Tells the user whether an inputted letter is lowercase or uppercase
*/

#include <stdio.h>

int main() {
  char letter = 'a';

  //Asks the user for a letter
  printf("Please enter your letter >");
  scanf("%c", &letter);

  //Checks if the input is Uppercase, Lowercase or not a letter.
  if(letter >='A' && letter <= 'Z') {
    printf("\n%c is Uppercase.\n", letter);
  } else if(letter >='a' && letter <= 'z') {
    printf("\n%c is Lowercase.\n", letter);
  } else {
    printf("\n%c is not a letter!\n", letter);
  }

  return(0);
}
