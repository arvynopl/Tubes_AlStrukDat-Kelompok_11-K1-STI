#include <stdio.h>
#include "queue_alt3.h"

/* ADT Queue yang dapat digunakan */
boolean IsEmpty (QueueLagu Q){
    return (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF);
}

boolean IsFull (QueueLagu Q){
    return((Q.idxHead == Q.idxTail+1) || (Q.idxHead == 0 && Q.idxTail == MaxEl-1));
}

int Length (QueueLagu Q){
    if (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF){
        return 0;
    }
    else if (Q.idxTail == Q.idxHead){
        return 1;
    }
    else if (Q.idxTail>Q.idxHead){
        return(Q.idxTail-Q.idxHead+1);
    }
    else if (Q.idxTail<Q.idxHead){
        return((MaxEl-1-Q.idxHead+1)+(Q.idxTail+1));
    }
}

void CreateQueue (QueueLagu * Q){
    (*Q).idxHead = IDX_UNDEF;
    (*Q).idxTail = IDX_UNDEF;
}


void enqueue (QueueLagu * Q, int X){
    if (IsEmpty(*Q)){
        (*Q).idxHead = 0;
        (*Q).idxTail = 0;
        (*Q).lagu_queue[(*Q).idxTail].album_id = X;
    }
    else if (!IsFull(*Q)){
        if ((*Q).idxTail == MaxEl-1){
            (*Q).idxTail = 0;
        }
        else{
            (*Q).idxTail += 1;
        }
        (*Q).lagu_queue[(*Q).idxTail].album_id = X;
    }
    else{
        printf("Queue Lagu sudah penuh. Tidak dapat menambahkan lagu ke dalam queue\n");
    }
}

int dequeue (QueueLagu * Q){
    if (!IsEmpty(*Q)){
        int X = (*Q).lagu_queue[(*Q).idxHead].album_id;
        if ((*Q).idxHead==MaxEl-1){
            (*Q).idxHead = 0;
        }
        else if ((*Q).idxHead == (*Q).idxTail){
            (*Q).idxHead = IDX_UNDEF;
            (*Q).idxTail = IDX_UNDEF;
        }
        else{
            (*Q).idxHead += 1;
        }
        return X;
    }
}

void displayQueue(QueueLagu q){
    if (IsEmpty(q)){
        printf("[]\n");
        return;
    }

    int idxHead = IDX_HEAD(q);
    int idxTail = IDX_TAIL(q);

    printf("[");
    while(idxHead != idxTail) {
        printf("%d,", q.lagu_queue[idxHead].album_id);
        if(idxHead == MaxEl-1) {
            idxHead = 0;
        } else {
            idxHead++;
        }
    }
    printf("%d]\n", q.lagu_queue[idxHead].album_id);
}