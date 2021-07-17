#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
int L[maxn][maxn], U[maxn][maxn], dp[maxn][maxn][25];
int m, n, k;
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j < n; j++) {
      int x;
      scanf("%d", &x);
      L[i][j] = x;
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      U[i][j] = x;
    }
  }
  if (k % 2) {
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) printf("-1 ");
      printf("\n");
    }
    return 0;
  }
  k /= 2;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j][0] = 0;
      for (int s = 1; s <= k; s++) dp[i][j][s] = INT_MAX / 2;
    }
  }
  for (int s = 1; s <= k; s++) {
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (i > 1)
          dp[i][j][s] = min(dp[i][j][s], dp[i - 1][j][s - 1] + U[i - 1][j]);
        if (i < m)
          dp[i][j][s] = min(dp[i][j][s], dp[i + 1][j][s - 1] + U[i][j]);
        if (j > 1)
          dp[i][j][s] = min(dp[i][j][s], dp[i][j - 1][s - 1] + L[i][j - 1]);
        if (j < n)
          dp[i][j][s] = min(dp[i][j][s], dp[i][j + 1][s - 1] + L[i][j]);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", 2 * dp[i][j][k]);
    printf("\n");
  }
  return 0;
}