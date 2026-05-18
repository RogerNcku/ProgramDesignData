#include <stdio.h>

int main(void)
{
    int i, j, *p, *q;

    i = 5;
    j = 6;
    p = &i;
    q = &j;

    *q = *p;
    *p = 1;

    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);

    return 0;
}
