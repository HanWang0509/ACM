#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int T, n, m, a[maxn * maxn], b[maxn][maxn], vis[maxn][maxn];
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &m, &n);
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &b[i][j]);
        a[++cnt] = b[i][j];
      }
    }
    sort(a + 1, a + 1 + n * m);
    for (int k = n; k >= 1; k--) {
      int flag = 0;
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (a[k] == b[i][j] && vis[i][j] == 0) {
            swap(b[i][j], b[i][k]);
            vis[i][k] = 1;
            flag = 1;
          }
        }
        if (flag == 1) break;
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) printf("%d ", b[i][j]);
      printf("\n");
    }
  }
  return 0;
}