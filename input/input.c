#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <stdint.h>
#endif

void readInput(double mat[][2], char *fileName, uint8_t line, uint8_t col) {
    FILE *fin = NULL;
    char number[MAX_NUM_SIZE];
    uint8_t index = 0, aux_line = 0, aux_col = 0;
    char ch;

    if ((fin = fopen(fileName, "r")) == NULL)
        showMessage("Error opening file", OPEN_FILE_ERR);    
    while ((ch = fgetc(fin)) != EOF) {
        if (str_isNumber(ch) || ch == '.')
            number[index++] = ch;
        else {
            number[index] = '\0';
            if (aux_col < col)
                mat[aux_line][aux_col++] = strtodouble(number);
            else {
                aux_line++;
                aux_col = 0;
            }
            index = 0;
        }
    }
    number[index] = '\0';
    printf("%s ", number);   
    fclose(fin);
}