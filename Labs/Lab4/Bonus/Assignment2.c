/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 4 Bonus 2

This program assists with the calculations of intravenous rates.
*/

/*
INTRAVENOUS RATE ASSISTANT
Enter the number of the problem you wish to GIVEN A MEDICAL ORDER IN
(1) ml/hr & tubing drop factor
(2) 1 L for n hr
(3) mg/kg/hr & concentration in mg/ml
(4) units/hr & concentration in units/ml
(5) QUIT
Problem>
*/

#include <stdio.h>
#include <math.h>

int get_problem();
void get_rate_drop_factor();
void get_kg_rate_conc();
void get_units_conc();
int fig_drops_min(double, double);
int fig_ml_hr(double);
int by_weight(double, double, double);
int by_units(double, double);

int main() {
  int choice = get_problem();

  while(choice != 5) {

    //Chooses what to do based on problem number
    switch(choice) {
      case 1: get_rate_drop_factor();
              break;

      case 2: printf("Enter number of hours=> ");
              double hours = 0;
              scanf("%lf", &hours);

              int rate = fig_ml_hr(hours);
              printf("The rate in milliliters per hour is %d.\n", rate);
              break;

      case 3: get_kg_rate_conc();
              break;

      case 4: get_units_conc();
              break;

      default: printf("That is not valid input.\n");
               break;
    }

    printf("\n\n\n");

    choice = get_problem();
  }

  printf("Quitting Program.\n");
}

//Precondition:  -
//Postcondition: Displays the menu and returns the problem number selected by the user
int get_problem() {
  printf("INTRAVENOUS RATE ASSISTANT\nEnter the number of the problem you wish to solve\n");
  printf("\tGIVEN A MEDICAL ORDER IN\t\tCALCULATE RATE IN\n");
  printf("(1)\tml/hr & tubing drop factor\t\tdrops / min\n");
  printf("(2)\t1 L for n hr\t\t\t\tml / hr\n");
  printf("(3)\tmg/kg/hr & concentration in mg/ml\tml / hr\n");
  printf("(4)\tunits/hr & concentration in units/ml\tml / hr\n");
  printf("(5)\tQUIT\n");
  printf("Problem> ");

  int c = 0;
  scanf("%d", &c);

  return(c);
}

//Precondition:  -
//Postcondition: Gets user data for problem 1 and prints answer
void get_rate_drop_factor() {
  double rate = 0;
  double drop_factor = 0;

  //Gets user input
  printf("Enter rate in ml/hr=> ");
  scanf("%lf", &rate);
  printf("Enter tubing's drop factor(drops/ml)=> ");
  scanf("%lf", &drop_factor);

  printf("The drop rate per minute is %d.\n", fig_drops_min(rate, drop_factor));
}

//Precondition:  -
//Postcondition: Gets user data for problem 3 and prints answer
void get_kg_rate_conc() {
  double rate = 0;
  double weight = 0;
  double concentration = 0;

  printf("Enter rate in mg/kg/hr=> ");
  scanf("%lf", &rate);
  printf("Enter patient weight in kg=> ");
  scanf("%lf", &weight);
  printf("Enter concentration in mg/ml=> ");
  scanf("%lf", &concentration);

  printf("The rate in milliliters per hour is %d.\n", by_weight(rate, weight, concentration));
}

//Precondition:  -
//Postcondition: Gets user data for problem 4 and prints answer
void get_units_conc() {
  double rate = 0;
  double concentration = 0;

  printf("Enter rate in units/hr=> ");
  scanf("%lf", &rate);
  printf("Enter concentration in units/ml=> ");
  scanf("%lf", &concentration);
  printf("The rate in milliliters per hour is %d.", by_units(rate, concentration));
}

//Precomdition:  Rate and drop Factor need to be correct
//Postcondition: Returns the drops per minute
int fig_drops_min(double rate, double drop_factor) {
  return(round(rate * drop_factor / 60.0));
}

//Precondition:  Input is the number of hours in which one litre is to be delivered
//Postcondition: Returns rate of drop in ml / hr
int fig_ml_hr(double hours) {
  return(round(1000.0 / hours));
}

//Precondition:  All parameters are accurate
//Postcondition: Returns rate in ml / hr
int by_weight(double rate, double patient_weight, double concentration) {
  return(round(rate * patient_weight / concentration));
}

//Precondition:  All parameters are accurate
//Postcondition: Returns rate in ml / hr
int by_units(double rate, double concentration) {
  return(round(rate / concentration));
}
