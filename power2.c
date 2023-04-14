#include <stdio.h>
int pow(int a, int b)
{
	int pow=1;
	for(int i=0;i<b;i++)
		pow*=a;
	return pow;
}

int Check_sum(int i, int n, int *a)
{
    long long sum = 0;
    for (int j= 0; j < n; j++)
        if(i & (1 << j))
            sum+=a[j];
    return (sum && (!(sum & (sum-1))));
}

int Combinations(int n, int pow, int *a)
{
    int number_of_exists_combin = 0;
    for (int i = 0; i < pow; i++) 
		number_of_exists_combin += Check_sum(i, n, a);
    return number_of_exists_combin;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", (a+i));
	printf("%d",Combinations(n, pow(2,n), a));
    return 0;
}
