#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack 用來暫存運算子與括號
typedef struct {
    char data[MAX];
    int top;
} Stack;

// 初始化 Stack
void init(Stack *s) {
    s->top = -1;
}

// 判斷 Stack 是否為空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// push：把元素放入 Stack
void push(Stack *s, char ch) {
    if (s->top >= MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = ch;
}

// pop：從 Stack 取出最上面的元素
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[(s->top)--];
}

// peek：只查看 Stack 最上面的元素，不取出
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

// 回傳運算子的優先順序
// 數字越大，代表越優先
int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 判斷是否為運算子
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// 中序轉後序：核心函式
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    init(&s);

    int i = 0; // 掃描 infix 的位置
    int j = 0; // 寫入 postfix 的位置

    while (infix[i] != '\0') {
        char ch = infix[i];

        // 忽略空白
        if (ch == ' ') {
            i++;
            continue;
        }

        // 情況 1：如果是運算元，直接輸出到 postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // 情況 2：如果是左括號，直接 push 到 Stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // 情況 3：如果是右括號，pop 到遇到左括號為止
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // 把左括號 pop 掉，但不輸出
        }
        // 情況 4：如果是運算子
        else if (isOperator(ch)) {
            // Stack 上方若有優先順序大於或等於目前運算子的運算子，就先輸出
            // 注意：此簡化版本把 ^ 也當成左結合；若要完整處理右結合可再調整
            while (!isEmpty(&s) && peek(&s) != '(' && priority(peek(&s)) >= priority(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }

        i++;
    }

    // 掃描結束後，把 Stack 裡剩下的運算子全部輸出
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("請輸入中序表示式，例如 A+B*C 或 (A+B)*(C-D)：\n");
    fgets(infix, MAX, stdin);

    // 去除 fgets 讀到的換行符號
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("\nInfix   Expression：%s\n", infix);
    printf("Postfix Expression：%s\n", postfix);

    return 0;
}
