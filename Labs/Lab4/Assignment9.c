/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4.9

This program plays 2 player hangman. The first player enters the word and the second player has to guess the word
with 8 wrong guess chances. The game is not case sensitive.
*/

#include <stdio.h>
#include <stdlib.h>

#define TOTAL_LETTERS 26
#define MAX_LIVES 8

#define to_upper_case(x) (x) - 'a' + 'A'
#define next_page() printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n") //\f didn't work, hence the macro

char *word;
char *guess_line;
int lives = MAX_LIVES;
char guesses[TOTAL_LETTERS];

int check_validity(int n);
void convert_to_uppercase(int n);
int game_loop(int n);
char print_interface(int n);
void print_arrays(int n);
void print_man();

int main() {

  //fills guesses with *
  for(int i = 0; i <= TOTAL_LETTERS; i++) {
    guesses[i] = '*';
  }

  int n = 0;
  char temp = '\n';

  START:

  //Asks the user for the length of the word
  printf("How many characters are in your word?");
  scanf("%d", &n);

  //Initializes word and guess_line
  word       = malloc(sizeof(char) * n);
  guess_line = malloc(sizeof(char) * n);

  //Asks user for input word
  printf("Enter your word> ");

  //Makes sure that the newline is not stored as a part of the word
  temp = '\n';
  while(temp == '\n') {
    scanf("%c", &temp);
  }
  if(n > 0) {
    word[0] = temp;
  }

  //Actually stores rest of the word in the array.
  for(int i = 1; i < n; i++) {
    scanf("%c", &word[i]);
  }

  for(int i = 0; i < n; i++) {
    guess_line[i] = '_';
  }

  //Makes sure that the input is valid
  int valid = check_validity(n);
  if(!valid) {
    printf("\aThat is not a valid word.\n\n");
    goto START;
  }

  convert_to_uppercase(n);

  //Makes sure that the word is correct
  printf("is your word ");
  for(int i = 0; i < n; i++) {
    printf("%c", word[i]);
  }
  printf("? (y/n)> ");

  //Makes sure that the newline is not stored as a part of the word
  temp = '\n';
  while(temp == '\n') {
    scanf("%c", &temp);
  }
  if(temp != 'y') {
    printf("\n");
    goto START;
  }

  //Loops game_loop until there is a winner
  int winner = 0;
  while(!winner) {
    winner = game_loop(n);
  }

  //Prints the results
  next_page();
  printf("\nHANGMAN\n");
  print_arrays(n);
  print_man();
  if(winner == 1) {
    printf("\nThe word giver wins!\n");
  } else if(winner == 2) {
    printf("\nThe word guesser wins!\n");
  }

  return(0);
}


