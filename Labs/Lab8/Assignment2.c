/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 8.2

This program reads airplane data from a database of a binary file and allows the user to search by different parameters.

Example of format of file:
SR-71 Blackbird
3500
16.95 32.74 M
high-speed strategic reconnaissance

EF-111A Raven
2280
19.21 23.16 M
electronic warfare

Concorde
2140
25.61 62.2 C
supersonic airliner
*/

#include <stdio.h>
#include <string.h>

#define MAX_NAME 25
#define MAX_DESC 80
#define MAX_AIRCRAFTS 150

typedef struct {
  char name[MAX_NAME];
  double max_cruise_speed;
  double wingspan;
  double length;
  char type;
  char description[MAX_DESC];
} Aircraft;

typedef struct {
  Aircraft aircrafts[MAX_AIRCRAFTS];
  int size;
} Fleet;

void print_aircraft(Aircraft a);
void print_fleet(Fleet f);
void filter_fleet(Fleet f, int choice, Fleet *output);

void filter_by_name(Fleet f, Fleet *output);
void filter_by_speed(Fleet f, Fleet *output);
void filter_by_wingspan(Fleet f, Fleet *output);
void filter_by_length(Fleet f, Fleet *output);
void filter_by_type(Fleet f, Fleet *output);

void copy_aircraft(Aircraft source, Aircraft *target);

char *scan_line(char *dest, FILE* input, int dest_len);
char *scan_line_stdin(char *dest, int dest_len);

int main() {
  Fleet fleet;
  fleet.size = 0;

  char db_name[MAX_DESC];
  printf("Enter the name of the Database> ");
  scanf("%s", db_name);

  FILE *db = fopen(db_name, "rb");

  char line[MAX_DESC];
  scan_line(line, db, MAX_DESC);

  while(line[0] != '\0' && line[0] != EOF) {
    int index = fleet.size;
    strcpy(fleet.aircrafts[index].name, line);

    scan_line(line, db, MAX_DESC);
    sscanf(line, "%lf", &fleet.aircrafts[index].max_cruise_speed);

    scan_line(line, db, MAX_DESC);
    sscanf(line, "%lf%lf %c", &fleet.aircrafts[index].wingspan, &fleet.aircrafts[index].length, &fleet.aircrafts[index].type);

    scan_line(line, db, MAX_DESC);
    strcpy(fleet.aircrafts[index].description, line);

    scan_line(line, db, MAX_DESC);
    scan_line(line, db, MAX_DESC);

    fleet.size++;
  }

  int choice = 0;
  while(choice != 6) {
    printf("What would you like to filter by?\n");
    printf("1. Name\n");
    printf("2. Cruise Speed\n");
    printf("3. Wingspan\n");
    printf("4. Length\n");
    printf("5. Type\n");
    printf("6. Quit\n\n");
    printf("Enter your choice> ");

    scanf("%d", &choice);

    Fleet f_sub;
    Fleet *fp = &f_sub;

    if(choice != 6) {
      filter_fleet(fleet, choice, fp);
      if(f_sub.size == 0) {
        printf("Sorry, there are no aircrafts that matched your criteria.\n\n");
      } else {
        printf("Number of aircrafts found: %d\n\n", f_sub.size);
      }
      print_fleet(f_sub);
    }

    f_sub.size = 0;
  }
  return(0);
}

//Prints the data in Aircraft a
void print_aircraft(Aircraft a) {
  printf("Name: %s\n", a.name);
  printf("Cruise Speed: %.2lf\n", a.max_cruise_speed);
  printf("Wingspan: %.2lf\n", a.wingspan);
  printf("Length: %.2lf\n", a.length);
  if(a.type == 'C') {
    printf("Type: Civilian\n");
  } else {
    printf("Type: Military\n");
  }
  printf("Description: %s\n", a.description);
}

//Prints all aircrafts in Fleet f
void print_fleet(Fleet f) {
  for(int i = 0; i < f.size; i++) {
    printf("Aircraft #%d:\n", i+1);
    print_aircraft(f.aircrafts[i]);
    printf("\n");
  }
}

//Filters the Fleet f based on choice and puts required aircrafts into output.
void filter_fleet(Fleet f, int choice, Fleet *output) {
  switch(choice) {
    case 1: filter_by_name(f, output); break;
    case 2: filter_by_speed(f, output); break;
    case 3: filter_by_wingspan(f, output); break;
    case 4: filter_by_length(f, output); break;
    case 5: filter_by_type(f, output); break;
    default: printf("That is not a valid choice.\n");
  }
}

//Filters elements of f into output if its name matches the given name
void filter_by_name(Fleet f, Fleet *output) {
  char name[MAX_NAME];
  printf("Enter the name> ");
  scan_line_stdin(name, MAX_NAME);
  scan_line_stdin(name, MAX_NAME);

  for(int i = 0; i < f.size; i++) {
    if(strcmp(f.aircrafts[i].name, name) == 0) {
      copy_aircraft(f.aircrafts[i], &(output->aircrafts[output->size]));
      output->size++;
    }
  }
}

//Filters elements of f into output if its speed matches the given speed
void filter_by_speed(Fleet f, Fleet *output) {
  double speed = 0;
  printf("Enter the Max Cruise Speed> ");
  scanf("%lf", &speed);

  for(int i = 0; i < f.size; i++) {
    if(f.aircrafts[i].max_cruise_speed == speed) {
      copy_aircraft(f.aircrafts[i], &(output->aircrafts[output->size]));
      output->size++;
    }
  }
}

//Filters elements of f into output if its wingspan matches the given wingspan
void filter_by_wingspan(Fleet f, Fleet *output) {
  double wingspan = 0;
  printf("Enter the Wingspan> ");
  scanf("%lf", &wingspan);

  for(int i = 0; i < f.size; i++) {
    if(f.aircrafts[i].wingspan == wingspan) {
      copy_aircraft(f.aircrafts[i], &(output->aircrafts[output->size]));
      output->size++;
    }
  }
}

//Filters elements of f into output if its length matches the given length
void filter_by_length(Fleet f, Fleet *output) {
  double length = 0;
  printf("Enter the Wingspan> ");
  scanf("%lf", &length);

  for(int i = 0; i < f.size; i++) {
    if(f.aircrafts[i].length == length) {
      copy_aircraft(f.aircrafts[i], &(output->aircrafts[output->size]));
      output->size++;
    }
  }
}

//Filters elements of f into output if its type matches the given type
void filter_by_type(Fleet f, Fleet *output) {
  char type = 'a';
  printf("Enter the Type (C / M) > ");
  scanf(" %c", &type);

  for(int i = 0; i < f.size; i++) {
    if(f.aircrafts[i].type == type) {
      copy_aircraft(f.aircrafts[i], &(output->aircrafts[output->size]));
      output->size++;
    }
  }
}

//Copies values in source to destination
void copy_aircraft(Aircraft source, Aircraft *target) {
  strcpy(target->name, source.name);
  target->max_cruise_speed = source.max_cruise_speed;
  target->wingspan = source.wingspan;
  target->length = source.length;
  target->type = source.type;
  strcpy(target->description, source.description);
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

//Authored by Mr. Pajela
/* * Gets one line of data from input. Returns an empty string on * end of file. If data line will not fit in allotted space, stores * portion that does fit and discards rest of input line. */
char *scan_line_stdin(char *dest, int dest_len) {
  int i, ch;  /* Gets next line one character at a time. */
  i = 0;
  for (ch = getchar(); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getchar()) {
    dest[i++] = ch;
  }
  dest[i] = '\0';  /* Discards any characters that remain on input line */
  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
  return(dest);
}
