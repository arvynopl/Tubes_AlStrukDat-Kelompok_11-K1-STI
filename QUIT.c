#include <stdio.h>
#include "QUIT.h"

/*TEMPORARY FUNCTION*/
void SAVE(){
    printf("Saving..\n");
}

void QUIT(){
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N) ? ");

    Word answer;
    scanf("%s", answer.TabWord);
    int count = 0;
    int i = 0;
    while (i != MaxEl && answer.TabWord[i] != STR_UNDEF){
        if (answer.TabWord[i] != STR_UNDEF){
            count += 1;
        }
        i += 1;
    }
    answer.Length = count;

    Word YES;
    YES = ToKata("Y");
    YES.Length = StringLength("Y");

    Word NO;
    NO = ToKata("N");
    NO.Length = StringLength("N");

    if (WordCompare(answer,YES)){
        SAVE();
        printf("Kamu keluar dari WayangWave.\n");
        exit(0);
    }
    else if (WordCompare(answer,NO)){
        printf("Kamu keluar dari WayangWave.\n");
        exit(0);
    }
    else{
        QUIT();
    }
}