#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t n)
{
    void *p;

    p = malloc(n);

    if (p == NULL)
    {
        printf("Error: malloc failed.\n");
        exit(1);
    }

    return p;
}

int main(void)
{
    int *arr;
    int i;

    arr = (int *)my_malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    for (i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
