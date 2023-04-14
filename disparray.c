#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum operation 
{
    AT,
    ASSIGN
};
typedef struct NodalPoint nodal_point;

struct NodalPoint 
{
    int Key;
    int Value;
    nodal_point* Parent;
    nodal_point* Left;
    nodal_point* Right;
};

typedef struct Tree 
{
    nodal_point* Base;
} tree;

typedef struct HashTable 
{
    tree* TreeTable;
    int SIZE;
} hash_table;

void TreeClearNodePoint(nodal_point* nodal_point)
{
    if (nodal_point->Left)
        TreeClearNodePoint(nodal_point->Left);
    if (nodal_point->Right)
        TreeClearNodePoint(nodal_point->Right);
    free(nodal_point);
}

void TreeInsertNode(tree* tree, int key, int value)
{
    nodal_point* NewNodePoint = (nodal_point*)malloc(128);
    NewNodePoint->Key = key;
    NewNodePoint->Value = value;
    NewNodePoint->Parent = NULL;
    NewNodePoint->Left = NULL;
    NewNodePoint->Right = NULL;

    if (!tree->Base) 
    {
        tree->Base = NewNodePoint;
        return;
    }
    nodal_point* NodePoint = tree->Base;
    while (1)
        if (key < NodePoint->Key) 
        {
            if (!NodePoint->Left) 
            {
                NodePoint->Left = NewNodePoint;
                NewNodePoint->Parent = NodePoint;
                return;
            }
            NodePoint = NodePoint->Left;
        }
        else 
        {
            if (!NodePoint->Right) 
            {
                NodePoint->Right = NewNodePoint;
                NewNodePoint->Parent = NodePoint;
                return;
            }
            NodePoint = NodePoint->Right;
        }
}

int F_AT(hash_table* table, int key)
{
    int hash = key % table->SIZE;
    nodal_point* nodal_point = (&table->TreeTable[hash])->Base;
    while (nodal_point && nodal_point->Key != key)
        if (key < nodal_point->Key)
            nodal_point = nodal_point->Left;
        else
            nodal_point = nodal_point->Right;
    if (!nodal_point)
        return 0;
    return nodal_point->Value;
}

void F_ASSIGN(hash_table* table, int key, int value)
{
    int hash = key % table->SIZE;
    tree* tree = &table->TreeTable[hash];
    nodal_point* nodal_point = tree->Base;

    while ((nodal_point) && (nodal_point->Key != key))
        if (key < nodal_point->Key)
            nodal_point = nodal_point->Left;
        else
            nodal_point = nodal_point->Right;
    if (nodal_point)
        nodal_point->Value = value;
    else
        TreeInsertNode(tree, key, value);
}

int Determine_operation(char* oper)
{
    const char operation[][7] = {"AT","ASSIGN"};
    for (int i = 0; i < 2; i++)
        if (strcmp(oper, operation[i]) == 0)
            return i;
    return -1;
}

int main()
{
    int m;
    scanf("%d", &m);
    hash_table table;
    table.SIZE = m;
    table.TreeTable = malloc(m * sizeof(tree));
    for (int i = 0; i < table.SIZE; i++)
        (&table.TreeTable[i])->Base = NULL;
    char oper[7] = "";
    while (strcmp(oper, "END")) 
    {
        scanf("%s", oper);
        int key, value;
        switch (Determine_operation(oper)) 
	{
            case AT:
                scanf("%d", &key);
                printf("\n%d\n\n", F_AT(&table, key));
                break;
            case ASSIGN:
                scanf("%d %d", &key, &value);
                F_ASSIGN(&table, key, value);
                break;
        }
    }
    for (int i = 0; i < table.SIZE; i++)
        if (table.TreeTable[i].Base)
            TreeClearNodePoint(table.TreeTable[i].Base);
    free(table.TreeTable);
    return 0;
}
