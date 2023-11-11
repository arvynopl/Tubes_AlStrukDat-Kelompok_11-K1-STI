#include "listdinamis.h"

void CreateListPlaylist(ListPlaylist* X){
    X = (ListPlaylist*) malloc((MaxEl/20) * sizeof(ListPlaylist));
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
        *val = (*X).playlist[(*X).playlist_length];
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
        defplaylist.list = NULL;
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
    X = realloc(X, newSize * sizeof(ListPlaylist));
    if (X != NULL){
        printf("Reallocation done correctly...\n");
    } else{
        printf("Error in reallocation...\n");
        free(X);
    }
}

void ResizeSmallerListPlaylist(ListPlaylist* X){
    (*X).playlist_size /= 2;
    size_t newSize = (*X).playlist_size;
    X = realloc(X, newSize * sizeof(ListPlaylist));
    if (X != NULL){
        printf("Reallocation done correctly...\n");
    } else{
        printf("Error in reallocation...\n");
        free(X);
    }
}

void FreePlaylist(ListPlaylist* X){
    int i = 0;
    int j = (*X).playlist_length - 1;
    while (i < j){
        NamaPlaylist* temp = &(*X).playlist[i];
        while (!IsEmptyPlaylist((*X).playlist[i])){
            int val;
            DeleteLastPlaylist(temp, &val);
        }
        i++;
    }
    free(X);
}
