#include <stdio.h>
#include "STATUS.h"

void STATUS(QueueLagu Q, Lagu currSong, ListPenyanyi ListPenyanyi){
    /* CURRENT PLAYLIST HOW ?*/

    printf("\n");
    printf("Now Playing:\n");
    if(currSong.lagu_nama.Length == 0){
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    }
    else{
        PrintWord(ListPenyanyi.penyanyi[currSong.penyanyi_id].penyanyi_nama);
        printf(" - ");
        PrintWord(ListPenyanyi.penyanyi[currSong.penyanyi_id].album_penyanyi[currSong.album_id].album_nama);
        printf(" - ");
        PrintWord(currSong.lagu_nama);
    }
    printf("\n");
    printf("Queue:\n");
    if(IsEmpty(Q)){
        printf("Your queue is empty.\n");
    }
    else{
        int idxHead = IDX_HEAD(Q);
        int idxTail = IDX_TAIL(Q);

        while(idxHead != idxTail) {
            printf("%d. ", idxHead);
            PrintWord(ListPenyanyi.penyanyi[Q.idxHead].penyanyi_nama);
            printf(" - ");
            PrintWord(ListPenyanyi.penyanyi[Q.idxHead].album_penyanyi[Q.lagu_queue[Q.idxHead].album_id].album_nama);
            PrintWord(Q.lagu_queue[idxHead].lagu_nama);
            printf("\n");
            if(idxHead == MaxEl-1) {
                idxHead = 0;
            } 
            else {
                idxHead++;
            }
        }
        printf("%d. ", idxHead);
        PrintWord(ListPenyanyi.penyanyi[Q.idxHead].penyanyi_nama);
        printf(" - ");
        PrintWord(ListPenyanyi.penyanyi[Q.idxHead].album_penyanyi[Q.lagu_queue[Q.idxHead].album_id].album_nama);
        printf(" - ");
        PrintWord(Q.lagu_queue[idxHead].lagu_nama);
    }
}