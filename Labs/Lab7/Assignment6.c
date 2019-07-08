/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 7.6

This program defines a structure for a battery and some functions to handle with the battery. The main method tests the
structure with some sample code.
*/

#include <stdio.h>

typedef struct {
  double emf;
  double max_energy;
  double current_energy;
} battery_t;

//Facilitates IO of battery
battery_t scan_battery();
void print_battery(battery_t b);

//Other methods to interact with battery_t
int power_device(double current, double time, battery_t *b);
double max_time(battery_t b, double current);
battery_t recharge(battery_t b);

int main() {
  battery_t battery = {12, 5000000, 5000000};
  int bool = power_device(4, 15 * 60, &battery);
  double t1 = max_time(battery, 8);
  battery = recharge(battery);
  double t2 = max_time(battery, 8);

  printf("Before the recharge, the battery could charge the device for %lf seconds.\n", t1);
  printf("After the recharge, the battery can charge the device for %lf seconds.\n", t2);

  return(0);
}

//Facilitates the input of a battery from stdin
battery_t scan_battery() {
  battery_t b;
  printf("Enter the EMF of the battery> ");
  scanf("%lf", &b.emf);
  printf("Enter the energy capacity of the battery> ");
  scanf("%lf", &b.max_energy);
  printf("Enter the current energy level of the battery> ");
  scanf("%lf", &b.current_energy);

  return(b);
}

//Facilitates output of battery to stdout
void print_battery(battery_t b) {
  printf("The EMF of the battery is %lf.\n", b.emf);
  printf("The energy capacity of the battery is %lf.\n", b.max_energy);
  printf("The current energy level of the battery is %lf.\n", b.current_energy);
}

//subtracts required energy from b if b has enough battery  and returns 1 else does nothing and returns 0
int power_device(double current, double time, battery_t *b) {
  if(max_time(*b, current) >= time) {
    b->current_energy -= b->emf * current * time;
    return(1);
  } else {
    return(0);
  }
}

//Returns the maximum amount of time the battery b can power device with current current fwith its current energy reserves
double max_time(battery_t b, double current) {
  double time = b.current_energy / (b.emf * current);
  return(time);
}

//Sets reserve energy of battery to its maximum capacity
battery_t recharge(battery_t b) {
  b.current_energy = b.max_energy;
  return(b);
}
