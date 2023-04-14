#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

enum operation 
{
  INSERT,
  LOOKUP,
  DELETE,
  RANK
};

struct elem 
{
  char* value;
  long k;
  struct elem** next;
  unsigned short* span;
};

struct elem * InitSkipList(int m) 
{
  struct elem* list = (struct elem*)calloc(1, sizeof(struct elem));
  list -> next = (struct elem**)malloc(m * sizeof(struct elem*));
  list -> span = (short*)calloc(m, sizeof(short));
  for(int i = 0; i < m; i++)
    list -> next[i] = NULL;
  return list;
}

struct elem** Skip(struct elem* list, int m, long k, struct elem** t) 
{
  for(int i = m-1; i >= 0; i--) 
  {
    while(list -> next[i] != NULL && list -> next[i] -> k < k)
      list = list -> next[i];
    t[i] = list;
  }
  return t;
}

void InSert(struct elem* list, int m, long k, struct elem* a, struct elem** t, short* rank_arr) 
{
  for(int i = m-1; i >= 0; i--) 
  {
    if(i == m - 1)
      rank_arr[i] = 0;
    else
      rank_arr[i] = rank_arr[i + 1];

    while(list -> next[i] != NULL && list -> next[i] -> k < k) 
    {
      rank_arr[i] += list -> span[i];
      list = list -> next[i];
    }
  }
  t = Skip(list, m, k, t);
  a -> next = (struct elem**) malloc(m * sizeof(struct elem*));
  a -> span = (short*) calloc(m, sizeof(short));
  int r = rand() << 1;
  int i;
  for(i = 0; i < m && !(r & 1); i++) 
  {
    a -> next[i] = t[i] -> next[i];
    t[i] -> next[i] = a;
    short sup_elem = rank_arr[0] - rank_arr[i];
    a -> span[i] = t[i] -> span[i] - sup_elem;
    t[i] -> span[i] = sup_elem + 1;
    r >>= 1;
  }
  for(; i < m; i++) 
  {
    ++t[i] -> span[i];
    a -> next[i] = NULL;
  }
}

char* LookUp(struct elem* list, int m, long k, struct elem** t) 
{
  t = Skip(list, m, k, t);
  struct elem* a = t[0]->next[0];
  return a->value;
}

void Delete(struct elem* list, int m, long k, struct elem** t) 
{
  t = Skip(list, m, k, t);
  struct elem* a = t[0] -> next[0];
  int i;
  for(i = 0; i < m && t[i] -> next[i] == a; i++) 
  {
    t[i] -> span[i] += a -> span[i] - 1;
    t[i] -> next[i] = a -> next[i];
  }
  for(; i < m;)
    --t[i] -> span[i++];
}

int Rank(struct elem* list, int m, long k) 
{
  long res = 0;
  for(int i = m-1; i >= 0; i--)
    while(list -> next[i] != NULL && list -> next[i] -> k < k) 
    {
      res += list -> span[i];
      list = list -> next[i];
    }
  return res;
}

int Determine_operation(char* oper) 
{
  const char operation[][7] = {"INSERT", "LOOKUP", "DELETE", "RANK"};
  for(int i = 0; i < 4; i++)
    if(strcmp(oper, operation[i]) == 0)
      return i;
  return -1;
}

int main() 
{
  srand(time(NULL));
  int m = 10000;
  long n = pow(m,2);
  struct elem* list = InitSkipList(m);
  struct elem* arr = (struct elem*) malloc(n * sizeof(struct elem));
  struct elem** t = (struct elem**) malloc(m * sizeof(struct elem*));
  short* rank_arr = (short*) malloc(m * sizeof(short));
  char oper[7]="";
  int j = 0;
  while(strcmp(oper, "END")) 
  {
    char v[10];
    long k;
    scanf("%s", oper);
    switch(Determine_operation(oper)) 
    {
    case INSERT:
      scanf("%ld %s", &k, v);
      arr[j].value = malloc((strlen(v) + 1) * sizeof(char));
      strcpy(arr[j].value, v);
      arr[j].k = k;
      InSert(list, m, k, &arr[j++], t, rank_arr);
      break;
    case LOOKUP:
      scanf("%ld", &k);
      printf("%s\n", LookUp(list, m, k, t));
      break;
    case DELETE:
      scanf("%ld", &k);
      Delete(list, m, k, t);
      break;
    case RANK:
      scanf("%ld", &k);
      printf("%d\n", Rank(list, m, k));
      break;
    }
  }
  for(int i = 0; i < j; i++) 
  {
    free(arr[i].value);
    free(arr[i].next);
    free(arr[i].span);
  }
  free(rank_arr);
  free(t);
  free(list -> next);
  free(list -> span);
  free(list);
  free(arr);
  return 0;
}
