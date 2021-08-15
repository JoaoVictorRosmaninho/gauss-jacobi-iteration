#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <sys/types.h>
#endif

double **mem_matrizAlloc(uint16_t dimension) {
    double **ptr = 0;
    if ((ptr = (double **) calloc(dimension, sizeof(double *))) == NULL)
        showMessage("Err, insuficient memory",MEM_ERROR);
    for (uint16_t i = 0; i < dimension; i++) {
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

