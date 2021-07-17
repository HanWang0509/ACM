#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5 + 10;
int T, n, k, m, vis[maxn];
pair<int, int> p[maxn];
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d", &T);
  while (T--) {
    memset(vis, 0, sizeof(vis));
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      p[i] = make_pair(x, 0);
    }
    if (m >= 2 * n) {
      for (int i = 0; i < 2 * n; i++) {
        int a = i % n;
        if (vis[p[a].first] == 0)
          vis[p[a].first]++;
        else {
          vis[p[a].first]--;
          p[a].second++;
        }
      }
      int tmp = m / (2 * n);
      for (int i = 0; i < n; i++) p[i].second *= tmp;
    }
    int mod = m % (2 * n);
    for (int i = 0; i < mod; i++) {
      int a = i % n;
      if (vis[p[a].first] == 0)
        vis[p[a].first]++;
      else {
        vis[p[a].first]--;
        p[a].second++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == n - 1)
        printf("%d\n", p[i].second);
      else
        printf("%d ", p[i].second);
    }
  }
  return 0;
}