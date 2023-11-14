#include "../ADT/mesinkarakter.h"

int main(){
    FILE* input = stdin;
    START(input);
    while (!IsEOP()){
        printf("Karakter: %c\n", GetCC());
        ADV();
    }
    printf("Karakter dalam terminal sudah habis...\n");

    input = fopen("D:/Tugas Besar/src/driver/pitakar.txt", "r");
    START(input);
    while (!IsEOP()){
        printf("Karakter: %c\n", GetCC());
        ADV();
    }
    printf("Karakter dalam file sudah habis...\n");
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

/*
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
        TambahKata();

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
*/