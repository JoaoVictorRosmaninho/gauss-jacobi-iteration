#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

#define MAX_NUM_SIZE 20

enum {INVALID_PARAMETERS, INVALID_VALUE,  OPEN_FILE_ERR, MEM_ERROR, VALUE_ERROR, INT_CONVERSION_ERROR};

typedef struct {
    double **array;
    uint16_t size_row;
    uint16_t size_col;
} Biarray;

void showMessage(const char *msg, unsigned char errCod);

/*   */
unsigned int str_isNumber(char ch);

/* */
unsigned int str_isvalid(char ch);

/* */
Biarray *io_readInput(FILE *fin, uint16_t row, uint16_t col);

/* */
double math_atof(char *number);

/* */
int math_atoi(char *ini_number);

/* */
int math_pow(int base, uint8_t exp);

/* */
Biarray *mem_biArrayAlloc(uint16_t row, uint16_t col);

/* */
double *mem_arrayAlloc(int size);

/* */
void io_printMat(Biarray *ptr_mat);

/**/
double *math_gaussJacobi(Biarray *ptr, double error);

/**/
void io_printArray(double *array, uint16_t size);