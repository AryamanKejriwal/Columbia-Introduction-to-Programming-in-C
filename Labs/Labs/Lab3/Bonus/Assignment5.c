/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 5

This program prints whether a given number is armstrong, perfect, and/or prime
*/

#include <stdio.h>

int isPrime(int);
int isArmstrong(int);
int isPerfect(int);

int main() {
  int n = 0;

  printf("Enter the number> ");
  scanf("%d", &n);

  //Checks whether input is valid
  if(n < 0) {
    printf("Thais is not a valid input\n");
  } else {
    int prime_flag = isPrime(n);
    int armstrong_flag = isArmstrong(n);
    int perfect_flag = isPerfect(n);
  }

  return(0);
}

//Precondition: n is a natural number
//Postcondition: returns 0 if n is not a prime and 1 if n is prime
int isPrime(int n) {
  for(int i = 2; i < n; i++) {
    if(n % i == 0) {
      return(0);
    }
  }

  //Makes sure that the number is not 1
  if(n != 1) {
    return(1);
  } else {
    return(0);
  }
}

//Precondition: n is a natural number
//Postcondition: returns 0 if n is not an armstrong number and 1 if n is an armstrong number
int isArmstrong(int n) {
  int sum_of_cubes = 0;
  int N = n; //Copy of n

  while(N != 0) {
    int digit = N % 10;
    sum_of_cubes += digit * digit * digit;
    N = N / 10;
  }

  return(n == sum_of_cubes);
}

//Precondition: n is a natural number
//Postcondition: returns 0 if n is not a perfect number and 1 if n is a perfect number
int isPerfect(int n) {
  int sum = 0;

  for(int i = 1; i < n; i++) {
    if(n % i == 0) {
      sum += i
    }
  }

  return(sum == n)
}
