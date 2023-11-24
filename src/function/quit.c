#include "function.h"

void QUITPROG(){
    if (IsON){
        Word ans;
        printf("Apakah kamu ingin menyimpan data sesi sekarang?(Y/N): ");
        STARTINPUT();
        ans = ToUpper(GetWord());

        if ((ans.TabWord[0] == 'Y') && (ans.Length = 1)){
            Word ans;
            printf("\nMasukkan nama file sebagai lokasi penyimpanan data: ");
            STARTINPUT();
            ans = GetWord();

            Word dir;
            dir = ToKata("save/");
            ConcatWordNoSpace(&dir, ans);

            char* file = WordToStr(dir);

            FILE* input = fopen(file, "w");
            SAVEPROG(input);
            IsON = false;
            printf("Kamu keluar dari WayangWave.\n");
            exit(0);
        } else if ((ans.TabWord[0] == 'N') && (ans.Length = 1)){
            IsON = false;
            printf("Kamu keluar dari WayangWave.\n");
            exit(0);
        } else{
            printf("Input selain Y/N adalah invalid. Silakan coba lagi.\n");
            CONSOLE();
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
        CONSOLE();
    }

}