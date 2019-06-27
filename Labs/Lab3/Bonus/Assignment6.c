/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 6

This program prints all prime numbers in a given interval (Including the boundary numbers)
*/

#include <stdio.h>

#define min(a, b) (a) < (b)? (a) : (b)
#define max(a, b) (a) > (b)? (a) : (b)

void printPrimes(int, int);
int isPrime(int);

int main() {

  int a = 0;
  int b = 0;

  //Gets range from user
  printf("What is the beginning of your range?\n");
  scanf("%d", &a);
  printf("What is the end of your range?\n");
  scanf("%d", &b);

  //makes sure upper >= lower
  int lower = min(a, b);
  int upper = max(a, b);

  //Makes sure that the input is valid
  if(upper <= 0 || lower <= 0) {
    printf("Those are invalid boundaries.\n");
  } else {
    printPrimes(lower, upper);
  }

  return(0);
}

//Precondition: upper_bound > 0 && lower_bound > 0 && lower_bound <= upper_bound
//Postcondition: Prints all prime numbers that lie between lower_boundary and upper_boundary (inclusive)
void printPrimes(int lower_bound, int upper_bound) {

  printf("The prime numbers between %d and %d are:\n", lower_bound, upper_bound);

  for(int i = lower_bound; i <= upper_bound; i++) {
    if(isPrime(i)) {
      printf("%d\n", i);
    }
  }
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
