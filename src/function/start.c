#include "function.h"

void STARTPROG(FILE* input){
    if (!IsON){
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
                int n = LP.penyanyi[i].album_penyanyi[j].lagu_length;
                ADVWORD();
                LP.penyanyi[i].album_penyanyi[j].album_nama = GetWord();
                for (int k = 0; k < n; k++){
                    ADVWORD();
                    if (!CheckLagu(LP.penyanyi[i].album_penyanyi[j], GetWord())){
                        LP.penyanyi[i].album_penyanyi[j].lagu_album[k].lagu_nama = GetWord();
                        LP.penyanyi[i].album_penyanyi[j].lagu_album[k].album_id = j;
                        LP.penyanyi[i].album_penyanyi[j].lagu_album[k].penyanyi_id = i;
                    } else{
                        LP.penyanyi[i].album_penyanyi[j].lagu_length--;
                    }
                }
            }
        }

        CLOSE();

        IsON = true;
        printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");

    } else{
        printf("Anda sudah masuk ke dalam program sebelumnya...\n");
    }
    
    CONSOLE();

}