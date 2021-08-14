#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#endif

unsigned int str_isvalid(char ch) {
   // return ((ch >= '\t' &&  ch <= '\r') || (ch == ' '));
   return (ch == ' ' || ch == '\n');
}

unsigned int str_isNumber(char ch) {
    return (ch >= '0' && ch <= '9');
}

void showMessage(const char *msg, unsigned char errCod) {
    fprintf(stderr, "%s\n", msg);
    exit(errCod);
}