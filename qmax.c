

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define true 1

#define ENQ           \
    long a;           \
    scanf("%ld", &a); \
    Enqueue(d_stack, a);

#define DEQ \
    printf("%ld\n", Dequeue(d_stack));

#define EMPTY \
    QueueEmpty(d_stack) ? printf("true\n") : printf("false\n");

#define MAX \
    printf("%ld\n", Max(d_stack));

#define END \
    break;

#define ERROR        \
    printf("ERROR"); \
    END

#define OVERFLOW                       \
{                                      \
        printf("error: \"overflow\""); \
        return;                        \
}

#define UNDERFLOW                       \
{                                       \
        printf("error: \"underflow\""); \
        return -1;                      \
}

#define var_1 \
    d_stack->data[d_stack->top1 - 1].max_value

#define var_2 \
    d_stack->data[d_stack->top2 + 1].max_value

typedef struct
    {
    long value;
    long max_value;
} Stack_data;

typedef struct
    {
    Stack_data* data;
    long cap;
    long top1;
    long top2;
} Double_stack;

void qmax(Double_stack* d_stack);

void InitDoubleStack(Double_stack* d_stack, long n)
{
    d_stack->data = (Stack_data*)malloc(n * sizeof(Stack_data));
    d_stack->cap = n;
    d_stack->top1 = 0;
    d_stack->top2 = n - 1;
}

long StackEmpty1(Double_stack* d_stack)
{
    long empty = !d_stack->top1;
    return empty;
}

long StackEmpty2(Double_stack* d_stack)
{
    long empty = (d_stack->top2 == d_stack->cap - 1);
    return empty;
}

void Push1(Double_stack* d_stack, long x)
{
    if (d_stack->top2 < d_stack->top1)
        OVERFLOW

    d_stack->data[d_stack->top1].value = x;
    d_stack->top1++;
}

void Push2(Double_stack* d_stack, Stack_data x)
{
    if (d_stack->top2 < d_stack->top1)
        OVERFLOW

    d_stack->data[d_stack->top2] = x;
    d_stack->top2--;
}

long Pop1(Double_stack* d_stack)
{
    if (StackEmpty1(d_stack))
        UNDERFLOW

    d_stack->top1--;
    Stack_data x = d_stack->data[d_stack->top1];
    return x.value;
}

long Pop2(Double_stack* d_stack)
{
    if (StackEmpty2(d_stack))
        UNDERFLOW

    d_stack->top2++;
    Stack_data x = d_stack->data[d_stack->top2];
    return x.value;
}

long QueueEmpty(Double_stack* d_stack)
{
    long empty = (StackEmpty1(d_stack) && StackEmpty2(d_stack));
    return empty;
}

void Enqueue(Double_stack* d_stack, long x)
{
    if (d_stack->top2 < d_stack->top1)
        OVERFLOW

    d_stack->data[d_stack->top1].max_value = StackEmpty1(d_stack) || x > var_1 ? x : var_1;
    Push1(d_stack, x);
}

long Dequeue(Double_stack* d_stack)
{
    if (StackEmpty2(d_stack))
        while (!(StackEmpty1(d_stack))) {
            Stack_data push;
            push.value = Pop1(d_stack);

            push.max_value = StackEmpty2(d_stack) || push.value > var_2 ? push.value : var_2;
            Push2(d_stack, push);
        }
    return Pop2(d_stack);
}

long Max(Double_stack* d_stack)
{
    return (StackEmpty1(d_stack)) ? var_2 : StackEmpty2(d_stack) || var_1 > var_2 ? var_1 : var_2;
}

int main()
{
    Double_stack d_stack;
    InitDoubleStack(&d_stack, 300500);

    qmax(&d_stack);

    free(d_stack.data);
    return 0;
}

void qmax(Double_stack* d_stack)
{
    char oper[1000];
    while (true) {
        scanf("%s", oper);
        if (strlen(oper) < 2 || strlen(oper) > 5) {
            ERROR
        }
        else if ('N' == oper[1] && 'Q' == oper[2]) {
            ENQ
        }
        else if ('E' == oper[1]) {
            DEQ
        }
        else if ('M' == oper[1]) {
            EMPTY
        }
        else if ('A' == oper[1]) {
            MAX
        }
        else if ('D' == oper[2]) {
            END
        }
    }
}

