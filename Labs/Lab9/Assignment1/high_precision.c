/*
Author: Aryaman Kejriwal
Course: Introduction to Programming in C
instructor: Gilbert Pajela
Assignment: Lab 9.1

This program inmplements the functions to deal with high precision numbers.
*/

#include <stdio.h>
#include <math.h>
#include "high_precision.h"

//Calculates and returns the sum of 2 high precision numbers
high_precision_t add_high(high_precision_t n1, high_precision_t n2) {
  int shift = n1.decpt - n2.decpt;
  high_precision_t answer;

  //Sign
  if(n1.sign == n2.sign) {
    answer.sign = n1.sign;
    n1.sign = 1;
    n2.sign = 1;
  } else {
    if(equals_high(n1, n2)) {
      answer.sign = 1;
      answer.decpt = 0;
      for(int i = 0; i < PRECISION; i++) {
        answer.digits[i] = 0;
      }

      return(answer);
    } else {
      high_precision_t tmp = larger(n1, n2);
      answer.sign = tmp.sign;
      if(tmp.sign == -1) {
        n1.sign *= -1;
        n2.sign *= -1;
      }
    }
  }

  //Decimal Point
  high_precision_t tmp = larger(n1, n2);
  answer.decpt = tmp.decpt;


  //Digits
  for(int i = 0; i < PRECISION; i++) {
    if(shift >= 0) {
      if(i - shift >= 0) {
        answer.digits[i] = n1.digits[i] * n1.sign + n2.digits[i - shift] * n2.sign;
      } else {
        answer.digits[i] = n1.digits[i] * n1.sign;
      }
    } else {
      if(i + shift >= 0) {
        answer.digits[i] = n1.digits[i + shift] * n1.sign + n2.digits[i] * n2.sign;
      } else {
        answer.digits[i] = n2.digits[i] * n2.sign;
      }
    }
  }

  //Erroneously rounded numbers:
  /*if(shift != 0) {
    if(shift > 0) {
      if(n2.digits[PRECISION - shift] >= 5) {
        answer.digits[PRECISION - 1] += 1;
      }
    } else {
      if(n1.digits[PRECISION - shift] >= 5) {
        answer.digits[PRECISION - 1] += 1;
      }
    }
  }*/

  //Carry-overs
  int error_index = digits_valid(answer);

  while(error_index != -1) {
    if(answer.digits[error_index] < 0) {
      if(error_index == 0) {
        answer.digits[error_index] *= -1;
      } else {
        answer.digits[error_index - 1]--;
        answer.digits[error_index] += 10;
      }
    } else {
      if(error_index == 0) {
        //Rounds off in case of deletion due to carry over (Erroneous)
        //if(answer.digits[PRECISION - 1] >= 5) {
          //answer.digits[PRECISION - 2] += 1;
        //}
        for(int i = PRECISION - 1; i > 0; i--) {
          answer.digits[i] = answer.digits[i - 1];
        }
        answer.digits[1]    -= 10;
        answer.digits[0]     = 1;
        answer.decpt += 1;
      } else {
        answer.digits[error_index - 1]++;
        answer.digits[error_index] -= 10;
      }
    }

    error_index = digits_valid(answer);
  }

  shift_digits(&answer);
  return(answer);
}

//Calculates and returns the difference between 2 high precision numbers
high_precision_t subtract_high(high_precision_t n1, high_precision_t n2) {
  n2.sign = n2.sign * -1;
  return(add_high(n1, n2));
}

//Calculates and returns the product of 2 high precision numbers
high_precision_t multiply_high(high_precision_t n1, high_precision_t n2) {
  high_precision_t answer;
  answer.decpt = 0;
  for(int i = 0; i < PRECISION; i++) {
    answer.digits[i] = 0;
  }

  high_precision_t intermediates[PRECISION];
  int decpt = n1.decpt + n2.decpt - 1;
  for(int i = 0; i < PRECISION; i++) {
    intermediates[i] = multiply_long(n1, n2.digits[i]);
    intermediates[i].decpt = decpt;
    intermediates[i].sign = 1;
    decpt--;
    shift_digits(&(intermediates[i]));
    int equals_zero = 1;
    for(int j = 0; j < PRECISION; j++) {
      if(intermediates[i].digits[j] == 0) {
        equals_zero = 0;
        break;
      }
    }

    if(equals_zero) {
      intermediates[i].decpt = 0;
    }
  }

  for(int i = 0; i < PRECISION; i++) {
    answer = add_high(answer, intermediates[i]);
  }
  if(n1.sign == n2.sign) {
    answer.sign = 1;
  } else {
    answer.sign = -1;
  }
  return(answer);
}

