/* ADT Queue dengan Alternatif 3 (Circular Buffer) */
/* ADT ini dibuat dengan representasi array secara eksplisit dan alokasi statik */

#ifndef queue_alt3_h
#define queue_alt3_h

#include "structure.h"

/* Cara mengakses elemen */
#define IDX_HEAD(q) (q).idxHead
#define     HEAD(q) (q).lagu_queue[(q).idxHead]
#define IDX_TAIL(q) (q).idxTail
#define     TAIL(q) (q).lagu_queue[(q).idxTail]

/* ADT Queue yang dapat digunakan */
boolean IsEmpty (QueueLagu Q);
/* Queue bernilai true ketika index Head dan index Tail dari Queue tersebut bernilai Index Undefined (IDX_UNDEF) */

boolean IsFull (QueueLagu Q);
/* Queue bernilai true ketika kondisi sebagai berikut 
1. Kondisi Index Head < Index Tail : Index Head = 0 and Index Tail = IDX_MAX
2. Kondisi Index Head > Index Tail : Index Head = IndexTail += 1
*/

int Length (QueueLagu Q);
/* Length mengirimkan banyaknya elemen dalam suatu Queue, Length akan bernilai 0 apabila Queue kosong */

void CreateQueue (QueueLagu * Q);
/* CreateQueue akan membuat sebuah Queue kosong dengan mendeklarasikan Index Head dan Index Tail sebagai Index Undefined (IDX_UNDEF) */

void enqueue (QueueLagu * Q, int X);
/* enqueue akan menambahkan element X sebagai tail yang baru, idx_tail bergeser ke kanan */
/* Jika Queue sebelum enqueue kosong, idx_head dan idx_Tail diset ke 0 dan diinsert element X */
/* Jika idx_tail = idx_max - 1, idx_tail menjadi 0 dan diinsert element X */

int dequeue (QueueLagu * Q);
/* dequeue akan memindahkan head yang lama ke variabel X dan idx_head bergeser ke kanan */
/* (1) Jika queue menjadi kosong, idx_head dan idx_tail menjadi idx_undef */
/* Jika idx_head = idx_max - 1, idx_head menjadi 0 */

void displayQueue(QueueLagu q);
/* displayQueue akan mengeluarkan hasil print dari isi Queue q */

#endif