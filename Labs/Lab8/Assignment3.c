/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 8.3

This program converts normal representation to concise representation and vice versa of sparse array.
Note: If a non zero element in not present in the row, the index is set to row_num -1 and the value is set to -1
*/

#include <stdio.h>

#define MAX 100
#define MAX_SPACE 200

void scan_matrix(FILE *input, int array[MAX_SPACE][MAX_SPACE], int l, int w);
void write_sparse(FILE *output, int array[MAX_SPACE][MAX_SPACE], int l, int w);

void scan_sparse(FILE *input, int array[MAX_SPACE][MAX_SPACE], int l, int w);
void write_matrix(FILE *output, int array[MAX_SPACE][MAX_SPACE], int l, int w);

char *scan_line(char *dest, FILE* input, int dest_len);

int main() {
  int choice = 0;
  printf("What do you want the input file format to be?\n1. Normal Representation\n2. Concise Representation\n\nEnter choice> ");
  scanf("%d", &choice);

  char in_name[MAX];
  char out_name[MAX];

  printf("Enter name of input file> ");
  scanf("%s", in_name);
  printf("Enter name of output file> ");
  scanf("%s", out_name);

  FILE *input = fopen(in_name, "r");
  FILE *output = fopen(out_name, "w");

  char line[MAX];
  scan_line(line, input, MAX);
  int l = 0; int w = 0;
  sscanf(line, "%d%d", &l, &w);

  int array[MAX_SPACE][MAX_SPACE];

  if(choice == 1 && !(l > MAX_SPACE) && !(w > MAX_SPACE)) {
    scan_matrix(input, array, l, w);
    write_sparse(output, array, l, w);
    printf("The data was successfully converted and transferred.\n");
  } else if(choice == 2 && !(l > MAX_SPACE) && !(w > MAX_SPACE)) {
    scan_sparse(input, array, l, w);
    write_matrix(output, array, l, w);
    printf("The data was successfully converted and transferred.\n");
  } else {
    if(choice != 1 && choice != 2) {
      printf("That is not a valid choice.\n");
    }
    if((l > MAX_SPACE) || (w > MAX_SPACE)) {
      printf("The given array is too big.\n");
    }
  }

  fclose(input);
  fclose(output);
  return(0);
}

//Reads Normal Representation of matrix from input file
void scan_matrix(FILE *input, int array[MAX_SPACE][MAX_SPACE], int l, int w) {
  for(int i = 0; i < l; i++) {
    for(int j = 0; j < w; j++) {
      fscanf(input, "%d", &array[i][j]);
    }
  }
}

//Writes matrix in Sparse Representation in output file
void write_sparse(FILE *output, int array[MAX_SPACE][MAX_SPACE], int l, int w) {
  fprintf(output, "%d %d\n", l, w);
  for(int i = 0; i < l; i++) {
    int placed = 0;
    for(int j = 0; j < w && !placed; j++) {
      //fprintf(output, "%d ", array[i][j]);
      if(array[i][j] != 0) {
        placed = 1;
        fprintf(output, "%d %d %d", i, j, array[i][j]);
      }
    }

    if(!placed) {
      fprintf(output, "%d -1 -1", i);
    }
    fprintf(output, "\n");
  }
}


//Reads Sparse Representation of matrix from input file
void scan_sparse(FILE *input, int array[MAX_SPACE][MAX_SPACE], int l, int w) {
  for(int i = 0; i < l; i++) {
    for(int j = 0; j < w; j++) {
      array[i][j] = 0;
    }
  }

  for(int i = 0; i < l; i++) {
    int x = 0; int y = 0; int val = 0;
    fscanf(input, "%d %d %d", &x, &y, &val);
    if(y != -1) {
      array[x][y] = val;
    }
  }
}

//Writes matrix in Normal Representation in output file
void write_matrix(FILE *output, int array[MAX_SPACE][MAX_SPACE], int l, int w) {
  fprintf(output, "%d %d\n", l, w);
  for(int i = 0; i < l; i++) {
    for(int j = 0; j < w; j++) {
      fprintf(output, "%d ", array[i][j]);
    }
    fprintf(output, "\n");
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
