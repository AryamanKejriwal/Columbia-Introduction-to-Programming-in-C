/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 8.4

This program takes each word from a given input file and to an output file prints each word along with the number of letters in
it. The programs removes whitspaces.
*/

#include <stdio.h>

#define MAX_LENGTH 150

void print_word(FILE *output, char word[MAX_LENGTH]);
int word_length(char word[MAX_LENGTH]);
int is_letter(char c);

int main() {
  char in_name[MAX_LENGTH];
  char out_name[MAX_LENGTH];

  //Asks user for input
  printf("Enter the input file name> ");
  scanf("%s", in_name);
  printf("Enter the output file name> ");
  scanf("%s", out_name);

  FILE *input = fopen(in_name, "r");
  FILE *output = fopen(out_name, "w");

  char word[MAX_LENGTH];
  int EOF_detection = fscanf(input, "%s", word);
  while(EOF_detection != EOF) {
    print_word(output, word);
    EOF_detection = fscanf(input, "%s", word);
  }

  printf("Data successfully printed.\n");

  fclose(input);
  fclose(output);
  return(0);
}

//Prints word with number of letters to output file
void print_word(FILE *output, char word[MAX_LENGTH]) {
  int l = word_length(word);
  while(!is_letter(word[0])) {
    for(int i = 1; i < MAX_LENGTH; i++) {
      word[i - 1] = word[i];
    }
  }
  int count = 0;
  while(word[count] != '\0') {
    count++;
  }
  while(count != 0 && !is_letter(word[count])) {
    word[count] = '\0';
    count--;
  }
  fprintf(output, "%s - %d\n", word, l);
}

//Returns the number of letters in a word
int word_length(char word[MAX_LENGTH]) {
  int count = 0;
  for(int i = 0; i < MAX_LENGTH && word[i] != ' ' && word[i] != '\n' && word[i] != '\0'; i++) {
    if(is_letter(word[i])) {
      count++;
    }
  }

  return(count);
}

//If character is a letter returns 1 else returns 0
int is_letter(char c) {
  return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
