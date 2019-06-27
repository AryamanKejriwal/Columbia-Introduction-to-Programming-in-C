/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 8

This program prints all armstrong numbers in a given interval (Including the boundary numbers)
*/

#include <stdio.h>

#define min(a, b) (a) < (b)? (a) : (b)
#define max(a, b) (a) > (b)? (a) : (b)

void printArmstrongs(int, int);
int isArmstrong(int);

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
    printArmstrongs(lower, upper);
  }

  return(0);
}

//Precondition: upper_bound > 0 && lower_bound > 0 && lower_bound <= upper_bound
//Postcondition: Prints all armstrong numbers that lie between lower_boundary and upper_boundary (inclusive)
void printArmstrongs(int lower_bound, int upper_bound) {

  printf("The armstrong numbers between %d and %d are:\n", lower_bound, upper_bound);

  for(int i = lower_bound; i <= upper_bound; i++) {
    if(isArmstrong(i)) {
      printf("%d\n", i);
    }
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
