/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 7.5

This program defines a structure to store data in a transformer and methods to input and output values
and to change values base on desired output voltage and current
*/

#include <stdio.h>

typedef struct {
  double n1;
  double n2;
  double v1;
  double i1;
} transformer_t;

//Functions to compute transformer output
double v_out(transformer_t t);
double i_out(transformer_t t);

//Functions to set parts of the transformer to get a desired output
transformer_t set_n1_for_v2(transformer_t t, double v2);
transformer_t set_v1_for_v2(transformer_t t, double v2);
transformer_t set_n2_for_v2(transformer_t t, double v2);
transformer_t set_n2_for_i2(transformer_t t, double i2);

//Functions to facilitate IO
transformer_t scan_transformer();
void print_transformer(transformer_t t);

int main() {
  transformer_t t = scan_transformer();
  print_transformer(t);
  return(0);
}

//Computes and returns output voltage from transformer
double v_out(transformer_t t) {
  return(t.v1 * t.n2 / t.n1);
}

//Computes and returns output current from transformer
double i_out(transformer_t t) {
  return(t.i1 * t.n1 / t.n2);
}

//Sets number of primary coils n1 to get a secondary voltage v2
transformer_t set_n1_for_v2(transformer_t t, double v2) {
  t.n1 = t.v1 * t.n2 / v2;
  return(t);
}

//Sets primary voltage v1 to get a secondary voltage v2
transformer_t set_v1_for_v2(transformer_t t, double v2) {
  t.v1 = v2 * t.n1 / t.n2;
  return(t);
}

//Sets number of secondary coils n2 to get a secondary voltage v2
transformer_t set_n2_for_v2(transformer_t t, double v2) {
  t.n2 = v2 * t.n1 / t.v1;
  return(t);
}

//Sets number of secondary coils n2 to get a secondary current i2
transformer_t set_n2_for_i2(transformer_t t, double i2) {
  t.n2 = t.n1 * t.i1 / i2;
  return(t);
}

//Faciliitates input of scanner from stdin.
transformer_t scan_transformer() {
  transformer_t t;

  printf("Enter primary number of coils> ");
  scanf("%lf", &t.n1);
  printf("Enter secondary number of coils> ");
  scanf("%lf", &t.n2);
  printf("Enter primary voltage> ");
  scanf("%lf", &t.v1);
  printf("Enter primary current> ");
  scanf("%lf", &t.i1);

  return(t);
}

//Prints the details of the scanner to stdout (including secondary voltage and current)
void print_transformer(transformer_t t) {
  printf("\t\tPrimary\t|\tSecondary\n");
  printf("Coils:\t\t%.2lf\t|\t%.2lf\n", t.n1, t.n2);
  printf("Voltage:\t%.2lf\t|\t%.2lf\n", t.v1, v_out(t));
  printf("Current:\t%.2lf\t|\t%.2lf\n", t.i1, i_out(t));
}
