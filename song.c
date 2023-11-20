#include "function.h"

void songNext()
{
    if (IsEmptyQueue(Queue))
    { // jika queue kosong maka memutar kembali lagu yang sama
        printf("Queeu kosong, memutar kembali  lagu");
        printf(currSong.lagu_nama); // ini harusnya nge print nama lagu yang sedang diputar (di currsong)
        printf("oleh");
        printf(currSong.penyanyi_nama(penyanyi_id)); // ini harusnya nge print nama penyanyi yang lagunya sedang di putar
    }
    else
    {
        Push(&Histori, currSong);   // memasukkan lagu yang sedang ada di currSong ke histori
        currSong = Dequeue(&Queue); // menjadikan lagu teratas pada queue menjadi lagu yang sekarang diputar

        printf("Memutar lagu selanjutnya ");
        printf(currSong.lagu_nama); // harusnya nge print nama lagu yang telah di next yang mana ada di currSong sekarang
        printf(" oleh");
        printf(currSong.penyanyi_nama); // harusnya nge print nama penyanyi yang sekarang ada di currSong
    }
}

void songPrevious()
{
    if (IsEmptyHistori(Histori))
    { // jika Histori kosong maka memutar kembali lagu yang sama
        printf("Riwayat lagu kosong, memutar kembali  lagu");
        printf(currSong.lagu_nama); // ini harusnya nge print nama lagu yang sedang diputar (di currsong)
        printf("oleh");
        printf(currSong.penyanyi_nama(penyanyi_id)); // ini harusnya nge print nama penyanyi yang lagunya sedang di putar
    }
    else
    {
        //     pop(&Histori, currSong); //memasukkan lagu yang sedang ada di currSong ke histori
        //     currSong = Dequeue(&Queue); //menjadikan lagu teratas pada queue menjadi lagu yang sekarang diputar

        //     printf("Memutar lagu selanjutnya ");
        //     printf(currSong.lagu_nama); // harusnya nge print nama lagu yang telah di next yang mana ada di currSong sekarang
        //     printf(" oleh");
        //     printf(currSong.penyanyi_nama); // harusnya nge print nama penyanyi yang sekarang ada di currSong
    }
}

void playSong()
{
    // Menampilkan daftar penyanyi yang ada
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < LP.penyanyi_length; i++)
    {
        printf("%d. ", i + 1);
        PrintWord(LP.penyanyi[i].penyanyi_nama);
        printf("\n");
    }

    // Inputan untuk nama penyanyi yang akan dipilih
    printf("Masukkan Nama Penyanyi yang dipilih: ");
    STARTINPUT();
    Word namaPenyanyi;
    namaPenyanyi = GetWord();
    int idpenyanyi = IndexOfPenyanyiStr(LP, namaPenyanyi);

    // Menampilkan daftar album dari penyanyi
    printf("Daftar Album oleh");
    PrintWord(namaPenyanyi);
    printf(":\n");
    for (int i = 0; i < LP.penyanyi[idpenyanyi].album_length; i++)
    {
        printf("%d. ", i + 1);
        PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[i].album_nama);
        printf("\n");
    }

    // Inputan untuk nama album yang akan dipilih
    Word namaAlbum;
    printf("Masukkan Nama Album yang dipilih : ");
    STARTINPUT();
    namaAlbum = GetWord();
    int idalbum = IndexOfAlbumStr(LP, namaPenyanyi, namaAlbum);
    for (int i = 0; i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length; i++)
    {
        printf("%d. ", i + 1);
        PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i].lagu_nama);
        printf("\n");
    }

    // Menampilkan daftar lagu yang terdapat pada album yang dipilih
    printf("Daftar Lagu Album");
    PrintWord(namaAlbum);
    printf("oleh");
    PrintWord(namaPenyanyi);
    for (int i = 0; i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length; i++)
    {
        printf("%d. ", i + 1);
        PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i].lagu_nama);
        printf("\n");
    }

    // Inputan untuk ID lagu yang dipilih
    Word namaLagu;
    printf("Masukkan ID Lagu yang dipilih: ");
    STARTINPUT();
    namaLagu = GetWord();
    int idlagu = IndexOfAlbumStr(LP, namaAlbum, namaLagu);

    // Lagu yang play menjadi current song saat ini
    currSong.lagu_nama = namaLagu;
    currSong.album_id = idalbum;
    currSong.penyanyi_id = idlagu;

    // Jika Queue tidak kosong maka akan men dequeue Queue
    QueueLagu antrianLagu;
    CreateQueue(*antrianLagu); // ini masih salah di gw error

    // Mengosongkan riwayat lagu
    while (!IsEmptyHistori)
    {
        Pop(*Histori, &); // ini ga tau song mana yang di pop...
    }

    printf("Memutara lagu \"");
    PrintWord(namaLagu);
    printf("\" oleh \"");
    printf(namaPenyanyi);
}

void playPlaylist()
{
    // Lagu L = (Histori).lagu_queue[IDX_TOP];

    printf("Masukkan ID Playlist: ");
    STARTINPUT();
    int id_playlist = WordToInt(GetWord());
    while (!IsEmptyQueue)
    {
        Dequeue(&Queue);
    }

    while (!IsEmptyHistori)
    {
        Lagu temp;
        Pop(&Histori, &temp);
    }

    Address P = ListPL.playlist[id_playlist].list;
    while (P != Nil)
    {
        Enqueue(&Queue, (*P).lagu_playlist);
        P = (*P).next;
    }

    P = ListPL.playlist[id_playlist].list;
    while (P != Nil)
    {
        Push(&Histori, (*P).lagu_playlist);
    }

    printf("Memutar \"");
    printf(ListPL.playlist[id_playlist]); // ini seharusnya nge print nama playlistnya
    printf("\"");
}
