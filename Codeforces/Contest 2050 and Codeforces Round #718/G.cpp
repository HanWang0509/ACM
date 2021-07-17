#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
typedef long long LL;
const LL inf = 1e18;
const int maxm = 2e5 + 10;
int head[maxn], ver[maxm], Next[maxm], d[maxn];
int n, m, s, t, tot;
LL maxflow, edge[maxm];
int X[maxn], Y[maxn];
LL val[maxn];
queue<int> q;
void add(int x, int y, LL z) {
  ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
  ver[++tot] = x, edge[tot] = 0ll, Next[tot] = head[y], head[y] = tot;
}
bool bfs() {
  memset(d, 0, sizeof(d));
  while (q.size()) q.pop();
  q.push(s);
  d[s] = 1;
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = Next[i]) {
      if (edge[i] && !d[ver[i]]) {
        q.push(ver[i]);
        d[ver[i]] = d[x] + 1;
        if (ver[i] == t) return 1;
      }
    }
  }
  return 0;
}
LL dinic(int x, LL flow) {
  if (x == t) return flow;
  LL rest = flow, k;
  for (int i = head[x]; i && rest; i = Next[i]) {
    if (edge[i] && d[ver[i]] == d[x] + 1) {
      k = dinic(ver[i], min(rest, edge[i]));
      if (!k) d[ver[i]] = 0;
      edge[i] -= k;
      edge[i ^ 1] += k;
      rest -= k;
    }
  }
  return flow - rest;
}
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  s = 0, t = 1, tot = 1;
  LL ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%lld", &X[i], &Y[i], &val[i]);
    ans += val[i];
    add(i << 1, i << 1 | 1, val[i]);
    int tmpx = abs(X[i]) & 1, tmpy = abs(Y[i]) & 1;
    if (tmpx && tmpy) val[i] = 3ll;
    if (tmpx && !tmpy) val[i] = 0ll;
    if (!tmpx && !tmpy) val[i] = 1ll;
    if (!tmpx && tmpy) val[i] = 2ll;
    if (val[i] == 0ll) add(s, i << 1, inf);
    if (val[i] == 3ll) add(i << 1 | 1, t, inf);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) == 1 && val[i] + 1ll == val[j]) {
        add(i << 1 | 1, j << 1, inf);
      }
    }
  }
  LL flow = 0;
  while (bfs()) {
    while (flow = dinic(s, inf)) maxflow += flow;
  }
  printf("%lld\n", ans - maxflow);
  return 0;
}