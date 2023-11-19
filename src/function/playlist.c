#include "function.h"

void swap(ListPlaylist* L, int idx0, int idx1, int idx2){
    if ((idx0 < 0) || (idx0 >= (*L).playlist_length)){
        printf("Error: Invalid index for playlist\n");
        return;
    }

    NamaPlaylist *p = &((*L).playlist[idx0]);

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

void remove(ListPlaylist *L, int urutan, int id){
    if (id < 0 || id >= (*L).playlist_length){
        printf("Error\n");
    }

    NamaPlaylist *p = &((*L).playlist[id]);

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

void delete(ListPlaylist *L, int id) {
    if (id < 0 || id >= (*L).playlist_length) {
        printf("Error: Invalid playlist index\n");
        return;
    }

    NamaPlaylist *p = &((*L).playlist[id]);

    free((*p).playlist_nama.TabWord);

    Address current = p->list;
    while (current != NULL) {
        Address temp = current;
        current = current->next;
        free(temp);
    }

    free(p);
}