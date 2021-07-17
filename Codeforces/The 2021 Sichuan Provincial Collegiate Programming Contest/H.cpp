#include "bits/stdc++.h"
using namespace std;
int T;
map<string, string> mp;
void init() {
  mp["imasu"] = "tte";
  mp["mimasu"] = "nde";
  mp["kimasu"] = "ite";
  mp["gimasu"] = "ide";
  mp["shimasu"] = "shite";
  mp["chimasu"] = "tte";
  mp["rimasu"] = "tte";
  mp["bimasu"] = "nde";
  mp["nimasu"] = "nde";
}
bool check(string a, string b) {
  int i = 0, j = a.length() - 1;
  // cout << a << " " << endl;
  while (i < j) {
    swap(a[i], a[j]);
    i++, j--;
  }
  // cout << a << " " << endl;
  i = 0;
  // cout << b << " " << endl;
  int k = b.length() - 1;
  while (i < k) {
    swap(b[i], b[k]);
    i++, k--;
  }
  // cout << b << " " << endl;
  int lena = a.length(), lenb = b.length();
  i = 0;
  while (i < lena && i < lenb) {
    if (a[i] == b[i])
      i++;
    else
      return false;
  }
  return true;
}
int main() {
  // freopen("in.txt", "r", stdin);
  init();
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    string res = "";
    if (check(s, "chimasu")) {
      res += s.substr(0, s.length() - 7) + mp["chimasu"];
    } else if (check(s, "rimasu")) {
      res += s.substr(0, s.length() - 6) + mp["rimasu"];
    } else if (check(s, "bimasu")) {
      res += s.substr(0, s.length() - 6) + mp["bimasu"];
    } else if (check(s, "nimasu")) {
      res += s.substr(0, s.length() - 6) + mp["nimasu"];
    } else if (check(s, "kimasu")) {
      if (s == "ikimasu")
        res = "itte";
      else
        res += s.substr(0, s.length() - 6) + mp["kimasu"];
    } else if (check(s, "gimasu")) {
      res += s.substr(0, s.length() - 6) + mp["gimasu"];
    } else if (check(s, "shimasu")) {
      res += s.substr(0, s.length() - 7) + mp["shimasu"];
    } else if (check(s, "mimasu")) {
      res += s.substr(0, s.length() - 6) + mp["mimasu"];
    } else if (check(s, "imasu")) {
      res += s.substr(0, s.length() - 5) + mp["imasu"];
    } else
      res = s;
    cout << res << endl;
  }
  return 0;
}