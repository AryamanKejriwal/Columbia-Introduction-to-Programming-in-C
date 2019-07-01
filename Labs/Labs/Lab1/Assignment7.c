/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 1.7

Tells the user what time he is expected to reach home
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

  int time = 0;

  printf("How many minutes from now do you expect to get home in?\n");
  scanf("%d", &time);

  time += min;
  min = 0;

  int add_hours = time/60;
  int add_mins  = time % 60;

  int total_hours = (hour + add_hours) % 24;
  int total_mins  = (min + add_mins);

  if(total_mins >= 10) {
    printf("You will get home at %2d:%2d (24-hour time)\n", total_hours, total_mins);
  } else {
    printf("You will get home at %2d:0%1d (24-hour time)\n", total_hours, total_mins);
  }
  return(0);

}
