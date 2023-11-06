#include <stdio.h>
#include "mesinkata.h"

int main(){
    printf("\n---Function toKata dan Procedure PrintWord---\n");
    Word hasilKata1 = toKata("Tubes");
    Word hasilKata2 = toKata("Spotify");
    printf("\nKata ke-1 : ");
    PrintWord(hasilKata1);
    printf("\n");
    printf("Kata ke-2 : ");
    PrintWord(hasilKata2);
    printf("\n");

    printf("\n---WordCompare---\n");
    printf("\nKata ke-1 adalah Tubes\n");
    printf("Kata ke-2 adalah Spotify\n");
    if(WordCompare(hasilKata1, hasilKata2)){
        printf("\nKata ke-1 dan kata ke-2 merupakan kata yang sama.\n");
    }
    else{
        printf("\nKata ke-1 dan kata ke-2 bukan kata yang sama.\n");
    }

    printf("\n---Function unionWord dan Function WordToStr---\n");
    char *kata1 = WordToStr(hasilKata1);
    Word hasilUnion = unionWord(kata1, hasilKata2);
    printf("\n");
    PrintWord(hasilUnion);
    printf("\n");

    printf("\n---Function unionWord dan Function WordToStr---\n");
    concatWord(&hasilKata1, hasilKata2);
    printf("\n");
    PrintWord(hasilKata1);
    printf("\n");

    printf("\n---Function toLower dan Function toLower toUpper---\n");
    Word kapital = toUpper(hasilKata1);
    printf("\nHasil kapital : ");
    PrintWord(kapital);

    Word nonkapital = toLower(hasilKata1);
    printf("\nHasil nonkapital : ");
    PrintWord(nonkapital);
    printf("\n");

    return 0;
}