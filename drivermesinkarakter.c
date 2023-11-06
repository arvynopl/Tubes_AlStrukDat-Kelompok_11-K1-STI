#include <stdio.h>
#include "mesinkarakter.h"

int main(){
    FILE *input = stdin;
    START();

    while(!IsEOP()){
        printf("Karakter : ");
        printf("%c\n", GetCC());
        ADV();
    }

    printf("Karakter sudah habis.\n");
    CLOSE();

    return 0;
}