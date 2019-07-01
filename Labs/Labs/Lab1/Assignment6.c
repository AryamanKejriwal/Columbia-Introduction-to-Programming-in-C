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

  int sunset_hour = 0;
  int sunset_minute  = 0;

  //Asks the user for sunset hour and minute
  printf("What is the sunset hour?\n");
  scanf("%d", &sunset_hour);
  printf("What is the sunset minute?\n");
  scanf("%d", &sunset_minute);

  //Greets the user based on time of day
  if(hour < 12) {
    printf("Good Morning!\n");
  } else if(hour*60 + min < sunset_hour*60 + sunset_minute) {
    printf("Good Evening!\n");
  } else {
    printf("Good Afternoon!\n");
  }

  return(0);
}
