#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <stdint.h>
#include <stdio.h>
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
    char *end_number = ini_number;
    double result = 0;
    while(*end_number) {
        if (str_isNumber(*end_number) && *(end_number + 1)) {
            end_number++;
            continue;
        } else {
            if (*end_number == '.')
                result += convert(ini_number, end_number - 1, 0);
            else 
               result += convert(ini_number, end_number, 1);
            end_number++;
            ini_number = end_number;                              
        }
    }
    return result;
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