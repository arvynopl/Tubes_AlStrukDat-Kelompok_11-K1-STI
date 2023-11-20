#include "function.h"

void LISTDEFAULT(){
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
    if (ans1.TabWord[0] == 'Y'){
        printf("Pilih penyanyi untuk melihat album mereka: ");
        STARTINPUT();
        ans1 = GetWord();
        if (CheckPenyanyi(LP, ans1)){
            int idpenyanyi = IndexOfPenyanyiStr(LP, ans1);
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
            if (ans2.TabWord[0] == 'Y'){
                printf("Pilih album untuk melihat lagu yang ada di album: ");
                STARTINPUT();
                if (CheckAlbum(LP.penyanyi[idpenyanyi], ans2)){
                    ans2 = GetWord();
                    int idalbum = IndexOfAlbumStr(LP, ans1, ans2);
                    for (int i = 0; i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length; i++){
                        printf("%d. ", i + 1);
                        PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i].lagu_nama);
                        printf("\n");
                    }
                    printf("\n");
                } else{
                    printf("Album tidak ada...\n");
                }
            } else if (ans2.TabWord[0] == 'N'){
                printf("\n");

            } else{
                printf("Input invalid...\n");
            }

        } else{
            printf("Penyanyi tidak ada...\n");
        }

    } else if (ans1.TabWord[0] == 'N'){
        printf("\n");

    } else{
        printf("Input invalid...\n");
    }

}

void LISTPLAYLIST(){
    printf("Daftar playlist yang kamu miliki: \n");
    if (ListPL.playlist_length == 0){
        printf("Kamu tidak memiliki playlist.\n");
    } else{
        for (int i = 0; i < ListPL.playlist_length; i++){
            printf("%d. ", i + 1);
            PrintWord(ListPL.playlist[i].playlist_nama);
            printf("\n");
        }
        printf("\n");
    }
}