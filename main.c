#ifndef HEADER_H
# define HEADER_H
# include "header.h"
#include <stdint.h>
#endif

int main(int argc, char *argv[]) {
    if (argc != 4)
        showMessage("parametros invalidos", INVALID_PARAMETERS);    
    FILE *fin;
    if ((fin = fopen(argv[1], "r")) == NULL)
        showMessage("Error opening file", OPEN_FILE_ERR);    
    Biarray *mat = io_readInput(fin, math_atoi(argv[2]), math_atoi(argv[3]));
    Biarray *matgauss = mem_biArrayAlloc(mat->size_row, mat->size_col);
    mem_memcpy(matgauss, mat, sizeof(Biarray));
    math_gaussJacobi(mat, 10E-4);
    math_gaussJordan(matgauss);
    io_displayNumericResult(mat, "Gauss-Jacobi");  
    io_displayAnaliticResult(matgauss, "Gauss-Jordan");

    
    return 0;           
}
