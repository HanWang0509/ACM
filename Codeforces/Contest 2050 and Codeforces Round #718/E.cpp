#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;
const LL mod = 998244353;
int T, n;
LL a[maxn], sum[maxn], f[maxn], ans;
void solve(int u, int v) {
  LL p = 0, c = 0;
  if (u) p += a[1];
  if (v) c += a[n];
  for (int i = u + 1; i <= n - v - 1; i++) {
    c += a[i];
    int l = -1, r = (n - v - i - 1) / 2;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      int j = i + mid * 2;
      LL sumc = c + f[j] - f[i];
      LL sump = sum[n] - sumc;
      if (sump > sumc)
        l = mid;
      else
        r = mid - 1;
    }
    l++;
    ans = (ans + (LL)l) % mod;
  }
}
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      sum[i] = sum[i - 1] + a[i];
      f[i] = f[max(i - 2, 0)] + a[i];
    }
    for (int i = 1; i <= n; i++)
      if (sum[i] > sum[n] - sum[i]) ans++;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) solve(i, j);
    printf("%lld\n", ans);
  }
  return 0;
}