/*
  中文註解版程式：binary_search_tree.c
  說明：主題 6：Binary Search Tree 示範。包含插入、搜尋與 inorder 排序輸出。
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
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// BST 插入：比目前節點小往左，大往右；空位置就是新節點位置。
Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);  // 空位置就是插入點
    if (key < root->key)
        root->left = insert(root->left, key);  // 較小的 key 放左子樹
    else if (key > root->key)
        root->right = insert(root->right, key);  // 較大的 key 放右子樹
    return root;
}

// BST 搜尋：從 root 開始比較，小往左、大往右，走到 NULL 表示找不到。
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder 走訪：Left → Visit → Right；套用在 BST 會得到由小到大的排序。
void inorder(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    inorder(root->left);   // 先走左子樹
    printf("%d ", root->key);  // 再拜訪目前節點
    inorder(root->right);  // 最後走右子樹
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main(void) {
    int data[] = {7, 3, 14, 2, 4, 10, 16, 1, 8, 9};
    int n = sizeof(data) / sizeof(data[0]);
    Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, data[i]);

    printf("Inorder sorted result: ");
    inorder(root);
    printf("\n");

    int target = 8;
    Node* ans = search(root, target);
    if (ans != NULL)
        printf("Find %d: FOUND\n", target);
    else
        printf("Find %d: NOT FOUND\n", target);
    return 0;
}
