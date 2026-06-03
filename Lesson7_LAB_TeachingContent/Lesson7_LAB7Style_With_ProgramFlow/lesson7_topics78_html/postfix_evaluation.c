#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
    主題 7：Evaluation of a Postfix Expression
    功能：使用 Stack 計算後序表示式（Postfix Expression）

    後序表示式規則：
    1. 遇到運算元 operand：push 到 stack
    2. 遇到運算子 operator：pop 出右運算元與左運算元
    3. 計算後，把結果 push 回 stack
    4. 表達式讀完後，stack 最上方就是最後答案

    範例：633^2*81++//
    意思相當於：6 / ((3^3 * 2) / (8 + 1))
*/

#define MAX 200

double stack[MAX];
int top = -1;

void push(double value) {
    if (top >= MAX - 1) {
        printf("Stack 已滿，無法 push。\n");
        exit(1);
    }
    stack[++top] = value;
}

double pop(void) {
    if (top < 0) {
        printf("Stack 為空，無法 pop。請檢查 postfix 是否正確。\n");
        exit(1);
    }
    return stack[top--];
}

void printStack(void) {
    int i;
    printf("Stack：");
    if (top < 0) {
        printf("Empty");
    } else {
        for (i = 0; i <= top; i++) {
            printf("%.2f ", stack[i]);
        }
    }
    printf("\n");
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

double power(double base, double exp) {
    double result = 1;
    int i;
    for (i = 0; i < (int)exp; i++) {
        result *= base;
    }
    return result;
}

double calculate(double left, double right, char op) {
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        case '^': return power(left, right);
        default:
            printf("未知運算子：%c\n", op);
            exit(1);
    }
}

int main(void) {
    char postfix[MAX];
    int i;

    printf("請輸入後序表示式，例如 633^2*81++//：");
    scanf("%199s", postfix);

    printf("\n開始計算 Postfix Expression：%s\n", postfix);
    printf("----------------------------------------\n");

    for (i = 0; postfix[i] != '\0'; i++) {
        char x = postfix[i];

        if (isdigit(x)) {
            /* 字元數字轉成真正數值，例如 '6' - '0' = 6 */
            double value = x - '0';
            printf("讀到 %c：這是運算元，push %.2f\n", x, value);
            push(value);
            printStack();
        }
        else if (isOperator(x)) {
            /* 注意：先 pop 出來的是右運算元，後 pop 出來的是左運算元 */
            double right = pop();
            double left = pop();
            double result = calculate(left, right, x);

            printf("讀到 %c：這是運算子，pop %.2f 和 %.2f，計算 %.2f %c %.2f = %.2f\n",
                   x, right, left, left, x, right, result);

            push(result);
            printStack();
        }
        else {
            printf("忽略無效字元：%c\n", x);
        }

        printf("----------------------------------------\n");
    }

    if (top == 0) {
        printf("最後答案 = %.2f\n", pop());
    } else {
        printf("Postfix 格式可能不正確，Stack 中還有多個值。\n");
    }

    return 0;
}
