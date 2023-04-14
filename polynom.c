#include <math.h>
#include<stdio.h>
int main()
{
	long long int n, x_0;
	scanf("%lld", &n);
	scanf("%lld", &x_0);
	long long int a[n+1];
	for(int i=n; i>-1; i--)
	{
		scanf("%lld", (a+i));
	}
	long long int P=a[n];
	for(int i=n-1; i>-1; i--)
	{
		P=a[i]+P*x_0;
		
	}
	long long int P_derivative=(n)*a[n];
	for(int i=n-1; i>0; i--)
	{
		if(((x_0!=0)||(i!=0)))
		{
			P_derivative=(i)*a[i]+P_derivative*x_0;
		}
		
	}

	printf("%lld %lld", P,P_derivative);
	return 0;	
}
