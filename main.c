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
<<<<<<< HEAD
    }*/
}
=======
    }
}

/*
void calculaXn(int Xn,float Matriz[51][51], float vetorXn[50],float valoresAtualizados[50]){
    int i = 0;
    float somaTotal = 0.0;
    while(i<50){
        if(Xn != i){
        somaTotal += Matriz[Xn][i]*vetorXn[i];
        }
        i++;
    }
    valoresAtualizados[Xn] = (Matriz[Xn][51] - somaTotal)/Matriz[Xn][Xn];
}

void atualizaVetor(float valoresAtualizados[50], float vetorXn[50]){
    int i = 0;
    while (i<50)
    {
        vetorXn[i]= valoresAtualizados[i];
        i++;
    }
}

float verificaErro(float vetorXn[50],float valoresAtualizados[50]){
    float erro = 0.0,erroAux = 0.0;
    int i = 0;

    erro = (valoresAtualizados[i]-vetorXn[i])/valoresAtualizados[i];
    while (i<49)
    {
        i++;
        erroAux = (valoresAtualizados[i]-vetorXn[i])/valoresAtualizados[i];
        if (erro < erroAux)
        {
            erro = erroAux;
        }
    }

    return erro;
}

void Gauss_Jacobi(float Matriz[51][51], float vetorXn[50], float valoresAtualizados[50]){
    int i = 0;
    float erro = 0.0;
    while ((erro > 0.001) || (i < 300))
    {
        for (int j = 0; j < 50; j++)
        {
            calculaXn(j,Matriz,vetorXn,valoresAtualizados);
        }
        erro = verificaErro(vetorXn,valoresAtualizados);
        atualizaVetor(valoresAtualizados,vetorXn);
        i++;
    }
}




void calculaXnGS(int Xn,float Matriz[51][51], float vetorXn[50],float valoresAtualizados[50]){
    int i = 0;
    float somaTotal = 0.0;
    while(i<50){
        if(Xn != i){
            if(i>Xn){
                somaTotal += Matriz[Xn][i]*vetorXn[i];
            }else{
                somaTotal += Matriz[Xn][i]*valoresAtualizados[i];
            }
        }
        i++;
    }
    valoresAtualizados[Xn] = (Matriz[Xn][51] - somaTotal)/Matriz[Xn][Xn];
}

void Gauss_Seidel(float Matriz[51][51], float vetorXn[50], float valoresAtualizados[50]){
    int i = 0;
    float erro = 0.0;
    while ((erro > 0.001) || (i < 300))
    {
        for (int j = 0; j < 50; j++)
        {
            calculaXn(j,Matriz,vetorXn,valoresAtualizados);
        }
        erro = verificaErro(vetorXn,valoresAtualizados);
        atualizaVetor(valoresAtualizados,vetorXn);
        i++;
    }
}

*/
>>>>>>> 0499cc1e6c4c85a313e3ad3e3bdf991fba61b23b
