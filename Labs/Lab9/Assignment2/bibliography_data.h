/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.2

This header file defines a structure to store data for a bibliography and declares functions that will deal with
the addition and modification of data enries.
*/
#define MAX_NAME 100
#define MAX_DESC 200
#define MAX_ENTRIES 50

typedef enum {
  book,
  encyclopedia,
  newspaper,
  periodical,
  website
} source_type;

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  char title[MAX_NAME];
  char author[MAX_NAME];
  char publisher[MAX_NAME];
  int publish_year;
} Book;

typedef struct {
  char title[MAX_NAME];
  int volume;
  char publisher[MAX_NAME];
  int page;
} Encyclopedia;

typedef struct {
  char name[MAX_NAME];
  char article_title[MAX_NAME];
  char author[MAX_NAME];
  Date issue_date;
} Newspaper;

typedef struct {
  char name[MAX_NAME];
  char author[MAX_NAME];
  int year;
  int volume;
  int page;
} Periodical;

typedef struct {
  char title[MAX_NAME];
  char url[MAX_NAME];
} Website;

typedef union {
  Book book;
  Encyclopedia encyclopedia;
  Newspaper newspaper;
  Periodical periodical;
  Website website;
} Source;

typedef struct {
  Source source;
  source_type component;
  char description[MAX_DESC];
  int entry_num;
} bibliography_data;

typedef struct {
  bibliography_data entries[MAX_ENTRIES];
  int size;
} Bibliography;

//Allows user to add a source to the bibliography
extern void add_source(Bibliography *b);

//Allows user to modify the source
extern void modify_record(bibliography_data *b);

//Allows user to access a source
extern bibliography_data *access_source(Bibliography *b);

//Allows user to state the order of the source
extern void mark_source(bibliography_data *bd);

//Allows user to store the Bibliography in a .txt file
extern void store_database(Bibliography b, FILE *output);

//ALlows user to load a database from a given .txt file
extern Bibliography load_database(FILE *input);

//Displays unused sources, used sources in order of selection and all sources in order by title/name
extern void display_sources(Bibliography b);

//Prints source to stdout
extern void display_source(bibliography_data b);
