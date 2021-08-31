#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define MAX_NUM_SIZE 20

enum {INVALID_PARAMETERS, INVALID_VALUE,  OPEN_FILE_ERR, MEM_ERROR, VALUE_ERROR, INT_CONVERSION_ERROR};

typedef struct {
    double **array;
    uint16_t size_row;
    uint16_t size_col;
    double *err;
    double *result;
} Biarray;

void showMessage(const char *msg, unsigned char errCod);

/* verifica se ch é um digito  */
unsigned int str_isNumber(char ch);

/* verifica se é um caractere de espaçamento válido */
unsigned int str_isvalid(char ch);

/* realiza a leitura do arquivo e preenche a matriz */
Biarray *io_readInput(FILE *fin, uint16_t row, uint16_t col);

/* converte um string em float */
double math_atof(char *number);

/* converte uma string em inteiro */
int math_atoi(char *ini_number);

/* realiza a operação de pontência */
int math_pow(int base, uint8_t exp);

/* aloca memoria para a estrutura biArray */
Biarray *mem_biArrayAlloc(uint16_t row, uint16_t col);

/* aloca memoria para um array uni-dimensional */
double *mem_arrayAlloc(int size);

/* exibe a matriz na saída padrao */
void io_printMat(Biarray *ptr_mat);

/* calcula a saída pelo metodo gauss jacob */
double *math_gaussJacobi(Biarray *ptr, double error);

/* calcula a saída pelo método gauss Seidl*/
double *math_gaussSeidl(Biarray *ptr, double error);

/* exibe um array uni-dimensional*/
void io_printArray(double *array, uint16_t size);

/* limpa a memoria, setando os valores para value */
void memclear(void *ptr, int8_t value, size_t size);

/* copia a memoria do orig to dest*/
void mem_memcpy(void *dest, void *orig, size_t size); 

/* Metodo analitico gauss-jordan*/
int math_gaussJordan(Biarray *ptr);

/**/
void io_displayNumericResult(Biarray *ptr, char *name);

/**/
void io_displayAnaliticResult(Biarray *ptr, char *name);
