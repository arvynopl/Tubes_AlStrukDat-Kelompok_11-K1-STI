#include "function.h"

void PLAYLISTCREATE(){
    if (IsON){
        Word ans;
        printf("Masukkan nama playlist yang ingin dibuat: ");
        STARTINPUT();
        ans = GetWord();
        printf("\n");

        if (!CheckValidInput(ans)){
            printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
        } else{
            NamaPlaylist temp;
            CreatePlaylist(&temp);
            temp.playlist_nama = ans;
            PushPlaylist(&ListPL, temp);
            printf("Playlist ");
            PrintWord(ans);
            printf(" berhasil dibuat!\n");
            printf("Silakan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}

void PLAYLISTADDSONG(){
    if (IsON){
        printf("Daftar Penyanyi :\n");
        for (int i = 0; i < LP.penyanyi_length; i++){
            printf("%d. ", i + 1);
            PrintWord(LP.penyanyi[i].penyanyi_nama);
            printf("\n");
        }
        printf("\n");

        Word ans1;
        printf("Masukkan nama penyanyi yang dipilih: ");
        STARTINPUT();
        ans1 = GetWord();
        if (CheckPenyanyi(LP, ans1)){
            int idpenyanyi = IndexOfPenyanyiStr(LP, ans1);
            printf("\nDaftar Album oleh ");
            PrintWord(LP.penyanyi[idpenyanyi].penyanyi_nama);
            printf(": \n");
            for (int i = 0; i < LP.penyanyi[idpenyanyi].album_length; i++){
                printf("%d. ", i + 1);
                PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[i].album_nama);
                printf("\n");
            }
            printf("\n");

            Word ans2;
            printf("Masukkan judul album yang dipilih: ");
            STARTINPUT();
            ans2 = GetWord();
            if (CheckAlbum(LP.penyanyi[idpenyanyi], ans2)){
                int idalbum = IndexOfAlbumStr(LP, ans1, ans2);
                printf("\nDaftar Lagu Album ");
                PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].album_nama);
                printf(" oleh ");
                PrintWord(LP.penyanyi[idpenyanyi].penyanyi_nama);
                printf(" : \n");
                for (int i = 0; i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length; i++){
                    printf("%d. ", i + 1);
                    PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i].lagu_nama);
                    printf("\n");
                }
                printf("\n");

                int idtemp;
                printf("Masukkan ID lagu yang dipilih: ");
                STARTINPUT();
                idtemp = WordToInt(GetWord());
                idtemp--;
                printf("\n");

                if (idtemp < 0 || idtemp >= LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length){
                    printf("Tidak ada lagu dengan ID %d. Silakan coba lagi.\n", idtemp + 1);

                } else{
                    Lagu addlagu = LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[idtemp];

                    if (ListPL.playlist_length == 0){
                        printf("Kamu belum memiliki playlist. Silahkan buat playlist dan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
                    } else{
                        printf("Daftar playlist pengguna: \n");
                        for (int i = 0; i < ListPL.playlist_length; i++){
                            printf("%d. ", i + 1);
                            PrintWord(ListPL.playlist[i].playlist_nama);
                            printf("\n");
                        }
                        printf("\n");

                        printf("Masukkan ID Playlist yang dipilih: ");
                        STARTINPUT();
                        idtemp = WordToInt(GetWord());
                        idtemp--;

                        if (idtemp < 0 || idtemp >= ListPL.playlist_length){
                            printf("Tidak ada playlist dengan playlist ID %d. Silakan coba lagi.\n", idtemp + 1);
                        } else{
                            if (CheckLaguPlaylist(ListPL.playlist[idtemp], addlagu)){
                                printf("Lagu sudah ada di dalam playlist. Silakan masukkan lagu yang belum ada di dalam playlist.\n");
                            } else{
                                InsertLastPlaylist(&(ListPL.playlist[idtemp]), addlagu);
                                
                                printf("Lagu dengan judul \"");
                                PrintWord(addlagu.lagu_nama);
                                printf("\" pada album ");
                                PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].album_nama);
                                printf(" oleh penyanyi ");
                                PrintWord(LP.penyanyi[idpenyanyi].penyanyi_nama);
                                printf(" berhasil ditambahkan ke dalam playlist ");
                                PrintWord(ListPL.playlist[idtemp].playlist_nama);
                                printf(".\n");
                            }
                        }
                    }                  
                }

            } else{
                printf("\nAlbum tidak ada dalam daftar. Silakan coba lagi.\n");
            }

        } else{
            printf("\nPenyanyi tidak ada dalam daftar. Silakan coba lagi.\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}

void PLAYLISTADDALBUM(){
    if (IsON){
        printf("Daftar Penyanyi :\n");
        for (int i = 0; i < LP.penyanyi_length; i++){
            printf("%d. ", i + 1);
            PrintWord(LP.penyanyi[i].penyanyi_nama);
            printf("\n");
        }
        printf("\n");

        Word ans1;
        printf("Masukkan nama penyanyi yang dipilih: ");
        STARTINPUT();
        ans1 = GetWord();
        if (CheckPenyanyi(LP, ans1)){
            int idpenyanyi = IndexOfPenyanyiStr(LP, ans1);
            printf("\nDaftar Album oleh ");
            PrintWord(LP.penyanyi[idpenyanyi].penyanyi_nama);
            printf(": \n");
            for (int i = 0; i < LP.penyanyi[idpenyanyi].album_length; i++){
                printf("%d. ", i + 1);
                PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[i].album_nama);
                printf("\n");
            }
            printf("\n");

            Word ans2;
            printf("Masukkan judul album yang dipilih: ");
            STARTINPUT();
            ans2 = GetWord();
            if (CheckAlbum(LP.penyanyi[idpenyanyi], ans2)){
                int idalbum = IndexOfAlbumStr(LP, ans1, ans2);
        
                if (ListPL.playlist_length == 0){
                    printf("Kamu belum memiliki playlist. Silahkan buat playlist dan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
                } else{
                    printf("Daftar playlist pengguna: \n");
                    for (int i = 0; i < ListPL.playlist_length; i++){
                        printf("%d. ", i + 1);
                        PrintWord(ListPL.playlist[i].playlist_nama);
                        printf("\n");
                    }
                    printf("\n");
                    
                    printf("Masukkan ID Playlist yang dipilih: ");
                    STARTINPUT();
                    int idplaylist = WordToInt(GetWord());
                    idplaylist--;

                    if (idplaylist < 0 || idplaylist >= ListPL.playlist_length){
                        printf("Tidak ada playlist dengan playlist ID %d. Silakan coba lagi.\n", idplaylist + 1);
                    } else{
                        for (int i = 0; i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length; i++){
                            Lagu temp = LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i];
                            if (!CheckLaguPlaylist(ListPL.playlist[idplaylist], temp)){
                                InsertLastPlaylist(&(ListPL.playlist[idplaylist]), temp);
                            }
                        }

                        printf("Album dengan judul \"");
                        PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].album_nama);
                        printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
                        PrintWord(ListPL.playlist[idplaylist].playlist_nama);
                        printf("\".\n");
                    }
                } 

            } else{
                printf("\n tidak ada dalam daftar. Silakan coba lagi.\n");
            }

        } else{
            printf("\nPenyanyi tidak ada dalam daftar. Silakan coba lagi.\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }  

    CONSOLE();

}

void PLAYLISTSWAP(int id, int x, int y){
    if (IsON){
        id--;
        x--;
        y--;

        if ((id < 0) || (id >= ListPL.playlist_length)){
            printf("Tidak ada playlist dengan playlist ID %d. Silakan coba lagi.\n", id + 1);
        } else{
            NamaPlaylist* P = &(ListPL.playlist[id]);
            int n = LengthOfPlaylist(*P);
            
            if (x < 0 || x >= n || y < 0 || y >= n){
                if (x < 0 || x >= n){
                    printf("Tidak ada lagu dengan urutan %d di playlist \"", x + 1);
                    PrintWord((*P).playlist_nama);
                    printf("\". Silakan coba lagi.\n");
                } else if (y < 0 || y >= n){
                    printf("Tidak ada lagu dengan urutan %d di playlist \"", y + 1);
                    PrintWord((*P).playlist_nama);
                    printf("\". Silakan coba lagi.\n");
                }
            } else{
                Address LX = (*P).list;
                Address LY = (*P).list;
                for (int i = 0; i < x; i++){
                    LX = (*LX).next;
                }
                for (int i = 0; i < y; i++){
                    LY = (*LY).next;
                }
                Lagu temp;
                temp = (*LX).lagu_playlist;
                (*LX).lagu_playlist = (*LY).lagu_playlist;
                (*LY).lagu_playlist = temp;

                printf("Berhasil menukar lagu dengan nama \"");
                PrintWord((*LY).lagu_playlist.lagu_nama);
                printf("\" dengan \"");
                PrintWord((*LX).lagu_playlist.lagu_nama);
                printf("\" di playlist \"");
                PrintWord((*P).playlist_nama);
                printf("\".\n");
            }
        }      

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}

void PLAYLISTREMOVE(int id, int n){
    if (IsON){
        id--;
        n--;

        if ((id < 0) || (id >= ListPL.playlist_length)){
            printf("Tidak ada playlist dengan playlist ID %d. Silakan coba lagi.\n", id + 1);
        } else{
            int x = LengthOfPlaylist(ListPL.playlist[id]);
            NamaPlaylist *P = &(ListPL.playlist[id]);
            if (n < 0 || n >= x){
                printf("Tidak ada lagu dengan urutan %d di playlist \"", n + 1);
                PrintWord((*P).playlist_nama);
                printf("\". Silakan coba lagi.\n");

            } else{
                Lagu temp;
                DeleteAtPlaylist(P, n, &temp);

                printf("Lagu \"");
                PrintWord(temp.lagu_nama);
                printf("\" oleh \"");
                PrintWord(LP.penyanyi[temp.penyanyi_id].penyanyi_nama);
                printf("\" telah dihapus dari playlist \"");
                PrintWord((*P).playlist_nama);
                printf("\".\n");
            }
        }
    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}

void PLAYLISTDELETE(){
    if (IsON){
        printf("Daftar playlist yang kamu miliki: \n");
        if (ListPL.playlist_length == 0){
            printf("Kamu belum memiliki playlist. Silahkan buat playlist dan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
        } else{
            for (int i = 0; i < ListPL.playlist_length; i++){
                printf("%d. ", i + 1);
                PrintWord(ListPL.playlist[i].playlist_nama);
                printf("\n");
            }
            printf("\n");

            int ans;
            printf("Masukkan ID playlist yang dipilih: ");
            STARTINPUT();
            ans = WordToInt(GetWord());
            ans--;
            printf("\n");

            int n = ListPL.playlist_length;
            Word temp = ListPL.playlist[ans].playlist_nama;
            if (ans < 0 || ans >= n){
                printf("\nTidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", ans + 1);
            } else{
                FreePlaylist(&ListPL, &(ListPL.playlist[ans]));
                printf("Playlist ID %d dengan judul \"", ans + 1);
                PrintWord(temp);
                printf("\" berhasil dihapus.\n");
            }

        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();
}

void PLAYLISTENHANCE() {
    if (IsON){
        printf("Masukkan ID Playlist yang dipilih: ");
        STARTINPUT();
        int idplaylist = WordToInt(GetWord());
        idplaylist--;
        printf("\n");

        if (idplaylist >= 0 && idplaylist < (ListPL).playlist_length) {
            
            Lagu hasilRekomendasi[5];

            printf("Daftar lagu rekomendasi WayangWave : \n");
            for (int i = 0; i < 5; i++) {
                int penyanyi_index = (int) RAND() % (LP.penyanyi_length - 1);
                int album_index = (int) RAND() % (LP.penyanyi[penyanyi_index].album_length - 1);
                int lagu_index = (int) RAND() % (LP.penyanyi[penyanyi_index].album_penyanyi[album_index].lagu_length - 1);
                
                hasilRekomendasi[i] = LP.penyanyi[penyanyi_index].album_penyanyi[album_index].lagu_album[lagu_index];

                printf("%d. ", i + 1);
                PrintWord(LP.penyanyi[penyanyi_index].penyanyi_nama);
                printf(" - ");
                PrintWord(LP.penyanyi[penyanyi_index].album_penyanyi[album_index].album_nama);
                printf(" - ");
                PrintWord(LP.penyanyi[penyanyi_index].album_penyanyi[album_index].lagu_album[lagu_index].lagu_nama);
                prinf("\n");
            }

            Word ans;
            printf ("Apakah ada lagu yang ingin tambahkan ke dalam playlist?(Y/N): ");
            STARTINPUT();
            ans = ToUpper(GetWord());
            printf("\n");

            if ((ans.TabWord[0] == 'Y') && (ans.Length == 1)){
                int id1 = INT_UNDEF, id2 = INT_UNDEF, id3 = INT_UNDEF, id4 = INT_UNDEF, id5 = INT_UNDEF;
                printf("Lagu apa yang ingin Anda tambahkan ke dalam playlist? Pilih ID lagu yang diinginkan (contoh: 1 2 3): ");
                STARTCOMMAND();
                id1 = WordToInt(GetWord());
                id1--;
                if (id1 != INT_UNDEF){
                    ADVINPUT();
                    id2 = WordToInt(GetWord());
                    id2--;
                    if (id2 != INT_UNDEF){
                        ADVINPUT();
                        id3 = WordToInt(GetWord());
                        id3--;
                        if (id3 != INT_UNDEF){
                            ADVINPUT();
                            id4 = WordToInt(GetWord());
                            id4--;
                            if (id4 != INT_UNDEF){
                                ADVINPUT();
                                id5 = WordToInt(GetWord());
                                id5--;
                            }
                        }
                    }
                } else{
                    printf("Anda tidak memasukkan ID lagu yang diinginkan. Silakan coba lagi.\n");
                    CONSOLE();
                }
                printf("\n");

                int n = LengthOfPlaylist(ListPL.playlist[idplaylist]);
                if (id1 >= 0 || id1 < n){
                    if (CheckLaguPlaylist(ListPL.playlist[idplaylist], hasilRekomendasi[id1])) {
                        printf("Lagu sudah ada di dalam playlist. Silakan masukkan lagu yang belum ada di dalam playlist.\n");
                    } else {
                        InsertLastPlaylist(&(ListPL.playlist[idplaylist]), hasilRekomendasi[id1]);
                    }
                } else{
                    printf("Tidak ada lagu dengan ID %d. Silakan coba lagi.\n", id1 + 1);
                }
                if (id2 != INT_UNDEF){
                    if (id2 >= 0 || id2 < n){
                        if (CheckLaguPlaylist(ListPL.playlist[idplaylist], hasilRekomendasi[id2])) {
                            printf("Lagu sudah ada di dalam playlist. Silakan masukkan lagu yang belum ada di dalam playlist.\n");
                        } else {
                            InsertLastPlaylist(&(ListPL.playlist[idplaylist]), hasilRekomendasi[id2]);
                        }
                    } else{
                        printf("Tidak ada lagu dengan ID %d. Silakan coba lagi.\n", id2 + 1);
                    }                  
                }
                if (id3 != INT_UNDEF){
                    if (id3 >= 0 || id3 < n){
                        if (CheckLaguPlaylist(ListPL.playlist[idplaylist], hasilRekomendasi[id3])) {
                            printf("Lagu sudah ada di dalam playlist. Silakan masukkan lagu yang belum ada di dalam playlist.\n");
                        } else {
                            InsertLastPlaylist(&(ListPL.playlist[idplaylist]), hasilRekomendasi[id3]);
                        }
                    } else{
                        printf("Tidak ada lagu dengan ID %d. Silakan coba lagi.\n", id3 + 1);
                    }                  
                }
                if (id4 != INT_UNDEF){
                    if (id4 >= 0 || id4 < n){
                        if (CheckLaguPlaylist(ListPL.playlist[idplaylist], hasilRekomendasi[id4])) {
                            printf("Lagu sudah ada di dalam playlist. Silakan masukkan lagu yang belum ada di dalam playlist.\n");
                        } else {
                            InsertLastPlaylist(&(ListPL.playlist[idplaylist]), hasilRekomendasi[id4]);
                        }
                    } else{
                        printf("Tidak ada lagu dengan ID %d. Silakan coba lagi.\n", id4 + 1);
                    }                  
                }
                if (id5 != INT_UNDEF){
                    if (id5 >= 0 || id5 < n){
                        if (CheckLaguPlaylist(ListPL.playlist[idplaylist], hasilRekomendasi[id5])) {
                            printf("Lagu sudah ada di dalam playlist. Silakan masukkan lagu yang belum ada di dalam playlist.\n");
                        } else {
                            InsertLastPlaylist(&(ListPL.playlist[idplaylist]), hasilRekomendasi[id5]);
                        }
                    } else{
                        printf("Tidak ada lagu dengan ID %d. Silakan coba lagi.\n", id5 + 1);
                    }                  
                }

                if (id1 != INT_UNDEF && id2 == INT_UNDEF){
                    printf("Lagu rekomendasi berhasil ditambahkan ke dalam playlist.\n");
                } else if (id1 != INT_UNDEF && (id2 != INT_UNDEF || id3 != INT_UNDEF || id4 != INT_UNDEF || id5 != INT_UNDEF)){
                    printf("Lagu-lagu rekomendasi berhasil ditambahkan ke dalam playlist.\n");
                }
                
            } else if ((ans.TabWord[0] == 'N') && (ans.Length == 1)){
                printf("Baiklah, kami mengerti bahwa Anda memilih untuk tidak menambahkan lagu ke dalam playlist.\n");
                printf("Apakah Anda ingin mencoba untuk mencari lagu-lagu rekomendasi lain?(Y/N): ");
                STARTINPUT();
                ans = ToUpper(GetWord());
                printf("\n");

                if ((ans.TabWord[0] == 'Y') && (ans.Length == 1)){
                    PLAYLISTENHANCE();
                } else if ((ans.TabWord[0] == 'N') && (ans.Length == 1)){
                    CONSOLE();
                } else{
                    printf("\nInput selain Y/N adalah invalid. Silakan coba lagi.\n");
                    CONSOLE();
                }
                
            } else{
                printf("\nInput selain Y/N adalah invalid. Silakan coba lagi.\n");
            }

        } else{
            printf("\nTidak ada playlist dengan playlist ID %d. Silakan coba lagi.\n", idplaylist + 1);
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}