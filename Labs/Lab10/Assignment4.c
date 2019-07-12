/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 10.4

This program takes a postfix expression from the user and evaluates it and prints the result.
Note: All input values must be a single digit and positive to be evaluated correctly.
      The answer and any intermediate values may be more than single digits and negative but they will not be
      displayed correctly if printing them is attempted (unless they are converted to integers and 48 is 
      subtracted from them).
*/

#include <stdio.h>
#include "stack.c"

int get_next_operator(Stack stack);
char get_element(Stack stack, int index);
void set_element(Stack stack, int index, char ch);
void del_element(Stack stack, int index);

int main() {
  int n = 0;

  //Asks user for input
  printf("Enter the number of characters in your expression> ");
  scanf(" %d", &n);

  Stack s;
  s.size = 0;

  //Push input into stack
  printf("Enter full statement> ");
  for(int i = 0; i < n; i++) {
    char e = 'a';
    scanf(" %c", &e);
    push(&s, e);
  }
  int operator_index = -1;

  do {

    operator_index = get_next_operator(s);
    if(operator_index == -1) {
      break;
    }

    char operator = get_element(s, operator_index);
    int operand1 = (int)get_element(s, operator_index - 2) - 48;
    int operand2 = (int)get_element(s, operator_index - 1) - 48;

    int result = 0;

    if(operator == '+') {
      result = operand1 + operand2;
    } else if(operator == '-') {
      result = operand1 - operand2;
    } else if(operator == '*') {
      result = operand1 * operand2;
    } else if(operator == '/') {
      result = operand1 / operand2;
    } else if(operator == '%') {
      result = operand1 % operand2;
    } else {
      printf("ERROR!\n");
    }

    set_element(s, operator_index - 2, (char)(result+48));
    del_element(s, operator_index);
    del_element(s, operator_index - 1);

  } while(operator_index != -1);

  char result = get_element(s, 0);
  printf("Result = %d\n", ((int)result) - 48);

  //print_stack(s);
  return(0);
}

//Precondition:  s is not empty
//Postcondition: Returns the index of the first node with an operator
int get_next_operator(Stack stack) {
  node_t *p = stack.head;
  int count = 0;
  while(p != NULL) {
    char ch = p->element;
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
      return(count);
    }
    count++;
    p = p->next;
  }

  return(-1);
}

//Precondition:  index < size of the stack
//Postcondition: Returns the character at index index of the stack
char get_element(Stack stack, int index) {
  node_t *p = stack.head;
  int count = 0;

  while(count < index) {
    p = p->next;
    count++;
  }

  return(p->element);
}

//Precondition:  index < size of the stack
//Postcondition: Sets the character at index index of the stack to ch
void set_element(Stack stack, int index, char ch) {
  node_t *p = stack.head;
  int count = 0;

  while(count < index) {
    p = p->next;
    count++;
  }

  p->element = ch;
}

//Precondition:  index < size of the stack + 1
//Postcondition: Sets the character at index index of the stack to ch
void del_element(Stack stack,int index) {
  node_t *p = stack.head;
  int count = 0;

  while(count < index - 1) {
    p = p->next;
    count++;
  }
  node_t *d = p->next;
  p->next = p->next->next;

  free(d);
}
