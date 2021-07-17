#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int maxn = 2e6 + 100;
const LL L = 1e9 + 1;
int n, d[maxn], t1, t2, h1, h2;
LL a, b, p[maxn], q1[maxn], q2[maxn], ans;
void solve1() {
  LL u = q1[++h1];
  ans = max(ans, u);
  if (a) {
    --a;
    q2[++t2] = u + L;
  }
}
void solve2() {
  LL u = q2[++h2];
  ans = max(ans, u);
  if (b) {
    --b;
    q1[++t1] = u + L;
  }
}
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d%lld%lld", &n, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  LL tmp = min(a, b) / (LL)n;
  a -= tmp * n, b -= tmp * n;
  LL s = tmp * 2 * L;
  for (int i = 1; i <= n; i++)
    if (d[i] == 0) q1[++t1] = p[i];
  for (int i = n; i >= 1; i--)
    if (d[i] == 1) q2[++t2] = L - p[i];
  while (h1 < t1 || h2 < t2) {
    if (h2 >= t2 || (h1 < t1 && q1[h1] < q2[h2]))
      solve1();
    else
      solve2();
  }
  printf("%lld\n", s + ans);
  return 0;
}