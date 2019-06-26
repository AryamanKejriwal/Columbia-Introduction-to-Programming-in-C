/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1 Bonus 10

Asks user for a dollar amount and tells the user the minimum
number of bills equalling the amount.
*/

#include <stdio.h>

int main() {

  //To store the number of notes of each currency bill
  int five_hundreds = 0;
  int hundreds      = 0;
  int fifties       = 0;
  int twenties      = 0;
  int tens          = 0;
  int fives         = 0;
  int ones          = 0;

  int sum = 0;

  //Asks user for the dollar amount
  printf("What is the dollar amount?\n");
  scanf("%d", &sum);

  //Calculates number of each bill
  five_hundreds = sum/500; sum = sum - 500 * five_hundreds;
  hundreds      = sum/100; sum = sum - 100 *hundreds;
  fifties       = sum/50;  sum = sum - 50 * fifties;
  twenties      = sum/20;  sum = sum - 20 * twenties;
  tens          = sum/10;  sum = sum - 10 * tens;
  fives         = sum/5;   sum = sum - 5 * fives;
  ones          = sum/1;   sum = sum - 1 * ones;

  //prints only bill that have number greater than 0
  if(five_hundreds != 0) {
    printf("$500: %2d\n", five_hundreds);
  }
  if(hundreds != 0) {
    printf("$100: %2d\n", hundreds);
  }
  if(fifties != 0) {
    printf("$50: %2d\n", fifties);
  }
  if(twenties != 0) {
    printf("$20: %2d\n", twenties);
  }
  if(tens != 0) {
    printf("$10: %2d\n", tens);
  }
  if(fives != 0) {
    printf("$5: %2d\n", fives);
  }
  if(ones != 0) {
    printf("$1: %2d\n", ones);
  }
  
  return(0);
}
