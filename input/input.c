#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <stdint.h>
#endif

double **readInput(FILE *fin, uint16_t value) {
    char number[MAX_NUM_SIZE];
    uint8_t index = 0, aux_line = 0, aux_col = 0;
    char ch;
    double **mat = mem_matrizAlloc(value);

    while ((ch = fgetc(fin)) != EOF) {
        if (str_isNumber(ch) || ch == '.')
            number[index++] = ch;
        else if (str_isvalid(ch)){
            number[index] = '\0';
            if (aux_col < value)
                mat[aux_line][aux_col++] = math_atof(number);
            else {
                aux_line++;
                aux_col = 0;
                mat[aux_line][aux_col++] = math_atof(number);
            }
            index = 0;
        }
        else
            showMessage("invalid value", INVALID_VALUE);
    }
    number[index] = '\0';
    mat[aux_line][aux_col] = math_atof(number);
    fclose(fin);
    return (mat);
}