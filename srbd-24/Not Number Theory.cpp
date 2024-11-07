#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(string s, int x) {
  // reverse(s.begin(), s.end());
  ll ans = -1, mx = -1;
  ll up = 1;
  while (x--) {
    up *= 10;
  }
  for (int i = 0; i < up; i++) {
    ll xx = i, num = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '?') {
        num = num * 10 + xx % 10;
        xx /= 10;
      } else {
        num = num * 10 + s[j] - '0';
      }
    }
    // cout << num << '\n';
    if (__builtin_popcount(num) >= mx) {
      mx = __builtin_popcount(num);
      if (mx == __builtin_popcount(ans)) {
        ans = max(ans, num);
      } else {
        ans = num;
      }
    }
  }
  return ans;
}
void solve() {
  string s;
  cin >> s;
  int qs = 0;
  for (char c : s)
    qs += c == '?';
  cout << fn(s, qs) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
