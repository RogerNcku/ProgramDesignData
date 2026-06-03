/*
  中文註解版程式：heap_sort_demo.c
  說明：主題 12：Heap Sort。先建立 Max Heap，再反覆把最大值移到陣列尾端完成排序。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>

// 交換兩個整數的值，用於排序或 Heap 調整。
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 印出陣列內容；Heap 範例保留 a[0] 不使用，從 index 1 開始。
void printArray(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Adjust 是 Heapify 的核心：把 root 節點向下移到正確位置。
void adjust(int a[], int root, int n) {
    int e = a[root];
    int child;

    for (child = 2 * root; child <= n; child *= 2) {
        if (child < n && a[child] < a[child + 1]) {
            child++;
        }
        if (e >= a[child]) {
            break;
        }
        a[child / 2] = a[child];
    }
    a[child / 2] = e;
}

// Heap Sort 主流程：先建 Max Heap，再反覆取出最大值。
void heapSort(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        adjust(a, i, n);
    }

    printf("After building max heap:\n");
    printArray(a, n);

    for (int i = n - 1; i >= 1; i--) {
        swap(&a[1], &a[i + 1]);  // 把目前最大值換到未排序區最後
        adjust(a, 1, i);  // 縮小 heap 範圍後重新調整 root
    }
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main() {
    int a[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = 10;

    printf("Original array:\n");
    printArray(a, n);

    heapSort(a, n);

    printf("Sorted array:\n");
    printArray(a, n);

    return 0;
}
