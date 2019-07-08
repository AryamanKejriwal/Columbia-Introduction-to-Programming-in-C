/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 7.4

This program defines a structure word_list that contains information such as language, number of words and
the words themselves. It also defines methods that can be used to manipulate the list.
*/

#include <stdio.h>
#include <string.h>

#define WORD_LENGTH 21 //One extra space for the null character at the end of the string
#define MAX_WORDS 100

typedef struct {
  char language[WORD_LENGTH];
  int length;
  char words[MAX_WORDS][WORD_LENGTH];
} word_list;

word_list load_word_list(FILE *input, word_list destination);
word_list add_word(char word[], word_list list);
int contains(char word[], word_list list);
int equal_lists(word_list l1, word_list l2);
void display_word_list(word_list list);
char *scan_line(char *dest, FILE *input, int dest_len);

int main() {
  word_list l1;
  char file_name[MAX_WORDS];
  printf("Enter input file name> ");
  scanf("%s", file_name);
  FILE *input = fopen(file_name, "r");

  l1 = load_word_list(input, l1);

  //Instantiates second list
  word_list l2;
  l2.length = 0;
  printf("Enter a language for a new list> ");
  scanf(" %s", l2.language);
  for(int i = 0; i < 12; i++) {
    char word[WORD_LENGTH];
    printf("Enter word number %d > ", i+1);
    scanf(" %s", word);

    l2 = add_word(word, l2);
  }

  //Checks users words in old list
  int n = 0;
  printf("Enter the number of words you want to look for> ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    char word[WORD_LENGTH];
    printf("Enter the word> ");
    scanf(" %s", word);
    if(contains(word, l1)) {
      printf("The first list contains %s.\n", word);
    } else {
      printf("The first list does not contain %s.\n", word);
    }
  }

  //Prints whether the lists are equal
  if(equal_lists(l1, l2)) {
    printf("The list you entered is the same as the list initialized from the input file.\n");
  } else {
    printf("The list you entered is not the same as the list initialized from the input file.\n");
  }

  //Prints both lists
  printf("\nList 1:\n");
  display_word_list(l1);
  printf("\nList 2:\n");
  display_word_list(l2);
  return(0);
}

//Loads word from an input file into a given word list
word_list load_word_list(FILE *input, word_list destination) {
  //Fills language from file
  int count = 0;
  char line[WORD_LENGTH];
  scan_line(line, input, WORD_LENGTH);
  while(line[count] != '\0') {
    destination.language[count] = line[count];
    count++;
  }
  destination.language[count] = '\0';

  //Fills word from file
  char beg = 'a';
  do {
    char word[WORD_LENGTH];

    scan_line(word, input, WORD_LENGTH);

    beg = word[0];

    if(word[0] == '\0') {
      break;
    } else {
      if(!contains(word, destination)) {
        destination = add_word(word, destination);
      }
    }
  } while(beg != '\0');

  return(destination);
}

//Add word to list if it is not full. If list is full,m prints an error. If word is already present in list,
//doesn't change list
word_list add_word(char word[], word_list list) {
  if(list.length >= MAX_WORDS) {
    printf("List full, %s not added.\n", word);
  } else if(!contains(word, list)) {
    for(int i = 0; i < WORD_LENGTH; i++) {
      list.words[list.length][i] = word[i];
    }
    list.length++;
  }

  return(list);
}

//Checks whether there is at least one occurance of word in list
int contains(char word[], word_list list) {
  for(int i = 0; i < list.length; i++) {
    if(strcmp(list.words[i], word) == 0) {
      return(1);
    }
  }

  return(0);
}

//checks if the language, length, and words in each list are the same
//Note: Order of the word does not matter
int equal_lists(word_list l1, word_list l2) {
  if(strcmp(l1.language, l2.language) == 0 && l1.length == l2.length) {
    for(int i = 0; i < l1.length; i++) {
      if(!contains(l1.words[i], l2)) {
        return(0);
      }
    }
    return(1);
  } else {
    return(0);
  }
}

//Prints all words in list in a four column table
void display_word_list(word_list list) {
  for(int i = 0; i < list.length; i++) {
    printf("%s\t", list.words[i]);
    if((i + 1)  % 4 == 0) {
      printf("\n");
    }
  }

  printf("\n");
}

//Authored by Mr. Pajela
/* * Gets one line of data from input. Returns an empty string on * end of file. If data line will not fit in allotted space, stores * portion that does fit and discards rest of input line. */
char *scan_line(char *dest, FILE *input, int dest_len) {
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
