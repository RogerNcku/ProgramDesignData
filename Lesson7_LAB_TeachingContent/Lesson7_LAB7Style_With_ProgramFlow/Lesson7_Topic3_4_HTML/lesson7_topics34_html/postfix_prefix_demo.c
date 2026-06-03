#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    主題 3：Postfix 與 Prefix 表示法示範
    目的：
    1. 讓使用者輸入一個簡單的二元運算式，例如 A+B。
    2. 程式將它改寫成 Infix、Postfix、Prefix 三種形式。

    注意：
    這份程式是「觀念示範版」，主要處理形如 A+B、x*y 這種
    一個運算子、兩個運算元的簡單 expression。
*/

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int main(void) {
    char exp[100];
    char left = '\0', right = '\0', op = '\0';
    int i;

    printf("請輸入簡單中序式，例如 A+B 或 x*y：");
    scanf("%99s", exp);

    /* 從輸入字串中找出：左運算元、運算子、右運算元 */
    for (i = 0; i < strlen(exp); i++) {
        if (isOperator(exp[i])) {
            op = exp[i];
            left = exp[i - 1];
            right = exp[i + 1];
            break;
        }
    }

    if (op == '\0') {
        printf("沒有找到運算子，請輸入例如 A+B 的格式。\n");
        return 0;
    }

    printf("\n===== 三種 expression 表示法 =====\n");
    printf("Infix   中序：%c %c %c\n", left, op, right);
    printf("Postfix 後序：%c %c %c\n", left, right, op);
    printf("Prefix  前序：%c %c %c\n", op, left, right);

    printf("\n說明：\n");
    printf("Infix   ：運算子放在兩個運算元中間。\n");
    printf("Postfix ：運算子放在兩個運算元後面。\n");
    printf("Prefix  ：運算子放在兩個運算元前面。\n");

    return 0;
}
