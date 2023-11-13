#include <stdio.h>
#include "../ADT/queue.h"

int main(){
    QueueLagu Q1;
    CreateQueue(&Q1);
    printf("Length dari Q1 adalah : %d\n",Length(Q1));
    if (IsEmpty(Q1)){
        printf("Status Queue : Queue Kosong\n");
    }
    else{
        printf("Status Queue : Queue tidak Kosong\n");
    }
    displayQueue(Q1);
    enqueue(&Q1,1);
    enqueue(&Q1,2);
    enqueue(&Q1,3);
    enqueue(&Q1,4);
    enqueue(&Q1,5);
    displayQueue(Q1);
    dequeue(&Q1);
    if (IsFull(Q1)){
        printf("Status Queue : Queue penuh\n");
    }
    else{
        printf("Status Queue : Queue tidak penuh\n");
    }
    displayQueue(Q1);
    printf("Length dari Q1 adalah : %d\n",Length(Q1));
}
