#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    int i;

    if (a[0] > a[1])
    {
        *largest = a[0];
        *second_largest = a[1];
    }
    else
    {
        *largest = a[1];
        *second_largest = a[0];
    }

    for (i = 2; i < n; i++)
    {
        if (a[i] > *largest)
        {
            *second_largest = *largest;
            *largest = a[i];
        }
        else if (a[i] > *second_largest)
        {
            *second_largest = a[i];
        }
    }
}

int main(void)
{
    int a[] = {10, 5, 30, 20, 40, 15};
    int largest, second_largest;
    int n = sizeof(a) / sizeof(a[0]);

    find_two_largest(a, n, &largest, &second_largest);

    printf("Largest = %d\n", largest);
    printf("Second largest = %d\n", second_largest);

    return 0;
}
