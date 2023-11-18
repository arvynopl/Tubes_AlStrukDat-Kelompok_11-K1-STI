#include "listdinamis.h"

void CreateListPlaylist(ListPlaylist* X){
    (*X).playlist = (NamaPlaylist*) malloc((MaxEl/20) * sizeof(NamaPlaylist));
    if (X != NULL){
        (*X).playlist_size = MaxEl/20;
        (*X).playlist_length = 0;
    }
}

void PushPlaylist(ListPlaylist* X, NamaPlaylist val){
    if ((*X).playlist_length == (*X).playlist_size){
        ResizeBiggerListPlaylist(X);
    }
    (*X).playlist[(*X).playlist_length] = val;
    (*X).playlist_length++;
}

void PopPlaylist(ListPlaylist* X, NamaPlaylist* val){
    if ((*X).playlist_length != 0){
        *val = (*X).playlist[(*X).playlist_length - 1];
        (*X).playlist_length--;
        if ((*X).playlist_length == (*X).playlist_size / 2){
            ResizeSmallerListPlaylist(X);
        }
    }
}

NamaPlaylist GetPlaylist(ListPlaylist X, size_t i){
    if (i >= X.playlist_length){
        printf("Indeks yang diakses invalid...\n");
        NamaPlaylist defplaylist;
        defplaylist.list = Nil;
        defplaylist.playlist_nama.TabWord[0] = STR_UNDEF;
        defplaylist.playlist_nama.Length = 0;
        return defplaylist;
    } else{
        return X.playlist[i];
    }
}

void SetPlaylist(ListPlaylist* X, size_t i, NamaPlaylist val){
    if (i >= (*X).playlist_length){
        printf("Indeks yang diakses invalid...\n");
    } else{
        (*X).playlist[i] = val;
    }
}

void ResizeBiggerListPlaylist(ListPlaylist* X){
    (*X).playlist_size *= 2;
    size_t newSize = (*X).playlist_size;
    (*X).playlist = realloc((*X).playlist, newSize * sizeof(NamaPlaylist));
    if ((*X).playlist != Nil){
        printf("Reallocation done correctly...\n");
    } else{
        printf("Error in reallocation...\n");
        free(X);
    }
}

void ResizeSmallerListPlaylist(ListPlaylist* X){
    (*X).playlist_size /= 2;
    size_t newSize = (*X).playlist_size;
    (*X).playlist = realloc((*X).playlist, newSize * sizeof(NamaPlaylist));
    if ((*X).playlist != Nil){
        printf("Reallocation done correctly...\n");
    } else{
        printf("Error in reallocation...\n");
        free(X);
    }
}

void FreePlaylist(ListPlaylist* X){
    for (int i = 0; i < X->playlist_length; i++){
        while (!IsEmptyPlaylist((*X).playlist[i])){
            Lagu val;
            DeleteLastPlaylist(&((*X).playlist[i]), &val);
        }
    }
    (*X).playlist_length = 0;
    (*X).playlist_size = MaxEl/20;
    free((*X).playlist);
}
