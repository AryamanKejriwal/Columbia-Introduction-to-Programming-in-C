/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.4

This header file declares functions that deal with monthly loan installments
*/

//Finds monthly payment based on a given i, p and y
extern int find_monthly_payment(double i, double p, double y);

//returns the maximum principal based on interest rate, monthly payment and loan term
extern double max_principal(double i, double m, double y);

//returns the maximum interest rate based on principal, monthly payment and loan term
extern double max_interest(double p, double m, double y);

//Prints amortization table
extern void print_table(int payment_num, double interest_paid, double principal_paid, double total_due);
