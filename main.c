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
    Biarray *matGJ = io_readInput(fin, math_atoi(argv[2]), math_atoi(argv[3]));
    Biarray *matGS = mem_biArrayAlloc(math_atoi(argv[2]), math_atoi(argv[3]));
    Biarray *matgauss = mem_biArrayAlloc(math_atoi(argv[2]), math_atoi(argv[3]));
    mem_memcpy(matgauss, matGJ, sizeof(Biarray));
    mem_memcpy(matGS, matGJ, sizeof(Biarray));

    math_gaussJordan(matgauss);
    io_displayAnaliticResult(matgauss, "Gauss-Jordan");

    math_gaussJacobi(matGJ, 10E-4);
    io_displayNumericResult(matGJ, "Gauss-Jacobi"); 

    math_gaussSeidl(matGS, 10E-4);
    io_displayNumericResult(matGS, "Gauss-Seidel");

    
    return 0;           
}
