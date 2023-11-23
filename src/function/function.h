#ifndef FUNCTION_H
#define FUNCTION_H

#include "../structure.h"
#include "../ADT/adt.h"

void CONSOLE();

/* ### FUNGSI UTAMA (COMMAND) ### */
/* Command START */
void STARTPROG(FILE* input);

/* Command LOAD */
void LOADPROG(FILE* input);

/* Command LIST */
void LISTDEFAULT();
void LISTPLAYLIST();

/* Command PLAY */
void PLAYSONG();
void PLAYPLAYLIST();

/* Command QUEUE */
void QUEUESONG();
void QUEUEPLAYLIST();
void QUEUESWAP();
void QUEUEREMOVE();
void QUEUECLEAR();

/* Command SONG */
void SONGNEXT();
void SONGPREVIOUS();

/* Command PLAYLIST */
void PLAYLISTCREATE();
void PLAYLISTADDSONG();
void PLAYLISTADDALBUM();
void PLAYLISTSWAP();
void PLAYLISTREMOVE();
void PLAYLISTDELETE();

/* Command STATUS */
void STATUS();

/* Command SAVE */
void SAVEPROG();

/* Command QUIT */
void QUITPROG();

/* Command HELP */
void HELP();

/* Command <INVALIDCOMMAND> */
boolean INVALIDCOMMAND(Word input, Word displayAll, Word start, Word load, Word help, Word listDefault, Word listPlaylist, Word playSong, Word playPlaylist, Word queueSong, Word queuePlaylist, Word queueSwap, Word queueRemove, Word queueClear, Word songNext, Word songPrevious, Word playlistCreate, Word playlistAddSong, Word playlistAddAlbum, Word playlistSwap, Word playlistRemove, Word playlistDelete, Word status, Word save, Word quit);

/* ### FUNGSI TAMBAHAN ### */
/* Fungsi cek isi struktur data */
void DisplayAll();

#endif