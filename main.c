#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2)
        showMessage("parametros invalidos");
    
    int **array = biArrayAlloc(argv[1], argv[2]);
        
}