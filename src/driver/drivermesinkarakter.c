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