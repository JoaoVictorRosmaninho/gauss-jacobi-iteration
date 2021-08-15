#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_NUM_SIZE 20

enum {INVALID_PARAMETERS, INVALID_VALUE,  OPEN_FILE_ERR, MEM_ERROR, VALUE_ERROR, INT_CONVERSION_ERROR};

void showMessage(const char *msg, unsigned char errCod);

/* */
unsigned int str_isNumber(char ch);

/* */
unsigned int str_isvalid(char ch);

/* */
double **readInput(FILE *fin, uint16_t value);

double math_atof(char *number);

int math_atoi(char *ini_number);

int math_pow(int base, uint8_t exp);

double **mem_matrizAlloc(uint16_t dimension);