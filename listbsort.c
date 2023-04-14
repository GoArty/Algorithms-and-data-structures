

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elem {
    struct Elem* next;
    char* word;
} list_elem_t;

list_elem_t* InitSingleLinkedList()
{
    list_elem_t* l = (list_elem_t*)calloc(1, sizeof(list_elem_t));
    l->next = NULL;
    return l;
}

int ListEmpty(list_elem_t* l)
{
    int empty = (l == NULL);
    return empty;
}

list_elem_t* ListSearch(list_elem_t* l, list_elem_t* y)
{
    list_elem_t* x = l;
    while (x->next)
        x = x->next;
    x->next = y;
    return l;
}

void InitList(list_elem_t* l, char* word)
{
    while (word = strtok(NULL, " ")) {
        list_elem_t* elem = InitSingleLinkedList();
        elem->word = word;
        ListSearch(l, elem);
    }
}

list_elem_t* Input(char* s)
{
    gets(s);
    char* word = strtok(s, " ");
    list_elem_t* l = InitSingleLinkedList();
    l->word = word;
    InitList(l, word);
    return l;
}

void Output(list_elem_t* l)
{
    while (l != NULL) {
        printf("%s\n", l->word);
        list_elem_t* elem = l;
        l = l->next;
        free(elem);
    }
}

void Swap(list_elem_t* sup_l)
{
    char* word = sup_l->word;
    sup_l->word = sup_l->next->word;
    sup_l->next->word = word;
}

list_elem_t* bsort(list_elem_t* list)
{
    if (!ListEmpty(list))
        for (long i = -1; i != 0;) {
            i = 0;
            for (list_elem_t* sup_l = list; sup_l->next != NULL; sup_l = sup_l->next)
                if (strlen(sup_l->next->word) < strlen(sup_l->word) && ++i)
                    Swap(sup_l);
        }
    return list;
}

void listbsort(list_elem_t* l)
{
    bsort(l);
    Output(l);
}

int main()
{
    char s[1000];
    list_elem_t* l = Input(s);
    listbsort(l);

    return 0;
}

