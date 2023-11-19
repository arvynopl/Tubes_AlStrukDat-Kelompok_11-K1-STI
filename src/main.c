#include "function/function.h"

void DisplayAll(){
    printf("--- List Penyanyi ---\n");
    PrintListPenyanyi(LP);
    printf("--- Lagu yang sedang diputar ---\n");
    PrintLagu(currSong);
    printf("%d\n", currSong.album_id);
    printf("%d\n", currSong.penyanyi_id);
    printf("\n--- Queue Lagu ---\n");
    PrintQueue(Queue);
    printf("--- Histori Lagu ---\n");
    PrintHistori(Histori);
    printf("--- List Playlist ---\n");
    PrintListPlaylist(ListPL);
}

int main(){
    FILE* input = fopen("D:/Tugas Besar/src/driver/filekonfigurasi_b.txt", "r");
    LOADPROG(input);
    DisplayAll();
    SAVEPROG();
    LISTDEFAULT();
    LISTPLAYLIST();
    return 0;
}