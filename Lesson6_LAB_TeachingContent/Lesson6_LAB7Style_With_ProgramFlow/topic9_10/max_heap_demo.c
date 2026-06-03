/*
  中文註解版程式：max_heap_demo.c
  說明：主題 10：Max Heap Push / Pop。示範插入 bubble up 與刪除 trickle down。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>

// 設定陣列容量上限，避免範例程式超出固定大小。
#define MAX_SIZE 100

// 定義節點結構：資料欄位存節點內容，指標欄位負責連到其他節點。
typedef struct {
    int data[MAX_SIZE];  // use index 1 as root, data[0] is unused
    int size;
} MaxHeap;

// 初始化 Heap：size 設為 0，表示目前沒有任何元素。
void initHeap(MaxHeap* h) {
    h->size = 0;
}

// Max Heap 插入：先放到最後，再和 parent 比較並往上移動。
void push(MaxHeap* h, int value) {
    int i = ++h->size;

    // bubble up: move parent down until value can be placed
    while (i != 1 && value > h->data[i / 2]) {
        h->data[i] = h->data[i / 2];
        i = i / 2;
    }
    h->data[i] = value;
}

// Max Heap 刪除：移除 root 最大值，再用最後元素向下調整。
int pop(MaxHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int maxValue = h->data[1];
    int last = h->data[h->size--];
    int parent = 1;
    int child = 2;

    // trickle down: compare with the larger child
    while (child <= h->size) {
        if (child < h->size && h->data[child] < h->data[child + 1]) {
            child++;
        }
        if (last >= h->data[child]) break;
        h->data[parent] = h->data[child];
        parent = child;
        child = child * 2;
    }
    h->data[parent] = last;
    return maxValue;
}

// 印出 Heap 陣列內容；本範例使用 index 1 作為 root。
void printHeap(MaxHeap* h) {
    for (int i = 1; i <= h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main(void) {
    MaxHeap heap;
    initHeap(&heap);

    int data[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        push(&heap, data[i]);
    }

    printf("Max heap array: ");
    printHeap(&heap);

    printf("Delete max: %d\n", pop(&heap));
    printf("After deletion: ");
    printHeap(&heap);

    push(&heap, 20);
    printf("After inserting 20: ");
    printHeap(&heap);

    return 0;
}
