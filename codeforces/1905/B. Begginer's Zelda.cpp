#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> grp(n + 1);
  for (int i = 0; i < n - 1; i++) {
    ll x, y;
    cin >> x >> y;
    grp[x].push_back(y);
    grp[y].push_back(x);
  }
  ll ans = 0;
  for (auto ic : grp) {
    if (ic.size() == 1) {
      ans++;
    }
  }
  cout << ceil(1.0 * ans / 2) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
