/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 2 Bonus 18

This program outputs the frequency of each digit in a given number
*/

#include <stdio.h>
#include <math.h>

int main() {

  int n = 0;

  //Initializing all counting variables
  int zero  = 0;
  int one   = 0;
  int two   = 0;
  int three = 0;
  int four  = 0;
  int five  = 0;
  int six   = 0;
  int seven = 0;
  int eight = 0;
  int nine  = 0;

  //Gets the user input
  printf("What is your number?\n");
  scanf("%d", &n);

  int N = n; //Copy of n
  int digit_num = 0;

  while(N != 0) {
    digit_num++;
    N = N/10;
  }

  N = n;

  for(int i = 0; i < digit_num; i++) {
    if(N%10 == 0) {
      zero++;
    } else if(N%10 == 1) {
      one++;
    } else if(N%10 == 2) {
      two++;
    } else if(N%10 == 3) {
      three++;
    } else if(N%10 == 4) {
      four++;
    } else if(N%10 == 5) {
      five++;
    } else if(N%10 == 6) {
      six++;
    } else if(N%10 == 7) {
      seven++;
    } else if(N%10 == 8) {
      eight++;
    } else if(N%10 == 9) {
      nine++;
    }

    N /= 10;
  }
  //Prints the frequency of each digit
  if(zero != 0) {
    printf("Zero: %d\n", zero);
  }
  if(one != 0) {
    printf("One: %d\n", one);
  }
  if(two != 0) {
    printf("Two: %d\n", two);
  }
  if(three != 0) {
    printf("Three: %d\n", three);
  }
  if(four != 0) {
    printf("Four: %d\n", four);
  }
  if(five != 0) {
    printf("Five: %d\n", five);
  }
  if(six != 0) {
    printf("Six: %d\n", six);
  }
  if(seven != 0) {
    printf("Sevem: %d\n", seven);
  }
  if(eight != 0) {
    printf("Eight: %d\n", eight);
  }
  if(nine != 0) {
    printf("Nine: %d\n", nine);
  }

  return(0);
}
