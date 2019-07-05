/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 6.5 (Bonus)

This program rearranges pancakes from largest to smallest less than 2n - 3 flips where n is the number of pancakes
*/

#include <stdio.h>

void sort_descending(int pancakes[], int length, int sorted);
void flip(int pancakes[], int length, int k);

int main() {
  int n = 0;

  //Asks the user for input
  printf("Enter the number of pancakes> ");
  scanf("%d", &n);
  int pancakes[n];
  for(int i = 0; i < n; i++) {
    printf("Enter the radius of pancake at element %d (from bottom to top)> ", i);
    scanf("%d", &pancakes[i]);
  }

  sort_descending(pancakes, n, 0);

  //flip(pancakes, n, 10);

  for(int i = 0; i < n; i++) {
    printf("%d ", pancakes[i]);
  }
  printf("\n");
  return(0);
}

//Sorts the array in descending order in at most 2n - 3 flips
void sort_descending(int pancakes[], int length, int sorted) {
  if(length <= sorted + 1) { //Base Case
    return;
  } else {
    int max_index = sorted;
    for(int i = sorted+1; i < length; i++) {
      if(pancakes[i] > pancakes[max_index]) {
        max_index = i;
      }
    }
    if(max_index != length - sorted) {
      if(max_index != length - 1) {
        flip(pancakes, length, length - max_index);
      }
      flip(pancakes, length, length - sorted);
    }

    sort_descending(pancakes, length, sorted+1);
  }
}

//Flips the last k elements (top k pancake)
void flip(int pancakes[], int length, int k) {
  for(int i = 0; i < k/2; i++) {
    int tmp = pancakes[i + length - k];
    pancakes[i + length - k] = pancakes[length - i - 1];
    pancakes[length - i - 1] = tmp;
  }
}
