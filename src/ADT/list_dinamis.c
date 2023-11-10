#include "listdinamis.h"
#include <stdio.h>
#include <stdlib.h>

DynamicList *createDynamicList(size_t initialCapacity)
{
    DynamicList *arr = (DynamicList *)malloc(sizeof(DynamicList));
    arr->data = (int *)malloc(sizeof(int) * initialCapacity);
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

void pushDynamicList(DynamicList *arr, int value)
{
    if (arr->size == arr->capacity)
    {
        resizeDynamicList(arr, arr->capacity * 2); // Double the capacity
    }
    arr->data[arr->size++] = value;
}

int getDynamicList(DynamicList *arr, size_t index)
{
    if (index >= arr->size)
    {
        printf("Index out of range.\n");
        exit(1);
    }
    return arr->data[index];
}

void setDynamicList(DynamicList *arr, size_t index, int value)
{
    if (index >= arr->size)
    {
        printf("Index out of range.\n");
        exit(1);
    }
    arr->data[index] = value;
}

void resizeDynamicList(DynamicList *arr, size_t newCapacity)
{
    int *newData = (int *)malloc(sizeof(int) * newCapacity);
    for (size_t i = 0; i < arr->size; i++)
    {
        newData[i] = arr->data[i];
    }
    free(arr->data);
    arr->data = newData;
    arr->capacity = newCapacity;
}

void freeDynamicList(DynamicList *arr)
{
    free(arr->data);
    free(arr);
}
