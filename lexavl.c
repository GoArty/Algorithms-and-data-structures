#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    int k;
    int value;
    int balance;
    struct Tree* parent;
    struct Tree* left;
    struct Tree* right;
} Tree;

int LookUp(Tree* tree, int k)
{
    while (tree != NULL && tree->k != k)
        if (k < tree->k)
            tree = tree->left;
        else
            tree = tree->right;
    if (tree == NULL || k != tree->k)
        return -1;
    else
        return tree->value;
}

Tree* InSert(Tree** tree, int k, int v)
{
    Tree* a = (Tree*)malloc(sizeof(Tree));
    Tree* b = *tree;
    a->k = k;
    a->value = v;
    a->parent = a->left = a->right = NULL;

    if (*tree == NULL)
        *tree = a;
    else
        while (1)
            if (k < b->k) {
                if (b->left == NULL) {
                    b->left = a;
                    a->parent = b;
                    break;
                }
                b = b->left;
            }
            else {
                if (b->right == NULL) {
                    b->right = a;
                    a->parent = b;
                    break;
                }
                b = b->right;
            }
    return *tree;
}

void Replace_node(Tree* tree, Tree* a, Tree* b)
{
    if (a != tree) {
        if (b != NULL)
            b->parent = a->parent;
        if (a->parent->left == a)
            a->parent->left = b;
        else
            a->parent->right = b;
    }
    else {
        tree = b;
        if (b != NULL)
            b->parent = NULL;
    }
}

void Rotate_right(Tree* tree, Tree* a)
{
    if (a->left != NULL) {
        Replace_node(tree, a, a->left);
        if (a->left->right != NULL)
            a->left->right->parent = a;

        a->left = a->left->right;
        a->parent = a->left;
        a->left->right = a;
        a->balance++;
        if (a->left->balance < 0)
            a->balance -= a->left->balance;
        a->left->balance++;
        if (a->balance > 0)
            a->left->balance += a->balance;
    }
}

void Rotate_left(Tree* tree, Tree* a)
{
    if (a->right != NULL) {
        Replace_node(tree, a, a->right);
        if (a->right->left != NULL)
            a->right->left->parent = a;

        a->right = a->right->left;
        a->parent = a->right;
        a->right->left = a;
        a->balance--;
        if (a->right->balance > 0)
            a->balance -= a->right->balance;
        a->right->balance--;
        if (a->balance < 0)
            a->right->balance += a->balance;
    }
}

Tree* InSert_AVL(Tree* tree, int k, int v)
{
    Tree* a = InSert(&tree, k, v);
    a->balance = 0;
    while (1) {
        if (a->parent == NULL)
            break;
        if (a == a->parent->left) {
            a->parent->balance--;
            if (a->parent->balance == 0)
                break;
            if (a->parent->balance == -2) {
                if (a->parent->balance == 1)
                    Rotate_left(tree, a);
                Rotate_right(tree, a->parent);
                break;
            }
        }
        else {
            a->parent->balance++;
            if (a->parent->balance == 0)
                break;
            if (a->parent->balance == 2) {
                if (a->balance == -1)
                    Rotate_right(tree, a);
                Rotate_left(tree, a->parent);
                break;
            }
        }
        a = a->parent;
    }
    return tree;
}

int Determine_SPEC(char a)
{
    char Specs[] = { '+', '-', '*', '/', '(', ')' };

    for (int i = 0; i < 6; i++)
        if (a == Specs[i])
            return i;
    return -1;
}

int Hash_FAQ6(const char* str)
{
    int hash = 0;
    while (*str) {
        hash += (char)(*str);
        hash += (hash << 10);
        hash ^= (hash >> 6);
        str++;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

void Delete_tree(Tree* tree)
{
    if (tree) {
        Delete_tree(tree->left);
        Delete_tree(tree->right);
        free(tree);
    }
}

char* my_gets(char* s)
{
    int i, k = getchar();
    if (k == EOF)
        return NULL;
    for (i = 0; k != EOF && k != '\n'; ++i) {
        s[i] = k;
        k = getchar();
        if (k == EOF)
            return NULL;
    }
    s[i] = '\0';

    return s;
}

void lexavl(Tree* tree, char* str, char* word, long length)
{
	int SPEC = -1;
    int count_IDENT = 0;
    int position = 0;
    int IDENT = -1;
    for (int i = 0; i < length; i++) {
        if (str[i] != ' ') {
            SPEC = Determine_SPEC(str[i]);
            if (SPEC != -1) {
                if (word[0] != '\0') {
                    if (57 < ((int)word[0]) || 48 > ((int)word[0])) {
                        IDENT = LookUp(tree, Hash_FAQ6(word));
                        if (IDENT != -1)
                            printf("IDENT %d\n", IDENT);
                        else {
                            printf("IDENT %d\n", count_IDENT);
                            tree = InSert_AVL(tree, Hash_FAQ6(word), count_IDENT);
                            count_IDENT++;
                        }
                    }
                    else
                        printf("CONST %d\n", atoi(word));
                    for (int i = 0; i < 20; i++)
                        word[i] = '\0';
                    position = 0;
                }
                printf("SPEC %d \n", SPEC);
            }
            else {
                word[position] = str[i];
                position++;
            }
            SPEC = -1;
        }

        else if (word[0] != '\0') {
            if (57 < ((int)word[0]) || 48 > ((int)word[0])) {
                IDENT = LookUp(tree, Hash_FAQ6(word));

                if (IDENT != -1)
                    printf("IDENT %d\n", IDENT);
                else {
                    printf("IDENT %d\n", count_IDENT);
                    tree = InSert_AVL(tree, Hash_FAQ6(word), count_IDENT);
                    count_IDENT++;
                }
            }
            else
                printf("CONST %d\n", atoi(word));
            for (int i = 0; i < 20; i++)
                word[i] = '\0';
            position = 0;
        }
    }
    if (word[0] != '\0')
        if (57 < ((int)word[0]) || 48 > ((int)word[0])) {
            int crypt = Hash_FAQ6(word);
            IDENT = LookUp(tree, crypt);

            if (IDENT != -1)
                printf("IDENT %d\n", IDENT);
            else {
                printf("IDENT %d\n", count_IDENT);
                tree = InSert_AVL(tree, crypt, count_IDENT);
                count_IDENT++;
            }
        }
        else
            printf("CONST %d\n", atoi(word));
}

char* Input()
{
	long length;
	scanf("%ld ", &length);
    length++;
    char* str = (char*)malloc (length * sizeof(char));
    scanf("%[^\n]s", str);
    return str;
}

int main()
{
    Tree* tree = NULL;
	char* str = Input();
    char* word = (char*)calloc(20, sizeof(char));
    lexavl(tree, str, word, strlen(str));
    
    free(str);
    free(word);
    Delete_tree(tree);
    return 0;
}
