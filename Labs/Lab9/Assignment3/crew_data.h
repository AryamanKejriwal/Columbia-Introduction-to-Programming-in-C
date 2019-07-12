/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.3

This header file defines a structure to store data about crews and aircraft cleaning schedules
*/

#define MAX_AIRCRAFTS 50
#define MAX_CREW 100

typedef struct {
  int crew_num;
  int skill_level;
  int cost;
  int busy_time;
} Crew;

typedef struct {
  Crew teams[MAX_CREW];
  int size;
} CrewList;

typedef struct {
  int id;
  int skill_level;
  int hours;
  int crew_num;
} Aircraft;

typedef struct {
  Aircraft aircrafts[MAX_AIRCRAFTS];
  int size;
} Fleet;

//Scans crew data
extern void scan_crew(Crew *input);

//Scans maintenance data
extern void scan_maintenance_data(Aircraft *input);

//Checks maintenance level required against the crew abilities and returns the number of the lowest-cost crew
//that can perform the maintenance.
extern int lowest_time_crew(Aircraft a, CrewList c);

//Checks the maintenance level required against the crew abilities and current schedule and returns
//the number of the qualified crew that will be free to perform the maintenance at the earliest time.
//If more than one crew satisfies the function’s con- straints, the number of the lowest-cost qualified crew is
//returned.
extern void fill_schedule(CrewList c, Fleet *f);

//Accumulates hours required for each crew as each maintenance task is scheduled.
extern void add_hours(Crew *c, int hours);

//Prints the schedule
void print_schedule(Fleet f);
