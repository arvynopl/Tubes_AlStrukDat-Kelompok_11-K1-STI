#include "function.h"

void SAVEPROG(FILE* input){
    if (IsON){
        // Menuliskan banyak penyanyi
        fprintf(input, "%d\n", LP.penyanyi_length);
        
        // Menuliskan data penyanyi, album, dan lagu
        for (int i = 0; i < LP.penyanyi_length; i++){
            fprintf(input, "%d ", LP.penyanyi[i].album_length);
            for (int l = 0; l < LP.penyanyi[i].penyanyi_nama.Length; l++){
                if (l < LP.penyanyi[i].penyanyi_nama.Length - 1){
                    fprintf(input, "%c", LP.penyanyi[i].penyanyi_nama.TabWord[l]);
                } else{
                    fprintf(input, "%c\n", LP.penyanyi[i].penyanyi_nama.TabWord[l]);
                }
            }
            for (int j = 0; j < LP.penyanyi[i].album_length; j++){
                fprintf(input, "%d ", LP.penyanyi[i].album_penyanyi[j].lagu_length);
                for (int m = 0; m < LP.penyanyi[i].album_penyanyi[j].album_nama.Length; m++){
                    if (m < LP.penyanyi[i].album_penyanyi[j].album_nama.Length - 1){
                        fprintf(input, "%c", LP.penyanyi[i].album_penyanyi[j].album_nama.TabWord[m]);
                    } else{
                        fprintf(input, "%c\n", LP.penyanyi[i].album_penyanyi[j].album_nama.TabWord[m]);
                    }
                }
                for (int k = 0; k < LP.penyanyi[i].album_penyanyi[j].lagu_length; k++){
                    for (int n = 0; n < LP.penyanyi[i].album_penyanyi[j].lagu_album[k].lagu_nama.Length; n++){
                        if (n < LP.penyanyi[i].album_penyanyi[j].lagu_album[k].lagu_nama.Length - 1){
                            fprintf(input, "%c", LP.penyanyi[i].album_penyanyi[j].lagu_album[k].lagu_nama.TabWord[n]);
                        } else{
                            fprintf(input, "%c\n", LP.penyanyi[i].album_penyanyi[j].lagu_album[k].lagu_nama.TabWord[n]);
                        }
                    }
                }
            }
        }

        // Menuliskan data lagu yang sedang dimainkan
        if (currSong.album_id != IDX_UNDEF && currSong.penyanyi_id != IDX_UNDEF){
            for (int i = 0; i < LP.penyanyi[currSong.penyanyi_id].penyanyi_nama.Length; i++){
                fprintf(input, "%c", LP.penyanyi[currSong.penyanyi_id].penyanyi_nama.TabWord[i]);
            }
            fprintf(input, ";");
            for (int i = 0; i < LP.penyanyi[currSong.penyanyi_id].album_penyanyi[currSong.album_id].album_nama.Length; i++){
                fprintf(input, "%c", LP.penyanyi[currSong.penyanyi_id].album_penyanyi[currSong.album_id].album_nama.TabWord[i]);
            }
            fprintf(input, ";");
            for (int i = 0; i < currSong.lagu_nama.Length; i++){
                if (i < currSong.lagu_nama.Length - 1){
                    fprintf(input, "%c", currSong.lagu_nama.TabWord[i]);
                } else{
                    fprintf(input, "%c\n", currSong.lagu_nama.TabWord[i]);
                }
            }
        } else{
            fprintf(input, "-\n");
        }

        // Menuliskan jumlah record lagu dalam queue
        fprintf(input, "%d\n", LengthOfQueue(Queue));

        // Menuliskan record lagu dalam queue
        for (int i = Queue.idxHead; i <= Queue.idxTail; i++){
            Lagu temp = Queue.lagu_queue[i];
            for (int j = 0; j < LP.penyanyi[temp.penyanyi_id].penyanyi_nama.Length; j++){
                fprintf(input, "%c", LP.penyanyi[temp.penyanyi_id].penyanyi_nama.TabWord[j]);
            }
            fprintf(input, ";");
            for (int j = 0; j < LP.penyanyi[temp.penyanyi_id].album_penyanyi[temp.album_id].album_nama.Length; j++){
                fprintf(input, "%c", LP.penyanyi[temp.penyanyi_id].album_penyanyi[temp.album_id].album_nama.TabWord[j]);
            }
            fprintf(input, ";");
            for (int j = 0; j < temp.lagu_nama.Length; j++){
                if (j < temp.lagu_nama.Length - 1){
                    fprintf(input, "%c", temp.lagu_nama.TabWord[j]);
                } else{
                    fprintf(input, "%c\n", temp.lagu_nama.TabWord[j]);
                }
            }
            if (i == MaxEl){
                i = 0;
            }
        }

        // Menuliskan jumlah record riwayat pemutaran lagu
        fprintf(input, "%d\n", LengthOfHistori(Histori));

        // Menuliskan record lagu dalam riwayat pemutaran lagu
        for (int i = 0; i <= Histori.idxTop; i++){
            Lagu temp = Histori.lagu_histori[i];
            for (int j = 0; j < LP.penyanyi[temp.penyanyi_id].penyanyi_nama.Length; j++){
                fprintf(input, "%c", LP.penyanyi[temp.penyanyi_id].penyanyi_nama.TabWord[j]);
            }
            fprintf(input, ";");
            for (int j = 0; j < LP.penyanyi[temp.penyanyi_id].album_penyanyi[temp.album_id].album_nama.Length; j++){
                fprintf(input, "%c", LP.penyanyi[temp.penyanyi_id].album_penyanyi[temp.album_id].album_nama.TabWord[j]);
            }
            fprintf(input, ";");
            for (int j = 0; j < temp.lagu_nama.Length; j++){
                if (j < temp.lagu_nama.Length - 1){
                    fprintf(input, "%c", temp.lagu_nama.TabWord[j]);
                } else{
                    fprintf(input, "%c\n", temp.lagu_nama.TabWord[j]);
                }
            }
            if (i == MaxEl){
                i = 0;
            }
        }

        // Menuliskan jumlah playlist
        fprintf(input, "%d\n", ListPL.playlist_length);

        // Menuliskan data playlist
        for (int i = 0; i < ListPL.playlist_length; i++){
            fprintf(input, "%d ", LengthOfPlaylist(ListPL.playlist[i]));
            for (int l = 0; l < ListPL.playlist[i].playlist_nama.Length; l++){
                if (l < ListPL.playlist[i].playlist_nama.Length - 1){
                    fprintf(input, "%c", ListPL.playlist[i].playlist_nama.TabWord[l]);
                } else{
                    fprintf(input, "%c\n", ListPL.playlist[i].playlist_nama.TabWord[l]);
                }
            }
            Address P = ListPL.playlist[i].list;
            while (P != NULL){
                Lagu temp = (*P).lagu_playlist;
                for (int j = 0; j < LP.penyanyi[(*P).lagu_playlist.penyanyi_id].penyanyi_nama.Length; j++){
                    fprintf(input, "%c", LP.penyanyi[(*P).lagu_playlist.penyanyi_id].penyanyi_nama.TabWord[j]);
                }
                fprintf(input, ";");
                for (int j = 0; j < LP.penyanyi[(*P).lagu_playlist.penyanyi_id].album_penyanyi[(*P).lagu_playlist.album_id].album_nama.Length; j++){
                    fprintf(input, "%c", LP.penyanyi[(*P).lagu_playlist.penyanyi_id].album_penyanyi[(*P).lagu_playlist.album_id].album_nama.TabWord[j]);
                }
                fprintf(input, ";");
                for (int j = 0; j < temp.lagu_nama.Length; j++){
                    if (j < temp.lagu_nama.Length - 1){
                        fprintf(input, "%c", temp.lagu_nama.TabWord[j]);
                    } else{
                        fprintf(input, "%c\n", temp.lagu_nama.TabWord[j]);
                    }
                }
                P = (*P).next;
            }
        }

        CLOSE(input);
        printf("Save file berhasil disimpan.\n");
        printf("\n");

    } else{
        printf("Anda belum masuk ke dalam program...\n");
        printf("\n");
    }   
}