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
void QUEUESWAP(int x, int y);
void QUEUEREMOVE(int id);
void QUEUECLEAR();

/* Command SONG */
void SONGNEXT();
void SONGPREVIOUS();

/* Command PLAYLIST */
void PLAYLISTCREATE();
void PLAYLISTADDSONG();
void PLAYLISTADDALBUM();
void PLAYLISTSWAP(int id, int x, int y);
void PLAYLISTREMOVE(int id, int n);
void PLAYLISTDELETE();
void PLAYLISTENHANCE();

/* Command STATUS */
void STATUS();

/* Command SAVE */
void SAVEPROG(FILE* input);

/* Command QUIT */
void QUITPROG();

/* Command HELP */
void HELP();

/* Command <INVALIDCOMMAND> */
boolean INVALIDCOMMAND(Word input, Word displayAll, Word start, Word load, Word help, Word listDefault, Word listPlaylist, Word playSong, Word playPlaylist, Word queueSong, Word queuePlaylist, Word queueSwap, Word queueRemove, Word queueClear, Word songNext, Word songPrevious, Word playlistCreate, Word playlistAddSong, Word playlistAddAlbum, Word playlistSwap, Word playlistRemove, Word playlistDelete, Word playlistEnhance, Word status, Word save, Word quit);

/* ### FUNGSI TAMBAHAN ### */
/* Fungsi random angka */
unsigned int RAND();
/* Fungsi cek isi struktur data */
void DisplayAll();

#endif