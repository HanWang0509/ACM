#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
int n, p[maxn], cell[maxn][maxn];
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    int t = p[i], x = i, y = i;
    cell[x][y] = p[i];
    --t;
    while (t) {
      if (y - 1 && !cell[x][y - 1]) {
        cell[x][y - 1] = p[i];
        --t, --y;
      } else if (x + 1 < n + 1 && !cell[x + 1][y]) {
        cell[x + 1][y] = p[i];
        --t, ++x;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) printf("%d ", cell[i][j]);
    printf("\n");
  }
  return 0;
}