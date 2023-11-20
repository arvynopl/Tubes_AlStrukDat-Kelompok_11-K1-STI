#include "function.h"

void swap(ListPlaylist* LP, int idx0, int idx1, int idx2){
    if ((idx0 < 0) || (idx0 >= (*LP).playlist_length)){
        printf("Error: Invalid index for playlist\n");
        return;
    }

    NamaPlaylist *p = &((*LP).playlist[idx0]);

    int n = LengthOfPlaylist(*p);

    if (idx1 < 0 || idx1 >= n || idx2 < 0 || idx2 >= n) {
        printf("Error: Invalid index for songs in the playlist\n");
        return;
    }

    Address a = (*p).list;
    Address b = (*p).list;
    Lagu temp;
    for (int i = 0; i <= idx1; i++){
        a = (*a).next;
    }

    for (int j = 0; j <= idx2; j++){
        b = (*b).next;
    }

    temp = (*a).lagu_playlist;
    (*a).lagu_playlist = (*b).lagu_playlist;
    (*b).lagu_playlist = temp;

    printf("Songs swapped successfully\n");
}

void remove(ListPlaylist *LP, int urutan, int id){
    if (id < 0 || id >= (*LP).playlist_length){
        printf("Error\n");
    }

    NamaPlaylist *p = &((*LP).playlist[id]);

    if (urutan <= 0 || urutan > LengthOfPlaylist(*p)){
        printf("Error\n");
    }

    Address song = (*p).list;
    Address prevsong = Nil;
    
    for (int i = 0; i < urutan; i++){
        prevsong = song;
        song = (*song).next;
    }

    if (urutan == 1){
        (*p).list = (*song).next;
    } else{
        (*prevsong).next = (*song).next;
    }

    Dealokasi(song);
}

void delete(ListPlaylist *LP, int id) {
    if (id < 0 || id >= (*LP).playlist_length) {
        printf("Error: Invalid playlist index\n");
        return;
    }

    NamaPlaylist *p = &((*LP).playlist[id]);

    free((*p).playlist_nama.TabWord);

    Address current = p->list;
    while (current != NULL) {
        Address temp = current;
        current = current->next;
        free(temp);
    }

    free(p);
}

void addfirst (NamaPlaylist* L, Lagu val){
    InsertFirstPlaylist(&L, val);
}

void addLast (NamaPlaylist* L, Lagu val){
    InsertLastPlaylist(&L, val);
}

void insertallsongsfromalbumtoplaylist(){
    Word Penyanyinama;
    Word Albumnama;
    STARTINPUT();
    Word ans1 = GetWord();
    if (ans1.TabWord[0] == 'Y'){
        printf("Pilih penyanyi untuk melihat album mereka: ");
        STARTINPUT();
        Penyanyinama = GetWord();
        int idpenyanyi = IndexOfPenyanyiStr(LP, Penyanyinama);
        if (!WordCompare(Penyanyinama, LP.penyanyi[idpenyanyi].penyanyi_nama)){
            printWord("Penyanyi", Penyanyinama, "tidak ada di dalam daftar. Silahkan coba lagi.");
        }else{
            STARTINPUT();
            Albumnama = GetWord();
            int idalbum = IndexOfAlbumStr (LP, Penyanyinama, Albumnama);
            if (!WordCompare (Albumnama, LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].album_nama)){
                printWord("Album", Albumnama, "tidak ada dalam daftar. Silahkan coba lagi.");
            }else{
                STARTINPUT();
                Word idp = GetWord();
                int idplaylist = WordToInt(idp);
                Word namaplaylist = ListPL.playlist[idplaylist].playlist_nama;
                int i = 0;
                boolean found;
                NamaPlaylist *L = &(ListPL.playlist[idplaylist]);
                Address A = list(*L);
                while (i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length) {
                     found = false;

                    while (A != NULL) {
                        if (WordCompare (LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i].lagu_nama, (*A).lagu_playlist.lagu_nama) && LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].penyanyi_id == (*A).lagu_playlist.penyanyi_id) {
                            found = true;
                            break;
                        }
                        A = (*A).next;
                    }

                    if (!found) {
                        addLast(&L, LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i]);
                    }

                    i++;
                    A = list(*L);
                }
            }
            
            
        }
    }
    
}