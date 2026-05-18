#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100
#define BUCKET_COUNT 20
#define BUCKET_RANGE 5
#define MAX_BUCKET_SIZE 100

/* ---------- insertion sort for one bucket ---------- */
static void insertionSort_bucket(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

/* ---------- print one bucket ---------- */
static void printBucket(int bucket[], int size, int index) {
    int i;
    printf("B[%d]: ", index);
    if (size == 0) {
        printf("(empty)");
    }
    else {
        for (i = 0; i < size; i++) {
            printf("%d ", bucket[i]);
        }
    }
    printf("\n");
}

/* ---------- bucket sort ---------- */
void bucketSort(int arr[], int n) {
    int buckets[BUCKET_COUNT][MAX_BUCKET_SIZE];
    int bucketSizes[BUCKET_COUNT] = { 0 };
    int i, j, k;

    /* Step 1: put A[i] into B[A[i]/5] */
    for (i = 0; i < n; i++) {
        if (arr[i] < 0 || arr[i] >= MAX_VALUE) {
            printf("Error: value %d is out of range [0, 99]\n", arr[i]);
            return;
        }

        j = arr[i] / BUCKET_RANGE;   /* bucket index */
        buckets[j][bucketSizes[j]] = arr[i];
        bucketSizes[j]++;
    }

    /* Step 2: sort each bucket by insertion sort */
    for (i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 1) {
            insertionSort_bucket(buckets[i], bucketSizes[i]);
        }
    }

    /* Step 3: display all buckets */
    printf("Buckets after sorting:\n");
    for (i = 0; i < BUCKET_COUNT; i++) {
        printBucket(buckets[i], bucketSizes[i], i);
    }

    /* Step 4: merge buckets back to original array */
    k = 0;
    for (i = 0; i < BUCKET_COUNT; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

/* ---------- demo runner ---------- */
void runBucketSortDemo(void) {
    int A[] = { 34, 82, 5, 12, 55, 77, 98, 70, 76, 90,
               23, 65, 83, 15, 35, 53, 22, 9, 19, 81 };

    int n = sizeof(A) / sizeof(A[0]);
    int i;

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    bucketSort(A, n);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}