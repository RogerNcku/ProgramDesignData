/*
  中文註解版程式：distinct_binary_trees.c
  說明：主題 13：不同 Binary Trees 數量。使用 Catalan number 的 DP 公式計算 n 個節點可形成幾種二元樹。
  閱讀方式：先看資料結構定義，再看操作函式，最後看 main() 如何測試。
*/

// 匯入標準輸入輸出函式庫，提供 printf / scanf 等功能。
#include <stdio.h>

// 動態規劃計算 Catalan number：代表 n 個節點的不同二元樹數量。
long long catalan(int n) {
    long long dp[50] = {0};
    dp[0] = 1;
    for (int nodes = 1; nodes <= n; nodes++) {
        for (int left = 0; left < nodes; left++) {
            int right = nodes - 1 - left;
            dp[nodes] += dp[left] * dp[right];
        }
    }
    return dp[n];
}

// 主程式：建立測試資料，呼叫上方函式，觀察輸出結果。
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Number of distinct binary trees with %d nodes = %lld\n", n, catalan(n));
    return 0;
}
