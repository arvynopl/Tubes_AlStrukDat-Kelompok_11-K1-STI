#include <stdio.h>
#include "mesinkarakter.h"


int main() {
    char inputMode;
    printf("Pilih mode input ('f' untuk file, 't' untuk terminal): ");
    scanf(" %c", &inputMode);

    if(inputMode == 'f'){
        START('f');

        while(!IsEOP()){
            printf("Karakter : ");
            printf("%c\n", GetCC());
            ADV();
        }

        printf("Karakter sudah habis.\n");
        CLOSE();
    }
    else if (inputMode == 't') {
        FILE *input;
        tambahKata();

        if (pita != NULL) {
            while (!IsEOP()) {
                printf("Karakter : %c\n", GetCC());
                ADV();
            }

            printf("Karakter sudah habis.\n");
        }
    }
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
