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
void print_table(double principal, double i, int num_months) {
  double monthly_payment = find_monthly_payment(i/12.0, principal, num_months / 12.0);
  double rem_balance = principal;
  int payment_num = 1;

  printf("\tPayment #\t|\tPayment\t|\tInterest Paid\t|\tPrincipal Paid\t|\tRemaining Balance\n");
  for(int i = 0; i < TABLE_WIDTH; i++) {
    printf("-");
  }

  printf("\n");
  for(int j = 0; j < num_months; j++) {
    double interest = (i * rem_balance)/12.0;
    double principal_paid = monthly_payment - interest;
    rem_balance = rem_balance - monthly_payment;
    if(j == num_months - 1) {
      principal_paid = principal_paid + rem_balance;
      monthly_payment = monthly_payment + rem_balance;
      rem_balance = 0;
    }
    printf("\t%d\t\t|\t%.2lf\t|\t%.2lf\t\t|\t%.2lf\t\t|\t%.2lf\n", payment_num, monthly_payment, interest, principal_paid, rem_balance);
    payment_num++;
  }
  printf("\n");
}
