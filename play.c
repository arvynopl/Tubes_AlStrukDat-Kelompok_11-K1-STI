#include "function.h"

void PLAYSONG()
{
    if (IsON)
    {
        printf("Daftar Penyanyi :\n");
        for (int i = 0; i < LP.penyanyi_length; i++)
        {
            printf("%d. ", i + 1);
            PrintWord(LP.penyanyi[i].penyanyi_nama);
            printf("\n");
        }
        printf("\n");

        Word ans1;
        printf("Masukkan nama penyanyi yang dipilih: ");
        STARTINPUT();
        ans1 = GetWord();
        if (CheckPenyanyi(LP, ans1))
        {
            int idpenyanyi = IndexOfPenyanyiStr(LP, ans1);
            for (int i = 0; i < LP.penyanyi[idpenyanyi].album_length; i++)
            {
                printf("%d. ", i + 1);
                PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[i].album_nama);
                printf("\n");
            }
            printf("\n");

            Word ans2;
            printf("Masukkan judul album yang dipilih: ");
            STARTINPUT();
            ans2 = GetWord();
            if (CheckAlbum(LP.penyanyi[idpenyanyi], ans2))
            {
                int idalbum = IndexOfAlbumStr(LP, ans1, ans2);
                for (int i = 0; i < LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_length; i++)
                {
                    printf("%d. ", i + 1);
                    PrintWord(LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[i].lagu_nama);
                    printf("\n");
                }
                printf("\n");

                int idlagu;
                printf("Masukkan ID lagu yang dipilih: ");
                STARTINPUT();
                idlagu = WordToInt(GetWord());
                idlagu--;

                currSong = LP.penyanyi[idpenyanyi].album_penyanyi[idalbum].lagu_album[idlagu];

                CreateQueue(&Queue);
                CreateHistori(&Histori);
                currPL.Length = 0;
                currPL.TabWord[0] = STR_UNDEF;

                printf("Memutar lagu \"");
                PrintWord(currSong.lagu_nama);
                printf("\" oleh \"");
                PrintWord(LP.penyanyi[currSong.penyanyi_id].penyanyi_nama);
                printf("\".\n");
            }
            else
            {
                printf("Album tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        }
        else
        {
            printf("Penyanyi tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
    else
    {
        printf("Anda belum masuk ke dalam program...\n");
    }

    printf("\n");
    CONSOLE();
}

void PLAYPLAYLIST()
{
    if (IsON)
    {
        int ans;
        printf("Masukkan ID playlist: ");
        STARTINPUT();
        ans = WordToInt(GetWord());
        ans--;

        if (ans < 0 || ans >= ListPL.playlist_length)
        {
            printf("Tidak ada playlist dengan playlist ID %d. Silakan coba lagi.\n", ans + 1);
        }
        else
        {
            NamaPlaylist P = ListPL.playlist[ans];
            if (IsEmptyPlaylist(P))
            {
                printf("Belum ada lagu yang ditambahkan dalam playlist. Silahkan coba lagi.\n");
            }
            else
            {
                Address Q = P.list;
                currPL = P.playlist_nama;
                currSong = (*Q).lagu_playlist;

                if ((*Q).next != Nil)
                {
                    Q = (*Q).next;
                    Address R = Q;

                    CreateQueue(&Queue);

                    while (Q != Nil)
                    {
                        Lagu temp = (*Q).lagu_playlist;
                        Enqueue(&Queue, temp);
                        Q = (*Q).next;
                    }

                    CreateHistori(&Histori);

                    while (R != Nil)
                    {
                        Lagu temp = (*R).lagu_playlist;
                        Push(&Histori, temp);
                        R = (*R).next;
                    }
                }

                printf("Memutar playlist \"");
                PrintWord(P.playlist_nama);
                printf("\".\n");
            }
        }
    }
    else
    {
        printf("Anda belum masuk ke dalam program...\n");
    }

    printf("\n");
    CONSOLE();
}