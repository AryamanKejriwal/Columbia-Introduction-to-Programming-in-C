/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.1

This header file defines a structure to store high precision numbers. It also contains functions to add, subtract
and multiply high precision numbers. scan_high() and print_high() are functions that facilitate I/O.
*/

#define PRECISION 5

typedef struct {
  int digits[PRECISION];
  int decpt;
  int sign;
} high_precision_t;

//Calculates and returns the sum of 2 high precision numbers
extern high_precision_t add_high(high_precision_t n1, high_precision_t n2);

//Calculates and returns the difference between 2 high precision numbers
extern high_precision_t subtract_high(high_precision_t n1, high_precision_t n2);

//Calculates and returns the product of 2 high precision numbers
extern high_precision_t multiply_high(high_precision_t n1, high_precision_t n2);

//Multiplied high_precision with an integer
extern high_precision_t multiply_long(high_precision_t n1, long n2);

//Multiplies hiogh_precision by 10 to the power n2
extern high_precision_t multiply_pow_10(high_precision_t n1, int n2);

//Gets rid of all leading 0s and changes decimal point accordingly
extern void shift_digits(high_precision_t *n);

//Returns -1 if the number's digits are valid, otherwise returns the index of the first invalid index
extern int digits_valid(high_precision_t n);

//Returns 1 if the numbers are equal, otherwise returns 0
//Ignores sign
extern int equals_high(high_precision_t n1, high_precision_t n2);

//Returns the larger of the 2 high precision numbers
//Ignores sign
extern high_precision_t larger(high_precision_t n1, high_precision_t n2);

//Scans high precision number from stdin
extern high_precision_t scan_high();

//Prints high precision number from stdin
extern void print_high(high_precision_t num);
