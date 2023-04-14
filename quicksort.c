#include <stdio.h>
#include <stdlib.h>

int partition(long *arr, int left, int right) 
{
    int i = left, j = left;
    long element;
    while(right > j) 
    {
    	if(arr[right] > arr[j]) 
    	{
    	     element= arr[i];
    	     arr[i]=arr[j];
    	     arr[j]=element;
    	     i++;
    	}
    	j++;
    }	
    element = arr[i];
    arr[i]=arr[right];
    arr[right]=element;
    return i;
}

void select_sort(long *arr, int left, int right) 
{
    for (int i = left; i <= right; i++)
    	for (int j = i; j <= right; j++)
      	    if (arr[j] < arr[i]) 
	    {
	  	long element = arr[i];
	  	arr[i] = arr[j];
	  	arr[j] = element;
	    }
}

void quick_sort(long *arr, int left, int right, long sequen_len) 
{
    while(left < right) 
    {
    	if(right-left < sequen_len - 1) 
    	{
    	     select_sort(arr, left, right);
      	     return;
    	}
    	int partit = partition(arr, left, right);
    	if (partit - left <= right - partit) 
	{
    	      quick_sort(arr, partit+1, right, sequen_len);
    	      right = partit - 1;
    	}
    	else
    	{
    	      quick_sort(arr, left, partit-1, sequen_len);
    	      left = partit + 1;
    	}    	
    }
}

int main() 
{
    int n;
    long sequen_len;
	
    scanf("%d %ld", &n, &sequen_len);

    long arr[n];
    for(int i = 0; i < n; i++) 
    scanf("%ld", arr+i);

    quick_sort(arr, 0, n-1, sequen_len);

    for (int i = 0; i < n; i++) 
    printf("%ld ", *(arr+i));

    return 0;
}
