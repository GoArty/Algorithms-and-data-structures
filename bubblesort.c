

void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)) 
{
  int max = nel - 1, min = 0, max_sup = nel - 1, i, min_sup = 0;
  char flag = 1;
  while (min_sup < max_sup) 
  {
    if (flag == 1) 
    {
      max_sup = max;
      max = min_sup;
      i = min_sup;
      while (i < max_sup) 
      {
        if (compare(i + 1, i) == -1) 
        {
          swap(i, i + 1);
          max = i;
        }
      i++;
      }
      flag = 0;
    } else 
    {
      min_sup = min;
      min = max_sup;
      i = max_sup;
      while (i > min_sup)
      {
        if (compare(i - 1, i) == 1) 
        {
          swap(i - 1, i);
          min = i;
        }
        i--;
      }
      flag = 1;
    }
  }
}

