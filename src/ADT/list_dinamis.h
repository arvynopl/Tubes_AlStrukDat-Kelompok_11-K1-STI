#ifndef ADTListDinamis
#define ADTListDinamis

// Kamus Umum
#define Mark -9999
#define constant \
    INITIAL_CAP: \
    integer = 100

#define Eltype int
#define IdxType int
#define size_t int

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
} DynamicList;

DynamicList *createDynamicList(size_t initialCapacity);

void pushDynamicList(DynamicList *arr, int value);

int getDynamicList(DynamicList *arr, size_t index);

void setDynamicList(DynamicList *arr, size_t index, int value);

void resizeDynamicList(DynamicList *arr, size_t newCapacity);

void freeDynamicList(DynamicList *arr);

#endif
