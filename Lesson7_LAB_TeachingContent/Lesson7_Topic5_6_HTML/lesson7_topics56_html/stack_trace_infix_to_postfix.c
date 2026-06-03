#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    主題 6：Infix-to-Postfix using a Stack
    說明：
    這份程式不只轉換 postfix，也會印出每一步的 Stack 與 Output，
    對應投影片 9-11 的表格示範。

    範例輸入：A+B*C^(2^3)/(A+B)
*/

#define MAX 300

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

void getStackString(char result[]) {
    int i, j = 0;
    if (isEmpty()) {
        strcpy(result, "Empty");
        return;
    }
    for (i = 0; i <= top; i++) {
        result[j++] = stack[i];
        result[j++] = ' ';
    }
    result[j] = '\0';
}

void printStep(char x, const char action[], const char output[]) {
    char stackText[MAX];
    getStackString(stackText);
    if (x == '\0') {
        printf("%-8s | %-18s | %-22s | %s\n", "End", stackText, output, action);
    } else {
        printf("%-8c | %-18s | %-22s | %s\n", x, stackText, output, action);
    }
}

int main(void) {
    char infix[MAX];
    char output[MAX] = "";
    int i;

    printf("請輸入中序式，例如 A+B*C^(2^3)/(A+B)：");
    scanf("%299s", infix);

    printf("\n%-8s | %-18s | %-22s | %s\n", "X", "Stack S", "Output", "說明");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; infix[i] != '\0'; i++) {
        char x = infix[i];
        char temp[3] = {x, '\0', '\0'};

        if (isalnum(x)) {
            // 運算元直接輸出
            strcat(output, temp);
            printStep(x, "運算元直接加入 output", output);
        }
        else if (x == '(') {
            // 左括號直接 push
            push(x);
            printStep(x, "左括號 push 到 stack", output);
        }
        else if (x == ')') {
            // 右括號：pop 到遇到左括號
            while (!isEmpty() && peek() != '(') {
                char op[2] = {pop(), '\0'};
                strcat(output, op);
            }
            pop(); // 移除左括號
            printStep(x, "右括號：pop 到遇到左括號並丟掉左括號", output);
        }
        else if (isOperator(x)) {
            // 運算子：先 pop 較高或相同優先順序的運算子
            while (!isEmpty() && peek() != '(' && priority(peek()) >= priority(x)) {
                char op[2] = {pop(), '\0'};
                strcat(output, op);
            }
            push(x);
            printStep(x, "運算子：比較優先順序後 push", output);
        }
    }

    // 最後把 stack 中所有運算子全部 pop 出來
    while (!isEmpty()) {
        char op[2] = {pop(), '\0'};
        strcat(output, op);
    }
    printStep('\0', "輸入結束：清空 stack", output);

    printf("\nPostfix 結果：%s\n", output);
    return 0;
}
