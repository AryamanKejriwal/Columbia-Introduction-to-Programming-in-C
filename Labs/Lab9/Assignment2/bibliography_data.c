/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.2

This program implements the functions to deal with bibliography data.
*/
#include <stdio.h>
#include <string.h>
#include "bibliography_data.h"

//Allows user to add a source to the bibliography
void add_source(Bibliography *b) {
  bibliography_data bd;
  int choice = 0;
  printf("What is the type of your source?\n");
  printf("1. Book\n");
  printf("2. Encyclopedia\n");
  printf("3. Newspaper\n");
  printf("4. Periodical\n");
  printf("5. Website\n\n");
  printf("Enter your choice> ");
  scanf("%d", &choice);

  if(choice == 1) {
    bd.component = book;
    //bd.source.book;

    printf("Enter Title> ");
    scanf(" %s", (bd.source.book.title));
    printf("Enter Author> ");
    scanf(" %s", (bd.source.book.author));
    printf("Enter Publisher> ");
    scanf(" %s", (bd.source.book.publisher));
    printf("Enter Publication Year> ");
    scanf("%d", &(bd.source.book.publish_year));
  } else if(choice == 2) {
    bd.component = encyclopedia;
    //bd.source.encyclopedia;

    printf("Enter Title> ");
    scanf(" %s", (bd.source.encyclopedia.title));
    printf("Enter Volume> ");
    scanf("%d", &(bd.source.encyclopedia.volume));
    printf("Enter Publisher> ");
    scanf(" %s", (bd.source.encyclopedia.publisher));
    printf("Enter Page number> ");
    scanf("%d", &(bd.source.encyclopedia.page));
  }  else if(choice == 3) {
    bd.component = newspaper;
    //bd.source.newspaper;

    printf("Enter Name> ");
    scanf(" %s", (bd.source.newspaper.name));
    printf("Enter Article Title> ");
    scanf(" %s", (bd.source.newspaper.article_title));
    printf("Enter Author> ");
    scanf(" %s", (bd.source.newspaper.author));
    printf("Enter Day of Issue> ");
    scanf("%d", &(bd.source.newspaper.issue_date.day));
    printf("Enter Month of Issue> ");
    scanf("%d", &(bd.source.newspaper.issue_date.month));
    printf("Enter Year of Issue> ");
    scanf("%d", &(bd.source.newspaper.issue_date.year));
  }  else if(choice == 4) {
    bd.component = periodical;
    //bd.source.periodical;

    printf("Enter Name> ");
    scanf(" %s", (bd.source.periodical.name));
    printf("Enter Author> ");
    scanf(" %s", (bd.source.periodical.author));
    printf("Enter Year> ");
    scanf("%d", &(bd.source.periodical.year));
    printf("Enter Volume> ");
    scanf("%d", &(bd.source.periodical.volume));
    printf("Enter Page Number> ");
    scanf("%d", &(bd.source.periodical.page));
  }  else if(choice == 5) {
    bd.component = website;
    //bd.source.website;

    printf("Enter Title> ");
    scanf(" %s", (bd.source.website.title));
    printf("Enter url> ");
    scanf(" %s", (bd.source.website.url));
  } else {
    printf("That is not a valid source type");
    return;
  }

  printf("\nEnter description> ");
  scanf(" %s", (bd.description));

  b->entries[b->size] = bd;
  b->size++;
}

