#ifndef HEADER_H
# define HEADER_H
# include "header.h"
#endif

int main(int argc, char *argv[]) {
    if (argc != 4)
        showMessage("parametros invalidos", INVALID_PARAMETERS);    
    FILE *fin;
    if ((fin = fopen(argv[1], "r")) == NULL)
        showMessage("Error opening file", OPEN_FILE_ERR);    
    Biarray *mat = io_readInput(fin, math_atoi(argv[2]), math_atoi(argv[3]));
    //io_printArray(math_gaussJacobi(mat, 10E-4), mat->size_row);
    
    io_printArray(math_gaussJacobi(mat, 10E-6), mat->size_row);
    io_printArray(math_gaussSeidl(mat, 10E-6), mat->size_row);
    return 0;           
}