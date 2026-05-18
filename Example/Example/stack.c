#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top >= MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

char peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}