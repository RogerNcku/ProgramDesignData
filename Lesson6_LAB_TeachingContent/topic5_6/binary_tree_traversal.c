/*
  中文註解版程式：binary_tree_traversal.c
  說明：主題 5：Binary Tree Traversal 示範。比較 inorder、preorder、postorder 三種走訪順序。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>
// 匯入標準函式庫，提供 malloc / free / exit 等記憶體與程式控制功能。
#include <stdlib.h>

// 定義節點結構：資料欄位存節點內容，指標欄位負責連到其他節點。
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// 建立新節點：配置記憶體、填入資料，並把左右指標初始化為 NULL。
Node* createNode(char data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Inorder 走訪：Left → Visit → Right；套用在 BST 會得到由小到大的排序。
void inorder(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    inorder(root->left);           // L
    printf("%c ", root->data);     // V
    inorder(root->right);          // R
}

// Preorder 走訪：Visit → Left → Right，常用來觀察樹建立的形狀。
void preorder(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    printf("%c ", root->data);     // V
    preorder(root->left);          // L
    preorder(root->right);         // R
}

// Postorder 走訪：Left → Right → Visit，常用於釋放整棵樹。
void postorder(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    postorder(root->left);         // L
    postorder(root->right);        // R
    printf("%c ", root->data);     // V
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main(void) {
    Node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->right = createNode('F');

    printf("Inorder   : "); inorder(root);   printf("\n");
    printf("Preorder  : "); preorder(root);  printf("\n");
    printf("Postorder : "); postorder(root); printf("\n");
    return 0;
}
