

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_chars_a(const void *a, const void *b)
{
    char *sup_a=*(char**)a, *sup_b=*(char**)b;
    int a_numb_of_a = 0, b_numb_of_a = 0;
    for(; *sup_a; *sup_a++) 
	if( *sup_a == 'a' ) 
		a_numb_of_a++;
    for(; *sup_b; *sup_b++)  
	if( *sup_b == 'a') 
		b_numb_of_a++;
    if(a_numb_of_a == b_numb_of_a) 
	return 0;
    if(a_numb_of_a > b_numb_of_a)
	return 1;
    if(a_numb_of_a < b_numb_of_a)
	return -1;
}

void swap(void *base, int a, int b, size_t width)
{
    void *sup_el = malloc(width);
    memcpy (sup_el, ((char*)base + width*b), width);
    memcpy (((char*)base + width*b), ((char*)base + width*a), width);
    memcpy (((char*)base + width*a), sup_el, width);
    free(sup_el);
}

void heapify(void *base, size_t i, size_t nel, size_t width, int (*compare)(const void *a, const void *b))
{
    while(1)
    {
	int l_r = (i*2) + 1, largest = i;
        if((l_r < nel) && (compare((((char*)base) + width*i), (((char*)base) + width*l_r)) < 0))
		i = l_r;
	l_r++;
	if((l_r < nel) && (compare((((char*)base) + width*i), (((char*)base) + width*l_r)) < 0))
              	i = l_r;
	if(largest == i) 
	       	return;
	swap(base, i, largest, width);
    }
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b))
{
    for(int i = (nel / 2) - 1; i >= 0; i--)
	heapify(base, i, nel, width, compare);
    nel--;
    for(; nel > 0; -- nel) 
    {
        swap (base, 0, nel, width);
        heapify (base, 0, nel, width, compare);
    }
}

int main()
{
    int n;
    scanf("%d ", &n);
    
    if(n>0)
    {
    	char** arr_str=(char**)malloc(n*sizeof(char*));
        for(int i =0;i<n;i++)
	{
		arr_str[i]=(char*)malloc(sizeof(char)*1000);
		scanf("%s", arr_str[i]);
	}
    	if(n != 1) 
		hsort(arr_str, n, sizeof(char*), sum_chars_a);
        printf("\n");
    	for (int i = 0; i < n; i++) 
    	{
		printf("%s \n", arr_str[i]);
		free(arr_str[i]);
    	}
	free(arr_str);
   }
   return 0;
}

