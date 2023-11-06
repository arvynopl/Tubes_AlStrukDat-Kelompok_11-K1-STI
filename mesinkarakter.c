#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(FILE *input){
       pita = input;
       ADV();
}

void ADV(){
       retval = fopen("pitakar.txt", "r");
       EOP = (currentChar == MARK);
       if (EOP){
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