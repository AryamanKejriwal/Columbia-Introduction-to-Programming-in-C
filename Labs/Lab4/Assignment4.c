/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.4

This program subtracts a 3x3 array from another 3x3 array
*/

#include <stdio.h>

#define LENGTH 3

void fillArr(int arr[LENGTH][LENGTH], int len);
void subtractArr(int arr1[LENGTH][LENGTH], int arr2[LENGTH][LENGTH], int arr3[LENGTH][LENGTH], int len);
void printArr(int arr [LENGTH][LENGTH], int len);

int main() {

  int arr1[LENGTH][LENGTH];
  int arr2[LENGTH][LENGTH];
  int arr3[LENGTH][LENGTH];

  //gets user input
  printf("Fill in the detailes of the first array below:\n");
  fillArr(arr1, LENGTH);
  printf("Fill in the detailes of the second array below:\n");
  fillArr(arr2, LENGTH);

  //subtracts arr2 from arr1 and fills it in arr3
  subtractArr(arr1, arr2, arr3, LENGTH);

  //Prints the resultant array;
  printf("The Resultant Array is:]\n");
  printArr(arr3, LENGTH);

  return(0);
}


//Precondition:  arr[][] is a 2D Array with the same length as the length of its elements
//               LENGTH == length of array
//Postcondition: arr[][] is filled with user input until length len and height len
void fillArr(int arr[LENGTH][LENGTH], int len) {
  for(int i = 0; i < len; i++) {
    for(int j = 0; j < len; j++) {
      printf("Enter value of index %dx%d of the array> ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }
}

//Precondition:  arrays are a 2D Arrays with the same length as the length of their elements
//               LENGTH == length of all arrays
//               dimensions of all arrays are the same
//Postcondition: arr3[][] is filled with values obtained by subtracting the corresponding values of arr2[][] from
//                those of arr1[][]
void subtractArr(int arr1[LENGTH][LENGTH], int arr2[LENGTH][LENGTH], int arr3[LENGTH][LENGTH], int len) {
  for(int i = 0; i < len; i++) {
    for(int j = 0; j < len; j++) {
      arr3[i][j] = arr1[i][j] - arr2[i][j];
    }
  }
}

//Precondition:  Both the height and length of arr[][] must be equal to LENGTH
//Postcondition: arr is printed to the console
void printArr(int arr [LENGTH][LENGTH], int len) {

  //Prints values
  for(int i = 0; i < len; i++) {
    printf("|");
    for(int j = 0; j < len; j++) {
      printf("\t%d", arr[i][j]);
    }
    printf("\t|\n");
  }

}
