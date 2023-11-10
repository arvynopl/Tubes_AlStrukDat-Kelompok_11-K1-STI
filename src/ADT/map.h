#ifndef MAP_H
#define MAP_H
#include "../structure.h"
#include "mesinkata.h"

/* ### Konstruktor ### */
/* Membuat Album kosong (A.lagu_length = Nil) sebagai Map dari Lagu */
void CreateMapLagu(Album* A);
/* Membuat Penyanyi kosong (P.album_length = Nil) sebagai Map dari Album */
void CreateMapAlbum(Penyanyi* P);
/* Mengirim true jika lagu Album A kosong (A.lagu_length = Nil) */
boolean IsEmptyMapLagu(Album A);
/* Mengirim true jika album Penyanyi P kosong (P.album_length = Nil) */
boolean IsEmptyMapAlbum(Penyanyi P);
/* Mengirim true jika lagu Album A penuh (A.lagu_length = MaxEl) */
boolean IsFullMapLagu(Album A);
/* Mengirim true jika album Penyanyi P penuh (P.album_length = MaxEl) */
boolean IsFullMapAlbum(Penyanyi P);
/* Mengirim panjang isi (Lagu) Album A */
int LengthMapLagu(Album A);
/* Mengirim panjang isi (Album) Penyanyi P */
int LengthMapAlbum(Penyanyi P);
/* Mengembalikan true jika Key K adalah member dari Album A */
boolean IsMemberMapLagu(Album A, Key K);
/* Mengembalikan true jika Key K adalah member dari Penyanyi P */
boolean IsMemberMapAlbum(Penyanyi P, Key K);

/* ### Operator Dasar Map ### */
/* Mendapatkan indeks sebuah Album pada Penyanyi */
int IndexOfAlbum(Penyanyi P, Album A);
/* Mendapatkan indeks sebuah Penyanyi pada List Penyanyi  */
int IndexOfPenyanyi(ListPenyanyi LP, Penyanyi P);
/* Mengembalikan nilai value Lagu dengan Key K dari Album A */
Lagu ValueMapLagu(Album A, Key K);
/* Mengembalikan nilai value Album dengan Key K dari Penyanyi P */
Album ValueMapAlbum(Penyanyi P, Key K);
/* Menambahkan array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void InsertMapLagu(Album* A, Lagu val);
/* Menambahkan array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void InsertMapAlbum(Penyanyi *P, Album val);
/* Menghapus array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void DeleteMapLagu(Album *A, Key K);
/* Menghapus array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void DeleteMapAlbum(Penyanyi *P, Key K);

/* ### Operator Output Map ### */
/* Mencetak nama lagu */
void PrintLagu(Lagu L);
/* Mencetak nama album dan daftar lagu yang ada di dalamnya  */
void PrintAlbum(Album A);
/* Mencetak nama penyanyi dan daftar album dan lagu yang ada di dalamnya  */
void PrintPenyanyi(Penyanyi P);
/* Mencetak daftar nama penyanyi beserta album dan lagu yang ada di dalamnya  */
void PrintListPenyanyi(ListPenyanyi LP);

#endif
