#include "function.h"

void SONGNEXT(){
    if (IsON){
        if (!IsEmptyQueue(Queue)){
            currSong = Dequeue(&Queue);
            currPL.Length = 0;
            currPL.TabWord[0] = STR_UNDEF;

            Push(&Histori, currSong);
            printf("Memutar lagu selanjutnya\n");
            printf("\"");
            PrintWord(currSong.lagu_nama);
            printf("\" oleh \"");
            PrintWord(LP.penyanyi[currSong.penyanyi_id].penyanyi_nama);
            printf("\"\n");

        } else{
            if (currSong.lagu_nama.Length == 0){
                printf("Anda belum memutar lagu. Silakan coba lagi.\n");
            } else{
                printf("Queue kosong, memutar kembali lagu\n");
                printf("\"");
                PrintWord(currSong.lagu_nama);
                printf("\" oleh \"");
                PrintWord(LP.penyanyi[currSong.penyanyi_id].penyanyi_nama);
                printf("\"\n");
            }

        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }
    
    CONSOLE();

}

void SONGPREVIOUS(){
    if (IsON){
        if (!IsEmptyHistori(Histori)){
            if (IsEmptyQueue(Queue)){
                Pop(&Histori, &currSong);
                Enqueue(&Queue, currSong);
                
                currPL.Length = 0;
                currPL.TabWord[0] = STR_UNDEF;

                printf("Memutar lagu sebelumnya\n");
                printf("\"");
                PrintWord(currSong.lagu_nama);
                printf("\" oleh \"");
                PrintWord(LP.penyanyi[currSong.penyanyi_id].penyanyi_nama);
                printf("\"\n");

            } else{
                if (!IsFullQueue(Queue)){
                    Pop(&Histori, &currSong);
                    Lagu temp = Queue.lagu_queue[Queue.idxTail];
                    int i = Queue.idxTail;
                    for (int j = Queue.idxHead + LengthOfQueue(Queue) - 1; j > Queue.idxHead; j--){
                        if (i - 1 < 0){
                            Queue.lagu_queue[i] = Queue.lagu_queue[MaxEl - 1];
                        } else{
                            Queue.lagu_queue[i] = Queue.lagu_queue[i - 1];
                        }
                        i--;
                        if (i < 0){
                            i = MaxEl - 1;
                        }
                    }

                    Queue.idxTail = Queue.idxTail + 1;
                    if (Queue.idxTail >= MaxEl){
                        Queue.idxTail -= MaxEl;
                    }
                    Queue.lagu_queue[Queue.idxTail] = temp;
                    Queue.lagu_queue[Queue.idxHead] = currSong;

                    currPL.Length = 0;
                    currPL.TabWord[0] = STR_UNDEF;

                    printf("Memutar lagu sebelumnya\n");
                    printf("\"");
                    PrintWord(currSong.lagu_nama);
                    printf("\" oleh \"");
                    PrintWord(LP.penyanyi[currSong.penyanyi_id].penyanyi_nama);
                    printf("\"\n");

                } else{
                    printf("Histori lagu penuh. Silakan coba lagi.\n");
                }
            }

        } else {
            printf("Histori lagu kosong, memutar kembali lagu\n");
            printf("\"");
            PrintWord(currSong.lagu_nama);
            printf("\" oleh \"");
            PrintWord(LP.penyanyi[currSong.penyanyi_id].penyanyi_nama);
            printf("\".\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}
