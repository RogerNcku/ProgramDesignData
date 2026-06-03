#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    主題二：Infix Expressions 中序表示法
    目的：示範中序表示式為什麼需要「運算優先順序」與「括號」。

    範例：
        5 + 2 * 3      結果是 11，因為 * 比 + 優先
        (5 + 2) * 3    結果是 21，因為括號最優先

    程式方法：
        使用兩個 stack：
        1. values[] 儲存數字
        2. ops[] 儲存運算子
*/

#define MAX 100

// 數字 stack
int values[MAX];
int vTop = -1;

// 運算子 stack
char ops[MAX];
int oTop = -1;

// push 數字
void pushValue(int v) {
    values[++vTop] = v;
}

// pop 數字
int popValue() {
    return values[vTop--];
}

// push 運算子
void pushOp(char op) {
    ops[++oTop] = op;
}

// pop 運算子
char popOp() {
    return ops[oTop--];
}

// 查看最上面的運算子，但不移除
char peekOp() {
    return ops[oTop];
}

// 判斷運算子優先順序
int priority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 實際做一次運算
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

// 從 stack 取出兩個數字與一個運算子，完成一次計算
void computeOnce() {
    int b = popValue();       // 注意：第二個運算元先被 pop 出來
    int a = popValue();       // 第一個運算元後被 pop 出來
    char op = popOp();
    int result = applyOp(a, b, op);

    printf("計算：%d %c %d = %d\n", a, op, b, result);
    pushValue(result);
}

// 計算 infix expression，這裡假設數字都是一位數，方便教學
int evaluateInfix(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (ch == ' ') continue;

        // 遇到數字：放入 values stack
        if (isdigit(ch)) {
            pushValue(ch - '0');
        }
        // 遇到左括號：放入 ops stack
        else if (ch == '(') {
            pushOp(ch);
        }
        // 遇到右括號：一直計算到遇到左括號為止
        else if (ch == ')') {
            while (oTop >= 0 && peekOp() != '(') {
                computeOnce();
            }
            popOp(); // 移除左括號 '('
        }
        // 遇到運算子：根據優先順序處理
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (oTop >= 0 && priority(peekOp()) >= priority(ch)) {
                computeOnce();
            }
            pushOp(ch);
        }
    }

    // 把剩下的運算子全部算完
    while (oTop >= 0) {
        computeOnce();
    }

    return popValue();
}

int main() {
    char exp1[] = "5+2*3";
    char exp2[] = "(5+2)*3";

    printf("範例一：%s\n", exp1);
    int ans1 = evaluateInfix(exp1);
    printf("結果：%d\n\n", ans1);

    // 重設 stack，準備算第二題
    vTop = -1;
    oTop = -1;

    printf("範例二：%s\n", exp2);
    int ans2 = evaluateInfix(exp2);
    printf("結果：%d\n", ans2);

    return 0;
}
