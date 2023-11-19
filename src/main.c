#include "function/function.h"

int main(){
    FILE* input = fopen("D:/Tugas Besar/src/driver/filekonfigurasi_b.txt", "r");
    LOADPROG(input);
    printf("--- List Penyanyi ---\n");
    PrintListPenyanyi(LP);
    printf("\n");
    printf("--- Lagu yang sedang diputar ---\n");
    PrintLagu(currSong);
    printf("\n");
    printf("--- Queue Lagu ---\n");
    PrintQueue(Queue);
    printf("\n");
    printf("--- Histori Lagu ---\n");
    PrintHistori(Histori);
    printf("\n");
    printf("--- List Playlist ---\n");
    PrintListPlaylist(ListPL);
    printf("\n");
    return 0;
}