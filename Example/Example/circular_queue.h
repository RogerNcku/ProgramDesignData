#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

#define MAX_SIZE 4

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q);
bool isQueueEmpty(Queue* q);
bool isQueueFull(Queue* q);
void insert(Queue* q, int value);
void delete(Queue* q);
void printQueue(Queue* q);
void runQueueDemo(void);

#endif