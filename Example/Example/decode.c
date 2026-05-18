#include <stdio.h>
#include <string.h>
#include "stack.h"

void runDecodeDemo(void) {
    Stack stack;
    char str[] = "artxE eseehc .esaelp";
    int index = 0;
    int len = strlen(str);

    printf("The encoded message: %s\n", str);
    printf("The decoded message: ");

    initialize(&stack);

    while (index < len) {
        while (index < len && str[index] != ' ') {
            push(&stack, str[index]);
            index++;
        }

        while (!isEmpty(&stack)) {
            printf("%c", pop(&stack));
        }

        if (index < len && str[index] == ' ') {
            printf(" ");
            index++;
        }
    }

    printf("\n");
}