#ifndef HEADER_H
# define HEADER_H
# include "header.h"
#endif

uint16_t size;

int main(int argc, char *argv[]) {
    if (argc != 3)
        showMessage("parametros invalidos", INVALID_PARAMETERS);    
    FILE *fin;
    size = math_atoi(argv[2]);
    if ((fin = fopen(argv[1], "r")) == NULL)
        showMessage("Error opening file", OPEN_FILE_ERR);    
    double **mat = readInput(fin, size);
    for (uint8_t i = 0; i < size; i++) {
        for (uint8_t j = 0; j < size; j++)
            printf("%.3lf ", mat[i][j]);
        putchar('\n');  
    }
    return 0;
            
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