//Allows user to modify the source
void modify_record(bibliography_data *b) {
  display_source(*b);

  int choice = 0;

  printf("What would you like to modify?\n");
  printf("1. Source Type\n2. Description\nEnter your choice> ");
  scanf("%d", &choice);

  if(choice == 1) {
    int c = 0;
    printf("What is the type of your source?\n");
    printf("1. Book\n");
    printf("2. Encyclopedia\n");
    printf("3. Newspaper\n");
    printf("4. Periodical\n");
    printf("5. Website\n\n");
    printf("Enter your choice> ");
    scanf("%d", &c);

    if(c == 1) {
      b->component = book;
      //bd.source.book;

      printf("Enter Title> ");
      scanf(" %s", (b->source.book.title));
      printf("Enter Author> ");
      scanf(" %s", (b->source.book.author));
      printf("Enter Publisher> ");
      scanf(" %s", (b->source.book.publisher));
      printf("Enter Publication Year> ");
      scanf("%d", &(b->source.book.publish_year));
    } else if(c == 2) {
      b->component = encyclopedia;
      //bd.source.encyclopedia;

      printf("Enter Title> ");
      scanf(" %s", (b->source.encyclopedia.title));
      printf("Enter Volume> ");
      scanf("%d", &(b->source.encyclopedia.volume));
      printf("Enter Publisher> ");
      scanf(" %s", (b->source.encyclopedia.publisher));
      printf("Enter Page number> ");
      scanf("%d", &(b->source.encyclopedia.page));
    }  else if(c == 3) {
      b->component = newspaper;
      //bd.source.newspaper;

      printf("Enter Name> ");
      scanf(" %s", (b->source.newspaper.name));
      printf("Enter Article Title> ");
      scanf(" %s", (b->source.newspaper.article_title));
      printf("Enter Author> ");
      scanf(" %s", (b->source.newspaper.author));
      printf("Enter Day of Issue> ");
      scanf("%d", &(b->source.newspaper.issue_date.day));
      printf("Enter Month of Issue> ");
      scanf("%d", &(b->source.newspaper.issue_date.month));
      printf("Enter Year of Issue> ");
      scanf("%d", &(b->source.newspaper.issue_date.year));
    }  else if(c == 4) {
      b->component = periodical;
      //bd.source.periodical;

      printf("Enter Name> ");
      scanf(" %s", (b->source.periodical.name));
      printf("Enter Author> ");
      scanf(" %s", (b->source.periodical.author));
      printf("Enter Year> ");
      scanf("%d", &(b->source.periodical.year));
      printf("Enter Volume> ");
      scanf("%d", &(b->source.periodical.volume));
      printf("Enter Page Number> ");
      scanf("%d", &(b->source.periodical.page));
    }  else if(c == 5) {
      b->component = website;
      //bd.source.website;

      printf("Enter Title> ");
      scanf(" %s", (b->source.website.title));
      printf("Enter url> ");
      scanf(" %s", (b->source.website.url));
    } else {
      printf("That is not a valid source type");
    }
  } else if(choice == 2) {
    printf("Enter new description> ");
    scanf(" %s", b->description);
  } else {
    printf("That is not a valid choice.");
  }
}

//Allows user to access a source
bibliography_data *access_source(Bibliography *b) {
  int choice = 0;
  printf("What do you want to access the source by?\n");
  printf("\n1. Name\n2. Title\n3. Author\nEnter your choice> ");
  scanf("%d", &choice);

  if(choice == 1) {
    char name[MAX_NAME];
    printf("Enter Name> ");
    scanf(" %s", name);

    for(int i = 0; i < b->size; i++) {
      if(b->entries[i].component == newspaper) {
        if(strcmp(b->entries[i].source.newspaper.name, name) == 0) {
          return(&(b->entries[i]));
        }
      } else if(b->entries[i].component == periodical) {
        if(strcmp(b->entries[i].source.periodical.name, name) == 0) {
          return(&(b->entries[i]));
        }
      }

    }
  } else if(choice == 2) {
    char title[MAX_NAME];
    printf("Enter Title> ");
    scanf(" %s", title);
    for(int i = 0; i < b->size; i++) {
      if(b->entries[i].component == book) {
        if(strcmp(b->entries[i].source.book.title, title) == 0) {
          return(&(b->entries[i]));
        }
      } else if(b->entries[i].component == encyclopedia) {
        if(strcmp(b->entries[i].source.encyclopedia.title, title) == 0) {
          return(&(b->entries[i]));
        }
      } else if(b->entries[i].component == website) {
        if(strcmp(b->entries[i].source.website.title, title) == 0) {
          return(&(b->entries[i]));
        }
      }
    }
  } else if(choice == 3) {
    char author[MAX_NAME];
    printf("Enter Author> ");
    scanf(" %s", author);
    for(int i = 0; i < b->size; i++) {
      if(b->entries[i].component == book) {
        if(strcmp(b->entries[i].source.book.author, author) == 0) {
          return(&(b->entries[i]));
        }
      } else if(b->entries[i].component == newspaper) {
        if(strcmp(b->entries[i].source.newspaper.author, author) == 0) {
          return(&(b->entries[i]));
        }
      } else if(b->entries[i].component == periodical) {
        if(strcmp(b->entries[i].source.periodical.author, author) == 0) {
          return(&(b->entries[i]));
        }
      }
    }
  }
  printf("That is not a valid choice.");
  return(access_source(b));
}

