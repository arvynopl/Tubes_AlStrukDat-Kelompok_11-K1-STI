#include "function.h"

void PLAYLISTCREATE(){
    if (IsON){
        Word ans;
        printf("Masukkan nama playlist yang ingin dibuat: ");
        STARTINPUT();
        ans = GetWord();

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

    printf("\n");
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

            } else{
                printf("Album tidak ada dalam daftar. Silakan coba lagi.\n");
            }

        } else{
            printf("Penyanyi tidak ada dalam daftar. Silakan coba lagi.\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    printf("\n");
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

            } else{
                printf("Album tidak ada dalam daftar. Silakan coba lagi.\n");
            }

        } else{
            printf("Penyanyi tidak ada dalam daftar. Silakan coba lagi.\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }  

    printf("\n");
    CONSOLE();

}

void PLAYLISTSWAP(){
    if (IsON){
        int rep;
        printf("Masukkan ID playlist yang berisikan lagu yang ingin ditukar: ");
        STARTINPUT();
        rep = WordToInt(GetWord());
        int id = rep;
        id--;
        printf("\nMasukkan ID lagu pertama yang ingin ditukar: ");
        STARTINPUT();
        rep = WordToInt(GetWord());
        int x = rep;
        x--;
        printf("\nMasukkan ID lagu kedua yang ingin ditukar: ");
        STARTINPUT();
        rep = WordToInt(GetWord());
        int y = rep;
        y--;
        printf("\n");

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

    printf("\n");
    CONSOLE();

}

void PLAYLISTREMOVE(){
    if (IsON){
        int rep;
        printf("Masukkan ID playlist yang berisikan lagu yang ingin dihapus: ");
        STARTINPUT();
        rep = WordToInt(GetWord());
        int id = rep;
        id--;
        printf("\nMasukkan ID lagu yang ingin dihapus: ");
        STARTINPUT();
        rep = WordToInt(GetWord());
        int n = rep;
        n--;
        printf("\n");

        if ((id < 0) || (id >= ListPL.playlist_length)){
            printf("Tidak ada playlist dengan playlist ID %d. Silakan coba lagi.\n", id);
        } else{
            int x = LengthOfPlaylist(ListPL.playlist[id]);
            NamaPlaylist *P = &(ListPL.playlist[id]);
            if (n < 0 || n >= x){
                printf("Tidak ada lagu dengan urutan %d di playlist \"", n);
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

    printf("\n");
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

            int n = ListPL.playlist_length;
            Word temp = ListPL.playlist[ans].playlist_nama;
            if (ans < 0 || ans >= n){
                printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", ans + 1);
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

    printf("\n");
    CONSOLE();
}