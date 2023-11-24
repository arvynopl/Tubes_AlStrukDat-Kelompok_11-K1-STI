#include "function.h"

boolean INVALIDCOMMAND(Word input, Word displayAll, Word start, Word load, Word help, Word listDefault, Word listPlaylist, Word playSong, Word playPlaylist, Word queueSong, Word queuePlaylist, Word queueSwap, Word queueRemove, Word queueClear, Word songNext, Word songPrevious, Word playlistCreate, Word playlistAddSong, Word playlistAddAlbum, Word playlistSwap, Word playlistRemove, Word playlistDelete, Word playlistEnhance, Word status, Word save, Word quit){
    if(IsON){
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
        else if(WordCompare(input,playlistAddSong)){
            return false;
        }
        else if(WordCompare(input,playlistAddAlbum)){
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
        else if(WordCompare(input,playlistEnhance)){
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
        else if(WordCompare(input,displayAll)){
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
        else if(WordCompare(input,playlistAddSong)){
            printf("Command tidak bisa dieksekusi!\n");
            return true;
        }
        else if(WordCompare(input,playlistAddAlbum)){
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
        else if(WordCompare(input,playlistEnhance)){
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
        else if(WordCompare(input,displayAll)){
            return false;
        }
        else{
            printf("Command tidak diketahui!\n");
            return true;
        }
    }
}