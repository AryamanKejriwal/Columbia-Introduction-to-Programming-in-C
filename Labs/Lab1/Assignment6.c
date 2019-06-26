/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1.6

Greets the user depending on the time of day.
*/

#include <stdio.h>
#include <time.h>

int main() {
  time_t t;
  struct tm *now;
  t = time(0);         /* get current time */
  now = localtime(&t); /* adjust for local timezone */

  int hour = now->tm_hour; /* retrieve current hour */
  int min  = now->tm_min;  /* retrieve current min  */

  int sunrise_hour = 0;
  int sunset_hour  = 0;

  //Asks the user for sunrise and sunset hours
  printf("What is the sunrise hour?\n");
  scanf("%d", &sunrise_hour);
  printf("What is the sunset hour?\n");
  scanf("%d", &sunset_hour);

  //Greets the user based on time of day
  if(hour < sunrise_hour) {
    printf("Good Morning!\n");
  } else if(hour > sunset_hour) {
    printf("Good Evening!\n");
  } else {
    printf("Good Afternoon!\n");
  }

  return(0);
}
