/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
#ifndef LIST_H
#define LIST_H
#include "../structure.h"
#include "mesinkata.h"

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */

/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
void CreateListPenyanyi(ListPenyanyi *LP);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */

/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
boolean IsEmptyListPenyanyi(ListPenyanyi LP);

/* Mengirimkan true jika list L penuh, mengirimkan false jika tidak */
boolean IsFullListPenyanyi(ListPenyanyi LP);

/* *** Menghasilkan sebuah elemen *** */
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
Penyanyi GetPenyanyi(ListPenyanyi LP, int i);

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
void SetPenyanyi(ListPenyanyi *LP, int i, Penyanyi P);

/* ********** SELEKTOR ********** */

/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
int LengthOfPenyanyi(ListPenyanyi LP);

/* *** Selektor INDEKS *** */
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
int FirstIdxOfListPenyanyi(ListPenyanyi LP);

/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
int LastIdxOfListPenyanyi(ListPenyanyi LP);

/* ********** Test Indeks yang valid ********** */
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
boolean IsIdxValidOfListPenyanyi(int i);

/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
boolean IsIdxEffOfListPenyanyi(ListPenyanyi LP, int i);

/* ********** Operasi-operasi ********** */
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
boolean SearchPenyanyi(ListPenyanyi LP, Penyanyi P);

/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
void InsertFirstListPenyanyi(ListPenyanyi *LP, Penyanyi P);

/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
void InsertAtListPenyanyi(ListPenyanyi *LP, Penyanyi P, int i);

/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
void InsertLastListPenyanyi(ListPenyanyi *LP, Penyanyi P);

/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
void DeleteFirstListPenyanyi(ListPenyanyi *LP);

/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
void DeleteAtListPenyanyi(ListPenyanyi *LP, int i);

/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
void DeleteLastListPenyanyi(ListPenyanyi *LP);

/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
ListPenyanyi ConcatListPenyanyi(ListPenyanyi L1, ListPenyanyi L2);

#endif
