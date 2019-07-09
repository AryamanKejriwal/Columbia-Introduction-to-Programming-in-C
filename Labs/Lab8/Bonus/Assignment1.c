/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 8 Bonus 1

This program defines a structure to measure data at different sites and prints out the site id of the site with highest
temperature range and that of site with highest average windspeed.
*/

#include <stdio.h>

#define MAX_SITES 10
#define MAX_DAYS 365
#define MAX_NAME 100

typedef struct {
  int site_id_num;
  int day_of_month;
  double wind_speed;
  double temperature;
} measured_data_t;

typedef struct {
  measured_data_t data[MAX_DAYS];
  int days;
  double temperature_range;
  double average_wind_speed;
} site_t;

int fill_sites(FILE *input, site_t sites[MAX_SITES]);
void copy_data(measured_data_t input, measured_data_t *output);
void copy_site(site_t input, site_t *output);

void fill_temp_range(site_t sites[MAX_SITES], int l);
double get_max_temp(site_t s);
double get_min_temp(site_t s);

void fill_average_speed(site_t sites[MAX_SITES], int l);

char *scan_line(char *dest, FILE* input, int dest_len);

int main() {
  site_t sites[MAX_SITES];
  int site_num = 0;

  char in_name[MAX_NAME];
  printf("Enter input file name> ");
  scanf("%s", in_name);

  FILE *input = fopen(in_name, "r");
  int length = fill_sites(input, sites);
  fclose(input);

  fill_temp_range(sites, length);
  fill_average_speed(sites, length);

  site_t max_temp_range;
  site_t max_av_windspeed;
  copy_site(sites[0], &max_temp_range);
  copy_site(sites[0], &max_av_windspeed);

  for(int i = 1; i < length; i++) {
    if(max_temp_range.temperature_range < sites[i].temperature_range) {
      copy_site(sites[i], &max_temp_range);
    }

    if(max_av_windspeed.average_wind_speed < sites[i].average_wind_speed) {
      copy_site(sites[i], &max_av_windspeed);
    }
  }

  printf("\nThe site with maximum temperature variation has id> %d\n", max_temp_range.data[0].site_id_num);
  printf("The site with maximum average wind speed has id> %d\n\n", max_av_windspeed.data[0].site_id_num);

  return(0);
}

//Fills sites with values in input file
//Returns number of sites
int fill_sites(FILE *input, site_t sites[MAX_SITES]) {
  char line[MAX_NAME];
  scan_line(line, input, MAX_NAME);
  int site_num = 0;
  int count = 0;

  while(line[0] != '\0' && line[0] != EOF) {
    int current_site_id = 0;
    int day = 0;
    double wind_speed = 0;
    double temperature = 0;

    sscanf(line, "%d %d %lf %lf", &current_site_id, &day, &wind_speed, &temperature);

    if(count != 0) {
      if(sites[site_num].data[0].site_id_num != current_site_id) {
        site_num++;
      }
    }

    measured_data_t md = {current_site_id, day, wind_speed, temperature};
    copy_data(md, &sites[site_num].data[sites[site_num].days]);
    sites[site_num].days++;

    count++;

    scan_line(line, input, MAX_NAME);
  }

  return(++site_num);
}

//Copies data in input to output
void copy_data(measured_data_t input, measured_data_t *output) {
  output->site_id_num = input.site_id_num;
  output->day_of_month = input.day_of_month;
  output->wind_speed = input.wind_speed;
  output->temperature = input.temperature;
}

//Copies data in input to output
void copy_site(site_t input, site_t *output) {
  output->days = input.days;
  output->average_wind_speed = input.average_wind_speed;
  output->temperature_range = input.temperature_range;
  for(int i = 0; i < input.days; i++) {
    copy_data(input.data[i], &(output->data[i]));
  }
}

//The temperature range for each site is filled
void fill_temp_range(site_t sites[MAX_SITES], int l) {
  for(int i = 1; i < l; i++) {
    double max_temp = get_max_temp(sites[i]);
    double min_temp = get_min_temp(sites[i]);
    sites[i].temperature_range = max_temp - min_temp;
  }
}

//Gets maximum temperature the site has experienced
double get_max_temp(site_t s) {
  double max = s.data[0].temperature;
  for(int i = 1; i < s.days; i++) {
    if(max < s.data[i].temperature) {
      max = s.data[i].temperature;
    }
  }

  return(max);
}

//Gets minimum temperature the site has experienced
double get_min_temp(site_t s) {
  double min = s.data[0].temperature;
  for(int i = 1; i < s.days; i++) {
    if(min > s.data[i].temperature) {
      min = s.data[i].temperature;
    }
  }

  return(min);
}

//The average wind speed for each site is filled
void fill_average_speed(site_t sites[MAX_SITES], int l) {
  for(int i = 0; i < l;i++) {
    double sum = 0;
    for(int j = 0; j < sites[i].days; j++) {
      sum += sites[i].data[j].wind_speed;
    }

    sites[i].average_wind_speed = sum / sites[i].days;
  }
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
