#include <stdio.h>
#include <stdlib.h>

int *func(int a[], int size)
{
    int *r;
    int i;

    r = (int *)malloc(size * sizeof(int));

    if (r == NULL)
    {
        return NULL;
    }

    for (i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            a[i] = -a[i];
        }

        r[i] = a[i] * a[i];
    }

    return r;
}

int main(void)
{
    int a[] = {-1, 2, -3, 4, -5};
    int size = sizeof(a) / sizeof(a[0]);
    int *r;
    int i;

    r = func(a, size);

    if (r == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Absolute array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nSquare array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", r[i]);
    }

    printf("\n");

    free(r);

    return 0;
}
