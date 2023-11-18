#include "function/function.h"

int main(){
    FILE* input = fopen("D:/Tugas Besar/src/driver/filekonfigurasi_b.txt", "r");
    LOADPROG(input);
    PrintListPenyanyi(LP);
    return 0;
}