#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll ind(string &s) {
  ll ans = 0, n = s.size(), cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt++;
      ll pw = n - i;
      ll tpw = (1LL << pw);
      // cout << "tpw = " << tpw << endl;
      if (cnt % 2)
        ans += tpw - 1;
      else
        ans -= tpw - 1;
    }
  }
  return ans;
}
void solve() {
  ll n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  // cout << s1 << " " << ind(s1) << endl;
  // cout << s2 << " " << ind(s2) << endl;
  cout << ind(s2) - ind(s1) - 1 << endl;
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
