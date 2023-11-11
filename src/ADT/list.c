#include "list.h"

void MakeListPenyanyi(ListPenyanyi* LP){
    (*LP).penyanyi_length = Nil;
}

boolean IsEmptyListPenyanyi(ListPenyanyi LP){
    return (LP.penyanyi_length == Nil);
}

boolean IsFullListPenyanyi(ListPenyanyi LP){
    return (LP.penyanyi_length == MaxEl/20);
}

int LengthOfPenyanyi(ListPenyanyi LP){
    return 0;
}

boolean IsIdxValidOfListPenyanyi(int i){
    return (i >= 0) && (i < MaxEl);
}

boolean IsIdxEffOfListPenyanyi(ListPenyanyi LP, int i){
    return (i >= 0) && (i < LP.penyanyi_length);
}

Penyanyi GetPenyanyi(ListPenyanyi LP, int i){
    return LP.penyanyi[i];
}

void SetPenyanyi(ListPenyanyi *LP, int i, Penyanyi P){
    if (i < LengthOfPenyanyi(*LP)){
        (*LP).penyanyi[i] = P;
    }
}

boolean SearchPenyanyi(ListPenyanyi LP, Penyanyi P){
    boolean found = false;
    int n = LengthOfPenyanyi(LP);
    int i = 0;
    while (!found && i < n){
        if (WordCompare(LP.penyanyi[i].penyanyi_nama, P.penyanyi_nama)){
            found = true;
        }
        i++;
    }
    return found;
}

void InsertFirstListPenyanyi(ListPenyanyi* LP, Penyanyi P){
    if (!IsFullListPenyanyi(*LP)){
        int i = (*LP).penyanyi_length - 1;
        while (i >= 0 && i < MaxEl){
            SetPenyanyi(LP, i + 1, GetPenyanyi(*LP, i));
            i--;
        }
        SetPenyanyi(LP, 0, P);
        (*LP).penyanyi_length++;
    } else{
        printf("List Penyanyi sudah penuh...\n");
    }

}

void InsertAtListPenyanyi(ListPenyanyi* LP, Penyanyi P, int i){
    if (!IsFullListPenyanyi(*LP)){
        int j = (*LP).penyanyi_length - 1;
        while (i <= j){
            SetPenyanyi(LP, j + 1, GetPenyanyi(*LP, j));
            j--;
        }
        SetPenyanyi(LP, i, P);
        (*LP).penyanyi_length++;
    } else{
        printf("List Penyanyi sudah penuh...\n");
    }
}

void InsertLastListPenyanyi(ListPenyanyi* LP, Penyanyi P){
    if (!IsFullListPenyanyi(*LP)){
        if (IsEmptyListPenyanyi(*LP)){
            InsertFirstListPenyanyi(LP, P);
        } else{
            (*LP).penyanyi[(*LP).penyanyi_length] = P;
            (*LP).penyanyi_length++;
        }
    } else{
        printf("List Penyanyi sudah penuh...\n");
    }
}

void DeleteFirstListPenyanyi(ListPenyanyi* LP){
    if (!IsEmptyListPenyanyi(*LP)){
        int i = 0;
        int j = (*LP).penyanyi_length - 2;
        while (i < j){
            (*LP).penyanyi[i] = (*LP).penyanyi[i + 1];
            i++;
        }
        (*LP).penyanyi_length--;
    } else{
        printf("List Penyanyi kosong. Silahkan tambah penyanyi...\n");
    }
}

void DeleteAtListPenyanyi(ListPenyanyi* LP, int i){
    if (!IsEmptyListPenyanyi(*LP)){
        int j = (*LP).penyanyi_length - 1;
        while (i <= j){
            (*LP).penyanyi[i] = (*LP).penyanyi[i + 1];
            i++;
        }
        (*LP).penyanyi_length--;
    } else{
        printf("List Penyanyi kosong. Silahkan tambah penyanyi...\n");
    }    
}

void DeleteLastListPenyanyi(ListPenyanyi* LP){
    if (!IsEmptyListPenyanyi(*LP)){
        (*LP).penyanyi_length--;
    } else{
        printf("List Penyanyi kosong. Silahkan tambah penyanyi...\n");
    }  
}

ListPenyanyi ConcatListPenyanyi(ListPenyanyi L1, ListPenyanyi L2){
    ListPenyanyi L3;
    MakeListPenyanyi(&L3);
    int i = 0;
    int j = (L1).penyanyi_length - 1;
    int idx = 0;
    while (i <= j){
        L3.penyanyi[idx] = L1.penyanyi[i];
        idx++;
        i++;
    }
    i = 0;
    j = (L2).penyanyi_length - 1;
    while (i <= j)
    {
        L3.penyanyi[idx] = L2.penyanyi[i];
        idx++;
        i++;
    }
    return L3;
}
