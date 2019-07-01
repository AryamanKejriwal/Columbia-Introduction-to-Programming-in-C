/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3.3

This program replacess all instances of a given digit with another digit of a
given number.
*/

#include <stdio.h>
#include <math.h>

int replaceDig(int, int, int);
int getDigit(int, int);
int numDigits(int);
int replace(int, int, int);

int main() {
  int n = 0;
  int old = 0;
  int new = 0;

//Gets input from user
  printf("What is your number?\n");
  scanf("%d", &n);
  printf("What is the digit to be replaced?\n");
  scanf("%d", &old);
  printf("What is the new digit?\n");
  scanf("%d", &new);

  n = replaceDig(n, old, new);

  printf("The new number is %d\n", n);

  return(0);
}

// Precondition: num > 0
// Postcondition: returns num with all instances of oldDigit replaces with
// newDigit.
int replaceDig(int num, int oldDigit, int newDigit) {
  int digit_num = numDigits(num);

  //Finds and replaces old digit with new digits
  for(int i = 1; i <= digit_num; i++) {
    int digit = getDigit(num, i);
    if(digit == oldDigit) {
      num = replace(num, i, newDigit);
    }
  }
  return(num);
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

//Replaces digit at a specific index with another digit
int replace(int n, int index, int newDigit) {
  int power = pow(10, index - 1);

  int beg = n % power;
  int end = n / (power * 10);

  n = beg + (newDigit * power) + (end * power * 10);

  return(n);
}
