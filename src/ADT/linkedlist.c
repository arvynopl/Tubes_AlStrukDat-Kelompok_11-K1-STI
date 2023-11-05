#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void CreatePlaylist(NamaPlaylist *L){
    (*L).playlist_nama[0] = STR_UNDEF;
    (*L).list = NULL;
}

LaguPlaylist* NewLagu(Lagu val){
    LaguPlaylist* N;
    N = (LaguPlaylist*) malloc(sizeof(LaguPlaylist));
    (*N).lagu_playlist = val;
    (*N).next = NULL;

    return N;
}

boolean IsEmptyPlaylist(NamaPlaylist L){
    return L.playlist_nama[0] == STR_UNDEF;
}

int IndexOfPlaylist(NamaPlaylist L, Lagu val){
    Address P = L.list;
    boolean found = false;
    int i = 0;

    while (P != NULL && !found){
        if (IsEqual((*P).lagu_playlist, val)){ /*Cek string nama lagu*/
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
    Address P = NewNode(val);
    if (P != NULL){
        (*P).next = (*L).list;
        (*L).list = P;
    }
}

void InsertAtPlaylist(NamaPlaylist* L, int idx, Lagu val){
    if (idx == 0){
        InsertFirst(L, val);
    } else{
        Address P = NewNode(val);
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
    if (IsEmpty(*L)){
        InsertFirst(L, val);
    } else{
        Address P = NewNode(val);
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
    if (!IsEmpty(*L)){
        Address P = (*L).list;
        *val = (*P).lagu_playlist;
        (*L).list = (*P).next;
        free(P);     
    }
}

void DeleteAtPlaylist(NamaPlaylist* L, int idx, Lagu* val){
    if (idx == 0){
        DeleteFirst(L, val);
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
    CreateList(&L);
    Address P = L1.list;
    while (P != Nil){
        InsertLast(&L, (*P).lagu_playlist);
        P = (*P).next;
    }
    P = L2.list;
    while (P != Nil){
        InsertLast(&L, (*P).lagu_playlist);
        P = (*P).next;
    }
    return L;
}