#include "input.h"

void readInput(char *input[], char *fileName) {
    FILE *fin = NULL;
    unsigned char number[20];
    unsigned short int index = 0;
    char ch;

    if ((fin = fopen(fileName, "r")) == NULL)
        showMessage("Error opening file", OPEN_FILE_ERR);
    
    while ((ch = fgetc(fin)) != EOF) {
        if (isNumber(ch) || ch == '.')
            number[index++] = ch;
        else if (isSpace(ch))
            index = 0;               
    }
    fclose(fin);
}