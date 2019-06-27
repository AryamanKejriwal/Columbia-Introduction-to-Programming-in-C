/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3.2

This program iteratively adds up the digits of a number and then the digits of the answer
until the result is a single digit number.
*/

#include <stdio.h>

int sumDigits(int);
int getDigit(int, int);
int numDigits(int);

int main() {

  int n = 0;

  //Ask user for input
  printf("Enter the number> ");
  scanf("%d", &n);

  //Checks if input is valid
  if(n <= 0) {
    printf("That is not a valid input.\n");
  } else {
    while(n > 9) {
      n = sumDigits(n);
    }
  }

  printf("The answer is %d.\n", n);

  return(0);
}

/* Precondition: num > 0 */
/* Postcondition: the return value is the iterated sum of
   digits of num */
int sumDigits(int num) {
  int digit_num = numDigits(num);
  int temp_sum = 0;

  for(int i = 1; i <= digit_num; i++) {
    int digit = getDigit(num, i);
    temp_sum += digit;
  }

  return(temp_sum);
}

/* Return the index’th digit of num: */
int getDigit(int num, int index) {
  for(int i = 1; i < index; i++) {
    num = num / 10;
  }

  return(num % 10);
}

/* Return the number of digits in num: */
int numDigits(int num) {
  int count = 0;

  while(num != 0) {
    num = num / 10;
    count++;
  }

  return(count);
}
