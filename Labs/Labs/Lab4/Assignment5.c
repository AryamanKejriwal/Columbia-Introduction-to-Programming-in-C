/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.5

This program calculates and prints the euclidean distance between 2 vectors.
*/

#include <stdio.h>
#include <math.h>

void fillArr(int arr[], int len);
int euclideanDistance(int arr1[], int arr2[], int len);

int main() {
  int N;

  printf("Enter N> ");
  scanf("%d", &N);

  //Fills arrays with user data
  int arr1[N];
  printf("Enter data for first vector below:\n");
  fillArr(arr1, N);
  printf("Enter data for second vector below:\n");
  int arr2[N];
  fillArr(arr2, N);

  int d = euclideanDistance(arr1, arr2, N);

  printf("The Euclidean distance between the 2 vectors is %d.\n", d);

  return(0);
}

//Precondition:  arr is an Array with length len
//Postcondition: arr is filled with user inputs
void fillArr(int arr[], int len) {
  for(int i = 0; i < len; i++) {
    printf("Enter the element at index %d of the vector> ", i);
    scanf("%d", &arr[i]);
  }
}

//Precondition:  arr1 and arr2 have length equal to len
//Postcondition: returns Euclidean distance between arr1 and arr2
int euclideanDistance(int arr1[], int arr2[], int len) {

  int sum = 0;

  for(int i = 0; i < len; i++) {
    sum += pow((arr1[i] - arr2[i]), 2);
  }

  return(sqrt(sum));

}
