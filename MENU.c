#include <stdio.h>
#include "MENU.h"

/*TEMPORARY FUNCTION*/
void START(){
    printf("START PROGRAM\n");
}

/*TEMPORARY FUNCTION 2*/
void LOAD(){
    printf("LOAD PROGRAM\n");
}

void MENU(){
    boolean isMasuk = false;
    printf("\n");
    printf("===== WELCOME TO WAYANGWAVE =====\n");
    printf("\n");
    printf("Music for Everyone. \n");
    printf("Developed by lets_git_it\n");
    printf("\n");
    printf("Anggota Kelompok : \n");
    printf("Daffari Adiyatma / 18222003\n");
    printf("Arvyno Pranata Limahardja / 18222007\n");
    printf("Nasywaa Anggun Athiefah / 18222021\n");
    printf("Anthony Bryant Gouw / 18222033\n");
    printf("Bastian Natanael Sibarani / 18222053\n");
    printf("\n");
    printf("==================================\n");
    printf("\n");
    printf("Please select a command to begin your journey : \n");
    printf(">START \n");
    printf(">LOAD \n");
    printf(">HELP \n");
    printf("\n");
    printf("Select : ");

    Word command;
    scanf("%s", command.TabWord);
    int count = 0;
    int i = 0;
    while (i != MaxEl && command.TabWord[i] != STR_UNDEF){
        if (command.TabWord[i] != STR_UNDEF){
            count += 1;
        }
        i += 1;
    }
    command.Length = count;

    Word start;
    start = ToKata("START");
    start.Length = StringLength("START");

    Word load;
    load = ToKata("LOAD");
    load.Length = StringLength("LOAD");

    Word help;
    help = ToKata("HELP");
    help.Length = StringLength("HELP");

    if(WordCompare(command,start)){
        if(INVALIDCOMMAND(isMasuk,command)){
            MENU();
        }
        else{
            START();
        }
    }
    else if(WordCompare(command,load)){
        if(INVALIDCOMMAND(isMasuk,command)){
            MENU();
        }
        else{
            LOAD();
        }
    }
    else if(WordCompare(command,help)){
        if(INVALIDCOMMAND(isMasuk,command)){
            MENU();
        }
        else{
            HELP(isMasuk);
        }
    }
}