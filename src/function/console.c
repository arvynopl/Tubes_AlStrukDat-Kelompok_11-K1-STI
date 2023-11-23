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
    
    Word ans;
    printf("\nKetik command disini: ");
    STARTINPUT(ans);
    ans = ToUpper(GetWord());
    printf("\n");

    if (INVALIDCOMMAND(ans, displayAll, start, load, help, listDefault, listPlaylist, playSong, playPlaylist, queueSong, queuePlaylist, queueSwap, queueRemove, queueClear, songNext, songPrevious, playlistCreate, playlistAddSong, playlistAddAlbum, playlistSwap, playlistRemove, playlistDelete, status, save, quit)){
        printf("Silakan masukkan command kembali.\n");
        printf("\nKetik command disini: ");
        STARTINPUT();
        ans = ToUpper(GetWord());
        printf("\n");
        while (INVALIDCOMMAND(ans, displayAll, start, load, help, listDefault, listPlaylist, playSong, playPlaylist, queueSong, queuePlaylist, queueSwap, queueRemove, queueClear, songNext, songPrevious, playlistCreate, playlistAddSong, playlistAddAlbum, playlistSwap, playlistRemove, playlistDelete, status, save, quit)){
            printf("Jika mengalami kesulitan, silakan ketik HELP untuk mendapatkan panduan.\n");
            printf("\nKetik command disini: ");
            STARTINPUT();
            ans = ToUpper(GetWord());
            printf("\n");
        }
    }

    if(WordCompare(ans,start)){
        IsON = false;
        FILE* input = fopen("save/filekonfigurasi_a.txt", "r");
        STARTPROG(input);
    }
    else if(WordCompare(ans,load)){
        IsON = false;
        Word ans;
        printf("Masukkan nama file (tanpa extension) sebagai lokasi pengambilan data: ");
        STARTINPUT();
        ans = GetWord();
        
        Word dir;
        dir = ToKata("save/");
        Word txt;
        txt = ToKata(".txt");
        ConcatWord(&dir, ans);
        ConcatWord(&dir, txt);

        char* file = WordToStr(dir);

        FILE* input = fopen(file, "r");
        
        if (input != Nil){
            LOADPROG(input);
        } else{
            printf("\nSave file tidak ditemukan. WayangWave gagal dijalankan.\n");
        }

        CONSOLE();
    }
    else if(WordCompare(ans,help)){
        HELP();
    }
    else if(WordCompare(ans,listDefault)){
        LISTDEFAULT();
    }
    else if(WordCompare(ans,listPlaylist)){
        LISTPLAYLIST();
    }
    else if(WordCompare(ans,playSong)){
        PLAYSONG();
    }
    else if(WordCompare(ans,playPlaylist)){
        PLAYPLAYLIST();
    }
    else if(WordCompare(ans,queueSong)){
        QUEUESONG();
    }
    else if(WordCompare(ans,queuePlaylist)){
        QUEUEPLAYLIST();
    }
    else if(WordCompare(ans,queueSwap)){
        QUEUESWAP();
    }
    else if(WordCompare(ans,queueRemove)){
        QUEUEREMOVE();
    }
    else if(WordCompare(ans,queueClear)){
        QUEUECLEAR();
    }
    else if(WordCompare(ans,songNext)){
        SONGNEXT();
    }
    else if(WordCompare(ans,songPrevious)){
        SONGPREVIOUS();
    }
    else if(WordCompare(ans,playlistCreate)){
        PLAYLISTCREATE();
    }
    else if(WordCompare(ans,playlistAddSong)){
        PLAYLISTADDSONG();
    }
    else if(WordCompare(ans,playlistAddAlbum)){
        PLAYLISTADDALBUM();
    }
    else if(WordCompare(ans,playlistSwap)){
        PLAYLISTSWAP();
    }
    else if(WordCompare(ans,playlistRemove)){
        PLAYLISTREMOVE();
    }
    else if(WordCompare(ans,playlistDelete)){
        PLAYLISTDELETE();
    }
    else if(WordCompare(ans,status)){
        STATUS();
    }
    else if(WordCompare(ans,save)){
        SAVEPROG();
    }
    else if(WordCompare(ans,quit)){
        QUITPROG();
    }
    else if(WordCompare(ans,displayAll)){
        DisplayAll();
    }

}