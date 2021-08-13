#ifndef HEADER_H
# define HEADER_H
# include "header.h"
#endif

/*int main(int argc, char *argv[]) {
    if (argc != 2)
        showMessage("parametros invalidos");
    
    int **array = biArrayAlloc(argv[1], argv[2]);
        
}*/

int main(void) {
    double mat[4][4];
    readInput(mat, "in.txt", 4, 4);
    for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 4; j++)
            printf("%lf", mat[i][j]);
         putchar('\n');
    }
}