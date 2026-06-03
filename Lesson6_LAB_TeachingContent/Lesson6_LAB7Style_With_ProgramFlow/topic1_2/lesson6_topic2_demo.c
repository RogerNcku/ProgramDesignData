/*
  中文註解版程式：lesson6_topic2_demo.c
  說明：主題 2：樹的表示法示範。用 left-child / right-sibling 將一般樹轉成規則的二元指標形式。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>
// 匯入標準函式庫，提供 malloc / free / exit 等記憶體與程式控制功能。
#include <stdlib.h>

// 定義節點結構：資料欄位存節點內容，指標欄位負責連到其他節點。
typedef struct Node {
    char data;
    struct Node *leftChild;
    struct Node *rightSibling;
} Node;

// 建立新節點：配置記憶體、填入資料，並把左右指標初始化為 NULL。
Node* createNode(char data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->leftChild = NULL;
    n->rightSibling = NULL;
    return n;
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main(void) {
    Node *A = createNode('A');
    Node *B = createNode('B');
    Node *C = createNode('C');
    A->leftChild = B;
    B->rightSibling = C;
    printf("A 的 left child 是 %c\n", A->leftChild->data);
    printf("B 的 right sibling 是 %c\n", B->rightSibling->data);
    return 0;
}