//Allows user to state the order of the source
void mark_source(bibliography_data *bd) {
  printf("Enter the serial number of the source> ");
  scanf("%d", &(bd->entry_num));
}

//Allows user to store the Bibliography in a .txt file
void store_database(Bibliography b, FILE *output) {
  for(int i = 0; i < b.size; i++) {
    if(b.entries[i].component == book) {
      fprintf(output, "book\n");
      fprintf(output, "%s\n", b.entries[i].source.book.title);
      fprintf(output, "%s\n", b.entries[i].source.book.author);
      fprintf(output, "%s\n", b.entries[i].source.book.publisher);
      fprintf(output, "%d\n\n", b.entries[i].source.book.publish_year);
    } else if(b.entries[i].component == encyclopedia) {
      fprintf(output, "encyclopedia\n");
      fprintf(output, "%s\n", b.entries[i].source.encyclopedia.title);
      fprintf(output, "%d\n", b.entries[i].source.encyclopedia.volume);
      fprintf(output, "%s\n", b.entries[i].source.encyclopedia.publisher);
      fprintf(output, "%d\n\n", b.entries[i].source.encyclopedia.page);
    } else if(b.entries[i].component == newspaper) {
      fprintf(output, "newspaper\n");
      fprintf(output, "%s\n", b.entries[i].source.newspaper.name);
      fprintf(output, "%s\n", b.entries[i].source.newspaper.article_title);
      fprintf(output, "%s\n", b.entries[i].source.newspaper.author);
      fprintf(output, "%2d %2d %4d\n\n",  b.entries[i].source.newspaper.issue_date.month, b.entries[i].source.newspaper.issue_date.day, b.entries[i].source.newspaper.issue_date.year);
    } else if(b.entries[i].component == periodical) {
      fprintf(output, "periodical\n");
      fprintf(output, "%s\n", b.entries[i].source.periodical.name);
      fprintf(output, "%s\n", b.entries[i].source.periodical.author);
      fprintf(output, "%d\n", b.entries[i].source.periodical.year);
      fprintf(output, "%d\n", b.entries[i].source.periodical.volume);
      fprintf(output, "%d\n\n", b.entries[i].source.periodical.page);
    } else if(b.entries[i].component == website) {
      fprintf(output, "website\n");
      fprintf(output, "%s\n", b.entries[i].source.website.title);
      fprintf(output, "%s\n\n", b.entries[i].source.website.url);
    }
  }
}

