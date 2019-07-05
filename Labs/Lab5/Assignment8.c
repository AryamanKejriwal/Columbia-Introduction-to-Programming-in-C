/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5.8

This program traverses names in a file and seperates the different parts of the names
and prints them in columns in another file
*/

#include <stdio.h>

#define MAX_FILE_NAME 100
#define MAX_LINE_LENGTH 80

char *scan_line(char *dest, FILE* input, int dest_len);
void split_name(char line[MAX_LINE_LENGTH], char surname[16], char first[11], char middle_init[2]);

int main() {
  FILE *input;
  FILE *output;

  char in_name[MAX_FILE_NAME];
  char out_name[MAX_FILE_NAME];

  //Asks user for name of input and output files respectively
  printf("Enter input file name> ");
  scanf("%s", in_name);
  printf("Enter output file name> ");
  scanf("%s", out_name);

  input  = fopen(in_name, "r");
  output = fopen(out_name, "w");

  char beg = 'a';
  do {
    char surname[16];
    char first[11];
    char middle_init[2];

    char line[MAX_LINE_LENGTH];
    scan_line(line, input, MAX_LINE_LENGTH);

    beg = line[0];

    if(line[0] == '\0') {
      break;
    } else {
      split_name(line, surname, first, middle_init);
    }

    fprintf(output, "%-15s   %-10s   %-1s\n", surname, first, middle_init);
  } while(beg != '\0');

  fclose(input);
  fclose(output);

  printf("Data successfully transferred.\n");

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

//Precondition:  The name on each line is in the specified format
//Postcondition: The name is split into the 3 arrays
void split_name(char line[MAX_LINE_LENGTH], char surname[16], char first[11], char middle_init[2]) {
  int count_line    = 0;
  int count_surname = 0;
  int count_first   = 0;

  while(line[count_line] != ',' && count_surname < 15) {
    surname[count_surname] = line[count_line];
    count_surname++;
    count_line++;
  }
  surname[count_surname] = '\0';

  while(line[count_line] != ',') {
    count_line++;
  }

  count_line += 2;

  while(line[count_line] != '.' && line[count_line] != ' ' && count_first < 10) {
    first[count_first] = line[count_line];
    count_first++;
    count_line++;
  }
  first[count_first] = '\0';

  while(line[count_line] != '.' && line[count_line] != ' ') {
    count_line++;
  }

  if(line[count_line] == '.') {
    count_line += 2;
  } else {
    count_line += 1;
  }

  middle_init[0] = line[count_line];
  middle_init[1] = '\0';
}
