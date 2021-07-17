#include "bits/stdc++.h"
using namespace std;
int T;
typedef long long LL;
LL br, bp, bs, dr, dp, ds;
int main() {
  // freopen("in.txt", "r", stdin);
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &br, &bp, &bs);
    scanf("%lld%lld%lld", &dr, &dp, &ds);
    LL cnt = 0;
    if (br) {
      // cout << dp << endl;
      if (dp && br) {
        LL tmp = min(dp, br);
        cnt += tmp;
        dp -= tmp;
        br -= tmp;
      }
      // cout << "--->" << br << "  " << dp << endl;
      if (dr && br) {
        LL tmp = min(dr, br);
        dr -= tmp;
        br -= tmp;
      }
      if (ds && br) {
        LL tmp = min(ds, br);
        cnt -= tmp;
        br -= tmp;
        ds -= tmp;
      }
    }
    if (bp) {
      if (ds && bp) {
        LL tmp = min(ds, bp);
        cnt += tmp;
        ds -= tmp;
        bp -= tmp;
      }
      if (dp && bp) {
        LL tmp = min(dp, bp);
        dp -= tmp;
        bp -= tmp;
      }
      if (dr && bp) {
        LL tmp = min(dr, bp);
        cnt -= tmp;
        dr -= tmp;
        bp -= tmp;
      }
    }
    if (bs) {
      if (dr && bs) {
        LL tmp = min(dr, bs);
        cnt += tmp;
        dr -= tmp;
        bs -= tmp;
      }
      if (ds && bs) {
        LL tmp = min(ds, bs);
        ds -= tmp;
        bs -= tmp;
      }
      if (bs && dp) {
        LL tmp = min(bs, dp);
        cnt -= tmp;
        bs -= tmp;
        dp -= tmp;
      }
    }
    printf("%lld\n", cnt);
  }
  return 0;
}