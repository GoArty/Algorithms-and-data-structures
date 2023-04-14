#include <stdio.h>
#include <string.h>

void Suffix(const char* str_1, int* sup_arr)
{
    int len_1 = strlen(str_1), h = len_1 - 1;
    sup_arr[len_1 - 1] = h;
    for (int i = len_1 - 2; i >= 0; i--) 
    {
        while (h < len_1 - 1 && str_1[h] != str_1[i])
            h = sup_arr[h + 1];
        if (str_1[h] == str_1[i])
            h--;
        sup_arr[i] = h;
    }
}

void Delta_1(const char* str_1, int* arr_1)
{
    for (int i = 0; i < 256; i++)
        arr_1[i] = strlen(str_1);
    for (int i = 0; i < strlen(str_1); i++)
        arr_1[str_1[i]] = strlen(str_1) - i - 1;
}

void Delta_2(const char* str_1, int* arr_2)
{
    int len_1 = strlen(str_1);
    int sup_arr[len_1];
    Suffix(str_1, sup_arr);
    for (int i = 0, k = sup_arr[0]; i < len_1; i++) 
    {
        while (k < i)
            k = sup_arr[k + 1];
        arr_2[i] = len_1 + k - i;
    }
    for (int i = 0, k; i < len_1 - 1; i++) 
    {
        k = i;
        while (k < len_1 - 1) 
        {
            k = sup_arr[k + 1];
            if (str_1[i] != str_1[k])
                arr_2[k] = len_1 - i - 1;
        }
    }
}

void bmall(const char* str_1, const char* str_2, int* count)
{
    int arr_1[256], arr_2[strlen(str_1)];
    Delta_1(str_1, arr_1);
    Delta_2(str_1, arr_2);

    for (int len_1 = strlen(str_1), len_2 = strlen(str_2), h = len_1 - 1, x = len_1 - 1, j = 0; h < len_2; x = len_1 - 1) 
    {
        while (str_2[h] == str_1[x]) 
        {
            if (x == 0) 
            {
                count[j] = h, j++;
                break;
            }
            x--, h--;
        }
        if (arr_1[str_2[h]] > arr_2[x])
            h += arr_1[str_2[h]];
        else
            h += arr_2[x];
    }
}

int main(int argc, char** argv)
{
    const char *str_1 = argv[1], *str_2 = argv[2];
    int len_2 = strlen(str_2);
    int count[len_2];
    for (int i = 0; i < len_2; i++)
        count[i] = -1;

    bmall(str_1, str_2, count);

    for (int i = 0; count[i] != -1 && i < len_2; i++)
        printf("%d ", count[i]);
    return 0;
}
