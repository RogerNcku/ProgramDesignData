#include <stdio.h>

#define row 3
#define column 5

int main(void)
{
    int a[row][column] =
    {
        {1, 2, 3, 4, 5},
        {1, 4, 9, 16, 25},
        {1, 8, 27, 64, 125}
    };

    int (*p)[column];
    int i, j;

    p = a;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }

    return 0;
}
