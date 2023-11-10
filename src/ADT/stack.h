#ifndef stack_H
#define stack_H
#include "structure.h"

void CreateEmpty(HistoriLagu *H);
/*membuat histori lagu bertipe stack*/
boolean isEmpty(HistoriLagu * H);
/*cek apakah history lagu kosong atau tidak*/
boolean IsFull(Stack S);
/*cek apakah histori lagu sudah penuh ( MaxEl = 100)*/
void Push(HistoriLagu * H, Lagu L);
/*Memasukkan lagu sebagai elemen top yang ke dalam histori lagu*/
void Pop(HistoriLagu * H, Lagu* L);
/*mengeluarkan lagu (elemen top) dari histori lagu*/