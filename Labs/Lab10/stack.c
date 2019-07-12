/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 10.3

This program implements the functions to help manipulate a stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//Precondition:  node is a pointer to the stack
//Postcondition: adds a node containing e to the end of the stack
void push(Stack *stack, char e) {
  node_t *n = stack->head;

  if(n != NULL) {
    while(n->next != NULL) {
      n = n->next;
    }

    n->next = (node_t *)malloc(sizeof(node_t));
    n = n->next;
    n->element = e;
    n->next = NULL;

  } else {
    n = (node_t *)malloc(sizeof(node_t));
    n->element = e;
    n->next = NULL;
    stack->head = n;
  }

  stack->size++;
}

//Precondition:  node is a pointer to the stack
//Postcondition: Removes the last node in the stack and
char pop(Stack *stack) {
  node_t *n = stack->head;
  node_t *previous = n;

  while(n->next != NULL) {
    previous = n;
    n = n->next;
  }
  char e = 'a';
  if(previous != n) {
    e = n->element;
    previous->next = NULL;
  } else {
    e = stack->head->element;
    stack->head = NULL;
  }
  stack->size--;
  return(e);
}

//Precondition:  s is not empty
//Postcondition: Returns the last element in the stack without changing it.
char retrieve(Stack s) {
  node_t *n = s.head;
  while(n->next != NULL) {
    n = n->next;
  }

  return(n->element);
}

//Postcondition: Prints entire stack from head to tail;
void print_stack(Stack s) {
  node_t *n = s.head;
  while(n != NULL) {
    printf("%c", n->element);
    if(n->next != NULL) {
      printf(", ");
    }
    n = n->next;
  }

  printf("\n");
}
