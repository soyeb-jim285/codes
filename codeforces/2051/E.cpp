#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n, k;
  cin >> n >> k;
  map<ll, pair<ll, ll>> mp;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mp[x].first++;
  }
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mp[x].second++;
  }
  ll mx = 0, bd = 0;
  for (auto &x : mp) {
    ll val = x.first;
    if (bd <= k)
      mx = max(mx, n * val);
    bd += x.second.first - x.second.second;
    n -= x.second.second;
  }
  cout << mx << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
