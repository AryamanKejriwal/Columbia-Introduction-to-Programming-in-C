/*
Author: Aryaman Kejriwal & Jacob Baer
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.3

This program prints average of 10 numbers and prints how many of the numbers are bellow average
*/

#include <stdio.h>

//Length has to be greater than zero
#define LENGTH 10;

int main() {

  int nums[LENGTH];
  int sum = 0;

  //Gets input from user
  printf("Enter 10 numbers below:\n");
  for(int i = 0; i < LENGTH; i++) {
    scanf("%d", &nums[i]);
    sum += nums[i];
  }

  int average = sum / LENGTH;

  //counts the numbers that are below average
  int count = 0;
  for(int i = 0;i < LENGTH; i++) {
    if(nums[i] < average) {
      count++;
    }
  }

  printf("The average of the numbers is %d and there are %d numbers below average.", average, count);

  return(0);
}
