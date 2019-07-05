/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5 Bonus 1

This program takes input as a file of data with hurricale names, year and states affected. Prints the data
ordered by name or by year, as chosen by the user.

Note: The data file must be in the correct format.(year; name; states;). The year, name and state list
      must be no longer than the macros defined.
*/

#include <stdio.h>
#include <string.h>

#define MAX 30
#define YEAR_LENGTH 21
#define NAME_LENGTH 21  //Maximum length of hurricane name and input file name
#define STATE_LENGTH 21

char *scan_line(char *dest, FILE* input, int dest_len);
void fill_data(char line[], char year[], char name[], char state[]);
void substr(char *str, int start_index, int length, char sub[]);
void sort_str(char a[MAX][NAME_LENGTH], char b[MAX][NAME_LENGTH], char c[MAX][NAME_LENGTH], int maxA, int maxB, int maxC, int length);
void str_cpy(char a[], char b[]);

int main() {
  char year[MAX][YEAR_LENGTH];
  char name[MAX][NAME_LENGTH];
  char state[MAX][STATE_LENGTH];

  char file_name[NAME_LENGTH];
  //Gets file name from user
  printf("Enter input file name> ");
  scanf("%s", file_name);

  FILE *input = fopen(file_name, "r");

  char beg = 'a';

  int index = 0;

  int length = 0;

  do {

    char line[MAX];
    scan_line(line, input, MAX);

    beg = line[0];

    if(line[0] == '\0') {
      break;
    } else {
      fill_data(line, year[index], name[index], state[index]);
      length++;
    }

    index++;
  } while(beg != '\0');

  //Asks user how to sort list
  int choice = 0;
  printf("1. Sort by Year\n2. Sort by name\nAny other number will result in unsorted output\nEnter the option you want> ");
  scanf("%d", &choice);

  if(choice == 1) {
    sort_str(year, name, state, YEAR_LENGTH, NAME_LENGTH, STATE_LENGTH, length);
  } else if(choice == 2) {
    sort_str(name, year, state, NAME_LENGTH, YEAR_LENGTH, STATE_LENGTH, length);
  }

  printf("Year   Name                   States\n----   -------                --------\n");

  for(int i = 0; i < index; i++) {
    printf("%-4s   %-20s   %-20s\n", year[i], name[i], state[i]);
  }

  return(0);
}

//Authored by Mr. Pajela
/* * Gets one line of data from input. Returns an empty string on * end of file. If data line will not fit in allotted space, stores * portion that does fit and discards rest of input line. */
char *scan_line(char *dest, FILE* input, int dest_len) {
  int i, ch;  /* Gets next line one character at a time. */
  i = 0;
  for (ch = getc(input); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getc(input)) {
    dest[i++] = ch;
  }
  dest[i] = '\0';  /* Discards any characters that remain on input line */
  while (ch != '\n' && ch != EOF) {
    ch = getc(input);
  }
  return(dest);
}

//Precondition:  Line is in the specified format
//Postcondition: The data about the hurricane is stored in the specific array
void fill_data(char line[], char year[], char name[], char state[]) {
  int start  = 0;
  int length = 0;

  //YEAR:
  while(line[start + length] != ';') {
    length++;
  }

  substr(line, start, length, year);
  year[length] = '\0';

  //NAME:
  start += length + 2;
  length = 0;

  while(line[start + length] != ';') {
    length++;
  }
  substr(line, start, length, name);
  name[length] = '\0';

  //STATE
  start += length + 2;
  length = 0;

  while(line[start + length] != ';') {
    length++;
  }
  substr(line, start, length, state);
  state[length] = '\0';
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

//Precondition:  a, b, and c are all of the same length
//Postcondition: a is sorted. b and c remain parallel to a
void sort_str(char a[MAX][NAME_LENGTH], char b[MAX][NAME_LENGTH], char c[MAX][NAME_LENGTH], int maxA, int maxB, int maxC, int length) {
  for(int i = 0; i < length - 1; i++) {
    for(int j = 0; j < length - 1 - i; j++) {
      if(strcmp(a[j], a[j+1]) > 0) {
        //Swap for a
        char tmpA[maxA];
        str_cpy(tmpA, a[j]);
        str_cpy(a[j], a[j+1]);
        str_cpy(a[j+1], tmpA);

        //Swap for b
        char tmpB[maxB];
        str_cpy(tmpB, b[j]);
        str_cpy(b[j], b[j+1]);
        str_cpy(b[j+1], tmpB);

        //Swap for c
        char tmpC[maxC];
        str_cpy(tmpC, c[j]);
        str_cpy(c[j], c[j+1]);
        str_cpy(c[j+1], tmpC);
      }
    }
  }
}

//Copies elements of b into a
void str_cpy(char a[], char b[]) {
  int i = 0;
  while(b[i] != '\0') {
    a[i] = b[i];
    i++;
  }
  a[i] = b[i];

}
