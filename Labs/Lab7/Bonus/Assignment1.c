/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 7 Bonus 1

This program defines a structure auto_t to model a car and defines methods to facilitate input and output.
A driver function reads and displays cars from a file.
*/

#include <stdio.h>
#include <math.h>

#define MAX_ARRAY 100

typedef struct {
  int day;
  int month;
  int year;
} date_t;

typedef struct {
  double capacity;
  double fuel_level;
} tank_t;

typedef struct {
  char make[MAX_ARRAY];
  char model[MAX_ARRAY];
  double odometer_reading;
  date_t manufacture_date;
  date_t purchase_date;
  tank_t gas_tank;
} auto_t;


date_t scan_date(char input[], int n);
tank_t scan_tank(char input[]);
auto_t scan_auto(char input[]);
void print_date(date_t d);
void print_tank(tank_t t);
void print_auto(auto_t a);

char *scan_line(char *dest, FILE* input, int dest_len);


//Loops through each line of the input file and stores and prints the auto data
int main() {
  //auto_t auto;
  char in_name[MAX_ARRAY];
  printf("Enter the input file name> ");
  scanf("%s", in_name);

  FILE *input = fopen(in_name, "r");
  if(input == NULL) {
    printf("Sorry, the file could not be opened.\n");
  }

  char line[MAX_ARRAY];
  scan_line(line, input, MAX_ARRAY);
  char beg = line[0];
  int i = 1;

  while(beg != EOF && beg != '\0') {
    auto_t a = scan_auto(line);

    printf("Auto Number %d:\n", i);
    print_auto(a);

    i++;

    scan_line(line, input, MAX_ARRAY);
    beg = line[0];
  }

  return(0);
}

//Scans date from a given input line
date_t scan_date(char input[], int n) {
  date_t d;
  char str[MAX_ARRAY];
  double x = 0;
  if(n == 1) {
    sscanf(input, "%s%s%lf%d%d%d", str, str, &x, &d.month, &d.day, &d.year);
  } else {
    sscanf(input, "%s%s%lf%d%d%d%d%d%d", str, str, &x, &d.month, &d.day, &d.year, &d.month, &d.day, &d.year );
  }

  return(d);
}

//Scans Tank information from a given input line
tank_t scan_tank(char input[]) {
  tank_t t;
  char str[MAX_ARRAY];
  double x;
  int d;
  sscanf(input, "%s%s%lf%d%d%d%d%d%d%lf%lf", str, str, &x, &d, &d, &d, &d, &d, &d, &t.capacity, &t.fuel_level);

  return(t);
}

//Scans an auto from an input line
auto_t scan_auto(char input[]) {
  auto_t a;
  sscanf(input, "%s%s%lf", a.make, a.model, &a.odometer_reading);

  a.manufacture_date = scan_date(input, 1);
  a.purchase_date = scan_date(input, 2);

  a.gas_tank = scan_tank(input);

  return(a);

}

//Prints the values stored in the argument date_t d
void print_date(date_t d) {
  printf("%2d/%2d/%4d\n", d.month, d.day, d.year);
}

//Prints the values stored in the argument tank_t t
void print_tank(tank_t t) {
  printf("\tCapacity: %.3lf gallons\n\t\tFuel Level: %.3lf gallons\n", t.capacity, t.fuel_level);
}

//Prints the values stored in the argument auto_t a
void print_auto(auto_t a) {
  printf("Make: %s\n", a.make);
  printf("Model: %s\n", a.model);
  printf("Odometer Reading: %.2lf\n", a.odometer_reading);
  printf("Manufacture Date: "); print_date(a.manufacture_date);
  printf("Purchase Date: "); print_date(a.purchase_date);
  printf("Gas Tank Data: "); print_tank(a.gas_tank);
}

//Authored by Mr. Pajela
/* * Gets one line of data from input. Returns an empty string on * end of file. If data line will not fit in allotted space, stores * portion that does fit and discards rest of input line. */
char *scan_line(char *dest, FILE* input, int dest_len) {
  int i, ch;  /* Gets next line one character at a time. */
  i = 0;
  for (ch = getc(input); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getc(input)) {
    dest[i++] = ch;
  }
  dest[i] = '\0';  /* Discards any characters that remain on input line */
  while (ch != '\n' && ch != EOF) {
    ch = getc(input);
  }
  return(dest);
}
