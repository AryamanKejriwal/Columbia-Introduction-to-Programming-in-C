/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.5

This program takes a .txt file name as a command line argument and creates a copy of the file with a heading
line and line numbers. Also, the backup file is a .txt file
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200

char *scan_line(char *dest, FILE* input, int dest_len);

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Not enough arguments. Type in command as follows:\n./exe_name.exe file_name\n");
  } else {
    char file_name[MAX_LENGTH];
    strcpy(file_name, argv[1]);

    char out_name[MAX_LENGTH];
    int count = 0;
    for(int i = 0; i < MAX_LENGTH && file_name[i] != '.'; i++) {
      out_name[i] = file_name[i];
      count++;
    }
    out_name[count++] = '.';
    out_name[count++] = 'l';
    out_name[count++] = 'i';
    out_name[count++] = 's';
    out_name[count]   = '\0';

    FILE *input  = fopen(file_name, "r");
    FILE *output = fopen(out_name, "w");
    fprintf(output, "***************** %s *****************\n", out_name);

    count = 1;

    char line[MAX_LENGTH];
    scan_line(line, input, MAX_LENGTH - 3);
    while(line[0] != '\0') {
      fprintf(output, "%d. %s\n", count++, line);
      scan_line(line, input, MAX_LENGTH - 3);
    }

    printf("Data Transfer Complete.\n");
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
