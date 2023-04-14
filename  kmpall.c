#include <stdio.h>
#include <string.h>

char iter(int len_1, int k, const char* str_1, const char* str_2)
{
    if (k > len_1)
        return str_2[k - len_1 - 1];
    else
        return str_1[k];
}

void kmpall(int len_1, int len_2, const char* str_1, const char* str_2, int* count)
{
    for (int i = 1, j; i < len_1 + len_2 + 1; i++) {
        j = count[i - 1];
        while (j > 0 && i > -1 && !(j != len_1 && i != len_1 && iter(len_1, j, str_1, str_2) == iter(len_1, i, str_1, str_2)))
            j = count[j - 1];
        if(j != len_1 && i != len_1 && iter(len_1, j, str_1, str_2) == iter(len_1, i, str_1, str_2))
		j++;
        count[i] = j;
    }
}

int main(int argc, char** argv)
{
    const char *str_1 = argv[1], *str_2 = argv[2];
    const int len_1 = strlen(str_1), len_2 = strlen(str_2);
    int count[len_1 + len_2 + 1];

    for (int i = 0; i < len_1 + len_2 + 1; i++)
        count[i] = 0;

    kmpall(len_1, len_2, str_1, str_2, count);

    for (int i = len_1 + 1; i < len_1 + len_2 + 1; i++)
        if (count[i] == len_1)
            printf("%d ", i - len_1 * 2);
    return 0;
}
