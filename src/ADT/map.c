#include "map.h"

/* ### Konstruktor ### */
/* Membuat Album kosong (A.lagu_length = Nil) sebagai Map dari Lagu */
void CreateMapLagu(Album* A){
    (*A).lagu_length = Nil;
}
/* Membuat Penyanyi kosong (P.album_length = Nil) sebagai Map dari Album */
void CreateMapAlbum(Penyanyi* P){
    (*P).album_length = Nil;
}
/* Mengirim true jika lagu Album A kosong (A.lagu_length = Nil) */
boolean IsEmptyMapLagu(Album A){
    return (A.lagu_length == Nil);
}
/* Mengirim true jika album Penyanyi P kosong (P.album_length = Nil) */
boolean IsEmptyMapAlbum(Penyanyi P){
    return (P.album_length == Nil);
}
/* Mengirim true jika lagu Album A penuh (A.lagu_length = MaxEl) */
boolean IsFullMapLagu(Album A){
    return (A.lagu_length == MaxEl);
}
/* Mengirim true jika album Penyanyi P penuh (P.album_length = MaxEl) */
boolean IsFullMapAlbum(Penyanyi P){
    return (P.album_length == MaxEl);
}
/* Mengembalikan true jika Key K adalah member dari Album A */
boolean IsMemberMapLagu(Album A, Key K){
    if (K < A.lagu_length){
        return true;
    } else {
        return false;
    }
}
/* Mengembalikan true jika Key K adalah member dari Penyanyi P */
boolean IsMemberMapAlbum(Penyanyi P, Key K){
    if (K < P.album_length){
        return true;
    } else {
        return false;
    }
}
/* ### Operator Dasar Map ### */
/* Mendapatkan indeks sebuah Album pada Penyanyi */
int IndexOfAlbum(Penyanyi P, Album A){
    boolean found = false;
    int i = 0;
    while (!found && i < P.album_length){
        if (IsEqual(P.album_penyanyi[i].album_nama, A.album_nama)){
            found = true;
        }
        i++;
    }
    if (found){
        return i - 1;
    } else{
        return IDX_UNDEF;
    }
}
/* Mendapatkan indeks sebuah Penyanyi pada List Penyanyi  */
int IndexOfPenyanyi(ListPenyanyi LP, Penyanyi P){
    boolean found = false;
    int i = 0;
    while (!found && i < LP.penyanyi_length){
        if (IsEqual(LP.penyanyi[i].penyanyi_nama, P.penyanyi_nama)){
            found = true;
        }
        i++;
    }
    if (found){
        return i - 1;
    } else{
        return IDX_UNDEF;
    }
}
/* Mengembalikan nilai value Lagu dengan Key K dari Album A */
Lagu ValueMapLagu(Album A, Key K){
    if (!IsEmptyMapLagu(A)){
        if (IsMemberMapLagu(A, K)){
            return A.lagu_album[K];
        } else{
            Lagu L;
            L.lagu_nama.TabWord[0] = STR_UNDEF;
            L.lagu_nama.Length = 0;
            return L;
        }
    }
}
/* Mengembalikan nilai value Album dengan Key K dari Penyanyi P */
Album ValueMapAlbum(Penyanyi P, Key K){
    if (!IsEmptyMapAlbum(P)){
        if (IsMemberMapAlbum(P, K)){
            return P.album_penyanyi[K];
        } else{
            Album A;
            A.lagu_length = IDX_UNDEF;
            return A;
        }
    }
}
/* Menambahkan array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void InsertMapLagu(Penyanyi* P, Album* A, Word* ST){
    if (!IsFullMapLagu(*A)){
        int i = 0;
        boolean found = false;
        while (!found && i < (*A).lagu_length){
            if (WordCompare((*A).lagu_album[i].lagu_nama, *ST)){ /* Cek string nama lagu */
                found = true;
            }
            (*A).lagu_album[i].album_id = IndexOfAlbum(*P, *A);
            i++;  
        }
    }
}
/* Menambahkan array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void InsertMapAlbum(ListPenyanyi* LP, Penyanyi *P, Word* AT){
    if (!IsFullMapAlbum(*P)){
        int i = 0;
        boolean found = false;
        while (!found && i < (*P).album_length){
            if (WordCompare((*P).album_penyanyi[i].album_nama, *AT)){ /* Cek string nama lagu */
                found = true;
            }
            (*P).album_penyanyi[i].penyanyi_id = IndexOfPenyanyi(*LP, *P);
            i++;  
        }
    }
}
/* Menghapus array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void DeleteMapLagu(Album *A, Key K){
    if (!IsEmptyMapLagu(*A)){
        if (IsMemberMapLagu(*A, K)){
            int i = 0;
            for (int j = K; j < (*A).lagu_length - 1; j++){
                (*A).lagu_album[j] = (*A).lagu_album[j + 1];
            }
            (*A).lagu_length--;
        }
    }
}
/* Menghapus array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void DeleteMapAlbum(Penyanyi *P, Key K){
    if (!IsEmptyMapAlbum(*P)){
        if (IsMemberMapAlbum(*P, K)){
            int i = 0;
            for (int j = K; j < (*P).album_length - 1; j++){
                (*P).album_penyanyi[j] = (*P).album_penyanyi[j + 1];
            }
            (*P).album_length--;
        }
    }
}