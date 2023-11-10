#include "structure.h"
#include <stdio.h>
#include "stack.h"

void CreateEmpty(HistoriLagu * H){
    (*H).idxTop = Nil;


boolean isEmpty(HistoriLagu * H){
    return (*H).idxTop == Nil;
}

boolean IsFull(HIstoriLagu *H){
    return (*H).idxTop == MaxEl - 1;
}

void Push(HistoriLagu * H, Lagu L){
    if (isEmpty (*H)){
        (*H).idxTop = 0;
        (*H).lagu_history[(*H).idxTop] = L;
    }else{
        idxTop ++;
        (*H).lagu_history[(*H).idxTop] = L;
    }
}

void Pop(HistoriLagu * H, Lagu* L){
    if (!isEmpty(*H)){
        *L = (*H).lagu_history[(*H).idxTop];
        (*H).idxTop--;
    }else{
        printf("error");
    }
}