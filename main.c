#ifndef HEADER_H
# define HEADER_H
# include "header.h"
#define NLin 2
#define NCol 2
#define valorX 2
#endif

uint16_t size;
void calculaXn(int Xn,double **Matriz, double valorUltCol[valorX], double valoresAtuais[valorX],double valoresAtualizados[valorX]);
void atualizaVetor(double valoresAtualizados[valorX], double valoresAtuais[valorX]);
double verificaErro(double valoresAtuais[valorX],double valoresAtualizados[valorX]);
void Gauss_Jacobi(double **Matriz, double valorUltCol[valorX], double valoresAtuais[valorX], double valoresAtualizados[valorX]);

int main(int argc, char *argv[]) {
    if (argc != 4)
        showMessage("parametros invalidos", INVALID_PARAMETERS);    
    FILE *fin;
    if ((fin = fopen(argv[1], "r")) == NULL)
        showMessage("Error opening file", OPEN_FILE_ERR);    
    Biarray *mat = io_readInput(fin, math_atoi(argv[2]), math_atoi(argv[3]));
    io_printMat(mat);
    
    return 0;
            
}



void calculaXn(int Xn,double **Matriz, double valorUltCol[valorX] ,double valoresAtuais[valorX],double valoresAtualizados[valorX]){
    int i = 0;
    double somaTotal = 0.0;
    while(i<valorX){
        if(Xn != i){
        somaTotal += Matriz[Xn][i]*valoresAtuais[i];
        }
        i++;
    }
    valoresAtualizados[Xn] = ( valorUltCol[Xn] - somaTotal)/Matriz[Xn][Xn];
    printf("entrei no calcula!, valorAtualizado de Xn = %.3lf\n",valoresAtualizados[Xn]);
}

void atualizaVetor(double valoresAtualizados[valorX], double valoresAtuais[valorX]){
    int i = 0;
    while (i<valorX)
    {
        valoresAtuais[i]= valoresAtualizados[i];
        i++;
    }
}

double verificaErro(double valoresAtuais[valorX],double valoresAtualizados[valorX]){
    double erro = 0.0,erroAux = 0.0;
    int i = 0;

    erro = (valoresAtualizados[i]-valoresAtuais[i])/valoresAtualizados[i];
    while (i<valorX)
    {
        erroAux = (valoresAtualizados[i]-valoresAtuais[i])/valoresAtualizados[i];
        if (erro < erroAux)
        {
            erro = erroAux;
        }
        i++;
    }

    return erro;
}

void Gauss_Jacobi(double **Matriz,double valorUltCol[valorX],double valoresAtuais[valorX], double valoresAtualizados[valorX]){
    printf("entrei no gaus jacobi\n");
    int i = 0;
    double erro = 0.0;
    while (i < 100)
    {
        for (int j = 0; j < valorX; j++)
        {
            calculaXn(j,Matriz, valorUltCol, valoresAtuais,valoresAtualizados);
        }
        erro = verificaErro(valoresAtuais,valoresAtualizados);
        atualizaVetor(valoresAtualizados,valoresAtuais);
        printf("erro = %lf\n",erro);
        printf("i = %d\n",i);
        i++;
    }
    
}



/*
void calculaXnGS(int Xn,double Matriz[51][51], double vetorXn[50],double valoresAtualizados[50]){
    int i = 0;
    double somaTotal = 0.0;
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

void Gauss_Seidel(double Matriz[51][51], double vetorXn[50], double valoresAtualizados[50]){
    int i = 0;
    double erro = 0.0;
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
