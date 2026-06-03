/*
  中文註解版程式：bst_insert_delete.c
  說明：主題 8：BST 插入與刪除。刪除分成 leaf、one child、two children 三種情況。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>
// 匯入標準函式庫，提供 malloc / free / exit 等記憶體與程式控制功能。
#include <stdlib.h>

// 定義節點結構：資料欄位存節點內容，指標欄位負責連到其他節點。
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// 建立新節點：配置記憶體、填入資料，並把左右指標初始化為 NULL。
Node* createNode(int key) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) exit(1);
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// BST 插入：比目前節點小往左，大往右；空位置就是新節點位置。
Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);  // 空位置就是插入點
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

// 找右子樹中最小節點，常作為刪除兩個孩子節點時的 successor。
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// BST 刪除：依照節點有 0、1、2 個孩子分別處理。
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        /* Case 1: no child */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        /* Case 2: one child */
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        /* Case 3: two children
           Replace by successor: the smallest node in right subtree. */
        Node* successor = findMin(root->right);
        root->key = successor->key;
        root->right = deleteNode(root->right, successor->key);
    }
    return root;
}

// Inorder 走訪：Left → Visit → Right；套用在 BST 會得到由小到大的排序。
void inorder(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    inorder(root->left);   // 先走左子樹
    printf("%d ", root->key);  // 再拜訪目前節點
    inorder(root->right);  // 最後走右子樹
}

// 釋放整棵樹：先釋放左右子樹，再釋放目前節點，避免記憶體洩漏。
void freeTree(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main(void) {
    int data[] = {5, 3, 15, 12, 10, 7, 6};
    int n = sizeof(data) / sizeof(data[0]);
    Node* root = NULL;

    for (int i = 0; i < n; i++) root = insert(root, data[i]);

    printf("Before delete: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 12);

    printf("After delete 12: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
