/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1.5

Tells the user the number of days in the given month in a given year
*/

#include <stdio.h>

int main() {
  int month = 0;
  int year = 0;

  //Asks user for a month and year number.
  printf("What is the given month?\n");
  scanf("%d", &month);

  printf("What is the given year?\n");
  scanf("%d", &year);

  //looks at non-February cases
  if(month != 2) {
    if(month > 0 && month <= 12) {
      switch(month) {
        case 1: printf("January %d has 31 days.\n", year); break;
        case 3: printf("March %d has 31 days.\n", year); break;
        case 4: printf("April %d has 30 days.\n", year); break;
        case 5: printf("May %d has 31 days.\n", year); break;
        case 6: printf("June %d has 30 days.\n", year); break;
        case 7: printf("July %d has 31 days.\n", year); break;
        case 8: printf("August %d has 31 days.\n", year); break;
        case 9: printf("September %d has 30 days.\n", year); break;
        case 10:printf("October %d has 31 days.\n", year); break;
        case 11:printf("November %d has 30 days.\n", year); break;
        case 12:printf("December %d has 31 days.\n", year); break;
      }

    //Deals with non-existant month numbers
    } else {
      printf("That is not a valid month\n");
    }
  //Deals with February
  } else {
    if(year % 400 == 0) {
      printf("February %d has 29 days\n", year);
    } else if(year % 100 == 0) {
      printf("February %d has 28 days\n", year);
    } else if(year % 4 == 0) {
      printf("February %d has 29 days\n", year);
    } else {
      printf("February %d has 28 days\n", year);
    }
  }

  return(0);
}
