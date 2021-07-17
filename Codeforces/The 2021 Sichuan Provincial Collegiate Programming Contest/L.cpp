#include "bits/stdc++.h"
using namespace std;
const int maxn = 2e5 + 100;
const int INF = 0x3f3f3f3f;
int n, m, q, w[maxn], dp[maxn][100 + 10];
vector<int> g[maxn];
void bfs(int num) {
  queue<int> que;
  for (int i = 1; i <= n; i++)
    if (w[i] == num) {
      que.push(i);
      dp[i][num] = 0;
    }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto v : g[u]) {
      if (dp[v][num] != INF) continue;
      que.push(v);
      dp[v][num] = dp[u][num] + 1;
    }
  }
}
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 100; j++) dp[i][j] = INF;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= 100; i++) bfs(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 100; j++) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
  while (q--) {
    int p, a;
    scanf("%d%d", &p, &a);
    printf("%d\n", dp[p][a] == INF ? -1 : dp[p][a]);
  }
  return 0;
}