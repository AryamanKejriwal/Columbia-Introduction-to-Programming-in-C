/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5.3

This program checks whether a chemical name ends in OH (Hydroxide);
*/

#include <stdio.h>
#include <string.h>

int hydroxide(char *str);
void substr(char *str, int start_index, int length, char sub[]);

int main() {
    //Tests the function hydroxide with the given chemical names
    if(hydroxide("KOH")) {
      printf("KOH is a hydroxide.\n");
    } else {
      printf("KOH is not a hydroxide.\n");
    }

    if(hydroxide("H2O2")) {
      printf("H2O2 is a hydroxide.\n");
    } else {
      printf("H2O2 is not a hydroxide.\n");
    }

    if(hydroxide("NaCl")) {
      printf("NaCl is a hydroxide.\n");
    } else {
      printf("NaCl is not a hydroxide.\n");
    }

    if(hydroxide("NaOH")) {
      printf("NaOH is a hydroxide.\n");
    } else {
      printf("NaOH is not a hydroxide.\n");
    }

    if(hydroxide("C9H8O4")) {
      printf("C9H8O4 is a hydroxide.\n");
    } else {
      printf("C9H8O4 is not a hydroxide.\n");
    }

    if(hydroxide("MgOH")) {
      printf("MgOH is a hydroxide.\n");
    } else {
      printf("MgOH is not a hydroxide.\n");
    }

  return(0);
}

//Precondition:  str is a string storing a valid chemical name
//Postcondition: returns 1 if last 2 characters are OH and 0 otherwise
int hydroxide(char *str) {
  int i = 0;
  while(str[i] != '\0') {
    i++;
  }

  char sub[2];

  substr(str, i - 2, 2, sub);

  if(strcmp(sub, "OH") == 0) {
    return(1);
  } else {
    return(0);
  }
}

//Precondition:  str is a string with at least start_index + length characters
//Postcondition: substring of str that starts with start_index and is length characters long is stored in sub
void substr(char *str, int start_index, int length, char sub[]) {
  char s[length+1];
  for(int i = 0; i < length; i++) {
    sub[i] = str[start_index + i];
  }

  sub[length] = '\0';
}
