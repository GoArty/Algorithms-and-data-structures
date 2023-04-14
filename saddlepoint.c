#include <stdio.h>
#include <malloc.h>

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	long long massiv[n][m];
	for(long long i=0;i<n;i++)
		for(long long j=0;j<m;j++)
			scanf("%lld", &(massiv[i][j]));
	long long min[m];
	for(int j=0;j<m;j++)
		min[j]=10000000;
	long long max[n];
	for(int i=0;i<n;i++)
		max[i]=-10000000;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(min[j] > massiv[i][j])
			{
				min[j]=massiv[i][j];
			}
			if(max[i] < massiv[i][j])
			{
				max[i]=massiv[i][j];
			}
		}

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		if(min[j]==max[i])
		{
			printf("%d %d", i, j);
			return 0;
		}
		
	printf("none");
 	return 0;
}
