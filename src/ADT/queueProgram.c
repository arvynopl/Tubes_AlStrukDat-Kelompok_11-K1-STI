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

queueRemove(QueueLagu queue, ListPenyanyi list){
    int inputUrutan;
    scanf("%d", &inputUrutan);

    QueueLagu temp;
    CreateQueue(&temp);

    if(inputUrutan < (queue.idxTail+1)){
        for(int i=1; i<inputUrutan; i++){
            Lagu first = HEAD(queue);
            Dequeue(&queue);
            Enqueue(&temp, first);
        }

        Lagu del = HEAD(queue);
        Dequeue(&queue);

        for(int i=inputUrutan+1; i<IDX_TAIL(queue); i++){
            Lagu first = HEAD(queue);
            Dequeue(&queue);
            Enqueue(&temp, first);
        }
        boolean found = false;
        int x, y, z;
        while(!found){
            for(x=0; x<(list).penyanyi_length; x++){
                for(y=0; y<(list).penyanyi[x].album_length; y++){
                    for(z=0; z<(list).penyanyi[x].album_penyanyi[y].lagu_length; z++){
                        if(WordCompare(del.lagu_nama, (list).penyanyi[x].album_penyanyi[y].lagu_album[z].lagu_nama)){
                            break;
                        }
                    }
                }
            }
        }
        printf("Lagu \"");
        PrintWord(del.lagu_nama);
        printf("\" oleh \"");
        PrintWord((list).penyanyi[x].penyanyi_nama);
        prinf("\" telah dihapus dari queue!\n");
    }
}

queueClear(QueueLagu queue){
    CreateQueue(&queue);
    printf("Queue berhasil dikosongkan.\n");
}