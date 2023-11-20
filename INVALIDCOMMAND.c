#include <stdio.h>
#include "INVALIDCOMMAND.h"

boolean INVALIDCOMMAND(boolean isMasuk, Word input){
    Word start;
    start = ToKata("START");
    start.Length = StringLength("START");

    Word load;
    load = ToKata("LOAD");
    load.Length = StringLength("LOAD");

    Word help;
    help = ToKata("HELP");
    help.Length = StringLength("HELP");

    Word listDefault;
    listDefault = ToKata("LIST DEFAULT");
    listDefault.Length = StringLength("LIST DEFAULT");

    Word listPlaylist;
    listPlaylist = ToKata("LIST PLAYLIST");
    listPlaylist.Length = StringLength("LIST PLAYLIST");

    Word playSong;
    playSong = ToKata("PLAY SONG");
    playSong.Length = StringLength("PLAY SONG");

    Word playPlaylist;
    playPlaylist = ToKata("PLAY PLAYLIST");
    playPlaylist.Length = StringLength("PLAY PLAYLIST");

    Word queueSong;
    queueSong = ToKata("QUEUE SONG");
    queueSong.Length = StringLength("QUEUE SONG");

    Word queuePlaylist;
    queuePlaylist = ToKata("QUEUE PLAYLIST");
    queuePlaylist.Length = StringLength("QUEUE PLAYLIST");

    Word queueSwap;
    queueSwap = ToKata("QUEUE SWAP");
    queueSwap.Length = StringLength("QUEUE SWAP");

    Word queueRemove;
    queueRemove = ToKata("QUEUE REMOVE");
    queueRemove.Length = StringLength("QUEUE REMOVE");

    Word queueClear;
    queueClear = ToKata("QUEUE CLEAR");
    queueClear.Length = StringLength("QUEUE CLEAR");

    Word songNext;
    songNext = ToKata("SONG NEXT");
    songNext.Length = StringLength("SONG NEXT");

    Word songPrevious;
    songPrevious = ToKata("SONG PREVIOUS");
    songPrevious.Length = StringLength("SONG PREVIOUS");

    Word playlistCreate;
    playlistCreate = ToKata("PLAYLIST CREATE");
    playlistCreate.Length = StringLength("PLAYLIST CREATE");

    Word playlistAdd;
    playlistAdd = ToKata("PLAYLIST ADD");
    playlistAdd.Length = StringLength("PLAYLIST ADD");

    Word playlistSwap;
    playlistSwap = ToKata("PLAYLIST SWAP");
    playlistSwap.Length = StringLength("PLAYLIST SWAP");

    Word playlistRemove;
    playlistRemove = ToKata("PLAYLIST REMOVE");
    playlistRemove.Length = StringLength("PLAYLIST REMOVE");

    Word playlistDelete;
    playlistDelete = ToKata("PLAYLIST DELETE");
    playlistDelete.Length = StringLength("PLAYLIST DELETE");

    Word status;
    status = ToKata("STATUS");
    status.Length = StringLength("STATUS");

    Word save;
    save = ToKata("SAVE");
    save.Length = StringLength("SAVE");

    Word quit;
    quit = ToKata("QUIT");
    quit.Length = StringLength("QUIT");

    if(isMasuk){
        if(WordCompare(input,start)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,load)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,help)){
            return false;
        }
        else if(WordCompare(input,listDefault)){
            return false;
        }
        else if(WordCompare(input,listPlaylist)){
            return false;
        }
        else if(WordCompare(input,playSong)){
            return false;
        }
        else if(WordCompare(input,playPlaylist)){
            return false;
        }
        else if(WordCompare(input,queueSong)){
            return false;
        }
        else if(WordCompare(input,queuePlaylist)){
            return false;
        }
        else if(WordCompare(input,queueSwap)){
            return false;
        }
        else if(WordCompare(input,queueRemove)){
            return false;
        }
        else if(WordCompare(input,queueClear)){
            return false;
        }
        else if(WordCompare(input,songNext)){
            return false;
        }
        else if(WordCompare(input,songPrevious)){
            return false;
        }
        else if(WordCompare(input,playlistCreate)){
            return false;
        }
        else if(WordCompare(input,playlistAdd)){
            return false;
        }
        else if(WordCompare(input,playlistSwap)){
            return false;
        }
        else if(WordCompare(input,playlistRemove)){
            return false;
        }
        else if(WordCompare(input,playlistDelete)){
            return false;
        }
        else if(WordCompare(input,status)){
            return false;
        }
        else if(WordCompare(input,save)){
            return false;
        }
        else if(WordCompare(input,quit)){
            return false;
        }
        else{
            printf("Command tidak diketahui!\n");
            return true;       
        }
    }
    else{
        if(WordCompare(input,start)){
            return false;
        }
        else if(WordCompare(input,load)){
            return false;
        }
        else if(WordCompare(input,help)){
            return false;
        }
        else if(WordCompare(input,listDefault)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,listPlaylist)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,playSong)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,playPlaylist)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,queueSong)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,queuePlaylist)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,queueSwap)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,queueRemove)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,queueClear)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,songNext)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,songPrevious)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,playlistCreate)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,playlistAdd)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,playlistSwap)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,playlistRemove)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,playlistDelete)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,status)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,save)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,quit)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else{
            printf("Command tidak diketahui!\n");
            return true;
        }
    }
}