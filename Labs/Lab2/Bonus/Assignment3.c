/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 3

This program prints letters from a to z
*/

#include <stdio.h>

int main() {
  //Loops through and prints required letters
  for(char i = 'a'; i <= 'z'; i++) {
    printf("%c\n", i);
  }
  return(0);
}
