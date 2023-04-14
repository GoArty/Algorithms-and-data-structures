#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define true 1

#define CONST        \
    int a;           \
    scanf("%d", &a); \
    Push(stack, a);

#define ADD \
    Push(stack, Pop(stack) + Pop(stack));

#define SUB \
    Push(stack, Pop(stack) - Pop(stack));

#define MUL \
    Push(stack, Pop(stack) * Pop(stack));

#define DIV \
    Push(stack, Pop(stack) / Pop(stack));

#define MAX                             \
    int a = Pop(stack), b = Pop(stack); \
    Push(stack, a > b ? a : b);

#define MIN                             \
    int a = Pop(stack), b = Pop(stack); \
    Push(stack, a < b ? a : b);

#define NEG \
    Push(stack, -Pop(stack));

#define DUP             \
    int b = Pop(stack); \
    Push(stack, b);     \
    Push(stack, b);

#define SWAP                            \
    int a = Pop(stack), b = Pop(stack); \
    Push(stack, a);                     \
    Push(stack, b);

#define END \
    break;

#define ERROR        \
    printf("ERROR"); \
    END

struct Stack {
    int* data;
    int cap;
    int top;
};

void StackMachine(struct Stack* stack);

void InitStack(struct Stack* stack, int n)
{
    stack->data = (int*)malloc(sizeof(int) * n);
    stack->cap = n;
    stack->top = 0;
}

int StackEmpty(struct Stack* stack)
{
    int empty = !stack->top;
    return empty;
}

void Push(struct Stack* stack, int x)
{
    if (stack->top == stack->cap)
        printf("error: \"overflow\"");
    stack->data[stack->top] = x;
    stack->top++;
}

int Pop(struct Stack* stack)
{
    if (StackEmpty(stack))
        printf("error: \"devastation\"");
    stack->top--;
    int x = stack->data[stack->top];
    return x;
}

void Output(struct Stack* stack)
{
    for (int i = 0; i < stack->top; i++)
        printf("%d\n", stack->data[i]);
}

int main()
{
    struct Stack stack;
    InitStack(&stack, 150000);

    StackMachine(&stack);

    Output(&stack);

    free(stack.data);
    return 0;
}

void StackMachine(struct Stack* stack)
{
    char oper[1000];
    while (true) {
        scanf("%s", oper);
        if (strlen(oper) < 2 || strlen(oper) > 5) {
            ERROR
        }
        else if ('C' == oper[0]) {
            CONST
        }
        else if ('A' == oper[0]) {
            ADD
        }
        else if ('B' == oper[2]) {
            SUB
        }
        else if ('L' == oper[2]) {
            MUL
        }
        else if ('V' == oper[2]) {
            DIV
        }
        else if ('X' == oper[2]) {
            MAX
        }
        else if ('N' == oper[2]) {
            MIN
        }
        else if ('G' == oper[2]) {
            NEG
        }
        else if ('P' == oper[2]) {
            DUP
        }
        else if ('A' == oper[2]) {
            SWAP
        }
        else if ('D' == oper[2]) {
            END
        }
    }
}