//ALlows user to load a database from a given .txt file
Bibliography load_database(FILE *input) {
  Bibliography b;
  char line[MAX_DESC];
  int EOF_detection = fscanf(input, "%s", line);
  while(EOF_detection != EOF) {
    if(strcmp(line, "book") == 0) {
      b.entries[b.size].component = book;
      fscanf(input, "%s", b.entries[b.size].source.book.title);
      fscanf(input, "%s", b.entries[b.size].source.book.author);
      fscanf(input, "%s", b.entries[b.size].source.book.publisher);
      fscanf(input, "%d", &(b.entries[b.size].source.book.publish_year));
      b.size++;
    } else if(strcmp(line, "encyclopedia") == 0) {
      b.entries[b.size].component = encyclopedia;
      fscanf(input, "%s", b.entries[b.size].source.encyclopedia.title);
      fscanf(input, "%d", &(b.entries[b.size].source.encyclopedia.volume));
      fscanf(input, "%s", b.entries[b.size].source.encyclopedia.publisher);
      fscanf(input, "%d", &(b.entries[b.size].source.encyclopedia.page));
      b.size++;
    } else if(strcmp(line, "newspaper") == 0) {
      b.entries[b.size].component = newspaper;
      fscanf(input, "%s", b.entries[b.size].source.newspaper.name);
      fscanf(input, "%s", b.entries[b.size].source.newspaper.article_title);
      fscanf(input, "%s", b.entries[b.size].source.newspaper.author);
      fscanf(input, "%d%d%d", &(b.entries[b.size].source.newspaper.issue_date.month), &(b.entries[b.size].source.newspaper.issue_date.day), &(b.entries[b.size].source.newspaper.issue_date.year));
      b.size++;
    } else if(strcmp(line, "periodical") == 0) {
      b.entries[b.size].component = periodical;
      fscanf(input, "%s", b.entries[b.size].source.periodical.name);
      fscanf(input, "%s", b.entries[b.size].source.periodical.author);
      fscanf(input, "%d", &(b.entries[b.size].source.periodical.year));
      fscanf(input, "%d", &(b.entries[b.size].source.periodical.volume));
      fscanf(input, "%d", &(b.entries[b.size].source.periodical.page));
      b.size++;
    } else if(strcmp(line, "website") == 0) {
      b.entries[b.size].component = website;
      fscanf(input, "%s", b.entries[b.size].source.website.title);
      fscanf(input, "%s", b.entries[b.size].source.website.url);
      b.size++;
    }
    EOF_detection = fscanf(input, "%s", line);
  }

  return(b);
}

//Displays unused sources, used sources in order of selection and all sources in order by title/name
void display_sources(Bibliography b) {
  printf("Unused sources:\n");
  for(int i = 0; i < b.size; i++) {
    if(b.entries[i].entry_num == 0) {
      display_source(b.entries[i]);
      printf("\n");
    }
  }

  printf("Used sources:\n");
  for(int i = 1; i < b.size; i++) {
    for(int j = 0; j < b.size; j++) {
      if(b.entries[j].entry_num == i) {
        display_source(b.entries[i]);
        printf("\n");
      }
    }
  }

  printf("All Sources:\n"); //Not ordered
  for(int i = 0; i < b.size; i++) {
    display_source(b.entries[i]);
    printf("\n");
  }
}

//Displays data about a source
void display_source(bibliography_data b) {
  if(b.component == book) {
    printf("Title: %s\n", b.source.book.title);
    printf("Author: %s\n", b.source.book.author);
    printf("Publisher: %s\n", b.source.book.publisher);
    printf("Publication Year: %d\n", b.source.book.publish_year);
  } else if(b.component == encyclopedia) {
    printf("Title: %s\n", b.source.encyclopedia.title);
    printf("Volume: %d\n", b.source.encyclopedia.volume);
    printf("Publisher: %s\n", b.source.encyclopedia.publisher);
    printf("Page: %d\n", b.source.encyclopedia.page);
  } else if(b.component == newspaper) {
    printf("Name: %s\n", b.source.newspaper.name);
    printf("Article Title: %s\n", b.source.newspaper.article_title);
    printf("Author: %s\n", b.source.newspaper.author);
    printf("Issue Date: %2d/%2d/%4d\n", b.source.newspaper.issue_date.month, b.source.newspaper.issue_date.day, b.source.newspaper.issue_date.year);
  } else if(b.component == periodical) {
    printf("Name: %s\n", b.source.periodical.name);
    printf("Author: %s\n", b.source.periodical.author);
    printf("Year: %d\n", b.source.periodical.year);
    printf("Volume: %d\n", b.source.periodical.volume);
    printf("Page: %d\n", b.source.periodical.page);
  } else if(b.component == website) {
    printf("Title: %s\n", b.source.website.title);
    printf("URL: %s\n", b.source.website.url);
  }
}
