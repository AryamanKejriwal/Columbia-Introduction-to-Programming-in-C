/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 7.2

This program defines a type catelog_entry_t and stores and displays data for an instance of an entry (book)
*/

#include <stdio.h>

#define MAX_AUTHORS 10
#define MAX_NAME 100
#define MAX_TITLE 100

typedef struct {
  char title[MAX_NAME];
  char publisher[MAX_NAME];
  int publication_year;
  char authors[MAX_AUTHORS][MAX_NAME];
} catelog_entry_t;

int main() {
  catelog_entry_t book;
  int n = 0;
  int index = 0;

  //Gets user input
  printf("Enter number of authors (has to be less than %d)> ", MAX_AUTHORS);
  scanf("%d", &n);
  getchar();

  for(int i = 0; i < n; i++) {
    printf("Enter name of author %d> ", i+1);
    fgets(book.authors[i], MAX_NAME, stdin);

    while(book.authors[i][index] != '\n' && index < MAX_NAME) {
      index++;
    }
    book.authors[i][index] = '\0';
  }

  index = 0;

  char title[MAX_NAME];
  char publisher[MAX_NAME];
  int publication_year = 0;

  printf("Enter title> ");
  fgets(book.title, MAX_NAME, stdin);
  while(book.title[index] != '\n' && index < MAX_NAME) {
    index++;
  }
  book.title[index] = '\0';
  index = 0;

  printf("Enter publisher> ");
  fgets(book.publisher, MAX_NAME, stdin);
  while(book.publisher[index] != '\n' && index < MAX_NAME) {
    index++;
  }
  book.publisher[index] = '\0';
  index = 0;

  printf("Enter publication year> ");
  scanf("%d", &book.publication_year);

  //Stores data
  //catelog_entry_t book = {title, publisher, publication_year, authors};

  //Prints Data
  printf("Author(s): ");
  for(int i = 0; i < n; i++) {
    printf("%s", book.authors[i]);
    if(i != n - 1) {
      printf(", ");
    }
  }
  printf("\n");
  printf("Title: %s\n", book.title);
  printf("Publisher: %s\n", book.publisher);
  printf("Publication Year: %d\n", book.publication_year);

  return(0);
}
