#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e6 + 100;
int vis[maxn], n, k;
vector<int> vec[maxn];
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int mod = i % k;
    vec[mod].push_back(i);
  }
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < vec[i].size(); j++) {
      cnt++;
      if (cnt == n)
        printf("%d\n", vec[i][j]);
      else
        printf("%d ", vec[i][j]);
    }
  }
  return 0;
}