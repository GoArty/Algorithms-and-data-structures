#include <stdio.h>
#include <math.h>
int main()
{
    long n;
    scanf("%ld", &n);
    if (n < 0)
        n = -n;
    long SIZE = floor(sqrt(n) + 1);

    char bool_A[SIZE];
    for (long i = 0; i < SIZE; i++)
        bool_A[i] = 1;
    bool_A[0] = bool_A[1] = 0;

    for (long i = 2; i < SIZE; i++)
        if (bool_A[i])
            for (long j = i * i; j < SIZE; j += i)
                bool_A[j] = 0;

    for (long i = 2; i < SIZE; i++)
        if (bool_A[i] != 0)
            while (((n % i) == 0) && ((n / i) > 1))
                n /= i;

    printf("%ld", n);
    return 0;
}

