#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    主題 4：Infix-to-Postfix 中序轉後序
    目的：
    使用 stack 將簡單中序式轉成後序式。

    支援：
    1. 單字元運算元，例如 A、B、C、x、y、1、2。
    2. 運算子 + - * / ^。
    3. 括號 ( )。

    範例：
    輸入：A+B*C
    輸出：ABC*+
*/

#define MAX 200

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop(void) {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek(void) {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int isEmpty(void) {
    return top == -1;
}

int priority(char op) {
    if (op == '^') return 3;              // 次方最高
    if (op == '*' || op == '/') return 2; // 乘除第二
    if (op == '+' || op == '-') return 1; // 加減第三
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int main(void) {
    char infix[MAX];
    char postfix[MAX];
    int i, j = 0;

    printf("請輸入中序式，例如 A+B*C 或 (A+B)*C：");
    scanf("%199s", infix);

    printf("\n===== 轉換過程 =====\n");

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            /* 遇到運算元：直接加入 postfix */
            postfix[j++] = ch;
            printf("讀到運算元 %c：直接輸出到 postfix\n", ch);
        }
        else if (ch == '(') {
            /* 遇到左括號：放入 stack */
            push(ch);
            printf("讀到左括號 (：push 到 stack\n");
        }
        else if (ch == ')') {
            /* 遇到右括號：pop 到遇到左括號為止 */
            printf("讀到右括號 )：開始 pop 直到遇到 (\n");
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // 把左括號丟掉，不輸出
        }
        else if (isOperator(ch)) {
            /* 遇到運算子：先處理 stack 中優先順序較高或相同的運算子 */
            printf("讀到運算子 %c：比較 stack 頂端運算子優先順序\n", ch);
            while (!isEmpty() && peek() != '(' && priority(peek()) >= priority(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    /* 把 stack 中剩下的運算子全部輸出 */
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\n===== 結果 =====\n");
    printf("Infix   ：%s\n", infix);
    printf("Postfix ：%s\n", postfix);

    return 0;
}
