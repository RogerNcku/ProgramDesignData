#include <stdio.h>
#include "circular_queue.h"

/* 初始化 */
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

/* 判空 */
bool isQueueEmpty(Queue* q) {
    return (q->front == q->rear);
}

/* 判滿 */
bool isQueueFull(Queue* q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

/* 插入 */
void insert(Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full not to insert %d\n", value);
        return;
    }

    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;

    printf("Insert %d\n", value);
    printf("insert: q->front= %d,q->rear= %d,value=%d\n", q->front, q->rear, value);
}

/* 刪除 */
void delete(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty not to delete.");
        printf("(front=%d rear=%d)\n", q->front, q->rear);
        return;
    }

    int value = q->items[(q->front + 1) % MAX_SIZE];
    q->front = (q->front + 1) % MAX_SIZE;

    printf("Delete %d\n", value);
    printf("del:q->front= %d,q->rear= %d,value=%d\n", q->front, q->rear, q->items[q->front]);
}

/* 印出 queue */
void printQueue(Queue* q) {
    int i;

    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");

    if (q->front < q->rear) {
        for (i = q->front + 1; i <= q->rear; i++)
            printf("%d ", q->items[i]);
    }
    else {
        for (i = q->front + 1; i <= q->rear + MAX_SIZE; i++)
            printf("%d ", q->items[i % MAX_SIZE]);
    }

    printf("\n");
    printf("(front=%d rear=%d)\n", q->front, q->rear);
}

void runQueueDemo(void) {
    Queue q;

    initializeQueue(&q);

    insert(&q, 10);
    insert(&q, 20);
    insert(&q, 30);
    insert(&q, 40);

    printQueue(&q);

    delete(&q);
    delete(&q);
    delete(&q);
    delete(&q);

    insert(&q, 50);
    insert(&q, 60);
    insert(&q, 70);
    insert(&q, 80);

    printQueue(&q);
}