#include <stdio.h>
#include "../ADT/list.h"

int main()
{
    ListPenyanyi test;
    CreateListPenyanyi(&test);
    Penyanyi isi = {{"Lau", 3}, {{"Liu", 3}, {{"gugu", 4}, 1, 1}, 4, 1}, 1};
    InsertFirstListPenyanyi(&test, isi);
    if (IsEmptyListPenyanyi)
    {
        printf("List ini kosong\n");
    }
    else
    {
        printf("List ini tidak kosong\n");
    }
    if (IsFullListPenyanyi)
    {
        printf("List ini penuh\n");
    }
    else
    {
        printf("List ini tidak penuh\n");
    }
    printf("Lenght dari list ini adalah : %d\n", LengthOfPenyanyi(test));

    int idx = 2;
    if (IsIdxValidOfListPenyanyi(idx))
    {
        printf("Indeks %d valid\n", idx);
    }
    else
    {
        printf("Indeks %d tidak valid\n", idx);
    }
    if (IsIdxEffOfListPenyanyi(test, idx))
    {
        printf("Indeks %d adalah indeks efektif\n", idx);
    }
    else
    {
        printf("Indeks %d bukan indeks efektif\n", idx);
    }
    int take = 2;
    printf("Elemen yang diambil oleh %d adalah %s\n", take, GetPenyanyi(test, take).penyanyi_nama.TabWord);

    int i = 2;
    Penyanyi set = {{"LALA", 4}, {{"LILI", 4}, {{"haha", 4}, 1, 1}, 4, 1}, 1};
    SetPenyanyi(&test, i, set);

    if (SearchPenyanyi(test, set))
    {
        printf("Penyanyi ditemukan\n");
    }
    else
    {
        printf("Penyanyi tidak ditemukan\n");
    }

    int j = 1;
    InsertFirstListPenyanyi(&test, set);
    printf("%s\n", GetPenyanyi(test, j).penyanyi_nama.TabWord);

    DeleteFirstListPenyanyi(&test);
    printf("%s\n", GetPenyanyi(test, j).penyanyi_nama.TabWord);

    InsertAtListPenyanyi(&test, set, take);
    printf("%s\n", GetPenyanyi(test, take).penyanyi_nama.TabWord);

    DeleteAtListPenyanyi(&test, take);
    printf("%s\n", GetPenyanyi(test, j).penyanyi_nama.TabWord);

    InsertLastListPenyanyi(&test, set);
    printf("%s\n", GetPenyanyi(test, LengthOfPenyanyi(test)).penyanyi_nama.TabWord);

    DeleteLastListPenyanyi(&test);
    printf("%s\n", GetPenyanyi(test, LengthOfPenyanyi(test)).penyanyi_nama.TabWord);

    ListPenyanyi test2, hasil;
    CreateListPenyanyi(&test2);
    InsertFirstListPenyanyi(&test2, set);
    ConcatListPenyanyi(test, test2);
    printf("%d + %d = %d\n", LengthOfPenyanyi(test), LengthOfPenyanyi(test2), LengthOfPenyanyi(hasil));
}
