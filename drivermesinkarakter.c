#include <stdio.h>
#include "mesinkarakter.h"

int main(){
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