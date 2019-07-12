/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.4

This program implements the functions to deal with monthly installments.
*/

#include <stdio.h>
#include "monthly_installments.h"
#include <math.h>

#define TABLE_WIDTH 115

//Finds monthly payment based on a given i, p and y
int find_monthly_payment(double i, double p, double y) {
  double m = 0;
  m = (i * p) / (1 - pow(i + 1, -12 * y));

  return((int)ceil(m));
}

//returns the maximum principal based on interest rate, monthly payment and loan term
double max_principal(double i, double m, double y) {
  double p = (m * (1 - pow(i + 1, -12 * y))) / i;
  return(p);
}

//returns the annual interest rate based on principal, monthly payment and loan term
double max_interest(double p, double m, double y) {
  double i = (m * (1 - pow(i + 1, -12 * y))) / p;
  return(12 * i);
}

//Prints amortization table
void print_table(int payment_num, double interest_paid, double principal_paid, double total_due) {
  double rem_balance = total_due - principal_paid;

  printf("\tPayment #\t|\tPayment\t|\tInterest Paid\t|\tPrincipal Paid\t|\tRemaining Balance\n");
  for(int i = 0; i < TABLE_WIDTH; i++) {
    printf("-");
  }
  printf("\n");

  printf("\t%d\t\t|\t%.2lf\t|\t%.2lf\t\t|\t%.2lf\t\t|\t%.2lf\n", payment_num, total_due, interest_paid, principal_paid, rem_balance);
}
