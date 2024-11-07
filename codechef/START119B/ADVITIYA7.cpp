#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll const mod = 1e9 + 7;

void solve() {
  ll x, q;
  cin >> x >> q;
  map<ll, ll> mp;
  for (ll i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      mp[i]++;
      x /= i;
    }
  }
  if (x > 1)
    mp[x]++;
  while (q--) {
    ll p;
    cin >> p;
    ll ans = 1;
    if (p == 1) {
      cout << "1\n";
      continue;
    }
    for (auto ic : mp) {
      ll ct = 1;
      if (ic.second % p == 0 && ic.second > 0) {
        ct++;
      }
      ans = (ans * ct) % mod;
    }
    if (ans < 0)
      ans += mod;
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
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
