#include <stdio.h>
#include "queue.h"

/* ADT Queue yang dapat digunakan */
boolean IsEmptyQueue(QueueLagu Q){
    return (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF);
}

boolean IsFullQueue(QueueLagu Q){
    return((Q.idxHead == Q.idxTail + 1) || (Q.idxHead == 0 && Q.idxTail == MaxEl - 1));
}

int LengthOfQueue(QueueLagu Q){
    if (IsEmptyQueue(Q)){
        return 0;
    } else if (Q.idxTail >= Q.idxHead){
        return(Q.idxTail - Q.idxHead + 1);
    } else if (Q.idxTail < Q.idxHead){
        return((MaxEl - Q.idxHead + 1) + (Q.idxTail + 1));
    }
}

void CreateQueue(QueueLagu* Q){
    (*Q).idxHead = IDX_UNDEF;
    (*Q).idxTail = IDX_UNDEF;
}


void Enqueue(QueueLagu* Q, Lagu X){
    if (!IsFullQueue(*Q)){
        if (IsEmptyQueue(*Q)){
            (*Q).idxHead = 0;
            (*Q).idxTail = 0;
        } else {
            (*Q).idxTail++;
            if ((*Q).idxTail == MaxEl){
                (*Q).idxTail = 0;
            }
        }
        (*Q).lagu_queue[(*Q).idxTail] = X;
    } else{
        printf("Queue Lagu sudah penuh. Tidak dapat menambahkan lagu ke dalam queue...\n");
    }
}

Lagu Dequeue(QueueLagu* Q){
    if (!IsEmptyQueue(*Q)){
        Lagu X = (*Q).lagu_queue[(*Q).idxHead];
        if ((*Q).idxHead == (*Q).idxTail){
            (*Q).idxHead = IDX_UNDEF;
            (*Q).idxTail = IDX_UNDEF;
        } else {
            (*Q).idxHead++;
            if ((*Q).idxHead == MaxEl){
                (*Q).idxHead = 0;
            }
        }
        return X;
    } else {
        Lagu deflagu;
        deflagu.lagu_nama.TabWord[0] = STR_UNDEF;
        deflagu.lagu_nama.Length = 0;
        return deflagu;
    }
}

void PrintQueue(QueueLagu Q){
    if (!IsEmptyQueue(Q)){
        int j = 1;
        for (int i = IDX_HEAD(Q); i <= IDX_TAIL(Q); i++){
            printf("%d. ", j);
            PrintWord(Q.lagu_queue[i].lagu_nama);
            printf("\n");
            j++;
            if (i == MaxEl){
                i = 0;
            }
        }
    }
    printf("\n");
}
