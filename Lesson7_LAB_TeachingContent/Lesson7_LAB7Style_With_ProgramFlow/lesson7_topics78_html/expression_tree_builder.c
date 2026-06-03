#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    主題 8：Expression Tree 表達式樹
    功能：從 Postfix Expression 建立 Expression Tree，並輸出三種走訪結果。

    Expression Tree 的觀念：
    1. 運算元 operand 會成為葉節點，例如 A、B、C、2、3
    2. 運算子 operator 會成為內部節點，例如 +、-、*、/、^
    3. 對樹做 inorder traversal，可以得到 infix
    4. 對樹做 preorder traversal，可以得到 prefix
    5. 對樹做 postorder traversal，可以得到 postfix

    範例 Postfix：ABC23^^*AB+/+
    對應 Infix：A + B * C ^ (2 ^ 3) / (A + B)
*/

#define MAX 300

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node* stack[MAX];
int top = -1;

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

Node* createNode(char data) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        printf("記憶體配置失敗。\n");
        exit(1);
    }
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void push(Node* n) {
    if (top >= MAX - 1) {
        printf("Stack 已滿。\n");
        exit(1);
    }
    stack[++top] = n;
}

Node* pop(void) {
    if (top < 0) {
        printf("Stack 為空，Postfix 可能不正確。\n");
        exit(1);
    }
    return stack[top--];
}

Node* buildExpressionTree(char postfix[]) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char x = postfix[i];

        if (isalnum(x)) {
            /* 運算元：建立葉節點後 push */
            Node* operand = createNode(x);
            push(operand);
            printf("讀到 %c：建立運算元節點，push 到 stack。\n", x);
        }
        else if (isOperator(x)) {
            /* 運算子：pop 兩棵子樹，組成新的樹 */
            Node* right = pop();  // 先 pop 的是右子樹
            Node* left = pop();   // 後 pop 的是左子樹
            Node* op = createNode(x);
            op->left = left;
            op->right = right;
            push(op);
            printf("讀到 %c：建立運算子節點，左子樹=%c，右子樹=%c，再 push 回 stack。\n",
                   x, left->data, right->data);
        }
    }
    return pop();
}

void inorder(Node* root) {
    if (root == NULL) return;
    if (isOperator(root->data)) printf("(");
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (isOperator(root->data)) printf(")");
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    char postfix[MAX];
    Node* root;

    printf("請輸入 Postfix，例如 ABC23^^*AB+/+：");
    scanf("%299s", postfix);

    printf("\n建立 Expression Tree 的過程：\n");
    printf("----------------------------------------\n");
    root = buildExpressionTree(postfix);

    printf("\nExpression Tree 建立完成。\n");

    printf("Infix   中序走訪：");
    inorder(root);
    printf("\n");

    printf("Prefix  前序走訪：");
    preorder(root);
    printf("\n");

    printf("Postfix 後序走訪：");
    postorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
