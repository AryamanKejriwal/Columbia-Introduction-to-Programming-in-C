/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 6 Bonus 2

This program prints whether an inputted string is a palindrome or not
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define to_lowercase(x) ((x) < 'a') ? ((x) + 'a' - 'A') : (x)

int deblank(char str[], int length);
int depunctuate(char str[], int length);
int is_palindrome(char str[], int length, int start);

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter the length of your string> ");
  scanf("%d", &n);
  char str[n+1];
  printf("Enter your string> ");

  char tmp = '\n';
  while(tmp == '\n') {
    scanf("%c", &tmp);
  }
  if(n > 0) {
    str[0] = tmp;
  }

  //Actually stores rest of the word in the array.
  for(int i = 1; i < n; i++) {
    scanf("%c", &str[i]);
  }
  str[n] = '\0';

  char str_copy[n+1];
  strcpy(str_copy, str);

  n = n - deblank(str, n);
  n = n - depunctuate(str, n);

  for(int i = 0; i < n; i++) {
    str[i] = to_lowercase(str[i]);
  }

  //printf("%s\n", str);
  if(is_palindrome(str, n, 0)) {
    printf("%s is a palindrome.\n", str_copy);
  } else {
    printf("%s is not a palindrome.\n", str_copy);
  }

  return(0);
}

//Removes blanks from str and returns the number of blanks removed
int deblank(char str[], int length) {
  int count = 0;
  for(int i = 0; i < length - count + 1; i++) {
    if(str[i] == ' ') {
      for(int j = i; j < length - count + 1; j++) {
        str[j] = str[j+1];
      }

      count++;
    }
  }

  return(count);
}

////Removes punctuation marks from str and returns the number of punctuation marks removed
int depunctuate(char str[], int length) {
  int count = 0;
  for(int i = 0; i < length - count + 1; i++) {
    if(ispunct(str[i])) {
      for(int j = i; j < length - count + 1; j++) {
        str[j] = str[j+1];
      }

      count++;
    }
  }

  return(count);
}

//Precondition:  str is a string of length length, start = 0 for first call
//Postcondition: Returns 1 if str is a palindrome and 0 if str is not a palindrome
int is_palindrome(char str[], int length, int start) {
  if(start >= length/2) { //Base Case
    return(str[start] == str[length - start - 1]);
  } else {
    return(is_palindrome(str, length, start + 1) && (str[start] == str[length - start - 1])); //Recursive call
  }
}
