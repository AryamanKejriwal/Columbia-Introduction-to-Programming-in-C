/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5.4

This program prints out the singular and plural form of a given noun (input in singular form).
*/

#include <stdio.h>
#include <string.h>

char *substr(char *str, int start_index, int length);

int main() {
  int length = 0;

  //Gets input from user
  printf("How long is your noun> ");
  scanf("%d", &length);
  char str[length];
  printf("Enter your word> ");
  scanf("%s", str);

  char *sub = substr(str, length - 2, 2);

  char new[length+2];

  if(sub[1] == 'y') {
    char *tmp = substr(str, 0, length-1);
    printf("The plural of %s is %sies.\n", str, tmp);
  } else if(sub[1] == 's' || (sub[0] == 'c' && sub[1] == 'h') || (sub[0] == 's' && sub[1] == 'h')) {
    sprintf(new, "%s", str);
    printf("The plural of %s is %ses.\n", str, new);
  } else {
    sprintf(new, "%s", str);
    printf("The plural of %s is %ss.\n", str, new);
  }

  return(0);
}

//Precondition:  str is a string with at least start_index + length characters
//Postcondition: returns substring of str that starts with start_index and is length characters long
char *substr(char *str, int start_index, int length) {
  char s[length+1];
  for(int i = 0; i < length; i++) {
    s[i] = str[start_index + i];
  }

  s[length] = '\0';

  return(s);
}
