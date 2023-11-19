#include "function.h"

void STARTPROG(FILE* input){
    // Inisialisasi variabel
    CreateListPenyanyi(&LP);
    CreateQueue(&Queue);
    CreateHistori(&Histori);
    CreateListPlaylist(&ListPL);

    // Menyimpan data penyanyi, album, dan lagu
    STARTWORD(input);
    LP.penyanyi_length = WordToInt(GetWord());
    for (int i = 0; i < LP.penyanyi_length; i++){
        ADVWORDNOSPACE();
        LP.penyanyi[i].album_length = WordToInt(GetWord());
        ADVWORD();
        LP.penyanyi[i].penyanyi_nama = GetWord();
        for (int j = 0; j < LP.penyanyi[i].album_length; j++){
            LP.penyanyi[i].album_penyanyi[j].penyanyi_id = i;
            ADVWORDNOSPACE();
            LP.penyanyi[i].album_penyanyi[j].lagu_length = WordToInt(GetWord());
            ADVWORD();
            LP.penyanyi[i].album_penyanyi[j].album_nama = GetWord();
            for (int k = 0; k < LP.penyanyi[i].album_penyanyi[j].lagu_length; k++){
                ADVWORD();
                LP.penyanyi[i].album_penyanyi[j].lagu_album[k].lagu_nama = GetWord();
                LP.penyanyi[i].album_penyanyi[j].lagu_album[k].album_id = j;
                LP.penyanyi[i].album_penyanyi[j].lagu_album[k].penyanyi_id = k;
            }
        }
    }
}