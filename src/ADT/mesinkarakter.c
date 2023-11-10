#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(){
    pita = fopen("pitakar.txt", "r");;
    ADV();
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
        if(IsEOP()){
            CLOSE();
        }
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
