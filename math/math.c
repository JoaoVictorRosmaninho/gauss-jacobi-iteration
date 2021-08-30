#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <stdint.h>
#endif

int math_pow(int base, uint8_t exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) 
        result *= base;
    return (result);    
}


static double convert(char *ini, char *end, uint8_t flag) {
    uint32_t mult = 1;
    uint8_t size = (uint8_t) (end - ini) + 1;
    double result = 0;
    while (end >= ini) {
        result += (*end - '0') * mult;
        mult *= 10;
        end--;
    }
    if (flag)
        return (result / math_pow(10, size));
    return (result);
}

double math_atof(char *ini_number) {
    double result = 0;
    uint8_t flag = 0;
    int8_t sign = 1;
    if (*ini_number == '-') {
        sign = -1;
        ini_number++;
    }
    char *end_number = ini_number;
    while(*end_number) {
        if (str_isNumber(*end_number) && *(end_number + 1)) {
            end_number++;
            continue;
        }
        if (*end_number == '-') {
            sign = -1;
            end_number++;
            continue;
        }
        if (*end_number == '.') {   
            result += convert(ini_number, end_number - 1, flag);
            flag = 1;
        }
        else 
            result += convert(ini_number, end_number, flag) ;        
        end_number++;
        ini_number = end_number;                              
        
    }
    return (result * sign);
}

int math_atoi(char *ini_number) {
    char *end_number = ini_number;
    while(*end_number) {
        if (!str_isNumber(*end_number)) 
            showMessage("invalid value for the int", INT_CONVERSION_ERROR);
        end_number++;
    }
    return (convert(ini_number, (end_number - 1), 0));
}

static void math_doublecpy(double *dest, double *orig, uint16_t size) {
    for (register uint16_t index = 0; index < size; index++)
        dest[index] = orig[index];
}

static int math_calcerr(double *value_xi, double *value_x0, double error, uint16_t iteration) {
   uint16_t count_err = 0;
   for (register uint16_t i = 0; i < iteration; i++) {
     double err = (value_xi[i] - value_x0[i]) / value_x0[i];
     printf("%5s x%u: %1f\n", "Error para:", i, err);
     if (err < error)
       count_err++;
   }
   putchar('\n');
   return (count_err == iteration);
}

double *math_gaussJacobi(Biarray *ptr, double error) {
    double *temp_values = mem_arrayAlloc(ptr->size_row);
    double *aux_values = mem_arrayAlloc(ptr->size_row);
    uint16_t iteration = 0;

    while (1) {       
        for (register uint16_t i = 0; i < ptr->size_row; i++) {
            double div_aux = 1.0;
            for (register uint16_t j = 0; j < ptr->size_col - 1; j++) {
                if (j != i) 
                    temp_values[i] += ptr->array[i][j] * aux_values[j];
                else  
                    div_aux = ptr->array[i][j];            
            }            
            temp_values[i] = ptr->array[i][ptr->size_col - 1] - temp_values[i];
            temp_values[i] /= div_aux;      
        }
        if (iteration != 0)
          if (math_calcerr(temp_values, aux_values, error, ptr->size_row))
            return aux_values;           
        iteration++;
        math_doublecpy(aux_values, temp_values, ptr->size_row);
        memclear(temp_values, 0, ptr->size_row * sizeof(double));
        
    }
     return aux_values;   
}

double *math_gaussSeidl(Biarray *ptr, double error) {
    double *temp_values = mem_arrayAlloc(ptr->size_row);
    double *aux_values = mem_arrayAlloc(ptr->size_row);
    uint16_t iteration = 0;
     double err = 1;
     while (1) {                      
        for (register uint16_t i = 0; i < ptr->size_row; i++) {
            double div_aux = 1.0;
            double aux_err;
            for (register uint16_t j = 0; j < ptr->size_col - 1; j++) {
                if (j != i) 
                    temp_values[i] += ptr->array[i][j] * aux_values[j];
                else  
                    div_aux = ptr->array[i][j];            
            }            
            temp_values[i] = ptr->array[i][ptr->size_col - 1] - temp_values[i];
            temp_values[i] /= div_aux;
            if (iteration > 1) {
                aux_err = (temp_values[i] - aux_values[i]) / aux_values[i];
                if (aux_err < err) err = aux_err;
            }            
            aux_values[i] = temp_values[i]; 
        }
        iteration++;
        printf("error: %f\n", err);
        if (err < error) {
            free(temp_values);
            return aux_values;
        }
        memclear(temp_values, 0, ptr->size_row * sizeof(double));
    }
     return NULL;   
}
