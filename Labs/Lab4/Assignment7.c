/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.7

This program takes two lists of non negative numbers at most 20 elements long and computes z which has
elements equal to the products of the corresponding elements of x and y
*/

#include <stdio.h>
#include <math.h>

#define LENGTH 20

int fillArr(double arr[], int len);
void fillProduct(double arr1[], double arr2[], double arr3[], int len);

int main() {
  double x[LENGTH];
  double y[LENGTH];
  double z[LENGTH];

  //Fills array and returns the length
  printf("Enter elements in first array:\n");
  int len_x = fillArr(x, LENGTH);
  printf("Enter elements in second array:\n");
  int len_y = fillArr(y, LENGTH);

  //Makes sure that the arrays are of the same length
  if(len_x != len_y) {
    printf("ERROR: The arrays are not of the same length.\n");
  } else {
    fillProduct(x, y, z, LENGTH);

    //Prints 3-column table with values for x, y, and z
    printf("|\tx\t|\ty\t|\tz\t|\n-------------------------------------------------\n");

    for(int i = 0; i < LENGTH; i++) {
      if(z[i] >= 0) {
        printf("|\t%.4lf\t|\t%.4lf\t|\t%.4lf\t|\n", x[i], y[i], z[i]);
      } else {
        break;
      }
    }

    double sum = 0;

    //Calculates sum of elements in z
    for(int i = 0; i < LENGTH; i++) {
      if(z[i] >= 0) {
        sum += z[i];
      } else {
        break;
      }
    }

    printf("The sqare root of the sum of elements in z is %lf\n", sqrt(sum));
  }


  return(0);
}

//Precondition:  arr is an Array with length len && len <= 20
//Postcondition: arr is filled with user inputs that are non-negative. Any negative is a sentinal value.
//               length of the array before sentinal value is returned
int fillArr(double arr[], int len) {
  for(int i = 0; i < len; i++) {
    double input = 0;
    printf("Enter the element at index %d of the array (Sentinal is any value < 0)> ", i);
    scanf("%lf", &input);
    arr[i] = input;
    if(input < 0) {
      return(i);
    }
  }

  return(len);
}

//Precondition:  arr1, arr2 and arr3 are all of length len. They may or may not have sentinal values earlier.
//               If they do, they must be in the same position.
//Postcondition: arr3 is filled with the product of the corresponding values in arr 1 and arr2. -1 is placed at the end if required.
void fillProduct(double arr1[], double arr2[], double arr3[], int len) {
  int i = 0;
  while(i < len && arr1[i] >= 0) {
    arr3[i] = arr1[i] * arr2[i];
    i++;
  }

  if(i < len) {
    arr3[i] = -1;
  }
}
