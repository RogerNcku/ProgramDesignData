/*
  中文註解版程式：tree_traversal_c.c
  說明：主題 15/16：樹節點建立與走訪示範。建立二元樹後輸出 inorder 與 postorder。
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
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder 走訪：Left → Visit → Right。
void inOrder(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    inOrder(root->left);
    printf("%c ", root->data);  // 拜訪目前節點並輸出資料
    inOrder(root->right);
}

// Postorder 走訪：Left → Right → Visit。
void postOrder(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);  // 拜訪目前節點並輸出資料
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main() {
    Node* root = createNode('A');
    Node* n1 = createNode('B');
    Node* n2 = createNode('C');
    Node* n3 = createNode('D');
    Node* n4 = createNode('E');
    Node* n5 = createNode('F');

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
