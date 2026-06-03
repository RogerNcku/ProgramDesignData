/*
  中文註解版程式：lesson6_topic4_demo.c
  說明：主題 4：二元樹陣列表示法示範。用 index 公式找 parent、left child、right child。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main(void) {
    char tree[8] = {'-', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int i;
    for (i = 1; i <= 7; i++) {
        printf("index %d = %c", i, tree[i]);
        if (2*i <= 7) printf(", left child = %c", tree[2*i]);
        if (2*i+1 <= 7) printf(", right child = %c", tree[2*i+1]);
        printf("\n");
    }
    return 0;
}
