#ifndef STACK_H
#define STACK_H
#include "../structure.h"
#include "mesinkata.h"

/* Membuat histori lagu bertipe stack */
void CreateHistori(HistoriLagu* H);
/* Mengirimkan true jika histori lagu kosong (Nil = 0) */
boolean IsEmptyHistori(HistoriLagu H);
/* Mengirimkan true jika histori lagu sudah penuh (MaxEl = 100) */
boolean IsFullHistori(HistoriLagu H);
/* Memasukkan lagu sebagai elemen pada index top ke dalam histori lagu */
void Push(HistoriLagu* H, Lagu L);
/* Mengeluarkan lagu sebagai elemen pada index top dari histori lagu*/
void Pop(HistoriLagu* H, Lagu* L);
/* Mengeluarkan hasil print dari isi HistoriLagu H */
void PrintHistori(HistoriLagu H);

#endif


