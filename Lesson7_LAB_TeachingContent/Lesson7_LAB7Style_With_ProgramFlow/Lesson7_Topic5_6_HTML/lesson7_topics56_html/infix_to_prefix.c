#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    主題 5：Infix-to-Prefix 中序轉前序
    說明：
    Prefix 的運算子放在運算元前面，例如：+ A B。

    常見做法：
    1. 將 infix 字串反轉。
    2. 反轉時把 '(' 和 ')' 對調。
    3. 對反轉後的式子做 infix-to-postfix。
    4. 再把得到的 postfix 反轉，就得到 prefix。

    範例：
    Infix : A+B*C
    Prefix: +A*BC
*/

#define MAX 200

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) stack[++top] = ch;
}

char pop(void) {
    if (top >= 0) return stack[top--];
    return '\0';
}

char peek(void) {
    if (top >= 0) return stack[top];
    return '\0';
}

int isEmpty(void) {
    return top == -1;
}

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void reverseString(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void swapParentheses(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    top = -1; // 每次轉換前先清空 stack

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            // 運算元直接輸出
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            // 左括號先進 stack
            push(ch);
        }
        else if (ch == ')') {
            // 右括號：一直 pop 到左括號
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // 丟掉左括號
        }
        else if (isOperator(ch)) {
            // 若 stack 頂端運算子優先順序較高或相同，就先輸出
            while (!isEmpty() && peek() != '(' && priority(peek()) >= priority(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) {
    char temp[MAX];
    char postfix[MAX];

    strcpy(temp, infix);

    // 第 1 步：反轉 infix
    reverseString(temp);

    // 第 2 步：左右括號互換
    swapParentheses(temp);

    // 第 3 步：轉成 postfix
    infixToPostfix(temp, postfix);

    // 第 4 步：反轉 postfix，得到 prefix
    reverseString(postfix);
    strcpy(prefix, postfix);
}

int main(void) {
    char infix[MAX];
    char prefix[MAX];

    printf("請輸入中序式，例如 A+B*C 或 (A+B)*C：");
    scanf("%199s", infix);

    infixToPrefix(infix, prefix);

    printf("\n===== 結果 =====\n");
    printf("Infix  ：%s\n", infix);
    printf("Prefix ：%s\n", prefix);

    return 0;
}
