/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5.2

This program takes input numbers from 0 to 9 and shows the calculation of the factorial of the number.
*/

#include <stdio.h>
#include <string.h>

char *fact_calc(int n, char *output);
void print_stars();
int factorial(int n);

int length = 0;

int main() {
  int n = 0;

  //Asks User for input
  printf("Enter n (-1 is sentinel)> ");
  scanf("%d", &n);

  while(n != -1) {

    int skip_display = 0;

    char output[length+50];

    if(n == 0 || n == 1) {
      length = 10;
    } else if(n <= 9 && n > 0) {
      length = 4 * n + 12;
    } else {
      printf("That is not a valid input.\n");
      skip_display = 1;
    }

    if(!skip_display) {
      //Makes sure the number of *s is correct
      if(n == 2 || n == 3) {
        length -= 2;
      } else if(n == 4) {
        length -= 1;
      } else if(n == 7) {
        length += 1;
      } else if(n == 8) {
        length += 2;
      } else if(n == 9) {
        length += 3;
      }

      //Prints required
      print_stars();
      fact_calc(n, output);

      printf("*%s*\n", output);
      print_stars();

      //Resets length so that it is not over-compensated in the next iternation
      if(n == 2 || n == 3) {
        length += 2;
      } else if(n == 4) {
        length += 1;
      } else if(n == 7) {
        length -= 1;
      } else if(n == 8) {
        length -= 2;
      } else if(n == 9) {
        length -= 3;
      }
    }
    //Asks User for input
    printf("Enter n (-1 is sentinel)> ");
    scanf("%d", &n);
  }
  return(0);
}

//Precondition:  Length is correctly initialized, n is between 0 and 9, output has enough space to store the output
//Postcondition: output will contain the calculation for n factorial. The same string will also be returned
char *fact_calc(int n, char output[]) {
  // Concatenates " n! = " to end of output
  sprintf(output, " %d! = ", n);

  if(n == 0 || n == 1) {
    sprintf(output, "%s1 ", output);

    return(output);
  }

  for(int i = n; i > 1; i--) {
    char num[] = {(char)(i+48), ' ', 'x', ' '};
    sprintf(output, "%s%s", output, num);
  }
  int f = factorial(n);
  sprintf(output, "%s1 = %d ", output, f);

  return(output);
}

//Prints length stars
void print_stars() {
  for(int i = 0; i < length; i++) {
    printf("*");
  }

  printf("\n");
}

//Precondition:  n is a non negative integer
//Postcondition: Returns the factorial of n
int factorial(int n) {
  int product = 1;

  for(int i = 1; i <= n; i++) {
    product *= i;
  }

  return(product);
}
