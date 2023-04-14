#include<stdio.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

unsigned char KeysGet(union Int32 array, int key) 
{
    if(key == 3) 
	return (unsigned char)((int)array.bytes[3] - 128);	
    return (unsigned char)array.bytes[key]; 	
}

void RadixSort(union Int32* array, int n)
{
    for(int key = 0; key < 4; key++)
    {
	int keys[256];
    	union Int32 sup_array[n];
    	for(int i = 0; i < 256; i++) 
	    keys[i] = 0;
    	for(int j = 0; j < n; j++)
    	    keys[KeysGet(array[j], key)]++;
    	for(int i = 0; i < 255; i++)
    	    keys[i + 1] += keys[i];
    	for (int j = n-1; j > -1; j--)
	{
    	    int i = keys[KeysGet(array[j], key)];
    	    keys[KeysGet(array[j], key)] = i - 1;
    	    sup_array[i - 1] = array[j];
    	}
    	for (int i = 0; i < n; i++)
    	    array[i] = sup_array[i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n>0)
    {
    	union Int32 array[n];
    	for(int i = 0; i < n; i++)
    	    scanf("%d", &(array+i)->x);
	RadixSort(array, n);
    	for(int i = 0; i < n; i++)
    	    printf("%d ", (array+i)->x);
    }
    return 0;
}
