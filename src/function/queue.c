#include "function.h"

void QUEUESONG(){
    if (IsON){  
        printf("Daftar Penyanyi :\n");
        for (int i = 0; i < LP.penyanyi_length; i++){
            printf("%d. ", i + 1);
            PrintWord(LP.penyanyi[i].penyanyi_nama);
            printf("\n");
        }
        printf("\n");

        Word ans1;
        printf("Masukkan nama penyanyi yang dipilih: ");
        STARTINPUT();
        ans1 = GetWord();
        if (CheckPenyanyi(LP, ans1)){
            int idpenyanyi = IndexOfPenyanyiStr(LP, ans1);
            for (int i = 0; i < LP.penyanyi[idpenyanyi].album_length; i++){
                printf("%d. ", i + 1);
                PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[i].album_nama);
                printf("\n");
            }
            printf("\n");

            Word ans2;
            printf("Masukkan judul album yang dipilih: ");
            STARTINPUT();
            ans2 = GetWord();
            if (CheckAlbum(LP.penyanyi[idpenyanyi], ans2)){
                int idalbum = IndexOfAlbumStr(LP, ans1, ans2);
                for (int i = 0; i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length; i++){
                    printf("%d. ", i + 1);
                    PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i].lagu_nama);
                    printf("\n");
                }
                printf("\n");

                int idlagu;
                printf("Masukkan ID lagu yang dipilih: ");
                STARTINPUT();
                idlagu = WordToInt(GetWord());
                idlagu--;
                printf("\n");

                if (idlagu < 0 || idlagu > LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length){
                    Enqueue(&Queue, LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[idlagu]);
                    printf("Berhasil menambahkan lagu \"");
                    PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[idlagu].lagu_nama);
                    printf("\" oleh \"");
                    PrintWord(LP.penyanyi[idpenyanyi].penyanyi_nama);
                    printf("\" ke queue.\n");
                } else{
                    printf("Tidak ada lagu dengan ID %d di queue", idlagu + 1);
                }

            } else{
                printf("\nAlbum tidak ada dalam daftar. Silakan coba lagi.\n");
            }

        } else{
            printf("\nPenyanyi tidak ada dalam daftar. Silakan coba lagi.\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }
    
    CONSOLE();

}

void QUEUEPLAYLIST(){
    if (IsON){
        int ans; 
        printf("Masukkan ID Playlist: ");
        STARTINPUT();
        ans = WordToInt(GetWord());
        ans--;
        printf("\n");

        if (ans >= 0 && ans < ListPL.playlist_length){
            
            int n = LengthOfPlaylist(ListPL.playlist[ans]);
            NamaPlaylist* P = &(ListPL.playlist[ans]);
            Address Q = (*P).list;

            for (int i = 0; i < n; i++){
                if (!IsFullQueue(Queue)){
                    Enqueue(&Queue, (*Q).lagu_playlist);
                } else{
                    printf("Queue lagu sudah penuh. Silakan coba lagi.\n");
                    CONSOLE();
                    break;
                }
                Q = (*Q).next;
            }

            printf("Berhasil menambahkan playlist \"");
            PrintWord(ListPL.playlist[ans].playlist_nama);
            printf("\" ke queue.\n");

        } else{
            printf("Tidak ada playlist dengan ID %d.\n", ans + 1);
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}

void QUEUESWAP(int x, int y){
    if (IsON){
        x--;
        y--;

        int n = LengthOfQueue(Queue);
        if (x < 0 || x >= n || y < 0 || y >= n){
            if (x < 0 || x >= n){
                printf("Lagu dengan urutan ke-%d tidak terdapat dalam queue. Silakan coba lagi.\n", x);
            } else if (y < 0 || y >= n){
                printf("Lagu dengan urutan ke-%d tidak terdapat dalam queue. Silakan coba lagi.\n", y);
            }
        } else{
            x += Queue.idxHead;
            if (x >= MaxEl){
                x -= MaxEl;
            }
            y += Queue.idxHead;
            if (y >= MaxEl){
                y -= MaxEl;
            }
            
            Lagu temp;
            temp = Queue.lagu_queue[y];
            Queue.lagu_queue[y] = Queue.lagu_queue[x];
            Queue.lagu_queue[x] = temp;

            printf("Lagu \"");
            PrintWord(Queue.lagu_queue[y].lagu_nama);
            printf("\" berhasil ditukar dengan \"");
            PrintWord(Queue.lagu_queue[x].lagu_nama);
            printf("\".\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}

void QUEUEREMOVE(int id){
    if (IsON){
        id--;

        if (!IsEmptyQueue(Queue)){
            if (id < 0 || id >= LengthOfQueue(Queue)){
                printf("Lagu dengan urutan ke-%d tidak ada.\n", id);
            } else{
                if (Queue.idxHead == Queue.idxTail){
                    Queue.idxHead = IDX_UNDEF;
                    Queue.idxTail = IDX_UNDEF;
                } else{
                    id += Queue.idxHead;
                    if (id >= MaxEl){
                        id -= MaxEl;
                    }
                    Lagu temp = Queue.lagu_queue[id];
                    int i = id;
                    for (int j = id; j < Queue.idxHead + LengthOfQueue(Queue) - 1; j++){
                        if (i + 1 == MaxEl){
                            Queue.lagu_queue[i] = Queue.lagu_queue[0];
                        } else{
                            Queue.lagu_queue[i] = Queue.lagu_queue[i + 1];
                        }
                        i++;
                        if (i == MaxEl){
                            i = 0;
                        }
                    }
                    Queue.idxTail = i - 1;
                    
                    printf("Lagu \"");
                    PrintWord(temp.lagu_nama);
                    printf("\" oleh \"");
                    PrintWord(LP.penyanyi[temp.penyanyi_id].penyanyi_nama);
                    printf("\" telah dihapus dari queue.\n");
                }
            }

        } else{
            printf("Queue kosong. Silakan queue lagu terlebih dahulu.\n");
        }

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}

void QUEUECLEAR(){
    if (IsON){
        CreateQueue(&Queue);
        printf("Queue berhasil dikosongkan.\n");

    } else{
        printf("Anda belum masuk ke dalam program...\n");
    }

    CONSOLE();

}