//Precondition:  word has to be defined, n has to be the length of the word
//Postcondition: Makes sure that word has only letters
int check_validity(int n) {
  for(int i = 0; i < n; i++) {
    char l = word[i];
    if(!((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z'))) {
      return(0);
    }
  }

  return(1);
}


//Precondition:  word has to be defined, n has to be the length of the word
//Postcondition: All of the letters in word that are lowercase will be converted to uppercase
void convert_to_uppercase(int n) {
  for(int i = 0; i < n; i++) {
    if(word[i] >= 'a' && word[i] <= 'z') {
      word[i] = to_upper_case(word[i]);
    }
  }
}


//Precondition:  word has to be defined, n has to be the length of the word
//Postcondition: This method manages each 'frame' of the game
//               If the game is not over, game_loop will return 0. If it is over, it will return the player number who won.
int game_loop(int n) {
  next_page();
  char guess = print_interface(n);

  int is_new_guess = 1;

  //Determines whether the letter has been guessed before or not
  for(int i = 0; i < TOTAL_LETTERS && guesses[i] != '*'; i++) {
    if(guess == guesses[i]) {
      is_new_guess = 0;
    }
  }

  //Deals with the case in which the letter guessed has not been guessed before
  if(is_new_guess) {
    int is_correct = 0;
    for(int i = 0; i < n; i++) {
      if(word[i] == guess) {
        is_correct = 1;
        break;
      }
    }

    //Deals with the case in which the guess is in the word
    if(is_correct) {
      for(int i = 0; i < n; i++) {
        if(word[i] == guess) {
          guess_line[i] = guess;
        }
      }

    //Deals with the case in which the guess is not in the word
    } else {
      lives = lives - 1;
    }

    //replaces the first '*' in guessed with the guessed letter
    int count = 0;
    while(guesses[count] != '*') {
      count++;
    }
    guesses[count] = guess;

  }

  //Checks if the word is done
  int word_complete = 1;
  for(int i = 0; i < n; i++) {
    if(word[i] != guess_line[i]) {
      word_complete = 0;
      break;
    }
  }

  if(word_complete) {
    return(2);
  }

  //Checks if the guesser has run out of lives
  if(lives <= 0) {
    return(1);
  }

  return(0);
}


//Precondition:  word has to be defined, n has to be the length of the word
//Postcondition: Prints Player Interface of the game and returns a valid guess
//               Note: for a guess to be valid, it only has to be a letter. If it has been tried before,
//                     the input will be counted as valid but no lives will be deducted
char print_interface(int n) {

  //prints arrays and man
  printf("\nHANGMAN\n");
  print_arrays(n);
  print_man();

  char guess = '\n';

  //Receives and makes sure that input is valid before returning
  int valid_input = 0;
  while(!valid_input) {
    printf("Enter your guess> ");
    do {
      scanf("%c", &guess);
    } while(guess == '\n');

    if(guess >= 'A' && guess <='Z') {
      valid_input = 1;
    } else if(guess >= 'a' && guess <='z') {
      guess = to_upper_case(guess);
      valid_input = 1;
    }
    if(!valid_input) {
      printf("\aThat was not a valid input.\n");
    }
  }

  return(guess);
}


//Precondition:  guess_line is defined, n is the length of word, * is used correctly as a sentinel for guesses
//Postcondition: prints the blanks and guessed letters
void print_arrays(int n) {
  printf("\n");

  for(int i = 0; i < n; i++) {
    printf("%c", guess_line[i]);
  }

  printf("\n\nGuessed\n[");
  for(int i = 0; i < TOTAL_LETTERS; i++) {
    if(i == TOTAL_LETTERS - 1 || guesses[i+1] == '*') {
      if(guesses[i] != '*') {
       printf("%c]\n", guesses[i]);
     } else {
        printf("]\n");
     }
      break;
    } else {
      printf("%c, ", guesses[i]);
    }
  }
}


//Precondition:  lives is correct
//Postcondition: prints the hanging man at the correct stage
void print_man() {
  if(lives == 8) {
    printf("\n-----\n\n");
  } else if(lives == 7) {
    printf("\n  |\n  |\n  |\n  |\n--+--\n\n");
  } else if(lives == 6) {
    printf("\n  +--\n  |\n  |\n  |\n  |\n--+--\n\n");
  } else if(lives == 5) {
    printf("\n  +--+\n  |  *\n  |\n  |\n  |\n--+--\n\n");
  } else if(lives == 4) {
    printf("\n  +--+\n  |  *\n  |  |\n  |\n  |\n--+--\n\n");
  } else if(lives == 3) {
    printf("\n  +--+\n  |  *\n  | /|\n  |\n  |\n--+--\n\n");
  } else if(lives == 2) {
    printf("\n  +--+\n  |  *\n  | /|\\\n  |\n  |\n--+--\n\n");
  } else if(lives == 1) {
    printf("\n  +--+\n  |  *\n  | /|\\\n  | /\n  |\n--+--\n\n");
  } else {
    printf("\n  +--+\n  |  *\n  | /|\\\n  | / \\\n  |\n--+--\n\n");
  }
}
