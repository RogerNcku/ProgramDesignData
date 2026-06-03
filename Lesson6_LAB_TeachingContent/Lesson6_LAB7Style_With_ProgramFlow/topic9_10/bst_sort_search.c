/*
  中文註解版程式：bst_sort_search.c
  說明：主題 9：BST Sorting and Searching。利用 inorder traversal 得到排序結果，並示範搜尋路徑。
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
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// BST 插入：比目前節點小往左，大往右；空位置就是新節點位置。
Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);  // 空位置就是插入點
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

// BST 搜尋：從 root 開始比較，小往左、大往右，走到 NULL 表示找不到。
Node* search(Node* root, int key) {
    Node* current = root;
    while (current != NULL) {
        printf("Compare with %d\n", current->key);
        if (key == current->key) return current;
        if (key < current->key) current = current->left;
        else current = current->right;
    }
    return NULL;
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
    int data[] = {7, 14, 10, 8, 16, 9, 3, 2, 4, 1};
    int n = sizeof(data) / sizeof(data[0]);
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    printf("BST sort by inorder traversal:\n");
    inorder(root);
    printf("\n\n");

    int targets[] = {8, 1, 15};
    for (int i = 0; i < 3; i++) {
        printf("Search %d:\n", targets[i]);
        Node* result = search(root, targets[i]);
        if (result != NULL) printf("Found %d.\n\n", targets[i]);
        else printf("%d NOT FOUND.\n\n", targets[i]);
    }

    freeTree(root);
    return 0;
}
