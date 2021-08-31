#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <stdint.h>
#endif

Biarray *mem_biArrayAlloc(uint16_t row, uint16_t col) {
    Biarray *ptr_mat = 0;
    if ((ptr_mat = (Biarray *) calloc(1, sizeof(Biarray))) == NULL)
        showMessage("Err, insuficient memory",MEM_ERROR);
    ptr_mat->size_row = row;
    ptr_mat->size_col = col;
    ptr_mat->err = NULL;
    ptr_mat->result = NULL;
    if ((ptr_mat->array = (double **) calloc(row, sizeof(double *))) == NULL)
        showMessage("Err, insuficient memory",MEM_ERROR);
    for (uint16_t i = 0; i < row; i++) {
        if((ptr_mat->array[i] = (double *) calloc(col, sizeof(double))) == NULL)
            showMessage("Err, insuficient memory", MEM_ERROR);
    }
    return (ptr_mat);
}

double *mem_arrayAlloc(int size) {
    double *ptr = 0;
     if ((ptr = (double *) calloc(size, sizeof(double))) == NULL)
        showMessage("Err, insuficient memory", MEM_ERROR);
    return (ptr);
}

void memclear(void *ptr, int8_t value, size_t size) {
  char *ptr_aux = (char *) ptr;
  for (uint8_t index = 0; index < size; index++)
    ptr_aux[index] = value;
}

void mem_memcpy(void *dest, void *orig, size_t size) {
    char *ptr = (char *) dest;
    char *ptr_aux = (char *) orig;
    while (size--)
        *ptr++ = *ptr_aux++;
}

