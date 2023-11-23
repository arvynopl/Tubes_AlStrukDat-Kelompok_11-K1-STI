#include "function.h"

void CONSOLE(){
    Word start;
    start = ToKata("START");

    Word load;
    load = ToKata("LOAD");

    Word help;
    help = ToKata("HELP");

    Word listDefault;
    listDefault = ToKata("LIST DEFAULT");

    Word listPlaylist;
    listPlaylist = ToKata("LIST PLAYLIST");

    Word playSong;
    playSong = ToKata("PLAY SONG");

    Word playPlaylist;
    playPlaylist = ToKata("PLAY PLAYLIST");

    Word queueSong;
    queueSong = ToKata("QUEUE SONG");

    Word queuePlaylist;
    queuePlaylist = ToKata("QUEUE PLAYLIST");

    Word queueSwap;
    queueSwap = ToKata("QUEUE SWAP");

    Word queueRemove;
    queueRemove = ToKata("QUEUE REMOVE");

    Word queueClear;
    queueClear = ToKata("QUEUE CLEAR");

    Word songNext;
    songNext = ToKata("SONG NEXT");

    Word songPrevious;
    songPrevious = ToKata("SONG PREVIOUS");

    Word playlistCreate;
    playlistCreate = ToKata("PLAYLIST CREATE");

    Word playlistAddSong;
    playlistAddSong = ToKata("PLAYLIST ADD SONG");

    Word playlistAddAlbum;
    playlistAddAlbum = ToKata("PLAYLIST ADD ALBUM");

    Word playlistSwap;
    playlistSwap = ToKata("PLAYLIST SWAP");

    Word playlistRemove;
    playlistRemove = ToKata("PLAYLIST REMOVE");

    Word playlistDelete;
    playlistDelete = ToKata("PLAYLIST DELETE");

    Word status;
    status = ToKata("STATUS");

    Word save;
    save = ToKata("SAVE");

    Word quit;
    quit = ToKata("QUIT");

    Word displayAll;
    displayAll = ToKata("DISPLAY ALL");
    
    Word ans1;
    Word ans2;
    Word ans3;
    int id1, id2, id3;
    printf("\nKetik command disini: ");
    STARTCOMMAND();
    ans1 = ToUpper(GetWord());
    if (WordCompare(ans1, ToKata("LIST")) || WordCompare(ans1, ToKata("PLAY")) || WordCompare(ans1, ToKata("QUEUE")) || WordCompare(ans1, ToKata("SONG")) || WordCompare(ans1, ToKata("PLAYLIST")) || WordCompare(ans1, ToKata("DISPLAY"))){
        ADVINPUT();
        ans2 = ToUpper(GetWord());
        if (WordCompare(ans1, ToKata("QUEUE")) && WordCompare(ans2, ToKata("SWAP"))){
            ADVINPUT();
            id1 = WordToInt(GetWord());
            ADVINPUT();
            id2 = WordToInt(GetWord());
        } else if (WordCompare(ans1, ToKata("QUEUE")) && WordCompare(ans2, ToKata("REMOVE"))){
            ADVINPUT();
            id1 = WordToInt(GetWord());
        } else if (WordCompare(ans1, ToKata("PLAYLIST")) && WordCompare(ans2, ToKata("SWAP"))){
            ADVINPUT();
            id1 = WordToInt(GetWord());
            ADVINPUT();
            id2 = WordToInt(GetWord());
            ADVINPUT();
            id3 = WordToInt(GetWord());
        } else if (WordCompare(ans1, ToKata("PLAYLIST")) && WordCompare(ans2, ToKata("REMOVE"))){
            ADVINPUT();
            id1 = WordToInt(GetWord());
            ADVINPUT();
            id2 = WordToInt(GetWord());
        } else if (WordCompare(ans1, ToKata("PLAYLIST")) && WordCompare(ans2, ToKata("ADD"))){
            ADVINPUT();
            ans3 = ToUpper(GetWord());
            ConcatWord(&ans2, ans3);
        }
        ConcatWord(&ans1, ans2);
        printf("\n");
    } else{
        if (WordCompare(ans1, ToKata("LOAD"))){
            ADVINPUT();
            ans2 = GetWord();
        } else if (WordCompare(ans1, ToKata("SAVE"))){
            ADVINPUT();
            ans2 = GetWord();
        }
    }

    while (INVALIDCOMMAND(ans1, displayAll, start, load, help, listDefault, listPlaylist, playSong, playPlaylist, queueSong, queuePlaylist, queueSwap, queueRemove, queueClear, songNext, songPrevious, playlistCreate, playlistAddSong, playlistAddAlbum, playlistSwap, playlistRemove, playlistDelete, status, save, quit)){
        printf("Silakan masukkan command kembali.\n");
        printf("Jika mengalami kesulitan, silakan ketik HELP untuk mendapatkan panduan.\n");
        printf("\nKetik command disini: ");
        STARTCOMMAND();
        ans1 = ToUpper(GetWord());
        if (WordCompare(ans1, ToKata("LIST")) || WordCompare(ans1, ToKata("PLAY")) || WordCompare(ans1, ToKata("QUEUE")) || WordCompare(ans1, ToKata("SONG")) || WordCompare(ans1, ToKata("PLAYLIST")) || WordCompare(ans1, ToKata("DISPLAY"))){
            ADVINPUT();
            ans2 = ToUpper(GetWord());
            if (WordCompare(ans1, ToKata("QUEUE")) && WordCompare(ans2, ToKata("SWAP"))){
                ADVINPUT();
                id1 = WordToInt(GetWord());
                ADVINPUT();
                id2 = WordToInt(GetWord());
            } else if (WordCompare(ans1, ToKata("QUEUE")) && WordCompare(ans2, ToKata("REMOVE"))){
                ADVINPUT();
                id1 = WordToInt(GetWord());
            } else if (WordCompare(ans1, ToKata("PLAYLIST")) && WordCompare(ans2, ToKata("SWAP"))){
                ADVINPUT();
                id1 = WordToInt(GetWord());
                ADVINPUT();
                id2 = WordToInt(GetWord());
                ADVINPUT();
                id3 = WordToInt(GetWord());
            } else if (WordCompare(ans1, ToKata("PLAYLIST")) && WordCompare(ans2, ToKata("REMOVE"))){
                ADVINPUT();
                id1 = WordToInt(GetWord());
                ADVINPUT();
                id2 = WordToInt(GetWord());
            } else if (WordCompare(ans1, ToKata("PLAYLIST")) && WordCompare(ans2, ToKata("ADD"))){
                ADVINPUT();
                ans3 = ToUpper(GetWord());
                ConcatWord(&ans2, ans3);
            }
            ConcatWord(&ans1, ans2);
            printf("\n");
        } else{
            if (WordCompare(ans1, ToKata("LOAD"))){
                ADVINPUT();
                ans2 = GetWord();
            } else if (WordCompare(ans1, ToKata("SAVE"))){
                ADVINPUT();
                ans2 = GetWord();
            }
        }
    }

    if(WordCompare(ans1,start)){
        FILE* input = fopen("save/filekonfigurasi_a.txt", "r");
        STARTPROG(input);
    }
    else if(WordCompare(ans1,load)){     
        Word dir;
        dir = ToKata("save/");
        ConcatWordNoSpace(&dir, ans2);

        char* file = WordToStr(dir);

        FILE* input = fopen(file, "r");
        
        if (input != Nil){
            LOADPROG(input);
        } else{
            printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
        }

        CONSOLE();
    }
    else if(WordCompare(ans1,help)){
        HELP();
    }
    else if(WordCompare(ans1,listDefault)){
        LISTDEFAULT();
    }
    else if(WordCompare(ans1,listPlaylist)){
        LISTPLAYLIST();
    }
    else if(WordCompare(ans1,playSong)){
        PLAYSONG();
    }
    else if(WordCompare(ans1,playPlaylist)){
        PLAYPLAYLIST();
    }
    else if(WordCompare(ans1,queueSong)){
        QUEUESONG();
    }
    else if(WordCompare(ans1,queuePlaylist)){
        QUEUEPLAYLIST();
    }
    else if(WordCompare(ans1,queueSwap)){
        QUEUESWAP(id1, id2);
    }
    else if(WordCompare(ans1,queueRemove)){
        QUEUEREMOVE(id1);
    }
    else if(WordCompare(ans1,queueClear)){
        QUEUECLEAR();
    }
    else if(WordCompare(ans1,songNext)){
        SONGNEXT();
    }
    else if(WordCompare(ans1,songPrevious)){
        SONGPREVIOUS();
    }
    else if(WordCompare(ans1,playlistCreate)){
        PLAYLISTCREATE();
    }
    else if(WordCompare(ans1,playlistAddSong)){
        PLAYLISTADDSONG();
    }
    else if(WordCompare(ans1,playlistAddAlbum)){
        PLAYLISTADDALBUM();
    }
    else if(WordCompare(ans1,playlistSwap)){
        PLAYLISTSWAP(id1, id2, id3);
    }
    else if(WordCompare(ans1,playlistRemove)){
        PLAYLISTREMOVE(id1, id2);
    }
    else if(WordCompare(ans1,playlistDelete)){
        PLAYLISTDELETE();
    }
    else if(WordCompare(ans1,status)){
        STATUS();
    }
    else if(WordCompare(ans1,save)){
        Word dir;
        dir = ToKata("save/");
        ConcatWordNoSpace(&dir, ans2);

        char* file = WordToStr(dir);

        FILE* input = fopen(file, "w");

        SAVEPROG(input);
    }
    else if(WordCompare(ans1,quit)){
        QUITPROG();
    }
    else if(WordCompare(ans1,displayAll)){
        DisplayAll();
    }

}