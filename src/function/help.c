#include "function.h"

void HELP(){
    printf("=====[ Menu Help WayangWave ]=====\n");
    if(IsON){
        printf("1. LIST DEFAULT -> Untuk melihat list penyanyi yang ada\n");
        printf("2. LIST PLAYLIST -> Untuk menampilkan playlist yang ada pada pengguna\n");
        printf("3. PLAY SONG -> Untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu\n");
        printf("4. PLAY PLAYLIST -> Untuk memainkan lagu berdasarkan id playlist\n");
        printf("5. QUEUE SONG -> Untuk menambahkan lagu ke dalam queue\n");
        printf("6. QUEUE PLAYLIST -> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue\n");
        printf("7. QUEUE SWAP -> Untuk menukar lagu pada urutan ke x dan juga urutan ke y\n");
        printf("8. QUEUE REMOVE -> Untuk menghapus lagu dari queue\n");
        printf("9. QUEUE CLEAR -> Untuk mengosongkan queue\n");
        printf("10. SONG NEXT -> Untuk memutar lagu yang berada di dalam queue\n");
        printf("11. SONG PREVIOUS -> Untuk memutar lagu yang terakhir kali diputar\n");
        printf("12. PLAYLIST CREATE -> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna\n");
        printf("13. PLAYLIST ADD SONG -> Untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna\n");
        printf("14. PLAYLIST ADD ALBUM -> Untuk menambahkan lagu-lagu dalam album pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna\n");
        printf("15. PLAYLIST SWAP -> Untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id\n");
        printf("16. PLAYLIST REMOVE -> Untuk menghapus lagu dengan urutan n pada playlist dengan index id\n");
        printf("17. PLAYLIST DELETE -> Untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna\n");
        printf("18. PLAYLIST ENHANCE -> Untuk menambahkan lagu-lagu rekomendasi WayangWave pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna\n");
        printf("19. STATUS -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar\n");
        printf("20. SAVE -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file\n");
        printf("21. QUIT -> Untuk keluar dari sesi\n");
        printf("==================================\n");
    }

    else{
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("==================================\n");
    }

    CONSOLE();
}