#ifndef LISTDINAMIS_H
#define LISTDINAMIS_H
#include "../structure.h"
#include "mesinkata.h"
#include "linkedlist.h"

void CreateListPlaylist(ListPlaylist* X);

void PushPlaylist(ListPlaylist* X, NamaPlaylist val);

void PopPlaylist(ListPlaylist* X, NamaPlaylist* val);

NamaPlaylist GetPlaylist(ListPlaylist X, size_t i);

void SetPlaylist(ListPlaylist* X, size_t i, NamaPlaylist val);

void ResizeBiggerListPlaylist(ListPlaylist* X);

void ResizeSmallerListPlaylist(ListPlaylist* X);

void FreePlaylist(ListPlaylist* X);

void PrintListPlaylist(ListPlaylist X);

#endif
