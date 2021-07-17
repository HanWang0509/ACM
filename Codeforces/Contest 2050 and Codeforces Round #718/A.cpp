#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int T;
int main() {
  scanf("%d", &T);
  while (T--) {
    LL n;
    scanf("%lld", &n);
    if (n % 2050) {
      printf("-1\n");
    } else {
      LL cnt = 0;
      LL num = n / 2050;
      while (num) {
        LL r = num % 10;
        cnt += r;
        num /= 10;
      }
      printf("%lld\n", cnt);
    }
  }
  return 0;
}