/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 5

This program prints all odd numbers from 1 to 100 (Inclusive)
*/

#include <stdio.h>

int main() {
  //Loops through and prints required numbers
  for(int i = 1; i <= 100; i += 2) {
    printf("%d\n", i);
  }
  return(0);
}
