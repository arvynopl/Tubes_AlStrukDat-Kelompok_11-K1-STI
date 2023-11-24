// structure.c
#include "structure.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LCG_A 1664525
#define LCG_C 1013904223
#define LCG_M 4294967296 

unsigned int lcg_seed; 


unsigned int custom_rand() {
    lcg_seed = (LCG_A * lcg_seed + LCG_C) % LCG_M;
    return lcg_seed;
}

void Enhance(ListPenyanyi *LP) {
    if (IsON){
        printf("Masukkan ID Playlist yang dipilih: ");
        STARTINPUT();
        int idplaylist = WordToInt(GetWord());

        usleep(100000);

        // Inisialisasi seed berdasarkan waktu
        lcg_seed = (unsigned int)time(NULL);

        Lagu hasilRekomendasi[6];

        for (int i = 0; i < 6; i++) {
            int penyanyi_index = custom_rand() % LP->penyanyi_length;
            Penyanyi penyanyi = LP->penyanyi[penyanyi_index];

            int album_index = custom_rand() % penyanyi.album_length;
            Album album = penyanyi.album_penyanyi[album_index];

            int lagu_index = custom_rand() % album.lagu_length;
            Lagu lagu;

           
            lagu.lagu_nama = album.lagu_album[lagu_index].lagu_nama;
            lagu.album_id = album.lagu_album[lagu_index].album_id;
            lagu.penyanyi_id = album.lagu_album[lagu_index].penyanyi_id;

            
            hasilRekomendasi[i] = lagu;

            printf("%d. %s - %s (%s)\n", i + 1, penyanyi.penyanyi_nama.TabWord, album.album_nama.TabWord, lagu.lagu_nama.TabWord);
        }
        Word ans;
        printf ("Apakah ada lagu yang ingin tambahkan ke dalam playlist?(Y/N)");
        STARTINPUT();
        ans = ToUpper(GetWord());
        if ((ans.TabWord[0] == 'Y') && (ans.Length = 1)){
            printf("Lagu apa yang ingin Anda tambahkan ke dalam playlist ?");
            Word ans1;
            STARTINPUT();
            ans1 = GetWord();

            if (idplaylist >= 0 && idplaylist < (ListPL).playlist_length) {
                for (int i = 0; i < 6; i++) {
                    if (WordCompare(ans1, hasilRekomendasi[i].lagu_nama)) {
                        if (CheckLaguPlaylist(ListPL.playlist[idplaylist], hasilRekomendasi[i])) {
                            printf("Lagu sudah ada di dalam playlist. Silakan masukkan lagu yang belum ada di dalam playlist.\n");
                        } else {
                            InsertLastPlaylist(&(ListPL.playlist[idplaylist]), hasilRekomendasi[i]);
                            printf("Lagu berhasil ditambahkan ke dalam playlist.\n");
                        }
                    }
                }
            } else {
                printf("ID Playlist tidak valid.\n");
            }
        }else{
            printf("Anda memilih untuk tidak menambahkan lagu ke dalam playlist.\n");
            
        }
        
    }else{
        printf("Anda belum masuk ke dalam program...\n");
    }
    CONSOLE();
}
    
