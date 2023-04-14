

//Во сколько мне к вам сегодня можно будет подойти?
#include <stdio.h>
#include <malloc.h>

#define true 1

#define ERROR                     \
{                                 \
    printf("The queue is empty"); \
}

#define MAX \
    a > b ? 1 : 0;

#define FREEMAMORY               \
    for (long i = 0; i < n; i++) \
        free(arr_sequen[i]);     \
    free(arr_sequen);            \
    free(q->heap);		 \
    free(q);
#define COMPARE \
    long (*compare)(long a, long b)

#define OVERFLOW                   \
{                                  \
    printf("error: \"overflow\""); \
    return;                        \
}

#define HEAP \
    q->heap

typedef struct{
    long value;
    long nel;
    long index;
} element_queue_t;

typedef struct{
    element_queue_t* heap;
    long cap;
    long count;
} queue_t;

long Max(long a, long b)
{
    return MAX
}

void heapify(queue_t* q, COMPARE)
{
    long i = 0, nel = q->count;
    while (true) {
        long l_r = 2 * i + 1, largest = i;
        i = l_r < nel && compare(HEAP[i].value, HEAP[l_r].value) ? l_r : i;
        l_r++;
        i = l_r < nel && compare(HEAP[i].value, HEAP[l_r].value) ? l_r : i;
        if (largest == i)
            return;
        element_queue_t sup_elem = HEAP[i];
        HEAP[i] = HEAP[largest];
        HEAP[largest] = sup_elem;
    }
}

void InitPriorityQueue(queue_t* q, long n)
{
    q->heap = (element_queue_t*)malloc(n * sizeof(element_queue_t));
    q->cap = n, q->count = 0;
}

void InSert(queue_t* q, element_queue_t ptr, COMPARE)
{
    long i = q->count;
    if (i == q->cap)
        OVERFLOW

    q->count++, HEAP[i] = ptr;
    while (i > 0 && compare(HEAP[(i - 1) / 2].value, HEAP[i].value)) {
        element_queue_t sup_elem = HEAP[(i - 1) / 2];
        HEAP[(i - 1) / 2] = HEAP[i];
        HEAP[i] = sup_elem, i = (i - 1) / 2;
    }
}

void FreeMemory(queue_t* q, long* arr_sequen[], long n)
{
    FREEMAMORY
}

element_queue_t ExtractMax(queue_t* q, COMPARE)
{
    if (q->count == 0)
        ERROR

    element_queue_t ptr = HEAP[0];
    --q->count;
    if (q->count > 0) {
        HEAP[0] = HEAP[q->count];
        heapify(q, compare);
    }
    return ptr;
}

void Input(long** arr_sequen, long* a, long* size, long n)
{
    for (long i = 0; i < n; i++) {
        scanf("%ld", size + i);
        arr_sequen[i] = (long*)malloc((size[i] + 1) * sizeof(long)), a[i] = 0;
    }

    for (long i = 0; i < n; i++)
        for (long j = 0; j < size[i]; j++)
            scanf("%ld", (arr_sequen[i] + j));
}

void CreatingInitPriorityQueue(queue_t* q, long** arr_sequen, long* sup_arr, long* size, long n, COMPARE)
{
    for (long i = 0; i < n; i++)
        if (!(size[i] == 0)) {
            element_queue_t sup_element_queue;
            sup_element_queue.value = arr_sequen[i][0];
            sup_element_queue.index = i;
            InSert(q, sup_element_queue, compare), sup_arr[i]++;
        }
}

void Merge(queue_t* q, long** arr_sequen, long* sup_arr, long* size, long n, COMPARE)
{
    Input(arr_sequen, sup_arr, size, n);

    CreatingInitPriorityQueue(q, arr_sequen, sup_arr, size, n, compare);

    while (q->count > 0) {
        element_queue_t ptr = ExtractMax(q, Max);
        printf("%ld ", ptr.value);
        if (sup_arr[ptr.index] == size[ptr.index])
            continue;
        else {
            element_queue_t sup_element_queue;
            sup_element_queue.value = arr_sequen[ptr.index][sup_arr[ptr.index]];
            sup_element_queue.index = ptr.index;
            InSert(q, sup_element_queue, compare), sup_arr[ptr.index]++;
        }
    }
}

int main()
{
    long n;
    scanf("%ld", &n);
    long **arr_sequen = (long **)malloc(n * sizeof(long *)), size[n], sup_arr[n];
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    InitPriorityQueue(q, n);

    Merge(q, arr_sequen, sup_arr, size, n, Max);

    FreeMemory(q, arr_sequen, n);
    return 0;
}

