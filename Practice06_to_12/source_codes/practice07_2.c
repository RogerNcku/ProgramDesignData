#include <stdio.h>

int *find_largest(int a[], int n)
{
    int i;
    int *largest = &a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > *largest)
        {
            largest = &a[i];
        }
    }

    return largest;
}

int main(void)
{
    int a[] = {10, 80, 30, 50, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int *p;

    p = find_largest(a, n);

    printf("Largest value = %d\n", *p);

    return 0;
}
