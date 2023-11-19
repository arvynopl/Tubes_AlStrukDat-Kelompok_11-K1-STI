/* ADT Queue dengan Alternatif 3 (Circular Buffer) */
/* ADT ini dibuat dengan representasi array secara eksplisit dan alokasi statik */
#ifndef QUEUE_H
#define QUEUE_H
#include "../structure.h"
#include "mesinkata.h"

/* ### ADT Queue yang dapat digunakan ### */
/* Queue bernilai true ketika index Head dan index Tail dari Queue tersebut bernilai Index Undefined (IDX_UNDEF) */
boolean IsEmptyQueue(QueueLagu Q);
/* Queue bernilai true ketika kondisi sebagai berikut 
1. Kondisi Index Head < Index Tail : Index Head = 0 and Index Tail = IDX_MAX
2. Kondisi Index Head > Index Tail : Index Head = IndexTail += 1
*/
boolean IsFullQueue(QueueLagu Q);
/* Length mengirimkan banyaknya elemen dalam suatu Queue, Length akan bernilai 0 apabila Queue kosong */
int LengthOfQueue(QueueLagu Q);
/* CreateQueue akan membuat sebuah Queue kosong dengan mendeklarasikan Index Head dan Index Tail sebagai Index Undefined (IDX_UNDEF) */
void CreateQueue(QueueLagu* Q);
/* Enqueue akan menambahkan elemen X sebagai tail yang baru, idx_Tail bergeser ke kanan */
/* Jika Queue sebelum Enqueue kosong, idx_Head dan idx_Tail diset ke 0 dan di-insert elemen X */
/* Jika idx_Tail = MaxEl - 1, idx_Tail menjadi 0 dan di-insert elemen X */
void Enqueue(QueueLagu* Q, Lagu X);
/* Dequeue akan memindahkan head yang lama ke variabel X dan idx_head bergeser ke kanan */
/* (1) Jika queue menjadi kosong, idx_head dan idx_tail menjadi idx_undef */
/* Jika idx_head = idx_max - 1, idx_head menjadi 0 */
Lagu Dequeue(QueueLagu* Q);
/* PrintQueue akan mengeluarkan hasil print dari isi Queue q */
void PrintQueue(QueueLagu q);

#endif
