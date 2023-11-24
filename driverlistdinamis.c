#include <stdio.h>
#include "../ADT/listdinamis.h"
#include "../structure.h"

int main()
{
    ListPlaylist test;
    CreateListPlaylist(&test);
    Address p = 123;

    NamaPlaylist isi1 = {{"myfav", 5}, p};
    NamaPlaylist isi2 = {{"wowww", 5}, p};
    NamaPlaylist isi3 = {{"wawww", 5}, p};

    PushPlaylist(&test, isi1);
    PushPlaylist(&test, isi2);
    PushPlaylist(&test, isi3);
    PrintListPlaylist(test);

    PopPlaylist(&test, &isi2);
    PrintListPlaylist(test);

    printf("Ini playlist yang dipilih : \n");
    GetPlaylist(test, 1);

    Address q = 321;
    NamaPlaylist pengganti = {{"wonder", 6}, q};

    SetPlaylist(&test, 1, pengganti);
    PrintListPlaylist(test);

    ResizeBiggerListPlaylist(&test);

    ResizeSmallerListPlaylist(&test);

    FreeListPlaylist(&test);

    FreePlaylist(&test, &isi3);
}
