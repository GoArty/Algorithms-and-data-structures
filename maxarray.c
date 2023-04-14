#include<stdio.h>
int maxarray(void* base, size_t nel, size_t width, int (*compare)(void* a, void* b))
{
    size_t index = 0;
    for (size_t i = 0; i < nel; i++)
        if (compare((char*)base + width * i, (char*)base + width * index) > 0)
            index = i;
    return index;
}
