#include <stdio.h> 
#include <malloc.h>
#include <math.h>

unsigned long long *arr_index;
unsigned long long *lookup_table;
unsigned long long SIZE;

unsigned long long fibonachi(unsigned long long x, int number_index);

int main()
{
	unsigned long long x, sum_fibonachis = 0, fibonachi_end, sup_x;
	scanf("%llu", &x);
	if(x==0)
	{
		printf("%lld", x);
		return 0;
	}
	SIZE = x;
	arr_index=(long*) malloc(SIZE *sizeof(unsigned long long));
	lookup_table=(long*) malloc(SIZE*sizeof(unsigned long long));
	for(int i = 0; i < SIZE;i++)
	{
		arr_index[i]=-1;
		lookup_table[i]=-1;
	} 
	 lookup_table[0]=1;

	int i = 0;
	//printf("%llu\n", x);
	sup_x=x;
	while (x>sum_fibonachis)
	{
		fibonachi_end = fibonachi(sup_x, i);
		sum_fibonachis+= fibonachi_end;
		sup_x = sup_x - fibonachi_end;
		//printf("\n%llu %d ", arr_fibonachi[i], arr_index[i]);
		//printf("%llu\n", sup_x);
		i++;
	}
	
	i=0;
	for(int y = arr_index[0]; y>= 1;y--)
	{
		if(y == arr_index[i])
		{
			printf("1");
			i++;
		}
		else
		{
			printf("0");
		}
	}
 	free(arr_index);
 	free(lookup_table);
	return 0;
}

unsigned long long fibonachi(unsigned long long x, int number_index)
{	
	for(long long i=1; SIZE>i;i++)
	{
		if(lookup_table[i]==-1)
		{
			break;
		}
		else if(lookup_table[i]>x)
		{
			arr_index[number_index]=i+1;
			return lookup_table[i-1];
		}
		else if(lookup_table[i]==x)
		{
			arr_index[number_index]=i+2;
			return lookup_table[i];
		}
	}
	unsigned long long sum = 0;
	int perv = 1, vtoroe= 1, index = 0;
	
	//printf("%d ", perv);
	while(x>=sum)
	{
		sum = perv + vtoroe;
		//printf("%llu ", sum);
		
		perv=vtoroe;	
		vtoroe=sum;
		lookup_table[index]=sum;
		index++;
	}
		
	arr_index[number_index]=index;
	if(x==sum)
	{
		return sum;
	}
	else
	{
		return perv;
	}
}
