#include <stdio.h>
#include "boolean.h"
#include "queue.h"
#include "structure.h"

queue_song(){
    ListPenyanyi list;
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

    printf("Berhasil menambahkan lagu \"");
    PrintWord((list).penyanyi[j].album_penyanyi[k].lagu_album[inputLagu-1].lagu_nama);
    printf("\" oleh \"");
    PrintWord(inputPenyanyi);
    printf("\" ke queue.\n");
    //***********************************BAKAL JADI NEW LINE
}

