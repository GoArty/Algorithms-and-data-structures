#include <math.h>
#include<stdio.h>
int main()
{
	int n, k;
	//printf("Size n: ");
	scanf("%d", &n);
	long long elements[n];
	for(int i =0; i<n;i++)
	{
		//printf("elements[%d] = ", i);
		scanf("%lld", (elements+i));
	}
	//printf("k: ");
	scanf("%d", &k);
	long long max = -9223372036854775807, sum=0;
	for(int i=0;((i<n)&&(i+k-1<n));i++)
	{
		sum=0;
		for(int y=i;(y-i)<k;y++)
		{
			sum += elements[y];
		}
		if (max < sum)
		{
			max = sum;
		}
	}
	printf("%lld", max);
	return 0;
}
