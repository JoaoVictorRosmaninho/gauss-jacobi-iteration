#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <stdint.h>
#endif

Biarray *io_readInput(FILE *fin, uint16_t row, uint16_t col) {
    char number[MAX_NUM_SIZE];
    uint16_t index = 0, aux_line = 0, aux_col = 0;
    char ch;
    Biarray *ptr_mat = mem_biArrayAlloc(row, col);

    while ((ch = fgetc(fin)) != EOF) {
        if (str_isNumber(ch) || ch == '.' || ch == '-')
            number[index++] = ch;
        else if (str_isvalid(ch)){
            number[index] = '\0';
            if (number[0] == '\0')
                showMessage("invalid value", INVALID_VALUE);
            if (aux_col < col)
                ptr_mat->array[aux_line][aux_col++] = math_atof(number);
            else {
                aux_line++;
                aux_col = 0;
                ptr_mat->array[aux_line][aux_col++] = math_atof(number);
            }
            index = 0;
        }
        else
            showMessage("invalid value", INVALID_VALUE);
    }
    number[index] = '\0';
    ptr_mat->array[aux_line][aux_col] = math_atof(number);
    fclose(fin);
    return (ptr_mat);
}

void io_printMat(Biarray *ptr_mat) {
    for (uint16_t i = 0; i < ptr_mat->size_row; i++) {
        for (uint16_t j = 0; j < ptr_mat->size_col; j++)
            printf("%5.2lf ", ptr_mat->array[i][j]);
        putchar('\n');
    }
}

void io_printArray(double *array, uint16_t size) {
    for (register uint16_t index = 0; index < size; index++)
        printf("%lf ", array[index]);
    putchar('\n');
}

void io_displayNumericResult(Biarray *ptr, char *name) {
    putchar('\n');  
    printf("####### %s #######\n", name);
    for (uint8_t i = 0; i < ptr->size_row; i++)
        printf("%3s%u\t", "X", i);
    putchar('\n');
    puts("\tError");
    for (uint8_t i = 0; i < ptr->size_row; i++)
        printf("%8.2E ", ptr->err[i]);
    putchar('\n');
    puts("\tResultado");
    for (uint8_t i = 0; i < ptr->size_row; i++)
        printf("%5.2f\t", ptr->result[i]);
    putchar('\n');    
    printf("####### ########## #######\n");
}

void io_displayAnaliticResult(Biarray *ptr, char *name) {
    putchar('\n');
    printf("####### %s #######\n", name);
    for (uint8_t i = 0; i < ptr->size_row; i++)
        printf("%3s%u\t", "X", i);
    putchar('\n');
    puts("\tResultado");
    for (uint16_t i = 0; i < ptr->size_row; i++)
        printf("%5.2f\t", (ptr->array[i][ptr->size_col - 1] / ptr->array[i][i]));
    putchar('\n');
    printf("####### ########## #######\n");
}