#include "mesinkarakter.h"

char currentChar;
boolean EOP;

FILE* pita;
int retval;

void START(FILE* input){
    pita = input;
    ADV();
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
}

void CLOSE(){
    fclose(pita);
}

char GetCC(){
    return currentChar;
}

boolean IsEOP(){
    return currentChar == MARK;
}

boolean IsEOF(){
    return retval == EOF;
}