/*
  中文註解版程式：forest_lcrs_demo.c
  說明：主題 14：Forest 的 Left-Child Right-Sibling 表示法。將多棵一般樹串成可用二元指標處理的結構。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>
// 匯入標準函式庫，提供 malloc / free / exit 等記憶體與程式控制功能。
#include <stdlib.h>

// 定義節點結構：資料欄位存節點內容，指標欄位負責連到其他節點。
typedef struct Node {
    char data;
    struct Node *leftChild;     // first child
    struct Node *rightSibling;  // next sibling
} Node;

// 建立新節點：配置記憶體、填入資料，並把左右指標初始化為 NULL。
Node* createNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
}

// LCRS 的 preorder：先拜訪目前節點，再走 leftChild，最後走 rightSibling。
void preorderLCRS(Node* root) {
    if (root == NULL) return;  // 遞迴終止條件：空節點不需要處理
    printf("%c ", root->data);  // 拜訪目前節點並輸出資料
    preorderLCRS(root->leftChild);
    preorderLCRS(root->rightSibling);
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main() {
    Node *A = createNode('A');
    Node *B = createNode('B');
    Node *C = createNode('C');
    Node *D = createNode('D');
    Node *E = createNode('E');
    Node *F = createNode('F');
    Node *G = createNode('G');
    Node *H = createNode('H');
    Node *I = createNode('I');

    // Forest: A has children B,C,D; E has child F; G has children H,I
    // Convert to left-child right-sibling form.
    A->leftChild = B;  B->rightSibling = C;  C->rightSibling = D;
    A->rightSibling = E;
    E->leftChild = F;
    E->rightSibling = G;
    G->leftChild = H;  H->rightSibling = I;

    printf("Preorder of forest in LCRS form: ");
    preorderLCRS(A);
    printf("\n");
    return 0;
}
