

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define true 1

struct queue {
    long* data;
    long count, head, tail, cap;
};

long Dequeue(struct queue* q);

void InitQueue(struct queue* q, long n)
{
    q->data = (long*)malloc(n * sizeof(long));
    q->cap = n;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}

int QueueEmpty(struct queue* q)
{
    long empty = !q->count;
    return empty;
}

void Enqueue(struct queue* q, long x)
{
    if (q->count == q->cap) {
        long* increase = malloc(2 * q->cap * sizeof(long));

        for (int i = 0; i < q->cap - q->head; i++)
            increase[i] = q->data[q->head + i];

        for (int i = 0; i < q->tail; i++)
            increase[i + q->cap - q->head] = q->data[i];

        free(q->data);
        q->data = increase, q->head = 0, q->tail = q->cap, q->cap *= 2;
    }
    q->data[q->tail] = x;
    q->tail++;
    if (q->tail == q->cap)
        q->tail = 0;
    q->count++;
}

long Dequeue(struct queue* q)
{
    if (QueueEmpty(q))
        printf("error: \"devastation\"");
    long x = q->data[q->head];
    q->head++;
    if (q->head == q->cap)
        q->head = 0;
    q->count--;
    return x;
}

void EMPTY(struct queue* q)
{
    if (QueueEmpty(q))
        printf("true\n");
    else
        printf("false\n");
}

void DEQ(struct queue* q)
{
    printf("%ld\n", Dequeue(q));
}

void ENQ(struct queue* q)
{
    long a;
    scanf("%ld\n", &a);
    Enqueue(q, a);
}

int main()
{
    struct queue q;
    long n;
    InitQueue(&q, 4);
    char oper[6] = "";
    while (true) {
        scanf("%s", oper);
        if (strlen(oper) < 3) {
            printf("ERROR");
            break;
        }
        else if ('D' == oper[0])
            DEQ(&q);
        else if ('Q' == oper[2])
            ENQ(&q);
        else if ('M' == oper[1])
            EMPTY(&q);
        else if ('D' == oper[2])
            break;
        else {
            printf("ERROR");
            break;
        }
    }

    free(q.data);
    return 0;
}

