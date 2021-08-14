#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_NUM_SIZE 20

enum {OPEN_FILE_ERR, MEM_ERROR, VALUE_ERROR};

void showMessage(const char *msg, unsigned char errCod);

/* */
unsigned int str_isNumber(char ch);

/* */
unsigned int str_isvalid(char ch);

/* */
void readInput(double mat[][2], char *fileName, uint8_t line, uint8_t col);

double strtodouble(char *number);

