#include <stdio.h>

int main(void)
{
    int a[5] = {5, 4, 3, 2, 1};
    int *p = a;
    int *q = &a[4];

    printf("*(p + 2) = %d\n", *(p + 2));
    printf("*(q - 3) = %d\n", *(q - 3));
    printf("q - p = %ld\n", q - p);
    printf("p < q is %s\n", (p < q) ? "true" : "false");
    printf("*p < *q is %s\n", (*p < *q) ? "true" : "false");

    return 0;
}
