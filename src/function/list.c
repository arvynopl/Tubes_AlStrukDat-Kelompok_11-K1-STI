#include "function.h"

void LISTDEFAULT(){
    if (IsON){
        printf("Daftar Penyanyi :\n");
        for (int i = 0; i < LP.penyanyi_length; i++){
            printf("%d. ", i + 1);
            PrintWord(LP.penyanyi[i].penyanyi_nama);
            printf("\n");
        }
        printf("\n");

        Word ans1;
        printf("Ingin melihat album yang ada?(Y/N): ");
        STARTINPUT();
        ans1 = ToUpper(GetWord());
        if ((ans1.TabWord[0] == 'Y') && (ans1.Length = 1)){
            printf("Pilih penyanyi untuk melihat album mereka: ");
            STARTINPUT();
            ans1 = GetWord();
            if (CheckPenyanyi(LP, ans1)){
                int idpenyanyi = IndexOfPenyanyiStr(LP, ans1);
                printf("\nDaftar Album oleh ");
                PrintWord(ans1);
                printf(" : \n");
                for (int i = 0; i < LP.penyanyi[idpenyanyi].album_length; i++){
                    printf("%d. ", i + 1);
                    PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[i].album_nama);
                    printf("\n");
                }
                printf("\n");
                
                Word ans2;
                printf("Ingin melihat lagu yang ada?(Y/N): ");
                STARTINPUT();
                ans2 = ToUpper(GetWord());
                if ((ans2.TabWord[0] == 'Y') && (ans2.Length = 1)){
                    printf("Pilih album untuk melihat lagu yang ada di album: ");
                    STARTINPUT();
                    ans2 = GetWord();
                    if (CheckAlbum(LP.penyanyi[idpenyanyi], ans2)){
                        int idalbum = IndexOfAlbumStr(LP, ans1, ans2);
                        printf("\nDaftar Lagu di ");
                        PrintWord(ans2);
                        printf(" : \n");
                        for (int i = 0; i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length; i++){
                            printf("%d. ", i + 1);
                            PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i].lagu_nama);
                            printf("\n");
                        }
                    } else{
                        printf("\nAlbum tidak ada dalam daftar. Silakan coba lagi.\n");
                    }
                    
                } else if ((ans2.TabWord[0] == 'N') && (ans2.Length = 1)){

                } else{
                    printf("\nInput selain Y/N adalah invalid. Silakan coba lagi.\n");
                }

            } else{
                printf("\nPenyanyi tidak ada dalam daftar. Silakan coba lagi.\n");
            }

        } else if ((ans1.TabWord[0] == 'N') && (ans1.Length = 1)){

        } else{
            printf("\nInput selain Y/N adalah invalid. Silakan coba lagi.\n");

        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }
    
    CONSOLE();
}

void LISTPLAYLIST(){
    printf("Daftar playlist yang kamu miliki : \n");
    if (ListPL.playlist_length == 0){
        printf("Kamu belum memiliki playlist. Silahkan buat playlist dan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
    } else{
        for (int i = 0; i < ListPL.playlist_length; i++){
            printf("%d. ", i + 1);
            PrintWord(ListPL.playlist[i].playlist_nama);
            printf("\n");
        }
    }

    CONSOLE();
}