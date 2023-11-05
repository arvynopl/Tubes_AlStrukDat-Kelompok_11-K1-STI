#ifndef structure_H
#define structure_H
#include "../src/boolean.h"
#include <stdlib.h>
#include <stdio.h>

typedef char Title;
typedef int Key;

#define MaxEl 100
#define IDX_UNDEF -1
#define INT_UNDEF -999
#define STR_UNDEF '0'
#define Nil 0

/* ##### STRUKTUR DATA ##### */
/* Struktur Data Lagu [Map (& Set)] */
/*  Indeks lagu [0..lagu_length] merupakan key dari map Album -> Lagu 
    Nilai variabel lagu_nama merupakan value dari map Album -> Lagu */
typedef struct {
    Title lagu_nama[MaxEl];
    int album_id;
} Lagu;
/* ### Akses Elemen Lagu ### */
#define LAGU_NAMA(L, i, j, k, l) (L).penyanyi[i].album_penyanyi[j].lagu_album[k].lagu_nama[l]
#define LAGU_ALBUM_ID(L, i, j, k) (L).penyanyi[i].album_penyanyi[j].lagu_album[k].album_id

/* Struktur Data Album yang memiliki Lagu [Map] */
/*  Indeks album [0..album_length] merupakan key dari map Penyanyi -> Album 
    Nilai variabel album_nama merupakan value dari map Penyanyi -> Album */
typedef struct {
    Title album_nama[MaxEl];
    Lagu lagu_album[MaxEl/5];
    int lagu_length;
    int penyanyi_id;
} Album;
/* ### Akses Elemen Album ### */
#define ALBUM_NAMA(A, i, j, k) (A).penyanyi[i].album_penyanyi[j].album_nama[k]
#define ALBUM_LAGU_LENGTH(A, i, j) (A).penyanyi[i].album_penyanyi[j].lagu_length
#define ALBUM_PENYANYI_ID(A, i, j) (A).penyanyi[i].album_penyanyi[j].penyanyi_id

/* Struktur Data Penyanyi yang memiliki Album (yang memiliki Lagu) [List Statis] */
typedef struct {
    Title penyanyi_nama[MaxEl];
    Album album_penyanyi[MaxEl/10];
    int album_length;
} Penyanyi;
/* ### Akses Elemen Penyanyi ### */
#define PENYANYI_NAMA(S, i, j) (S).penyanyi[i].penyanyi_nama[j]
#define PENYANYI_ALBUM_LENGTH(S, i) (S).penyanyi[i].album_length

/* Struktur Data List Penyanyi (yang memiliki Album yang memiliki Lagu) [List Statis] */
typedef struct {
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
typedef struct {
    Title playlist_nama[MaxEl];
    Address list;
} NamaPlaylist;

/* Struktur Data List Playlist yang memiliki Playlist (yang memiliki Lagu) [List Dinamis] */
/* playlistSize pertama kali diinisialisasi dengan nilai (MaxEl/20) */
typedef struct {
    NamaPlaylist* playlist;
    size_t playlistSize;
} ListPlaylist;
/* ### Struktur Data ListPlaylist ### */
#define LIST_PLAYLIST_ID(LP, i) (LP).(*playlist + i)
#define LIST_PLAYLIST_SIZE(LP) (LP).playlistSize

#endif
