/*
  中文註解版程式：max_heap_build_insert_delete.c
  說明：主題 11：建立、插入、刪除 Max Heap。從完整二元樹建立最大堆積樹，並維持 heap property。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>

// 設定陣列容量上限，避免範例程式超出固定大小。
#define MAX_SIZE 100

// 印出 Heap 陣列內容；本範例使用 index 1 作為 root。
void printHeap(int heap[], int size) {
    printf("Heap array: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// 交換兩個整數的值，用於排序或 Heap 調整。
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 向下調整 Heap：parent 若小於 child，就與較大的 child 交換。
void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int left = index * 2;
        int right = index * 2 + 1;
        int largest = index;

        if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest == index) break;

        swap(&heap[index], &heap[largest]);
        index = largest;
    }
}

// 建立 Max Heap：從最後一個非葉節點開始，往 root 方向逐一 heapify。
void buildMaxHeap(int heap[], int size) {
    for (int i = size / 2; i >= 1; i--) {
        heapifyDown(heap, size, i);
    }
}

// 插入 Max Heap：新資料先放最後，再 bubble up 維持最大堆積性質。
void insertMaxHeap(int heap[], int *size, int value) {
    (*size)++;
    int index = *size;
    heap[index] = value;

    while (index > 1 && heap[index / 2] < heap[index]) {
        swap(&heap[index / 2], &heap[index]);
        index = index / 2;
    }
}

// 刪除最大值：取出 root，把最後節點補到 root，再向下調整。
int deleteMax(int heap[], int *size) {
    if (*size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int maxValue = heap[1];
    heap[1] = heap[*size];  // 用最後一個節點補到 root 位置
    (*size)--;  // Heap 大小減少一個
    heapifyDown(heap, *size, 1);  // 從 root 開始向下修復 Max Heap
    return maxValue;
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main() {
    int heap[MAX_SIZE] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = 10;

    printf("Original complete binary tree:\n");
    printHeap(heap, size);

    buildMaxHeap(heap, size);
    printf("After building max heap:\n");
    printHeap(heap, size);

    insertMaxHeap(heap, &size, 20);
    printf("After inserting 20:\n");
    printHeap(heap, size);

    int deleted = deleteMax(heap, &size);
    printf("Deleted max value: %d\n", deleted);
    printf("After deleting max:\n");
    printHeap(heap, size);

    return 0;
}
