#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value)
{
    int *arr;
    int i;

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        return NULL;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = initial_value;
    }

    return arr;
}

int main(void)
{
    int *arr;
    int n;
    int value;
    int i;

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter initial value: ");
    scanf("%d", &value);

    arr = create_array(n, value);

    if (arr == NULL)
    {
        printf("Array allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
