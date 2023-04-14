

#include <stdio.h>
#include <malloc.h>

struct Queue_element 
{
    int t1;
    int t2;
    int sum;
};

struct Queue 
{
    struct Queue_element *data;
    int cap;
    int count;
};

int Compare(struct Queue_element *a, struct Queue_element *b) 
{
    return a->sum - b->sum;
}

void Up(struct Queue *queue, int i) 
{
    while(i != 0 && Compare(&queue->data[i] , &queue->data[(i - 1) / 2]) < 0) 
    {
        struct Queue_element sup_elem = queue->data[i];
	queue->data[i] = queue->data[(i - 1) / 2];
	queue->data[(i - 1) / 2] = sup_elem;
        i = (i - 1) / 2;
    }
}

void Down(struct Queue *queue, int i) 
{
    while(i < queue->count / 2) 
    {
        int max_index = 2 * i + 1;
        if((2 * i + 2 < queue->count) && (Compare(&queue->data[2 * i + 2] , &queue->data[2 * i + 1]) < 0))
            max_index++;
        if(Compare(&queue->data[i] , &queue->data[max_index]) <= 0)
            return;
        struct Queue_element sup_elem = queue->data[i];
	queue->data[i] = queue->data[max_index];
	queue->data[max_index] = sup_elem;
        i = max_index;
    }
}

void InitPriorityQueue(struct Queue *queue, int n) 
{
    queue->data = (struct Queue_element*)malloc(sizeof(struct Queue_element) * n);
    queue->cap = n;
    queue->count = 0;
}

int QueueEmpty(struct Queue *queue)
{
    int empty = queue->count == 0;
    return empty;
}

void Insert(struct Queue *queue, struct Queue_element ptr) 
{
    int i = queue->count;
    if(i == queue->cap) 
	printf("error: \"overflow\"");
    queue->count++;
    queue->data[i] = ptr;
    Up(queue, i);
}

struct Queue_element ExtractMin(struct Queue *queue) 
{
    if(QueueEmpty(queue)) 
	printf("error: \"queue is empty\"");
    struct Queue_element result = queue->data[0];
    queue->count--;
    if(0 < queue->count)
    {
        struct Queue_element sup_elem = queue->data[queue->count];
	queue->data[queue->count] = queue->data[0];
	queue->data[0] = sup_elem;
        Down(queue, 0);
    }
    return result;
}

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    struct Queue queue;
    InitPriorityQueue(&queue, n);
    struct Queue_element *elems = malloc(m * sizeof(struct Queue_element));
    for(int i = 0; i < m; i++) 
    {
        scanf("%d %d", &elems[i].t1, &elems[i].t2);
        elems[i].sum = elems[i].t1 + elems[i].t2;
    }
    for(int i = 0; (i < n) && (i < m); i++) 
        Insert(&queue, elems[i]);
    struct Queue_element elem;
    int i = n, max;
    while(queue.count) 
    {
        elem = ExtractMin(&queue);
        if(m > i) 
	{
            if(elems[i].t1 > elem.sum)
                max = elems[i].t1;
            else max = elem.sum;
            	elems[i].sum = max + elems[i].t2;
            Insert(&queue, elems[i]);
            i++;
        }
    }
    printf("%d", elem.sum);
    free(queue.data);
    free(elems);
}

