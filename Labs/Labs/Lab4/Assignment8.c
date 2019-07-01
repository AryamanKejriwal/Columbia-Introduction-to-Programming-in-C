/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.8

This program prints the values of a normalized vector given an initial vector as input
*/

#include <stdio.h>
#include <math.h>

void normalizeVector(double vector[], int len);
int sq_sum(double vector[], int len);

int main() {
  int n = 0;
  //Gets number of dimensions of the vector
  printf("Enter the number of dimensions in the vector> ");
  scanf("%d", &n);

  double vector[n];

  //Gets user input for the vector
  for(int i = 0; i < n; i++) {
    printf("Enter the value of the vector in the dimension %d> ", (i+1));
    scanf("%lf", &vector[i]);
  }

  //Normalizes vector
  normalizeVector(vector, n);

  //prints the normalised vector
  printf("The new vector is:\n[");
  for(int i = 0; i < n; i++) {
    if(i != n-1) {
      printf("%lf, ", vector[i]);
    } else {
      printf("%lf]\n", vector[i]);
    }
  }
  return(0);
}

//Precondition:  vector must be an array with length len
//Postcondition: vector is normalized
void normalizeVector(double vector[], int len) {
  double vector_copy[len];

  //copies vector into vector_copy
  for(int i = 0; i < len; i++) {
    vector_copy[i] = vector[i];
  }

  //Enters normalised values into vector
  for(int i = 0; i < len; i++) {
    vector[i] = vector_copy[i] / sqrt(sq_sum(vector_copy, len));
  }
}

//Precondition:  vector is an array with lenth len
//Postcondition: returns sum of squares of elements of vector
int sq_sum(double vector[], int len) {
  double sum = 0;

  for(int i = 0; i < len; i++) {
    sum += pow(vector[i], 2);
  }

  return(sum);
}
