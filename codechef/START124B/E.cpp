#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 998244353;
ll binpowmod(ll a, ll b, ll m) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res = res % m;
    }
    a *= a;
    a = a % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  ll n, x;
  cin >> n >> x;
  map<ll, ll> prims;
  for (ll i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      prims[i]++;
      x /= i;
    }
  }
  if (x > 1) {
    prims[x]++;
  }
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    ll k = 1;
    for (auto ic : prims) {
      k = (k *
           (binpowmod(ic.second + 1, i, mod) - binpowmod(ic.second, i, mod))) %
          mod;
    }
    ans = (ans + k) % mod;
  }
  if (ans < 0)
    ans += mod;
  cout << ans << "\n";
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
