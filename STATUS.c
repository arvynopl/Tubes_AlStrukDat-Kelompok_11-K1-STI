#include "function.h"

void STATUS(){
    if (IsON){
        if (currPL.Length > 0){
            printf("Current Playlist: ");
            PrintWord(currPL);
            printf("\n");
        }

        printf("Now Playing:\n");
        if(currSong.lagu_nama.Length == 0){
            printf("No songs have been played yet. Please search for a song to begin playback.\n");
        }
        else{
            PrintWord(LP.penyanyi[currSong.penyanyi_id].penyanyi_nama);
            printf(" - ");
            PrintWord(LP.penyanyi[currSong.penyanyi_id].album_penyanyi[currSong.album_id].album_nama);
            printf(" - ");
            PrintWord(currSong.lagu_nama);
            printf("\n");
        }

        printf("\nQueue:\n");
        if(IsEmptyQueue(Queue)){
            printf("Your queue is empty.\n");
        }
        else{
            int idxHead = IDX_HEAD(Queue);
            int idxTail = IDX_TAIL(Queue);
            int i = 1;

            while(idxHead != idxTail) {
                printf("%d. ", i);
                PrintWord(LP.penyanyi[Queue.lagu_queue[idxHead].penyanyi_id].penyanyi_nama);
                printf(" - ");
                PrintWord(LP.penyanyi[Queue.lagu_queue[idxHead].penyanyi_id].album_penyanyi[Queue.lagu_queue[idxHead].album_id].album_nama);
                printf(" - ");
                PrintWord(Queue.lagu_queue[idxHead].lagu_nama);
                printf("\n");
                if(idxHead == MaxEl - 1) {
                    idxHead = 0;
                } 
                else {
                    idxHead++;
                }
                i++;
            }
            printf("%d. ", i);
            PrintWord(LP.penyanyi[Queue.lagu_queue[idxHead].penyanyi_id].penyanyi_nama);
            printf(" - ");
            PrintWord(LP.penyanyi[Queue.lagu_queue[idxHead].penyanyi_id].album_penyanyi[Queue.lagu_queue[idxHead].album_id].album_nama);
            printf(" - ");
            PrintWord(Queue.lagu_queue[idxHead].lagu_nama);
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    printf("\n\n");   
    CONSOLE();

}

// Fungsi tambahan
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

    CONSOLE();
}