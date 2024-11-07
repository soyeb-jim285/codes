#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string sn;
  cin >> sn;
  ll n = stoll(sn);
  string s = "";
  for (int i = 0; i <= 10; i++) {
    s += sn;
  }
  vector<pair<ll, ll>> v;
  for (ll a = 1; a <= 10000; a++) {
    string tmp = "";
    for (int i = 0; i <= 7; i++) {
      ll ln = sz(sn) * a;
      ll b = ln - i - 1;
      tmp += s[i];
      if (b <= 0)
        continue;
      ll num = stoll(tmp);
      if (n * a - b == num) {
        v.push_back({a, b});
      }
    }
  }
  cout << sz(v) << "\n";
  for (auto ic : v) {
    cout << ic.first << " " << ic.second << "\n";
  }
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
