#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    struct Elem *prev, *next;
    long v;
} list_elem_t;

void InsertAfter(list_elem_t* x, list_elem_t* y)
{
    list_elem_t* z = x->next;
    x->next = y;
    y->prev = x;
    y->next = z;
    z->prev = y;
}

list_elem_t* InitDoubleLinkedList(list_elem_t* l)
{
    l = (list_elem_t*)calloc(1, sizeof(list_elem_t));
    l->prev = l;
    l->next = l;
    return l;
}

long ListEmpty(list_elem_t* l)
{
    long empty = (l->next == l);
}

long ListLength(list_elem_t* l)
{
    long len = 0;
    list_elem_t* x = l;
    while (x->next != l) {
        len++;
        x = x->next;
    }
    return len;
}

void Delete(list_elem_t* x)
{
    list_elem_t *y, *z;
    y = x->prev;
    z = x->next;
    y->next = z;
    z->prev = y;
    x->prev = NULL;
    x->next = NULL;
}

list_elem_t* ListSearch(list_elem_t* l, int v)
{
    list_elem_t* x = l->next;
    while (x != l && x->v != v)
        x = x->next;
    return x;
}

void InsertSort(list_elem_t* double_list)
{
    list_elem_t* list_next = double_list->next;
    while (double_list != list_next) {
        list_elem_t* list_prev = list_next->prev;
        while ((double_list != list_prev) && (list_prev->v > list_next->v))
            list_prev = list_prev->prev;
        Delete(list_next);
        InsertAfter(list_prev, list_next);
        list_next = list_next->next;
    }
}

void Input(list_elem_t* double_list, list_elem_t* sup_list)
{
    scanf("%ld", &(sup_list->v));
    InsertAfter(double_list->prev, sup_list);
}

void Output(list_elem_t* double_list)
{
    printf("%ld ", double_list->next->v);
    double_list->next = double_list->next->next;
}

void listisort(list_elem_t* double_list, long n)
{
    list_elem_t* sup_list = (list_elem_t*)calloc(n, sizeof(list_elem_t));
    for (long i = 0; i < n; i++) 
        Input(double_list, sup_list + i);

    InsertSort(double_list);

    while (!ListEmpty(double_list))
        Output(double_list);
    free(sup_list);
}

int main()
{
    long n;
    scanf("%ld", &n);
    list_elem_t* double_list = InitDoubleLinkedList(double_list);

    listisort(double_list, n);

    free(double_list);
    return 0;
}
