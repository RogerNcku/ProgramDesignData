#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void push(Stack *stack, char value);
char pop(Stack *stack);
char peek(Stack *stack);

#endif