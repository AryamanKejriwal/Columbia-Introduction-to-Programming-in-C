/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5.7

This program takes 2 words as input and returns the longest common suffix
*/

#include <stdio.h>

#define MAX_LENGTH 20

int common_suffix_len(char w1[], char w2[]);

int main() {
  char word1[MAX_LENGTH];
  char word2[MAX_LENGTH];

  //Gets user input
  printf("Enter the first word> ");
  scanf("%s", word1);
  printf("Enter the second word> ");
  scanf("%s", word2);

  int l = common_suffix_len(word1, word2);

  printf("The longest common suffix is %s.\n", &word1[l]);

  return(0);
}

//Precondition:  w1 and w2 are shorter than or equal to MAX_LENGTH
//Postcondition: returns the index from which the longest common suffix starts in w1
int common_suffix_len(char w1[], char w2[]) {
  int l = 0;

  int end_index1 = -1;
  int end_index2 = -1;

  for(int i = 0; i < MAX_LENGTH; i++) {
    if(end_index1 == -1 && w1[i] == '\0') {
      end_index1 = i;
    }
    if(end_index2 == -1 && w2[i] == '\0') {
      end_index2 = i;
    }
  }

  while(w1[end_index1 - l - 1] == w2[end_index2 - l - 1]) {
    l++;
  }

  return(end_index1 - l);
}
