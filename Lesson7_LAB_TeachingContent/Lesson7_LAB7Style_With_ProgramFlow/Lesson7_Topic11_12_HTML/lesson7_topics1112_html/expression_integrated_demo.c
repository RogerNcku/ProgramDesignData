#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
   Lesson 7 主題 12：整合範例
   功能：
   1. 將 Infix expression 轉成 Postfix expression
   2. 用 Stack 顯示轉換概念
   3. 適合輸入單一字元運算元，例如：A+B*C、(A+B)*C、A*(B+C)-D

   注意：
   這份教學範例主要用來理解演算法，所以每個 operand 用單一字元表示。
*/

#define MAX 100

char stack[MAX];
int top = -1;

// 判斷 stack 是否為空
int isEmpty() {
    return top == -1;
}

// push：把字元放入 stack
void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

// pop：從 stack 取出最上方字元
char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return '\0';
}

// peek：只查看 stack 最上方字元，不移除
char peek() {
    if (!isEmpty()) {
        return stack[top];
    }
    return '\0';
}

// 判斷是否為運算子
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// 運算子優先順序
int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 將 Infix 轉成 Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // 1. 如果是 operand，直接輸出到 postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // 2. 如果是左括號，直接 push 進 stack
        else if (ch == '(') {
            push(ch);
        }
        // 3. 如果是右括號，pop 到遇到左括號為止
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // 移除左括號 '('，但不輸出
        }
        // 4. 如果是運算子，處理優先順序
        else if (isOperator(ch)) {
            while (!isEmpty() && priority(peek()) >= priority(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // 5. 掃描完 infix 後，把 stack 剩下的運算子全部輸出
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("請輸入 Infix expression，例如 A+B*C 或 (A+B)*C：\n");
    scanf("%99s", infix);

    infixToPostfix(infix, postfix);

    printf("\nInfix  : %s\n", infix);
    printf("Postfix: %s\n", postfix);

    printf("\n觀念說明：\n");
    printf("1. Operand 直接輸出。\n");
    printf("2. Operator 先放入 stack，但要比較優先順序。\n");
    printf("3. 右括號出現時，要 pop 到左括號為止。\n");
    printf("4. 最後把 stack 中剩下的運算子全部輸出。\n");

    return 0;
}
