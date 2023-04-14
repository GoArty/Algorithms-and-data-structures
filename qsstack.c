#include <stdio.h>
#include <malloc.h>

struct Task 
{
    int low;
    int high;
};

struct Stack 
{
    struct Task *data;
    int cap;
    int top;
};

void InitStack(struct Stack *stack, int n) 
{
    stack->data =(struct Task*)malloc(n * sizeof(struct Task));
    stack->cap = n;
    stack->top = 0;
}

int StackEmpty(struct Stack *stack)
{
    int empty = !stack->top;
    return empty;
}

void Push(struct Stack *stack, struct Task x) 
{
    if(stack->top == stack->cap) 
	printf("error: \"overflow\"");
    stack->data[stack->top] = x;
    stack->top++;
}

struct Task Pop(struct Stack *stack) 
{
    if(StackEmpty(stack)) 
	printf("error: \"devastation\"");
    stack->top--;
    struct Task x = stack->data[stack->top];
    return x;
}

int Partition(int *arr, int low, int high) 
{
    int index = low;
    for(int i = low; i < high; i++) 
        if(arr[high] > arr[i]) 
        {
            int sup_element = arr[index];
            arr[index] = arr[i];
            arr[i] = sup_element;
            index++;
        }  
    int sup_element = arr[index];
    arr[index]=arr[high];
    arr[high]=sup_element;
    return index;
}

void QuickSort(int *arr, int low, int high) 
{
    int left, right;
    struct Task task;
    task.low = low;
    task.high = high;
    struct Stack stack;
    InitStack(&stack, high + 1);
    Push(&stack, task);
    
    while(stack.top) 
    {
        task = Pop(&stack);
        if(task.high <= task.low) 
	    continue;
        int i = Partition(arr, task.low, task.high);
        struct Task push;
        if(i - task.low < task.high - i) 
	{
            push.high = task.high;
            push.low = i + 1;
            Push(&stack, push);
            push.low = task.low;
            push.high = i - 1;
            Push(&stack, push);
        }
        else
	{
            push.high = i - 1;
            push.low = task.low;
            Push(&stack, push);
            push.low = i + 1;
            push.high = task.high;
            Push(&stack, push);
        } 
    }
    free(stack.data);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) 
	scanf("%d", &arr[i]);		
    QuickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) 
	printf("%d ", arr[i]);	
    return 0;
}
