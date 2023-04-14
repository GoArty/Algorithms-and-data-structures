#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    int *int_a = (int *)a, *int_b = (int *)b;
    if (abs(*int_a) - abs(*int_b) > 0)
        return 1;
    else if (abs(*int_a) - abs(*int_b) < 0)
        return -1;
    return 0;
}

void insertion_sort(void* arr, int right, int left, int width)
{
    char* element = malloc(width);
    for (int i = left, index; i < right + 1; i++) {
        memcpy(element, (char*)arr + i * width, width);
        index = i - 1;
        while (index >= 0 && (compare((char*)arr + index * width, element) > 0)) {
            memcpy((char*)arr + (index + 1) * width, (char*)arr + index * width, width);
            index--;
        }
        memcpy((char*)arr + (index + 1) * width, element, width);
    }
    free(element);
}

void merge(void* base, int left, int medium, int right, int width)
{
    char* sup_arr = malloc((right - left + 1) * width);
    long i = left, j = medium + 1, k = 0;
    while (k < right - left + 1) {
        if (j <= right && (i == medium + 1 || compare((char*)base + j * width, (char*)base + i * width) < 0)) {
            memcpy(sup_arr + k * width, (char*)base + j * width, width);
            j++;
        }
        else {
            memcpy(sup_arr + k * width, (char*)base + i * width, width);
            i++;
        }
        k++;
    }
    memcpy((char*)base + left * width, sup_arr, width * (right - left + 1));
    free(sup_arr);
}

void merge_sort(void* arr, size_t right, size_t left, size_t width)
{
    if (right - left < 4) {
        insertion_sort(arr, right, left, width);
        return;
    }

    int medium = (right + left) / 2;
    merge_sort(arr, medium, left, width);
    merge_sort(arr, right, medium + 1, width);
    merge(arr, left, medium, right, width);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    merge_sort(arr, n - 1, 0, sizeof(int));
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
