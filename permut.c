#include <math.h>
#include<stdio.h>
int main()
{
	int n = 8, match = 0, sum_A = 0, sum_B = 0;
	unsigned long long A[n], B[n];
	
	for(int i=0;i<n;i++)
	{
		//printf("A[%d] = ", i);
		scanf("%llu", (A+i));
		sum_A+=A[i];
	}
	//printf("\n");
	for(int i=0;i<n;i++)
	{
		//printf("B[%d] = ", i);
		scanf("%llu", (B+i));
		sum_B+=B[i];
	}
	//for(int i=0; i<n; i++)
	//{
	//	printf("\nA[%d] = %llu\t\tB[%d] = %llu ", i, A[i], i, B[i]);
	//}
	for(int i=0; i<n; i++)
	{
		for(int y=0; y<n; y++)
		{
			if(A[i]==B[y])
			{					
				match = 1;
				break;					
			}
		}
		if(match==0)
		{
			break;
		}
	}
	if((match==1)&&(sum_A==sum_B))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	
	return 0;
}
