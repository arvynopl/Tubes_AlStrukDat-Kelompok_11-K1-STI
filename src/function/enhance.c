#include "function.h"

#define LCG_A 1664525
#define LCG_C 1013904223
#define LCG_M 4294967296 

unsigned int RAND(){
    unsigned int lcg_seed; 
    usleep(100000);
    lcg_seed = (unsigned int) time(NULL);
    lcg_seed = (LCG_A * lcg_seed + LCG_C) % LCG_M;
    return lcg_seed;
}  