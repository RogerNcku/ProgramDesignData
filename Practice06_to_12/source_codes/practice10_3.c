#include <stdio.h>

double inner_product(const double *a, const double *b, int n)
{
    int i;
    double sum = 0.0;

    for (i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }

    return sum;
}

int main(void)
{
    double a[] = {1.0, 2.0, 3.0};
    double b[] = {4.0, 5.0, 6.0};
    double result;

    result = inner_product(a, b, 3);

    printf("Inner product = %.2f\n", result);

    return 0;
}
