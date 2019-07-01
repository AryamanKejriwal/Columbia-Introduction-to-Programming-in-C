/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2.2

This program draws shapes with given dimensions
*/

#include <stdio.h>

int main() {

  //All variables needed to store dimensions for all shapes
  int w, h, l, s;
  double r;

  /* RECTANGLE */
  //Gets inpute from user for the rectangle
  printf("The Rectangle:\n");
  printf("Enter width>");
  scanf("%d", &w);
  printf("Enter height>");
  scanf("%d", &h);

  //Checks whether dimentions are valid
  if(w <= 0 || h <= 0) {
    printf("Those are not valid dimensions\n");
  } else {
    //Draws boundary of the rectangle
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(i == 0 || i == (h-1) || j == 0 || j == (w-1)) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  /* X */
  //Gets inpute from user for the X
  printf("The X:\n");
  printf("Enter length>");
  scanf("%d", &l);

  //Checks whether dimentions are valid
  if(l <= 0) {
    printf("Those are not valid dimensions\n");
  } else {
    //Draws the X
    for(int i = 0; i < l; i++) {
      for(int j = 0; j < l; j++) {
        if(i == j || i == (l - (j + 1))) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }


  /* LOWER TRIANGLE */
  //Gets inpute from user for the lower triangle
  printf("The Lower Triangle:\n");
  printf("Enter side>");
  scanf("%d", &s);

  //Checks whether dimentions are valid
  if(s <= 0) {
    printf("Those are not valid dimensions\n");
  } else {
    //Draws the lower triangle
    for(int i = 0; i < s; i++) {
      for(int j = 0; j < s; j++) {
        if(i >= j) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  /* UPPER TRIANGLE */
  //Gets inpute from user for the lower triangle
  printf("The Upper Triangle:\n");
  printf("Enter side>");
  scanf("%d", &s);

  //Checks whether dimentions are valid
  if(s <= 0) {
    printf("Those are not valid dimensions\n");
  } else {
    //Draws the upper triangle
    for(int i = 0; i < s; i++) {
      for(int j = 0; j < s; j++) {
        if(i <= j) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  /* TRAPEZOID */
  //Gets inpute from user for the trapezoid
  printf("The Trapezoid:\n");
  printf("Enter side>");
  scanf("%d", &s);
  printf("Enter height>");
  scanf("%d", &h);

  //Checks whether dimentions are valid
  if((s <= 0 || h <= 0) ||(s < h)) {
    printf("Those are not valid dimensions\n");
  } else {
    //Draws the trapezoid
    for(int i = (s - h); i < s; i++) {
      for(int j = 0; j < s; j++) {
        if(i >= j) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  /* CIRCLE */
  //Gets inpute from user for the circle
  printf("The Circle:\n");
  printf("Enter radius>");
  scanf("%lf", &r);

  //Checks whether dimentions are valid
  if(r <= 0) {
    printf("Those are not valid dimensions\n");
  } else {
    //Draws the circle
    for(int i = -r; i <= r; i++) {
      for(int j = -r; j <= r; j++) {
        if((i * i) + (j * j) < (r * r)) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  return(0);
}
