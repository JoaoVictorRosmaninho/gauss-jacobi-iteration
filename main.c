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
    double mat[2][2];
    readInput(mat, "in.txt", 2, 2);
    /*for (int i = 0; i < 2; i++) {
         for (int j = 0; j < 2; j++)
            printf("%.4lf", mat[i][j]);
         putchar('\n');
    }*/
}