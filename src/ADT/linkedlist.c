#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void CreatePlaylist(NamaPlaylist *L){
    (*L).playlist_nama[0] = STR_UNDEF;
    (*L).list = NULL;
}

boolean IsEmptyPlaylist(NamaPlaylist L){
    return L.list == NULL;
}

LaguPlaylist* NewLagu(NamaPlaylist *L, Lagu val){
    LaguPlaylist* N = (LaguPlaylist*) malloc(sizeof(LaguPlaylist));
    if (N != NULL){
        (*N).lagu_playlist = val;
        (*N).next = (*L).list;
        (*L).list = N;   
    }
    return N;
}

/*
int IndexOfPlaylist(NamaPlaylist L, Lagu val){
    Address P = L.list;
    boolean found = false;
    int i = 0;

    while (P != NULL && !found){
        if (IsEqual((*P).lagu_playlist, val)){ /*Cek string nama lagu*//*
            found = true;
        } else{
            i++;
            P = (*P).next;
        }
    }

    if (found){
        return i;
    } else{
        return Nil;
    }
}
*/
int LengthOfPlaylist(NamaPlaylist L){
    Address P = L.list;
    int ctr = 0;

    while (P != NULL){
        ctr++;
        P = (*P).next;
    }

    return ctr;
}

Lagu GetElmtOfPlaylist(NamaPlaylist L, int idx){
    Address P = L.list;
    int ctr = 0;

    while (ctr < idx){
        ctr++;
        P = (*P).next;
    }

    return (*P).lagu_playlist;
}

void SetElmtOfPlaylist(NamaPlaylist L, int idx, Lagu val){
    Address P = L.list;
    int ctr = 0;

    while (ctr < idx){
        ctr++;
        P = (*P).next;
    }

    (*P).lagu_playlist = val;
}

void InsertFirstPlaylist(NamaPlaylist* L, Lagu val){
    Address P = NewLagu(L, val);
    if (P != NULL){
        (*P).next = (*L).list;
        (*L).list = P;
    }
}

void InsertAtPlaylist(NamaPlaylist* L, int idx, Lagu val){
    if (idx == 0){
        InsertFirstPlaylist(L, val);
    } else{
        Address P = NewLagu(L, val);
        if (P != NULL){
            int ctr = 0;
            Address loc = (*L).list;
            while (ctr < idx - 1){
                ctr++;
                loc = (*loc).next;
            }
            (*P).next = (*loc).next;
            (*loc).next = P;
        }
    }
}

void InsertLastPlaylist(NamaPlaylist* L, Lagu val){
    if (IsEmptyPlaylist(*L)){
        InsertFirstPlaylist(L, val);
    } else{
        Address P = NewLagu(L, val);
        if (P != NULL){
            Address last = (*L).list;
            while ((*last).next != Nil){
                last = (*last).next;
            }
            (*last).next = P;
        }
    }
}

void DeleteFirstPlaylist(NamaPlaylist* L, Lagu* val){
    if (!IsEmptyPlaylist(*L)){
        Address P = (*L).list;
        *val = (*P).lagu_playlist;
        (*L).list = (*P).next;
        free(P);     
    }
}

void DeleteAtPlaylist(NamaPlaylist* L, int idx, Lagu* val){
    if (idx == 0){
        DeleteFirstPlaylist(L, val);
    } else{
        int ctr = 0;
        Address loc = (*L).list;
        while (ctr < idx - 1){
            ctr++;
            loc = (*loc).next;
        }
        Address P = (*loc).next;
        *val = (*P).lagu_playlist;
        (*loc).next = (*P).next;
        free(P);
    }
}

void DeleteLastPlaylist(NamaPlaylist* L, Lagu* val){
    Address P = (*L).list;
    Address loc = Nil;
    while ((*P).next != Nil){
        loc = P;
        P = (*P).next;
    }
    if (loc == Nil){
        (*L).list = Nil;
    } else{
        (*loc).next = Nil;
    }
    *val = (*P).lagu_playlist;
    free(P);
}

NamaPlaylist ConcatPlaylist(NamaPlaylist L1, NamaPlaylist L2){
    NamaPlaylist L;
    CreatePlaylist(&L);
    Address P = L1.list;
    while (P != Nil){
        InsertLastPlaylist(&L, (*P).lagu_playlist);
        P = (*P).next;
    }
    P = L2.list;
    while (P != Nil){
        InsertLastPlaylist(&L, (*P).lagu_playlist);
        P = (*P).next;
    }
    return L;
}

void PrintNamaPlaylist(NamaPlaylist L){
    int i = 0;
    while (L.playlist_nama[i] != '\0'){
        printf("%c", L.playlist_nama[i]);
        i++;
    }
}

void PrintIsiPlaylist(NamaPlaylist L){
    Address P = L.list;
    int i = 1;
    while (P != NULL){
        printf("%d. %c", i, (*P).lagu_playlist.lagu_nama[0]);
        int j = 1;
        while ((*P).lagu_playlist.lagu_nama[j] != '\0'){
            printf("%c", (*P).lagu_playlist.lagu_nama[j]);
            j++;
        }
        printf("\n");
        P = (*P).next;
        i++;
    }
}

/*
int main(){
    ListPenyanyi LP;
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].album_id = 0;
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama[0] = 'R';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama[1] = 'A';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama[2] = 'S';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama[3] = 'A';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama[4] = '\0';    
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama[0] = 'G';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama[1] = 'A';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama[2] = 'R';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama[3] = 'A';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama[4] = 'M';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama[5] = '\0';
    NamaPlaylist L;
    CreatePlaylist(&L);
    L.playlist_nama[0] = 'A';
    L.playlist_nama[1] = 'B';
    L.playlist_nama[2] = 'C';
    L.playlist_nama[3] = 'D';
    L.playlist_nama[4] = 'E';
    L.playlist_nama[5] = '\0';
    NewLagu(&L, LP.penyanyi[0].album_penyanyi[0].lagu_album[0]);
    NewLagu(&L, LP.penyanyi[0].album_penyanyi[0].lagu_album[1]);
    PrintIsiPlaylist(L);
    PrintNamaPlaylist(L);
    printf("\nPanjang Album (sebelum): %d\n", LengthOfPlaylist(L));
    Lagu S;
    S = GetElmtOfPlaylist(L, 0);
    SetElmtOfPlaylist(L, 0, LP.penyanyi[0].album_penyanyi[0].lagu_album[0]);
    PrintIsiPlaylist(L);
    PrintNamaPlaylist(L);
    printf("\nPanjang Album (setelah): %d", LengthOfPlaylist(L));
    printf("\nAlbum ID: %d\n", S.album_id);
    for (int i = 0; i < 5; i++){
        printf("%c", S.lagu_nama[i]);
    }
}
*/