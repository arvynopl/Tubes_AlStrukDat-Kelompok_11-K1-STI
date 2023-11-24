#ifndef STRUCTURE_H
#define STRUCTURE_H
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define Nil 0
#define MaxEl 100
#define IDX_UNDEF -1
#define INT_UNDEF -999
#define STR_UNDEF '\0'
#define MARK '\n'
#define COLON ';'
#define STRIP '-'
#define BLANK ' '
#define TAB '\t'
#define RET '\r'
#define VTAB '\v'
#define FEED '\f'
#define BACKSPACE '\b'

typedef struct kata{
   char TabWord[MaxEl]; /* Container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;
typedef int Key;

/* Struktur Data Lagu [Map (& Set)] */
/*  Indeks lagu [0..lagu_length] merupakan key dari map Album -> Lagu 
    Nilai variabel lagu_nama merupakan value dari map Album -> Lagu */
typedef struct lagu {
    Word lagu_nama;
    int album_id;
    int penyanyi_id;
} Lagu;
/* ### Akses Elemen Lagu ### */
#define LAGU_NAMA(L, i, j, k) (L).penyanyi[i].album_penyanyi[j].lagu_album[k].lagu_nama
#define LAGU_ALBUM_ID(L, i, j, k) (L).penyanyi[i].album_penyanyi[j].lagu_album[k].album_id

/* Struktur Data Album yang memiliki Lagu [Map] */
/*  Indeks album [0..album_length] merupakan key dari map Penyanyi -> Album 
    Nilai variabel album_nama merupakan value dari map Penyanyi -> Album */
typedef struct album {
    Word album_nama;
    Lagu lagu_album[MaxEl/5];
    int lagu_length;
    int penyanyi_id;
} Album;
/* ### Akses Elemen Album ### */
#define ALBUM_NAMA(A, i, j) (A).penyanyi[i].album_penyanyi[j].album_nama
#define ALBUM_LAGU_LENGTH(A, i, j) (A).penyanyi[i].album_penyanyi[j].lagu_length
#define ALBUM_PENYANYI_ID(A, i, j) (A).penyanyi[i].album_penyanyi[j].penyanyi_id

/* Struktur Data Penyanyi yang memiliki Album (yang memiliki Lagu) [List Statis] */
typedef struct penyanyi {
    Word penyanyi_nama;
    Album album_penyanyi[MaxEl/10];
    int album_length;
} Penyanyi;
/* ### Akses Elemen Penyanyi ### */
#define PENYANYI_NAMA(S, i) (S).penyanyi[i].penyanyi_nama
#define PENYANYI_ALBUM_LENGTH(S, i) (S).penyanyi[i].album_length

/* Struktur Data List Penyanyi (yang memiliki Album yang memiliki Lagu) [List Statis] */
typedef struct listpenyanyi {
    Penyanyi penyanyi[MaxEl/20];
    int penyanyi_length;
} ListPenyanyi;
/* ### Akses Elemen ListPenyanyi ### */
#define LIST_PENYANYI_ID(LS, i) (LS).penyanyi[i]
#define LIST_PENYANYI_LENGTH(LS) (LS).penyanyi_length

/* Struktur Data Playlist yang memiliki Lagu [List Berkait] */
/*  Setiap list sebagai pointer menuju masing-masing playlist memiliki:
    1) playlist_nama dan 2) list (pointer) */
typedef struct tPlaylist* Address;
typedef struct tPlaylist {
    Lagu lagu_playlist;
    Address next;
} LaguPlaylist;
typedef struct namaplaylist {
    Word playlist_nama;
    Address list;
} NamaPlaylist;

/* Struktur Data List Playlist yang memiliki Playlist (yang memiliki Lagu) [List Dinamis] */
/* playlistSize pertama kali diinisialisasi dengan nilai (MaxEl/20) */
typedef struct listplaylist {
    NamaPlaylist* playlist;
    size_t playlist_size;
    int playlist_length;
} ListPlaylist;
/* ### Struktur Data ListPlaylist ### */
#define LIST_PLAYLIST_ID(LP, i) (LP).(*playlist + i)
#define LIST_PLAYLIST_SIZE(LP) (LP).playlistSize
#define LIST_PLAYLIST_LENGTH(LP) (LP).penyanyi_length

/* Struktur Data Queue Lagu [Queue] */
typedef struct queue {
    Lagu lagu_queue[MaxEl];
    int idxHead;
    int idxTail;
} QueueLagu;
#define LAGU_QUEUE(Q, i) (Q).lagu_queue[i]
#define IDX_HEAD(Q) (Q).idxHead
#define     HEAD(Q) (Q).lagu_queue[(Q).idxHead]
#define IDX_TAIL(Q) (Q).idxTail
#define     TAIL(Q) (Q).lagu_queue[(Q).idxTail]

/* Struktur Data Histori Lagu [Stack] */
typedef struct stack {
    Lagu lagu_histori[MaxEl];
    int idxTop;
} HistoriLagu;
#define HISTORI_LAGU(H, i) (H).lagu_queue[i]
#define IDX_TOP(H) (H).idxTop

/* ### Variabel Global ### */
struct listpenyanyi LP;
struct lagu currSong;
struct queue Queue;
struct stack Histori;
struct listplaylist ListPL;
struct kata currPL;
boolean IsON;

/* ### Default State ### */

/* Lagu */
/*
Lagu deflagu;
deflagu.lagu_nama.TabWord[0] = STR_UNDEF;
deflagu.lagu_nama.Length = 0;
*/

/* Album */
/*
Album defalbum;
defalbum.album_nama.TabWord[0] = STR_UNDEF;
defalbum.album_nama.Length = 0;
defalbum.lagu_length = IDX_UNDEF;
defalbum.lagu_album[0] = deflagu;
*/

/* Penyanyi */
/*
Penyanyi defpenyanyi;
defpenyanyi.penyanyi_nama.TabWord[0] = STR_UNDEF;
defpenyanyi.penyanyi_nama.Length = 0;
defpenyanyi.album_length = 0;
defpenyanyi.album_penyanyi[0] = defalbum;
*/

#endif
