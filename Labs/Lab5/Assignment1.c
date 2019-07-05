/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5.1

This program tests the function deblank, that takes a string and returns the same string without all blanks
*/

#include <stdio.h>

char *deblank(char *input, char *output);

int main() {
  char in[] = "Hello This is a test.";
  char out[50];

  char *str = deblank(in, out);

  printf("%s\n%s\n", out, str);

  return(0);
}

//Precondition:  input and output are strings. output must have enough space to store the input string.
//Postcondition: output will be overwritten with the value of input except without spaces
char *deblank(char *input, char *output) {
  int i = 0;
  int discrepency = 0;
  for(i = 0; input[i] != '\0'; i++) {
    if(input[i] != ' ') {
      output[i - discrepency] = input[i];
    } else {
      discrepency++;
    }
  }

  output[i - discrepency] = '\0';

  return(output);
}
