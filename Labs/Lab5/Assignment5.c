/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5.5

This program stores the names of people along with their ages and sorts them
*/

//This program is incomplete and throws error(s)

#include <stdio.h>
#include <string.h>

#define LENGTH 6
#define LARGEST 100

int main() {

  char names[LENGTH][LARGEST] = {"Ryan, Elizabeth", "McIntyre, Osborne", "DuMond, Kristin", "Larson, Lois",
                                 "Thorpe, Trinity", "Ruiz, Pedro"};

  int ages[LENGTH] = {62, 84, 18, 42,
                      15, 35};

  printf("Original List:\n-------------------------\n");
  for(int i = 0; i < LENGTH; i++) {
    printf("%-25s%d\n", names[i], ages[i]);
  }

  for(int i = 0; i < LENGTH; i++) {
    for(int j = 0; j < LENGTH - 1 - i; j++) {
      if(strcmp(names[j], names[j+1]) > 0) {
        char str_tmp[LARGEST];
        strcpy(str_tmp, names[j]);
        strcpy(names[j], names[j+1]);
        strcpy(names[j+1], str_tmp);

        int tmp = ages[j];
        ages[j] = ages[j+1];
        ages[j+1] = tmp;
      }
    }
  }

  printf("\n\nAlphabetized List:\n-------------------------\n");
  for(int i = 0; i < LENGTH; i++) {
    printf("%-25s%d\n", names[i], ages[i]);
  }
  return(0);
}
