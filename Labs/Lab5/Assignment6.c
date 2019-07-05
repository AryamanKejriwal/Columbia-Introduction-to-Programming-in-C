/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 5.6

This program traverses data line by line and reverses the order of the words
Note: The input and output files must exist.
*/

#include <stdio.h>
#include <string.h>

#define LENGTH 100

void swap_words(char line[]);
char *scan_line(char *dest, FILE* input, int dest_len);
char *substr(char *str, int start_index, int length);

int main() {
  char in_name[100];
  char out_name[100];

  //Asks user for names
  printf("Enter input file name> ");
  scanf("%s", in_name);
  printf("Enter output file name> ");
  scanf("%s", out_name);

  FILE *input  = fopen(in_name, "r");
  FILE *output = fopen(out_name, "w");

  char beg = 'a';
  do {
    char line[1000];
    scan_line(line, input, 1000);

    beg = line[0];

    if(line[0] == '\0') {
      break;
    } else {
      swap_words(line);
    }

    fprintf(output, "%s", line);
  } while(beg != '\0');

  fclose(input);
  fclose(output);

  printf("Data successfully transferred.\n");

  return(0);
}

//Flips the order of of the words in the line
void swap_words(char line[]) {
  char final[1000];
  char words[80][20];

  int count = 0;
  int first_letter  = 0;

  int i = 0;

  while(line[count] != '\0') {
    while(line[count] != ' ' && line[count] != '\0' ) {
      count++;
    }

    char *word = substr(line, first_letter, (count - first_letter));
    for(int j = 0; j < 20; j++) {
      words[i][j] = word[j];
    }

    i++;
    if(line[count] != '\0') {
      count++;
    }
    first_letter = count;
  }

  count = 0;

  for(i = i - 1; i >= 0; i--) {
    for(int j = 0; words[i][j] != '\0'; j++) {
      final[count] = words[i][j];
      count++;
    }
    final[count] = ' ';
    count++;
  }

  final[count] = '\n';
  final[count+1] = '\0';

  for(i = 0; final[i] != '\0'; i++) {
    line[i] = final[i];
  }
  line[i] = '\0';
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
