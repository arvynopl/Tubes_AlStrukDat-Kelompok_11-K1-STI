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

/*

============CONTOH HASIL KELUARAN============

Karakter : t
Karakter : u
Karakter : b
Karakter : e
Karakter : s
Karakter sudah habis.

*/
