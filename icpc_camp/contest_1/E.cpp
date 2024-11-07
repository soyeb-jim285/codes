#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e9 + 7;
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
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    ll x, y;
    cin >> x >> y;
  }
  ll up = ((n - 1) * (n - 1)) % mod;
  ll dn = (n * (n + 1) / 2) % mod;
  ll g = __gcd(up, dn);
  // up /= g;
  // dn /= g;
  cout << up << " " << dn << endl;
  ll ans = (up * binpowmod(dn, mod - 2, mod) % mod) % mod;
  if (ans < 0)
    ans += mod;
  cout << ans << endl;
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
