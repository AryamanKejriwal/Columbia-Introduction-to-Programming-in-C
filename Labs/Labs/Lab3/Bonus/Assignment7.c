/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 7

This program prints all strong numbers in a given interval (Including the boundary numbers)
*/

#include <stdio.h>

#define min(a, b) (a) < (b)? (a) : (b)
#define max(a, b) (a) > (b)? (a) : (b)

void printStrongs(int, int);
int isStrong(int);

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
//Postcondition: Prints all strong numbers that lie between lower_boundary and upper_boundary (inclusive)
void printStrongs(int lower_bound, int upper_bound) {

  printf("The strong numbers between %d and %d are:\n", lower_bound, upper_bound);

  for(int i = lower_bound; i <= upper_bound; i++) {
    if(isStrong(i)) {
      printf("%d\n", i);
    }
  }
}

//Precondition: n is a natural number
//Postcondition: returns 0 if n is not a strong number and 1 if n is a strong number
int isStrong(int n) {
  int N = n; //Copy of n
  sum = 0;

  while(N != 0) {
    int digit = N % 10;
    product = 1;
    for(int i = 1; i <= digit; i++) {
      product *= i;
    }

    sum += product;

    N = N / 10;
  }

  return(sum == n);
}
