/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 6.5 (Bonus)

This program prints all bit strings that have a given Hamming Distance k from a given bit string s
*/

#include <stdio.h>

#define MAX_LENGTH 100

void print_Hamming(char s1[], char s2[], int k);
void add_one_bin(char s[]);
int find_Hamming_distance(char s1[], char s2[]);

int main() {
  int k = 0;
  char bits[MAX_LENGTH];

  //Asks user for input
  printf("Enter the string of bits> ");
  scanf("%s", bits);
  printf("Enter the value of k> ");
  scanf("%d", &k);

  //find length of string
  int length = 0;
  while(bits[length] != '\0') {
    length++;
  }

  char s[length+1];
  int i = 0;
  for(i = 0; i < length; i++) {
    s[i] = '0';
  }

  s[length] = '\0';


  print_Hamming(bits, s, k);
  printf("\n");

  return(0);
}

//Prints all strings that are Hamming distance of k away from s
void print_Hamming(char s1[], char s2[], int k) {
  if(find_Hamming_distance(s1, s2) == k) {
    printf("%s ", s2);
  }

  int is_end = 1;
  int i = 0;

  //s2 must start at 00... so it ends at 11...
  while(s2[i] != '\0' && is_end) {
    if(s2[i] == '0') {
      is_end = 0;
    }
    i++;
  }

  if(is_end) { //Base Case
    return;
  }

  add_one_bin(s2);
  print_Hamming(s1, s2, k); //Recursive call
}

//Precondition:  s is a string with only values 0 and 1
//Postcondition: manipulates s so thast it becomes 1 + s in binary notation
void add_one_bin(char s[]) {
  //find length of string
  int length = 0;
  while(s[length] != '\0') {
    length++;
  }

  int i = 0;
  while(i < length && s[i] == '1') {
    s[i] = '0';
    i++;
  }
  if(i < length) {
    s[i] = '1';
  }
}

//Precondition:  Length of s1 and s2 are equal
//Postcondition: Returns the Hamming distance between s1 and s2
int find_Hamming_distance(char s1[], char s2[]) {
  int d = 0;
  for(int i = 0; s1[i] != '\0'; i++) {
    if(s1[i] != s2[i]) {
      d++;
    }
  }

  return(d);
}
