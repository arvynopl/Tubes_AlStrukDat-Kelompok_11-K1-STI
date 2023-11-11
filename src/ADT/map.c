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
    return (A.lagu_length == MaxEl/5);
}
/* Mengirim true jika album Penyanyi P penuh (P.album_length = MaxEl) */
boolean IsFullMapAlbum(Penyanyi P){
    return (P.album_length == MaxEl/10);
}
/* Mengirim panjang isi (Lagu) Album A */
int LengthMapLagu(Album A){
    return A.lagu_length;
}
/* Mengirim panjang isi (Album) Penyanyi P */
int LengthMapAlbum(Penyanyi P){
    return P.album_length;
}
/* Mengembalikan true jika Key K adalah member dari Album A */
boolean IsMemberMapLagu(Album A, Key K){
    return (K < A.lagu_length);
}
/* Mengembalikan true jika Key K adalah member dari Penyanyi P */
boolean IsMemberMapAlbum(Penyanyi P, Key K){
    return (K < P.album_length);
}
/* ### Operator Dasar Map ### */
/* Mendapatkan indeks sebuah Album pada Penyanyi */
int IndexOfAlbum(Penyanyi P, Album A){
    int i = 0;
    while (i < P.album_length){
        if (WordCompare(P.album_penyanyi[i].album_nama, A.album_nama)){
            return i;
        }
        i++;
    }
    return IDX_UNDEF;
}
/* Mendapatkan indeks sebuah Penyanyi pada List Penyanyi  */
int IndexOfPenyanyi(ListPenyanyi LP, Penyanyi P){
    int i = 0;
    while (i < LP.penyanyi_length){
        if (WordCompare(LP.penyanyi[i].penyanyi_nama, P.penyanyi_nama)){
            return i;
        }
        i++;
    }
    return IDX_UNDEF;
}
/* Mengembalikan nilai value Lagu dengan Key K dari Album A */
Lagu ValueMapLagu(Album A, Key K){
    if (!IsEmptyMapLagu(A)){
        if (IsMemberMapLagu(A, K)){
            return A.lagu_album[K];
        } else{
            Lagu deflagu;
            deflagu.lagu_nama.TabWord[0] = STR_UNDEF;
            deflagu.lagu_nama.Length = 0;
            return deflagu;
        }
    }
}
/* Mengembalikan nilai value Album dengan Key K dari Penyanyi P */
Album ValueMapAlbum(Penyanyi P, Key K){
    if (!IsEmptyMapAlbum(P)){
        if (IsMemberMapAlbum(P, K)){
            return P.album_penyanyi[K];
        } else{
            Album defalbum;
            defalbum.album_nama.TabWord[0] = STR_UNDEF;
            defalbum.album_nama.Length = 0;
            defalbum.lagu_length = IDX_UNDEF;
            Lagu deflagu;
            deflagu.lagu_nama.TabWord[0] = STR_UNDEF;
            deflagu.lagu_nama.Length = 0;
            defalbum.lagu_album[0] = deflagu;
            return defalbum;
        }
    }
}
/* Menambahkan array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void InsertMapLagu(Album* A, Lagu val){
    if (!IsFullMapLagu(*A)){
        int i = 0;
        boolean found = false;
        while (i < (*A).lagu_length){
            if (((*A).lagu_album[i].album_id == val.album_id) && (WordCompare((*A).lagu_album[i].lagu_nama, val.lagu_nama))){
                found = true;
                break;
            }
            i++;  
        }
        if (!found){
            (*A).lagu_album[(*A).lagu_length] = val;
            (*A).lagu_length++;
        } else{
            printf("Error...\n");
        }
    }
}
/* Menambahkan array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void InsertMapAlbum(Penyanyi *P, Album val){
    if (!IsFullMapAlbum(*P)){
        int i = 0;
        boolean found = false;
        while (i < (*P).album_length){
            if (((*P).album_penyanyi[i].penyanyi_id == val.penyanyi_id) && (WordCompare((*P).album_penyanyi[i].album_nama, val.album_nama))){
                found = true;
                break;
            }
            i++;  
        }
        if (!found){
            (*P).album_penyanyi[(*P).album_length] = val;
            (*P).album_length++;
        } else{
            printf("Error...\n");
        }
    }
}
/* Menghapus array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void DeleteMapLagu(Album *A, Key K){
    if (!IsEmptyMapLagu(*A)){
        if (IsMemberMapLagu(*A, K)){
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
            for (int j = K; j < (*P).album_length - 1; j++){
                (*P).album_penyanyi[j] = (*P).album_penyanyi[j + 1];
            }
            (*P).album_length--;
        }
    }
}

void PrintLagu(Lagu L){
    PrintWord(L.lagu_nama);
    printf("\n");
}

void PrintAlbum(Album A){
    PrintWord(A.album_nama);
    printf("\n");
    for (int i = 0; i < A.lagu_length; i++){
        printf("  %d. ", i + 1);
        PrintLagu(A.lagu_album[i]);
    }
}

void PrintPenyanyi(Penyanyi P){
    PrintWord(P.penyanyi_nama);
    printf("\n");
    for (int i = 0; i < P.album_length; i++){
        printf(" %d. ", i + 1);
        PrintAlbum(P.album_penyanyi[i]);
    }
}

void PrintListPenyanyi(ListPenyanyi LP){
    for (int i = 0; i < LP.penyanyi_length; i++){
        printf("%d. ", i + 1);
        PrintPenyanyi(LP.penyanyi[i]);
    }
}