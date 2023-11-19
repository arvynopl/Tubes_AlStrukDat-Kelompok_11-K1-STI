#include "stack.h"

void CreateHistori(HistoriLagu* H){
    (*H).idxTop = IDX_UNDEF;
}

boolean IsEmptyHistori(HistoriLagu H){
    return (H.idxTop == IDX_UNDEF);
}

boolean IsFullHistori(HistoriLagu H){
    return (H.idxTop == MaxEl - 1);
}

int LengthOfHistori(HistoriLagu H){
    if (IsEmptyHistori(H)){
        return 0;
    } else{
        int j = 0;
        for (int i = H.idxTop; i >= 0; i--){
            j++;
        }
        return j;
    }
}

void Push(HistoriLagu* H, Lagu L){
    if (!IsFullHistori(*H)){
        if (IsEmptyHistori(*H)){
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
    if (!IsEmptyHistori(*H)){
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

void PrintHistori(HistoriLagu H){
    if (!IsEmptyHistori(H)){
        int j = 1;
        for (int i = H.idxTop; i >= 0; i--){
            printf("%d. ", j);
            PrintWord(H.lagu_histori[i].lagu_nama);
            printf("\n");
            j++;
        }
    }
    printf("\n");
}