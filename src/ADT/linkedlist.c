#include "linkedlist.h"

void CreatePlaylist(NamaPlaylist *L){
    (*L).playlist_nama.TabWord[0] = STR_UNDEF;
    (*L).playlist_nama.Length = 0;
    (*L).list = NULL;
}

boolean IsEmptyPlaylist(NamaPlaylist L){
    return L.list == NULL;
}

Address NewLagu(Lagu val){
    LaguPlaylist* N = (LaguPlaylist*) malloc(sizeof(LaguPlaylist));
    if (N != NULL){
        (*N).lagu_playlist = val;
        (*N).next = NULL;
        return N;   
    } else{
        return NULL;
    }
}

void Dealokasi (Address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    if (*P != Nil){
        free(*P);
        *P = Nil;
    }
}

Address Search (NamaPlaylist L, Lagu val){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    Address P = L.list;
    if (P == NULL){
        return NULL;
    } else{
        boolean found = false;
        while (P != NULL){
            if ((((*P).lagu_playlist.album_id == val.album_id)) && (WordCompare((*P).lagu_playlist.lagu_nama, val.lagu_nama))){
                found = true;
                break;
            }
            P = (*P).next;
        }

        if (found){
            return P;
        } else{
            return NULL;
        }
    }
}

int IndexOfPlaylist(NamaPlaylist L, Lagu val){
    Address P = L.list;
    if (P == NULL){
        return IDX_UNDEF;
    } else{
        int ctr = 0;
        boolean found = false;
        while (P != NULL){
            if (WordCompare((*P).lagu_playlist.lagu_nama, val.lagu_nama)){
                found = true;
                break;
            }
            P = (*P).next;
            ctr++;
        }

        if (found){
            return ctr;
        } else{
            return IDX_UNDEF;
        }
    }
}

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

    while (P != NULL && ctr < idx){
        ctr++;
        P = (*P).next;
    }
    
    if (P != NULL){
        return (*P).lagu_playlist;
    } else{
        Lagu defLagu;
        defLagu.album_id = IDX_UNDEF;
        defLagu.lagu_nama.TabWord[0] = STR_UNDEF;
        defLagu.lagu_nama.Length = 0;
        return defLagu;
    }  
}

void SetElmtOfPlaylist(NamaPlaylist *L, int idx, Lagu val){
    Address P = (*L).list;
    int ctr = 0;

    while (P != NULL && ctr < idx){
        ctr++;
        P = (*P).next;
    }
    
    if (P != NULL){
        (*P).lagu_playlist = val;
    } else{
        printf("Error...\n");
    }
}

void InsertFirstPlaylist(NamaPlaylist* L, Lagu val){
    Address P = NewLagu(val);
    if (P != NULL){
        (*P).next = (*L).list;
        (*L).list = P;
    } else{
        printf("Error...\n");
    }
}

void InsertAtPlaylist(NamaPlaylist* L, int idx, Lagu val){
    if (idx < 0 || idx >= LengthOfPlaylist(*L)) {
        printf("Error...\n");
    }
    
    if (idx == 0){
        InsertFirstPlaylist(L, val);
    } else{
        Address P = NewLagu(val);
        if (P != NULL){
            int ctr = 0;
            Address loc = (*L).list;
            while (loc != NULL && ctr < idx - 1){
                ctr++;
                loc = (*loc).next;
            }
            if (loc != NULL){
                (*P).next = (*loc).next;
                (*loc).next = P;
            } else{
                printf("Error...\n");
            }
        }
    }
}

void InsertLastPlaylist(NamaPlaylist* L, Lagu val){
    if (IsEmptyPlaylist(*L)){
        InsertFirstPlaylist(L, val);
    } else{
        Address P = NewLagu(val);
        if (P != NULL){
            Address last = (*L).list;
            while (last != NULL && (*last).next != NULL){
                last = (*last).next;
            }
            if (last != NULL){
                (*last).next = P;
            } else{
                printf("Error...\n"); 
            }

        }
    }
}

void DeleteFirstPlaylist(NamaPlaylist* L, Lagu* val){
    if (!IsEmptyPlaylist(*L)){
        Address P = (*L).list;
        *val = (*P).lagu_playlist;
        (*L).list = (*P).next;
        Dealokasi(&P);     
    } else{
        printf("Error...\n");
    }
}

void DeleteAtPlaylist(NamaPlaylist* L, int idx, Lagu* val){
    if (idx < 0 || idx >= LengthOfPlaylist(*L)) {
        printf("Error...\n");
    }

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
        Dealokasi(&P);
    }
}

void DeleteLastPlaylist(NamaPlaylist* L, Lagu* val){
    Address P = (*L).list;
    Address loc = NULL;
    while (P != NULL && (*P).next != NULL){
        loc = P;
        P = (*P).next;
    }
    if (P != NULL){
        if (loc == NULL){
            (*L).list = NULL;
        } else{
            (*loc).next = NULL;
        }
        *val = (*P).lagu_playlist;
        Dealokasi(&P);
    } else{
        printf("Error...\n");
    }
}

NamaPlaylist ConcatPlaylist(NamaPlaylist L1, NamaPlaylist L2){
    NamaPlaylist L;
    CreatePlaylist(&L);
    Address P = L1.list;
    while (P != NULL){
        InsertLastPlaylist(&L, (*P).lagu_playlist);
        P = (*P).next;
    }
    P = L2.list;
    while (P != NULL){
        InsertLastPlaylist(&L, (*P).lagu_playlist);
        P = (*P).next;
    }
    return L;
}

void PrintPlaylist(NamaPlaylist L){
    PrintWord(L.playlist_nama);
    printf("\n");
    Address P = L.list;
    int i = 1;
    while (P != NULL){
        printf("%d. ", i);
        PrintWord((*P).lagu_playlist.lagu_nama);
        printf("\n");
        P = (*P).next;
        i++;
    }
}
