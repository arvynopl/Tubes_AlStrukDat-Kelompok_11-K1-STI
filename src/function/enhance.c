#include "function.h"

void my_sleep(double seconds) {
    clock_t start_time = clock();
    double delay_clocks = seconds * CLOCKS_PER_SEC;

    while ((clock() - start_time) < delay_clocks)
        ;
}

unsigned int RAND(){
    unsigned int lcg_seed; 
    my_sleep(0.0000001);
    unsigned int LCG_A = (unsigned int) time(NULL);
    my_sleep(0.000001);
    unsigned int LCG_C = (unsigned int) time(NULL);
    my_sleep(0.00001);
    unsigned int LCG_M = (unsigned int) time(NULL);
    my_sleep(0.0001);
    lcg_seed = (unsigned int) time(NULL);
    lcg_seed = (LCG_A * lcg_seed + LCG_C) % LCG_M;
    return lcg_seed;
}