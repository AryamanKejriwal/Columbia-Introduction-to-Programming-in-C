/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4 Bonus 1

This program prints the number of odd and even digits in a number.
*/

#include <stdio.h>

#define is_even(n) ((n) % 2 == 0) ? 1 : 0

int get_digit(int n, int index);

int main() {
  int n = 0;

  //Asks the user for input
  printf("Enter your number> ");
  scanf("%d", &n);

  int N = n; //Copy of n

  int odd = 0;
  int even = 0;

  for(int i = 0; N != 0; i++) {
    if(is_even(get_digit(n, i))) {
      even++;
    } else {
      odd++;
    }

    N = N / 10;
  }

  if(n % 10 == 0) {
    even++;
  }

  printf("Thre are %d odd digits and %d even digits in %d.\n", odd, even, n);

  return(0);

}

//Precondition:  n is a number and index <= the number of digits in n
//Postcondition: The digit at index is returned
//EG:   INDEX:   3 2 1 0
//      NUMBER:  4 8 9 1
int get_digit(int n, int index) {
  for(int i = 0; i < index; i++) {
    n = n / 10;
  }

  return(n % 10);
}
