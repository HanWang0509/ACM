#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5 + 10;
int n, k, x, p0;
int s[maxn], t[maxn], p[maxn];
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d%d%d%d", &n, &k, &x, &p0);
  int ans = p0;
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= k; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= k; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= k; i++) ans = max(ans, p[i] - t[i]);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = (x + s[i] - 1) / s[i];
    if (tmp <= ans) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}