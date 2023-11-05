#ifndef linkedlist_H
#define linkedlist_H
#include "../src/structure.h"

/* ### Konstruktor ### */
/* Membuat list baru dengan kondisi kosong (L = Nil) */
void CreatePlaylist(NamaPlaylist *L);
/* Membuat node baru dengan info bernilai val */
LaguPlaylist* NewLagu(Lagu val);

/* ### Predikat ### */
/* Memeriksa kondisi sebuah kosong tidaknya sebuah list L.
   Jika kosong (L = Nil), maka akan bernilai true */
boolean IsEmptyPlaylist(NamaPlaylist L);
/* Mendapatkan indeks sebuah node pada list L dengan nilai val */
int IndexOfPlaylist(NamaPlaylist L, Lagu val);
/* Mendapatkan panjang sebuah list L */
int LengthOfPlaylist(NamaPlaylist L);

/* ### Selektor ### */
/* Mendapatkan elemen sebuah node dengan indeks idx pada list L */
Lagu GetElmtOfPlaylist(NamaPlaylist L, int idx);
/* Mengubah elemen sebuah node dengan indeks idx pada list L menjadi bernilai val */
void SetElmtOfPlaylist(NamaPlaylist L, int idx, Lagu val);

/* ### Menambahkan elemen ### */
/* Menambahkan nodes baru dengan nilai val pada indeks pertama list L */
void InsertFirstPlaylist(NamaPlaylist* L, Lagu val);
/* Menambahkan node baru dengan nilai val pada indeks idx list L */
void InsertAtPlaylist(NamaPlaylist* L, int idx, Lagu val);
/* Menambahkan node baru dengan nilai val pada indeks terakhir List L*/
void InsertLastPlaylist(NamaPlaylist* L, Lagu val);

/* ### Menghapus elemen ### */
/* Menghapus node indeks pertama pada list L */
void DeleteFirstPlaylist(NamaPlaylist* L, Lagu* val);
/* Menghapus node indeks idx pada list L */
void DeleteAtPlaylist(NamaPlaylist* L, int idx, Lagu* val);
/* Menghapus node indeks terakhir pada list L */
void DeleteLastPlaylist(NamaPlaylist* L, Lagu* val);

/* ### Menyatukan nodes dalam list berkait ### */
/* Menyatukan nodes yang ada pada List L1 dan List L2 menjadi suatu list L */
NamaPlaylist ConcatPlaylist(NamaPlaylist L1, NamaPlaylist L2);

#endif
