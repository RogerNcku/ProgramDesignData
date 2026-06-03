#include <stdio.h>
#include <stdlib.h>

// 節點結構：可以存放運算子，也可以存放運算元
// 在 Expression Tree 中：
// 1. 葉節點通常是運算元，例如 A、B、C、D
// 2. 內部節點通常是運算子，例如 +、-、*、/
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// 建立新節點
Node* createNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Preorder 前序走訪：Root -> Left -> Right
// 對 Expression Tree 來說，前序走訪會得到 Prefix Expression
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data);   // 先印根節點
    preorder(root->left);         // 再走左子樹
    preorder(root->right);        // 最後走右子樹
}

// Inorder 中序走訪：Left -> Root -> Right
// 對 Expression Tree 來說，中序走訪會接近 Infix Expression
// 為了讓括號清楚，這裡每個子樹都加上括號
void inorder(Node* root) {
    if (root == NULL) return;
    printf("(");
    inorder(root->left);          // 先走左子樹
    printf("%c", root->data);     // 再印根節點
    inorder(root->right);         // 最後走右子樹
    printf(")");
}

// Postorder 後序走訪：Left -> Right -> Root
// 對 Expression Tree 來說，後序走訪會得到 Postfix Expression
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);        // 先走左子樹
    postorder(root->right);       // 再走右子樹
    printf("%c ", root->data);   // 最後印根節點
}

// 釋放樹的記憶體
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // 建立表達式樹：(A + B) * (C - D)
    //
    //             *
    //           /   \
    //          +     -
    //         / \   / \
    //        A   B C   D
    //
    // Prefix  : * + A B - C D
    // Infix   : ((A+B)*(C-D))
    // Postfix : A B + C D - *

    Node* root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('-');

    root->left->left = createNode('A');
    root->left->right = createNode('B');

    root->right->left = createNode('C');
    root->right->right = createNode('D');

    printf("Expression Tree Traversal 範例\n\n");

    printf("Prefix  Expression：");
    preorder(root);
    printf("\n");

    printf("Infix   Expression：");
    inorder(root);
    printf("\n");

    printf("Postfix Expression：");
    postorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
