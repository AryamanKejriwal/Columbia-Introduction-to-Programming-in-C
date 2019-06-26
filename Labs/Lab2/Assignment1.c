/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2.1

This program computes n choose k for a given n and k
*/

#include <stdio.h>

int main() {
  int n = 0;
  int k = 0;

  //Asks the user for values of n and k
  printf("What is the value of n?\n");
  scanf("%d", &n);
  printf("What is the value of k?\n");
  scanf("%d", &k);

  printf("\n");

//computes the difference between n and k
  int diff = n - k;

  //computes all required factorials
  int n_factorial = 1;
  for(int i = 2; i <= n; i++) {
    n_factorial *= i;
  }

  int k_factorial = 1;
  for(int i = 2; i <= k; i++) {
    k_factorial *= i;
  }

  int diff_factorial = 1;
  for(int i = 2; i <= diff; i++) {
    diff_factorial *= i;
  }

  //Computes and prints the final answer
  int answer = n_factorial / (k_factorial*diff_factorial);
  printf("%d choose %d is %d\n", n, k, answer);

  return(0);
}
