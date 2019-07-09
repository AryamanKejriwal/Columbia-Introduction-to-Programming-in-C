/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 8.1

This program merges the contents of 2 files containing chemical elements sorted by atomic number and combines them into
a third file, ensuring that the third file is also sorted
*/

#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_LENGTH 200

int fill_elements(FILE *input, char array[MAX_ELEMENTS][MAX_LENGTH]);
int merge_array(char arr1[MAX_ELEMENTS][MAX_LENGTH], char arr2[MAX_ELEMENTS][MAX_LENGTH], char arr3[MAX_ELEMENTS][MAX_LENGTH], int l1, int l2);
void fill_file(FILE *output, char arr[MAX_ELEMENTS][MAX_LENGTH], int length);

char *scan_line(char *dest, FILE* input, int dest_len);

int main() {
  char in_name1[MAX_LENGTH];
  char in_name2[MAX_LENGTH];
  char out_name[MAX_LENGTH];

  printf("Enter name of first input file> ");
  scanf("%s", in_name1);
  printf("Enter name of second input file> ");
  scanf("%s", in_name2);
  printf("Enter name of output file> ");
  scanf("%s", out_name);

  FILE *input1 = fopen(in_name1, "r");
  FILE *input2 = fopen(in_name2, "r");
  FILE *output = fopen(out_name, "wb");

  char in1_text[MAX_ELEMENTS][MAX_LENGTH];
  char in2_text[MAX_ELEMENTS][MAX_LENGTH];

  int len1 = fill_elements(input1, in1_text);
  int len2 = fill_elements(input2, in2_text);

  fclose(input1);
  fclose(input2);

  char out_text[MAX_ELEMENTS][MAX_LENGTH];
  int len_out = merge_array(in1_text, in2_text, out_text, len1, len2);

  fill_file(output, out_text, len_out);

  fclose(output);

  printf("Data Successfully transfered.\n");

  printf("Data in binary file:\n");
  output = fopen(out_name, "rb");
  char out_text2[MAX_ELEMENTS][MAX_LENGTH];
  for(int i = 0; i < len_out; i++) {
    fread(out_text2[i], sizeof(char), MAX_LENGTH, output);
    printf("%s", out_text2[i]);
  }

  fclose(output);

  return(0);
}

//Fills the 2d array array with lines from FILE *input
//Returns the length of the array
int fill_elements(FILE *input, char array[MAX_ELEMENTS][MAX_LENGTH]) {
  int len = 0;
  for(int i = 0; i < MAX_ELEMENTS; i++) {
    scan_line(array[i], input, MAX_LENGTH);
    len++;
    if(array[i][0] == '\0') {
      break;
    }
  }

  len--;

  return(len);
}

//Merges the first and second array into the third array and keeps it sorted
////Returns the length of the third array
int merge_array(char arr1[MAX_ELEMENTS][MAX_LENGTH], char arr2[MAX_ELEMENTS][MAX_LENGTH], char arr3[MAX_ELEMENTS][MAX_LENGTH],int l1, int l2) {
  int i1 = 0;
  int i2 = 0;
  for(int i = 0; i < l1 + l2; i++) {
    if(i1 >= l1) {
      strcpy(arr3[i], arr2[i2]);
      i2++;
    } else if(i2 >= l2) {
      strcpy(arr3[i], arr1[i1]);
      i1++;
    } else {
      int a_num1 = 0;
      int a_num2 = 0;
      sscanf(arr1[i1], "%d", &a_num1);
      sscanf(arr2[i2], "%d", &a_num2);
      if(a_num1 < a_num2) {
        strcpy(arr3[i], arr1[i1]);
        i1++;
      } else {
        strcpy(arr3[i], arr2[i2]);
        i2++;
      }
    }
  }

  return(l1 + l2);
}

//Fills output with the values in arr
void fill_file(FILE *output, char arr[MAX_ELEMENTS][MAX_LENGTH], int length) {
  for(int i = 0; i < length; i++) {
    sprintf(arr[i], "%s\n", arr[i]);
    fwrite(arr[i], sizeof(char), MAX_LENGTH, output);
  }
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
