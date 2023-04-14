#include <stdio.h>
#include <string.h>

void prefix(int n, const char* str, int* count)
{
    count[0] = 0;
    for (int i = 1, k = 0; i < n; count[i] = k, i++) 
    {
        while (k > 0 && str[k] != str[i])
            k = count[k - 1];
        if (str[k] == str[i])
            k++;
    }
}

int main(int argc, char** argv)
{
    char* str = argv[1];
    int n = strlen(str);
    int count[n];
    prefix(n, str, count);
    for (int i = 0, l, d = i + 1 - count[i]; i < n; i++, d = i + 1 - count[i])
        if (count[i] != 0 && (i + 1) % d == 0)
            printf("%d %d\n", i + 1, (i + 1) / d);
    return 0;
}
