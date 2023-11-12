#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;
FILE *pita = NULL;

static int retval;

void START(char mode){
    if (mode == 'f') {
        pita = fopen("pitakar.txt", "r");
    } 
    else if (mode == 't') {
        pita = stdin;
    }

    if (pita == NULL) {
        printf("Gagal membuka file atau input dari terminal.\n");
    }
    else {
        ADV();
    }
}

void tambahKata(){
    pita = fopen("pitakar.txt", "a"); // Buka file dalam mode append

    if (pita == NULL) {
        printf("Gagal membuka file.");
        return;
    }

    char kata[100];
    printf("Masukkan kata yang ingin ditambahkan ke file: ");
    scanf("%s", kata);

    fprintf(pita, "%s ", kata);

    fclose(pita);
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
        if(IsEOP()){
            CLOSE();
        }
}

void ADVINPUT(){
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
    return (currentChar == MARK || currentChar == ' ');
}