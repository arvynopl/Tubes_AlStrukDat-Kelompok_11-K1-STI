#include "stack.h"

void CreateEmpty(HistoriLagu* H){
    (*H).idxTop = IDX_UNDEF;
}

boolean IsEmpty(HistoriLagu H){
    return (H.idxTop == IDX_UNDEF);
}

boolean IsFull(HistoriLagu H){
    return (H.idxTop == MaxEl - 1);
}

void Push(HistoriLagu* H, Lagu L){
    if (!IsFull(*H)){
        if (IsEmpty(*H)){
            (*H).idxTop = 0;
        } else{
            (*H).idxTop++;
        }
        (*H).lagu_histori[(*H).idxTop] = L;
    } else{
        printf ("Histori lagu sudah penuh...\n");
    }
}

void Pop(HistoriLagu* H, Lagu* L){
    if (!IsEmpty(*H)){
        *L = (*H).lagu_histori[(*H).idxTop];
        if ((*H).idxTop == 0){
            (*H).idxTop = IDX_UNDEF;
        } else{
            (*H).idxTop--;
        }
    } else{
        printf("Histori lagu kosong, silahkan play lagu terlebih dahulu...\n");
    }
}