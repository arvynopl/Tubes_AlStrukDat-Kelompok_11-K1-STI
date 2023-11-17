#include <stdio.h>
#include "boolean.h"
#include "queue.h"
#include "structure.h"

void queueSong(ListPenyanyi list, QueueLagu queue){
    Word inputPenyanyi, inputAlbum;
    int inputLagu;

    printf("Daftar Penyanyi :\n");
    for(int i = 0; i < ((list).penyanyi_length); i++){
        printf("    %d. ", i+1);
        PrintWord((list).penyanyi[i].penyanyi_nama);
    }
    printf("\n\nMasukkan Nama Penyanyi: ");
    scanf("%s", &inputPenyanyi);

    boolean found = false;
    int j = 0;
    while(found && j < (list).penyanyi_length){
        if(WordCompare(inputPenyanyi, (list).penyanyi[j].penyanyi_nama)){
            found = true;
            printf("Daftar Album oleh %c :\n", inputPenyanyi);
            for(int i = 0; i < (list).penyanyi[j].album_length; i++){
                printf("    %d. ", i+1);
                PrintWord((list).penyanyi[j].album_penyanyi[i].album_nama);
            }
            printf("\n\nMasukkan Nama Album yang dipilih : ");
            scanf("%s", &inputAlbum);
        }
        else{
            j++;
        }
    }
    if(!found){
        printf("Penyanyi tidak valid\n"); //***********BELUM TAU OUTPUTNYA APA
    }

    found = false;
    int k = 0;
    while(found && k < (list).penyanyi[j].album_length){
        if(WordCompare(inputAlbum, (list).penyanyi[j].album_penyanyi[k].album_nama)){
            found = true;
            printf("Daftar Lagu Album %c oleh %c :\n", inputAlbum, inputPenyanyi);
            for(int i = 0; i < (list).penyanyi[j].album_penyanyi[k].lagu_length; i++){
                printf("    %d. ", i+1);
                PrintWord((list).penyanyi[j].album_penyanyi[k].lagu_album[i].lagu_nama);
            }
            printf("\n\nMasukkan ID Lagu yang dipilih : ");
            scanf("%d", &inputLagu);
        }
        else{
            k++;
        }
    }
    if(!found){
        printf("Album tidak valid\n"); //***********BELUM TAU OUTPUTNYA APA
    }

    Enqueue(&queue, (list).penyanyi[j].album_penyanyi[k].lagu_album[inputLagu-1]);
    printf("Berhasil menambahkan lagu \"");
    PrintWord((list).penyanyi[j].album_penyanyi[k].lagu_album[inputLagu-1].lagu_nama);
    printf("\" oleh \"");
    PrintWord(inputPenyanyi);
    printf("\" ke queue.\n");
    //***********************************BAKAL JADI NEW LINE
}

void queuePlaylist(ListPlaylist list, QueueLagu queue){
    int inputId;
    printf("Masukkan ID Playlist: ");
    scanf("%d", inputId);

    for(int i=0; i<(list).(*playlist + inputId); i++){
        Enqueue(&queue, (list).playlist.playlist_nama.lagu_playlist);
    }

    printf("Berhasil menambahkan playlist \"");
    PrintWord((list).(*playlist+inputId).playlist_nama);
    printf("\" ke queue.\n");

}

queueSwap(QueueLagu queue){
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    if(x < (queue.idxTail+1) && y < (queue.idxTail+1)){
        if(y<x){
            int tempx = x;
            x = y;
            y = tempx;
        }

        Lagu tempLagux = queue.lagu_queue[x-1];
        Lagu tempLaguy = queue.lagu_queue[y-1];

        queue.lagu_queue[x-1] = tempLaguy;
        queue.lagu_queue[y-1] = tempLagux;

        printf("Lagu \"");
        PrintWord(queue.lagu_queue[x-1].lagu_nama);
        prinf("\" berhasil ditukar dengan \"");
        PrintWord(queue.lagu_queue[y-1].lagu_nama);
        printf("Lagu \"\n");
    }
    else{
        if(x > (queue.idxTail+1)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        }
        else if(y > (queue.idxTail+1)){
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
        }
        else{
            printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n", x, y);
        }
    }
}

