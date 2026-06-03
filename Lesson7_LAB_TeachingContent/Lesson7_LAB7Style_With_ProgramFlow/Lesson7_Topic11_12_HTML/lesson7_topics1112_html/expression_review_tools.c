#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
   Lesson 7 主題 11：Expression 綜合複習工具
   功能：
   1. 逐字分析 expression 裡的 token
   2. 判斷 operand / operator / parenthesis
   3. 顯示運算子的優先順序
   這個程式適合用來複習主題 1 到主題 10 的基本概念。
*/

// 判斷是否為運算子
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// 回傳運算子優先順序，數字越大代表越優先
int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char exp[100];

    printf("請輸入一個 Infix expression，例如 A+B*C 或 (A+B)*C：\n");
    scanf("%99s", exp);

    printf("\n逐步分析結果：\n");
    printf("--------------------------------------\n");
    printf("字元\t類型\t\t補充說明\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (isalnum(ch)) {
            // isalnum 表示英文字母或數字，這裡視為 operand
            printf("%c\tOperand\t\t運算元，可代表變數或數字\n", ch);
        } else if (isOperator(ch)) {
            // 運算子需要看優先順序
            printf("%c\tOperator\t優先順序 = %d\n", ch, priority(ch));
        } else if (ch == '(') {
            printf("%c\tLeft Paren\t左括號，代表新的計算範圍開始\n", ch);
        } else if (ch == ')') {
            printf("%c\tRight Paren\t右括號，代表括號內要先完成\n", ch);
        } else {
            printf("%c\tUnknown\t\t不是本程式處理的符號\n", ch);
        }
    }

    printf("--------------------------------------\n");
    printf("複習重點：Infix 對人類直覺，但程式需要判斷括號與運算子優先順序。\n");

    return 0;
}
