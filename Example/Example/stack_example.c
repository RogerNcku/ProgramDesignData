#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

void runStackDemo(void) {
    Stack stack;
    initialize(&stack);

    push(&stack, 'n');
    printf("Pushed n onto the stack\n");

    push(&stack, 'c');
    printf("Pushed c onto the stack\n");

    push(&stack, 'k');
    printf("Pushed k onto the stack\n");

    push(&stack, 'u');
    printf("Pushed u onto the stack\n");

    while (!isEmpty(&stack)) {
        printf("Popped element: %c\n", pop(&stack));
    }
}