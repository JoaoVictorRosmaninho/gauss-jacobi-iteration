#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#endif

double **mem_biArrayAlloc(int dimension, char value) {
    double **ptr = 0;
    if ((ptr = (double **) calloc(dimension, sizeof(double *))) == NULL)
        showMessage("Err, insuficient memory",MEM_ERROR);
    for (char i = 0; i < dimension; i++) {
        if((ptr[i] = (double *) calloc(dimension, sizeof(double))) == NULL)
            showMessage("Err, insuficient memory", MEM_ERROR);
    }
    return (ptr);
}

double *mem_arrayAlloc(int size) {
    double *ptr = 0;
     if ((ptr = (double *) calloc(size, sizeof(double))) == NULL)
        showMessage("Err, insuficient memory", MEM_ERROR);
    return (ptr);
}

void mem_arrayPopulate(double *array, char *str_ini)
{
    char *str_end = str_ini;
    short int index = 0;

    while(*str_end) {
        if (!(*str_end >= '0' && *str_end <= '9')) {
           str_end++;
           str_ini++;
           continue;
        }
        if (!(*str_end >= '0' && *str_end <= '9'))
            array[index++] = math_atoi(str_ini, (str_end - 1));
        str_end++;
    }
}