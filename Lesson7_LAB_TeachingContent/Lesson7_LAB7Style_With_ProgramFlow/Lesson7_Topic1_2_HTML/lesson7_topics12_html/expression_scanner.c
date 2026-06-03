#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    主題一：Expressions 表達式基本概念
    目的：讀取一個 expression，判斷每一個字元是：
          1. 運算元 operand，例如 A、B、5、3
          2. 運算子 operator，例如 +、-、*、/
          3. 括號或其他符號

    這個程式不是為了計算答案，而是先讓電腦能夠「看懂」表達式的組成。
*/

// 判斷字元是不是運算子
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int main() {
    // 你可以修改這一行，換成自己的 expression
    char exp[] = "5/3*8*6+1";

    int operandCount = 0;
    int operatorCount = 0;

    printf("原始 Expression：%s\n\n", exp);
    printf("逐一分析 expression 裡面的元素：\n");

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        // 如果是空白，就跳過
        if (ch == ' ') {
            continue;
        }

        // isalnum() 可以判斷是否為英文字母或數字
        if (isalnum(ch)) {
            printf("%c  是 Operand（運算元）\n", ch);
            operandCount++;
        }
        else if (isOperator(ch)) {
            printf("%c  是 Operator（運算子）\n", ch);
            operatorCount++;
        }
        else if (ch == '(' || ch == ')') {
            printf("%c  是 Parenthesis（括號）\n", ch);
        }
        else {
            printf("%c  是其他符號\n", ch);
        }
    }

    printf("\n統計結果：\n");
    printf("Operand 數量：%d\n", operandCount);
    printf("Operator 數量：%d\n", operatorCount);

    printf("\n三種表示法的概念：\n");
    printf("Infix   ：A + B  （運算子在中間）\n");
    printf("Postfix ：A B +  （運算子在後面）\n");
    printf("Prefix  ：+ A B  （運算子在前面）\n");

    return 0;
}
