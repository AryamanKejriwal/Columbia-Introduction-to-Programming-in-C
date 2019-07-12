/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.3

This program implements the functions to deal with crew data.
*/

#include <stdio.h>
#include "crew_data.h"

#define TABLE_SIZE 103

//Scans crew data
void scan_crew(Crew *input) {
  printf("Enter Crew Id> ");
  scanf("%d", &(input->crew_num));
  printf("Enter Crew Skill Level> ");
  scanf("%d", &(input->skill_level));
  printf("Enter Crew Cost> ");
  scanf("%d", &(input->cost));
  input->busy_time = 0;
}

//Scans maintenance data
void scan_maintenance_data(Aircraft *input) {
  printf("Enter Aircraft Id> ");
  scanf("%d", &(input->id));
  printf("Enter Required Skill Level> ");
  scanf("%d", &(input->skill_level));
  printf("Enter Required No. of Hours> ");
  scanf("%d", &(input->hours));
}

//Checks maintenance level required against the crew abilities and returns the number of the lowest-time crew
//that can perform the maintenance. if there are multiple crew that fit the criteria, the crew with lowest cost
//is returned. If there is no such crew, -1 is returned.
int lowest_time_crew(Aircraft a, CrewList c) {
  CrewList c2;
  c2.size = 0;

  //Filter for skill level
  for(int i = 0; i < c.size; i++) {
    if(c.teams[i].skill_level >= a.skill_level) {
      c2.teams[c2.size].crew_num = c.teams[i].crew_num;
      c2.teams[c2.size].skill_level = c.teams[i].skill_level;
      c2.teams[c2.size].cost = c.teams[i].cost;
      c2.teams[c2.size].busy_time = c.teams[i].busy_time;
      c2.size++;
    }
  }

  if(c2.size != 0) {
    CrewList c3;
    c3.teams[0].crew_num    = c2.teams[0].crew_num;
    c3.teams[0].skill_level = c2.teams[0].skill_level;
    c3.teams[0].cost        = c2.teams[0].cost;
    c3.teams[0].busy_time   = c2.teams[0].busy_time;
    c3.size = 1;

    //Filter for hours
    for(int i = 0; i < c2.size; i++) {
      if(c2.teams[i].busy_time < c3.teams[c3.size - 1].busy_time) {
        c3.teams[0].crew_num    = c2.teams[i].crew_num;
        c3.teams[0].skill_level = c2.teams[i].skill_level;
        c3.teams[0].cost        = c2.teams[i].cost;
        c3.teams[0].busy_time   = c2.teams[i].busy_time;
        c3.size = 1;
      } else if(c2.teams[i].busy_time == c3.teams[c3.size - 1].busy_time) {
        c3.teams[c3.size].crew_num    = c2.teams[i].crew_num;
        c3.teams[c3.size].skill_level = c2.teams[i].skill_level;
        c3.teams[c3.size].cost        = c2.teams[i].cost;
        c3.teams[c3.size].busy_time   = c2.teams[i].busy_time;
        c3.size += 1;
      }
    }

    if(c3.size > 1) {
      //filter for Cost
      Crew crew;
      crew.crew_num    = c3.teams[0].crew_num;
      crew.skill_level = c3.teams[0].skill_level;
      crew.cost        = c3.teams[0].cost;
      crew.busy_time   = c3.teams[0].busy_time;

      for(int i = 0; i < c3.size; i++) {
        if(crew.cost > c3.teams[i].cost) {
          crew.crew_num    = c3.teams[i].crew_num;
          crew.skill_level = c3.teams[i].skill_level;
          crew.cost        = c3.teams[i].cost;
          crew.busy_time   = c3.teams[i].busy_time;
        }
      }

      return(crew.crew_num);
    } else {
      return(c3.teams[0].crew_num);
    }
  } else {
    return(-1);
  }
}

//Checks the maintenance level required against the crew abilities and current schedule and returns
//the number of the qualified crew that will be free to perform the maintenance at the earliest time.
//If more than one crew satisfies the function’s constraints, the number of the lowest-cost qualified crew is
//returned. The entire schedule is filled
void fill_schedule(CrewList c, Fleet *f) {
  for(int i = 0; i < f->size; i++) {
    int crew_num = lowest_time_crew(f->aircrafts[i], c);
    if(crew_num != -1) {
      f->aircrafts[i].crew_num = crew_num;
    } else {
      printf("There are no crew of the required level for aircraft #%d.\n", f->aircrafts[i].id);
      f->aircrafts[i].crew_num = crew_num;
      continue;
    }
    for(int j = 0; j < c.size; j++) {
      if(c.teams[j].crew_num == crew_num) {
        add_hours(&(c.teams[j]), f->aircrafts[i].hours);
        break;
      }
    }
  }
}

//Accumulates hours required for each crew as each maintenance task is scheduled.
void add_hours(Crew *c, int hours){
  c->busy_time += hours;
}

//Prints the schedule
void print_schedule(Fleet f) {
  printf("Aircraft ID\t|\tLevel of Maintenance\t|\tNumber of Hours\t|\tMaintenance Crew Number\n");
  for(int i = 0; i < TABLE_SIZE; i++) {
    printf("-");
  }
  printf("\n");

  for(int i = 0; i < f.size; i++) {
    printf("%4d\t\t|", f.aircrafts[i].id);
    printf("\t\t%1d\t\t|", f.aircrafts[i].skill_level);
    printf("\t\t%2d\t|", f.aircrafts[i].hours);
    if(f.aircrafts[i].crew_num != -1) {
      printf("\t\t%2d\n", f.aircrafts[i].crew_num);
    } else {
      printf("\t\tNA\n");
    }
  }

  printf("\n");
}

//Tests functions
int main() {
  CrewList list;
  list.size = 0;
  Fleet schedule;

  int crew = 0;
  printf("Enter number of crew> ");
  scanf("%d", &crew);

  for(int i = 0; i < crew; i++) {
    printf("Data for crew #%d:\n", (i+1));
    scan_crew(&(list.teams[i]));
    list.size++;
    printf("\n");
  }

  int entries = 0;
  printf("Enter number of entries in schedule> ");
  scanf("%d", &entries);

  for(int i = 0; i < entries; i++) {
    printf("Data for entry #%d:\n", (i+1));
    scan_maintenance_data(&(schedule.aircrafts[i]));
    schedule.size++;
    printf("\n");
  }

  fill_schedule(list, &schedule);

  print_schedule(schedule);
  return(0);
}
