#ifndef FUNCTION_H
#define FUNCTION_H

#include "../structure.h"
#include "../ADT/adt.h"

/* ### FUNGSI UTAMA (COMMAND) ### */
/* Command START */
void STARTPROG(FILE* input);

/* Command LOAD */
void LOADPROG(FILE* input);

/* Command SAVE */
void SAVEPROG();

/* Command LIST */
void LISTDEFAULT();
void LISTPLAYLIST();

/* ### FUNGSI TAMBAHAN ### */
/* Fungsi cek isi struktur data */
void DisplayAll();

#endif