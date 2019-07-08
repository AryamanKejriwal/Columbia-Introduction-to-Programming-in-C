/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 7.3

This program gets the position of a bishop on an otherwise empty chess board and prints all its possible
positions in one move.
*/

#include <stdio.h>

#define abs(x) ((x) < 0) ? -(x) : (x)

typedef struct {
  char col;
  int row;
} Position;

int is_valid_pos(Position pos);
void print_moves_bishop(Position bishop);

int main() {
  Position bishop;

  //Asks user for input
  printf("Enter the column letter of the bishop (in lowercase) > ");
  scanf("%c", &bishop.col);
  printf("Enter the row number of the bishop> ");
  scanf("%d", &bishop.row);

  if(is_valid_pos(bishop)) {
    print_moves_bishop(bishop);
  } else {
    printf("That is not a valid move.\n");
  }
  return(0);
}

//Checks whether the position is valid or not and returns 1  if it is valid and 0 if it is invalid
int is_valid_pos(Position pos) {
  return(pos.col >= 'a' && pos.col <= 'h' && pos.row >= 1 && pos.row <= 8);
}

//Loops through all possible positions and prints the positions in which the bishop can move
void print_moves_bishop(Position bishop) {
  for(char x = 'a'; x <= 'h'; x = (char)(x + 1)) {
    for(int y = 1; y <= 8; y++) {
      if((x - y == bishop.col - bishop.row || x + y == bishop.col + bishop.row) && bishop.col != x) {
        printf("%c%d ", x, y);
      }
    }
  }

  printf("\n");
}
