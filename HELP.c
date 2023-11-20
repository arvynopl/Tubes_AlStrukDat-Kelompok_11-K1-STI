#include <stdio.h>
#include "HELP.h"

void HELP(boolean isMasuk){
    printf("\n");
    printf("=====[ Menu Help WayangWave ]=====\n");
    if(isMasuk){
        printf("1. LIST DEFAULT -> untuk melihat list penyanyi yang ada\n");
        printf("2. LIST PLAYLIST -> untuk menampilkan playlist yang ada pada pengguna\n");
        printf("3. PLAY SONG -> untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu\n");
        printf("4. PLAY PLAYLIST -> untuk memainkan lagu berdasarkan id playlist\n");
        printf("5. QUEUE SONG -> untuk menambahkan lagu ke dalam queue\n");
        printf("6. QUEUE PLAYLIST -> untuk menambahkan lagu yang ada dalam playlist ke dalam queue\n");
        printf("7. QUEUE SWAP -> untuk menukar lagu pada urutan ke x dan juga urutan ke y\n");
        printf("8. QUEUE REMOVE -> untuk menghapus lagu dari queue\n");
        printf("9. QUEUE CLEAR -> untuk mengosongkan queue\n");
        printf("10. SONG NEXT -> untuk memutar lagu yang berada di dalam queue\n");
        printf("11. SONG PREVIOUS -> untuk memutar lagu yang terakhir kali diputar\n");
        printf("12. PLAYLIST CREATE -> untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna\n");
        printf("13. PLAYLIST ADD -> untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna\n");
        printf("14. PLAYLIST SWAP -> untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id\n");
        printf("15. PLAYLIST REMOVE -> untuk menghapus lagu dengan urutan n pada playlist dengan index id\n");
        printf("16. PLAYLIST DELETE -> untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna\n");
        printf("17. STATUS -> untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar\n");
        printf("18. SAVE -> untuk menyimpan state aplikasi terbaru ke dalam suatu file\n");
        printf("19. QUIT -> Untuk keluar dari sesi\n");
        printf("==================================\n");
    }
    else{
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("==================================\n");
    }
    printf("\n");
}