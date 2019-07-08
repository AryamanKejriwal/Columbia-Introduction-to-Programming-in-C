/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 7.1

This program defines a type long_lat_t that stores latitude and longitude and methods to scan, print and check
their equality.
*/

#include <stdio.h>

typedef struct {
  int degrees;
  int minutes;
  char direction;
} long_lat_t;

long_lat_t scan_long_lat(long_lat_t l);
void print_long_lat(long_lat_t l);
int long_lat_equal(long_lat_t l1, long_lat_t l2);

int main() {
  long_lat_t l1;
  long_lat_t l2;

  printf("First Longitude/Latitude:\n");
  l1 = scan_long_lat(l1);
  printf("Second Longitude/Latitude:\n");
  l2 = scan_long_lat(l2);

  printf("First Longitude/Latitude:\n");
  print_long_lat(l1);
  printf("Second Longitude/Latitude:\n");
  print_long_lat(l2);

  int are_equal = long_lat_equal(l1, l2);

  //Checks the returned value from lat_long_equal()
  if(are_equal) {
    printf("The first longitude/latitude is equal to the second.\n");
  } else {
    printf("The first longitude/latitude is not equal to the second.\n");
  }

  return(0);
}

//Gets data for and returns a long_lat_t
long_lat_t scan_long_lat(long_lat_t l) {
  printf("Enter the degrees> ");
  scanf("%d", &(l.degrees));
  printf("Enter the minutes> ");
  scanf("%d", &(l.minutes));
  printf("Enter the direction> ");
  scanf(" %c", &(l.direction));

  return(l);
}

//Prints a long_lat_t
void print_long_lat(long_lat_t l) {
  printf("The data of the latitude/longitude is as follows:\n");
  printf("Degrees:\t%d\nMinutes:\t%d\nDirection:\t%c\n", l.degrees, l.minutes, l.direction);
}

//Returns 1 if all members of l1 are equal to all members of l2 and 0 otherwise
int long_lat_equal(long_lat_t l1, long_lat_t l2) {
  if(l1.degrees == l2.degrees && l1.minutes == l2.minutes && l1.direction == l2.direction) {
    return(1);
  } else {
    return(0);
  }
}
