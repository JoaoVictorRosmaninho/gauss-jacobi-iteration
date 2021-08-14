#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <stdint.h>
#include <stdio.h>
#endif

static double convert(char *ini, char *end, uint8_t flag) {
    uint32_t mult = 1;
    uint8_t size = (uint8_t) (end - ini);
    double result = 0;
    while (end >= ini) {
        result += (*end - '0') * mult;
        mult *= 10;
        end--;
    }
    if (flag)
        return (result / size);
    return (result);
}

double strtodouble(char *number) {
    char *ini_number = number, *end_number = number;
    double result = 0;
    uint8_t flag = 0;
    while(*end_number) {
        if (str_isNumber(*end_number) && *(end_number + 1)) {
            end_number++;
            continue;
        } else {
            if (*end_number == '.') {
                result += convert(ini_number, end_number - 1, flag);
                flag = 1;
            }
            else 
                result += convert(ini_number, end_number, flag);
            end_number++;
            ini_number = end_number;                              
        }
    }
    printf("%ld\n", result);
    return result;
}