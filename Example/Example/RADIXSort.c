#include <stdio.h>
//#include "sort.h"

#define SIZE 10
#define RADIX 10

/* 印出陣列 */
static void printArray_radix(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i > 0) printf(" -> ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

/* 一次 pass：依 exp 位數做分配與收集 */
static void onePass(int arr[], int n, int exp, const char* title) {
    int buckets[RADIX][SIZE];
    int count[RADIX] = { 0 };
    int i, j, k, digit;

    printf("\n%s\n", title);

    /* 放入對應 bucket */
    for (i = 0; i < n; i++) {
        digit = (arr[i] / exp) % 10;
        buckets[digit][count[digit]] = arr[i];
        count[digit]++;
    }

    /* 印出每個 bucket */
    for (i = 0; i < RADIX; i++) {
        printf("digit[%d] -> ", i);
        for (j = 0; j < count[i]; j++) {
            if (j > 0) printf(" -> ");
            printf("%d", buckets[i][j]);
        }
        printf("\n");
    }

    /* 收集回原陣列 */
    k = 0;
    for (i = 0; i < RADIX; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    /* 印出這一輪排序後結果 */
    printf("\nCurrent array:\n");
    printArray_radix(arr, n);
}

/* Radix Sort */
void radixSort(int arr[], int n) {
    onePass(arr, n, 1, "Insert number using the last digit (個位)");
    onePass(arr, n, 10, "Insert number using the second digit (十位)");
    onePass(arr, n, 100, "Insert number using the first digit (百位)");
}

/* 給 main.c 呼叫的 demo */
void runRadixSortDemo(void) {
    int A[SIZE] = { 179, 208, 306, 93, 859, 984, 55, 9, 271, 33 };

    printf("Original:\n");
    printArray_radix(A, SIZE);

    radixSort(A, SIZE);

    printf("\nFinal sorted:\n");
    printArray_radix(A, SIZE);
}