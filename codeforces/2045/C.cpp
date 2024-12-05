#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  map<char, int> cnt1, cnt2;
  for (int i = 1; i < s1.size(); i++) {
    if (cnt1[s1[i]] == 0)
      cnt1[s1[i]] = i;
  }
  reverse(s2.begin(), s2.end());
  for (int i = 1; i < s2.size(); i++) {
    if (cnt2[s2[i]] == 0)
      cnt2[s2[i]] = i;
  }
  ll mn = 1e9;
  string ans = "";
  for (auto ic : cnt1) {
    for (auto jc : cnt2) {
      if (ic.first == jc.first) {
        if (ic.second + jc.second < mn) {
          mn = ic.second + jc.second;
          string tmp = s2.substr(0, jc.second + 1);
          reverse(tmp.begin(), tmp.end());
          ans = s1.substr(0, ic.second) + tmp;
        }
      }
    }
  }
  if (mn == 1e9) {
    cout << "-1" << endl;

  } else {
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
