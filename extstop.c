#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Delta_1(const char* str_1, int** count, int len_1)
{
    for (int i = 0; i < len_1; i++)
        for (int j = 0; j < 94; j++)
            count[i][j] = len_1 - i;
}

int extstop(const char* str_1, const char* str_2)
{
    int len_1 = strlen(str_1), len_2 = strlen(str_2), *count[len_1];
    for (int i = 0; i < len_1; i++)
        count[i] = (int*)malloc(94 * sizeof(int));
    Delta_1(str_1, count, len_1);
    for (int h = len_1 - 1, x = len_1 - 1; h < len_2; x = len_1 - 1) {
        while (str_1[x] == str_2[h]) {
            if (x == 0) {
                for (int i = 0; i < len_1; i++)
                    free(count[i]);
                return h;
            }
            x--, h--;
        }
        h += count[x][str_2[h] - 33];
    }
    for (int i = 0; i < len_1; i++)
        free(count[i]);
    return len_2;
}

int main(int argc, char** argv)
{
    const char *str_1 = argv[1], *str_2 = argv[2];
    printf("%d", extstop(str_1, str_2));
    return 0;
}
