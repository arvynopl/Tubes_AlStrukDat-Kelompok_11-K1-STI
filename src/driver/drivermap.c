#include "../ADT/map.h"

int main(){
    ListPenyanyi LP;

    /* Penyanyi 1 (penyanyi_id = 0) */
    LP.penyanyi[0].album_length = 2;
    LP.penyanyi[0].penyanyi_nama.TabWord[0] = 'J';
    LP.penyanyi[0].penyanyi_nama.TabWord[1] = 'i';
    LP.penyanyi[0].penyanyi_nama.TabWord[2] = 's';
    LP.penyanyi[0].penyanyi_nama.TabWord[3] = 'o';
    LP.penyanyi[0].penyanyi_nama.TabWord[4] = 'o';
    LP.penyanyi[0].penyanyi_nama.Length = 5;
    /* Album 1 (album_id = 0) dari Penyanyi 1 */
    LP.penyanyi[0].album_penyanyi[0].album_nama.TabWord[0] = 'A';
    LP.penyanyi[0].album_penyanyi[0].album_nama.TabWord[1] = 'P';
    LP.penyanyi[0].album_penyanyi[0].album_nama.TabWord[2] = 'A';
    LP.penyanyi[0].album_penyanyi[0].album_nama.Length = 3;
    LP.penyanyi[0].album_penyanyi[0].lagu_length = 2;
    LP.penyanyi[0].album_penyanyi[0].penyanyi_id = 0;
    /* Lagu 1 (lagu_id = 0) dari Album 1 Penyanyi 1 */
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].album_id = 0;
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama.TabWord[0] = 'A';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama.TabWord[1] = 'S';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama.TabWord[2] = 'I';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama.TabWord[3] = 'K';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[0].lagu_nama.Length = 4;    
    /* Lagu 2 (lagu_id = 1) dari Album 1 Penyanyi 1 */
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].album_id = 0;
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[0] = 'S';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[1] = 'A';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[2] = 'N';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[3] = 'G';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[4] = 'A';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[5] = 'T';
    LP.penyanyi[0].album_penyanyi[0].lagu_album[1].lagu_nama.Length = 6;
    /* Album 2 (album_id = 1) dari Penyanyi 1 */
    LP.penyanyi[0].album_penyanyi[1].album_nama.TabWord[0] = 'Y';
    LP.penyanyi[0].album_penyanyi[1].album_nama.TabWord[1] = 'A';
    LP.penyanyi[0].album_penyanyi[1].album_nama.Length = 2;
    LP.penyanyi[0].album_penyanyi[1].lagu_length = 3;
    LP.penyanyi[0].album_penyanyi[1].penyanyi_id = 0;
    /* Lagu 1 (lagu_id = 0) dari Album 2 Penyanyi 1 */
    LP.penyanyi[0].album_penyanyi[1].lagu_album[0].album_id = 1;
    LP.penyanyi[0].album_penyanyi[1].lagu_album[0].lagu_nama.TabWord[0] = 'G';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[0].lagu_nama.TabWord[1] = 'A';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[0].lagu_nama.TabWord[2] = 'M';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[0].lagu_nama.TabWord[3] = 'E';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[0].lagu_nama.Length = 4;
    /* Lagu 2 (lagu_id = 1) dari Album 2 Penyanyi 1 */
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].album_id = 1;
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].lagu_nama.TabWord[0] = 'M';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].lagu_nama.TabWord[1] = 'A';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].lagu_nama.TabWord[2] = 'N';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].lagu_nama.TabWord[3] = 'C';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].lagu_nama.TabWord[4] = 'I';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].lagu_nama.TabWord[5] = 'N';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].lagu_nama.TabWord[6] = 'G';
    LP.penyanyi[0].album_penyanyi[1].lagu_album[1].lagu_nama.Length = 7;
    /* Album 3 (album_id = 2) dari Penyanyi 1 */
    LP.penyanyi[0].album_penyanyi[2].lagu_length = Nil;
    
    /* Penyanyi 2 (penyanyi_id = 1) */
    LP.penyanyi[1].album_length = 1;
    LP.penyanyi[1].penyanyi_nama.TabWord[0] = 'S';
    LP.penyanyi[1].penyanyi_nama.TabWord[1] = 'e';
    LP.penyanyi[1].penyanyi_nama.TabWord[2] = 'p';
    LP.penyanyi[1].penyanyi_nama.TabWord[3] = 'u';
    LP.penyanyi[1].penyanyi_nama.TabWord[4] = 'h';
    LP.penyanyi[1].penyanyi_nama.Length = 5;
    /* Album 1 (album_id = 0) dari Penyanyi 2 */
    LP.penyanyi[1].album_penyanyi[0].album_nama.TabWord[0] = 'H';
    LP.penyanyi[1].album_penyanyi[0].album_nama.TabWord[1] = 'I';
    LP.penyanyi[1].album_penyanyi[0].album_nama.TabWord[2] = 'T';
    LP.penyanyi[1].album_penyanyi[0].album_nama.Length = 3;
    LP.penyanyi[1].album_penyanyi[0].lagu_length = 2;
    LP.penyanyi[1].album_penyanyi[0].penyanyi_id = 1;
    /* Lagu 1 (lagu_id = 0) dari Album 1 Penyanyi 2 */
    LP.penyanyi[1].album_penyanyi[0].lagu_album[0].album_id = 0;
    LP.penyanyi[1].album_penyanyi[0].lagu_album[0].lagu_nama.TabWord[0] = 'A';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[0].lagu_nama.TabWord[1] = 'N';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[0].lagu_nama.TabWord[2] = 'A';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[0].lagu_nama.TabWord[3] = 'K';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[0].lagu_nama.Length = 4;    
    /* Lagu 2 (lagu_id = 1) dari Album 1 Penyanyi 2 */
    LP.penyanyi[1].album_penyanyi[0].lagu_album[1].album_id = 0;
    LP.penyanyi[1].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[0] = 'C';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[1] = 'E';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[2] = 'R';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[3] = 'D';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[4] = 'A';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[1].lagu_nama.TabWord[5] = 'S';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[1].lagu_nama.Length = 6;
    /* Lagu 3 (lagu_id = 2) dari Album 1 Penyanyi 2 */
    LP.penyanyi[1].album_penyanyi[0].lagu_album[2].album_id = 0;
    LP.penyanyi[1].album_penyanyi[0].lagu_album[2].lagu_nama.TabWord[0] = 'S';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[2].lagu_nama.TabWord[1] = 'U';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[2].lagu_nama.TabWord[2] = 'K';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[2].lagu_nama.TabWord[3] = 'A';
    LP.penyanyi[1].album_penyanyi[0].lagu_album[2].lagu_nama.Length = 4;

    /* Penyanyi 3 (penyanyi_id = 2) */
    LP.penyanyi[2].album_length = Nil;
    
    LP.penyanyi_length = 3; /* Buat fungsi cek panjang penyanyi */

    printf("Print...\n");
    PrintListPenyanyi(LP);

    printf("\nIsEmpty...\n");
    printf("Kosong atau tidak Album 1 (album_id = 0) Penyanyi 1: %d\n", IsEmptyMapLagu(LP.penyanyi[0].album_penyanyi[0]));
    printf("Kosong atau tidak Album 3 (album_id = 2) Penyanyi 1: %d\n", IsEmptyMapLagu(LP.penyanyi[0].album_penyanyi[2]));
    printf("Kosong atau tidak Penyanyi 1 (penyanyi_id = 0): %d\n", IsEmptyMapAlbum(LP.penyanyi[0]));
    printf("Kosong atau tidak Penyanyi 3 (penyanyi_id = 2): %d\n", IsEmptyMapAlbum(LP.penyanyi[2]));

    printf("\nIsFull...\n");
    printf("Penuh atau tidak Album 1 (penyanyi_id = 0) Penyanyi 1: %d\n", IsFullMapLagu(LP.penyanyi[0].album_penyanyi[0]));
    printf("Penuh atau tidak Penyanyi 1 (penyanyi_id = 0): %d\n", IsFullMapAlbum(LP.penyanyi[0]));

    printf("\nLength...\n");
    printf("Panjang Album 1 (album_id = 0) Penyanyi 1: %d\n", LengthMapLagu(LP.penyanyi[0].album_penyanyi[0]));
    printf("Panjang Penyanyi 1 (penyanyi_id = 0): %d\n", LengthMapAlbum(LP.penyanyi[0]));
    printf("Panjang Album 1 (album_id = 0) Penyanyi 2: %d\n", LengthMapLagu(LP.penyanyi[1].album_penyanyi[0]));
    printf("Panjang Penyanyi 2 (penyanyi_id = 1): %d\n", LengthMapAlbum(LP.penyanyi[1]));    

    printf("\nIsMember...\n");
    printf("Ada atau tidak Lagu pertama (indeks 0) dalam Album 1: %d\n", IsMemberMapLagu(LP.penyanyi[0].album_penyanyi[0], 0));
    printf("Ada atau tidak Album pertama (indeks 0) dalam Penyanyi 1: %d\n", IsMemberMapAlbum(LP.penyanyi[0], 0));
    printf("Ada atau tidak Lagu pertama (indeks 0) dalam Album 3 Penyanyi 1: %d\n", IsMemberMapLagu(LP.penyanyi[0].album_penyanyi[2], 0));
    printf("Ada atau tidak Album pertama (indeks 0) dalam Penyanyi 3: %d\n", IsMemberMapAlbum(LP.penyanyi[2], 0)); 

    printf("\nIndexOf...\n");
    printf("Cek indeks Album 1 di Penyanyi 1: %d\n", IndexOfAlbum(LP.penyanyi[0], LP.penyanyi[0].album_penyanyi[0]));
    printf("Cek indeks Penyanyi 1 di ListPenyanyi: %d\n", IndexOfPenyanyi(LP, LP.penyanyi[0]));

    printf("\nIndexOf...\n");
    printf("Cek indeks Album 1 di Penyanyi 1: %d\n", IndexOfAlbum(LP.penyanyi[0], LP.penyanyi[0].album_penyanyi[0]));
    printf("Cek indeks Penyanyi 1 di ListPenyanyi: %d\n", IndexOfPenyanyi(LP, LP.penyanyi[0]));
}