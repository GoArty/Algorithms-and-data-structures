#include <stdio.h>

int main()
{
    int A = 0, B = 0;
    int SIZE_A, SIZE_B;
    signed char elem;
    scanf("%d", &SIZE_A);
    for (int i = 0; SIZE_A > i; i++) {
        scanf("%hhd", &elem);
        if (-1 < elem && elem < 32)
            A |= (1 << elem);
        else {
            printf("Error");
            return 1;
        }
    }
    scanf("%d", &SIZE_B);
    for (int i = 0; SIZE_B > i; i++) {
        scanf("%hhd", &elem);
        if (-1 < elem && elem < 32)
            B |= (1 << elem);
        else {
            printf("Error");
            return 1;
        }
    }
    printf("\n");
    int C = A & B;
    for (int i = 0; i < 32; i++)
        if ((C >> i) & 1)
            printf("%hhd ", i);
    return 0;
}

