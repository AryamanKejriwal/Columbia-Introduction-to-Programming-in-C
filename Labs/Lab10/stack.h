/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 10.3

This header file defines a structure store and manipulate a stack
(Linked List Implementation)
*/

typedef struct node_s {
  char element;
  struct node_s *next;
} node_t;

typedef struct {
  node_t *head;
  int size;
} Stack;

//Precondition:  node is a pointer to the stack
//Postcondition: adds a node containing e to the end of the stack
extern void push(Stack *stack, char e);

//Precondition:  node is a pointer to the stack
//Postcondition: Removes the last node in the stack and
extern char pop(Stack *stack);

//Precondition:  s is not empty
//Postcondition: Returns the last element in the stack without changing it.
extern char retrieve(Stack s);

//Postcondition: Prints entire stack from head to tail;
extern void print_stack(Stack s);
