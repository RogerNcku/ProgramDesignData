#include <stdio.h>

/* 印出陣列 */
static void printArray_quick(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Hoare partition + 印出過程 */
static int partition_quick(int num[], int p, int r, int size) {
    int x = num[p];
    int i = p - 1;
    int j = r + 1;
    int temp;

    printf("\n--- Partition (pivot = %d) ---\n", x);

    while (1) {
        do { j--; } while (num[j] > x);
        do { i++; } while (num[i] < x);

        printf("i=%d, j=%d\n", i, j);

        if (i < j) {
            printf("Swap %d and %d\n", num[i], num[j]);

            temp = num[i];
            num[i] = num[j];
            num[j] = temp;

            printArray_quick(num, size);
        }
        else {
            printf("Return partition index = %d\n", j);
            return j;
        }
    }
}

/* QuickSort + 印出範圍 */
void quickSort(int arr[], int p, int r, int size) {
    if (p < r) {
        int q;

        printf("\nQuickSort range [%d ~ %d]\n", p, r);

        q = partition_quick(arr, p, r, size);

        quickSort(arr, p, q, size);
        quickSort(arr, q + 1, r, size);
    }
}

/* demo runner */
void runQuickSortDemo(void) {
    int arr[] = { 5, 3, 2, 6, 4, 1, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array:\n");
    printArray_quick(arr, n);

    quickSort(arr, 0, n - 1, n);

    printf("\nFinal sorted array:\n");
    printArray_quick(arr, n);
}