//Multiplied high_precision with an integer
high_precision_t multiply_long(high_precision_t n1, long n2) {
  high_precision_t sum;
  for(int i = 0; i < PRECISION; i++) {
    sum.digits[i] = 0;
  }
  sum.decpt = 0;
  sum.sign = 1;

  for(int i = 0; i < n2; i++) {
    sum = add_high(sum, n1);
  }

  return(sum);
}

//Multiplies hiogh_precision by 10 to the power n2
high_precision_t multiply_pow_10(high_precision_t n1, int n2) {
  n1.decpt += n2;
  return(n1);
}

//Gets rid of all leading 0s and changes decimal point accordingly
void shift_digits(high_precision_t *n) {
  int c = 0;
  while(n->digits[0] == 0 && c < PRECISION) {
    for(int i = 0; i < PRECISION - 1; i++) {
      n->digits[i] = n->digits[i+1];
    }

    n->digits[PRECISION - 1] = 0;
    n->decpt                -= 1;

    c++;
  }
}

//Returns -1 if the number's digits are valid, otherwise returns the index of the first invalid index
int digits_valid(high_precision_t n) {
  for(int i = 0; i < PRECISION; i++) {
    if(n.digits[i] < 0 || n.digits[i] > 9 ) {
      return(i);
    }
  }

  return(-1);
}

//Returns 1 if the numbers are equal, otherwise returns 0
//Ignores sign
int equals_high(high_precision_t n1, high_precision_t n2) {
  if(n1.decpt != n2.decpt) {
    return(0);
  }

  for(int i = 0; i < PRECISION; i++) {
    if(n1.digits[i] != n2.digits[i]) {
      return(0);
    }
  }

  return(1);
}

//Returns the larger of the 2 high precision numbers
//NOTE: n1 cannot be equal to n2
//Ignores sign
high_precision_t larger(high_precision_t n1, high_precision_t n2) {
  if(n1.decpt > n2.decpt) {
    return(n1);
  } else if(n1.decpt < n2.decpt) {
    return(n2);
  } else {
    for(int i = 0; i < PRECISION; i++) {
      if(n1.digits[i] > n2.digits[i]) {
        return(n1);
      } else if (n1.digits[i] < n2.digits[i]) {
        return(n2);
      }
    }
  }
}

//Scans high precision number from stdin
high_precision_t scan_high() {
  high_precision_t answer;

  printf("Data for high precision number:\n");
  for(int i = 0; i < PRECISION; i++) {
    printf("Enter digits (keep entering 0 if there are no more digits)> ");
    scanf("%d", &(answer.digits[i]));
  }

  printf("Enter position of decimal point> ");
  scanf("%d", &(answer.decpt));
  printf("Enter sign> ");
  scanf("%d", &(answer.sign));
  if(answer.sign < 0) {
    answer.sign = -1;
  } else {
    answer.sign = 1;
  }

  printf("\n");
  shift_digits(&answer);
  return(answer);
}

//Prints high precision number from stdin
void print_high(high_precision_t num) {
  if(num.sign < 0) {
    printf("-");
  }
  if(num.decpt <= 0) {
    printf("0.");
    for(int i = 0; i > num.decpt; i--) {
      printf("0");
    }

    for(int i = 0; i < PRECISION; i++) {
      printf("%d", num.digits[i]);
    }
  } else {
    for(int i = 0; i < num.decpt && i < PRECISION; i++) {
      printf("%d", num.digits[i]);
    }

    if(num.decpt > PRECISION) {
      for(int i = PRECISION; i < num.decpt; i++) {
        printf("%d", 0);
      }
    }

    printf(".");

    int prints = 0;

    for(int i = num.decpt; i < PRECISION; i++) {
      printf("%d", num.digits[i]);
      prints = 1;
    }

    if(!prints) {
      printf("0");
    }
  }

  printf("\n");
}
