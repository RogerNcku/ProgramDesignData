/*
  中文註解版程式：lesson6_topic1_demo.c
  說明：主題 1：樹的基本概念示範。用 left-child / right-sibling 指標建立 Root 與 Children。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>
// 匯入標準函式庫，提供 malloc / free / exit 等記憶體與程式控制功能。
#include <stdlib.h>

// 定義節點結構：資料欄位存節點內容，指標欄位負責連到其他節點。
typedef struct TreeNode {
    char data;
    struct TreeNode *leftChild;
    struct TreeNode *rightSibling;
} TreeNode;

// 建立新節點：配置記憶體、填入資料，並把指標初始化為 NULL。
TreeNode* createNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main(void) {
    TreeNode *root = createNode('A');
    root->leftChild = createNode('B');
    root->leftChild->rightSibling = createNode('C');
    printf("Root = %c\n", root->data);
    printf("Children = %c, %c\n", root->leftChild->data, root->leftChild->rightSibling->data);
    return 0;
}
