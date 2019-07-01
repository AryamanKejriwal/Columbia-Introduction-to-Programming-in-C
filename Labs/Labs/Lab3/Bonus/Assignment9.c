/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 3 Bonus 9

This program prints all perfect numbers in a given interval (Including the boundary numbers)
*/

#include <stdio.h>

#define min(a, b) (a) < (b)? (a) : (b)
#define max(a, b) (a) > (b)? (a) : (b)

void printPerfects(int, int);
int isPerfect(int);

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
//Postcondition: Prints all perfect numbers that lie between lower_boundary and upper_boundary (inclusive)
void printPerfects(int lower_bound, int upper_bound) {

  printf("The perfect numbers between %d and %d are:\n", lower_bound, upper_bound);

  for(int i = lower_bound; i <= upper_bound; i++) {
    if(isPerfect(i)) {
      printf("%d\n", i);
    }
  }
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
