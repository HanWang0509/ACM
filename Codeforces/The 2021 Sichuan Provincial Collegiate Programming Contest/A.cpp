#include "bits/stdc++.h"
using namespace std;
int T;
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d", &T);
  while (T--) {
    int k;
    scanf("%d", &k);
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
      for (int j = i; j <= k; j++) {
        if (i + j == k) {
          if (i >= 1 && j >= 1 && i <= 6 && j <= 6) cnt++;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}