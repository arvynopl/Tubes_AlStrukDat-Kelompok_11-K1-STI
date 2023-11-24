#include "function.h"

#define LCG_A 1664525
#define LCG_C 1013904223
#define LCG_M 4294967296 

void my_sleep(double seconds) {
    clock_t start_time = clock();
    double delay_clocks = seconds * CLOCKS_PER_SEC;

    while ((clock() - start_time) < delay_clocks)
        ;
}

unsigned int RAND(){
    unsigned int lcg_seed; 
    my_sleep(0.001);
    lcg_seed = (unsigned int) time(NULL);
    lcg_seed = (LCG_A * lcg_seed + LCG_C) % LCG_M;
    return lcg_seed;
}  