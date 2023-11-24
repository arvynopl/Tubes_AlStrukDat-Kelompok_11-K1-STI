#include "function.h"

void LOADPROG(FILE* input){
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

        // Menyimpan data currSong
        ADVWORD();
        if (GetWord().TabWord[0] != '-'){
            Word temp = GetWord();
            currSong.penyanyi_id = IndexOfPenyanyiStr(LP, temp);
            ADVWORD();
            currSong.album_id = IndexOfAlbumStr(LP, temp, GetWord());
            ADVWORD();
            currSong.lagu_nama = GetWord();
        } else{
            currSong.album_id = IDX_UNDEF;
            currSong.penyanyi_id = IDX_UNDEF;
            currSong.lagu_nama.Length = 0;
            currSong.lagu_nama.TabWord[0] = STR_UNDEF;
        }

        // Menyimpan data queue lagu
        ADVWORD();
        int nQueue = WordToInt(GetWord()); 
        for (int i = 0; i < nQueue; i++){
            Lagu lagu_queue;
            ADVWORD();
            Word temp = GetWord();
            lagu_queue.penyanyi_id = IndexOfPenyanyiStr(LP, temp);
            ADVWORD();
            lagu_queue.album_id = IndexOfAlbumStr(LP, temp, GetWord());
            ADVWORD();
            lagu_queue.lagu_nama = GetWord();
            Enqueue(&Queue, lagu_queue);
        }

        // Menyimpan data histori lagu
        ADVWORD();
        int nStack = WordToInt(GetWord()); 
        for (int i = 0; i < nStack; i++){
            Lagu lagu_stack;
            ADVWORD();
            Word temp = GetWord();
            lagu_stack.penyanyi_id = IndexOfPenyanyiStr(LP, temp);
            ADVWORD();
            lagu_stack.album_id = IndexOfAlbumStr(LP, temp, GetWord());
            ADVWORD();
            lagu_stack.lagu_nama = GetWord();
            Push(&Histori, lagu_stack);
        }

        // Menyimpan data playlist
        ADVWORD();
        int nPlaylist = WordToInt(GetWord());
        for (int i = 0; i < nPlaylist; i++){
            ADVWORDNOSPACE();
            int nLaguPlaylist = WordToInt(GetWord());

            NamaPlaylist playlist;
            CreatePlaylist(&playlist);
            ADVWORD();
            playlist.playlist_nama = GetWord();

            for (int j = 0; j < nLaguPlaylist; j++){
                Lagu lagu_playlist;
                ADVWORD();
                Word temp = GetWord();
                lagu_playlist.penyanyi_id = IndexOfPenyanyiStr(LP, temp);
                ADVWORD();
                lagu_playlist.album_id = IndexOfAlbumStr(LP, temp, GetWord());
                ADVWORD();
                lagu_playlist.lagu_nama = GetWord();
                InsertLastPlaylist(&playlist, lagu_playlist);
            }
            
            PushPlaylist(&ListPL, playlist);
        }

        CLOSE(); 

        IsON = true;
        printf("\nSave file berhasil dibaca. WayangWave berhasil dijalankan.\n");

    } else{
        printf("Anda sudah masuk ke dalam program sebelumnya...\n");
    }
}