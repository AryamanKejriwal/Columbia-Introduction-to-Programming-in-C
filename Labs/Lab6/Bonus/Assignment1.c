/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 6 Bonus 1

This program counts the number of pixels in an object in a picture
*/

#include <stdio.h>

#define HEIGHT 6
#define WIDTH 6

int blob_check(int picture[HEIGHT][WIDTH], int x, int y);



int main() {
  int picture[HEIGHT][WIDTH] = { {1, 1, 1, 0, 0, 1},
                                 {0, 1, 1, 1, 0, 0},
                                 {0, 1, 1, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 1},
                                 {0, 0, 0, 0, 1, 1},
                                 {0, 1, 0, 1, 0, 1},
                               };
  int x = 0;
  int y = 0;

  //Asks user for input
  printf("Enter the value of x> ");
  scanf("%d", &x);
  printf("Enter the value of y> ");
  scanf("%d", &y);

  int count = blob_check(picture, x, y);

  printf("The number of pixels in the selected object is %d.\n", count);

  return(0);
}

//Recursively checks the size of the blob of which the pixel is a part
int blob_check(int picture[HEIGHT][WIDTH], int x, int y) {
  int sum = 0;

  if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) { //Base case 1
    return(0);
  } else {
    if(picture[y][x] == 0) { //Base case 2
      return(0);
    } else {
      sum++;
      picture[y][x] = 0;
      for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
          if(!(i == 0 && j == 0)) {
            sum += blob_check(picture, x + i, y + j); //Recursive Call
          }
        }
      }
    }
  }

  return(sum);
}
