#include <math.h>
#include<stdio.h>
int main()
{
	unsigned long long a, b, b_arr[64], m;
	scanf("%llu", &a);
	scanf("%llu", &b);
	scanf("%llu", &m);
	unsigned long long sup_b = b;
	
	for(int i = 0; i < 64; i++)
	{
		b_arr[i]= sup_b%2;
		sup_b/=2;
	}
	
	unsigned long long a_multiply_b_mod_m = ((a%m) * (b_arr[63]%m))% m;
	for(int i=62; i>0; i--)
	{
		a_multiply_b_mod_m = (((a_multiply_b_mod_m *(2%m))%m) + (((a%m) * (b_arr[i]%m))% m))%m;
	}
	a_multiply_b_mod_m = (((a_multiply_b_mod_m*(2%m))%m) + ((a % m)*(b_arr[0] % m)) % m) % m;
	printf("%llu", a_multiply_b_mod_m);
	
	return 0;
}
